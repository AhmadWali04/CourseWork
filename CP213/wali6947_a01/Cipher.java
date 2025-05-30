package cp213;

/**
 * @author Ahmad Wali
 * @version 2024-10-03
 */
public class Cipher {
    // Constants
    public static final String ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    public static final int ALPHA_LENGTH = ALPHA.length();

    /**
     * Encipher a string using a shift cipher. Each letter is replaced by a letter
     * 'n' letters to the right of the original. Thus for example, all shift values
     * evenly divisible by 26 (the length of the English alphabet) replace a letter
     * with itself. Non-letters are left unchanged.
     *
     * @param s string to encipher
     * @param n the number of letters to shift
     * @return the enciphered string in all upper-case
     */
    public static String shift(final String s, final int n) {
    	String shifted = "";
    	for(int i = 0; i <= s.length()-1; i++) {
    		char letter = s.charAt(i);
    		// go through my string 
    		for (int j = 0; j < ALPHA_LENGTH-1;j++) {
    			if (Character.toUpperCase(letter) == ALPHA.charAt(j)) {
    				//find it in the alphabet
    				int spot = (j + n) % ALPHA_LENGTH;
    				//find the letter to replace it with
    				String newLetter = Character.toString(ALPHA.charAt(spot));
    				shifted += newLetter;
    			}
    		}
    	}
	return shifted;
    }

    /**
     * Encipher a string using the letter positions in ciphertext. Each letter is
     * replaced by the letter in the same ordinal position in the ciphertext.
     * Non-letters are left unchanged. Ex:
     *
     * <pre>
    Alphabet:   ABCDEFGHIJKLMNOPQRSTUVWXYZ
    Ciphertext: AVIBROWNZCEFGHJKLMPQSTUXYD
     * </pre>
     *
     * A is replaced by A, B by V, C by I, D by B, E by R, and so on. Non-letters
     * are ignored.
     *
     * @param s          string to encipher
     * @param ciphertext ciphertext alphabet
     * @return the enciphered string in all upper-case
     */
    public static String substitute(final String s, final String ciphertext) {
    	String cipher = "";
    	for (int i = 0; i < s.length();i++) {
    		char check = s.charAt(i);
    		for(int j = 0;j < ALPHA.length();j++) {
    			if (check == ALPHA.charAt(j)){
    				String newLetter = Character.toString(ciphertext.charAt(j));
    				cipher += newLetter;
    			}
    		}
    	}
	return cipher;
    }
}
