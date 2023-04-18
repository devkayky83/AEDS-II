#include <iostream>
#include <vector>
#include <windows.h>
 
using namespace std;

void QuickSort_Int(int Lista_Int[], int esquerda, int direita)
{
    int aux; ;
    int pivo = Lista_Int[(esquerda + direita) / 2], i = esquerda, j = direita;

    
    while (i <= j)
    {
        while (Lista_Int[i] < pivo)
            i++;
        while (Lista_Int[j] > pivo)
            j--;
        if (i <= j)
        {
            for (int k = 0; k < 9; k++)
            {
                cout << Lista_Int[k] << " ";
            }
            cout << endl;
            cout << pivo;
            cout << endl;
            
            aux = Lista_Int[i];
            Lista_Int[i] = Lista_Int[j];
            Lista_Int[j] = aux;
            i++;
            j--;

            for (int u = 0; u < 9; u++)
            {
                cout << Lista_Int[u] << " ";
            }
            cout << endl;
        }
    };

    if (esquerda < j)
        QuickSort_Int(Lista_Int, esquerda, j);
    if (i < direita)
        QuickSort_Int(Lista_Int, i, direita);

}
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  int Car[] = {4,3,6,5,10,11,9,8,7};

  QuickSort_Int(Car, 0, 9);
 
 
  cout << endl;
  return 0;
}