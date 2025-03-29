#include <stdio.h>
/*A program that asks the user how much change is owed and then spits out the minimum number of coins with which said change can be made
Assume that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).*/ 

int main() {
    const float coins[] = {0.25, 0.1, 0.05, 0.01};  
    float change;

    while (1) {
        printf("Change owed: ");
        scanf("%f", &change);
        if (change > 0) {
            break;
        }
    }

    int coin_amt = 0;
    int cents = (int)(change * 100 + 0.5);  // Convert dollars to cents (to avoid float precision issues)

    // Loop through the coin values
    for (int i = 0; i < sizeof(coins) / sizeof(coins[0]); i++) {
        int coin_value = (int)(coins[i] * 100);  // Convert coin values to cents

        while (cents >= coin_value) {
            cents -= coin_value;
            coin_amt++;
        }
    }

    printf("%d", coin_amt);
    return 0;
}
