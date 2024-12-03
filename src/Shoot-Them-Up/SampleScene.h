#pragma once

#include "Scene.h"

class DummyEntity;

class SampleScene : public Scene
{
	DummyEntity* pSFMLEntity1;
	DummyEntity* pSFMLEntity2;

	DummyEntity* pSFMLEntitySelected;

private:
	void TrySetSelectedSFMLEntity(DummyEntity* pSFMLEntity, int x, int y);

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;
};


