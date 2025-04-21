"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-02-03"
-------------------------------------------------------
"""
# Imports

# Constants

from functions import queue_split_alt
from Queue_array import Queue
lst = [1, 2, 3, 4, 5, 6, 7, 8, 9]
source = Queue()
for i in range(len(lst)):
    source.insert(lst[i])
target1, target2 = queue_split_alt(source)
print(target1._values)
print(target2._values)
