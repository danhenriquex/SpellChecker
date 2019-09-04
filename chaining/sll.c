#include "sll.h"

struct Sll* CreateNode(void) {

    struct Sll* list = (struct Sll*) malloc(sizeof(struct Sll));
    list->head = NULL;
    list->tail = NULL;
    ++list->size;

    return list;
}

void Append(struct Sll* list, char* word) {

    struct Node* n1;

    if(list->head == NULL) {

        list->head = (struct Node*) malloc(sizeof(struct Node));
        
        list->head->word = word;
        list->head->next = NULL;
        list->tail = list->head;
        list->tail->next = NULL;

    }else {

        list->tail = list->head;

        while(list->tail->next != NULL) 
            list->tail = list->tail->next;

        n1 = (struct Node*) malloc(sizeof(struct Node));
        
        n1->word = word;
        n1->next = NULL;
        list->tail->next = n1;

    }

    ++list->size;

}

void Prepend(struct Sll* list, char* word) {

    struct Node* n1 = NULL;

    if(list->head == NULL) {

        list->head = (struct Node*) malloc(sizeof(struct Node));
        
        list->head->word = word;
        list->head->next = NULL;
        list->tail = list->head;
        list->tail->next = NULL;

    }else {

        n1 = (struct Node*) malloc(sizeof(struct Node));

        n1->word = word;
        n1->next = list->head; 
        list->head = n1;

    }

    ++list->size;

}

void WrongWords(struct Sll* list, char* word) {

    struct Node* n1 = NULL;

    if(list->head == NULL) {

        n1 = (struct Node*) malloc(sizeof(struct Node));
        n1->next = NULL;
        n1->word = word;

        strcpy(n1->palavra, word);

        list->head = n1;
        
        list->tail = list->head;
        list->tail->next = NULL;

    }else {

        n1 = (struct Node*) malloc(sizeof(struct Node));

        strcpy(n1->palavra, word);

        n1->word = word;
        n1->next = list->head; 
        list->head = n1;

    }

    ++list->size;

}

void DestroyList(struct Sll* list) { 

    if(list->head == NULL) {

        free(list);

    }else {

        struct Node* aux;

        aux = list->head;  

        while(aux != NULL) {

            list->head = aux->next;
            free(aux);
            aux = list->head;

        }

    }

}

void Delete(struct Sll* list, struct Node* node) { 

    if(list == (struct Sll*) node) {

        list = NULL;
        free(node);

    }else {

        struct Node* aux = NULL;
        struct Node* aux2 = NULL;

        aux = list->head;

        while(aux != node) {

            aux2 = aux;
            aux = aux->next;

        }

        aux2->next = aux->next;
        free(aux);

    }

}

void PrintList(struct Sll* list, int index) {

    if(list->head == NULL) {

        printf("Vazio.\n");

    }else {

        struct Node* aux;

        aux = list->head;

        int i = 0;

        while(aux != NULL) {
            
            printf("table[%i] = %s\n", index, aux->word);
            aux = aux->next;
            ++i;

        }

        free(aux);

    }
}

