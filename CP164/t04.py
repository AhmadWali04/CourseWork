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

from Deque_linked import Deque
from Sorts_Deque_linked import Sorts
import random

a = Deque()

for n in range(1000):
    a.insert_rear(random.randrange(-10000, 10000))

for value in a:
    print(value, end=", ")

print()

Sorts.gnome_sort(a)

for value in a:
    print(value, end=", ")
