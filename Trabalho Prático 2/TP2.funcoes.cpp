#include <iostream>
#include <Windows.h>
#include <fstream>
#include "TP2.hpp"

using namespace std;

void Menu_Principal()
{
    system("cls");
    cout << "\n --------------------------";
    cout << "\n       DEPARTAMENTO";
    cout << "\n --------------------------";
    cout << "\n 1. Cadastrar Funcionário";
    cout << "\n 2. Buscar Funcionário";
    cout << "\n 3. Remover Funcionário";
    cout << "\n 4. Imprimir";
    cout << "\n 0. Sair";
    cout << "\n --------------------------" << endl;
}

void Menu_Busca()
{
    system("cls");
    cout << "\n ---------------------------";
    cout << "\n        FUNCIONÁRIO";
    cout << "\n ---------------------------";
    cout << "\n 1. Buscar por Nome";
    cout << "\n 2. Buscar por CPF";
    cout << "\n ---------------------------" << endl;
}

void Menu_Remover()
{
    system("cls");
    cout << "\n ---------------------------";
    cout << "\n        FUNCIONÁRIO";
    cout << "\n ---------------------------";
    cout << "\n 1. Remover por Nome";
    cout << "\n 2. Remover por CPF";
    cout << "\n ---------------------------" << endl;
}

void InserirEsquerda(TipoNo *No, TipoInfo Info)
{
    if (No->Esq == NULL)
    {
        TipoNo *novo = new TipoNo;
        novo->Info = Info;
        novo->Esq = NULL;
        novo->Dir = NULL;
        No->Esq = novo;
    }
    else
    {
        if(strcmp(Info.nome, No->Esq->Info.nome) == -1)
        {
            InserirEsquerda(No->Esq, Info);
        }
        else
        {
            InserirDireita(No->Esq, Info);
        }
    }
}

void InserirDireita(TipoNo *No, TipoInfo Info)
{
    if (No->Dir == NULL)
    {
        TipoNo *novo = new TipoNo;
        novo->Info = Info;
        novo->Esq = NULL;
        novo->Dir = NULL;
        No->Dir = novo;
    }
    else
    {
        if (strcmp(Info.nome, No->Dir->Info.nome) == 1)
        {
            InserirDireita(No->Dir, Info);
        }
        else
        {
            InserirEsquerda(No->Dir, Info);
        }
    }
}

void Inserir(TipoArvore *Raiz, TipoInfo Info)
{
    int escolha;

    system("cls");
    cout << "\n Digite a mátricula do funcionário: ";
    cin >> Info.matricula;

    system("cls");
    cout << "\n Digite o nome do funcionário: ";
    cin.ignore();
    cin.getline(Info.nome, 50);

    system("cls");
    cout << "\n Digite o cpf do funcionário: ";
    cin >> Info.cpf;

    system("cls");
    cout << "\n Digite o cargo que o mesmo ocupa: ";
    cin.ignore();
    cin.getline(Info.cargo, 30);

    system("cls");
    cout << "\n Digite o telefone do funcionário: ";
    cin >> Info.telefone;

    system("cls");
    cout << "\n Digite o estado onde mora o funcionário: ";
    cin.ignore();
    cin.getline(Info.Endereco.estado, 20);

    system("cls");
    cout << "\n Digite a cidade do funcionário: ";
    cin.getline(Info.Endereco.cidade, 20);

    system("cls");
    cout << "\n Digite o bairro do funcionário: ";
    cin.getline(Info.Endereco.bairro, 30);

    system("cls");
    cout << "\n Digite o número da casa: ";
    cin >> Info.Endereco.numero;

    system("cls");
    cout << "\n Possui logradouro? (1) - Sim, (2) - Não: ";
    cin >> escolha;

        if (escolha == 1)
        {
            cout << "\n Digite o logradouro: ";
            cin.ignore();
            cin.getline(Info.Endereco.logradouro, 50);
        }
        else
        {
            *Info.Endereco.logradouro = NULL;
        }

        system("cls");
        cout << "\n Digite o CEP da cidade do funcionário: ";
        cin.ignore();
        cin.getline(Info.Endereco.cep, 10);

        system("cls");
        cout << "\n Digite o dia do nascimento: ";
        cin >> Info.Data.dia;

        system("cls");
        cout << "\n Digite o mês do nascimento: ";
        cin >> Info.Data.mes;

        system("cls");
        cout << "\n Digite o ano do nascimento: ";
        cin >> Info.Data.ano;

    if (Raiz->Raiz == NULL)
    {
        TipoNo *novo = new TipoNo;
        novo->Info = Info;
        novo->Esq = NULL;
        novo->Dir = NULL;
        Raiz->Raiz = novo;
    }
    else
    {
        if (strcmp(Info.nome, Raiz->Raiz->Info.nome) == -1)
        {
            InserirEsquerda(Raiz->Raiz, Info);
        }
        else
        {
            InserirDireita(Raiz->Raiz, Info);
        }
    }
    cout << "\n Funcionário inserido com sucesso!" << endl;
    system("pause");
}

void Imprimir(TipoNo *No)
{
    if (No != NULL)
    {
        cout << "\n Nome do funcionário: " << No->Info.nome;
        cout << "\n Matricula: " << No->Info.matricula;
        cout << "\n CPF: " << No->Info.cpf;
        cout << "\n Cargo: " << No->Info.cargo;
        cout << "\n Telefone: " << No->Info.telefone;
        cout << "\n Estado: " << No->Info.Endereco.estado;
        cout << "\n Cidade: " << No->Info.Endereco.cidade;
        cout << "\n Bairro: " << No->Info.Endereco.bairro;
        cout << "\n Nº da casa: " << No->Info.Endereco.numero;
        
        if (*No->Info.Endereco.logradouro != NULL)
        {
            cout << "\n Logradouro: " << No->Info.Endereco.logradouro;
        }
        else if (*No->Info.Endereco.logradouro == NULL)
        {
            cout << "\n Logradouro: NULL";
        }

        cout << "\n CEP: " << No->Info.Endereco.cep;
        cout << "\n Data de Nascimento: " << No->Info.Data.dia 
        << "/" << No->Info.Data.mes << "/" << No->Info.Data.ano; 
        cout << "\n ------------------------------------" << endl;
        Imprimir(No->Esq);
        Imprimir(No->Dir);
    }
}

void Imprimir_Busca(TipoNo *No)
{
    if (No != NULL)
    {
        cout << "\n Nome do funcionário: " << No->Info.nome;
        cout << "\n Matricula: " << No->Info.matricula;
        cout << "\n CPF: " << No->Info.cpf;
        cout << "\n Cargo: " << No->Info.cargo;
        cout << "\n Telefone: " << No->Info.telefone;
        cout << "\n Estado: " << No->Info.Endereco.estado;
        cout << "\n Cidade: " << No->Info.Endereco.cidade;
        cout << "\n Bairro: " << No->Info.Endereco.bairro;
        cout << "\n Nº da casa: " << No->Info.Endereco.numero;
        
        if (*No->Info.Endereco.logradouro != NULL)
        {
            cout << "\n Logradouro: " << No->Info.Endereco.logradouro;
        }
        else if (*No->Info.Endereco.logradouro == NULL)
        {
            cout << "\n Logradouro: NULL";
        }

        cout << "\n CEP: " << No->Info.Endereco.cep;
        cout << "\n Data de Nascimento: " << No->Info.Data.dia 
        << "/" << No->Info.Data.mes << "/" << No->Info.Data.ano;
        cout << "\n ------------------------------------" << endl;
    }
}

void Buscar_Nome(TipoNo *No, char nome_recebido[50])
{
    if (No == NULL)
    {
        cout << "\n Não há funcionarios cadastrados!" << endl;
    }
    else
    {
        cout << "\n Digite o nome do funcionário que desejá buscar: ";
        cin >> nome_recebido;
        system("cls");

        while (No)
        {
            if (strcmp(nome_recebido, No->Info.nome) == -1)
            {
                No = No->Esq;
            }
            else if (strcmp(nome_recebido, No->Info.nome) == 1)
            {
                No = No->Dir;
            }
            else if (strcmp(nome_recebido, No->Info.nome) == 0)
            {
                return Imprimir_Busca(No);
            }
        }
    }
}

void Buscar_CPF(TipoNo *No, char cpf_recebido[11])
{
    if (No == NULL)
    {
        cout << "\n Não há funcionarios cadastrados!" << endl;
    }
    else
    {
        cout << "\n Digite o nome do funcionário que desejá buscar: ";
        cin >> cpf_recebido;
        system("cls");

        while (No)
        {
            if (strcmp(cpf_recebido, No->Info.cpf) == -1)
            {
                No = No->Esq;
            }
            else if (strcmp(cpf_recebido, No->Info.cpf) == 1)
            {
                No = No->Dir;
            }
            else if (strcmp(cpf_recebido, No->Info.cpf) == 0)
            {
                return Imprimir_Busca(No);
            }
        }
    }
}

TipoNo* Remover_PorNome(TipoNo *No, char nome_recebido[50])
{   
    if (No == NULL)
    {
        cout << "\n Não há funcionarios cadastrados!" << endl;
        system("pause");
    }
    else
    {
        if (strcmp(No->Info.nome, nome_recebido) == 0)
        {
            if (No->Esq == NULL && No->Dir == NULL)
            {
                free(No);
                cout << "\n Removendo Funcionário...";
                Sleep(2000);
                system("cls");
                cout << "\n Funcionário removido com sucesso!" << endl;
                return NULL;
            }
            else
            {
                if (No->Esq != NULL || No->Dir != NULL)
                {
                    TipoNo *Aux;

                    if (No->Esq != NULL)
                    {
                        Aux = No->Esq;
                    }
                    else
                    {
                        Aux = No->Dir;
                    }
                    free(No);
                    return Aux;
                }
                else
                {
                    TipoNo *Aux = No->Esq;

                    while(Aux->Dir != NULL)
                    {
                        Aux = Aux->Dir;
                    }
                    No->Info = Aux->Info;
                    *Aux->Info.nome = *nome_recebido;
                    No->Esq = Remover_PorNome(No->Esq, nome_recebido);
                    return No;
                }
            }
        }
        else
        {
            if (strcmp(nome_recebido, No->Info.nome) == -1)
            {
                No->Esq = Remover_PorNome(No->Esq, nome_recebido);
            }
            else if (strcmp(nome_recebido, No->Info.nome) == 1)
            {
                No->Dir = Remover_PorNome(No->Dir, nome_recebido);
            }
            return No;
        }
    }
}

TipoNo* Remover_PorCPF(TipoNo *No, char cpf_recebido[11])
{
    if (No == NULL)
    {
        cout << "\n Não há funcionarios cadastrados!" << endl;
        system("pause");
    }
    else
    {
        if (strcmp(No->Info.cpf , cpf_recebido) == 0)
        {
            if (No->Esq == NULL && No->Dir == NULL)
            {
                free(No);
                cout << "\n Removendo Funcionário...";
                Sleep(2000);
                system("cls");
                cout << "\n Funcionário removido com sucesso!" << endl;
                return NULL;
            }
            else
            {
                if (No->Esq != NULL || No->Dir != NULL)
                {
                    TipoNo *Aux;

                    if (No->Esq != NULL)
                    {
                        Aux = No->Esq;
                    }
                    else
                    {
                        Aux = No->Dir;
                    }
                    free(No);
                    return Aux;
                }
                else
                {
                    TipoNo *Aux = No->Esq;

                    while(Aux->Dir != NULL)
                    {
                        Aux = Aux->Dir;
                    }
                    No->Info = Aux->Info;
                    *Aux->Info.cpf = *cpf_recebido;
                    No->Esq = Remover_PorCPF(No->Esq, cpf_recebido);
                    return No;
                }
            }
        }
        else
        {
            if (strcmp(cpf_recebido, No->Info.cpf) == -1)
            {
                No->Esq = Remover_PorCPF(No->Esq, cpf_recebido);
            }
            else if (strcmp(cpf_recebido, No->Info.cpf) == 1)
            {
                No->Dir = Remover_PorCPF(No->Dir, cpf_recebido);
            }
            return No;
        }
    }
}

void Salva_Arquivo(TipoNo *No, TipoInfo *Info)
{
    int contador_funcionario = 0;

    ofstream ArquivoS;

    ArquivoS.open("Funcionarios.txt", ios::app);

    ArquivoS << "\n           - Funcionário " << contador_funcionario + 1;
    ArquivoS << "\n -------------------------------------" << endl;

    ArquivoS << "\n Nome do funcionário: " << Info->nome;
    ArquivoS << "\n Matricula: " << Info->matricula;
    ArquivoS << "\n CPF: " << Info->cpf;
    ArquivoS << "\n Cargo: " << Info->cargo;
    ArquivoS << "\n Telefone: " << Info->telefone;
    ArquivoS << "\n Estado: " << Info->Endereco.estado;
    ArquivoS << "\n Cidade: " << Info->Endereco.cidade;
    ArquivoS << "\n Bairro: " << Info->Endereco.bairro;
    ArquivoS << "\n Nº da casa: " << Info->Endereco.numero;
        
    if (*No->Info.Endereco.logradouro != NULL)
    {
        ArquivoS << "\n Logradouro: " << Info->Endereco.logradouro;
    }
    else if (*No->Info.Endereco.logradouro == NULL)
    {
        ArquivoS << "\n Logradouro: NULL";
    }

    ArquivoS << "\n CEP: " << Info->Endereco.cep;
    ArquivoS << "\n Data de Nascimento: " << Info->Data.dia 
    << "/" << Info->Data.mes << "/" << Info->Data.ano; 
    ArquivoS << "\n ------------------------------------" << endl;
}