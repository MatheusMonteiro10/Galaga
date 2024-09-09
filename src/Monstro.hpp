#ifndef MONSTRO_HPP
#define MONSTRO_HPP

#include "ObjetoDeJogo.hpp"

class Monstro : public ObjetoDeJogo
{
public:
    Monstro(const ObjetoDeJogo &obj, int life = 1) : ObjetoDeJogo(obj), life(life) {} 

    int getLife() const {return life;}
    bool isAlive() const {return life != 0;}
    void sofrerAtaque(int ataque) { (life - ataque >= 0) ? life - ataque : 0; }


private:
    int life;

};
#endif