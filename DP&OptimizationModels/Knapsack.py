# greedy algorithm for knapsack problem 
# Problem statement: A menu of food items where each item has a value and a calorific weight.
# You will input a max calorific value and the program will output the items you can consume 
# such that the 'value' is maximized and the total calorific weight <= calorific weight entered by you 

class Food():
    def __init__(self, name, value, calories):
        # these are instance variables
        # each object will have its own copy
        self.name = name
        self.value = value 
        self.calories = calories
    
    def getValue(self):
        return self.value
    
    def getCalories(self):
        return self.calories

    def density(self):
        # density = value/calories
        return self.getValue()/self.getCalories()
    def __str__(self):
        return self.name 

# Building a Menu of Food items
def buildMenu(names, values, calories):
    """
    names, values and calories are of type lists
    they should be of same length 
    """
    menu = [] # List of all Foods
    for i in range(len(values)):
        menu.append(Food(names[i],values[i],calories[i]))
        # calling Food class constructor for each value in input lists
    return menu

# building a menu
names = ['wine', 'beer', 'pizza', 'burger', 'fries', 'coke', 'apple', 'donut']
values = [89,90,30,50,90,79,90,10]
calories = [123, 154, 258, 354, 365, 150, 95, 195]
foods = buildMenu(names,values,calories)

"""
We are using a 'flexible' greedy algorithm 
Approach: sort the items in the menu according to a keyfunction
This keyfunction can be defined by you 

Then iterate over the sorted list, adding each element to our final output list
and decreasing the totalcalories remaining value 
Repeat the procedure till you reach your goal calorie weight 
"""

def knapsackGreedy(items, maxCalories, keyFunction):
    """
    items - list of food items 
    maxCalories >= 0
    we will be sorting according to the keyFunction

    Time complexity: sorting takes O(nlogn) and then we have a for loop O(n)
    Thus the time complexity is O(nlogn)
    """

    itemsSort = sorted(items, key = keyFunction, reverse=True)
    # reverse is set to true - gives descending order 
    # we pick element with highest key first 

    result = []
    totalValue, totalCalories = 0.0, 0.0

    for i in range(len(itemsSort)):
        if( totalCalories + itemsSort[i].getCalories() <= maxCalories):
            result.append(itemsSort[i])
            totalCalories = totalCalories + itemsSort[i].getCalories()
            totalValue = totalValue + itemsSort[i].getValue()
    return (result, totalValue)

def testKnapsackGreedy(items, constraint, keyFunction):
    result, valueGain = knapsackGreedy(items, constraint, keyFunction)

    print('Total value of Items taken = ', valueGain)
    print('List of items taken ')
    for item in result:
        print(' ', item, end='')

def testCase(maxCalories):
    print("Using greedy by value to allocate ", maxCalories, " calories")
    testKnapsackGreedy(foods, maxCalories, Food.getValue)

    print("Using greedy by calories to allocate ", maxCalories, " calories")
    testKnapsackGreedy(foods, maxCalories, Food.getCalories)

    print("Using greedy by density to allocate ", maxCalories, " calories")
    testKnapsackGreedy(foods, maxCalories, Food.density)

testCase(800)

"""
All three keyFunctions gives us 3 different values 
No one approach is entirely correct 
The knapsack problem is NP complete 
This is the best we can do 
"""


