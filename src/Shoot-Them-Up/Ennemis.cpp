#include "pch.h"
#include "Ennemis.h"
#include <iostream>
void Ennemis::OnUpdate()
{
}

void Ennemis::OnCollision(Entity* collidedWith)
{
	std::cout << "OnCollision" << std::endl;
}

void Ennemis::OnInitialize()
{
}

void Ennemis::CheckWindow()
{
}
