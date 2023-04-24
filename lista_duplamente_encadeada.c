#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dado;
    struct node *ant;
    struct node *prox;
} Node;

Node *head = NULL;
Node *current = NULL;

void add_inicio(int dado){
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->dado = dado;
    new_node->prox = head;
    head->ant = new_node;
    head = new_node;
    new_node->ant = NULL;
    if (current == NULL)
        current = new_node;   
}

void add_fim(int dado){
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->dado = dado;
    new_node->prox = NULL;
    new_node->ant = current;
    current->prox = new_node;
    current = new_node;
    if (head == NULL)
        head = new_node;
    
}
void imprimir(){
    current = head;
    while (current != NULL) {
        printf("%d\n", current->dado);
        current = current->prox;
    }
}

void freeList(Node *head) {
    Node *current = head;
    Node *temp;

    while (current != NULL) {
        temp = current;
        current = current->prox;
        free(temp);
    }
}

int main(){

    add_inicio(1);
    add_fim(2);
    add_fim(3);
    add_inicio(0);
    imprimir();
    freeList(head);

    return 0;
}