#pragma once
#include "Inimigo.h"

class Claude_Easy : public Inimigo
{
private:
    sf::RectangleShape Retangulo;

public:
    Claude_Easy();
    ~Claude_Easy();

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
