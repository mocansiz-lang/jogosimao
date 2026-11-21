#pragma once
#include "Inimigo.h"

class Inim_Medio : public Inimigo
{
private:
    sf::RectangleShape Retangulo;
    float velX;

public:
    Inim_Medio();
    ~Inim_Medio();

    sf::FloatRect getLados()
    {
        return Retangulo.getGlobalBounds();
    }

    sf::RectangleShape& getRetangulo() { return Retangulo; }
    void setPoint(float px, float py);
    void mover();
    void executar();
    void salvar();
};
