import sys
import random
from rich import print

# Defining a Die class for simulating a single dice roll.
class Die(object):
    def __init__(self, sides=None):
        if not sides:
            self.sides = 6
        else:
            if not isinstance(sides, int):
                print("error: sides is not an integer!")
                sys.exit()
            self.sides = sides

    # The roll method shuffles a list of values representing the sides of the die,
    # and then returns the first value + 1 to simulate rolling the die.
    def roll(self):
        values = [x for x in range(self.sides)]
        random.shuffle(values)
        return values[0] + 1

    def __str__(self):
        return f"[sides: {self.sides}]"

# Defining a Dice class for simulating rolling multiple dice.
class Dice:
    def __init__(self, sides=None, num_dice=1):
        if not sides:
            print("Need to pass in sides!!!")
            sys.exit()

        self.sides = sides
        self.num_dice = num_dice
        self.dice = [Die(sides) for _ in range(num_dice)]

    # The sum method simulates rolling all the dice and adding the results.
    def sum(self):
        total = 0
        for d in self.dice:
            total += d.roll()
        return total

    #returns the maximum result
    def max(self):
        return max(d.roll() for d in self.dice)
    #returns the minimum result.
    def min(self):
        return min(d.roll() for d in self.dice)
    # The avg method simulates rolling all the dice and returning the average         result.
    def avg(self):
        return sum(d.roll() for d in self.dice) / self.num_dice

    # The roll method can be used to simulate rolling the dice in different ways,
    # depending on the value of the rollType parameter.
    def roll(self, rollType=None):
        if rollType == 'max':
            return self.max()
        elif rollType == 'min':
            return self.min()
        elif rollType == 'avg':
            return self.avg()
        else:
            return self.sum()

    #The __str__ method returns a string representation of the Dice object.
    def __str__(self):
        s = ""
        for d in self.dice:
            s = s + f"   [sides: {d.sides}]\n"
        s = s + "]\n"
        return s

# The dieTester function is used to test the Die and Dice classes by rolling them a certain number of times.
def dieTester(die, runs=10, testType="sum"):
    if isinstance(die, Die):
        print(f"Testing {die.sides} sided die for {runs} rolls:")
        print("    [ ", end="")
        for i in range(runs):
            print(die.roll(), end=" ")
        print("]")
    else:
        print(
            f"Rolling {len(die.dice)} {die.sides} sided dice {runs} times to get the {testType} value:"
        )
        print("    [ ", end="")
        for i in range(runs):
            if testType == "avg":
                print(die.avg(), end=" ")
            elif testType == "min":
                print(die.min(), end=" ")
            elif testType == "max":
                print(die.max(), end=" ")
            else:
                print(die.sum(), end=" ")
        print("]")

if __name__=='__main__':
    d1 = Die()
    d2 = Die(20)

    print(d1)
    print(d2)
    print()
    d3 = Dice(10,5)
    dieTester(d1, 10)
    dieTester(d2, 20)
    dieTester(d3, 10, "max")
    dieTester(d3, 10, "min")
    dieTester(d3, 10, "avg")
