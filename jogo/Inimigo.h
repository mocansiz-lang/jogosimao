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

    int getNivelMaldade() const;
    void setNivelMaldade(int m);
    virtual void danificar(Jogador* pJog);

    virtual sf::FloatRect getLados() = 0;
};
