package cp213;

import java.util.HashSet;

/**
 * A single linked list structure of <code>Node T</code> objects. These data
 * objects must be Comparable - i.e. they must provide the compareTo method.
 * Only the <code>T</code> object contained in the priority queue is visible
 * through the standard priority queue methods. Extends the
 * <code>SingleLink</code> class.
 *
 * @author Ahmad Wali, 169036947, wali6947@mylaurier.ca 
 * @version 2024-10-31
 * @param <T> this SingleList data type.
 */
public class SingleList<T extends Comparable<T>> extends SingleLink<T> {

	/**
	 * Searches for the first occurrence of key in this SingleList. Private helper
	 * methods - used only by other ADT methods.
	 *
	 * @param key The object to look for.
	 * @return A pointer to the node previous to the node containing key.
	 */
	private SingleNode<T> linearSearch(final T key) {

		// your code here
		SingleNode<T> current = this.front;
		SingleNode<T> previous = null;

		while (current != null && current.getObject() != key) {
			previous = current;
			current = current.getNext();
		}
		return previous;
	}

	/**
	 * Appends data to the end of this SingleList.
	 *
	 * @param data The object to append.
	 */
	public void append(final T data) {
		SingleNode<T> newNode = new SingleNode<>(data, null);
		if (this.front == null) {
			// if its an empty list, this is the front and the rear
			this.front = newNode;
			this.rear = newNode;
		} else {
			//we change link the rear to the new node and make the new node the new rear
			this.rear.setNext(newNode);
			this.rear = newNode;
		}
		this.length++;

		return;
	}

	/**
     * Removes duplicates from this SingleList. The list contains one and only one
     * of each object formerly present in this SingleList. The first occurrence of
     * each object is preserved.
     */
    public void clean() {
    	SingleNode<T> previous = null;
    	SingleNode<T> current = this.front;
    	HashSet<T> tempset = new HashSet<>();
    	while(current!=null) {
    		if(tempset.contains(current.getObject())){
    			if(tempset.contains(current.getObject())) {
    				previous.setNext(current.getNext());
    				this.length--;
    			}else {
    				tempset.add(current.getObject());
    				previous = current;
    			}
    			current = current.getNext();
    		}
    	}
	return;
    }

	/**
	 * Combines contents of two lists into a third. Values are alternated from the
	 * origin lists into this SingleList. The origin lists are empty when finished.
	 * NOTE: data must not be moved, only nodes.
	 *
	 * @param left  The first list to combine with this SingleList.
	 * @param right The second list to combine with this SingleList.
	 */
	public void combine(final SingleList<T> left, final SingleList<T> right) {
		SingleNode<T> current = this.front;
		while(current!=null) {
			this.moveFrontToFront(left);
			this.moveFrontToFront(right);
		}
		return;
	}

	/**
	 * Determines if this SingleList contains key.
	 *
	 * @param key The key object to look for.
	 * @return true if key is in this SingleList, false otherwise.
	 */
	public boolean contains(final T key) {
		if (this.linearSearch(key) == null) {
			return false;
		} else {
			return true;
		}
	}

	/**
	 * Finds the number of times key appears in list.
	 *
	 * @param key The object to look for.
	 * @return The number of times key appears in this SingleList.
	 */
	public int count(final T key) {
		int num = 0;
		SingleNode<T> current = this.front;
		while (current != null) {
			if (current.getObject() == key) {
				num++;
			}
			current = current.getNext();
		}
		return num;
	}

	/**
	 * Finds and returns the object in list that matches key.
	 *
	 * @param key The object to search for.
	 * @return The object that matches key, null otherwise.
	 */
	public T find(final T key) {
		SingleNode<T> dummy = this.linearSearch(key);
		if(dummy != null) {
			return dummy.getNext().getObject();
		}else {
			return null;
		}
	}

	/**
	 * Get the nth object in this SingleList.
	 *
	 * @param n The index of the object to return.
	 * @return The nth object in this SingleList.
	 * @throws ArrayIndexOutOfBoundsException if n is not a valid index.
	 */
	public T get(final int n) throws ArrayIndexOutOfBoundsException {
		SingleNode<T> current = this.front;
		for (int i = 0; i <= n; i++) {
			current = current.getNext();
		}
		return current.getObject();
	}

	/**
	 * Determines whether two lists are identical.
	 *
	 * @param source The list to compare against this SingleList.
	 * @return true if this SingleList contains the same objects in the same order
	 *         as source, false otherwise.
	 */
	public boolean equals(final SingleList<T> source) {
		SingleNode<T> thisCheck = this.front;
		SingleNode<T> sourceCheck = source.front;
		while (thisCheck != null && sourceCheck != null) {
			if(thisCheck.getObject()!= sourceCheck.getObject()) {
				return false;
			}
			sourceCheck = sourceCheck.getNext();
			thisCheck = thisCheck.getNext();
			}
		return true;
	}

	/**
	 * Finds the first location of a object by key in this SingleList.
	 *
	 * @param key The object to search for.
	 * @return The index of key in this SingleList, -1 otherwise.
	 */
	public int index(final T key) {
		int i = 0;
		boolean found = false;
		SingleNode<T> current = this.front;
		while(current!= null && !found) {
			if(current.getObject().compareTo(key) ==0) {
				found = true;
			}else {
				current = current.getNext();
				i++;
			}
		}
		if(!found) {
			return -1;
		}else {
			return i;
		}
	}

	/**
	 * Inserts object into this SingleList at index i. If i greater than the length
	 * of this SingleList, append data to the end of this SingleList.
	 *
	 * @param i    The index to insert the new data at.
	 * @param data The new object to insert into this SingleList.
	 */
	public void insert(int i, final T data) {
        //cases: inserting in the front, middle and rear
        //prepend if ii = 0 and append if i = 0
        if(i<=0 || this.length ==0) {
        	this.prepend(data);
        }else if (i > this.length) {
        	this.append(data);
        }
        else {
        	SingleNode<T> current = this.front;
    		SingleNode<T> previous = null;
    		int count = 0;
        	while(current!=null && count < i) {
        	previous = current;
        	current = current.getNext();
        	count++;
        		//iterate to i, then link what was linking to i, to j
        		//link j to i 
        	}
        	SingleNode<T> newNode = new SingleNode<>(data,null);
        	previous.setNext(newNode);
        	newNode.setNext(current);
        	this.length++;
        }
		return;
	}

	/**
	 * Creates an intersection of two other SingleLists into this SingleList. Copies
	 * data to this SingleList. left and right SingleLists are unchanged. Values
	 * from left are copied in order first, then objects from right are copied in
	 * order.
	 *
	 * @param left  The first SingleList to create an intersection from.
	 * @param right The second SingleList to create an intersection from.
	 */
	public void intersection(final SingleList<T> left, final SingleList<T> right) {
		//call my contains function
		SingleNode<T> check = left.front;
		while(check!= null) {
			if(right.contains(check.getObject())) {
				this.append(check.getObject());
			}
			check = check.getNext();
		}
		return;
	}

	/**
	 * Finds the maximum object in this SingleList.
	 *
	 * @return The maximum object.
	 */
	public T max() {
		assert this.front != null : "Cannot scan through an empty list";
		SingleNode<T> current = this.front;
		T greatest = current.getObject();
		while(current != null) {
			if(current.getObject().compareTo(greatest) > 0) {
				greatest = current.getObject();
			}
			current = current.getNext();
		}
		return greatest;
	}

	/**
	 * Finds the minimum object in this SingleList.
	 *
	 * @return The minimum object.
	 */
	public T min() {
		assert this.front != null : "Cannot scan thorugh an empty list";
		SingleNode<T> current = this.front;
		T least = current.getObject();
		while(current!= null) {
			if(current.getObject().compareTo(least) < 0) {
				least = current.getObject();
			}
			current = current.getNext();
		}
		return least;
	}

	/**
	 * Inserts object into the front of this SingleList.
	 *
	 * @param data The object to insert into the front of this SingleList.
	 */
	public void prepend(final T data) {
		SingleNode<T> newNode = new SingleNode<>(data,this.front);
		this.front = newNode;
		this.length++;
		return;
	}

	/**
	 * Finds, removes, and returns the object in this SingleList that matches key.
	 *
	 * @param key The object to search for.
	 * @return The object matching key, null otherwise.
	 */
	public T remove(final T key) {
		T check;
		SingleNode<T> previous = this.linearSearch(key);
		if(previous == null) {
			check = this.front.getObject();
			this.front = this.front.getNext();			
		} else {
			if(previous.getNext()==null) {
				check = null;
			} else {
				check = previous.getNext().getObject();
				previous.setNext(previous.getNext().getNext());
			}
			this.length--;
		}
		return check;
	}

	/**
	 * Removes the object at the front of this SingleList.
	 *
	 * @return The object at the front of this SingleList.
	 */
	public T removeFront() {
		assert this.front != null: "Cannot remove from an empty list";
		SingleNode<T> head = this.front;
		if(this.length ==1) {
			this.front = null;
		} else {
			this.front = head.getNext();
		}
		T value = head.getObject();
		this.length--;
		return value;
	}

	/**
	 * Finds and removes all objects in this SingleList that match key.
	 *
	 * @param key The object to search for.
	 */
	public void removeMany(final T key) {
		//fix 
		while(this.linearSearch(key)!= null) {
			this.remove(key);
		}
	}

	/**
	 * Reverses the order of the objects in this SingleList.
	 */
	public void reverse() {
		SingleNode<T> previous = null;
		SingleNode<T> current = this.front;
		SingleNode<T> temp;
		while(current!= null) {
			temp = current.getNext();
			current.setNext(previous);
			previous = current;
			current = temp;
		}
		this.front = previous;
		return;
	}

	/**
	 * Splits the contents of this SingleList into the left and right SingleLists.
	 * Moves nodes only - does not move object or call the high-level methods insert
	 * or remove. this SingleList is empty when done. The first half of this
	 * SingleList is moved to left, and the last half of this SingleList is moved to
	 * right. If the resulting lengths are not the same, left should have one more
	 * object than right. Order is preserved.
	 *
	 * @param left  The first SingleList to move nodes to.
	 * @param right The second SingleList to move nodes to.
	 */
	public void split(final SingleList<T> left, final SingleList<T> right) {
		int value = this.length / 2;

		if (this.length % 2 == 0) {
		    while (left.length < value) {
		    	left.moveFrontToRear(this);
		    }
		    while (right.length < value) {
		    	right.moveFrontToRear(this);
		    }
		}else {
		    while (left.length <= value) {
		    	left.moveFrontToRear(this);
		    }
		    while (right.length < value) {
		    	right.moveFrontToRear(this);
		    }
		}		
			
		return;
	}

	/**
	 * Splits the contents of this SingleList into the left and right SingleLists.
	 * Moves nodes only - does not move object or call the high-level methods insert
	 * or remove. this SingleList is empty when done. Nodes are moved alternately
	 * from this SingleList to left and right. Order is preserved.
	 *
	 * @param left  The first SingleList to move nodes to.
	 * @param right The second SingleList to move nodes to.
	 */
	public void splitAlternate(final SingleList<T> left, final SingleList<T> right) {
		while(this.front != null) {
			//take the front of this and moves it into left and right? 
			left.moveFrontToRear(this);
			right.moveFrontToRear(this);
		}
		return;
	}

	/**
	 * Creates a union of two other SingleLists into this SingleList. Copies object
	 * to this list. left and right SingleLists are unchanged. Values from left are
	 * copied in order first, then objects from right are copied in order.
	 *
	 * @param left  The first SingleList to create a union from.
	 * @param right The second SingleList to create a union from.
	 */
	public void union(final SingleList<T> left, final SingleList<T> right) {
		SingleNode<T> leftHead = left.front;
		SingleNode<T> rightHead = right.front;
		while(leftHead!= null) {
			T leftCheck = leftHead.getObject();
			int search = this.index(leftCheck);
			if(search == -1) {
				this.append(leftCheck);
			}
			leftHead = leftHead.getNext();
		}
		while(rightHead!= null) {
			T rightCheck = rightHead.getObject();
			int search = this.index(rightCheck);
			if(search == -1) {
				this.append(rightCheck);
			}
			rightHead = rightHead.getNext();
		}
		return;
	}
}
