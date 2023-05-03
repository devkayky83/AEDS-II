#ifndef Funcionario_H
#define Funcionario_H

typedef struct TipoData
{
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
};

typedef struct TipoEndereco
{
    char logradouro[50];
    int numero;
    char bairro[30];
    char cidade[30];
    char estado[2];
    char cep[10];
};

class Funcionario
{
    private:

    int matricula;
    char nome;
    int cpf;
    char cargo[30];
    char telefone[15];
    TipoEndereco Endereco;
    TipoData Data;

    public:

    Funcionario();
    Funcionario(int CPF, char name);
    char ObterNome();
    int ObterCPF();
};


#endif