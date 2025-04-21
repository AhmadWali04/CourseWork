"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:    wali6947@mylaurier.ca
__updated__ = "2024-01-13"
-------------------------------------------------------
"""
from functions import matrix_stats
a = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
small, large, total, average = matrix_stats(a)
print(f"{small}, {large}, {total}, {average}")
