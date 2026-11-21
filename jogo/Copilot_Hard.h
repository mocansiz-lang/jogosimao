#pragma once
#include "Inimigo.h"

class Copilot_Hard : public Inimigo
{
private:
    sf::RectangleShape Retangulo;
    float velX;
    float velY;

public:
    Copilot_Hard();
    ~Copilot_Hard();

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
