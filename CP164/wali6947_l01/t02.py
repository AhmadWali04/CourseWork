"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Your Name
ID:      Your ID
Email:   your email@mylaurier.ca
__updated__ = "2024-01-12"
-------------------------------------------------------
"""
# Imports

# Constants
from Food_utilities import get_food
food = get_food()
name = food.name
origin = food.origin
vegetarian = food.is_vegetarian
calories = food.calories
print(name, origin, vegetarian, calories)
