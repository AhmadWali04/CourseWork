"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-03-01"
-------------------------------------------------------
"""
# Imports

# Constants

from List_linked import List
# Initialize
lst = List()

array = [22, 44, 33, 55, 11]

for value in array:
    lst.append(value)

prev, cur, i = lst._linear_search_r(33)
# Results
print(f"prev: {prev._value}")
print(f"cur: {cur._value}")
print(f"i  {i}")
