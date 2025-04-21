 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "bst.h"
 
 
 BSTNODE *bst_node(RECORD data);
 BSTNODE *extract_smallest_node(BSTNODE **rootp);
 
 
 BSTNODE *bst_search(BSTNODE *root, char *key) {
     while (root) {
         int num = strcmp(root->data.name, key);
         if (num == 0) {
             return root;
         } else if (num < 0) {
             root = root->right;
         } else {
             root = root->left;
         }
     }
     return NULL;
 }
 
 void bst_insert(BSTNODE **rootp, RECORD data) {
     if (*rootp == NULL) {
         *rootp = bst_node(data);
         return;
     }
 
     BSTNODE *check = *rootp;
 
     while (1) {
         int num = strcmp(check->data.name, data.name);
         if (num == 0) {
             check->data.score = data.score;
             return;
         } else if (num < 0) {
             if (check->right == NULL) {
                 check->right = bst_node(data);
                 return;
             }
             check = check->right;
         } else {
             if (check->left == NULL) {
                 check->left = bst_node(data);
                 return;
             }
             check = check->left;
         }
     }
 }
 
 void bst_delete(BSTNODE **rootp, char *key) {
     BSTNODE *root = *rootp;
     BSTNODE *check = NULL;
 
     while (root) {
         int num = strcmp(root->data.name, key);
         if (num == 0) {
             if (root->left == NULL && root->right == NULL) {
                 if (check == NULL) {
                     *rootp = NULL;
                 } else if (check->left == root) {
                     check->left = NULL;
                 } else {
                     check->right = NULL;
                 }
                 free(root);
             } else if (root->left == NULL) {
                 if (check == NULL) {
                     *rootp = root->right;
                 } else if (check->left == root) {
                     check->left = root->right;
                 } else {
                     check->right = root->right;
                 }
                 free(root);
             } else if (root->right == NULL) {
                 if (check == NULL) {
                     *rootp = root->left;
                 } else if (check->left == root) {
                     check->left = root->left;
                 } else {
                     check->right = root->left;
                 }
                 free(root);
             } else {
                 BSTNODE *node = extract_smallest_node(&root->right);
                 memcpy(&root->data, &node->data, sizeof(RECORD));
                 free(node);
             }
             return;
         } else if (num < 0) {
             check = root;
             root = root->right;
         } else {
             check = root;
             root = root->left;
         }
     }
 }
 
 
 BSTNODE *bst_node(RECORD data) {
     BSTNODE *np = (BSTNODE *) malloc(sizeof(BSTNODE));
     if (np) {
         memcpy(np, &data, sizeof(BSTNODE));
         np->left = NULL;
         np->right = NULL;
     }
     return np;
 }
 
 void bst_clean(BSTNODE **rootp) {
     BSTNODE *root = *rootp;
     if (root) {
         if (root->left)
             bst_clean(&root->left);
         if (root->right)
             bst_clean(&root->right);
         free(root);
     }
     *rootp = NULL;
 }
 
 BSTNODE *extract_smallest_node(BSTNODE **rootp) {
     BSTNODE *p = *rootp, *parent = NULL;
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