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

    virtual bool IsColliding(Entity* other) const = 0;
    virtual bool IsInside(float x, float y) const = 0;

    virtual void Destroy() = 0;
    virtual bool ToDestroy() const = 0;

    virtual int GetTag() const = 0;
    virtual void SetTag(int tag) = 0;

    virtual std::pair<float, float> GetPosition(float ratioX = 0.5f, float ratioY = 0.5f) const = 0;

    virtual ~Entity() = default;
};
