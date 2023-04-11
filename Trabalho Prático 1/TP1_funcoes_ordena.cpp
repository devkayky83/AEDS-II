#include <iostream>
#include <windows.h>

using namespace std;

void Bubble_Sort(string Lista[], int tamanho) // Ordem crescente
{
    string aux;
    int troca = 0;

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
    
    system("cls");
    cout << "\n Vetor pós ordenação: " << endl;
    cout << "[";
    for (int i = 0; i < tamanho; i++)
    {
        cout << " " << Lista[i];
    }
    cout << " ]" << endl;
    cout << "\n Número total de troca de posições: " << troca << endl;
}

void InsertionSort(string Lista[], int n)
{
    string chave;
    int j;

    for (int i = 1; i < n; i++)
    {
        chave = Lista[i];
        j = i-1;

        while (j >= 0 && Lista[j] > chave)
        {
            Lista[j+1] = Lista[j];
            j--;
        }
        Lista[j+1] = chave;
    }

    cout << "\n Vetor pós ordenação: "  << endl;
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << " " << Lista[i];
    }
    cout << " ]" << endl;
}

void SelectionSort(string Lista[], int n)
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
    }

    cout << "\n Vetor pós ordenação: " << endl;
    cout << "[";
    for (int k = 0; k < n; k++)
    {
        cout << " "<< Lista[k];
    }
    cout << " ]" << endl;
}

int QuickSort(int v[], int esquerda, int direita, int troca = 0)
{
    int aux, i = esquerda, j = direita;
    int pivo = v[(esquerda + direita) / 2] ;

    
    while (i <= j)
    {
        for (int i = 0; i < 9; i++)
        {
            cout << " " << v[i];
        }
        cout << endl;

        while (v[i] < pivo)
            i++;
        while (v[j] > pivo)
            j--;
        if (i <= j)
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
            troca++;
        }
        
    };

    for (int i = 0; i < 9; i++)
    {
        cout << " " << v[i];
    }
    cout << endl;

    if (esquerda < j)
        QuickSort(v, esquerda, j);
    if (i < direita)
        QuickSort(v, i, direita);

    for (int i = 0; i < 9; i++)
    {
        cout << " " << v[i];
    }
    cout << endl;
}

void shellsort(int v[], int n)
{
    int h, x, i, j, troca = 0;

    for (h = 1; h < n; h = 3 * h + 1);

    cout << "\n Sequência de troca: " << "[";
    while (h > 1)
    {
        h = h / 3;

        for (i = h; i < n; i++)
        {
            x = v[i];
            j = i;

            cout << " " << v[i];
            while(j >= h && v[j - h] > x)
            {
                v[j] = v[j - h];
                j = j - h;
                troca++;
            }
            v[j] = x;
        }
    }
    cout << " ]" << endl;
    
    cout << "\n Vetor pós ordenação: " << "[";
    for (int i = 0; i < 1000; i++)
    {
        cout << " " << v[i];
    }
    cout << " ]" << endl;
    cout << "\n Total de trocas: " << troca;
}

void Intercala(int Lista[], int inicio, int meio, int fim)
{
    int * ListaAux = (int *) malloc(sizeof(int) * (fim + 1));
    int i, j, troca;

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







