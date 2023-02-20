#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int value;
    struct Node *next; //store address of another node
} *head, *tail; //global var to store the address of first and last node in the LinkedList (LL)

struct Node *createNode(int value){
    Node *newNode =(Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}


void readNode(Node *currentNode){
printf("Value: %d\n", currentNode-> value);
printf("Alamat Node sekarang: %p\n", currentNode);
printf("Alamat Node setelahnya: %p\n",currentNode->next);
}

void pushTail(int value)
{
    Node *temp = createNode(value);
    tail->next = temp;
    tail = temp;

}
int main(){

    Node *nodePertama = createNode(10);
    
    return 0;
}