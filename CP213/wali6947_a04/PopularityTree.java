package cp213;

/**
 * Implements a Popularity Tree. Extends BST.
 *
 * @author Ahmad Wali, wali6947@mylaurier.ca, 169036947
 * @author David Brown
 * @version 2024-11-14
 */
public class PopularityTree<T extends Comparable<T>> extends BST<T> {

	/**
	 * Auxiliary method for valid. May force node rotation if the retrieval count of
	 * the located node data is incremented.
	 *
	 * @param node The node to examine for key.
	 * @param key  The data to search for. Count is updated to count in matching
	 *             node data if key is found.
	 * @return The updated node.
	 */
	private TreeNode<T> retrieveAux(TreeNode<T> node, final CountedData<T> key) {
		if (node == null) {
			node = new TreeNode<T>(key);
			return node;
		}
		int result = node.getData().compareTo(key);
		this.comparisons++;
		if (result == 0) {
			node.getData().incrementCount();
			key.setCount(node.getData().getCount());
		} else if (result > 0) {
			node.setLeft(this.retrieveAux(node.getLeft(), key));
			if (node.getLeft() != null && node.getData().getCount() < node.getLeft().getData().getCount()) {
				node = this.rotateRight(node);
			}
		} else if (result < 0) {
			node.setRight(this.retrieveAux(node.getRight(), key));
			if (node.getRight() != null && node.getData().getCount() < node.getRight().getData().getCount()) {
				node = this.rotateLeft(node);
			}
		} else {
			node.getData().incrementCount();
			key.setCount(node.getData().getCount());
		}

		return node;

	}

	/**
	 * Performs a left rotation around node.
	 *
	 * @param parent The subtree to rotate.
	 * @return The new root of the subtree.
	 */
	private TreeNode<T> rotateLeft(final TreeNode<T> parent) {
		TreeNode<T> newParent = parent.getRight();
		parent.setRight(newParent.getLeft());
		newParent.setLeft(parent);
		parent.updateHeight();
		newParent.updateHeight();

		return newParent;
	}

	/**
	 * Performs a right rotation around {@code node}.
	 *
	 * @param parent The subtree to rotate.
	 * @return The new root of the subtree.
	 */
	private TreeNode<T> rotateRight(final TreeNode<T> parent) {

		TreeNode<T> newParent = parent.getLeft();
		parent.setLeft(newParent.getRight());
		newParent.setRight(parent);
		parent.updateHeight();
		newParent.updateHeight();

		return newParent;
	}

	/**
	 * Replaces BST insertAux - does not increment count on repeated insertion.
	 * Counts are incremented only on retrieve.
	 */
	@Override
	protected TreeNode<T> insertAux(TreeNode<T> node, final CountedData<T> data) {
		if (node == null) {
			TreeNode<T> new_node = new TreeNode<T>(data);
			this.size++;
			return new_node;
		} else if (data.compareTo(node.getData()) > 0) {
			node.setRight(insertAux(node.getRight(), data));
		} else if (data.compareTo(node.getData()) < 0) {
			node.setLeft(insertAux(node.getLeft(), data));
		}
		node.updateHeight();
		return node;
	}

	/**
	 * Auxiliary method for valid. Determines if a subtree based on node is a valid
	 * subtree. An Popularity Tree must meet the BST validation conditions, and
	 * additionally the counts of any node data must be greater than or equal to the
	 * counts of its children.
	 *
	 * @param node The root of the subtree to test for validity.
	 * @return true if the subtree base on node is valid, false otherwise.
	 */
	@Override
	protected boolean isValidAux(final TreeNode<T> node, TreeNode<T> minNode, TreeNode<T> maxNode) {
		if (node == null) {
			return true;
		} else if (minNode != null) {
			if (minNode.getData().compareTo(node.getData()) > 0) {
				return false;
			} else if (minNode.getData().getCount() < node.getData().getCount()) {
				return false;
			}
		} else if (maxNode != null) {
			if (maxNode.getData().compareTo(node.getData()) < 0) {
				return false;
			} else if (maxNode.getData().getCount() < node.getData().getCount()) {
				return false;
			}
		}
		return isValidAux(node.getLeft(), minNode, node) && isValidAux(node.getRight(), node, maxNode);
	}

	/**
	 * Determines whether two PopularityTrees are identical.
	 *
	 * @param target The PopularityTree to compare this PopularityTree against.
	 * @return true if this PopularityTree and target contain nodes that match in
	 *         position, data, count, and height, false otherwise.
	 */
	public boolean equals(final PopularityTree<T> target) {
		return super.equals(target);
	}

	/**
	 * Very similar to the BST retrieve, but increments the data count here instead
	 * of in the insertion.
	 *
	 * @param key The key to search for.
	 */
	@Override
	public CountedData<T> retrieve(CountedData<T> key) {

		CountedData<T> value = null;
		TreeNode<T> node = retrieveAux(this.root, key);
		if (node != null) {
			value = node.getData();
		}
		return value;
	}
}
