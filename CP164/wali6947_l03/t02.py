"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-01-24"
-------------------------------------------------------
"""

from Queue_array import Queue
q = Queue()
q.insert(5)
q.insert(6)
q.insert(7)
x = q.remove()
y = q.peek()
print(f"{x}, {y}")