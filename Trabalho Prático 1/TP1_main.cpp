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
 
  int escolha_metodo = 0, escolha_arquivo = 0;
  vector <string> result;

  MENU();
  cout << "\n\t - Selecione o método que deseja aplicar: ";
  cin >> escolha_metodo; 

  do
  {
    if (escolha_metodo >= 1 && escolha_metodo <= 6)
    {
        MENU_Instancias();
        cout << "\n - Escolha o arquivo que deseja ordenar: ";
        cin >> escolha_arquivo;
      
        if (escolha_arquivo >= 1 && escolha_arquivo <= 17)
        {
           AbrirArquivo(result, escolha_arquivo, escolha_metodo);
        }
    }
  }while (escolha_metodo != 0);
 
 
  cout << endl;
  return 0;
}