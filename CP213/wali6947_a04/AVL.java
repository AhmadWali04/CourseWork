package cp213;

/**
 * Implements an AVL (Adelson-Velsky Landis) tree. Extends BST.
 *
 * @author Ahmad Wali, wali6947@mylaurier.ca, 169036947
 * @author David Brown
 * @version 2024-11-14
 */
public class AVL<T extends Comparable<T>> extends BST<T> {

	/**
	 * Returns the balance data of node. If greater than 1, then left heavy, if less
	 * than -1, then right heavy. If in the range -1 to 1 inclusive, the node is
	 * balanced. Used to determine whether to rotate a node upon insertion.
	 *
	 * @param node The TreeNode to analyze for balance.
	 * @return A balance number.
	 */
	private int balance(final TreeNode<T> node) {
		// left node hight - right node height
		int bal;
		if (node == null) {
			bal = 0;
		}
		if (node.getRight() == null) {
			bal = node.getHeight();
		}
		if (node.getLeft() == null) {
			bal = 0 - node.getHeight();
		} else {
			bal = node.getLeft().getHeight() - node.getRight().getHeight();
		}
		return bal;
	}

	/**
	 * Rebalances the current node if its children are not balanced.
	 *
	 * @param node the node to rebalance
	 * @return replacement for the rebalanced node
	 */
	private TreeNode<T> rebalance(TreeNode<T> node) {
		TreeNode<T> newNode = null;
		if (node != null) {
			int factor = balance(node);
			if (factor > 1) {
				if (balance(node.getLeft()) >= 0) {
					newNode = rotateRight(node);
				} else {
					node.setLeft(rotateLeft(node.getLeft()));
					newNode = rotateRight(node);
				}
			} else if (factor < -1) {
				if (balance(node.getRight()) <= 0) {
					newNode = rotateLeft(node);
				} else {
					node.setRight(rotateRight(node.getRight()));
					newNode = rotateLeft(node);
				}
			}
		}
		return newNode;
	}

	/**
	 * Performs a left rotation around node.
	 *
	 * @param node The subtree to rotate.
	 * @return The new root of the subtree.
	 */
	private TreeNode<T> rotateLeft(final TreeNode<T> node) {
		TreeNode<T> newRoot = node.getRight();
		node.setRight(newRoot.getLeft());
		newRoot.setLeft(node);
		node.updateHeight();
		newRoot.updateHeight();

		return newRoot;
	}

	/**
	 * Performs a right rotation around node.
	 *
	 * @param node The subtree to rotate.
	 * @return The new root of the subtree.
	 */
	private TreeNode<T> rotateRight(final TreeNode<T> node) {
		TreeNode<T> newRoot = node.getLeft();
		node.setLeft(newRoot.getRight());
		newRoot.setRight(node);
		node.updateHeight();
		newRoot.updateHeight();
		return newRoot;
	}

	/**
	 * Auxiliary method for insert. Inserts data into this AVL. Same as BST
	 * insertion with addition of rebalance of nodes.
	 *
	 * @param node The current node (TreeNode).
	 * @param data Data to be inserted into the node.
	 * @return The inserted node.
	 */
	@Override
	protected TreeNode<T> insertAux(TreeNode<T> node, final CountedData<T> data) {
		TreeNode<T> inserted = super.insertAux(node, data);
		//insert the node, then traverse our way down to the node and figure out what needs to be rebalanced
		TreeNode<T>current = this.root;
		this.size++;
		while(current != null) {
			if (Math.abs(balance(current))>1){
				//creates a dummy so i dont lose current when navigating along to inserted path
				TreeNode<T> dummy = current;
				rebalance(dummy);
			}
			int result = current.getData().compareTo(data);
			if (result > 0){
				current = current.getRight();
			}
			if(result<0) {
				current = current.getLeft();
			}
		}
		return inserted;
	}

	/**
	 * Auxiliary method for valid. Determines if a subtree based on node is a valid
	 * subtree. An AVL must meet the BST validation conditions, and additionally be
	 * balanced in all its subtrees - i.e. the difference in height between any two
	 * children must be no greater than 1.
	 *
	 * @param node The root of the subtree to test for validity.
	 * @return true if the subtree base on node is valid, false otherwise.
	 */
	@Override
	protected boolean isValidAux(final TreeNode<T> node, TreeNode<T> minNode, TreeNode<T> maxNode) {
		if (node != null) {
			return true;
		} else {
			// for any nodes left, first check if they have a valid balance factor
			int balance = Math.abs(minNode.getHeight() - maxNode.getHeight());
			if (balance > 1) {
				return false;
			}
			// if 2 nodes exist and they have incorrect data, its false
			if (minNode != null && maxNode != null) {
				if (minNode.getData().compareTo(node.getData()) > 0
						|| maxNode.getData().compareTo(node.getData()) < 0) {
					return false;
				}
				// if one node left, if it has incorrect data its false
			} else if (minNode != null) {
				if (minNode.getData().compareTo(node.getData()) > 0) {
					return false;
				}
				// if its one node left and its the max node, incorrect data means its false
			} else if (maxNode != null) {
				if (maxNode.getData().compareTo(node.getData()) < 0) {
					return false;
				}
			}
		}
		return isValidAux(node.getLeft(), minNode, node) && isValidAux(node.getRight(), node, maxNode);

	}

	/**
	 * Determines whether two AVLs are identical.
	 *
	 * @param target The AVL to compare this AVL against.
	 * @return true if this AVL and target contain nodes that match in position,
	 *         data, count, and height, false otherwise.
	 */
	public boolean equals(final AVL<T> target) {
		return super.equals(target);
	}

	/**
	 * Auxiliary method for remove. Removes data from this BST. Same as BST removal
	 * with addition of rebalance of nodes.
	 *
	 * @param node The current node (TreeNode).
	 * @param data Data to be removed from the tree.
	 * @return The replacement node.
	 */
	@Override
	protected TreeNode<T> removeAux(TreeNode<T> node, final CountedData<T> data) {
		TreeNode <T> replacement = super.removeAux(node, data);
		TreeNode<T>current = this.root;
		this.size--;
		while(current != null) {
			if (Math.abs(balance(current))>1){
				//creates a dummy so i dont lose current when navigating along removal path
				TreeNode<T> dummy = current;
				rebalance(dummy);
			}
			int result = current.getData().compareTo(data);
			if (result > 0){
				current = current.getRight();
			}
			if(result<0) {
				current = current.getLeft();
			}
		}
		return replacement;
	}

}
