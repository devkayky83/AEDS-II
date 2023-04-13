#include <iostream>
#include <windows.h>

using namespace std;

int trocas = 0;

void Bubble_Sort(vector <string> &Lista, int tamanho, int troca) // Ordem crescente
{
    string aux;
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 1; j < tamanho - i; j++)
        {
            if (Lista[j] < Lista[j - 1])
            {
                aux = Lista[j];
                Lista[j] = Lista[j - 1];
                Lista[j - 1] = aux;
                troca++;
            }
        }
    }
    trocas = troca;
}

void InsertionSort(vector <string> &Lista, int n, int troca = 0)
{
    string chave;
    int j;

    for (int i = 1; i < n; i++)
    {
        chave = Lista[i];
        j = i - 1;

        while (j >= 0 && Lista[j] > chave)
        {
            Lista[j + 1] = Lista[j];
            j--;
            troca++;
        }
        Lista[j + 1] = chave;
    }
    trocas = troca;
}

void SelectionSort(vector <string> &Lista, int n, int troca = 0)
{
    int min;
    string aux;

    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (Lista[j] < Lista[min])
            {
                min = j;
            }
        }
        aux = Lista[i];
        Lista[i] = Lista[min];
        Lista[min] = aux;
        troca++;
    }
    trocas = troca;
}

void QuickSort(vector <string> &Lista, int esquerda, int direita, int troca = 0)
{
    string aux; 
    int i = esquerda, j = direita;
    string pivo = Lista[(esquerda + direita) / 2];

    while (i <= j)
    {
        while (Lista[i] < pivo)
            i++;
        while (Lista[j] > pivo)
            j--;
        if (i <= j)
        {
            aux = Lista[i];
            Lista[i] = Lista[j];
            Lista[j] = aux;
            i++;
            j--;
            troca++;
        }
    };

    if (esquerda < j)
        QuickSort(Lista, esquerda, j);
    if (i < direita)
        QuickSort(Lista, i, direita);

    trocas = troca;
}

void Shellsort(vector <string> &v, int n, int troca = 0)
{
    int h, i, j;
    string x;

    for (h = 1; h < n; h = 3 * h + 1);

    while (h > 1)
    {
        h = h / 3;

        for (i = h; i < n; i++)
        {
            x = v[i];
            j = i;

            cout << " " << v[i];
            while (j >= h && v[j - h] > x)
            {
                v[j] = v[j - h];
                j = j - h;
                troca++;
            }
            v[j] = x;
        }
    }
    trocas = troca;
}

void Intercala(int Lista[], int inicio, int meio, int fim, int troca = 0)
{
    int *ListaAux = (int *)malloc(sizeof(int) * (fim + 1));
    int i, j;

    for (i = inicio; i <= meio; i++)
    {
        ListaAux[i] = Lista[i];
    }

    for (j = meio + 1; j <= fim; j++)
    {
        ListaAux[fim + meio + 1 - j] = Lista[j];
    }

    i = inicio;
    j = fim;

    for (int k = inicio; k <= fim; k++)
    {
        if (ListaAux[i] <= ListaAux[j])
        {
            Lista[k] = ListaAux[i];
            i++;
        }
        else
        {
            Lista[k] = ListaAux[j];
            j--;
        }
    }
    free(ListaAux);
}

void MergeSort(int Lista[], int inicio, int fim)
{
    int meio, troca;

    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;
        MergeSort(Lista, inicio, meio);
        MergeSort(Lista, meio + 1, fim);
        Intercala(Lista, inicio, meio, fim);
    }
}
