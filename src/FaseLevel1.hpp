#ifndef FASELEVEL_HPP
#define FASELEVEL_HPP

#include "NaveInimiga.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/Fase.hpp"
#include "Nave.hpp"

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
    //NaveInimiga *naveInimiga[4]; 
    Nave *naveHeroi; 

};
#endif