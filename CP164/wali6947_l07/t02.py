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
lst2 = List()

arr = [22, 44, 33, 55, 11]

for item in arr:
    lst.append(item)
    lst2.append(item)

identical1 = lst.is_identical_r(lst2)

lst2.remove_front()

identical2 = lst.is_identical_r(lst2)
