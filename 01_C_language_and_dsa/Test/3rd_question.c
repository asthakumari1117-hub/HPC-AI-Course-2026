//write a c program  to  create a circular linked list with user 5 input elements  and display all 
// the element of the linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
   
    int i;
    struct Node *head , *temp , *newNode ;
    

    for(i = 1; i <= 5; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter element %d: ", i);
        scanf("%d", &newNode->data);

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
            newNode->next = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
            temp->next = head;
        }
    }

   
    printf("\nElements of Circular Linked List are:\n");

    temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(Head)\n");

    return 0;
}