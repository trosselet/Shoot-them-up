#pragma once

#include "Scene.h"


class DummyEntity;
class Bullet;


class SampleScene : public Scene
{

	DummyEntity* pEntity1;
	DummyEntity* pEntity2;

	DummyEntity* pEntitySelected;
	Bullet* pBullet;

private:
	void TrySetSelectedEntity(DummyEntity* pEntity, int x, int y);

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;

	enum Tag {
		BULLET,
		ENNEMY
	};
};

