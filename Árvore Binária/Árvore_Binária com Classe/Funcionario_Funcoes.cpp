#include <iostream>
#include <windows.h>
#include "Funcionario.hpp"

using namespace std;

Funcionario::Funcionario(int CPF, char name)
{
    cpf = CPF;
    nome = name;
}

char Funcionario::ObterNome()
{
    return nome;
}

int Funcionario::ObterCPF()
{
    return cpf;
}



