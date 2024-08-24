#include <cmath>
#include "..\Include\Entities\Characters\Enemies\Scorpion.h"
using namespace Entities;
using namespace Characters;
using namespace Enemies;

Scorpion::Scorpion(sf::Vector2f position) : Enemy(),
origin(position),
facingRight(true),
range(160.0f),
dist(0.0f)
{
	pos = position;
	body.setFillColor(sf::Color::Cyan);
}

Scorpion::~Scorpion()
{

}

void Scorpion::Move()
{
	if (facingRight)
		pos.x += vel.x;
	else
		pos.x -= vel.x;
	dist = std::fabs(pos.x - origin.x);
}

void Scorpion::Update()
{
	body.setPosition(pos);
	if (dist >= range)
		facingRight = (!facingRight);
	Move();
}

void Scorpion::Draw()
{
	pGM->render(&body);
}
