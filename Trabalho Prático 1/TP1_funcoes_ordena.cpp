#include <iostream>
#include <windows.h>

using namespace std;

int trocas = 0;
int comparacoes = 0;

// Merge Sort String em fase de manutenção.

void Bubble_Sort(vector <string> &Lista_String, vector <int> &Lista_Int, int troca = 0, int compara = 0, int recebe_escolha_arquivo = 0) // Ordem crescente
{
    if (recebe_escolha_arquivo >= 1 && recebe_escolha_arquivo <= 5)
    {
        string aux;

        for (int i = 0; i < Lista_String.size() - 1; i++)
        {
            for (int j = 1; j < Lista_String.size() - i; j++)
            {
                compara++;
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
        comparacoes = compara;
    }
    else if(recebe_escolha_arquivo >= 6 && recebe_escolha_arquivo <= 22)
    {
        int aux;

        for (int i = 0; i < Lista_Int.size() - 1; i++)
        {
            for (int j = 1; j < Lista_Int.size() - i; j++)
            {
                compara++;
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
        comparacoes = compara;
    }
}

void InsertionSort(vector <string> &Lista_String, vector <int> &Lista_Int, int troca = 0, int compara = 0, int recebe_escolha_arquivo = 0)
{
    if (recebe_escolha_arquivo >= 1 && recebe_escolha_arquivo <= 5)
    {
        string chave;
        int j;

        for (int i = 1; i < Lista_String.size(); i++)
        {
            chave = Lista_String[i];
            j = i - 1;
            compara++;

            while (j >= 0 && Lista_String[j] > chave)
            {
                Lista_String[j + 1] = Lista_String[j];
                j--;
                troca++;
            }
            Lista_String[j + 1] = chave;
        }
        trocas = troca;
        comparacoes = compara;
    }
    else if (recebe_escolha_arquivo >= 6 && recebe_escolha_arquivo <= 22)
    {
        int chave, j;

        for (int i = 1; i < Lista_Int.size(); i++)
        {
            chave = Lista_Int[i];
            j = i - 1;
            compara++;

            while (j >= 0 && Lista_Int[j] > chave)
            {
                Lista_Int[j + 1] = Lista_Int[j];
                j--;
                troca++;
            }
            Lista_Int[j + 1] = chave;
        }
        trocas = troca;
        comparacoes = compara;
    }
}

void SelectionSort(vector <string> &Lista_String, vector <int> &Lista_Int, int troca = 0, int compara = 0, int recebe_escolha_arquivo = 0)
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
                compara++;
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
        comparacoes = compara;
    }
    else if (recebe_escolha_arquivo >= 6 && recebe_escolha_arquivo <= 22)
    {
        int min, aux;

        for (int i = 0; i < Lista_Int.size() - 1; i++)
        {
            min = i;
            for (int j = i + 1; j < Lista_Int.size(); j++)
            {
                compara++;
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
        comparacoes = compara;
    }
}

void ShellSort(vector <string> &Lista_String, vector <int> &Lista_Int, int troca = 0, int compara = 0, int recebe_escolha_arquivo = 0)
{
    if (recebe_escolha_arquivo >= 1 && recebe_escolha_arquivo <= 5)
    {
        int h, i, j;
        string x;

        for (h = 1; h < Lista_String.size(); h = 3 * h + 1);

        while (h > 1)
        {
            compara += 2;
            h = h / 3;

            for (i = h; i < Lista_String.size(); i++)
            {
                compara += 2;
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
        comparacoes = compara;
    }
    else if (recebe_escolha_arquivo >= 6 && recebe_escolha_arquivo <= 17)
    {
        int h, i, j, x;

        for (h = 1; h < Lista_Int.size(); h = 3 * h + 1);

        while (h > 1)
        {
            compara++;
            h = h / 3;

            for (i = h; i < Lista_Int.size(); i++)
            {
                compara++;
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
        comparacoes = compara;
    }
}

void QuickSort_String(vector <string> &Lista_String, int esquerda, int direita, int troca = 0, int compara = 0)
{
    string aux; 
    int i = esquerda, j = direita;
    string pivo = Lista_String[(esquerda + direita) / 2] ;

    while (i <= j)
    {
        compara++;
        while (Lista_String[i] < pivo)
            i++, compara++;
        while (Lista_String[j] > pivo)
            j--, compara++;
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
        QuickSort_String(Lista_String, esquerda, j);
    if (i < direita)
        QuickSort_String(Lista_String, i, direita);

        trocas = troca;
        comparacoes = compara;
}

void QuickSort_Int(vector <int> &Lista_Int, int esquerda, int direita, int troca = 0, int compara = 0)
{
    int aux, i = esquerda, j = direita;
    int pivo = Lista_Int[(esquerda + direita) / 2] ;

    
    while (i <= j)
    {
        compara++;
        while (Lista_Int[i] < pivo)
            i++, compara++;
        while (Lista_Int[j] > pivo)
            j--, compara++;
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
        QuickSort_Int(Lista_Int, esquerda, j);
    if (i < direita)
        QuickSort_Int(Lista_Int, i, direita);

        trocas = troca;
        comparacoes = compara; 
}

void Intercala_String(vector <string> &Lista_String, vector <string> &ListaAux, int inicio, int meio, int fim, int troca = 0)
{
    // ListaAux = (string *)malloc(sizeof(int) * (fim + 1));
    int i, j;

    for (i = inicio; i <= fim; i++)
    {
        ListaAux[i] = Lista_String[i];
    }

    i = inicio;
    j = meio + 1;

    for (int k = inicio; k <= fim; k++)
    {
        if (i > meio)
        {
            Lista_String[k] = ListaAux[j++];
        }
        else 
        {
            if (j > fim)
            {
                Lista_String[k] = ListaAux[i++];
            }
            else if(ListaAux[i] < ListaAux[j])
            {
                Lista_String[k] = ListaAux[i++];
            }
            else
            {
                Lista_String[k] = ListaAux[j++];
            }
        }
        // if (ListaAux[i] <= ListaAux[j])
        // {
        //     Lista_String[k] = ListaAux[i];
        //     i++;
        //     troca++;
        // }
        // else
        // {
        //     Lista_String[k] = ListaAux[j];
        //     j--;
        //     troca++;
        // }
    }
    // free(ListaAux);
    trocas = troca;
}

void MergeSort_String(vector <string> &Lista_String, vector <string> &ListaAux, int inicio, int fim)
{
    int meio;

    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;
        MergeSort_String(Lista_String, ListaAux, inicio, meio);
        MergeSort_String(Lista_String, ListaAux, meio + 1, fim);
        Intercala_String(Lista_String, ListaAux, inicio, meio, fim);
    }
}

void Intercala_Int(vector <int> &Lista_Int, int inicio, int meio, int fim, int troca = 0, int compara = 0)
{
    int *ListaAux = (int *)malloc(sizeof(int) * (fim + 1));
    int i, j;

    for (i = inicio; i <= meio; i++)
    {
        ListaAux[i] = Lista_Int[i];
        compara++;
    }

    for (j = meio + 1; j <= fim; j++)
    {
        ListaAux[fim + meio + 1 - j] = Lista_Int[j];
        compara++;
    }

    i = inicio;
    j = fim;

    for (int k = inicio; k <= fim; k++)
    {
        compara++;
        if (ListaAux[i] <= ListaAux[j])
        {
            Lista_Int[k] = ListaAux[i];
            i++;
            troca++;
        }
        else
        {
            Lista_Int[k] = ListaAux[j];
            j--;
            troca++;
        }
    }
    free(ListaAux);
    trocas = troca;
    comparacoes = compara;
}

void MergeSort_Int(vector <int> &Lista_Int, int inicio, int fim)
{
    int meio, compara;

    if (inicio < fim)
    {
        compara++;
        meio = (inicio + fim) / 2;
        MergeSort_Int(Lista_Int, inicio, meio);
        MergeSort_Int(Lista_Int, meio + 1, fim);
        Intercala_Int(Lista_Int, inicio, meio, fim);
    }
}
