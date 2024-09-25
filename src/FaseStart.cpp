#include "FaseStart.hpp"

void FaseStart::init()
{
    objs.push_back(new ObjetoDeJogo("planet", Sprite("rsc/galaga.img"),18,72));
    objs.push_back(new ObjetoDeJogo("text", TextSprite("PRESSIONE QUALQUER TECLA PARA INICIAR"),37, 76));
}

unsigned FaseStart::run(SpriteBuffer &screen)
{
	std::string ent;
	
	//padrão
	draw(screen);
	system("clear");
	show(screen);
	
		//lendo entrada
		getline(std::cin,ent);
		if (ent == "q")
			return Fase::END_GAME;

        else
            Fase::LEVEL_COMPLETE;
		
		//padrão
		update();
		draw(screen);
		system("clear");
		show(screen);

    return Fase::END_GAME;
}