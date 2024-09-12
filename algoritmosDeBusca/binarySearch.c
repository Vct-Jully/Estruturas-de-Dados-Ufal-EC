#include <stdio.h>

int binarySearch(int *v, int size, int element)
{
    int begin = 0;
    int end = size - 1;
    int middle;

    while (begin <= end)
    {
        middle = (end + begin) / 2;
        if (v[middle] < element)
        {
            begin = middle + 1;
        }
        if (v[middle] > element)
        {
            end = middle - 1;
        }
        if (v[middle] == element)
        {
            return middle;
        }
    }
    return -1;
}

int main()
{

    int aarray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int saida = binarySearch(aarray, 10, 3);

    printf("%d", saida);
}