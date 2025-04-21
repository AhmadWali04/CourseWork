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
# Imports

# Constants

from Priority_Queue_array import Priority_Queue
from utilities import array_to_pq, pq_to_array, priority_queue_test
pq = Priority_Queue()
source = [11, 22, 33, 44]
target = []
a = [3, 2, 1]
for a in pq:
    pq.insert(a)
array_to_pq(pq, source)
pq_to_array(pq, target)
priority_queue_test(a)
