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

array = [11, 22, 33, 44, 55, 66]

for item in array:
    lst.append(item)

tar1, tar2 = lst.split_alt_r()
