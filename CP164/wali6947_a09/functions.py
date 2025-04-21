"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-03-22"
-------------------------------------------------------
"""
# Imports
from Hash_Set_array import Hash_Set
from Number import Number
# Constants


def insert_words(fv, hash_set):
    """
    -------------------------------------------------------
    Retrieves every Word in file_variable and inserts into
    a Hash_Set. Each Word object in hash_set contains the number
    of comparisons required to insert that Word object from
    file_variable into hash_set.
    Use: insert_words(file_variable, hash_set)
    -------------------------------------------------------
    Parameters:
        fv - the already open file containing data to evaluate (file)
        hash_set - the Hash_Set to insert the words into (Hash_Set)
    Returns:
        None
    -------------------------------------------------------
    """
    line = fv.readline().strip().split(" ")
    while line != "":
        # for the whole length of the text file, we have words that are borken
        # by spaces
        for word in line:
            # for each word we have
            # hash it and then inserts it into the hash set
            hash._set.insert(word)
        line = fv.readline().strip().split("")
    return None


def comparison_total(hash_set):
    """
    -------------------------------------------------------
    Sums the comparison values of all Word objects in hash_set.
    Use: total, max_word = comparison_total(hash_set)
    -------------------------------------------------------
    Parameters:
        hash_set - a hash set of Word objects (Hash_Set)
    Returns:
        total - the total of all comparison fields in the Hash_Set
            Word objects (int)
        max_word - the word having the most comparisons (Word)
    -------------------------------------------------------
    """
    total = 0
    max_word = ''
    for val in hash_set:
        total += val.comparisons
        # for everything in the hash_set, we now add
        # the number of comparisons of each value
        if val.comparisons >= max_word.comparisons:
            max_word = val
    return total, max_word
