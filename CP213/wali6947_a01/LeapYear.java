package cp213;

/**
 * @author Ahmad Wali
 * @version 2024-10-03
 */
public class LeapYear {

	/**
     * Determines whether or not a year is a leap year.
     *
     * A leap year is defined as:
     *
     * "Every year that is exactly divisible by four is a leap year, except for
     * years that are exactly divisible by 100, but these centurial years are leap
     * years if they are exactly divisible by 400. For example, the years 1700,
     * 1800, and 1900 are not leap years, but the years 1600 and 2000 are." (United
     * States Naval Observatory)
     *
     * Thus 1996, 2000, and 2004 are leap years, but 1899, 1900, and 1901 are not
     * leap years."
     *
     * @param year The year to test (int greater than 0)
     * @return true if year is a leap year, false otherwise.
     */
    public static boolean isLeapYear(final int year) {
    	if (year < 0) {
            System.out.println("Years cant be negative");
            System.exit(-1);
	    	}
        if (year % 4== 0  && (year % 100 != 0 || year % 400 == 0)) {
            //my issue was how I used the brackets
            //the first part about year %4 must be true and the other one is an or so its in one ()
            //and the whole thing is in its own () since its an if statemetn
            return true;
    	}
        return false;
    	}
    }


