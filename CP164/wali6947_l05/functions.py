"""
-------------------------------------------------------
[program description]
-------------------------------------------------------
Author:  Ahmad Wali
ID:      169036947
Email:   wali6947l@mylaurier.ca
__updated__ = "2024-04-16"
-------------------------------------------------------
"""
# Imports

# Constants


def recurse(x, y):
    """
    -------------------------------------------------------
    Recursive function - example of tree recursion.
    Use: ans = recurse(x, y)
    -------------------------------------------------------
    Parameters:
        x - an integer (int)
        y - an integer (int)
    Returns:
        ans - the function result (int)
    -------------------------------------------------------
    """
    if x < 0 or y < 0:
        ans = x - y
        # if both x and y are less than 0 then we get our answer by
        # subtracting them
    else:
        ans = recurse(x - 1, y) + recurse(x, y - 1)
        # otherwise we get out answer by subtracting one from x and one from y until we get them to be less than
        # 0, and then we add them
    return ans


def gcd(m, n):
    """
    -------------------------------------------------------
    Recursively find the Greatest Common Denominator of two numbers.
    Use: ans = gcd(m, n)
    -------------------------------------------------------
    Parameters:
        n - an integer (int)
        m - an integer (int)
    Returns:
        ans - the function result (int)
    -------------------------------------------------------
    """
    if m % n == 0:
        ans = n
        # if n divides into m perfectly then it is the greatest common
        # denominator
    else:
        ans = gcd(n, m % n)
        # if they dont divide perfectly into eachother, run it again with
        # m as the remainder after dividing itself
    return ans


def vowel_count(s):
    """
    -------------------------------------------------------
    Recursively counts number of vowels in a string.
    Use: count = vowel_count(s)
    -------------------------------------------------------
    Parameters:
        s - string to examine (str)
    Returns:
        count - number of vowels in s (int)
    -------------------------------------------------------
    """
    # "Good"
    vowels = 'aeiouAEIOU'
    if s == "":
        count = 0
        # if the string is nothing then its 0
    elif s[0] in vowels:
        count = 1 + vowel_count(s[1:])
        # otherwise we check if the first index is the string vowels
        # and we count again, while calling it again wihtout the first
        # character anymore
    else:
        count = vowel_count(s[1:])
        # otherwise just call it without the first character
    return count


def to_power(base, power):
    # this needs to work for negative exponents
    """
    -------------------------------------------------------
    Calculates base^power.
    Use: ans = to_power(base, power)
    -------------------------------------------------------
    Parameters:
        base - base to apply power to (float)
        power - power to apply (int)
    Returns:
        ans - base ^ power (float)
    -------------------------------------------------------
    """
    # if statment is my final case

    if power == 0:
        ans = 1
    elif power >= 1:
        # if the power is above 1
        ans = base * to_power(base, power - 1)
        # 5^4 = 5 * 5^3 ..
    else:
        ans = 1 / (base * to_power(base, (abs(power + 1))))
        # once our power is 1, we
    return ans


def is_palindrome(s):
    """
    -------------------------------------------------------
    Recursively determines if s is a palindrome. Ignores non-letters and case.
    Use: palindrome = is_palindrome(s)
    -------------------------------------------------------
    Parameters:
        s - a string (str)
    Returns:
        palindrome - True if s is a palindrome, False otherwise (boolean)
    -------------------------------------------------------
    """
    palindrome = True
    s = s.lower()
    # this just makes the string a lower case
    if s.isalpha() == False and len(s) <= 1:
        # if the strings length is greater than 1
        palindrome = True
        print(f"if statment: {s}")
        # stop checking for a palindrome if we only have 1 piece left
    else:
        palindrome = s[0] == s[-1] and is_palindrome(s[1:-1])
        # if the first and last chraacters match, return the palindrome the
        # string spliced
        print(f"else statement: {s}")
    return palindrome


def bag_to_set(bag):
    """
    -------------------------------------------------------
    Copies elements of a bag to a set.
    Use: new_set = bag_to_set(bag)
    -------------------------------------------------------
    Parameters:
        bag - a list of values (list)
    Returns:
        new_set - containing one each of the elements in bag (list)
    -------------------------------------------------------
    """
    if len(bag) == 0:
        new_set = []
    # if its an empty list then new_set is also an empty list
    else:
        new_set = bag_to_set(bag[:-1])
        # we make a list without the last element
        if bag[-1] not in new_set:
            # if the last element in the old list is not in the new list
            new_set.append(bag[-1])
            # then we add the last element from the old list into the new list
    return new_set
