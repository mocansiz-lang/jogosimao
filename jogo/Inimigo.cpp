#include "Inimigo.h"
#include "Jogador.h"

Inimigo::Inimigo(int vidas, int maldade, const std::string& nomeInim) :
    Personagem(vidas, nomeInim), nivel_maldade(maldade)
{
}

Inimigo::~Inimigo()
{
}

int Inimigo::getNivelMaldade() const
{
    return nivel_maldade;
}

void Inimigo::setNivelMaldade(int m)
{
    nivel_maldade = m;
}

void Inimigo::danificar(Jogador* pJog)
{
    if (pJog != nullptr)
    {
        pJog->tomarDano(nivel_maldade);
    }
}
