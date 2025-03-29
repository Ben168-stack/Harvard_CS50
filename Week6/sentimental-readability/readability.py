'''
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
'''

# Function to count letters
def count_letters(text):
    letter_count = 0

    for char in text:
        if char.isalpha(): # If character is an alphabet add 1 to count
            letter_count += 1

    return letter_count

# Function to count words
def count_words(text):
    word_count = len(text.split())

    return word_count

# Function to count sentences
def count_sentences(text):
    end_of_sentence_indicators = {'.', '?', '!'}
    sentence_count = 0

    previous_char = ''  # Track the last character to prevent overcounting

    for char in text:
        if char in end_of_sentence_indicators and previous_char not in end_of_sentence_indicators:
            sentence_count += 1
        previous_char = char  # Update the previous character

    return sentence_count

def main():
    text = input("Text: ")

    strip_sentence = text.strip()

    # Count letters, words, and sentences
    no_of_letters = count_letters(strip_sentence);
    no_of_words = count_words(strip_sentence);
    no_of_sentences = count_sentences(strip_sentence);

    # Compute the Coleman-Liau index
    L = no_of_letters / no_of_words * 100;
    S =  no_of_sentences / no_of_words * 100;

    index_grade = 0.0588 * L - 0.296 * S - 15.8;

    if index_grade < 1:
        print("Before Grade 1");
    elif index_grade >= 16:
        print("Grade 16+");
    else:
        print(f"Grade {round(index_grade)}")

main()