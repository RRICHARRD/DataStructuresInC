#include <stdio.h>
#include <stdlib.h>

#include <LinkedList.h>

int main(){

    Linked_List *linked_list = (Linked_List *) create_linked_list();

    insert_first(linked_list, 1);
    insert_first(linked_list, 2);
    insert_first(linked_list, 3);
    insert_first(linked_list, 4);
    insert_last(linked_list, 5);
    insert_first(linked_list, 6);
    insert_last(linked_list, 7);
    insert_first(linked_list, 8);

    insert_new_node_after_node(linked_list, 7, 123);
    insert_new_node_after_node(linked_list, 6, 321);
    insert_new_node_after_node(linked_list, 8, 000);

    delete_node(linked_list, 123);
    delete_node(linked_list, 321);
    delete_node(linked_list, 8);
    delete_node(linked_list, 7);
    //delete_node(linked_list, 5);

    show(linked_list);

    int total_nodes = get_total_nodes(linked_list);
    printf("The linked list has %d nodes\n", total_nodes);

    printf("Destroing linked list values\n");
    destroy(&linked_list, false);
    //destroy(&linked_list, true); destroy to intire list of the memory
    
    printf("linked list reference is %p\n", linked_list);

    //show(linked_list); segmentation fault if destroyed the intire linked list before
    show(linked_list);

    return EXIT_SUCCESS;
}