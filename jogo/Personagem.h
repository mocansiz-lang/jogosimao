#pragma once
#include "Entidade.h"

class Personagem :
    public Entidade
{
protected:
    int num_vidas;
    int max_vidas;

public:
    Personagem(int vidas = 1);
    virtual ~Personagem();

    int getNumVidas() const;
    int getMaxVidas() const;
    void setNumVidas(int v);
    virtual void tomarDano(int dano);
    bool estaVivo() const;

    virtual void mover() = 0;
};
