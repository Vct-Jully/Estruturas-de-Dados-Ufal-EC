#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node node;

node *createList()
{
    return NULL;
}

int empty(node *head)
{
    return (head == NULL);
}

node *add(node *head, int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = head;
    return newNode;
}

void printList(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }

    printf("\n");
}

int verify(node *list, int value2)
{
    node *atual = list;
    while (atual != NULL)
    {
        if (atual->value == value2)
        {
            return 1;
        }
        atual = atual->next;
    }
    return 0;
}

int subconjunto(node *list1, node *list2)
{

    node *atual = list2;
    while (atual != NULL)
    {
        if ((verify(list1, atual->value)) == 0)
        {
            return 0;
        }
        atual = atual->next;
    }
    return 1;
}

int main()
{

    int n, value;
    node *list1 = createList();
    node *list2 = createList();

    scanf("%d/n", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        list1 = add(list1, value);
    }

    printList(list1);

    scanf("%d/n", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        list2 = add(list2, value);
    }

    printList(list2);

    int r = subconjunto(list1, list2);

    if (r == 0)
    {
        printf("0");
    }
    else
    {
        printf("1");
    }

    return 0;
}
