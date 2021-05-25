#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


struct node {
int data;
struct node * prev;
struct node * next;
}*head, *last;


//function declaration
void createList(int n);

void displayList();

void deleteFromBeginning();

void deleteFromEnd();

void deleteFromN(int position);

void insertAtBeginning(int data);

void insertAtEnd(int data);



int main()
{

int n, data, choice=1;

head = NULL;
last = NULL;

        printf("NAME: Khushi Arora\n\n CLASS: CSE2C \n\n RollNO: 2K20CSUN01058\n\n");
        printf("SELECT A DOUBLY LINKED LIST PROGRAM\n");
        printf("1. Deletion from beginning\n");
        printf("2. Deletion from end\n");
        printf("3. Deletion from a choosen position\n");
        printf("4. Insertion at beginning\n");
        printf("5. Insertion at the end\n");


        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            printf("*creating double link list*\nEnter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                
                deleteFromBeginning();
                break;
                
            case 2:
            printf("*creating double link list*\nEnter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                
                deleteFromEnd();
                break;
                
            case 3:
            printf("*creating double link list*\nEnter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                printf("Enter the node position which you want to delete: ");
                scanf("%d", &n);
                
                deleteFromN(n);
                break;
                
            case 4:
            printf("*creating double link list*\nEnter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                
                printf("Enter data of first node : ");
                scanf("%d", &data);

                insertAtBeginning(data);
                break;
                
            case 5:
            printf("*creating double link list*\nEnter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                
                 printf("Enter data of last node : ");
                scanf("%d", &data);

                insertAtEnd(data);
                break;
                
            default:
                printf("invalid input. please choose between 1-6");
        }

 getch();   
}



void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
    head = (struct node *)malloc(sizeof(struct node));

    printf("Enter data of 1 node: ");
    scanf("%d", &data);

    head->data = data;
    head->prev = NULL;
    head->next = NULL;

    last = head;

        
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last; 
            newNode->next = NULL;

            last->next = newNode; 
            last = newNode; 
        }

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}



void displayList()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;

            temp = temp->next;
        }
    }
}



void deleteFromBeginning()
{
    struct node * toDelete;

    if(head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = head;

        head = head->next; 
        
        if (head != NULL)
            head->prev = NULL; 

        free(toDelete); 
        printf("SUCCESSFULLY DELETED NODE FROM BEGINNING OF THE LIST.\n");
        displayList();
    }
}



void deleteFromEnd()
{
    struct node * toDelete;

    if(last == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = last;

        last = last->prev; 
        
        if (last != NULL)
            last->next = NULL; 

        free(toDelete);       
        printf("SUCCESSFULLY DELETED NODE FROM END OF THE LIST.\n");
        displayList();
    }
}


void deleteFromN(int position)
{
    struct node *current;
    int i;

    current = head;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }

    if(position == 1)
    {
        deleteFromBeginning();
    }
    else if(current == last)
    {
        deleteFromEnd();
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current); 

        printf("SUCCESSFULLY DELETED NODE FROM %d POSITION.\n", position);
        displayList();
    }
    else
    {
        printf("Invalid position!\n");
    }
}


void insertAtBeginning(int data)
{
    struct node * newNode;

    if(head == NULL)
    {
        printf("Error, List is Empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = head; 
        newNode->prev = NULL; 

        head->prev = newNode;

        head = newNode;

        printf("NODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST\n");
        displayList();

    }
}
void insertAtEnd(int data)
{
    struct node * newNode;

    if(last == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;

        last->next = newNode;
        last = newNode;

        printf("NODE INSERTED SUCCESSFULLY AT THE END OF LIST\n");
displayList();

    }
}
