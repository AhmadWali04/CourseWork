/*
 * your program signature
 */ 
 
 #include "string.h" 
 #include "avl.h"
 #include "set_avl.h"
 
 int set_size(SET *s) {
    if(s!=NULL){
        return s->size;
    }
    return 0;
 }
 
 int set_contain(SET *s, char *e){
    if(s==NULL || s->root == NULL){
        return 0;
    }
    return avl_search(s->root,e) != NULL;
 }
 
 void set_add(SET *s, char *e){
    if(s==NULL){
        return;
    }
    RECORD temp;
    strcpy(temp.name,e);
    avl_insert(&(s->root),temp);
    s->size++;
 }
 
 void set_remove(SET *s, char *e){
    if(s==NULL || s->root == NULL){
        return;
    }
    if(set_contain(s,e)){
        avl_delete(&(s->root),e);
        s->size--;
    }
 }
 
 void set_clean(SET *s){
    if (s==NULL){
        return;
    }
    avl_clean(&(s->root));
    s->size=0;
 }   