#include "Copilot_Hard.h"
#include "GerenciadorGrafico.h"

Copilot_Hard::Copilot_Hard() : Inimigo(5, 3, "copilot(hard)"), velX(2.5f), velY(1.5f)
{
    Retangulo.setSize(sf::Vector2f(70.f, 70.f));
    Retangulo.setFillColor(sf::Color::Cyan);
    setPoint(250.f, 260.f);
    pFig = &Retangulo;
}

Copilot_Hard::~Copilot_Hard()
{
}

void Copilot_Hard::setPoint(float px, float py)
{
    Entidade::setPoint(px, py);
    Retangulo.setPosition(sf::Vector2f(px, py));
}

void Copilot_Hard::mover()
{
    sf::Vector2f pos = Retangulo.getPosition();
    pos.x += velX;
    pos.y += velY;

    if (pos.x <= 0.f || pos.x + 70.f >= W_LARGURA)
    {
        velX = -velX;
        pos.x += velX;
    }
    if (pos.y <= 0.f || pos.y + 70.f >= W_ALTURA)
    {
        velY = -velY;
        pos.y += velY;
    }
    setPoint(pos.x, pos.y);
}

void Copilot_Hard::executar()
{
    mover();
}

void Copilot_Hard::salvar()
{
}
