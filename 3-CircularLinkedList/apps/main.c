 
#include <stdio.h>
#include <stdlib.h>

#include <CircularLinkedList.h>

int main(){

    CircularLinkedList *circular_linked_list = (CircularLinkedList *) create_circuluar_linked_list();

    insert_new_node(circular_linked_list, 0);
    insert_new_node(circular_linked_list, 1);
    insert_new_node(circular_linked_list, 2);
    insert_new_node(circular_linked_list, 3);
    insert_new_node(circular_linked_list, 4);
    insert_new_node(circular_linked_list, 5);
    insert_new_node(circular_linked_list, 6);
    insert_new_node(circular_linked_list, 7);
    insert_new_node(circular_linked_list, 8);
    insert_new_node(circular_linked_list, 9);

    show(circular_linked_list, true);

    return EXIT_SUCCESS;
}