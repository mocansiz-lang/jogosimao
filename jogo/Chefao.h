#pragma once
#include "Inimigo.h"

class Chefao : public Inimigo
{
private:
    sf::RectangleShape Retangulo;
    int forca;
    bool emFuria;
    float velX;

public:
    Chefao();
    ~Chefao();

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
