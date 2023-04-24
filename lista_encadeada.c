#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;
Node *current = NULL;

void add_inicio(int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    if (current == NULL && head == NULL){
        current = new_node;
        head = new_node;
    }
}
 
void add_fim(int data){
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (current == NULL && head == NULL){
        current = new_node;
        head = new_node;
    }
    current->next = new_node;
    current = new_node;
}

void rmv_inicio(){
    Node *aux = head;
    head = head->next;
    free(aux);
}

void rmv_fim(){
    Node *aux = head;
    while (aux->next->next != NULL) {
        aux = aux->next;
    }
    current = aux;
    aux = aux->next;
    current->next = NULL;
    free(aux);

}

void imprimir(){
    current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void freeList(Node *head) {
    Node *current = head;
    Node *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {

    add_fim(2);
    add_inicio(1);
    add_fim(3);
    add_inicio(-1);
    rmv_inicio();
    rmv_fim();
    add_fim(4);
    imprimir();
    freeList(head);

    return 0;
}
