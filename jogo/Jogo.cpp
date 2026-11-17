#include "Jogo.h"
#include "Inim_Facil.h"
#include "Inim_Medio.h"
#include "Chefao.h"

Jogo::Jogo() :
    GG(),
    pJog1(new Jogador()),
    pInimFacil(new Inim_Facil()),
    pInimMedio(new Inim_Medio()),
    pChefao(new Chefao()),
    GC(pJog1, pInimFacil)
{
    Ente::setGG(&GG);
    executar();
}

Jogo::~Jogo()
{
    if (pJog1) delete pJog1;
    if (pInimFacil) delete pInimFacil;
    if (pInimMedio) delete pInimMedio;
    if (pChefao) delete pChefao;
}

void Jogo::executar()
{
    while (GG.getWindow()->isOpen())
    {
        sf::Event event;
        while (GG.getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                GG.getWindow()->close();
        }

        GG.getWindow()->clear();

        pJog1->executar();
        pInimFacil->executar();
        pInimMedio->executar();
        pChefao->executar();

        GC.executar();

        pJog1->desenhar();
        pInimFacil->desenhar();
        pInimMedio->desenhar();
        pChefao->desenhar();

        GG.getWindow()->display();
    }
}