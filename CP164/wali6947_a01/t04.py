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
from functions import file_analyze
fv = open("file.txt", "r", encoding="utf-8")
upp, low, dig, whi, rem = file_analyze(fv)
print(f"{upp}, {low}, {dig}, {whi}, {rem}")
fv.close()
