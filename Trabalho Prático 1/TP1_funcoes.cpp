#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>
#include <time.h>
#include <vector>
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
    cout << "\n\t    2 - DicionarioInversamenteOrdenado-29855.txt";
    cout << "\n\t    3 - DicionarioInversamenteOrdenado-261791.txt";
    cout << "\n\t    4 - DicionarioOrdenado-29855.txt";
    cout << "\n\t    5 - DicionarioOrdenado-261791.txt";
    cout << "\n\t    6 - ListaOrdenada-1000.txt";
    cout << "\n\t    7 - ListaInversamenteOrdenada-1000.txt";
    cout << "\n\t    8 - ListaQuaseOrdenada-1000.txt";
    cout << "\n\t    9 - ListaAleatoria-1000.txt";
    cout << "\n\t   10 - ListaAleatoria-10000.txt";
    cout << "\n\t   11 - ListaInversamenteOrdenada-10000.txt";
    cout << "\n\t   12 - ListaOrdenada-10000.txt";
    cout << "\n\t   13 - ListaQuaseOrdenada-10000.txt";
    cout << "\n\t   14 - ListaAleatoria-100000.txt";
    cout << "\n\t   15 - ListaInversamenteOrdenada-100000.txt";
    cout << "\n\t   16 - ListaOrdenada-100000.txt";
    cout << "\n\t   17 - ListaQuaseOrdenada-100000.txt" << endl;
    cout << "\t ---------------------------------------------------\n";
}

void Escolha_Metodo(int escolha_metodo, vector <string> &vector, int tamanho)
{
    switch (escolha_metodo)
    {
        case 1:
            Bubble_Sort(vector, tamanho, trocas);
        break;

        case 2:
            InsertionSort(vector, tamanho, trocas);
        break;

        case 3:
            SelectionSort(vector, tamanho, trocas);
        break;
        
        case 4:
            Shellsort(vector, tamanho, trocas);
        break;

        case 5:
            QuickSort(vector, 0, tamanho - 1, trocas);
        break;
    }
}

void AbrirArquivo(vector <string> vector, int escolha_arquivo = 0, int escolha_metodo = 0)
{
    int tamanho = 0, i = 0;
    string linha;

    ifstream arquivoE;

    switch (escolha_arquivo)
    {
        case 1:
            arquivoE.open("DicionarioAleatorio-29855.txt");
            tamanho = 29855;
        break;

        case 2:
            arquivoE.open("DicionarioInversamenteOrdenado-29855.txt");
            tamanho = 29855;
        break;

        case 3:
            arquivoE.open("DicionarioInversamenteOrdenado-261791.txt");
            tamanho = 261791;
        break;

        case 4:
            arquivoE.open("DicionarioOrdenado-29855.txt");
            tamanho = 29855;
        break;

        case 5:
            arquivoE.open("DicionarioOrdenado-261791.txt");
            tamanho = 261791;
        break;

        case 6:
            arquivoE.open("ListaOrdenada-1000.txt");
            tamanho = 1000;
        break;

        case 7:
            arquivoE.open("ListaInversamenteOrdenada-1000.txt");
            tamanho = 1000;
        break;

        case 8:
            arquivoE.open("ListaQuaseOrdenada-1000.txt");
            tamanho = 1000;
        break;

        case 9:
            arquivoE.open("ListaAleatoria-1000.txt");
            tamanho = 1000;
        break;

        case 10:
            arquivoE.open("ListaAleatoria-10000.txt");
            tamanho = 10000;
        break;

        case 11:
            arquivoE.open("ListaInversamenteOrdenada-10000.txt");
            tamanho = 10000;
        break;

        case 12:
            arquivoE.open("ListaOrdenada-10000.txt");
            tamanho = 10000;
        break;

        case 13:
            arquivoE.open("ListaQuaseOrdenada-10000.txt");
            tamanho = 10000;
        break;

        case 14:
            arquivoE.open("ListaAleatoria-100000.txt");
            tamanho = 100000;
        break;

        case 15:
            arquivoE.open("ListaInversamenteOrdenada-100000.txt");
            tamanho = 100000;
        break;

        case 16:
            arquivoE.open("ListaOrdenada-100000.txt");
            tamanho = 100000;
        break;

        case 17:
            arquivoE.open("ListaQuaseOrdenada-100000.txt");
            tamanho = 100000;
        break;
    }

    if (arquivoE.is_open())
    {
        while (getline(arquivoE, linha))
        {
            vector.push_back(linha);
            i++;
        }        
    }
    else
    {
        cout << "\n Erro!" << endl;
    }

    system("cls");
    clock_t inicio = clock();
    Escolha_Metodo(escolha_metodo, vector, tamanho);
    inicio = clock() - inicio;

    system("cls");
    cout << "\n Vetor pós ordenação: \n" << endl;
    cout << "[";
    for (i = 0; i < tamanho; i++)
    {
        cout << " " << vector[i];
    }
    cout << " ]" << endl;

    cout << "\n - Número total de troca de posições: " << trocas << endl;

    cout << "\n - Tempo gasto: " << ((float)inicio) / CLOCKS_PER_SEC << " segundos/milissegundos" << endl; 

    system("pause");
}
