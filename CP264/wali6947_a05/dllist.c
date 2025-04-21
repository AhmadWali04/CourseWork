#include "dllist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


NODE* dll_node(char value) {
	NODE *node = (NODE *) malloc(sizeof(NODE));
	node->data = value;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

void dll_insert_start(DLL *dllp, NODE *np) {
	//case: empty
	if (dllp->start == NULL) {
		dllp->start = np;
		dllp->end = np;
		dllp->length = 1;
	} else { // case: not empty
		NODE *next = dllp->start;
		dllp->start = np;
		np->next = next;
		next->prev = np;
		dllp->length += 1;
	}

}

void dll_insert_end(DLL *dllp, NODE *np) {
	//case: empty
	if (dllp->start == NULL) {
		dllp->start = np;
		dllp->end = np;
		dllp->length = 1;
	} else { // case: not empty
		NODE *prev = dllp->end;
		dllp->end = np;
		np->prev = prev;
		prev->next = np;
		dllp->length += 1;
	}
}

void dll_delete_start(DLL *dllp) {
	if (dllp->start == NULL) {
		return;
	}
	//case: length == 1
	if (dllp->length == 1) {
		dllp->length = 0;
		free(dllp->start);
		dllp->start = NULL;
		dllp->end = NULL;
		//free(dllp->end);
		return;
	}

	// case: not empty
	NODE *next = dllp->start->next;
	dllp->start->next = NULL;
	dllp->start->data = 0;
	free(dllp->start);
	dllp->start = next;
	dllp->length -= 1;

}

void dll_delete_end(DLL *dllp) {

	//case: empty
	if (dllp->start == NULL) {
		return;
	}

	//case: length == 1
	if (dllp->length == 1) {
		dllp->length = 0;
		free(dllp->end);

		dllp->start = NULL;
		dllp->end = NULL;

		//free(dllp->start);
		//

		return;
	}

	// case: not empty
	NODE *prev = dllp->end->prev;
	dllp->end->prev = NULL;
	dllp->end->data = 0;
	free(dllp->end);

	prev->next = NULL;
	dllp->end = prev;

	dllp->length -= 1;

}

void dll_clean(DLL *dllp) {

	NODE *curr = dllp->start;
	while (dllp->length > 0) {
		NODE *next = curr->next;

		//freeing curr
		curr->data = 0;
		curr->next = NULL;
		curr->prev = NULL;

		free(curr);
		curr = NULL;

		// minus len
		dllp->length -= 1;

		//next node
		dllp->start = next;
		curr = next;

	}
	dllp->start = NULL;
	dllp->end = NULL;

}