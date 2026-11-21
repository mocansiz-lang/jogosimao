#pragma once
#include "Inimigo.h"

class Gemini_Medium : public Inimigo
{
private:
    sf::RectangleShape Retangulo;
    float velX;

public:
    Gemini_Medium();
    ~Gemini_Medium();

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
