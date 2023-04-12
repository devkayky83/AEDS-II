#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include "TP1_funcoes.cpp"
 
using namespace std;

int main() 
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  int escolha, escolha_bubblesort, escolha_insertionsort, 
  escolha_selectionsort;
  vector <string> result;

  MENU();
  cout << "\n\t - Selecione o método que deseja aplicar: ";
  cin >> escolha; 

  do
  {
    switch(escolha)
    {
      case 1:
        MENU_Instancias();
        cout << "\n - Escolha o arquivo que deseja ordenar: ";
        cin >> escolha_bubblesort;
      
        if (escolha_bubblesort >= 1 && escolha_bubblesort <= 14)
        {
           AbrirArquivo_Bubblesort(result, escolha_bubblesort);
        }
      break;

      case 2:
        MENU_Instancias();
        cout << "\n - Escolha o arquivo que deseja ordenar: ";
        cin >> escolha_insertionsort;

        if (escolha_insertionsort >= 1 && escolha_insertionsort <= 14)
        {
          AbrirArquivo_Insertionsort(result, escolha_insertionsort);
        }
      break;

      case 3:
        MENU_Instancias();
        cout << "\n - Escolha o arquivo que deseja ordenar: ";
        cin >> escolha_selectionsort;

        if (escolha_selectionsort >= 1 && escolha_selectionsort <= 14)
        {
          AbrirArquivo_Selectionsort(result, escolha_selectionsort);
        }
      break;
    }
  }while (escolha != 0);
 
 
  cout << endl;
  return 0;
}