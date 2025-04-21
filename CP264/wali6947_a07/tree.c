/*
* your program signature
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "queue_stack.h"
 #include "tree.h"
 
 TPROPS tree_property(TNODE *root) {
     TPROPS tree1;
 
     if (root == NULL) {
         tree1.order = 0;
         tree1.height = 0;
         return tree1;
     }
 
     tree1.order = 1 + tree_property(root->left).order
             + tree_property(root->right).order;
     int left = tree_property(root->left).height;
     int right = tree_property(root->right).height;
 
     tree1.height = (left > right) ? left + 1 : right + 1;
     return tree1;
 }
 
 void preorder(TNODE *root) {
     if (root) {
         printf("%c ", root->data);
         preorder(root->left);
         preorder(root->right);
     }
 }
 
 void inorder(TNODE *root) {
     if (root) {
         inorder(root->left);
         printf("%c ", root->data);
         inorder(root->right);
     }
 }
 
 void postorder(TNODE *root) {
     if (root) {
         postorder(root->left);
         postorder(root->right);
         printf("%c ", root->data);
     }
 }
 
 
 void bforder(TNODE *root) {
     QUEUE queue1 = { };
     TNODE *check = NULL;
 
     if (root == NULL) {
         return;
     }
 
     enqueue(&queue1, root);
     while (queue1.front) {
         check = dequeue(&queue1);
         if (check) {
             printf("%c ", check->data);
             enqueue(&queue1, check->left);
             enqueue(&queue1, check->right);
         }
     }
 }
 
 TNODE *bfs(TNODE *root, char val) {
     if (root == NULL) {
         return NULL;
     }
     TNODE *node[1000];
     int check1 = 0, check2 = 0;
     node[check2++] = root;
 
     while (check1 < check2) {
         TNODE *curr = node[check1++];
         if (curr->data == val) {
             return curr;
         }
         if (curr->left != NULL) {
             node[check2++] = curr->left;
         }
         if (curr->right != NULL) {
             node[check2++] = curr->right;
         }
     }
     return NULL;
 }
 
 TNODE *dfs(TNODE *root, char val) {
     TNODE *node = NULL;
     if (root) {
         STACK stack = { 0 };
         push(&stack, root);
         while (stack.top) {
             TNODE *check = (TNODE*) pop(&stack);
             if (check->data == val) {
                 node = check;
                 break;
             }
 
             if (check->left) {
                 push(&stack, check->right);
             } else if (check->right) {
                 push(&stack, check->left);
             }
         }
         clean_stack(&stack);
     }
     return node;
 }
 
 
     // the following functions are given, need to add to your program.
 
     TNODE *tree_node(char val) {
         TNODE *np = (TNODE *) malloc(sizeof(TNODE));
         if (np != NULL) {
             np->data = val;
             np->left = NULL;
             np->right = NULL;
         }
         return np;
     }
 
     void clean_tree(TNODE **rootp) {
         TNODE *p = *rootp;
         if (p) {
             if (p->left)
                 clean_tree(&p->left);
             if (p->right)
                 clean_tree(&p->right);
             free(p);
         }
         *rootp = NULL;
     }
 
     void insert_tree(TNODE **rootp, char val) {
         if (*rootp == NULL) {
             *rootp = tree_node(val);
         } else {
             QUEUE queue = { 0 };
             TNODE *p;
             enqueue(&queue, *rootp);
             while (queue.front) {
                 p = dequeue(&queue);
                 if (p->left == NULL) {
                     p->left = tree_node(val);
                     break;
                 } else {
                     enqueue(&queue, p->left);
                 }
 
                 if (p->right == NULL) {
                     p->right = tree_node(val);
                     break;
                 } else {
                     enqueue(&queue, p->right);
                 }
             }
         }
     }