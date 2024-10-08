#pragma once

#include "..\Being.h"

#define GRAVITY 70.0f

namespace Entities
{
	class Entity : public Being
	{
	protected:
		bool grounded;
		bool active;

		sf::Vector2f size;
		sf::Vector2f pos;
		sf::Vector2f vel;
		sf::RectangleShape body;

		static float deltaTime;

	public:
		Entity(sf::Vector2f size, bID id_);
		~Entity();

		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void Move() = 0;

		virtual void save() = 0;

		void Gravity();
		void ThrustForce();

		static void updateDeltaTime(const float dt);

		const sf::RectangleShape* getBody();
		const sf::Vector2f getPosition(const bool collision = false)const;
		const sf::Vector2f getSize()const;

		void setActive(const bool b);
		const bool getActive()const;
	};
}