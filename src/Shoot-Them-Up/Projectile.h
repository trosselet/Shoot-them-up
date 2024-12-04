#pragma once
#include "Entity.h"


class Projectile : public Entity
{

	int mDamage;


public:

	virtual void OnUpdate() override;
	virtual void OnCollision(Entity* collidedWith) override;
	virtual void OnInitialize() override;
	void CheckWindow();


};

