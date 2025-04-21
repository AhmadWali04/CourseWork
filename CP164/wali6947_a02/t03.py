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
from Food_utilities import calories_by_origin, read_foods
fv = open('foods.txt', 'r')
foods = read_foods(fv)
origin = 1
by_origins = calories_by_origin(foods, origin)
print(by_origins)
