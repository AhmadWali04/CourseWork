package cp213;

import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.print.PageFormat;
import java.awt.print.Printable;
import java.awt.print.PrinterException;
import java.math.BigDecimal;
import java.util.HashMap;

/**
 * Stores a HashMap of MenuItem objects and the quantity of each MenuItem
 * ordered. Each MenuItem may appear only once in the HashMap.
 *
 * @author Ahmad Wali
 * @author Abdul-Rahman Mawlood-Yunis
 * @author David Brown
 * @version 2024-10-15
 */
public class Order implements Printable {

    private static final String lineFormat = "%-14s%2d @ $%5.2f = $%6.2f\n";
    private static final String totalFormat = "%-9s                   $%6.2f\n";
    /**
     * The current tax rate on menu items.
     */
    public static final BigDecimal TAX_RATE = new BigDecimal(0.13);

    // define a Map of MenuItem objects
    // Note that this must be a *Map* of some flavour
    // @See
    // https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/util/Map.html

    // your code here
    private HashMap<MenuItem,Integer> hash_menu = new HashMap<MenuItem,Integer>();

    /**
     * Increments the quantity of a particular MenuItem in an Order with a new
     * quantity. If the MenuItem is not in the order, it is added.
     *
     * @param item     The MenuItem to purchase - the HashMap key.
     * @param quantity The number of the MenuItem to purchase - the HashMap value.
     */
    public void add(final MenuItem item, final int quantity) {

	// your code here
        if(hash_menu.containsKey(item)){
            hash_menu.put(item,quantity + hash_menu.get(item));
        }
        else{
            hash_menu.put(item, quantity);
        }

    }

    /**
     * Calculates the total value of all MenuItems and their quantities in the
     * HashMap.
     *
     * @return the total cost for the MenuItems ordered.
     */
    public BigDecimal getSubTotal() {

	// your code here
        BigDecimal total = new BigDecimal(0);
        for(MenuItem food: hash_menu.keySet()){
            total = total.add(food.getPrice().multiply(new BigDecimal(hash_menu.get(food))));
        }

    	return total;    
    	}

    /**
     * Calculates and returns the total taxes to apply to the subtotal of all
     * MenuItems in the order. Tax rate is TAX_RATE.
     *
     * @return total taxes on all MenuItems
     */
    public BigDecimal getTaxes() {

	// your code here

        BigDecimal total = new BigDecimal(0);
        for(MenuItem food: hash_menu.keySet()){
            total = total.add(food.getPrice().multiply(new BigDecimal(hash_menu.get(food))));
        }
        BigDecimal tax = total.multiply(TAX_RATE);

    	return tax;   
    	}
    

    /**
     * Calculates and returns the total cost of all MenuItems order, including tax.
     *
     * @return total cost
     */
    public BigDecimal getTotal() {

	// your code here

        BigDecimal total = new BigDecimal(0);
        for(MenuItem food: hash_menu.keySet()){
            total = total.add(food.getPrice().multiply(new BigDecimal(hash_menu.get(food))));
        }
        total = total.add(total.multiply(TAX_RATE));

    	return total;    
    	}

    /*
     * Implements the Printable interface print method. Prints lines to a Graphics2D
     * object using the drawString method. Prints the current contents of the Order.
     */
    @Override
    public int print(final Graphics graphics, final PageFormat pageFormat, final int pageIndex)
	    throws PrinterException {
	int result = PAGE_EXISTS;

	if (pageIndex == 0) {
	    final Graphics2D g2d = (Graphics2D) graphics;
	    g2d.setFont(new Font("MONOSPACED", Font.PLAIN, 12));
	    g2d.translate(pageFormat.getImageableX(), pageFormat.getImageableY());
	    // Now we perform our rendering
	    final String[] lines = this.toString().split("\n");
	    int y = 100;
	    final int inc = 12;

	    for (final String line : lines) {
		g2d.drawString(line, 100, y);
		y += inc;
	    }
	} else {
	    result = NO_SUCH_PAGE;
	}
	return result;
    }

    /**
     * Returns a String version of a receipt for all the MenuItems in the order.
     */
    @Override
    public String toString() {
        String receipt = "";
        for(MenuItem food: hash_menu.keySet()){
            BigDecimal total = food.getPrice().multiply(new BigDecimal(hash_menu.get(food)));
            receipt += String.format(lineFormat,food.getListing(),
                hash_menu.get(food), food.getPrice(), total);
        }
        receipt += String.format(totalFormat, this.getSubTotal());
        receipt += String.format(totalFormat, this.getTaxes());
        receipt += String.format(totalFormat, this.getTotal());
    	return receipt;
        }

    /**
     * Replaces the quantity of a particular MenuItem in an Order with a new
     * quantity. If the MenuItem is not in the order, it is added. If quantity is 0
     * or negative, the MenuItem is removed from the Order.
     *
     * @param item     The MenuItem to update
     * @param quantity The quantity to apply to item
     */
    public void update(final MenuItem item, final int quantity) {

	// your code here
        if(quantity >  0){
            hash_menu.put(item,quantity);
        }
        else if(hash_menu.containsKey(item)){
            hash_menu.remove(item);
            }

    }
}