"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-02-02"
-------------------------------------------------------
"""
from Queue_circular import Queue
src = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
q = Queue()
for i in range(len(src)):
    q.insert(src[i])
    print(q._values)
while q.is_empty() == False:
    q.remove()
    print(q._values)
q.remove()
