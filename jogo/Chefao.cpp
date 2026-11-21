#include "Chefao.h"
#include "GerenciadorGrafico.h"

Chefao::Chefao() : Inimigo(10, 5), forca(3), emFuria(false), velX(2.0f)
{
    Retangulo.setSize(sf::Vector2f(95.f, 95.f));
    Retangulo.setFillColor(sf::Color::Magenta);
    setPoint(780.f, 110.f);
    pFig = &Retangulo;
}

Chefao::~Chefao()
{
}

void Chefao::setPoint(float px, float py)
{
    Entidade::setPoint(px, py);
    Retangulo.setPosition(sf::Vector2f(px, py));
}

void Chefao::mover()
{
    sf::Vector2f pos = Retangulo.getPosition();
    float velocidade = emFuria ? velX * 1.5f : velX;
    pos.x += velocidade;
    if (pos.x <= 0.f || pos.x + 95.f >= W_LARGURA)
    {
        velX = -velX;
        pos.x += (emFuria ? velX * 1.5f : velX);
    }
    setPoint(pos.x, pos.y);
}

void Chefao::executar()
{
    if (!emFuria && num_vidas <= 5)
    {
        emFuria = true;
        nivel_maldade += forca;
        Retangulo.setFillColor(sf::Color(255, 80, 0));
    }
    mover();
}

void Chefao::salvar()
{
}
