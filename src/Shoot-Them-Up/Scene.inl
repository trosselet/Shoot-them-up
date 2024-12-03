	#pragma once

#include "Scene.h"
#include "GameManager.h"
#include "SFMLEntity.h"

template<typename T>
T* Scene::CreateSFMLEntity(float radius, int r, int g, int b, int a)
{
	static_assert(std::is_base_of<SFMLEntity, T>::value, "T must be derived from SFMLEntity");

	T* newSFMLEntity = new T();

	SFMLEntity* SFMLEntity = newSFMLEntity;
	SFMLEntity->Initialize(radius, r, g, b, a);
	
	mpGameManager->mEntitiesToAdd.push_back(newSFMLEntity);

	return newSFMLEntity;
}
