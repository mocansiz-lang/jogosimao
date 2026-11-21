#pragma once
#include "Inimigo.h"

class Inim_Dificil : public Inimigo
{
private:
    sf::RectangleShape Retangulo;
    float velX;
    float velY;

public:
    Inim_Dificil();
    ~Inim_Dificil();

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
