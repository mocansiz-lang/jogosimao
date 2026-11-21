#pragma once
#include "Personagem.h"

class Jogador :
    public Personagem
{
private:
    sf::CircleShape circulo;
    int cooldownDano;

public:
    Jogador();
    void mover();
    void executar();
    void salvar();
    void tomarDano(int dano);
    void setPoint(float px, float py);

    sf::FloatRect getLados()
    {
        return circulo.getGlobalBounds();
    }
    sf::CircleShape& getCirculo() { return circulo; }
};
