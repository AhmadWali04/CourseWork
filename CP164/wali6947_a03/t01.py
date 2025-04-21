"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-01-26"
-------------------------------------------------------
"""
# Imports

# Constants
from Stack_array import Stack
from functions import stack_combine
stack1 = Stack()
stack2 = Stack()
source1 = [5, 8, 12, 8]
for i in range(len(source1)):
    stack1.push(source1[i])
source2 = [3, 6, 1, 7, 9, 14]
for i in range(len(source2)):
    stack2.push(source2[i])
stack_combine(stack1, stack2)
