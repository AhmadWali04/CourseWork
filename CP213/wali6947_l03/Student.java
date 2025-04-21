package cp213;

import java.time.LocalDate;

/**
 * Student class definition.
 *
 * @author Ahmad Wali
 * @version 2024-10-03
 */
/**
 * @author Ahmad Wali
 * @DATE 2024-10-04
 */
public class Student implements Comparable<Student> {

	// Attributes
	private LocalDate birthDate = null;
	private String forename = "";
	private int id = 0;
	private String surname = "";

	/**
	 * Instantiates a Student object.
	 *
	 * @param id        student ID number
	 * @param surname   student surname
	 * @param forename  name of forename
	 * @param birthDate birthDate in 'YYYY-MM-DD' format
	 */
	public Student(int id, String surname, String forename, LocalDate birthDate) {
		this.forename = forename;
		this.surname = surname;
		this.id = id;
		this.birthDate = birthDate;
		// takes the private variables made, passes them to the student class.
		// Then sets them as parameters for each object this class creats

		return;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#toString() Creates a formatted string of student data.
	 */
	@Override
	public String toString() {
		int width = 20;
		return String.format("%" + width + "s: %s %s\n%" + width + "s: %d\n%" + width + "s: %s\n", "NAME", forename,
				surname, "ID", id, "BIRTHDAY", birthDate);

	}

	// Other methods, such as compareTo, can be added here

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Comparable#compareTo(java.lang.Object)
	 */
	@Override
	public int compareTo(final Student target) {
		int result = 0;
		result = this.surname.compareTo(target.surname);
		if (result == 0) {
			this.forename.compareTo(target.forename);
			if (result == 0){
				if (this.id>target.id) {
					result = 1;
				}
				else if (this.id<target.id) {
					result = -1;
				}
			}
		} return result;
		}
	// SETTER AND GETTER FUNCTIONS

	/**
	 * @param identification
	 * @return None sets the id of the student object given the identification
	 *         parameter
	 */
	public void setId(int identification) {
		id = identification;
	}

	/**
	 * @param None
	 * @return id returns the id of the student
	 */
	public Integer getId() {
		return id;
	}

	/**
	 * @param firstname
	 * @return None Sets the first name of the stuent object
	 */
	public void setForename(String firstName) {
		forename = firstName;
	}

	/**
	 * @param None
	 * @return forename returns the first name of the student
	 */
	public String getForename() {
		return forename;
	}

	/**
	 * @param lastName
	 * @return None Sets the last name of the student
	 */
	public void setSurname(String lastName) {
		surname = lastName;
	}

	/**
	 * @param None
	 * @return surname returns the last name of the student
	 */
	public String getSurname() {
		return surname;
	}

	/**
	 * @param birth
	 * @return None Sets the birthday of the student object
	 */
	public void setBirthDate(LocalDate birth) {
		birthDate = birth;
	}

	/**
	 * @param None
	 * @return birthDate returns the birthday of the student
	 */
	public LocalDate getBirthDate() {
		return birthDate;
	}
}
