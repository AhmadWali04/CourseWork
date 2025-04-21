 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include "avl.h"
 
 
 AVLNODE *avl_node(RECORD data)
 {
   AVLNODE *np = (AVLNODE *)malloc(sizeof(AVLNODE));
   if (np)
   {
     np->data = data;
     np->height = 1;
     np->left = NULL;
     np->right = NULL;
   }
   return np;
 }
 
 
 int max(int a, int b) 
 {
   return (a > b)? a : b;
 }
 
 
 int height(AVLNODE *np){
  if(np == NULL){
    return 0;
  }
  return np->height;
 }
 
 int balance_factor(AVLNODE *np){
    return height(np->left) - height(np->right);
 }
 
 
 AVLNODE *rotate_left(AVLNODE *np){
    //x is np
    AVLNODE *newRoot = np->right; //newNode basically
    AVLNODE *temp = newRoot->left;

    //Rotate:
    newRoot->left = np;
    np->right = temp;
    //Update heights:
    np->height = max(height(np->left),height(np->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
 }
 
 
 AVLNODE *rotate_right(AVLNODE *root){
    //newroot is x, root is y
    AVLNODE *newRoot = root->left;
    AVLNODE *temp = newRoot->right;
    //Peform rotations:
    newRoot->right = root;
    root->left = temp;
    //Update heights:
    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
 }
 
 AVLNODE *extract_smallest_node(AVLNODE **rootp) {
   AVLNODE *p = *rootp, *parent = NULL;
   if (p) {
     while (p->left) {
       parent = p;
       p = p->left;
     }
     if (parent == NULL)
       *rootp = p->right;
     else
       parent->left = p->right;
     
     p->left = NULL;
     p->right = NULL;
   }
   return p;
 }
 
 /* Insert a node of given record data into AVL tree.
 *
 * @param rootp - pointer of pointer to tree root.
 * @param data  - record data for the new node.
 */
 void avl_insert(AVLNODE **rootp, RECORD data){  
   // 1. Perform the normal BST insertion incase its empty
   if (*rootp == NULL) {
     AVLNODE *np = (AVLNODE *) malloc(sizeof(AVLNODE));
       if (np) {
         np->data = data;
         np->height = 1;
         np->left = NULL;
         np->right = NULL;
       }
       *rootp = np;
   } else {
    // a pointer to the root will point to the pointer to the root pointer
     AVLNODE *root = *rootp;
     
     if (strcmp(data.name, root->data.name) == 0 )
       return;
     else if (strcmp(data.name, root->data.name) < 0 ) {
       avl_insert(&root->left, data);
     }
     else {
       avl_insert(&root->right, data);
     }
     
     // 2. update height of this ancestor node

     //in this case **rootp is *node
     root->height = max(height(root->left),height(root->right)) + 1;
     
     // 3. Get the balance factor of this ancestor node to check whether this node became unbalanced
     int balance = balance_factor(root);
    
     // 4. rebalance if not balanced
     //Left rotations
     if(balance > 1){
      //LL
      if(root->left !=NULL && strcmp(data.name, root->left->data.name) < 0){
        *rootp = rotate_right(root);
     }
     //LR
      if(root->left != NULL && strcmp(data.name,root->left->data.name) > 0){
        root->left = rotate_left(root->left);
        *rootp = rotate_right(root);
      }
    }
    //Right rotations
    if(balance < -1){
      //RR
      if(root->right != NULL && strcmp(data.name, root->right->data.name) > 0){
        *rootp = rotate_left(root);
      }
      //RL
      if(root->right != NULL && strcmp(data.name, root->right->data.name) < 0){
        root->right = rotate_right(root);
        *rootp = rotate_left(root);
      }
    }
   }
  }
 
  void avl_delete(AVLNODE **rootp, char *name) {
    if (*rootp == NULL) return;

    AVLNODE *root = *rootp;
    AVLNODE *np;

    // Step 1: Perform standard BST deletion
    if (strcmp(name, root->data.name) == 0) {
        // Case 1: No children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            *rootp = NULL;
        }
        // Case 2: One child (left)
        else if (root->left != NULL && root->right == NULL) {
            np = root->left;
            free(root);
            *rootp = np;
        }
        // Case 3: One child (right)
        else if (root->left == NULL && root->right != NULL) {
            np = root->right;
            free(root);
            *rootp = np;
        }
        // Case 4: Two children (find inorder successor)
        else {
            np = extract_smallest_node(&root->right); // Successor node
            np->left = root->left;
            np->right = root->right;
            free(root);
            *rootp = np;
        }
    } 
    else {
        if (strcmp(name, root->data.name) < 0) {
            avl_delete(&root->left, name);
        } else {
            avl_delete(&root->right, name);
        }
    }

    // Step 2: If the tree had only one node, return
    if (*rootp == NULL) return;
    root = *rootp; // Update root after deletion

    // Step 3: Update height of the current node
    root->height = max(height(root->left), height(root->right)) + 1;

    // Step 4: Get the balance factor to check for unbalance
    int balance = balance_factor(root);

    // **Fixing Rotations after Deletion**
    if (balance > 1) {  // Left-heavy
        if (balance_factor(root->left) >= 0) { // Left-Left (LL)
            *rootp = rotate_right(root);
        } else { // Left-Right (LR)
            root->left = rotate_left(root->left);
            *rootp = rotate_right(root);
        }
    }
    else if (balance < -1) {  // Right-heavy
        if (balance_factor(root->right) <= 0) { // Right-Right (RR)
            *rootp = rotate_left(root);
        } else { // Right-Left (RL)
            root->right = rotate_right(root->right);
            *rootp = rotate_left(root);
        }
    }
}

 
 AVLNODE *avl_search(AVLNODE *root, char *name) {
  AVLNODE *node = root;
  while (node != NULL) {
    int check = strcmp(name, node->data.name);
    if (check < 0) {
      node = node->left;
    } else if (check > 0) {
      node = node->right;
    } else {
      return node;
    }
  }
  return NULL;
}
 
 
 void avl_clean(AVLNODE **rootp) {
   AVLNODE *root = *rootp;
   if (root) {
     if (root->left)
       avl_clean(&root->left);
     if (root->right)
       avl_clean(&root->right);
     free(root);
   }
   *rootp = NULL;
 }