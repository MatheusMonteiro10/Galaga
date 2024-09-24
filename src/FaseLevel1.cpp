#include "ASCII_Engine/Core/SpriteBase.hpp" //->getLarguraMax()
#include "FaseLevel1.hpp"

#include <iostream>

void FaseLevel1::init()
{
    naveHeroi = new Nave(ObjetoDeJogo("NaveHeroi", Sprite("rsc/naveH.img"), 42, 92));
    objs.push_back(naveHeroi);

    monstros[0] = new Monstro(ObjetoDeJogo("Monstro1", Sprite("rsc/monstro.img"), 12, 55));
    objs.push_back(monstros[0]);

    monstros[1] = new Monstro(ObjetoDeJogo("Monstro2", Sprite("rsc/monstro.img"), 12, 69));
    objs.push_back(monstros[1]);

    monstros[2] = new Monstro(ObjetoDeJogo("Monstro3", Sprite("rsc/monstro.img"), 12, 83));
    objs.push_back(monstros[2]);

    monstros[3] = new Monstro(ObjetoDeJogo("Monstro4", Sprite("rsc/monstro.img"), 12, 97));
    objs.push_back(monstros[3]);

    monstros[4] = new Monstro(ObjetoDeJogo("Monstro5", Sprite("rsc/monstro.img"), 12, 111));
    objs.push_back(monstros[4]);

    disparoNaveHeroi = nullptr; // Inicializa o disparo como nulo

    for (int i = 0; i < 5; i++){
        disparoMonstro[i] = nullptr;
    }
}

unsigned FaseLevel1::run(SpriteBuffer &screen)
{
    std::string ent;

    int stateMonstros = DIREITA;
    int stateDisparo = END;
    int stateDisparoMonstros[5] = {END,END,END,END,END};

    system("clear");
    draw(screen);
    show(screen);

    while (true)
    {
        getline(std::cin, ent);

        int posL = naveHeroi->getPosL(), posC = naveHeroi->getPosC();

        if (ent == "q")
            return Fase::END_GAME;
        else if (ent == "a" && naveHeroi->getPosC() > 9)
            naveHeroi->moveLeft(3);
        else if (ent == "d" && naveHeroi->getPosC() < screen.getLarguraMax() - naveHeroi->getSprite()->getLarguraMax())
            naveHeroi->moveRight(3);
        else if (ent == "x")
        {
            if (disparoNaveHeroi == nullptr || stateDisparo == END)
            {
                disparoNaveHeroi = new ObjetoDeJogo("DisparoNaveHeroi", Sprite("rsc/disparoNaveHero.img"),naveHeroi->getPosL()+1,naveHeroi->getPosC()+6);
                objs.push_back(disparoNaveHeroi);
                stateDisparo = UP;
            }
        }

        // Se já existe um disparo ativo verifica se colide com algum dos monstros
        if (disparoNaveHeroi != nullptr){
            for (int m = 0; m < 5; m++){
                if (disparoNaveHeroi->colideCom(*monstros[m])){
                    monstros[m]->sofrerAtaque(1);
                    if (!monstros[m]->isAlive())
                        monstros[m]->desativarObj();
                    stateDisparo = END;

                    bool todosMortos = true; // Assume que todos estão mortos
                    for (int i = 0; i < 5; i++) {
                        if (monstros[i]->isAlive()) {
                            todosMortos = false; // Se encontrar algum vivo, muda para false
                            break; // Não precisa continuar verificando, sai do loop
                        }
                    }
                }
            }
        }

        // Se o estado do disparo é UP, ele continua até atingir o topo da tela
        if (stateDisparo == UP)
        {
            if (disparoNaveHeroi->getPosL() > 0)
                disparoNaveHeroi->moveUp(3);
            else
                stateDisparo = END;
        }

        // Se o disparo acabou, ele é desativado
        if (stateDisparo == END && disparoNaveHeroi != nullptr)
        {
            disparoNaveHeroi->desativarObj();
            disparoNaveHeroi = nullptr;
        }     

        // Disparos dos monstros
        for (int i = 0; i < 5; i++){
            if (monstros[i]->isAlive() && monstros[i]->atacar() == 1 && (disparoMonstro[i] == nullptr)){
                disparoMonstro[i] = new ObjetoDeJogo("DisparoMonstro", Sprite("rsc/disparoMonstroInimigo.img"),monstros[i]->getPosL() - 1, monstros[i]->getPosC() + 6);
                objs.push_back(disparoMonstro[i]);
                stateDisparoMonstros[i] = DOWN;
            }

            if (stateDisparoMonstros[i] == DOWN) {
                if (disparoMonstro[i]->getPosL() < 55)
                    disparoMonstro[i]->moveDown(3);
                else
                    stateDisparoMonstros[i] = END;
            }

            if (disparoMonstro[i] != nullptr && disparoMonstro[i]->colideCom(*naveHeroi)) {
                naveHeroi->sofrerAtaque(1);
                stateDisparoMonstros[i] = END;
                if (!naveHeroi->isAlive()){
                    naveHeroi->desativarObj();
                    return Fase::END_GAME;
                }
                    
            }

            if (stateDisparoMonstros[i] == END && disparoMonstro[i] != nullptr) {
                disparoMonstro[i]->desativarObj();
                disparoMonstro[i] = nullptr;
            }
        }

        // Movimento dos monstros
        int posUltimo = 4, posPrimeiro = 0;

        // Encontrar o último e o primeiro monstro vivos
        while (posUltimo >= 0 && !monstros[posUltimo]->isAlive()) {
            posUltimo--;
        }

        while (posPrimeiro < 5 && !monstros[posPrimeiro]->isAlive()) {
            posPrimeiro++;
        }

        switch (stateMonstros)
        {
        case DIREITA:
            if (posUltimo >= 0 && monstros[posUltimo]->getPosC() < screen.getLarguraMax() - monstros[posUltimo]->getSprite()->getLarguraMax()) {
                for (int i = posPrimeiro; i <= posUltimo; i++) {
                    if (monstros[i] != nullptr && monstros[i]->isAlive())
                        monstros[i]->moveRight(3);
                }
            } else {
                stateMonstros = ESQUERDA;
            }
            break;

        case ESQUERDA:
            if (posPrimeiro < 5 && monstros[posPrimeiro]->getPosC() > 9) {
                for (int i = posUltimo; i >= posPrimeiro; i--) {
                    if (monstros[i] != nullptr && monstros[i]->isAlive())
                        monstros[i]->moveLeft(3);
                }
            } else {
                stateMonstros = DIREITA;
            }
            break;
        }

        update();
        screen.clear();
        draw(screen);
        system("clear");
        show(screen);
    }
}
