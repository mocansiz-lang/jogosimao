#include "Claude_Easy.h"

Claude_Easy::Claude_Easy() : Inimigo(1, 1, "claude(easy)")
{
    Retangulo.setSize(sf::Vector2f(50.f, 50.f));
    Retangulo.setFillColor(sf::Color::Red);
    setPoint(900.f, 670.f);
    pFig = &Retangulo;
}

Claude_Easy::~Claude_Easy()
{
}

void Claude_Easy::setPoint(float px, float py)
{
    Entidade::setPoint(px, py);
    Retangulo.setPosition(sf::Vector2f(px, py));
}

void Claude_Easy::mover()
{
}

void Claude_Easy::executar()
{
    mover();
}

void Claude_Easy::salvar()
{
}
