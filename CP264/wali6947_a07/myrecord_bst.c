/*
* your program signature
 */

 #include <stdio.h>
 #include <math.h>
 #include "bst.h"
 #include "myrecord_bst.h"
 double stdev(BSTNODE *sewy, float val) {
     if (sewy == NULL) {
         return 0;
     }
 
     double val2 = pow(sewy->data.score - val, 2) + stdev(sewy->left, val)
             + stdev(sewy->right, val);
     if (isnan(val2)) { 
         return 0.0;
     }
     return val2;
 }
 void add_record(BSTDS *ds, RECORD record) {
     bst_insert(&(ds->root), record);
     ds->count++;
 
     ds->mean = (ds->mean * (ds->count - 1) + record.score) / ds->count;
 
     if (ds->count == 0) {
         ds->stddev = 0;
         ds->mean = 0;
         return;
     }
     ds->stddev = sqrt(stdev(ds->root, ds->mean) / ds->count);
 }
 
 void remove_record(BSTDS *ds, char *name) {
     BSTNODE *sewy = bst_search(ds->root, name);
 
     if (sewy != NULL) {
         ds->count--;
         ds->mean = (ds->mean * (ds->count + 1) - sewy->data.score) / ds->count;
         bst_delete(&ds->root, name);
 
         double val = sqrt(stdev(ds->root, ds->mean) / ds->count);
         if (isnan(val)) {
             ds->stddev = 0;
         } else {
             ds->stddev = val;
         }
     }
 
     if (ds->count == 0) {
         ds->stddev = 0;
         ds->mean = 0;
     }
 }
 
 void bstds_clean(BSTDS *ds) {
     bst_clean(&ds->root);
     ds->count = 0;
     ds->mean = 0;
     ds->stddev = 0;
 }