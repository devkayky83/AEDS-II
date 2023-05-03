#include <iostream>
#include <windows.h>
#include "Arvore_funcoes.cpp"
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  
 
 
  cout << endl << endl;
  return 0;
}