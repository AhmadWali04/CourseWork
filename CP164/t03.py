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

# Answer to the question in testing

array = []

for n in range(1000):
    array.append(random.randrange(-10000, 10000))

print(array)

Sorts.gnome_sort(array)

print(array)
