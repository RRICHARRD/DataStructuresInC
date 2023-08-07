
#include <stdlib.h>
#include <stdio.h>

#include <DoublyLinkedList.h>

char *separator(){
    return "---------------";
}

void sprint(char *word){
    printf("\n%s %s %s\n", separator(), word, separator());
}

int main(){

    DoublyLinkedList *doubly_linked_list = (DoublyLinkedList*) create_doubly_linked_list();

    insert_last(doubly_linked_list, 1);
    insert_last(doubly_linked_list, 2);
    insert_last(doubly_linked_list, 3);
    insert_last(doubly_linked_list, 4);
    insert_last(doubly_linked_list, 5);

    sprint("normal head");
    show_from_head(doubly_linked_list);
    
    sprint("normal tail");
    show_from_tail(doubly_linked_list);

    insert_head(doubly_linked_list, 11);
    insert_head(doubly_linked_list, 22);
    insert_head(doubly_linked_list, 33);
    insert_head(doubly_linked_list, 44);
    insert_head(doubly_linked_list, 55);

    sprint("after insert head normal");
    show_from_head(doubly_linked_list);
    
    sprint("after insert head tail");
    show_from_tail(doubly_linked_list);

    sprint("deleting value 11");
    delete_node(doubly_linked_list, 11);
    show_from_head(doubly_linked_list);

    sprint("destroying doubly linked list nodes");
    destroy(&doubly_linked_list, false);
    show_from_tail(doubly_linked_list);

    return EXIT_SUCCESS;
}