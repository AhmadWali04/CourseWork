package cp213;

/**
 * @author Ahmad Wali
 * @version 2024-10-03
 */
public class Strings {
	// Constants
	public static final String VOWELS = "aeiouAEIOU";

	/**
	 * Determines if string is a "palindrome": a word, verse, or sentence (such as
	 * "Able was I ere I saw Elba") that reads the same backward or forward. Ignores
	 * case, spaces, digits, and punctuation in the string parameter s.
	 *
	 * @param string a string
	 * @return true if string is a palindrome, false otherwise
	 */
	public static boolean isPalindrome(final String string) {
		// first set the string to all lowercase
		// set the string to no spaces
		// set the string to lose digits and punctuation
		Boolean palindrome = true;
		String lower = string.toLowerCase();
		String noDigit = lower.replaceAll("1234567890", "");
		String noSpace = noDigit.replaceAll(" ","");
		String clean = noSpace.replaceAll("\\p{Punct}", "");
		//now that I have a clean string
		for(int i = 0; i < clean.length()/2;i++) {
			if (clean.charAt(i) != clean.charAt(clean.length()-i-1)){
				palindrome = false;
			}
		}
		return palindrome;
	}

	/**
	 * Determines if name is a valid Java variable name. Variables names must start
	 * with a letter or an underscore, but cannot be an underscore alone. The rest
	 * of the variable name may consist of letters, numbers and underscores.
	 *
	 * @param name a string to test as a Java variable name
	 * @return true if name is a valid Java variable name, false otherwise
	 */
	public static boolean isValid(final String name) {
		char check;
		boolean valid = true;
		// if its one character long, and its not a letter its false
		if (name.length() == 1) {
			check = name.charAt(0);
			if (Character.isLetter(check) == false) {
				valid = false;
			}
			// if the string starts with a letter
			// if the string only contains letters and underscores
			// if the strings longer than 1
		} else if (name.length() > 1) {
			check = name.charAt(0);
			// it must start with _ or a leter
			if (Character.isLetter(check) || check == '_') {
				for (int i = 1; i < name.length() - 1; i++) {
					if (check != '_' && Character.isLetter(check) == false && Character.isDigit(check) == false) {
						valid = false;
					}
				}
			} else {
				valid = false;
			}
		}
		return valid;
	}


	/**
	 * Converts a word to Pig Latin. The conversion is:
	 * <ul>
	 * <li>if a word begins with a vowel, add "way" to the end of the word.</li>
	 * <li>if the word begins with consonants, move the leading consonants to the
	 * end of the word and add "ay" to the end of that. "y" is treated as a
	 * consonant if it is the first character in the word, and as a vowel for
	 * anywhere else in the word.</li>
	 * </ul>
	 * Preserve the case of the word - i.e. if the first character of word is
	 * upper-case, then the new first character should also be upper case.
	 *
	 * @param word The string to convert to Pig Latin
	 * @return the Pig Latin version of word
	 */
	public static String pigLatin(String word) {
		 // Find the index of the first vowel
		int len = word.length();
		int firstVowelIndex = -1;
        for (int i = 0; i < len; i++) {
            char c = word.charAt(i);
            if (VOWELS.indexOf(c) != -1) {
                firstVowelIndex = i;
                break;
            }
        }

        // If the word starts with a vowel
        if (firstVowelIndex == 0) {
            return word + "way";
        }

        // If the word starts with consonants
        if (firstVowelIndex > 0) {
            String prefix = word.substring(0, firstVowelIndex);
            String suffix = word.substring(firstVowelIndex);
            String pigLatinWord = suffix + prefix + "ay";

            // Preserve the case of the first character
            if (Character.isUpperCase(word.charAt(0))) {
                pigLatinWord = Character.toUpperCase(pigLatinWord.charAt(0)) + pigLatinWord.substring(1).toLowerCase();
            }

            return pigLatinWord;
        }

		
		return null;
	}
}
