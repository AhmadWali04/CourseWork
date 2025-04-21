from Food_utilities import write_foods
from Food_utilities import read_food
food = read_food("Lasagna|7|False|135")
foods = [food, food, ]

File_variable = open("new_foods.txt", "w", encoding="utf-8")
write_foods(File_variable, foods)

File_variable.close()
