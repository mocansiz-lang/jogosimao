#pragma once
#include "Entidade.h"

class Personagem : public Entidade
{
protected:
    int num_vidas;

public:
    Personagem(int vidas = 1) : Entidade(), num_vidas(vidas) {}
    virtual ~Personagem() {}

    void setVidas(int v) { num_vidas = v; }
    int getVidas() const { return num_vidas; }
    void tomarDano(int dano = 1) { num_vidas -= dano; }
    bool estaVivo() const { return num_vidas > 0; }

    virtual void mover() = 0;
    virtual void executar() = 0;
    virtual void salvar() = 0;
};