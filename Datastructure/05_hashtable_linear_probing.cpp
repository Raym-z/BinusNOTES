#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_BUCKETS = 20;

struct Node
{
    char name[255];

} *bucket[MAX_BUCKETS];

Node *createNode(const char *name)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    strcpy(temp->name, name);
    return temp;
}

int hashFunction(const char *str)
{
    int key = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        key += str[i];
    }
    return key % MAX_BUCKETS;
}

void linearProb(int index, Node *toInstert)
{
    for (int i = (index + 1); i != index; i = (i + 1) % MAX_BUCKETS)
    {
        if (!bucket[i])
        {
            bucket[i] = toInstert;
            return;
        }
    }
    puts("TABLE IS FULL");
    return;
}

void insert(const char *str)
{
    Node *temp = createNode(str);
    int index = hashFunction(str);

    if (!bucket[index])
    {
        bucket[index] = temp;
    }
    else
    {
        linearProb(index, temp);
    }
}

void view()
{
    for (int i = 0; i < MAX_BUCKETS; i++)
    {
        printf("Index %d: ", i);
        if (bucket[i])
        {
            printf("%s\n", bucket[i]->name);
        }
        else
            puts("NULL");
    }
}

int main()
{
    char names[][255] = {
        {"romario"}, {"admiralspoon"}, {"kesya"}, {"nich"}, {"valencia"}, {"laffpai"}, {"kevice"}, {"darnell"}, {"doctorneuron"}, {"ashborne"}, {"hans"}, {"whisper"}};

    for (int i = 0; i < 12; i++)
    {
        insert(names[i]);
    }

    view();
    return 0;
}