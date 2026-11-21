#pragma once
#include "Inimigo.h"

class Fable_Boss : public Inimigo
{
private:
    sf::RectangleShape Retangulo;
    int forca;
    bool emFuria;
    float velX;

public:
    Fable_Boss();
    ~Fable_Boss();

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
