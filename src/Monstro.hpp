#ifndef MONSTRO_HPP
#define MONSTRO_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include <random>

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
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<> distrib(0, 99);

        int random_value = distrib(gen); 

            if (random_value == 10)
                return 1;
            else 
                return 0;         
    }

private:
    int ataque;
    int life;
};
#endif
