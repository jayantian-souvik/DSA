#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NULL 0

struct node
{
    int number;
    struct node *link;
};

struct node *start = NULL, *p, *q, *prev;

void create();
void display();
void insert1();
void insert_begin();
void insert_end();
void ins_pos();
void delete1();
void delete_begin();
void delete_end();
void del_item();

int main()
{
    int ch, number, pos;

    while (1)
    {
        printf("\n1. Create a linked list");
        printf("\n2. Insert");
        printf("\n3. Delete");
        printf("\n4. Display linked list");
        printf("\n5. Exit");
        printf("\nEnter your choice:");

        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            insert1();
            break;
        case 3:
            delete1();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }

    return 0;
}

void create()
{
    start = NULL;
    q = NULL;
    p = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the number: ");
    scanf("%d", &p->number);
    p->link = NULL;
    if (start == NULL)
    {
        start = p;
        q = p;
    }
    else
    {
        q->link = p;
        q = p;
    }
}

void insert1()
{
    int ch;
    do
    {
        printf("\n1. Insert at the beginning");
        printf("\n2. Insert at the End");
        printf("\n3. Insert in a particular position");
        printf("\n4. Exit!!");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_begin();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            ins_pos();
            break;
        }
    } while (ch != 4);
}

void delete1()
{
    int ch;
    do
    {
        printf("\n1. Delete at the beginning");
        printf("\n2. Delete at the End");
        printf("\n3. Delete in a particular position");
        printf("\n4. Exit!!");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            delete_begin();
            break;
        case 2:
            delete_end();
            break;
        case 3:
            del_item();
            break;
        }
    } while (ch != 4);
}

void display()
{
    printf("\nThe nodes in the list are\n\nSTART->");
    p = start;
    while (p != NULL)
    {
        printf("%d ->", p->number);
        p = p->link;
    }
    printf("NULL\n");
}

void insert_begin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\nEnter the data value for the node: ");
    scanf("%d", &temp->number);
    temp->link = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->link = start;
        start = temp;
    }
}

void insert_end()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\nEnter the data value for the node: ");
    scanf("%d", &temp->number);
    temp->link = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}

void ins_pos()
{
    int i, pos;
    printf("\nEnter the position at which you want to insert the new node: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insert_begin();
    }
    else
    {
        q = start;
        for (i = 1; i < pos - 1; i++)
        {
            q = q->link;
            if (q == NULL)
            {
                printf("\nPosition not found");
                return;
            }
        }
        p = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter number: ");
        scanf("%d", &p->number);
        p->link = q->link;
        q->link = p;
    }
}

void delete_begin()
{
    struct node *ptr;
    ptr = start;
    start = start->link;
    printf("\nThe deleted element is: %d", ptr->number);
    free(ptr);
}

void delete_end()
{
    struct node *temp, *ptr;
    if (start == NULL)
    {
        printf("\nList is Empty");
        exit(0);
    }
    else if (start->link == NULL)
    {
        ptr = start;
        start = NULL;
        printf("\nThe deleted element is: %d", ptr->number);
        free(ptr);
    }
    else
    {
        ptr = start;
        while (ptr->link != NULL)
        {
            temp = ptr;
            ptr = ptr->link;
        }
        temp->link = NULL;
        printf("\nThe deleted element is: %d", ptr->number);
        free(ptr);
    }
}

void del_item()
{
    int i, pos;
    struct node *temp, *ptr;
    if (start == NULL)
    {
        printf("\nThe List is Empty");
        exit(0);
    }
    else
    {
        printf("\nEnter the position of the node to be deleted: ");
        scanf("%d", &pos);
        if (pos == 1)
        {
            ptr = start;
            start = start->link;
            printf("\nThe deleted element is: %d", ptr->number);
            free(ptr);
        }
        else
        {
            ptr = start;
            for (i = 1; i < pos; i++)
            {
                temp = ptr;
                ptr = ptr->link;
                if (ptr == NULL)
                {
                    printf("\nPosition not Found");
                    return;
                }
            }
            temp->link = ptr->link;
            printf("\nThe deleted element is: %d", ptr->number);
            free(ptr);
        }
    }
}
