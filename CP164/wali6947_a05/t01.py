"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-02-10"
-------------------------------------------------------
"""
# Imports
from List_array import List
test = List()
values = [2, 1, 5, 7, 2, 2, 9, 11, 17, 16]
key = 2
test.remove_many(key)
for i in range(10):
    test.append(i)
for value in test:
    print(value)
