#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef uint8_t BYTE; // define BYTE as 8 bits
int main(int argc, char *argv[])
{
    // Check usage
    if (argc != 2)
    {
        printf("Wrong usage\n");
        return 1;
    }
    // Open file
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }
    // Read 512 bytes into a buffer, the buffer is "bytes"
    BYTE buffer[512];
    int counter = 0; // to count the number of files created/read
    FILE *outputFile = NULL;
    char filename[8]; // xxx.jpg + '\\0', it is 8 because we need the null character too since its a
                      // string
    // Check if this might be the beginning of a 512 byte JPEG file
    while (fread(buffer, sizeof(BYTE), 512, inputFile) != 0)
    {
        // Check for JPEG header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If a file is already open, close it
            if (outputFile != NULL)
            {
                fclose(outputFile);
            }

            // Create new JPEG file
            sprintf(filename, "%03i.jpg", counter);
            outputFile = fopen(filename, "w");
            counter++;
        }

        // Write to JPEG if one is currently open
        if (outputFile != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, outputFile);
        }
    }
    // Close files
    fclose(inputFile);
    if (outputFile != NULL)
    {
        fclose(outputFile);
    }
    return 0;
}
