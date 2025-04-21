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

from Food_utilities import by_origin, read_foods
fv = open('foods.txt', 'r')
foods = read_foods(fv)
fv.close()
origin = 1
o_foods = by_origin(foods, origin)
for food in o_foods:
    print(food)
# o foods is a list of food objects, printing it will
