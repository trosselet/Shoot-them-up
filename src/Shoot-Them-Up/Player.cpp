#include "pch.h"
#include "Player.h"
#include <iostream>

void Player::OnUpdate()
{
}

void Player::OnCollision(Entity* collidedWith)
{

	std::cout << "OnCollision" << std::endl;
}

void Player::OnInitialize()
{
}

void Player::CheckWindow()
{


}

float Player::GetSpeed()
{
	return mSpeed;
}
