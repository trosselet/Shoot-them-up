#include "pch.h"
#include "DummyEntity.h"

#include <iostream>

void DummyEntity::OnCollision(SFMLEntity* other)
{
	std::cout << "DummyEntity::OnCollision" << std::endl;
}