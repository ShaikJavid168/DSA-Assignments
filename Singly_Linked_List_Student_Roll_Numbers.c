#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int roll;
    struct Node *next;
};

struct Node *head = NULL;

void create()
{
    int n, roll;
    struct Node *newNode, *temp;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter roll number: ");
        scanf("%d", &roll);

        newNode = (struct Node *)malloc(sizeof(struct Node));

        newNode->roll = roll;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

void insertBeginning()
{
    int roll;

    struct Node *newNode;

    printf("Enter roll number to insert: ");
    scanf("%d", &roll);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->roll = roll;
    newNode->next = head;
    head = newNode;

    printf("Node inserted at beginning\n");
}

void search()
{
    int roll, position = 1;
    struct Node *temp = head;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            printf("Roll number found at position %d\n", position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Roll number not available\n");
}

void deleteRoll()
{
    int roll;

    struct Node *temp = head;
    struct Node *prev = NULL;

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    while (temp != NULL && temp->roll != roll)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Roll number not available\n");
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);

    printf("Roll number deleted successfully\n");
}

void display()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Student roll numbers:\n");

    while (temp != NULL)
    {
        printf("%d -> ", temp->roll);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    create();

    while (1)
    {
        printf("\n--- STUDENT LINKED LIST ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertBeginning();
                display();
                break;

            case 2:
                search();
                break;

            case 3:
                deleteRoll();
                display();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}