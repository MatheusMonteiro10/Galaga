#ifndef MONSTRO_HPP
#define MONSTRO_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include <cstdlib>

//assistir aula 7

class Monstro : public ObjetoDeJogo
{
public:
    Monstro(const ObjetoDeJogo &obj, int life = 1, int ataque = 1) : ObjetoDeJogo(obj), ataque(ataque), life(life) {}
    virtual ~Monstro() {}; 

    int getLife() const {return life;}
    bool isAlive() const {return life != 0;}

    void sofrerAtaque(int ataque) { (life - ataque >= 0) ? life - ataque : 0; }
    int atacar() const 
    { 
        int chance = rand() % 10;
        if (chance < 7)
            return 0;
        return 1; 
    }

private:
    int ataque;
    int life;
};
#endif
