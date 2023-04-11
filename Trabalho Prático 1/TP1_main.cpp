#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include "TP1_funcoes.cpp"
 
using namespace std;

 
int main() 
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  int escolha, escolha_bubblesort, escolha_insertionsort, 
  escolha_selectionsort;
  string result[29855];

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
      
        if (escolha_bubblesort == 1 || escolha_bubblesort == 2 || escolha_bubblesort == 3 ||
            escolha_bubblesort == 4 || escolha_bubblesort == 5 || escolha_bubblesort == 6 ||
            escolha_bubblesort == 7 || escolha_bubblesort == 8 || escolha_bubblesort == 9 ||
            escolha_bubblesort == 10 || escolha_bubblesort == 11)
        {
           AbrirArquivo_Bubblesort(result, escolha_bubblesort);
        }
      break;

      case 2:
        MENU_Instancias();
        cout << "\n - Escolha o arquivo que deseja ordenar: ";
        cin >> escolha_insertionsort;

        if (escolha_insertionsort == 1 || escolha_insertionsort == 2 || escolha_insertionsort == 3 ||
            escolha_insertionsort == 4 || escolha_insertionsort == 5 || escolha_insertionsort == 6 ||
            escolha_insertionsort == 7 || escolha_insertionsort == 8 || escolha_insertionsort == 9 ||
            escolha_insertionsort == 10 || escolha_insertionsort == 11)
        {
          AbrirArquivo_Insertionsort(result, escolha_insertionsort);
        }
      break;

      case 3:
        MENU_Instancias();
        cout << "\n - Escolha o arquivo que deseja ordenar: ";
        cin >> escolha_selectionsort;

        if (escolha_selectionsort == 1 || escolha_selectionsort == 2 || escolha_selectionsort == 3 ||
            escolha_selectionsort == 4 || escolha_selectionsort == 5 || escolha_selectionsort == 6 ||
            escolha_selectionsort == 7 || escolha_selectionsort == 8 || escolha_selectionsort == 9 ||
            escolha_selectionsort == 10 || escolha_selectionsort == 11)
        {
          AbrirArquivo_Selectionsort(result, escolha_selectionsort);
        }
      break;
    }
  }while (escolha != 0);
 
 
  cout << endl;
  return 0;
}