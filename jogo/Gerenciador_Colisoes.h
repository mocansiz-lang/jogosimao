#pragma once
#include <vector>
#include "Jogador.h"
#include "Inimigo.h"

class Gerenciador_Colisoes
{
private:
    Jogador* player1;
    std::vector<Inimigo*> LIs;

public:
    Gerenciador_Colisoes(Jogador* Pessoa, Inimigo* inimigos = nullptr);
    ~Gerenciador_Colisoes();

    void incluirInimigo(Inimigo* pi);
    bool verificarColisao(Entidade* pe1, Entidade* pe2) const;
    void tratarColisoesJogsObstacs();
    void tratarColisoesJogsParedes();
    void tratarColisoesJogsInimgs();

    void executar();
};
