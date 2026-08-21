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
    int count=0;
    
    first =(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

    // first->data=10;
    // second->data=20;
    // third->data=30;

    first->prev=NULL;
    first->next=second;

    second->prev=first;
    second->next=third;

    third->prev=second;
    third->next=NULL;
    temp=first;

    
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
printf("Total Nodes =%d\n",count);
    free(first);
    free(second);
    free(third);
    return 0;
}