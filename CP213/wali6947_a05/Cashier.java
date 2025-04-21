package cp213;

import java.util.Scanner;

/**
 * Wraps around an Order object to ask for MenuItems and quantities.
 *
 * @author Ahmad Wali
 * @author Abdul-Rahman Mawlood-Yunis
 * @author David Brown
 * @version 2024-10-15
 */
public class Cashier {

    private Menu menu = null;

    /**
     * Constructor.
     *
     * @param menu A Menu.
     */
    public Cashier(Menu menu) {
	this.menu = menu;
    }

    /**
     * Reads keyboard input. Returns a positive quantity, or 0 if the input is not a
     * valid positive integer.
     *
     * @param scan A keyboard Scanner.
     * @return
     */
    private int askForQuantity(Scanner scan) {
	int quantity = 0;
	System.out.print("How many do you want? ");
	try {
	    String line = scan.nextLine();
	    quantity = Integer.parseInt(line);
	} catch (NumberFormatException nfex) {
	    System.out.println("Not a valid number");
	}
	return quantity;
    }

    /**
     * Prints the menu.
     */
    private void printCommands() {
	System.out.println("\nMenu:");
	System.out.println(menu.toString());
	System.out.println("Press 0 when done.");
	System.out.println("Press any other key to see the menu again.\n");
    }

    /**
     * Asks for commands and quantities. Prints a receipt when all orders have been
     * placed.
     *
     * @return the completed Order.
     */
    public Order takeOrder() {
	System.out.println("Welcome to WLU Foodorama!");
    this.printCommands();
    Scanner input = new Scanner(System.in);
    Order input_order = new Order();
    String input_text1 = "";
    int input_int = 0;
    String input_text2 = "";
    int input_int2 = 0;
    MenuItem input_menu;
    while(!(input_text1.equals("0"))){
        this.printCommands();
        System.out.print("Command: ");
        input_text1 = input.nextLine();
        try{
            input_int = Integer.parseInt(input_text1);
            if(input_int > 0 && input_int <=menu.size()){
                input_menu = menu.getItem(input_int - 1);
                System.out.print("How many do you want? ");
                input_text2 = input.nextLine();
                try{
                    input_int2 = Integer.parseInt(input_text2);
                    input_order.update(input_menu, input_int2);
                }catch(NumberFormatException e){
                    System.out.println("Not a valid number. ");
                }
            }
        }catch(NumberFormatException e){
            System.out.println("Not a valid number. ");
        }
    }
    System.out.println("----------------------------------------");
	System.out.println("Reciept");
	System.out.println(input_order.toString());
    input.close();
	return input_order;
    }
}