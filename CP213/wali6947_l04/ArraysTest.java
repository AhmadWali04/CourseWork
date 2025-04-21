package cp213;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Arrays Lab task methods.
 *
 * @author
 * @version 2022-01-25
 */
public class ArraysTest {

	/**
	 * Tests arrays.
	 *
	 * @param args unused default parameter
	 */
	public static void main(final String[] args) {
		System.out.println("Task 1");
		System.out.println(ArraysTest.task1());
		System.out.println("Task 2");
		System.out.println(ArraysTest.task2());
		System.out.println("Task 3");
		System.out.println(ArraysTest.task3());
		System.out.println("Task 4");
		System.out.println(ArraysTest.task4());
		System.out.println("Task 5");
		System.out.println(Arrays.toString(ArraysTest.task5()));
	}

	/**
	 * Print the contents of the arrays first and second using a standard for loop.
	 *
	 * @return true if second contains the same values as first, false otherwise
	 */
	public static boolean task1() {
		final int[] first = { 1, 3, 5, 7, 9 };
		final int[] second = first;
		System.out.println("FIRST ARRAY");
		for (int i = 0; i < first.length - 1; i++) {
			System.out.println(first[i]);
		}
		System.out.println("SECOND ARRAY");
		for (int j = 0; j < second.length - 1; j++) {
			System.out.println(second[j]);
		}
		return Arrays.equals(first, second);
	}

	/**
	 * Double the contents of the array first with a standard for loop.
	 *
	 * @return true if second contains the same values as first, false otherwise
	 */
	public static boolean task2() {
		final int[] first = { 1, 3, 5, 7, 9 };
		final int[] second = first;
		for (int i = 0; i <= first.length - 1; i++) {
			first[i] *= 2;
		}
		return Arrays.equals(first, second);
	}

	/**
	 * Double the contents of the array first with an enhanced for loop.
	 *
	 * @return true if the values in first are permanently changed, false otherwise
	 */
	public static boolean task3() {
		final int[] first = { 1, 3, 5, 7, 9 };
	    int[] expected = { 2, 6, 10, 14, 18 };

		for (int numbers : first) {
			numbers = numbers * 2;
		}
		return Arrays.equals(first, expected);
	}

	/**
	 * Attempt to assign the array first to a row of the 2D array third.
	 *
	 * @return true if this is allowed, false otherwise
	 */
	public static boolean task4() {
		final int[] first = { 1, 3, 5, 7, 9 };
		final int[][] third = { first, { 1, 2, 3, 4, 5 }, { 7, 3, 6, 9, 12 }, { 14, 566, 2, 4, 8 } };

		// creates a 2D array and assigns the first row to the 1D array called "first"
		// your code here
		if (third[0] == first) {
			return true;
		} else {
			return false;
		}

	}

	/**
	 * Assign the values 0 through 9 to an Integer ArrayList.
	 *
	 * @return the contents of the ArrayList as an Integer[] array.
	 */
	public static Integer[] task5() {
		final ArrayList<Integer> values = new ArrayList<>();
		  for (int i = 0; i < 10; i++) {
		        values.add(i);
		    }
		    Integer[] array = new Integer[values.size()];
		    array = values.toArray(array);
		    return array;

	}
}
