 
#include <stdio.h>
#include <stdlib.h>

#include <CircularLinkedList.h>

int main(){

    CircularLinkedList *circular_linked_list = (CircularLinkedList *) create_circuluar_linked_list();

    insert_new_node(circular_linked_list, 1);

    return EXIT_SUCCESS;
}