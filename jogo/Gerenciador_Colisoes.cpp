#include "Gerenciador_Colisoes.h"

Gerenciador_Colisoes::Gerenciador_Colisoes(Jogador* Pessoa) :
    player1(Pessoa), LIs()
{
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
    LIs.clear();
}

void Gerenciador_Colisoes::incluirInimigo(Inimigo* pi)
{
    if (pi != nullptr)
    {
        LIs.push_back(pi);
    }
}

bool Gerenciador_Colisoes::verificarColisao(Entidade* pe1, Entidade* pe2) const
{
    return pe1->getLados().intersects(pe2->getLados());
}

void Gerenciador_Colisoes::tratarColisoesJogsObstacs()
{
}

void Gerenciador_Colisoes::tratarColisoesJogsParedes()
{
    sf::FloatRect lado = player1->getCirculo().getGlobalBounds();
    sf::Vector2f pos = player1->getCirculo().getPosition();

    if (lado.left < 0)
        pos.x -= lado.left;
    if (lado.left + lado.width > W_LARGURA)
        pos.x -= (lado.left + lado.width - W_LARGURA);
    if (lado.top < 0)
        pos.y -= lado.top;
    if (lado.top + lado.height > W_ALTURA)
        pos.y -= (lado.top + lado.height - W_ALTURA);

    player1->getCirculo().setPosition(pos);
}

void Gerenciador_Colisoes::tratarColisoesJogsInimgs()
{
    for (size_t i = 0; i < LIs.size(); i++)
    {
        Inimigo* inim = LIs[i];
        if (inim && inim->estaVivo() && verificarColisao(player1, inim))
        {
            sf::Vector2f pos = player1->getCirculo().getPosition();
            sf::FloatRect caixaInim = inim->getLados();

            // Se o jogador cair por cima do inimigo, tira vida do inimigo
            if (pos.y + player1->getLados().height <= caixaInim.top + 15.f)
            {
                inim->tomarDano(1);
                pos.y = caixaInim.top - player1->getLados().height - 5.f;
            }
            else
            {
                // Colisão lateral: inimigo danifica o jogador usando seu nivel_maldade
                inim->danificar(player1);

                if (pos.x < caixaInim.left)
                    pos.x -= 25.f * inim->getNivelMaldade();
                else
                    pos.x += 25.f * inim->getNivelMaldade();
            }

            player1->getCirculo().setPosition(pos);
        }
    }
}

void Gerenciador_Colisoes::executar()
{
    tratarColisoesJogsParedes();
    tratarColisoesJogsInimgs();
}