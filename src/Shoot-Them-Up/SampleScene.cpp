#include "pch.h"
#include "SampleScene.h"

#include "DummyEntity.h"
#include "Player.h"
#include "Projectile.h"
#include "Debug.h"
#include "Ennemis.h"
#include <iostream>

void SampleScene::OnInitialize()
{
	pPlayer = CreateEntity<Player>(70, sf::Color::Red);
	pPlayer->SetPosition(100, 100);
	pPlayer->SetSpeed(200.f);

	pEntity2 = CreateEntity<Ennemis>(50, sf::Color::Green);
	pEntity2->SetPosition(500, 500);



}

void SampleScene::OnEvent(const sf::Event& event)
{
	//if (event.type != sf::Event::EventType::MouseButtonPressed)
		//return;


	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Z: // Haut
			pPlayer->SetDirection(0.f, -1.f, pPlayer->GetSpeed()); // Direction vers le haut
			break;
		case sf::Keyboard::S: // Bas
			pPlayer->SetDirection(0.f, 1.f, pPlayer->GetSpeed()); // Direction vers le bas
			break;
		case sf::Keyboard::Q: // Gauche
			pPlayer->SetDirection(-1.f, 0.f, pPlayer->GetSpeed()); // Direction vers la gauche
			break;
		case sf::Keyboard::D: // Droite
			pPlayer->SetDirection(1.f, 0.f, pPlayer->GetSpeed()); // Direction vers la droite
			break;
		default:
			break;
		}
	}
	
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Space)
		{
			pProjectile = CreateEntity<Projectile>(20, sf::Color::Yellow);
			pProjectile->SetPosition(100, 100);
			pProjectile->SetTag(BULLET);
		}
	}
	/*
	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (pEntitySelected != nullptr)
		{
			pEntitySelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100.f);
		}
	}
	*/
}
/*
void SampleScene::TrySetSelectedEntity(Entity* pEntity, int x, int y)
{
	if (pEntity->IsInside(x, y) == false)
		return;

	pEntitySelected = pEntity;
}
*/
void SampleScene::OnUpdate()
{
	if (pPlayer != nullptr)
	{
		sf::Vector2f position = pPlayer->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}





}