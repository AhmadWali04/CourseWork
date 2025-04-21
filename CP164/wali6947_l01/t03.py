from Food_utilities import read_food
food = read_food("Lasagna|7|False|135")
name = food.name
origin = food.origin
vegetarian = food.is_vegetarian
calories = food.calories
print(name, origin, vegetarian, calories)
