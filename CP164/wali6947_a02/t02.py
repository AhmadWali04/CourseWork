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
from Food_utilities import average_calories, read_foods
fv = open('foods.txt', 'r')
foods = read_foods(fv)
avg = average_calories(foods)
print(avg)
fv.close()
