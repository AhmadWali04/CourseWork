"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-03-31"
-------------------------------------------------------
"""
# Imports

# Constants
from Sorts_List_linked import Sorts
from List_linked import List
import random

# Testing
array = List()
for n in range(1000):
    array.append(random.randrange(0, 10000))


print()
Sorts.radix_sort(array)

for i in array:
    print(f"{i}")
