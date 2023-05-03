#include <iostream>
#include <windows.h>
#include <cstddef>
#include "Arvore.hpp"

using namespace std;


    Arvore_De_Busca::Arvore_De_Busca() // Função construtora
    {   
        Raiz = NULL;
    }   

    Arvore_De_Busca::~Arvore_De_Busca() // Função destrutora
    {

    }

    No *Arvore_De_Busca::ObterRaiz()
    {
        return Raiz;
    }

    bool Arvore_De_Busca::EstaVazio()
    {
        return (Raiz == NULL);
    }

    bool Arvore_De_Busca::EstaCheio()
    {
        try
        {
            No *Temporario = new No;
            delete Temporario;
            return false;
        }catch (bad_alloc exception)
        {
            return true;
        }
    }


    void DeletarArvore(No* Atual);
    void Inserir(Funcionario funcionario);
    void Remover(Funcionario funcionario);
    void Pesquisa(Funcionario &funcionario, bool &pesquisa);
    void ImprimirPreOrdem(No *Atual);
    void ImprimirEmOrdem(No *Atual);
    void ImprimirPosOrdem(No *Atual);

