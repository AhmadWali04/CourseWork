"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-01-31"
-------------------------------------------------------
"""
# Imports

# Constants

from List_array import List
lst = List()
i = 0
value = 1
key = 3
for i in range(10):
    lst.insert(i, value)
n = lst.index(key)
value = lst.find(key)
m = lst.count(key)
greatest = lst.max()
lowest = lst.min()
print(n, value, m, greatest, lowest)
