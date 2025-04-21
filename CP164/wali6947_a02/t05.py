"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-01-20"
-------------------------------------------------------
"""
# Imports

# Constants
from Food_utilities import food_search, read_foods
fv = open('foods.txt', 'r')
foods = read_foods(fv)
origin = 1
max_cals = 0
is_veg = True
result = food_search(foods, origin, max_cals, is_veg)
for food in result:
    print(food)
