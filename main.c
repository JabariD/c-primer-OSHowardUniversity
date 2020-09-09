#include <stdio.h>

#include "list.h"

int main() {
    printf("Tests for linked list implementation\n");

    /* NOTE: This Linked List is 0-indexed. */
    
    list_t* head = list_alloc();
    list_add_to_back(head, 2); // 2
    list_add_to_back(head, 5); // 2, 5
    list_add_to_front(head, 10); // 10, 2, 5
    list_add_at_index(head, 100, 0); // 100, 10, 2, 5
    list_add_at_index(head, 50, 3); // 100, 10, 2, 50, 5
    list_remove_from_back(head); // 100, 10, 2, 50

    printf("Size: %d\n", list_length(head)); // 4

    printf("%s", list_is_in(head, 100) ? "true\n" : "false\n"); // true

    list_add_at_index(head, 75, 1); // 100, 75, 10, 2, 50
    list_remove_at_index(head, 2); // 100, 75, 2, 50
    list_remove_from_back(head); // 100, 75, 2
    list_remove_from_front(head); // 75, 2

    printf("Size: %d\n", list_length(head)); // 2


    printf("%s", list_is_in(head, 100) ? "true\n" : "false\n"); // false
    printf("%s", list_is_in(head, 75) ? "true\n" : "false\n"); // true

    list_add_to_front(head, 100); // 100, 75, 2
    list_add_to_front(head, 200); // 200, 100, 75, 2
    
    printf("%d\n", list_get_elem_at(head, 2)); // 75

    printf("%d\n", list_get_index_of(head, 4)); // -1

    list_print(head); // 200, 100, 75, 2

    list_free(head);
    return 0;
}