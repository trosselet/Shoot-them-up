#include "SFMLEntity.h"

#include "GameManager.h"

template<typename T>
T* SFMLEntity::GetScene() const
{
	T* pScene = dynamic_cast<T*>(GetScene());

	_ASSERT(pScene != nullptr);

	return pScene;
}


template<typename T>
T SFMLEntity::CreateSFMLEntity(float radius, int r, int g, int b, int a)
{
	return GetScene()->CreateSFMLEntity<T>(radius, sf::Color::Color(r, g, b, a));
}

template<typename T>
T* SFMLEntity::GetPosition(float ratioX, float ratioY) const
{
	float size = mShape.getRadius() * 2;
	sf::Vector2f position = mShape.getPosition();

	position.x += size * ratioX;
	position.y += size * ratioY;

	return position;
}
