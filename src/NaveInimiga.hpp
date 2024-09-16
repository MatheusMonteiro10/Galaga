/*
#ifndef NAVEINIMIGA_HPP
#define NAVEINIMIGA_HPP

#include "ObjetoDeJogo.hpp"

class NaveInimiga : public ObjetoDeJogo //herda de Inimigo ou objJogo?
{
public:
    NaveInimiga(const ObjetoDeJogo &obj, int life = 1, int ataque = 1) : ObjetoDeJogo(obj), life(life), ataque(ataque), item(false) {} 

    int getLife() const { return life; }
    bool isAlive() const { return life != 0; }

    void sofrerAtaque(int ataque) { (life - ataque >= 0) ? life - ataque : 0; }
    int atacar() const { return 1; }

private:
    int life;
    int ataque;
    bool item;
};
#endif
*/