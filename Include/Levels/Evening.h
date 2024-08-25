#pragma once

#include "Level.h"
#include "..\Entities\Characters\Enemies\Scorpion.h"
using namespace Enemies;

namespace Levels
{
	class Evening : public Level
	{
	private:
		
	public:
		Evening(StateMachine* psm);
		~Evening();

		std::string getFileName();

		void Update();
		void Reset();

		void CreateEntity(char id, sf::Vector2f pos);
		void CreateScorpion(sf::Vector2f pos);
		void CreateNest(sf::Vector2f pos);
	};
}
