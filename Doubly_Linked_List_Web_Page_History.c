#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char page[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertPage()
{
    char page[50];
    struct Node *newNode;

    printf("Enter page name: ");
    scanf("%s", page);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->page, page);

    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    printf("Page inserted successfully\n");
}

void forwardDisplay()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("No pages available\n");
        return;
    }

    printf("\nPages from First to Last:\n");

    while (temp != NULL)
    {
        printf("%s", temp->page);

        if (temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }

    printf("\n");
}

void backwardDisplay()
{
    struct Node *temp = tail;

    if (tail == NULL)
    {
        printf("No pages available\n");
        return;
    }

    printf("\nPages from Last to First:\n");

    while (temp != NULL)
    {
        printf("%s", temp->page);

        if (temp->prev != NULL)
            printf(" <-> ");

        temp = temp->prev;
    }

    printf("\n");
}

void deletePage()
{
    char page[50];
    struct Node *temp = head;

    printf("Enter page to delete: ");
    scanf("%s", page);

    while (temp != NULL && strcmp(temp->page, page) != 0)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Page not found\n");
        return;
    }

    /* Deleting the first node */
    if (temp == head)
    {
        head = temp->next;

        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
    }

    /* Deleting the last node */
    if (temp == tail)
    {
        tail = temp->prev;

        if (tail != NULL)
            tail->next = NULL;
    }
    else
    {
        temp->next->prev = temp->prev;
    }

    free(temp);

    if (head == NULL)
        tail = NULL;

    printf("Page deleted successfully\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- WEB PAGE HISTORY ---\n");
        printf("1. Insert Page\n");
        printf("2. Display First to Last\n");
        printf("3. Display Last to First\n");
        printf("4. Delete Page\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertPage();
                break;

            case 2:
                forwardDisplay();
                break;

            case 3:
                backwardDisplay();
                break;

            case 4:
                deletePage();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}