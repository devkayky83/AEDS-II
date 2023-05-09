#include <iostream>
#include <windows.h>
#include "TP2.funcoes.cpp"

using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  int escolha_menu, escolha;
  char nome_digitado[50], cpf_digitado[11];

  TipoArvore Raiz;
  TipoNo No;
  TipoInfo Info;

  Raiz.Raiz = NULL;

  do
  {
    Menu_Principal();
    cout << "\n Escolha oque desejá fazer: ";
    cin >> escolha_menu;

    switch (escolha_menu)
    {
      case 1:
        Inserir(&Raiz, Info);
        Salva_Arquivo(&No, &Raiz.Raiz->Info);
      break;

      case 2:
        Menu_Busca();
        cout << "\n Digite o modo que desejá buscar: ";
        cin >> escolha;

        if (escolha == 1)
        {
          system("cls");
          Buscar_Nome(Raiz.Raiz, nome_digitado);
          system("pause");
        }
        else if (escolha == 2)
        {
          system("cls");
          Buscar_CPF(Raiz.Raiz, cpf_digitado);
          system("pause");
        }
      break;

      case 3:
        Menu_Remover();
        cout << "\n Digite o modo que desejá remover: ";
        cin >> escolha;

        if (escolha == 1)
        {
          system("cls");
          cout << "\n Digite o nome do funcionário que desejá remover: ";
          cin >> nome_digitado;
          system("cls");
          Raiz.Raiz = Remover_PorNome(Raiz.Raiz, nome_digitado);
          system("pause");
        }
        else if (escolha == 2)
        {
          system("cls");
          cout << "\n Digite o cpf do funcionário que desejá remover: ";
          cin >> cpf_digitado;
          system("cls");
          Raiz.Raiz = Remover_PorCPF(Raiz.Raiz, cpf_digitado);
          system("pause");
        }
      break;

      case 4:
        system("cls");
        Imprimir(Raiz.Raiz);
        system("pause");
      break;

      case 0:
        return 0;
      break;
    
      default:
        cout << "\n Comando invalido..." << endl;
        system("pause");
      break;
    }
  } while (escolha_menu != 0);
  
 
 
  cout << endl;
  return 0;
}