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

from Sorts_array import Sorts
import random

# Testing
array = []
for n in range(1000):
    array.append(random.randrange(0, 10000))

print(array)

Sorts.radix_sort(array)

print(array)
