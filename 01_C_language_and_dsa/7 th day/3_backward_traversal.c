#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

int main()
{
    struct Node *first,*second,*third,*temp;
    first =(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

    first->data=10;
    second->data=20;
    third->data=30;

    first->prev=NULL;
    first->next=second;

    second->prev=first;
    second->next=third;

    third->prev=second;
    third->next=NULL;
    temp=third;

    printf("Backward Traversal \n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->prev;
    }

    free(first);
    free(second);
    free(third);
    return 0;
}