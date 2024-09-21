#ifndef FASELEVEL1_HPP
#define FASELEVEL1_HPP

#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/Fase.hpp"
#include "Nave.hpp"
#include "Monstro.hpp"

#include <list>

class FaseLevel1 : public Fase
{
public:
    FaseLevel1(std::string name, const Sprite &bkg) : Fase(name, bkg) {}
    FaseLevel1(std::string name, const SpriteAnimado & bkg) : Fase(name, bkg) {}
    virtual ~FaseLevel1() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

    //bool colideComBloco() const;

private:
    Monstro *monstros[5]; 
    Nave *naveHeroi; 
    ObjetoDeJogo *disparoNaveHeroi;
    ObjetoDeJogo *disparoMonstro;

    enum{ESQUERDA, DIREITA}; //estados de movimento dos monstros
    enum{UP, END, DOWN}; //estados de movimento dos disparos

};
#endif