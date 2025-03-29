// #include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/*

implement a program that calculates the approximate grade level needed to comprehend some text.
Your program should print as output “Grade X” where “X” is the grade level computed, rounded to the
nearest integer. If the grade level is 16 or higher (equivalent to or greater than a senior
undergraduate reading level), your program should output “Grade 16+” instead of giving the exact
index number. If the grade level is less than 1, your program should output “Before Grade 1”.

BACKGROUND
____________________________________________________________________________________________________
So what sorts of traits are characteristic of higher reading levels? Well, longer words probably
correlate with higher reading levels. Likewise, longer sentences probably correlate with higher
reading levels, too.

A number of “readability tests” have been developed over the years that define formulas for
computing the reading level of a text. One such readability test is the Coleman-Liau index. The
Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to
understand some text. The formula is
____________________________________________________________________________________________________

index = 0.0588 * L - 0.296 * S - 15.8
____________________________________________________________________________________________________

where L is the average number of letters per 100 words in the text, and S is the average number of
sentences per 100 words in the text.

____________________________________________________________________________________________________
Specification
For the purpose of this problem, we’ll consider any sequence of characters separated by a space to
be a word (so a hyphenated word like “sister-in-law” should be considered one word, not three). You
may assume that a sentence:

- will contain at least one word;
- will not start or end with a space; and
- will not have multiple spaces in a row.

Under those assumptions, you might already be able to find a mathematical relationship between the
number of words and the number of spaces.
*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function to count letters
int count_letters(char *text) {
    int letter_count = 0;
    for (int m = 0; text[m]; m++) {
        if (isalpha(text[m])) { // Only count alphabetic characters
            letter_count++;
        }
    }
    return letter_count;
}

// Function to count words
int count_words(char *text) {
    int word_count = 1; // Start with 1 because last word won't have a space
    for (int m = 0; text[m]; m++) {
        if (text[m] == ' ') {
            word_count++;
        }
    }
    return word_count;
}

// Function to count sentences
int count_sentences(char *text) {
    char end_of_sentence_indicators[] = {'.', '?', '!'};
    int sentence_count = 0;

    for (int m = 0; text[m]; m++) {
        for (int i = 0; i < sizeof(end_of_sentence_indicators) / sizeof(end_of_sentence_indicators[0]); i++) {
            if (text[m] == end_of_sentence_indicators[i]) {
                sentence_count++;
                break;
            }
        }
    }
    return sentence_count;
}

// Function to strip leading and trailing spaces
char *strstrip(char *s) {
    size_t size;
    char *end;
    size = strlen(s);
    if (!size) return s;

    // Trim trailing spaces
    end = s + size - 1;
    while (end >= s && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    // Trim leading spaces
    while (*s && isspace((unsigned char)*s)) s++;

    return s;
}

int main(void) {
    char sentence[1000]; 

    // Prompt the user for input
    printf("Text: ");
    fgets(sentence, sizeof(sentence), stdin); 

    char *strip_sentence = strstrip(sentence);

    // Count letters, words, and sentences
    int no_of_letters = count_letters(strip_sentence);
    int no_of_words = count_words(strip_sentence);
    int no_of_sentences = count_sentences(strip_sentence);

    // Compute the Coleman-Liau index
    float L = (float) no_of_letters / no_of_words * 100;
    float S = (float) no_of_sentences / no_of_words * 100;
    float index_grade = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade level
    if (index_grade < 1) {
        printf("Before Grade 1\n");
    } else if (index_grade >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %.0f\n", round(index_grade));
    }

    return 0;
}