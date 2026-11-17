#include "Inim_Medio.h"

Inim_Medio::Inim_Medio() :
    Inimigo(3, 2), // 3 de vida, 2 de nivel_maldade
    tamanho(65),
    velX(-2.5f),
    velY(0.f),
    noChao(true)
{
    Retangulo.setSize(sf::Vector2f(static_cast<float>(tamanho), static_cast<float>(tamanho)));
    Retangulo.setFillColor(sf::Color::Yellow);
    Retangulo.setPosition(600.f, static_cast<float>(W_ALTURA - tamanho));
    x = 600;
    y = W_ALTURA - tamanho;
    pFig = &Retangulo;
}

Inim_Medio::~Inim_Medio()
{
}

void Inim_Medio::mover()
{
    sf::Vector2f pos = Retangulo.getPosition();

    // Movimento horizontal escalado pelo nivel_maldade
    pos.x += velX * (0.5f * nivel_maldade);
    if (pos.x < 350.f || pos.x + tamanho > W_LARGURA)
        velX = -velX;

    // Salto periódico do Inimigo Médio
    if (noChao)
    {
        velY = -10.f;
        noChao = false;
    }

    velY += 0.4f; // Gravidade
    pos.y += velY;

    if (pos.y + tamanho >= W_ALTURA)
    {
        pos.y = static_cast<float>(W_ALTURA - tamanho);
        velY = 0.f;
        noChao = true;
    }

    Retangulo.setPosition(pos);
}

void Inim_Medio::executar()
{
    if (estaVivo())
        mover();
}

void Inim_Medio::salvar()
{
}