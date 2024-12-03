#pragma once

class SFMLEntity;

class Entity
{
public:
	Entity() = default;

	virtual bool GoToDirection(int x, int y, float speed = -1.f) = 0;
	virtual bool GoToPosition(int x, int y, float speed = -1.f) = 0;
	virtual void SetPosition(float x, float y, float ratioX = 0.5f, float ratioY = 0.5f) = 0;
	virtual void SetDirection(float x, float y, float speed = -1.f) = 0;
	virtual float GetRadius() const = 0;

	template<typename T>
	T* GetPosition(float ratioX = 0.5f, float ratioY = 0.5f) const = 0;

	virtual bool IsColliding(SFMLEntity* other) const = 0;

};