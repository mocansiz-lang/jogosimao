#pragma once
#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Inim_Facil.h"
#include "Inim_Medio.h"
#include "Chefao.h"
#include "Gerenciador_Colisoes.h"
#include "Menu.h"

class Jogo
{
private:
    GerenciadorGrafico GG;
    Jogador jogador;
    Inim_Facil inimigo;
    Inim_Medio inimigoMedio;
    Chefao chefao;
    Gerenciador_Colisoes GC;
    Menu menu;
    bool menua;


public:
    Jogo();
    ~Jogo();
    void executar();
    void iniciar();
    void menub();


};