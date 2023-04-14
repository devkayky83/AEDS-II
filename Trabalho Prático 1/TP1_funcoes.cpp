#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>
#include <time.h>
#include <vector>
#include "TP1_funcoes_ordena.cpp"
#include "TP1.hpp"

int recebe_escolha_arquivo = 0;
 
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

void Escolha_Metodo(int escolha_metodo, vector <string> &vector_string, vector <int> &vector_int)
{
    switch (escolha_metodo)
    {
        case 1:
            Bubble_Sort(vector_string, vector_int, trocas, recebe_escolha_arquivo);
        break;

        case 2:
            InsertionSort(vector_string, vector_int, trocas, recebe_escolha_arquivo);
        break;

        case 3:
            SelectionSort(vector_string, vector_int, trocas, recebe_escolha_arquivo);
        break;
        
        case 4:
            Shellsort(vector_string, vector_int, trocas, recebe_escolha_arquivo);
        break;

        case 5:
            QuickSort(vector_string, vector_int, 0, trocas, recebe_escolha_arquivo);
        break;
    }
}

void AbrirArquivo(vector <string> vector_string, vector <int> vector_int, int escolha_arquivo = 0, int escolha_metodo = 0)
{
    int i = 0;
    string linha;

    ifstream arquivoE;

    switch (escolha_arquivo)
    {
        case 1:
            arquivoE.open("DicionarioAleatorio-29855.txt");
        break;

        case 2:
            arquivoE.open("DicionarioInversamenteOrdenado-29855.txt");
        break;

        case 3:
            arquivoE.open("DicionarioInversamenteOrdenado-261791.txt");
        break;

        case 4:
            arquivoE.open("DicionarioOrdenado-29855.txt");
        break;

        case 5:
            arquivoE.open("DicionarioOrdenado-261791.txt");
        break;

        case 6:
            arquivoE.open("ListaOrdenada-1000.txt");
        break;

        case 7:
            arquivoE.open("ListaInversamenteOrdenada-1000.txt");
        break;

        case 8:
            arquivoE.open("ListaQuaseOrdenada-1000.txt");
        break;

        case 9:
            arquivoE.open("ListaAleatoria-1000.txt");
        break;

        case 10:
            arquivoE.open("ListaAleatoria-10000.txt");
        break;

        case 11:
            arquivoE.open("ListaInversamenteOrdenada-10000.txt");
        break;

        case 12:
            arquivoE.open("ListaOrdenada-10000.txt");
        break;

        case 13:
            arquivoE.open("ListaQuaseOrdenada-10000.txt");
        break;

        case 14:
            arquivoE.open("ListaAleatoria-100000.txt");
        break;

        case 15:
            arquivoE.open("ListaInversamenteOrdenada-100000.txt");
        break;

        case 16:
            arquivoE.open("ListaOrdenada-100000.txt");
        break;

        case 17:
            arquivoE.open("ListaQuaseOrdenada-100000.txt");
        break;
    }

    if (arquivoE.is_open())
    {
        if (escolha_arquivo >= 1 && escolha_arquivo <= 5)
        {
            while (getline(arquivoE, linha))
            {
                vector_string.push_back(linha);
                i++;
            }
        }

        else if (escolha_arquivo >= 6 && escolha_arquivo <= 17)
        {
            while (getline(arquivoE, linha))
            {
                vector_int.push_back(stoi(linha));
                i++;
            }
        }
        recebe_escolha_arquivo = escolha_arquivo;      
    }
    else
    {
        cout << "\n Erro!" << endl;
    }

    system("cls");
    clock_t inicio = clock();
    Escolha_Metodo(escolha_metodo, vector_string, vector_int);
    inicio = clock() - inicio;

    system("cls");
    cout << "\n Vetor pós ordenação: \n" << endl;
    cout << "[";

    if (escolha_arquivo >= 1 && escolha_arquivo <= 5)
    {
        for (i = 0; i < vector_string.size(); i++)
        {
            cout << " " << vector_string[i];
        }
    }
    else if (escolha_arquivo >= 6 && escolha_arquivo <= 17)
    {
        for (i = 0; i < vector_int.size(); i++)
        {
            cout << " " << vector_int[i];
        }
    }
    cout << " ]" << endl;

    cout << "\n - Número total de troca de posições: " << trocas << endl;

    cout << "\n - Tempo gasto: " << ((float)inicio) / CLOCKS_PER_SEC << " segundos/milissegundos" << endl; 

    system("pause");
}
