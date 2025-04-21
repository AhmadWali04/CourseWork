package cp213;

import java.util.Scanner;
import java.util.InputMismatchException;

public class Main {

    /**
     * @param args unused
     */
    public static void main(String[] args) {
	System.out.println("Test scannerTest");
	System.out.println();
	Scanner keyboard = new Scanner(System.in);
	int total = scannerTest(keyboard);
	keyboard.close();
	System.out.println("Total: " + total);
	System.out.println();

	System.out.print("Test stringPrinter");
	System.out.println();

	try {
	    String output = stringPrinter(5, "*");
	    System.out.println(output);
	    output = stringPrinter(-5, "*");
	    System.out.println(output);
	} catch (Exception e) {
	    System.out.println();
	    System.out.println("getMessage:");
	    System.out.println(e.getMessage());
	    System.out.println();
	    System.out.println("toString:");
	    System.out.println(e.toString());
	    System.out.println();
	    System.out.println("printStackTrace:");
	    e.printStackTrace();
	}
    }

    /**
     * Uses exceptions to capture bad input from a keyboard Scanner.
     *
     * @return The total of all the integers entered.
     */
    public static int scannerTest(final Scanner keyboard) {
    	int total = 0;
        while (true) {
            System.out.print("Enter an integer (or type 'Quit' to finish): ");
            if (keyboard.hasNext("Quit")) { 
                keyboard.next(); 
                break;
            }
            try {
                int number = keyboard.nextInt();
                total += number;
            } catch (InputMismatchException e) {
                System.out.println("That is not an integer!");
                keyboard.next();
            }
        }
        return total;
    }

    /**
     * Repeats a string.
     *
     * @param n   Number of times to repeat a string.
     * @param str The string to print.
     * @return The repeated string.
     * @throws Exception If n is negative.
     */
    public static String stringPrinter(int n, String str) throws Exception {
    	StringBuilder repeated = new StringBuilder();
    	try {
    		if(n<0) {
    			throw new IllegalArgumentException("n must be greater than 0");
    		}
    		for(int i = 0; i <=n;i++) {
    			repeated.append(str);
    		}
    	}catch(IllegalArgumentException e){
    		System.out.println(e.getMessage());
    	}
	return repeated.toString();
    }

}
