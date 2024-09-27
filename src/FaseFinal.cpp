#include "FaseFinal.hpp"

void FaseFinal::init()
{
	objs.push_back(new ObjetoDeJogo("YouWin",Sprite("rsc/youwin.img"),22,67));
    objs.push_back(new ObjetoDeJogo("Saturn", SpriteAnimado("rsc/saturn.anm",2),3,12));
    objs.push_back(new ObjetoDeJogo("planet", Sprite("rsc/planeta.img"),35,135));
    nave = new ObjetoDeJogo("nave", Sprite("rsc/naveH.img"),42,92);
    objs.push_back(nave);
}

unsigned FaseFinal::run(SpriteBuffer &screen)
{
	std::string ent;
	
	draw(screen);
	system("clear");
	show(screen);
	
	for (int i = 0 ; i < 15 ; i++)
	{
		getline(std::cin,ent);
		if (ent == "q")
			return Fase::END_GAME;

        if (nave->getPosL() > 0)
            nave->moveUp(3);
        else
            nave->desativarObj();
		
		update();
        screen.clear();
		draw(screen);
		system("clear");
		show(screen);
	}
	
	return Fase::END_GAME; // não necessário
}