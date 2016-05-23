#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node * next;
    int val;
}Node;

void initialize(Node **n){
    *n = NULL;
}

int addInFront(Node **head, int val){
    Node * aux = (Node*)malloc(sizeof(Node));
    if(aux==NULL){
        printf("Error while allocating memory");
        return 0;
    }
    if(*head == NULL){
        aux->next = NULL;
        *head = aux;
    } else {  // there is/are element(s) on the list
        (*aux).next = *head;
        *head = aux;
    }
    (*head)->val = val;
    return 1; // successful insertion
}

void removeElement(Node **head, int value){
    Node * aux1 = *head;
    Node * aux2;
    while(aux1!= NULL){
        if (aux1->val!=value){
            aux2 = aux1;
            aux1 = aux1->next;
        } else{
            if(aux1 == *head){
                *head = aux1->next;
                free(aux1);
                aux1 = *head;
            } else{
                aux2->next = aux1->next;
                free(aux1);
                aux1 = aux2->next;
            }
        }
    }
}


void printList(Node ** head){
    Node * aux = *head;
    while(aux!=NULL){
        printf("%d ", aux->val);
        aux = aux->next;
    }
    printf("\n");
}

int main(){
    Node * ll;
    int n, val;
    initialize(&ll);
    
    printf("How many values: ");
    scanf("%d", &n);
     
    int i = 1;
    for(i; i<=n; i=i+1){
        fflush(stdin);
        scanf("%d", &val);
        addInFront(&ll, val);
    }
    printList(&ll);
    int remove;
    scanf("%d", &remove);
    removeElement(&ll, remove);
    printList(&ll);

    return 0;
}
