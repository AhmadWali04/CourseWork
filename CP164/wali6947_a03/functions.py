"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-01-27"
-------------------------------------------------------
"""
# Imports

# Constants
from Stack_array import Stack


def stack_combine(source1, source2):
    """
    -------------------------------------------------------
    Combines two source stacks into a target stack.
    When finished, the contents of source1 and source2 are interlaced
    into target and source1 and source2 are empty.
    Use: target = stack_combine(source1, source2)
    -------------------------------------------------------
    Parameters:
        source1 - a stack (Stack)
        source2 - another stack (Stack)
    Returns:
        target - the contents of the source1 and source2
            are interlaced into target (Stack)
    -------------------------------------------------------
    """
    target = Stack()
    while not source1.is_empty() and not source2.is_empty():
        target.push(source1.pop())
        target.push(source2.pop())

    while not source1.is_empty():
        target.push(source1.pop())

    while not source2.is_empty():
        target.push(source2.pop())

    return target


def stack_reverse(source):
    """
    -------------------------------------------------------
    Reverses the contents of a stack.
    Use: stack_reverse(source)
    -------------------------------------------------------
    Parameters:
        source - a Stack (Stack)
    Returns:
        None
    -------------------------------------------------------
    """
    values = []
    # takes the source stack, pushes it all into a list, then
    while source.is_empty() == False:
        values.append(source.pop())
        # puts this whole stack into a list
    while len(values) != 0:
        value = values.pop(0)
        source.push(value)
    return None


def is_palindrome_stack(string):
    """
    -------------------------------------------------------
    Determines if string is a palindrome. Ignores case, digits, spaces, and
    punctuation in string.
    Use: palindrome = is_palindrome_stack(string)
    -------------------------------------------------------
    Parameters:
        string - a string (str)
    Returns:
        palindrome - True if string is a palindrome, False otherwise (bool)
    -------------------------------------------------------
    """
    stack = Stack()
    palindrome = True
    punctuation = [".", ",", "!", "?", ":", ";",
                   '-', "'", '"', "(", ")", "{", "}", "[", "]"]
    cleanString = ""
    # this will be the string once its completely cleaned up (gets put into
    # the stack)
    temp = ""
    # this will be the string spit out of the stack
    for i in range(len(string)):
        if string[i].isspace() == False and string[i].isdigit() == False and string[i] not in punctuation:
            cleanString += string[i].lower()
            # this creates a new lowercase string thats clean and usable for
            # checking
    for ii in range(len(cleanString)):
        stack.push(cleanString[ii])
        # this pushes that whole string into a stack
    while stack.is_empty() == False:
        letter = stack.pop(0)
        temp += letter
    if temp != cleanString:
        palindrome = False


# Constants
OPERATORS = "+-*/"


def postfix(string):
    """
    -------------------------------------------------------
    Evaluates a postfix expression.
    Use: answer = postfix(string)
    -------------------------------------------------------
    Parameters:
        string - the postfix string to evaluate (str)
    Returns:
        answer - the result of evaluating string (float)
    -------------------------------------------------------
    """
    OPERATORS = ["+", "-", "*", "/"]
    stack = Stack()
    for i in range(len(string)):
        if i not in OPERATORS:
            stack.push(i)
        else:
            first = stack.pop()
            sec = stack.pop()
            if i == "+":
                stack.push(sec + first)
            elif i == "-":
                stack.push(sec - first)
            elif i == "/":
                stack.push(sec / first)
            elif i == "*":
                stack.push(sec * first)
    answer = stack.peek()
    return answer


def stack_maze(maze):
    """
    -------------------------------------------------------
    Solves a maze using Depth-First search.
    Use: path = stack_maze(maze)
    -------------------------------------------------------
    Parameters:
        maze - dictionary of points in a maze, where each point
            represents a corridor end or a branch. Dictionary
            keys are the name of the point followed by a list of
            branches, if any. First point is named 'Start', exit
            is named 'X' (dict)
    Returns:
        path - list of points visited before the exit is reached,
            does not include 'Start', but does include 'X'.
            Return None if there is no exit (list of str)
    -------------------------------------------------------
    """
    # maze = {'Start': ['A'], 'A':['B', 'C'], 'B':[], 'C':['D', 'E'],
    #     'D':[], 'E':['F', 'X'], 'F':['G', 'H'], 'G':[], 'H':[]}
    stack = Stack()
    path = []
    key = 'Start'
    value = maze[key]
    # key is the individual character, value is a list of position we can go to next
    # creates stack/ creates a new list/starts our dictionary at the beggining
    for i in range(len(value)):
        stack.push(value[i])
    # value here will represent stuff like all of the letters inside of index A, so we loop through it
    # and then when we loop, we add it to our stack
    key = stack.pop()
    # then we take that new letter, and we now move forward to the new A
    # position
    # this will put A into our path
    while key != 'X' and key not in path:
        # until we get to the final position, and we dont go somewhere weve
        # already went
        path.append(key)
        # already gone
        value = maze[key]
        # the list of possible next positions in the path
        for i in range(len(value)):
            stack.push(value[i])
            # loop through it to add it to our stack
        key = stack.pop()
        # we pop it so we can move forward to the next location aswell as mark
        # it as part of our path
        # list this location down as somewhere weve already been
    return path
