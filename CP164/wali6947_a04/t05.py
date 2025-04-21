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


from Queue_array import Queue
from functions import pq_split_key
source = Queue()
src = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
for i in range(len(src)):
    source.insert(src[i])
key = 5
target1, target2 = pq_split_key(source, key)
print(target1._values)
print(target2._values)
