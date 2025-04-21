package cp213;

import java.time.LocalDate;

/**
 * Tests the Student class.
 *
 * @author Ahmad Wali
 * @version 2024-10-03S
 */
public class Main {

    public static void main(String[] args) {
	final String line = "-".repeat(40);
	int id = 123456;
	String surname = "Brown";
	String forename = "David";
	LocalDate birthDate =  LocalDate.parse("1962-10-25");
	Student student = new Student(id,surname,forename,birthDate);
	//makes a new student object what has the defined variables are paramaters
	System.out.println("New Student:");
	System.out.println(student);
	System.out.println(line);
	System.out.println("Test Getters");
	student.getId();
	System.out.println(student.toString());
	System.out.println(line);
	System.out.println("Test Setters");
	student.setBirthDate(LocalDate.parse("2004-05-05"));
	student.setForename("Ahmad");
	student.setSurname("Wali");
	student.setId(169036947);
	System.out.print(student.toString());
	System.out.println("Updated Student:");
	System.out.println(student);
	System.out.println(line);
	System.out.println("Test compareTo");
	Student dummy = new Student(051426,"Wali","Faiza",LocalDate.parse("2000-12-14"));
	System.out.println(dummy.toString());
	System.out.println(student.compareTo(dummy));
	//
    }

}
