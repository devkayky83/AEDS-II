#ifndef Arvore_H
#define Arvore_H
#include "Funcionario.hpp"


typedef struct No
{
    Funcionario funcionario;
    No *Esq;
    No *Dir;
};


class Arvore_De_Busca
{
    private:
    No *Raiz;

    public:
    Arvore_De_Busca();
    ~Arvore_De_Busca();
    No *ObterRaiz();
    bool EstaVazio();
    bool EstaCheio();
    void DeletarArvore(No* Atual);
    void Inserir(Funcionario funcionario);
    void Remover(Funcionario funcionario);
    void Pesquisa(Funcionario &funcionario, bool &pesquisa);
    void ImprimirPreOrdem(No *Atual);
    void ImprimirEmOrdem(No *Atual);
    void ImprimirPosOrdem(No *Atual);
};





#endif