#pragma once

#include <list>

class SFMLEntity;
class Scene;
class Debug;

namespace sf 
{
	class RenderWindow;
	class Event;
}

class GameManager : public IGraphicEngine
{
	std::list<SFMLEntity*> mEntities;
	std::list<SFMLEntity*> mEntitiesToDestroy;
	std::list<SFMLEntity*> mEntitiesToAdd;

	sf::RenderWindow* mpWindow;
	sf::Font mFont;

	Scene* mpScene;

	float mDeltaTime;

	int mWindowWidth;
	int mWindowHeight;

private:
	GameManager();

	void Run() override;
	
	void HandleInput() override;
	void Update();
	void Draw() override;

	void SetDeltaTime(float deltaTime) { mDeltaTime = deltaTime; }

	sf::RenderWindow* GetWindow() const { return mpWindow; }

public:
	~GameManager();
	static GameManager* Get();

	void Initialize(unsigned int width, unsigned int height, const std::string& title) override;

	template<typename T>
	void LaunchScene();

	float GetDeltaTime() const { return mDeltaTime; }
	Scene* GetScene() const { return mpScene; }
	sf::Font& GetFont() { return mFont; };

	friend Debug;
	friend Scene;
};

#include "GameManager.inl"