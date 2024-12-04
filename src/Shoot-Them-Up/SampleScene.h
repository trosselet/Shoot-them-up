#pragma once

#include "Scene.h"


class DummyEntity;
class Player;
class Ennemis;
class Projectile;

class SampleScene : public Scene
{
    Player* pPlayer;
	Ennemis* pEntity2;
	Projectile* pProjectile;
	

private:
	//void TrySetSelectedEntity(Entity* pEntity, int x, int y);

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;

	enum Tag 
	{
		ENNEMY,
		BULLET,
	};

};


