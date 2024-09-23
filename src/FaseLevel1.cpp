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
    int posUltimo = 4;

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

        //Se já existe um disparo ativo verifica se colide com algum dos monstros
        //Se colide com algum monstro, disparo muda de estado para END e o monstro é desativado
        if (disparoNaveHeroi != nullptr){
            for (int m = 0; m < 5; m++){
                if (disparoNaveHeroi->colideCom(*monstros[m])){
                    monstros[m]->sofrerAtaque(naveHeroi->atacar());
                    stateDisparo = END;
                    if (!monstros[m]->isAlive())
                        monstros[m]->desativarObj();
                }
            }
        }

        //Se o estado do disparo é UP ele continua até atingir o topo da tela
        if (stateDisparo == UP)
        {
            if (disparoNaveHeroi->getPosL() > 0)
                disparoNaveHeroi->moveUp(3);
            else
                stateDisparo = END;
        }

        //Se o estado do disparo é END e existe um disparo ativo
        //Disparo é desativado e setado como null para liberar um novo disparo
        if (stateDisparo == END && disparoNaveHeroi != nullptr)
        {
            disparoNaveHeroi->desativarObj();
            disparoNaveHeroi = nullptr;
        }     

        //Se o método ataque funcionar e não existir um disparo ativo é criado um novo disparo
        for (int i = 0; i < 5; i++){
            if (monstros[i]->atacar() == 1 && (disparoMonstro[i] == nullptr)){
                disparoMonstro[i] = new ObjetoDeJogo("DisparoMonstro", Sprite("rsc/disparoMonstroInimigo.img"),monstros[i]->getPosL() - 1, monstros[i]->getPosC() + 6);
                objs.push_back(disparoMonstro[i]);
                stateDisparoMonstros[i] = DOWN;
            }

            // Movimenta o disparo do monstro se ativo
            if (stateDisparoMonstros[i] == DOWN) {
                if (disparoMonstro[i]->getPosL() < 55)
                    disparoMonstro[i]->moveDown(3);
                else
                    stateDisparoMonstros[i] = END;
            }

            if (disparoMonstro[i] != nullptr && disparoMonstro[i]->colideCom(*naveHeroi)) {
                naveHeroi->sofrerAtaque(monstros[i]->atacar());
                stateDisparoMonstros[i] = END;
            }

            // Se o disparo acabou, remove o objeto
            if (stateDisparoMonstros[i] == END && disparoMonstro[i] != nullptr) {
                disparoMonstro[i]->desativarObj();
                disparoMonstro[i] = nullptr;
            }
        }
        switch (stateMonstros)
        {
            //somente apos a verificação do monstro mais a direita a logica de movimento pode funcionar
            //if (!monstro[4]->isAlive()) se o monstro mais a direita nao esta vivo
            //a logica da movimentação deve desconsiderar ele e passar para monstro[n-1]
            /*
            for (int i = 4; i >= 0; i--){
                if (!monstros[i]->isAlive())
                    posUltimo = i;
            }
            */
        case DIREITA:           
            if (monstros[posUltimo]->getPosC() < screen.getLarguraMax() - monstros[posUltimo]->getSprite()->getLarguraMax())
            {
                monstros[4]->moveRight(3);
                monstros[3]->moveRight(3);
                monstros[2]->moveRight(3);
                monstros[1]->moveRight(3);
                monstros[0]->moveRight(3);
            }
            else
                stateMonstros = ESQUERDA;
            break;

        case ESQUERDA:
            if (monstros[0]->getPosC() > 9)
            {
                monstros[0]->moveLeft(3);
                monstros[1]->moveLeft(3);
                monstros[2]->moveLeft(3);
                monstros[3]->moveLeft(3);
                monstros[4]->moveLeft(3);
            }
            else
                stateMonstros = DIREITA;
            break;
        }

        update();
        draw(screen);
        system("clear");
        show(screen);
    }
}