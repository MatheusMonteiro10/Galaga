#include "FaseLevel1.hpp"

#include "NaveInimiga.hpp"

#include <iostream>

void FaseLevel1::init()
{
    naveHeroi = new Nave("NaveHeroi", SpriteAnimado("rsc/NaveHeroi.txt"), 2, 20, 20);
}