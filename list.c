// list/list.c
// 
// Implementation for linked list.
//
// <Payton Dennis>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int SIZE = 0;

list_t *list_alloc() { 
    list_t *list = malloc(sizeof(list_t));
    list->head = NULL;
    return list; 
}

void list_free(list_t *l) {
    if (l->head == NULL) return;
    node_t *ptr = l->head;
    while (ptr->next != NULL) {
        node_t *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    free(ptr);
    free(l);
}

void list_print(list_t *l) {
    node_t* ptr;
    for (ptr = l->head; ptr != NULL; ptr = ptr->next ) {
        printf("%d ", ptr->value);
    }
}
int list_length(list_t *l) { return SIZE; }

void list_add_to_back(list_t *l, elem value) {
    node_t *temp = malloc(sizeof(node_t));
    temp->value = value;
    temp->next = NULL;

    if (l->head == NULL) {
        l->head = temp;
    } else {
        node_t* ptr = l->head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    SIZE += 1;
}
void list_add_to_front(list_t *l, elem value) {
    node_t *temp = malloc(sizeof(node_t));
    temp->value = value;
    temp->next = l->head;

    l->head = temp;
    SIZE += 1;
}
void list_add_at_index(list_t *l, elem value, int index) {
    if (index < 0 || index > SIZE) return;

    if (index == 0) list_add_to_front(l, value);
    else if (index == SIZE) list_add_to_back(l, value);
    else {
        node_t *temp = malloc(sizeof(node_t));
        temp->value = value;
        temp->next = NULL;

        node_t* ptr = l->head;
        int count = 0;
        while (ptr->next != NULL && count < index - 1) {
            ptr = ptr->next;
            count++;
        }
        node_t* holder = ptr->next;
        ptr->next = temp;
        temp->next = holder;
        SIZE += 1;
    }

}

elem list_remove_from_back(list_t *l) { 
    elem value;
    if (l->head->next == NULL) {
        value = l->head->value;
        free(l->head);
        l->head = NULL;
    } else {
        node_t* ptr = l->head;
        while (ptr->next->next != NULL) {
            ptr = ptr->next;
        }
        value = ptr->next->value;
        free(ptr->next);
        ptr->next = NULL;
    }
    SIZE -= 1;
    return value;
}
elem list_remove_from_front(list_t *l) { 
    elem value;
    if (l->head == NULL) return value;
    
    value = l->head->value;
    node_t* holder = l->head;
    l->head = l->head->next;
    free(holder);

    SIZE -= 1;
    return value;
}
elem list_remove_at_index(list_t *l, int index) { 
    elem value;
    if (index < 0 || index > SIZE - 1) return value;

    if (index == 0) list_remove_from_front(l);
    else if (index == SIZE - 1) list_remove_from_back(l);
    else {
        node_t* ptr = l->head;
        int count = 0;
        while (ptr->next != NULL && count < index - 1) {
            ptr = ptr->next;
            count++;
        }
        node_t* holder = ptr->next;
        ptr->next = ptr->next->next;
        free(holder);
        SIZE -= 1;
    }
}

bool list_is_in(list_t *l, elem value) { 
    node_t* ptr;
    for (ptr = l->head; ptr != NULL; ptr = ptr->next ) {
        if (ptr->value == value) return true;
    }
    return false; 
}
elem list_get_elem_at(list_t *l, int index) {
    elem value;
    if (index > SIZE || index < 0) return value;
    int count = 0;
    node_t *ptr;
    for (ptr = l->head; ptr != NULL; ptr = ptr->next ) {
        if (count == index) return ptr->value;
        count += 1;
    }

}
int list_get_index_of(list_t *l, elem value) { 
    int index = 0;
    node_t* ptr;
    for (ptr = l->head; ptr != NULL; ptr = ptr->next ) {
        if (ptr->value == value) return index;
        index += 1;
    }
    return -1; 
}