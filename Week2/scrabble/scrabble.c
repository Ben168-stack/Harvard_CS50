#include <ctype.h>
// #include <cs50.h>
#include <stdio.h>
#include <string.h>
/*In the game of Scrabble, players create words to score points,
and the number of points is the sum of the point values of each letter in the word.

+--------+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+----+---+---+---+---+---+---+---+---+----+
| Letter | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q  | R | S | T | U | V | W | X | Y | Z  |
+--------+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+----+---+---+---+---+---+---+---+---+----+
| Score  | 1 | 3 | 3 | 2 | 1 | 4 | 2 | 4 | 1 | 8 | 5 | 1 | 3 | 1 | 1 | 3 | 10 | 1 | 1 | 1 | 1 | 4 | 4 | 8 | 4 | 10 |
+--------+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+----+---+---+---+---+---+---+---+---+----+

For example, if we wanted to score the word “CODE”, we would note that the ‘C’ is worth 3 points,
the ‘O’ is worth 1 point, the ‘D’ is worth 2 points, and the ‘E’ is worth 1 point. Summing these,
we get that “CODE” is worth 7 points.*/

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char word[]){
    int score = 0;

    for(int i = 0, length = strlen(word); i < length; i++){
        if(isupper(word[i])){
            score += POINTS[word[i] - 'A'];
        } 
        else if(islower(word[i])){
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}

int main()
{
    char player1_word[50];
    char player2_word[50];

    printf("Player 1: ");
    scanf("%s", player1_word);
    printf("Player 2: ");
    scanf("%s", player2_word);

    int player1_score = compute_score(player1_word);
    int player2_score = compute_score(player2_word);

    if (player1_score > player2_score) {
        printf("Player 1 wins!\n");
    }
    else if (player1_score < player2_score) {
        printf("Player 2 wins!\n");
    }
    else if (player1_score == player2_score) {
        printf("Tie\n");
    }

    return 0;
}
