package cp213;

/**
 * Sample string methods.
 *
 * @author your name, ID, and email here
 * @version 2022-05-06
 */
public class StringMethods {
	// Constants
	/**
	 * String of vowels.
	 */
	public static final String VOWELS = "aeiouAEIOU";

	/**
	 * Counts the number of vowels in a string. Does not include 'y'.
	 *
	 * @param string A string.
	 * @return Number of vowels in string.
	 */
	public static int vowelCount(final String string) {
		int count = 0;
		// Lets take a variable "char" that increments through the string
		// and make it check if char in vowels
		// increment char
		char letter;
		char check;
		for (int i = 0; i < string.length(); i++) {
			letter = string.charAt(i);
			// if letter IN vowels
			for (int j = 0; j < VOWELS.length(); j++) {
				check = VOWELS.charAt(j);
				if (letter == check) {
					count++;
				}

			}

		}

		// your code here

		return count;
	}

	/**
	 * Counts the number of digits in a string.
	 *
	 * @param string A string.
	 * @return Number of digits in string.
	 */
	public static int digitCount(final String string) {
		int count = 0;
		char check;
		for (int i = 0; i < string.length();i++) {
			//going through the length of the string
			check = string.charAt(i);
			if(Character.isDigit(check)) {
				count++;
			}
		}

		return count;
	}

	/**
	 * Totals the individual digits in a string.
	 *
	 * @param string A string.
	 * @return The integer total of all individuals digits in string.
	 */
	public static int totalDigits(final String string) {
		int total = 0;
		char check;
		int num;
		for (int i = 0; i < string.length();i++) {
			//going through the length of the string
			check = string.charAt(i);
			if(Character.isDigit(check)) {
				num = Character.getNumericValue(check);
				total += num;
			}
		}
		
		return total;
	}

	/**
	 * Compares string1 and string2 and returns a comma-delimited concatenated
	 * string consisting of the string that is first lexically followed by the
	 * string that is second lexically. If the strings are equal, then only string1
	 * is returned.
	 *
	 * @param string1 String to compare against string2.
	 * @param string2 String to compare against string1.
	 * @return A concatenation of string1 and string2 in order.
	 */
	public static String pairs(String string1, String string2) {
		String line = null;
		if (string1.equals(string2)){
			line = string1;
		} else {
			int check = string1.compareTo(string2);
			if(check > 0) {
				line = string2 + "," + string1;
			}if (check<0) {
				line = string1 + "," + string2;
			}
		}
		return line;
	}

	/**
	 * Finds the distance between the s1 and s2. The distance between two strings of
	 * the same length is the number of positions in the strings at which their
	 * characters are different. If two strings are not the same length, the
	 * distance is unknown (-1). If the distance is zero, then two strings are
	 * equal.
	 *
	 * @param string1 String to compare against string2.
	 * @param string2 String to compare against string1.
	 * @return The distance between string1 and string2.
	 */
	public static int stringDistance(String string1, String string2) {
		int distance = 0;
		char check1;
		char check2;
		if (string1.length() != (string2.length())) {
			distance = -1;
		}else {
			for (int i = 0; i < string1.length(); i ++) {
				check1 = string1.charAt(i);
				check2 = string2.charAt(i);
				if (check1 != check2) {
					distance ++;
				}
					
			}
		}
		return distance;
	}
}
