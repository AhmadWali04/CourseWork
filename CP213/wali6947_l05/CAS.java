package cp213;

/**
 * Inherited class in simple example of inheritance / polymorphism.
 *
 * @author Ahmad Wali
 * @version 2024-10-28
 */
public class CAS extends Professor {
	private String term = null;
    /**
     * @param lastName
     *            CAS last name (surname): defined in Person
     * @param firstName
     *            CAS first name (given name): defined in Person
     * @param department
     *            CAS department
     * @param term
     * 			  CAS term
     */
	public CAS(final String lastName, final String firstName, final String department, final String term) {
		super(lastName,firstName,department);
		this.term = term;
	}
    /**
     * Creates formatted string version of CAS.
     */
    @Override
	public String toString() {
		return (super.toString() + "\nTerm" + this.term);
	}
    /**
     * Getter for term.
     *
     * @return this.term
     */
	public String getTerm() {
		return this.term;
	}
	
}
