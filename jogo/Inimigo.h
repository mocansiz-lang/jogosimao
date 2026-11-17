#pragma once
#include "Personagem.h"

class Jogador;

class Inimigo : public Personagem
{
protected:
    int nivel_maldade;

public:
    Inimigo(int vidas = 1, int maldade = 1);
    virtual ~Inimigo();

    void setNivelMaldade(int maldade) { nivel_maldade = maldade; }
    int getNivelMaldade() const { return nivel_maldade; }

    virtual sf::FloatRect getLados() = 0;
    virtual void mover() = 0;
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void danificar(Jogador* pJog);
};