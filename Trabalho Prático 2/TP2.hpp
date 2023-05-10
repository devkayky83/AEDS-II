#ifndef TP2_h
#define TP2_H

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
    char cidade[20];
    char estado[10];
    char cep[10];
};

typedef struct TipoInfo
{
    int matricula;
    char cpf[11];
    char nome[50];
    char cargo[30];
    char telefone[15];
    TipoEndereco Endereco;
    TipoData Data;
};

typedef struct TipoNo
{
    TipoInfo Info;
    struct TipoNo *Esq, *Dir;
};

typedef struct TipoArvore
{
    TipoNo *Raiz;
};

void Menu_Principal();
void Menu_Busca();
void Menu_Remover();
void Coleta_Informacoes(TipoInfo *Info);
void InserirDireita(TipoNo *No, TipoInfo Info);
void InserirEsquerda(TipoNo *No, TipoInfo Info);
void Inserir(TipoArvore *Raiz, TipoInfo Info);
void Imprimir(TipoNo *No);
void Imprimir_Busca(TipoNo *No);
void Buscar_Nome(TipoNo *No, char nome_recebido[50]);
void Buscar_CPF(TipoNo *No, char cpf_recebido[11]);
TipoNo* Remover_PorNome(TipoNo *No, char nome_recebido[50]);
TipoNo* Remover_PorCPF(TipoNo *No, char cpf_recebido[11]);
void Salva_Arquivo(TipoNo *No, TipoInfo *Info);

#endif