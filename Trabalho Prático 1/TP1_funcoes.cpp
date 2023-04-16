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
bool verificacao;
 
using namespace std;
 
void MENU()
{
    system("cls");
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
    cout << "\t ---------------------------------------------------";
    cout << "\n\t    1 - DicionarioAleatorio-29855.txt";
    cout << "\n\t    2 - DicionarioAleatorio-261791.txt";
    cout << "\n\t    3 - DicionarioInversamenteOrdenado-29855.txt";
    cout << "\n\t    4 - DicionarioInversamenteOrdenado-261791.txt";
    cout << "\n\t    5 - DicionarioOrdenado-29855.txt";
    cout << "\n\t    6 - DicionarioOrdenado-261791.txt";
    cout << "\n\t ---------------------------------------------------";
    cout << "\n\t    7 - ListaAleatoria-1000.txt";
    cout << "\n\t    8 - ListaAleatoria-10000.txt";
    cout << "\n\t    9 - ListaAleatoria-100000.txt";
    cout << "\n\t   10 - ListaAleatoria-1000000.txt";
    cout << "\n\t ---------------------------------------------------";
    cout << "\n\t   11 - ListaInversamenteOrdenada-1000.txt";
    cout << "\n\t   12 - ListaInversamenteOrdenada-10000.txt";
    cout << "\n\t   13 - ListaInversamenteOrdenada-100000.txt";
    cout << "\n\t   14 - ListaInversamenteOrdenada-1000000.txt";
    cout << "\n\t ---------------------------------------------------";
    cout << "\n\t   15 - ListaOrdenada-1000.txt";
    cout << "\n\t   16 - ListaOrdenada-10000.txt";
    cout << "\n\t   17 - ListaOrdenada-100000.txt";
    cout << "\n\t   18 - ListaOrdenada-1000000.txt";
    cout << "\n\t ---------------------------------------------------";
    cout << "\n\t   19 - ListaQuaseOrdenada-1000.txt";
    cout << "\n\t   20 - ListaQuaseOrdenada-10000.txt";
    cout << "\n\t   21 - ListaQuaseOrdenada-100000.txt";
    cout << "\n\t   22 - ListaQuaseOrdenada-1000000.txt" << endl;
    cout << "\t ---------------------------------------------------";
    cout << "\n\t    0 - Voltar para o menu principal";
    cout << "\n\t ---------------------------------------------------"; 
}

void Escolha_Metodo(int escolha_metodo, vector <string> &vector_string, vector <int> &vector_int)
{
    vector <string> vector_aux;

    switch (escolha_metodo)
    {
        case 1:
            Bubble_Sort(vector_string, vector_int, trocas = 0, comparacoes = 0, recebe_escolha_arquivo);
        break;

        case 2:
            InsertionSort(vector_string, vector_int, trocas = 0, comparacoes = 0, recebe_escolha_arquivo);
        break;

        case 3:
            SelectionSort(vector_string, vector_int, trocas = 0, comparacoes = 0, recebe_escolha_arquivo);
        break;
        
        case 4:
            ShellSort(vector_string, vector_int, trocas = 0, comparacoes = 0, recebe_escolha_arquivo);
        break;

        case 5:
            if (verificacao == true)
            {
                QuickSort_String(vector_string, 0, vector_string.size() - 1);
            }
            else if (verificacao == false)
            {
                QuickSort_Int(vector_int, 0, vector_int.size() - 1);
            }
        break;

        case 6:
            if (verificacao == true)
            {
                MergeSort_String(vector_string, vector_aux, 0, vector_string.size() - 1);
            }
            else if (verificacao == false)
            {
                MergeSort_Int(vector_int, 0, vector_int.size() - 1);
            }
        break;
    }
}

void AbrirArquivo(vector <string> vector_string, vector <int> vector_int, int escolha_arquivo = 0, int escolha_metodo = 0)
{
    int i = 0;
    string linha, arquivo_nome, metodo_nome;

    ifstream arquivoE;

    switch (escolha_metodo)
    {
        case 1:
            metodo_nome = "Bubble Sort";
        break;

        case 2:
            metodo_nome = "Insertion Sort";
        break;

        case 3:
            metodo_nome = "Selection Sort";
        break;

        case 4:
            metodo_nome = "Shell Sort";
        break;

        case 5:
            metodo_nome = "Quick Sort";
        break;

        case 6:
            metodo_nome = "Merge Sort";
        break;
    }

    switch (escolha_arquivo)
    {
        case 1:
            arquivoE.open("DicionarioAleatorio-29855.txt");
            arquivo_nome = "DicionarioAleatorio-29855.txt";
        break;

        case 2:
            arquivoE.open("DicionarioAleatorio-261791.txt");
            arquivo_nome = "DicionarioAleatorio-261791.txt";
        break;

        case 3:
            arquivoE.open("DicionarioInversamenteOrdenado-29855.txt");
            arquivo_nome = "DicionarioInversamenteOrdenado-29855.txt";
        break;

        case 4:
            arquivoE.open("DicionarioInversamenteOrdenado-261791.txt");
            arquivo_nome = "DicionarioInversamenteOrdenado-261791.txt";
        break;

        case 5:
            arquivoE.open("DicionarioOrdenado-29855.txt");
            arquivo_nome = "DicionarioOrdenado-29855.txt";
        break;

        case 6:
            arquivoE.open("DicionarioOrdenado-261791.txt");
            arquivo_nome = "DicionarioOrdenado-261791.txt";
        break;

        case 7:
            arquivoE.open("ListaAleatoria-1000.txt");
            arquivo_nome = "ListaAleatoria-1000.txt";
        break;

        case 8:
            arquivoE.open("ListaAleatoria-10000.txt");
            arquivo_nome = "ListaAleatoria-10000.txt";
        break;

        case 9:
            arquivoE.open("ListaAleatoria-100000.txt");
            arquivo_nome = "ListaAleatoria-100000.txt";
        break;

        case 10:
            arquivoE.open("ListaAleatoria-1000000.txt");
            arquivo_nome = "ListaAleatoria-1000000.txt";
        break;

        case 11:
            arquivoE.open("ListaInversamenteOrdenada-1000.txt");
            arquivo_nome = "ListaInversamenteOrdenada-1000.txt";
        break;

        case 12:
            arquivoE.open("ListaInversamenteOrdenada-10000.txt");
            arquivo_nome = "ListaInversamenteOrdenada-10000.txt";
        break;

        case 13:
            arquivoE.open("ListaInversamenteOrdenada-100000.txt");
            arquivo_nome = "ListaInversamenteOrdenada-100000.txt";
        break;

        case 14:
            arquivoE.open("ListaInversamenteOrdenada-1000000.txt");
            arquivo_nome = "ListaInversamenteOrdenada-1000000.txt";
        break;

        case 15:
            arquivoE.open("ListaOrdenada-1000.txt");
            arquivo_nome = "ListaOrdenada-1000.txt";
        break;

        case 16:
            arquivoE.open("ListaOrdenada-10000.txt");
            arquivo_nome = "ListaOrdenada-10000.txt";
        break;

        case 17:
            arquivoE.open("ListaOrdenada-100000.txt");
            arquivo_nome = "ListaOrdenada-100000.txt";
        break;

        case 18:
            arquivoE.open("ListaOrdenada-1000000.txt");
            arquivo_nome = "ListaOrdenada-1000000.txt";
        break;

        case 19:
            arquivoE.open("ListaQuaseOrdenada-1000.txt");
            arquivo_nome = "ListaQuaseOrdenada-1000.txt";
        break;

        case 20:
            arquivoE.open("ListaQuaseOrdenada-10000.txt");
            arquivo_nome = "ListaQuaseOrdenada-10000.txt";
        break;

        case 21:
            arquivoE.open("ListaQuaseOrdenada-100000.txt");
            arquivo_nome = "ListaQuaseOrdenada-100000.txt";
        break;

        case 22:
            arquivoE.open("ListaQuaseOrdenada-1000000.txt");
            arquivo_nome = "ListaQuaseOrdenada-1000000.txt";
        break;
    }

    if (arquivoE.is_open())
    {
        if (escolha_arquivo >= 1 && escolha_arquivo <= 5)
        {
            verificacao = true;
            while (getline(arquivoE, linha))
            {
                vector_string.push_back(linha);
                i++;
            }
        }

        else if (escolha_arquivo >= 6 && escolha_arquivo <= 22)
        {
            verificacao = false;
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

    if (verificacao == true)
    {
        for (i = 0; i < vector_string.size(); i++)
        {
            cout << " " << vector_string[i];
        }
    }
    else if (verificacao == false)
    {
        for (i = 0; i < vector_int.size(); i++)
        {
            cout << " " << vector_int[i];
        }
    }
    cout << " ]" << endl;

    cout << "\n - Número total de troca de posições: " << trocas << endl;

    cout << "\n - Número total de comparações: " << comparacoes << endl;

    cout << "\n - Tempo gasto: " << ((float)inicio) / CLOCKS_PER_SEC << " segundos/milissegundos" << endl;

    ofstream arquivoS;

    arquivoS.open("Dados.txt", ios::app);

    cout << endl;
    arquivoS << "\n Método utilizado: " << metodo_nome << "\n";
    arquivoS << "\n Arquivo: " << arquivo_nome << "\n";
    arquivoS << "\n Trocas: " << trocas << "\n";
    arquivoS << "\n Comparações: " << comparacoes << "\n";
    arquivoS << "\n Tempo Total: " << ((float)inicio) / CLOCKS_PER_SEC << " segundos/milissegundos" << "\n";
    arquivoS << "\n -----------------------------------------------";

    system("pause");
}
