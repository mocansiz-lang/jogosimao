#include "Personagem.h"

Personagem::Personagem(int vidas) : num_vidas(vidas), max_vidas(vidas)
{
}

Personagem::~Personagem()
{
}

int Personagem::getNumVidas() const
{
    return num_vidas;
}

int Personagem::getMaxVidas() const
{
    return max_vidas;
}

void Personagem::setNumVidas(int v)
{
    num_vidas = v;
    if (v > max_vidas)
    {
        max_vidas = v;
    }
}

void Personagem::tomarDano(int dano)
{
    num_vidas -= dano;
    if (num_vidas < 0)
    {
        num_vidas = 0;
    }
}

bool Personagem::estaVivo() const
{
    return num_vidas > 0;
}
