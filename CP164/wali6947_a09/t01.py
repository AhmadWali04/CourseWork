"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-03-18"
-------------------------------------------------------
"""
# Imports

# Constants

from functions import insert_words, comparison_total
from Hash_Set_array import Hash_Set
file_variable = open("otoos610.txt", mode="r", encoding='utf-8')
hash_set = Hash_Set()
insert_words(file_variable, hash_set)
