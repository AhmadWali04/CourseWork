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
from Stack_array import Stack
stack = Stack()
# Constants
values = [22, 33, 11, 55, 44]
value = 5
for i in range(len(values)):
    stack.push(values[i])
a = stack.is_empty()
b = stack.push((value))
c = stack.pop()
d = stack.peek()
print(f"{a}, {b}, {c}, {d} ")
