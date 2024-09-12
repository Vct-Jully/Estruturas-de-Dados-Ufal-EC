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

node *add(node *head, int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = head;
    return newNode;
}

int verify(node *list, int value2)
{
    node *atual = list;
    while (atual != NULL)
    {
        if (atual->value == value2)
        {
            return value2;
        }
        atual = atual->next;
    }
    return -1;
}

void bubbleSort(int values[], int tam)
{
    int i, j, temp;
    for (i = 0; i < tam - 1; i++)
    {
        for (j = 0; j < tam - i - 1; j++)
        {
            if (values[j] > values[j + 1])
            {
                temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
}

void printArray(int values[], int n)
{
    for (int i = 0; i < n; i++)
    {
        while ((values[i] == values[i + 1]) && i + 1 <= n)
        {
            i++;
        }
        printf("%d ", values[i]);
    }
    printf("\n");
}

void subconjunto(node *list1, node *list2)
{
    int values[20];
    int i = 0;
    node *atual = list2;

    while (atual != NULL)
    {
        int valueint = verify(list1, atual->value);
        if (valueint != -1)
        {
            values[i] = valueint;
            i++;
        }
        atual = atual->next;
    }

    if (!i)
    {
        printf("VAZIO");
    }
    else
    {
        bubbleSort(values, i);
        printArray(values, i);
    }
}

int main()
{
    int n = 20;
    int value;
    node *list1 = createList();
    node *list2 = createList();

    // scan and add list1

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        list1 = add(list1, value);
    }

    // scan and add list2

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        list2 = add(list2, value);
    }

    // verify subset

    subconjunto(list1, list2);

    return 0;
}
