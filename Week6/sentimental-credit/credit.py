'''
a program that prompts the user for a credit card number and then reports (via print) 
whether it is a valid American Express, MasterCard, or Visa card number

So that we can automate some tests of your code, we ask that your program’s 
last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less.

For simplicity, you may assume that the user’s input will be entirely numeric 
(i.e., devoid of hyphens, as might be printed on an actual card).
Best to use get_int or get_string from CS50’s library to get users’ input, depending on how you to decide to implement this one.

Hints:
AMEX:
All American Express account numbers are embossed and start with “37” or “34”. 2. 
Check account numbers are embossed (15 digits) with no alterations.
e.g: 378282246310005

MASTERCARD:
Mastercard numbers start with a 2 or 5,
Credit cards for Mastercard feature 16 digits
e.g: 5555555555554444

VISA:
Visa card numbers start with a 4
Credit cards for Visa feature 16 digits
e.g: 4012888888881881


'''
from cs50 import get_string

def main():
    cc_number = get_string("Number: ")