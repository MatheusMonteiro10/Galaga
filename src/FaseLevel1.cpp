#include "FaseLevel1.hpp"
#include "NaveInimiga.hpp"
#include "ASCII_Engine/Core/SpriteBase.hpp"
#include "ASCII_Engine/Core/ColorHandler.hpp"

#include <iostream>

void FaseLevel1::init()
{
    naveHeroi = new Nave(ObjetoDeJogo("NaveHeroi",SpriteAnimado("rsc/NaveHeroi.txt",2),39,108));
    objs.push_back(naveHeroi);
}

unsigned FaseLevel1::run(SpriteBuffer &screen)
{
    std::string ent;

    draw(screen);
    system("clear");
    show(screen);

    while(true)
    {
        getline(std::cin,ent);

        int posL = naveHeroi->getPosL(), posC = naveHeroi->getPosC();

        if (ent == "w" && naveHeroi->getPosL() > 10)
            naveHeroi->moveUp(3);
        else if (ent == "s" && naveHeroi->getPosL() < screen.getAltura() - 15)
            naveHeroi->moveDown(3);
        else if (ent == "a" && naveHeroi->getPosC() > 12)
            naveHeroi->moveLeft(3);
        else if (ent == "d" && naveHeroi->getPosC() < screen.getLarguraMax() - naveHeroi->getSprite()->getLarguraMax() - 13)
            naveHeroi->moveRight(3);

        update();
        draw(screen);
        system("clear");
        show(screen);
    }
}