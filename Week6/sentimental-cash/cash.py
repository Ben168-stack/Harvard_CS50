'''
A program that asks the user how much change is owed and then spits out the minimum number of coins with which said change can be made
Assume that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).

'''
from cs50 import get_float

coins = [0.25, 0.1, 0.05, 0.01]

def main():
    while True:
        change = get_float("Change: ")
        if change > 0:
            break
        else:
            continue

    remainder = change
    coin_amt = 0

    for coin in coins:
        div_mod_change = divmod(remainder, coin)
        coin_amt += div_mod_change[0]
        remainder = round(div_mod_change[1],2 )

        if change != 0:
            continue
        else:
            break

    print(int(coin_amt))

main()