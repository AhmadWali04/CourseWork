"""
-------------------------------------------------------
Tests various array-based sorting functions.
-------------------------------------------------------
Author:  David Brown
ID:      999999999
Email:   dbrown@wlu.ca
Section: CP164 C
__updated__ = "2024-03-22"
-------------------------------------------------------
"""
# Imports
from Number import Number
from random import randint
from Sorts_array import Sorts

# Constants
SIZE = 100  # Size of array to sort.
XRANGE = 1000  # Range of values in random arrays to sort.
TESTS = 100  # Number of random arrays to generate.

SORTS = (
    ('Bubble Sort', Sorts.bubble_sort),
    ('Insertion Sort', Sorts.insertion_sort),
    ('Merge Sort', Sorts.merge_sort),
    ('Quick Sort', Sorts.quick_sort),
    ('Selection Sort', Sorts.selection_sort),
    ('Bin. Ins. Sort', Sorts.binary_insert_sort),
    ('BST Sort', Sorts.bst_sort),
    ('Cocktail Sort', Sorts.cocktail_sort),
    ('Comb Sort', Sorts.comb_sort),
    ('Heap Sort', Sorts.heap_sort),
    ('Shell Sort', Sorts.shell_sort)
)


def create_sorted():
    """
    -------------------------------------------------------
    Creates a sorted list of SIZE Number objects with values
    from 0 up to SIZE-1.
    Use: values = create_sorted()
    -------------------------------------------------------
    Returns:
        values - a sorted list of SIZE Number objects (list of Number)
    -------------------------------------------------------
    """
    values = []
    for i in range(SIZE):
        values.append(Number(i))
        # we have a number "object" that is created with i
        # see Number.py on creating number objecct
    return values


def create_reversed():
    """
    -------------------------------------------------------
    Create a reversed list of SIZE Number objects with values
    from SIZE-1 down to 0.
    Use: values = create_reversed()
    -------------------------------------------------------
    Returns:
        values - a reversed list of SIZE Number objects (list of Number)
    -------------------------------------------------------
    """
    values = []
    for i in range(SIZE - 1, -1, -1):
        values.append(Number(i))
    return values


def create_randoms():
    """
    -------------------------------------------------------
    Create a 2D list of Number objects with TESTS rows and
    SIZE columns of values between 0 and XRANGE.
    Use: lists = create_randoms()
    -------------------------------------------------------
    Returns:
        arrays - TESTS lists of SIZE Number objects containing
            values between 0 and XRANGE (list of list of Number)
    -------------------------------------------------------
    """
    arrays = []
    for i in range(TESTS):
        col = []
        for j in range(SIZE):
            col.append(Number(randint(0, XRANGE)))
        arrays.append(col)
    return arrays


def test_sort(title, func):
    """
    -------------------------------------------------------
    Test a sort function with Number data and prints the number 
    of comparisons necessary to sort an array:
    in order, in reverse order, and a list of arrays in random order.
    Use: test_sort(title, func)
    -------------------------------------------------------
    Parameters:
        title - name of the sorting function to call (str)
        func - the actual sorting function to call (function)
    Returns:
        None
    -------------------------------------------------------
    """
    # sorts has swaps, number has comparisons
    value = create_sorted()
    Number.comparisons = 0
    Sorts.swaps = 0
    func(value)
    sortedComp = int(Number.comparisons)
    sortedSwaps = int(Sorts.swaps)
    # makes a new sorted list, then sets # of comparisons before
    # runs it througha  function, and then saves the number of
    # sorts and swaps it returns as an integer
    value = create_reversed()
    Number.comparisons = 0
    Sorts.swaps = 0
    func(value)
    revComp = int(Number.comparisons)
    revSwaps = int(Sorts.swaps)
    # does the same thing but with the reversed
    list = create_randoms()
    Number.comparisons = 0
    Sorts.swaps = 0
    func(list)
    randComp = Number.comparisons
    randSwaps = Sorts.swaps
    print(f"{title}  {sortedComp} {revComp} {randComp}    {
          sortedSwaps} {revComp}  {randComp}")
    return
