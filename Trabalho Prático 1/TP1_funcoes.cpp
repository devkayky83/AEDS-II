#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>
#include <time.h>
#include "TP1_funcoes_ordena.cpp"
#include "TP1.hpp"
 
using namespace std;
 
void MENU()
{
    cout << "\n\t ------------------------\n";
    cout << "\t - MÉTODOS DE ORDENAÇÃO - \n";
    cout << "\t ------------------------\n";
    cout << "\n\t    1 - Bubble Sort";
    cout << "\n\t    2 - Insertion Sort";
    cout << "\n\t    3 - Selection Sort";
    cout << "\n\t    4 - Shell Sort";
    cout << "\n\t    5 - Quick Sort";
    cout << "\n\t    6 - Merge Sort";
    cout << "\n\t    0 - Sair do menu\n";
    cout << "\t ------------------------\n";
}

void MENU_Instancias()
{
    system("cls");
    cout << "\n\t ---------------------------------------------------\n";
    cout << "\t                    - ARQUIVOS - \n";
    cout << "\t ---------------------------------------------------\n";
    cout << "\n\t    1 - DicionarioAleatorio-29855.txt";
    cout << "\n\t    2 - ListaAleatoria-1000.txt";
    cout << "\n\t    3 - DicionarioInversamenteOrdenado-29855.txt";
    cout << "\n\t    4 - ListaOrdenada-1000.txt";
    cout << "\n\t    5 - ListaInversamenteOrdenada-1000.txt";
    cout << "\n\t    6 - ListaQuaseOrdenada-1000.txt";
    cout << "\n\t    7 - ListaAleatoria-10000.txt";
    cout << "\n\t    8 - ListaInversamenteOrdenada-10000.txt";
    cout << "\n\t    9 - ListaOrdenada-10000.txt";
    cout << "\n\t   10 - ListaQuaseOrdenada-10000.txt";
    cout << "\n\t   11 - ListaAleatoria-100000.txt" << endl;
    cout << "\t ---------------------------------------------------\n";
}

void AbrirArquivo_Bubblesort(string vector[], int escolha_bubblesort)
{
    int tamanho, i = 0;
    string linha;

    ifstream arquivoE;

    switch (escolha_bubblesort)
    {
        case 1:
            arquivoE.open("DicionarioAleatorio-29855.txt");
            tamanho = 29855;
        break;

        case 2:
            arquivoE.open("ListaAleatoria-1000.txt");
            tamanho = 1000;
        break;

        case 3:
            arquivoE.open("DicionarioInversamenteOrdenado-29855.txt");
            tamanho = 29855;
        break;

        case 4:
            arquivoE.open("ListaOrdenada-1000.txt");
            tamanho = 1000;
        break;

        case 5:
            arquivoE.open("ListaInversamenteOrdenada-1000.txt");
            tamanho = 1000;
        break;

        case 6:
            arquivoE.open("ListaQuaseOrdenada-1000.txt");
            tamanho = 1000;
        break;

        case 7:
            arquivoE.open("ListaAleatoria-10000.txt");
            tamanho = 10000;
        break;

        case 8:
            arquivoE.open("ListaInversamenteOrdenada-10000.txt");
            tamanho = 10000;
        break;

        case 9:
            arquivoE.open("ListaOrdenada-10000.txt");
            tamanho = 10000;
        break;

        case 10:
            arquivoE.open("ListaQuaseOrdenada-10000.txt");
            tamanho = 10000;
        break;

        case 11:
            arquivoE.open("ListaAleatoria-100000.txt");
            tamanho = 100000;
        break;
    }

    if (arquivoE.is_open())
    {
        while (getline(arquivoE, linha))
        {
            vector[i] = linha;
            i++;
        }        
    }
    else
    {
        cout << "\n Erro!" << endl;
    }

    system("cls");
    clock_t inicio = clock();
    Bubble_Sort(vector, tamanho);
    inicio = clock() - inicio;

    cout << "\n Tempo gasto: " << ((float)inicio) / CLOCKS_PER_SEC << " segundos" << endl; 

    system("pause");
}

void AbrirArquivo_Insertionsort(string vector[], int escolha_insertionsort)
{
    int tamanho, i = 0;
    string linha;

    ifstream arquivoE;

    switch (escolha_insertionsort)
    {
        case 1:
            arquivoE.open("DicionarioAleatorio-29855.txt");
            tamanho = 29855;
        break;

        case 2:
            arquivoE.open("ListaAleatoria-1000.txt");
            tamanho = 1000;
        break;

        case 3:
            arquivoE.open("DicionarioInversamenteOrdenado-29855.txt");
            tamanho = 29855;
        break;
    }

    if (arquivoE.is_open())
    {
        while (getline(arquivoE, linha))
        {
            vector[i] = linha;
            i++;
        }
    }
    else
    {
        cout << "\n Erro!" << endl;
    }

    system("cls");

    clock_t inicio = clock();
    InsertionSort(vector, tamanho);
    inicio = clock() - inicio;

    cout << "\n Tempo total gasto: " << ((float)inicio) / CLOCKS_PER_SEC << " segundos" << endl;

    system("pause");
}

void AbrirArquivo_Selectionsort(string vector[], int escolha_selectionsort)
{
    int tamanho, i = 0;
    string linha;

    ifstream arquivoE;

    switch (escolha_selectionsort)
    {
        case 1:
            arquivoE.open("DicionarioAleatorio-29855.txt");
            tamanho = 29855;
        break;

        case 2:
            arquivoE.open("ListaAleatoria-1000.txt");
            tamanho = 1000;
        break;

        case 3:
            arquivoE.open("DicionarioInversamenteOrdenado-29855.txt");
            tamanho = 29855;
        break;
    }

    if (arquivoE.is_open())
    {
        while (getline(arquivoE, linha))
        {
            vector[i] = linha;
            i++;
        }
    }
    else
    {
        cout << "\n Erro!" << endl;
    }

    system("cls");

    clock_t inicio = clock();
    SelectionSort(vector, tamanho);
    inicio = clock() - inicio;

    cout << "\n Tempo total gasto: " << ((float)inicio) / CLOCKS_PER_SEC << " segundos" << endl;

    system("pause");
}
