#include "Inimigo.h"
#include "Jogador.h"

Inimigo::Inimigo(int vidas, int maldade) :
    Personagem(vidas), nivel_maldade(maldade)
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::danificar(Jogador* pJog)
{
    if (pJog && estaVivo())
    {
        // Causa dano ao jogador baseado no nivel_maldade do inimigo
        pJog->tomarDano(nivel_maldade);
    }
}