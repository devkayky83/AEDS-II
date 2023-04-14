#include <iostream>
#include <windows.h>

using namespace std;

int trocas = 0;

// QuickSort em fase de reparo, problemas com a recursividade.

void Bubble_Sort(vector <string> &Lista_String, vector <int> &Lista_Int, int troca = 0, int recebe_escolha_arquivo = 0) // Ordem crescente
{
    if (recebe_escolha_arquivo >= 1 && recebe_escolha_arquivo <= 5)
    {
        string aux;
        for (int i = 0; i < Lista_String.size() - 1; i++)
        {
            for (int j = 1; j < Lista_String.size() - i; j++)
            {
                if (Lista_String[j] < Lista_String[j - 1])
                {
                    aux = Lista_String[j];
                    Lista_String[j] = Lista_String[j - 1];
                    Lista_String[j - 1] = aux;
                    troca++;
                }
            }
        }
        trocas = troca;
    }
    else if(recebe_escolha_arquivo >= 6 && recebe_escolha_arquivo <= 17)
    {
        int aux;
        for (int i = 0; i < Lista_Int.size() - 1; i++)
        {
            for (int j = 1; j < Lista_Int.size() - i; j++)
            {
                if (Lista_Int[j] < Lista_Int[j - 1])
                {
                    aux = Lista_Int[j];
                    Lista_Int[j] = Lista_Int[j - 1];
                    Lista_Int[j - 1] = aux;
                    troca++;
                }
            }
        }
        trocas = troca;
    }
}

void InsertionSort(vector <string> &Lista_String, vector <int> &Lista_Int, int troca = 0, int recebe_escolha_arquivo = 0)
{
    if (recebe_escolha_arquivo >= 1 && recebe_escolha_arquivo <= 5)
    {
        string chave;
        int j;

        for (int i = 1; i < Lista_String.size(); i++)
        {
            chave = Lista_String[i];
            j = i - 1;

            while (j >= 0 && Lista_String[j] > chave)
            {
                Lista_String[j + 1] = Lista_String[j];
                j--;
                troca++;
            }
            Lista_String[j + 1] = chave;
        }
        trocas = troca;
    }
    else if (recebe_escolha_arquivo >= 6 && recebe_escolha_arquivo <= 17)
    {
        int chave, j;

        for (int i = 1; i < Lista_Int.size(); i++)
        {
            chave = Lista_Int[i];
            j = i - 1;

            while (j >= 0 && Lista_Int[j] > chave)
            {
                Lista_Int[j + 1] = Lista_Int[j];
                j--;
                troca++;
            }
            Lista_Int[j + 1] = chave;
        }
        trocas = troca;
    }
}

void SelectionSort(vector <string> &Lista_String, vector <int> &Lista_Int, int troca = 0, int recebe_escolha_arquivo = 0)
{
    if (recebe_escolha_arquivo >= 1 && recebe_escolha_arquivo <= 5)
    {
        int min;
        string aux;

        for (int i = 0; i < Lista_String.size() - 1; i++)
        {
            min = i;
            for (int j = i + 1; j < Lista_String.size(); j++)
            {
                if (Lista_String[j] < Lista_String[min])
                {
                    min = j;
                }
            }
            aux = Lista_String[i];
            Lista_String[i] = Lista_String[min];
            Lista_String[min] = aux;
            troca++;
        }
        trocas = troca;
    }
    else if (recebe_escolha_arquivo >= 6 && recebe_escolha_arquivo <= 17)
    {
        int min, aux;

        for (int i = 0; i < Lista_Int.size() - 1; i++)
        {
            min = i;
            for (int j = i + 1; j < Lista_Int.size(); j++)
            {
                if (Lista_Int[j] < Lista_Int[min])
                {
                    min = j;
                }
            }
            aux = Lista_Int[i];
            Lista_Int[i] = Lista_Int[min];
            Lista_Int[min] = aux;
            troca++;
        }
        trocas = troca;
    }
}

void QuickSort(vector <string> &Lista_String, vector <int> &Lista_Int, int esquerda, int troca = 0, int recebe_escolha_arquivo = 0)
{
    if (recebe_escolha_arquivo >= 1 && recebe_escolha_arquivo <= 5)
    {
        string aux; 
        int i = esquerda, j = Lista_String.size();
        string pivo = Lista_String[(esquerda + Lista_String.size()) / 2];

        while (i <= j)
        {
            while (Lista_String[i] < pivo)
                i++;
            while (Lista_String[j] > pivo)
                j--;
            if (i <= j)
            {
                aux = Lista_String[i];
                Lista_String[i] = Lista_String[j];
                Lista_String[j] = aux;
                i++;
                j--;
                troca++;
            }
        };

        if (esquerda < j)
            QuickSort(Lista_String, Lista_Int, esquerda, j);
        if (i < Lista_String.size())
            QuickSort(Lista_String, Lista_Int, i, Lista_String.size());

        trocas = troca;
    }
    else if (recebe_escolha_arquivo >= 6 && recebe_escolha_arquivo <= 17)
    {
        int i = esquerda, j = Lista_Int.size(), aux;
        int pivo = Lista_Int[(esquerda + Lista_Int.size()) / 2];

        while (i <= j)
        {
            while (Lista_Int[i] < pivo)
                i++;
            while (Lista_Int[j] > pivo)
                j--;
            if (i <= j)
            {
                aux = Lista_Int[i];
                Lista_Int[i] = Lista_Int[j];
                Lista_Int[j] = aux;
                i++;
                j--;
                troca++;
            }
        };

        if (esquerda < j)
            QuickSort(Lista_String, Lista_Int, esquerda, j);
        if (i < Lista_Int.size())
            QuickSort(Lista_String, Lista_Int, i, Lista_Int.size());

        trocas = troca;
    }
}

void Shellsort(vector <string> &Lista_String, vector <int> &Lista_Int, int troca = 0, int recebe_escolha_arquivo = 0)
{
    if (recebe_escolha_arquivo >= 1 && recebe_escolha_arquivo <= 5)
    {
        int h, i, j;
        string x;

        for (h = 1; h < Lista_String.size(); h = 3 * h + 1);

        while (h > 1)
        {
            h = h / 3;

            for (i = h; i < Lista_String.size(); i++)
            {
                x = Lista_String[i];
                j = i;

                while (j >= h && Lista_String[j - h] > x)
                {
                    Lista_String[j] = Lista_String[j - h];
                    j = j - h;
                    troca++;
                }
                Lista_String[j] = x;
            }
        }
        trocas = troca;
    }
    else if (recebe_escolha_arquivo >= 6 && recebe_escolha_arquivo <= 17)
    {
        int h, i, j, x;

        for (h = 1; h < Lista_Int.size(); h = 3 * h + 1);

        while (h > 1)
        {
            h = h / 3;

            for (i = h; i < Lista_Int.size(); i++)
            {
                x = Lista_Int[i];
                j = i;

                while (j >= h && Lista_Int[j - h] > x)
                {
                    Lista_Int[j] = Lista_Int[j - h];
                    j = j - h;
                    troca++;
                }
                Lista_Int[j] = x;
            }
        }
        trocas = troca;
    }
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
