"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-01-25"
-------------------------------------------------------
"""
from Queue_array import Queue
from utilities import array_to_queue, queue_to_array, queue_test
# imports the class aswell as importing the funtions
queue = Queue()
# creates a new queue
target = []
a = [1, 2, 3]
# these are just parameters for the functions
for i in a:
    queue.insert(a[i - 1])
    # this is just making a queue array with the elements of a in it
source = [11, 22, 33, 44]
x = array_to_queue(queue, source)

y = queue_to_array(queue, target)
z = queue_test(a)
