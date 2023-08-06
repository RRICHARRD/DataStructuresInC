
#include <stdlib.h>
#include <stdio.h>

#include <DoublyLinkedList.h>


int main(){
    
    DoublyLinkedList *doubly_linked_list = (DoublyLinkedList*) create_doubly_linked_list();

    insert_last(doubly_linked_list, 1);
    insert_last(doubly_linked_list, 2);
    insert_last(doubly_linked_list, 3);
    insert_last(doubly_linked_list, 4);
    insert_last(doubly_linked_list, 5);

    show_from_head(doubly_linked_list);

    return EXIT_SUCCESS;
}