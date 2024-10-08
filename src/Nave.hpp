#ifndef NAVE_HPP
#define NAVE_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Nave : public ObjetoDeJogo
{
public:
    Nave(const ObjetoDeJogo &obj, int life = 3, int ataque = 1) : ObjetoDeJogo(obj), life(life), ataque(ataque), item(false) {} 

    virtual ~Nave() {}

    int getLife() const { return life; }
    bool isAlive() const { return life != 0; }

    void sofrerAtaque(int ataque) { (life - ataque >= 0) ? life -= ataque : 0; }
    int atacar() const { return 1; }

    void pegarItem() {item = true;} //colocar uma quantidade de disparos para terminar o buff do item
    bool possuiItem() const { return item; }

private:
    int life;
    int ataque;
    bool item;
};
#endif
