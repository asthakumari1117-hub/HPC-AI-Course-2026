#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data ;
    struct Node *next;
};
int main()
{
    struct Node *first,*second,*third,*temp;

    first=(struct Node*)malloc (sizeof(struct Node));
    second=(struct Node*)malloc (sizeof(struct Node));
    third=(struct Node*)malloc (sizeof(struct Node));
first->data=10;
second->data=20;
third->data=30;

first->next =second;
second->next=third;
third->next=NULL;
temp=first;

while(temp->next !=third)
{
    
    temp =temp->next;
}
temp->next=NULL;
free(third);
printf("after Deleting Last Node :\n");
temp=first;
while(temp!=NULL)
{
    printf("%d->",temp->data);
    temp=temp->next;
}
printf("NULL\n");
free(first);
free(second);
return 0;
}