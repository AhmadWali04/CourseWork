"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-02-10"
-------------------------------------------------------
"""
# Imports

# Constants

from Sorted_List_array import Sorted_List
test = Sorted_List()
values = [1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
for i in range(len(values)):
    test.insert(values[i])
# b = test == test2

# adding things to my sorted list
print(f"First list VVV")
for i in test:
    print(i)
key = 1
test.remove_many(key)
print("removing many:")
for i in test:
    print(i)
