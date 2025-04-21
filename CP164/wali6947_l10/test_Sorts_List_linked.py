"""
-------------------------------------------------------
Tests various linked sorting functions.
-------------------------------------------------------
Author:  David Brown
ID:      999999999
Email:   dbrown@wlu.ca
Section: CP164 C
__updated__ = "2024-03-22"
-------------------------------------------------------
"""
# Imports
from random import randint
from List_linked import List, _List_Node
from Number import Number
from Sorts_List_linked import Sorts

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
)


def create_sorted():
    """
    -------------------------------------------------------
    Creates a sorted List of Number objects.
    Use: values = create_sorted()
    -------------------------------------------------------
    Returns:
        values - a sorted list of SIZE Number objects (List of Number)
    -------------------------------------------------------
    """
    values = List()
    for num in range(SIZE):
        values.append(Number(num))
    return values


def create_reversed():
    """
    -------------------------------------------------------
    Create a reversed List of Number objects.
    Use: values = create_reversed()
    -------------------------------------------------------
    Returns:
        values - a reversed list of SIZE Number objects (List of Number)
    -------------------------------------------------------
    """
    values = List()
    for val in range(SIZE - 1, -1, -1):
        values.append(Number(val))
    return values


def create_randoms():
    """
    -------------------------------------------------------
    Create a 2D list of Number objects with TESTS rows and
    SIZE columns of values between 0 and XRANGE.
    Use: lists = create_randoms()
    -------------------------------------------------------
    Returns:
        lists - TESTS lists of SIZE Number objects containing
            values between 0 and XRANGE (list of List of Number)
    -------------------------------------------------------
    """
    lists = List()
    for i in range(TESTS):
        cols = List()
        for j in range(SIZE):
            cols.append(Number(randint(0, XRANGE)))
        lists.append(cols)
    return lists


def test_sort(title, func):
    """
    -------------------------------------------------------
    Tests a sort function with Number data and prints the number 
    of comparisons necessary to sort an array:
    in order, in reverse order, and a list of Lists in random order.
    Use: test_sort(title, func)
    -------------------------------------------------------
    Parameters:
        title - name of the sorting function to call (str)
        func - the actual sorting function to call (function)
    Returns:
        None
    -------------------------------------------------------
    """
    Number.comparisons = 0
    Sorts.swaps = 0
    value = create_sorted()
    func(value)
    orderTotal = int(Number.comparisons)
    orderSwaps = int(Sorts.swaps)

    Number.comparisons = 0
    Sorts.swaps = 0
    value = create_reversed()
    func(value)
    revTotal = int(Number.comparisons)
    revSwaps = int(Sorts.swaps)

    Number.comparisons = 0
    Sorts.swaps = 0
    arrays = create_randoms()
    randTotal = int(Number.comparisons // TESTS)
    randSwaps = int((Sorts.swaps) // TESTS)
    for i in arrays:
        func(i)
    print(f"{title} {orderTotal} {revTotal} {randTotal} {orderSwaps} {revSwaps} {randSwaps}")
    return
