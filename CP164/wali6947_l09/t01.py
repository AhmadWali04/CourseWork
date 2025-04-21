from functions import hash_table
from Food import Food
import Food_utilities as FU
# we gonna do this because food utilities is an extension of
# functions we can do with the food class
file = open("foods.txt", mode="r", encoding='utf-8')
src = FU.read_foods(file)
file.close()
hash_table(5, src)
