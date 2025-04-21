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
q1 = Queue()
q2 = Queue()
for i in range(5):
    q1.insert(i)
    q2.insert(i)
print(q1 == q2)
