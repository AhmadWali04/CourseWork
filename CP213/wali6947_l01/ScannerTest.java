package cp213;

import java.io.File;
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

/**
 * Class to demonstrate the use of Scanner with a keyboard and File objects.
 *
 * @author Ahmad Wali/wali6947@mylaurier.ca/ID#169036947
 * @version 2022-01-08
 */
public class ScannerTest {

	/**
	 * Count lines in the scanned file.
	 *
	 * @param source Scanner to process
	 * @return number of lines in scanned file
	 */

//ERRORES:
	/**
	 * 1/2. I neeed to understand my file not found exception error
	 * also how does path to a file work
	 * and also how to pass a file through the scanner 
	 */

	// THIS PROGRAM SHOULD PROLLY USE A TRY/CATCH BLOCK TO MAKE SURE THAT IT GETS
	// THE FILE RIGHT
	public static int countLines(final Scanner source) {
		int count = 0;
		try {
			File file = new File("player.txt");
			while (source.nextLine() != null) {
				source = source.nextLine();
				count++;
			}
		} catch (FileNotFoundException e) {
			System.out.println("File not Found");
		}
		return count;
	}

	/**
	 * Count tokens in the scanned object.
	 *
	 * @param source Scanner to process
	 * @return number of tokens in scanned object
	 */
	// THIS ALSO NEEDS A TRY CATCH BLOCK
	public static int countTokens(final Scanner source) {
		int tokens = 0;
		Scanner fileIn = null;
		try {
			fileIn = new Scanner(new FileInputStream("player.txt"));
		} catch (FileNotFoundException e) {
			System.out.println("File not found.");
			System.exit(0);
		}
		while (source.hasNext()) {
			source.next();
			tokens++;
		}
		return tokens;
	}

	/**
	 * Ask for and total integers from the keyboard.
	 *
	 * @param source Scanner to process
	 * @return total of positive integers entered from keyboard
	 */
	public static int readNumbers(final Scanner keyboard) {
		// Create variables needed
		int total = 0;
		System.out.println("Enter an integer, press q to quit");
		String input = keyboard.next();
		while (input.equals("q") == false) {
			try {
				int number = Integer.parseInt(input);
				total += number;
			}
			catch (NumberFormatException e) {
				System.out.println( input + " is not an integer, please enter a number or press q to quit");
			}
			input = keyboard.next();
		}
		return total;

	}

}
