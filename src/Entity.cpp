#include "..\Include\Entities\Entity.h"
using namespace Entities;

Entity::Entity(sf::Vector2f size, bID id_) : Being(id_),
	active(true),
	size(size),
	body(size),
	vel(300.f,300.f)
{

}
Entity::~Entity()
{

}

void Entity::Gravity()
{
	vel.y += GRAVITY * deltaTime;
}

const sf::RectangleShape* Entity::getBody()
{
	return &body;
}

const sf::Vector2f Entity::getPosition()const
{
	return pos;
}

void Entity::updateDeltaTime(const float dt)
{
	deltaTime = dt;
}

void Entity::setActive(const bool b)
{
	active = b;
}

const bool Entity::getActive()const
{
	return active;
}
float Entity::deltaTime(0);