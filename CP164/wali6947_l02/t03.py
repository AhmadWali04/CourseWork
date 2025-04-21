"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-01-18"
-------------------------------------------------------
"""
# Imports

# Constants
from Stack_array import Stack
from utilities import stack_to_array

stack = Stack()
target = []
s = [11, 22, 33, 44, 55]
for i in range(len(s)):
    stack.push(s[i])
stack_to_array(stack, target)
print(target)
