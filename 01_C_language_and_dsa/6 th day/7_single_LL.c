#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data ;
    struct Node *next;
};
int main()
{
    struct Node *first, *second,*third,*newNode,*temp;
    first=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    newNode=(struct Node *)malloc(sizeof(struct Node));
    

first->data=10;
second->data=20;
third->data=30;
newNode->data=5;

first->next =second;
second->next=third;
third->next=NULL;

newNode->next=first;
first=newNode;
temp =first;
printf("After Insertion at Beginning: \n");
while(temp !=NULL)
{
    printf("%d->",temp->data);
    temp =temp->next;
}
printf("NULL\n");
free(first);
free(second);
free(third);
free(newNode);
return 0;
}