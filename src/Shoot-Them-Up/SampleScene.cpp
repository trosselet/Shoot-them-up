#include "pch.h"
#include "SampleScene.h"

#include "DummyEntity.h"

#include "Debug.h"

void SampleScene::OnInitialize()
{
	pSFMLEntity1 = CreateSFMLEntity<DummyEntity>(100, 255, 0, 0, 255);
	pSFMLEntity1->SetPosition(100, 100);

	pSFMLEntity2 = CreateSFMLEntity<DummyEntity>(50, 0, 255, 0, 255);
	pSFMLEntity2->SetPosition(500, 500);

	pSFMLEntitySelected = nullptr;
}

void SampleScene::OnEvent(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		TrySetSelectedSFMLEntity(pSFMLEntity1, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedSFMLEntity(pSFMLEntity2, event.mouseButton.x, event.mouseButton.y);
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (pSFMLEntitySelected != nullptr) 
		{
			pSFMLEntitySelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100.f);
		}
	}
}

void SampleScene::TrySetSelectedSFMLEntity(DummyEntity* pSFMLEntity, int x, int y)
{
	if (pSFMLEntity->IsInside(x, y) == false)
		return;

	pSFMLEntitySelected = pSFMLEntity;
}

void SampleScene::OnUpdate()
{
	if(pSFMLEntitySelected != nullptr)
	{
		sf::Vector2f position = pSFMLEntitySelected->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}
}