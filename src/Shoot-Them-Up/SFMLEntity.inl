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
T* SFMLEntity::GetShape()
{
	static_assert(std::is_same<T, sf::CircleShape>::value, "Unsupported shape type");
	return &mShape;
}

template<typename T>
T SFMLEntity::CreateSFMLEntity(float radius, int r, int g, int b, int a)
{
	return GetScene()->CreateSFMLEntity<T>(radius, sf::Color::Color(r, g, b, a));
}