#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    Node *next; //store address of another node    
}*head,*tail;//global var 

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value; // fill in value with the given parameter
    newNode->next = NULL; // at first, next node is set to NULL
    return newNode; // return new node
}

void readNode(Node *currentNode)
{
    printf("Value: %d\n", currentNode->value);
    printf("Alamat node sekarang: %p\n", currentNode);
    printf("Alamat node setelahnya: %p\n", currentNode->next);
}

void pushTail(int value)
{
    Node *temp = createNode(value);// create new node
    if (!head) // no head ( still empty )
    {
        head = tail = temp; //tail will be new head and the new tail
    }
    else
    {
    tail->next = temp; //tail node will point to new node in LL (basicly new tail)
    tail = temp; // new node will be the last node in LL (tail)
    }
}
void popTail()
{
    if(!head) return; // no node to delete anyways so just return

    else if (head == tail) // only 1 node
    {
        free(head); //free allocated memory (basicly deleting it)
        head = tail = NULL; // both head and tail is now NULL so there are no nodes now 
    }

    else // if this is triggered that means there is more than 1 node 
    {
        Node *temp =head;
        while(temp->next !=tail) // while next node is not tail
        {
            temp = temp->next; //continue loop until you are behind tail
        }
        // 50 (head) -> 30 -> 42 (temp) -> 100 (tail) -> NULL
        temp->next = NULL;// 50 (head) -> 30 -> 42 (temp) -> NULL || 100 (tail) -> NULL
        free(tail); // 50 (head) -> 30 -> 42 (temp) -> NULL
        tail=temp; // 50 (head) -> 30 -> 42 (tail, temp) -> NULL
    }
}

void printLinkedList()
{
    for (Node *temp = head; temp!=NULL;temp = temp->next)
    {
        readNode(temp);
        puts("|");
        puts("|");  
        puts("v");
    }
    puts("NULL");
}

int main()
{
    pushTail(10);
    pushTail(15);
    pushTail(30);
    printLinkedList();
    popTail();
    printLinkedList();

  return 0;
}