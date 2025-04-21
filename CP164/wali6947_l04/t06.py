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
from utilities import array_to_list, list_to_array
target = []
ToAppend = [1, 2, 3, 4, 5]
llist = []
source = []
for i in ToAppend:
    llist.append(ToAppend[i])
for i in ToAppend:
    source.append(ToAppend[i] * i)
array_to_list(llist, source)
list_to_array(llist, target)
