#include "Gerenciador_Colisoes.h"
#include "GerenciadorGrafico.h"
#include <algorithm>
#include <cmath>

Gerenciador_Colisoes::Gerenciador_Colisoes(Jogador* Pessoa, Inimigo* inimigos) :
    player1(Pessoa)
{
    if (inimigos != nullptr)
    {
        LIs.push_back(inimigos);
    }
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
    if (pe1 == nullptr || pe2 == nullptr)
    {
        return false;
    }
#if SFML_VERSION_MAJOR >= 3
    return pe1->getLados().findIntersection(pe2->getLados()).has_value();
#else
    return pe1->getLados().intersects(pe2->getLados());
#endif
}

void Gerenciador_Colisoes::tratarColisoesJogsObstacs()
{
}

void Gerenciador_Colisoes::tratarColisoesJogsParedes()
{
    if (player1 == nullptr)
    {
        return;
    }

    sf::FloatRect lado = player1->getCirculo().getGlobalBounds();
    sf::Vector2f pos = player1->getCirculo().getPosition();

#if SFML_VERSION_MAJOR >= 3
    float left = lado.position.x;
    float top = lado.position.y;
    float width = lado.size.x;
    float height = lado.size.y;
#else
    float left = lado.left;
    float top = lado.top;
    float width = lado.width;
    float height = lado.height;
#endif

    if (left < 0.f)
        pos.x -= left;
    if (left + width > W_LARGURA)
        pos.x -= (left + width - W_LARGURA);
    if (top < 0.f)
        pos.y -= top;
    if (top + height > W_ALTURA)
        pos.y -= (top + height - W_ALTURA);

    player1->setPoint(pos.x, pos.y);
}

void Gerenciador_Colisoes::tratarColisoesJogsInimgs()
{
    if (player1 == nullptr)
    {
        return;
    }

    for (Inimigo* inimigo : LIs)
    {
        if (inimigo != nullptr && inimigo->estaVivo() && verificarColisao(player1, inimigo))
        {
            sf::FloatRect jogRect = player1->getLados();
            sf::FloatRect inimRect = inimigo->getLados();
            sf::Vector2f pos = player1->getCirculo().getPosition();

#if SFML_VERSION_MAJOR >= 3
            float jLeft = jogRect.position.x;
            float jTop = jogRect.position.y;
            float jWidth = jogRect.size.x;
            float jHeight = jogRect.size.y;

            float iLeft = inimRect.position.x;
            float iTop = inimRect.position.y;
            float iWidth = inimRect.size.x;
            float iHeight = inimRect.size.y;
#else
            float jLeft = jogRect.left;
            float jTop = jogRect.top;
            float jWidth = jogRect.width;
            float jHeight = jogRect.height;

            float iLeft = inimRect.left;
            float iTop = inimRect.top;
            float iWidth = inimRect.width;
            float iHeight = inimRect.height;
#endif

            float jCenterX = jLeft + jWidth * 0.5f;
            float jCenterY = jTop + jHeight * 0.5f;
            float iCenterX = iLeft + iWidth * 0.5f;
            float iCenterY = iTop + iHeight * 0.5f;

            float overlapX = std::min(jLeft + jWidth, iLeft + iWidth) - std::max(jLeft, iLeft);
            float overlapY = std::min(jTop + jHeight, iTop + iHeight) - std::max(jTop, iTop);

            if (overlapX < overlapY)
            {
                if (jCenterX < iCenterX)
                    pos.x -= (overlapX + 4.f);
                else
                    pos.x += (overlapX + 4.f);
            }
            else
            {
                if (jCenterY < iCenterY)
                    pos.y -= (overlapY + 4.f);
                else
                    pos.y += (overlapY + 4.f);
            }

            player1->setPoint(pos.x, pos.y);
            tratarColisoesJogsParedes();
            inimigo->danificar(player1);
        }
    }
}

void Gerenciador_Colisoes::executar()
{
    tratarColisoesJogsParedes();
    tratarColisoesJogsInimgs();
}
