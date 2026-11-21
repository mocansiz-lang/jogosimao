#include "Inim_Medio.h"
#include "GerenciadorGrafico.h"

Inim_Medio::Inim_Medio() : Inimigo(3, 2), velX(1.5f)
{
    Retangulo.setSize(sf::Vector2f(60.f, 60.f));
    Retangulo.setFillColor(sf::Color::Yellow);
    setPoint(550.f, 450.f);
    pFig = &Retangulo;
}

Inim_Medio::~Inim_Medio()
{
}

void Inim_Medio::setPoint(float px, float py)
{
    Entidade::setPoint(px, py);
    Retangulo.setPosition(sf::Vector2f(px, py));
}

void Inim_Medio::mover()
{
    sf::Vector2f pos = Retangulo.getPosition();
    pos.x += velX;
    if (pos.x <= 0.f || pos.x + 60.f >= W_LARGURA)
    {
        velX = -velX;
        pos.x += velX;
    }
    setPoint(pos.x, pos.y);
}

void Inim_Medio::executar()
{
    mover();
}

void Inim_Medio::salvar()
{
}
