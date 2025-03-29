
'''
A program that recreates a half-pyramid using hashes (#) for blocks, 

E.g
Height: 4
    #  #
   ##  ##
  ###  ###
 ####  ####

Specification
To make things more interesting, first prompt the user with get_int for the half-pyramid’s height, a positive integer between 1 and 8, inclusive.
If the user fails to provide a positive integer no greater than 8, you should re-prompt for the same again.
Then, generate (with the help of print and one or more loops) the desired half-pyramid.
Take care to align the bottom-left corner of your half-pyramid with the left-hand edge of your terminal window.

'''

from cs50 import get_int

def main():
    height = 0
    while True:
        try:
            height = get_int("Height: ")
        except:
            print("Please Enter a valid height")
            continue

        if type(height) == int and height > 8:
            break
        elif height < 8:
            print("Please enter a positive integer greater than 8")


    hash_block = "#"

    for i in range(1,height+1):
        left_pyramid = (height-i) * " " + hash_block * (i)
        right_pyramid = hash_block * i
        print(left_pyramid + "  " + right_pyramid)

main()