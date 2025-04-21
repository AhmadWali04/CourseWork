package cp213;

import java.util.ArrayList;


/**
 * Implements a Binary Search Tree.
 *
 * @author Ahmad Wali, wali6947@mylaurier.ca, 169036947
 * @author David Brown
 * @version 2024-11-14
 */
public class BST<T extends Comparable<T>> {

    // Attributes.
    /**
     * Count of comparisons performed by tree.
     */
    protected int comparisons = 0;
    /**
     * Root node of the tree.
     */
    protected TreeNode<T> root = null;
    /**
     * Number of nodes in the tree.
     */
    protected int size = 0;
    /**
     * Auxiliary method for {@code equals}. Determines whether two subtrees are
     * identical in datas and height.
     *
     * @param source Node of this BST.
     * @param target Node of that BST.
     * @return true if source and target are identical in datas and height.
     */
    protected boolean equalsAux(final TreeNode<T> source, final TreeNode<T> target) {
    	boolean isEqual = false;
    	//base case: the node has no more childre
    	if(source == null  && target == null) {
    		isEqual = true;
    	}else if(source==null || target==null){
    		isEqual = false;
    		//we know it cant be that theyre both true otherwise the top one would fire ouff
    		//if one is null and the other isnt, we can ay its not valid
    	}else if(!(source.getData().equals(target.getData()))) {
    		isEqual = false;
    	}else {
    		isEqual = this.equalsAux(source.getLeft(), target.getLeft()) && this.equalsAux(source.getRight(), target.getRight());
    		//checks if both the left leaves and the right leaves on the soruce/target BST are equivalent
    	}
	return isEqual;
    }

    /**
     * Auxiliary method for insert. Inserts data into this BST.
     *
     * @param node The current node (TreeNode).
     * @param data Data to be inserted into the tree.
     * @return The inserted node.
     */
    protected TreeNode<T> insertAux(TreeNode<T> node, final CountedData<T> data) {

	if (node == null) {
	    // Base case - add a new node containing the data.
	    node = new TreeNode<T>(data);
	    node.getData().incrementCount();
	    this.size++;
	} else {
	    // Compare the node data against the insert data.
	    final int result = node.getData().compareTo(data);
	    if (result > 0) {
		// General case - check the left subtree.
		node.setLeft(this.insertAux(node.getLeft(), data));
	    } else if (result < 0) {
		// General case - check the right subtree.
		node.setRight(this.insertAux(node.getRight(), data));
	    } else {
		// Base case - data is already in the tree, increment its count
		node.getData().incrementCount();
	    }
	}
	node.updateHeight();
	return node;
    }

    /**
     * Auxiliary method for valid. Determines if a subtree based on node is a valid
     * subtree.
     *
     * @param node    The root of the subtree to test for validity.
     * @param minNode The node of the minimum data in the current subtree.
     * @param maxNode The node of the maximum data in the current subtree.
     * @return true if the subtree base on node is valid, false otherwise.
     */
    protected boolean isValidAux(final TreeNode<T> node, TreeNode<T> minNode, TreeNode<T> maxNode) {
    	boolean isValid = false;
    	//min node is the node to the left, maxNode is the node to the right
    	if(node.getLeft()!= null) {
    		minNode = node.getLeft();
    	}
    	if(node.getRight()!= null) {
    		maxNode = node.getRight();
    	}
    	//if the left and right nodes arent null, check if they both have correctly ordered data and heights
    	if(minNode != null && maxNode != null) {
    		if(minNode.getData().compareTo(node.getData())<0 && maxNode.getData().compareTo(node.getData()) > 0){
    			//if the value on the left is less than the parent, and the value on the right is greater than the parents
    			if(node.getHeight() == minNode.getHeight()+1 && node.getHeight() == maxNode.getHeight()+1) {
    				//if the nodes are valid height
    				isValid = true && this.isValidAux(node.getLeft(), null, null) && this.isValidAux(node.getRight(), null, null);
    			}
    		}
    	//if my left node is not null and my right node is null
    	}else if(minNode != null) {
    		if(minNode.getData().compareTo(node.getData())<0) {
    			//if the value on the left node is less than zero (so it ssmaller)
    			if(node.getHeight()==minNode.getHeight()+1) {
    				isValid = true && this.isValidAux(node.getLeft(), null, null);
    			}
    		}
    	//checking when I only have a right leaf node to check
    	}else if(maxNode != null) {
    		if(maxNode.getData().compareTo(node.getData())>0) {
    			if(node.getHeight() == maxNode.getHeight()+1) {
    				isValid = true && this.isValidAux(node.getRight(), null, null);
    			}
    		}
    		
    	}
    	
	return isValid;
    }

    /**
     * Returns the height of a given TreeNode. Required for when TreeNode is null.
     *
     * @param node The TreeNode to determine the height of.
     * @return The height attribute of node, 0 if node is null.
     */
    protected int nodeHeight(final TreeNode<T> node) {
	return node != null ? node.getHeight() : 0;
    }

    /**
     * Auxiliary method for remove. Removes data from this BST.
     *
     * @param node The current node (TreeNode).
     * @param data Data to be removed from the tree.
     * @return The replacement node.
     */
    protected TreeNode<T> removeAux(TreeNode<T> node, final CountedData<T> data) {
    	  if (node == null) {
    	        return null;
    	    }
    	    int cmp = node.getData().compareTo(data);

    	    if (cmp > 0) {
    	        // Data is smaller, so proceed to the left subtree
    	        node.setLeft(removeAux(node.getLeft(), data));
    	    } else if (cmp < 0) {
    	        // Data is larger, so proceed to the right subtree
    	        node.setRight(removeAux(node.getRight(), data));
    	    } else {
    	        // Node to be deleted found
    	        this.size--;
    	        // Case 1: Node with only one child or no child
    	        if (node.getLeft() == null) {
    	            return node.getRight();
    	        } else if (node.getRight() == null) {
    	            return node.getLeft();
    	        }
    	        // Case 2: Node with two children
    	        // Find the in-order predecessor (max node in the left subtree)
    	        TreeNode<T> predecessorParent = node;
    	        TreeNode<T> predecessor = node.getLeft();
    	        while (predecessor.getRight() != null) {
    	            predecessorParent = predecessor;
    	            predecessor = predecessor.getRight();
    	        }
    	        // If the in-order predecessor is not a direct child of the node
    	        if (predecessorParent != node) {
    	            // Set the right subtree of the predecessor’s parent to the left child of the predecessor
    	            predecessorParent.setRight(predecessor.getLeft());
    	            // Move the left subtree of the node to the left of the predecessor
    	            predecessor.setLeft(node.getLeft());
    	        }
    	        // Move the right subtree of the node to the right of the predecessor
    	        predecessor.setRight(node.getRight());
    	        // Set the predecessor as the new root of this subtree
    	        node = predecessor;
    	    }
    	    // Update the height of the current node after deletion
    	    node.updateHeight();
    	    return node;
    }

    /**
     * Determines if this BST contains key.
     *
     * @param key The key to search for.
     * @return true if this contains key, false otherwise.
     */
    public boolean contains(final CountedData<T> key) {
	return this.retrieve(key) != null;
    }

    /**
     * Determines whether two trees are identical.
     *
     * @param target The tree to compare this BST against.
     * @return true if this and target contain nodes that match in position, data,
     *         count, and height, false otherwise.
     */
    public boolean equals(final BST<T> target) {
	boolean isEqual = false;
	if (this.size == target.size) {
	    isEqual = this.equalsAux(this.root, target.root);
	}
	return isEqual;
    }

    /**
     * Get number of comparisons executed by the retrieve method.
     *
     * @return comparisons
     */
    public int getComparisons() {
	return this.comparisons;
    }

    /**
     * Returns the height of the root node of this tree.
     *
     * @return height of root node, 0 if the root node is null.
     */
    public int getHeight() {
	return this.root != null ? this.root.getHeight() : 0;
    }

    /**
     * Returns the number of nodes in the tree.
     *
     * @return number of nodes in this tree.
     */
    public int getSize() {
	return this.size;
    }

    /**
     * Returns a list of the data in the current tree. The list contents are in
     * order from smallest to largest.
     *
     * Not thread safe as it assumes contents of the tree are not changed by an
     * external thread during the loop.
     *
     * @return The contents of this tree as a list of data.
     */
    public ArrayList<CountedData<T>> inOrder() {
	return this.root.inOrder();
    }

    /**
     * Inserts data into this tree.
     *
     * @param data Data to store.
     */
    public void insert(final CountedData<T> data) {
	this.root = this.insertAux(this.root, data);
	return;
    }

    /**
     * Determines if this tree is empty.
     *
     * @return true if this tree is empty, false otherwise.
     */
    public boolean isEmpty() {
	return this.size==0;
    }

    /**
     * Determines if this tree is a valid BST; i.e. a node's left child data is
     * smaller than its data, and its right child data is greater than its data, and
     * a node's height is equal to the maximum of the heights of its two children
     * (empty child nodes have a height of 0), plus 1.
     *
     * @return true if this tree is a valid BST, false otherwise.
     */
    public boolean isValid() {
	return this.isValidAux(this.root, null, null);
    }

    /**
     * Returns a list of the data in the current tree. The list contents are in node
     * level order starting from the root node. Helps determine the structure of the
     * tree.
     *
     * Not thread safe as it assumes contents of the tree are not changed by an
     * external thread during the loop.
     *
     * @return this tree data as a list of data.
     */
    public ArrayList<CountedData<T>> levelOrder() {
	return this.root.levelOrder();
    }

    /**
     * Returns a list of the data in the current tree. The list contents are in node
     * preorder.
     *
     * Not thread safe as it assumes contents of the tree are not changed by an
     * external thread during the loop.
     *
     * @return The contents of this tree as a list of data.
     */
    public ArrayList<CountedData<T>> preOrder() {
	return this.root.preOrder();
    }

    /**
     * Removes data from the tree. Decrements the node count, and if the count is 0,
     * removes the node entirely.
     *
     * @param data Data to decrement or remove.
     */ 
    public void remove(final CountedData<T> data) {
	this.root = this.removeAux(this.root, data);
	return;
    }

    /**
     * Resets the comparison count to 0.
     */
    public void resetComparisons() {
	this.comparisons = 0;
	return;
    }

    /**
     * Retrieves a copy of data matching key (key should have data count of 0).
     * Returning a complete CountedData gives access to the data and its count.
     *
     * @param key The key to look for.
     * @return data The complete CountedData that matches key, null otherwise.
     */
    public CountedData<T> retrieve(final CountedData<T> key) {
    	CountedData<T> dummy = null;
    	//we just use a while loop and and make sure we dont hit a null value, navigating to it 
    	TreeNode<T> node = this.root;
    	while (node!= null && !(node.getData().compareTo(key)==0)) {
    		//while im still traversing the list and havent found the matching data yet
    		if(node.getData().compareTo(key)>0) {
    			//if im getting something greater, go left
    			node=node.getLeft();
    		}if(node.getData().compareTo(key)<0) {
    			node = node.getRight();
    		}else if (node.getData().compareTo(key)==0){
    			//if the data has been found
    			dummy = node.getData();
    		}
    	}
    	
	return dummy;
    }
}
