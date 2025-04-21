"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-03-20"
-------------------------------------------------------
"""
# Imports

# Constants

from test_Sort_array import test_sort, SORTS
print("n:   100       |      Comparisons       | |         Swaps          |")
print("Algorithm      In Order Reversed   Random In Order Reversed   Random")
print('-------------- -------- -------- -------- -------- -------- --------')
for i in range(len(SORTS)):
    title = SORTS[i][0]
    func = SORTS[i][1]
    test_sort(title, func)
