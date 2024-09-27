#ifndef GAME_HPP
#define GAME_HPP

#include "FaseLevel1.hpp"
#include "FaseStart.hpp"
#include "FaseFinal.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"

//g++ -std=c++17 -o game src/*.cpp src/ASCII_Engine/*.cpp src/ASCII_Engine/Core/*.cpp && ./game

class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run()
	{
		SpriteBuffer buffer(200,55);
	
		FaseStart start("FaseStart",Sprite("rsc/background.img"));
		FaseLevel1 fase1("Fase1",Sprite("rsc/background.img"));
		FaseFinal faseFinal("Fase1",Sprite("rsc/background.img"));
		
		start.init();
		start.run(buffer);

		buffer.clear();
		fase1.init();
		int ret1 = fase1.run(buffer);
		if ( ret1 != Fase::GAME_OVER && ret1 != Fase::END_GAME){
		
			buffer.clear();
			faseFinal.init();
			faseFinal.run(buffer);
		}
		else
			std::cout << "GAME OVER" << std::endl;
		
		std::cout << "Saindo..." << std::endl;
	}

};
#endif