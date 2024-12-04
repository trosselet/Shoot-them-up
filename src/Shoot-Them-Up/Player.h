#pragma once
#include "Entity.h"

class Player : public Entity
{

public:


	void OnUpdate() override;
	void OnCollision(Entity* collidedWith) override;
    void OnInitialize() override;
	void CheckWindow() override;
	float GetSpeed();
	
};

