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
lst1 = List()
lst2 = List()

arr = [11, 22, 33, 44, 55, 66]

for item in arr:
    lst1.append(item)
    lst2.append(item)

lst3 = List()

lst3.intersection_r(lst1, lst2)
