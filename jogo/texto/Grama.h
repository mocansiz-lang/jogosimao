#pragma once
#include "Obstaculo.h"

class Grama : public Obstaculo
{
    private:
        int altura;
        sf::RectangleShape Chao;

    public:
        Grama();
        ~Grama();
        void executar();
        void salvar();

        void obstaculizar(Jogador* p);

        sf::FloatRect getLados()
        {
            return Chao.getGlobalBounds();
        }
        sf::RectangleShape& getRetangulo() { return Chao; }

};
