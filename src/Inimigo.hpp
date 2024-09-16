/*
#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "ObjetoDeJogo.hpp"

class Inimigo : public ObjetoDeJogo
{
public:
    Inimigo(const ObjetoDeJogo &obj, int life = 1) : ObjetoDeJogo(obj), life(life) {} 

    int getLife() const {return life;}
    bool isAlive() const {return life != 0;}
    void sofrerAtaque(int ataque) { (life - ataque >= 0) ? life - ataque : 0; }


private:
    int life;

};
#endif
*/