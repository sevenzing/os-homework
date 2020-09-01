#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// ====================================
// Implementation of doubly linked list
// ====================================

int min(int num1, int num2) {
    /**
     * Find minimum between two numbers.
     */
    return (num1 > num2 ) ? num2 : num1;
}
struct Node{
    struct Node *prev;
    struct Node *next;
    int data;
};

struct Node* __create_node(int value){
    /*
    * Allocate memory for new node.
    */
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = value;
    return new_node;
}

struct Node* create_list(){
    /*
    * Create head of the list
    */
    return __create_node(0x14881488);
}

struct Node* __get_node(struct Node *head, int index){
    /*
    * Return node with index=`index`
    */
    
    struct Node *cur_node = head;
    for (int i = 0; i < index + 1; i++){
        cur_node = cur_node->next;
    }
    return cur_node;
}

int get_list_size(struct Node *head){
    /*
    * Return size of the list
    */
    int c = 0;
    struct Node *cur_node = head;
    while (cur_node->next != NULL){
        c++;
        cur_node = cur_node->next;
    }

    return c;
}

void print_list(struct Node *head){
    /*
    * Print all numbers in the list
    */
    int counter = 0;
    struct Node *cur_node = head->next;
    printf("[");
    while (cur_node != NULL){
        printf("%d", cur_node->data);
        cur_node = cur_node->next;
        if (cur_node != NULL){
            printf(", ");
        }
        counter++;
    }
    printf("]\n");
}


void insert_node(struct Node *head, int index, int value){
    /* 
     Insert value BEFORE the node with index=`index`
     [1,2,3] -> insert(0, 4) -> [4,1,2,3]
     [1,2,3] -> insert(3, 4) -> [1,2,3,4]
    */
    int list_size = get_list_size(head);
    index = min(index, list_size);

    // Insert AFTER cur_node, since index = `index - 1`
    struct Node *cur_node = __get_node(head, index - 1);
    struct Node *new_node = __create_node(value);
    new_node->next = cur_node->next;
    new_node->prev = cur_node;
    
    if (cur_node->next != NULL){
        cur_node->next->prev = new_node;
    }
    cur_node->next = new_node;

}

void append_node(struct Node *head, int value){
    int n = get_list_size(head);
    insert_node(head, n, value);
}

void delete_node(struct Node *head, int index){
    assert(0<= index <= get_list_size(head));

    struct Node *cur_node = __get_node(head, index);
    struct Node *prev_node = cur_node->prev;
    struct Node *next_node = cur_node->next;
    
    prev_node->next = next_node;
    if (next_node != NULL){
        next_node->prev = prev_node;
    }

    free(cur_node);
}


int main(int argc, char const *argv[]){
    // ====================
    // Python style of list
    // ====================

    struct Node *head = create_list();
    append_node(head, 1);
    append_node(head, 2);
    append_node(head, 3);
    insert_node(head, 0, 5);
    insert_node(head, 1, 4);

    print_list(head); // [5, 4, 1, 2, 3]
    
    delete_node(head, 3);
    delete_node(head, 1);
    
    print_list(head); // [5, 1, 3]

    delete_node(head, 0);
    delete_node(head, 0);
    delete_node(head, 0);
    print_list(head); // []
    append_node(head, 1);
    insert_node(head, 0, 5);
    print_list(head); // [5, 1]
    
    return 0;
}


