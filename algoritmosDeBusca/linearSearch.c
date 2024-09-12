// Percorre cada elemento do array um por um até encontrar o elemento desejado
// Pior caso: Percorrer todos os elementos

int linear_search(int *aarray, int size, int element)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (aarray[i] == element)
        {
            return i;
        }
    }
    return -1;
}
