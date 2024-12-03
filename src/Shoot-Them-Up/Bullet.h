#pragma once
#include "Entity.h"
class Bullet : public Entity
{
//create class bullet
public: 
	void OnCollision(Entity* other) override;
	void position(int x, int y, float speed);
	void OnInitialize(float x, float y, float speed = -1.f) ;

};

