#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include <vector>

class Gerenciador_Colisoes
{
private:
    Jogador* player1;
    std::vector<Inimigo*> LIs; // Lista de Inimigos (Fácil, Médio e Chefão)

public:
    Gerenciador_Colisoes(Jogador* Pessoa = nullptr);
    ~Gerenciador_Colisoes();

    // FUNÇÃO PARA ANEXAR INIMIGO FÁCIL, MÉDIO E CHEFÃO
    void incluirInimigo(Inimigo* pi);

    bool verificarColisao(Entidade* pe1, Entidade* pe2) const;
    void tratarColisoesJogsObstacs();
    void tratarColisoesJogsParedes();
    void tratarColisoesJogsInimgs();

    void executar();
};
