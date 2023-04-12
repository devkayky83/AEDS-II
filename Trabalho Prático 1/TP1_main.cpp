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
 
  int escolha, escolha_arquivo;
  vector <string> result;

  MENU();
  cout << "\n\t - Selecione o método que deseja aplicar: ";
  cin >> escolha; 

  do
  {
    if (escolha >= 1 && escolha <= 6)
    {
        MENU_Instancias();
        cout << "\n - Escolha o arquivo que deseja ordenar: ";
        cin >> escolha_arquivo;
      
        if (escolha_arquivo >= 1 && escolha_arquivo <= 14)
        {
           AbrirArquivo(result, escolha_arquivo, escolha);
        }
    }

  }while (escolha != 0);
 
 
  cout << endl;
  return 0;
}