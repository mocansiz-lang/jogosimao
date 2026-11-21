#pragma once
#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Inim_Facil.h"
#include "Inim_Medio.h"
#include "Inim_Dificil.h"
#include "Chefao.h"
#include "Gerenciador_Colisoes.h"
#include "Menu.h"
#include <string>

class Jogo
{
private:
    GerenciadorGrafico GG;
    Jogador jogador;
    Inim_Facil inimigo;
    Inim_Medio inimigoMedio;
    Inim_Dificil inimigoDificil;
    Chefao chefao;
    Gerenciador_Colisoes GC;
    Menu menu;
    bool menua;
    sf::Font fonte;
    bool fonteCarregada;

    void desenharVida(Personagem* p, const std::string& nome);

public:
    Jogo();
    ~Jogo();
    void executar();
    void iniciar();
    void menub();
};
