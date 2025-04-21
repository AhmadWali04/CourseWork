package cp213;

import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author Ahmad Wali
 * @version 2024-10-03
 */
public class SerialNumber {

	/**
	 * Determines if a string contains all digits.
	 *
	 * @param str The string to test.
	 * @return true if str is all digits, false otherwise.
	 */
	public static boolean allDigits(final String str) {
		boolean valid = true;
		int length = str.length();
		char check;
		
		for(int i = 0; i <= str.length()-1;i++) {
			check = str.charAt(i);
			if (Character.isDigit(check) == false) {
				valid = false;
			}
		}
		return valid;
	}

	/**
	 * Determines if a string is a good serial number. Good serial numbers are of
	 * the form 'SN/nnnn-nnn', where 'n' is a digit.
	 *
	 * @param sn The serial number to test.
	 * @return true if the serial number is valid in form, false otherwise.
	 */
	public static boolean validSn(final String sn) {
		if (sn.length() == 11){
			if (sn.substring(0,3).equals("SN/")) {
				String firstFour = sn.substring(3,7);
					if (allDigits(firstFour)){
						if (sn.charAt(7) =='-'){
							String lastThree = sn.substring(8);
							if(allDigits(lastThree)) {
								return true;
							}
						}
				}	
			}
			
		}
		return false;
	}

	/**
	 * Evaluates serial numbers from a file. Writes valid serial numbers to
	 * good_sns, and invalid serial numbers to bad_sns. Each line of fileIn contains
	 * a (possibly valid) serial number.
	 *
	 * @param fileIn  a file already open for reading
	 * @param goodSns a file already open for writing
	 * @param badSns  a file already open for writing
	 */
	public static void validSnFile(final Scanner fileIn, final PrintStream goodSns, final PrintStream badSns) {
	       while (fileIn.hasNextLine()) {
	            String sn = fileIn.nextLine();
	            if (validSn(sn)) {
	                goodSns.println(sn);
	            } else {
	                badSns.println(sn);
	            }
	        }
		return;
	}
}
