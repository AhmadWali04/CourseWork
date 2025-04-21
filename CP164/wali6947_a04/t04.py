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
# Imports

# Constants


from Queue_array import Queue
q = Queue()
lst = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
for i in range(len(lst)):
    q.insert(lst[i])
# making a queue and inserting it
target1, target2 = q.split_alt()
print(target1._values)
print(target2._values)
