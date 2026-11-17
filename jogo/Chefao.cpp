#include "Chefao.h"
#include "Jogador.h"

Chefao::Chefao() :
    Inimigo(10, 5), // 10 de vida, 5 de nivel_maldade
    forca(3),
    velX(-1.5f)
{
    Retangulo.setSize(sf::Vector2f(90.f, 90.f));
    Retangulo.setFillColor(sf::Color::Magenta);
    Retangulo.setPosition(850.f, static_cast<float>(W_ALTURA - 90));
    x = 850;
    y = W_ALTURA - 90;
    pFig = &Retangulo;
}

Chefao::~Chefao()
{
}

void Chefao::mover()
{
    // Modo fúria: se a vida cair pela metade, aumenta a maldade
    if (num_vidas <= 5 && nivel_maldade < 8)
        nivel_maldade = 8;

    sf::Vector2f pos = Retangulo.getPosition();
    pos.x += velX * (0.4f * nivel_maldade);

    if (pos.x < 500.f || pos.x + 90.f > W_LARGURA)
        velX = -velX;

    Retangulo.setPosition(pos);
}

void Chefao::danificar(Jogador* pJog)
{
    if (pJog && estaVivo())
    {
        // Dano do chefão soma o nivel_maldade com a forca
        pJog->tomarDano(nivel_maldade + forca);
    }
}

void Chefao::executar()
{
    if (estaVivo())
        mover();
}

void Chefao::salvar()
{
}