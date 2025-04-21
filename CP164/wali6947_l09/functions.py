"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-03-13"
-------------------------------------------------------
"""
# Imports
from Food import Food
from Hash_Set_array import Hash_Set
# Constants


def hash_table(slots, values):
    """
    -------------------------------------------------------
    Print a hash table of a set of values. The format is:
Hash     Slot Key
-------- ---- --------------------
     695    2 Lasagna, 7
    1355    4 Butter Chicken, 2
    Do not create an actual Hash_Set.
    Use: hash_table(slots, values)
    -------------------------------------------------------
    Parameters:
       slots - the number of slots available (int > 0)
       values - the values to hash (list of ?)
    Returns:
       None
    -------------------------------------------------------
    """
    print("Hash     Slot Key")
    print("-----------------")
    for i in range(len(values)):
        # i is just the index
        h = hash(values[i])
        # this takes the pre made hash coding function and turns something into
        # a hash number
        slot = h % slots
        # assign it a slot space
        print(f"{h: >5} {slot: >3} {i.name}, {i.origin}")
    # this will tell me the slot it will belong in
