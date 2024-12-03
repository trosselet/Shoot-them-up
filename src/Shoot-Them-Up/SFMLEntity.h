#pragma once

#include "Entity.h"

namespace sf
{
    class Shape;
    class Color;
}

class Scene;

class SFMLEntity : public Entity
{
    struct Target
    {
        sf::Vector2i position;
        float distance;
        bool isSet;
    };

protected:
    sf::CircleShape mShape;
    sf::Vector2f mDirection;
    Target mTarget;
    float mSpeed;
    bool mToDestroy;
    int mTag;

public:
    bool GoToDirection(int x, int y, float speed = -1.f) override;
    bool GoToPosition(int x, int y, float speed = -1.f) override;
    void SetPosition(float x, float y, float ratioX = 0.5f, float ratioY = 0.5f) override;
    void SetDirection(float x, float y, float speed = -1.f) override;
    void SetSpeed(float speed) { mSpeed = speed; }
    void SetTag(int tag) { mTag = tag; }
    float GetRadius() const override { return mShape.getRadius(); }

    template<typename T>
    T GetPosition(float ratioX = 0.5f, float ratioY = 0.5f) const;

    template<typename T>
    T* GetShape() { return &mShape; }

    bool IsTag(int tag) const { return mTag == tag; }
    bool IsColliding(SFMLEntity* other) const;
    bool IsInside(float x, float y) const;

    void Destroy() { mToDestroy = true; }
    bool ToDestroy() const { return mToDestroy; }

    template<typename T>
    T* GetScene() const;

    Scene* GetScene() const;
    float GetDeltaTime() const;

    template<typename T>
    T* CreateSFMLEntity(float radius, int r, int g, int b, int a);

protected:
    SFMLEntity() = default;
    ~SFMLEntity() = default;

    virtual void OnUpdate() {};
    virtual void OnCollision(SFMLEntity* collidedWith) {};
    virtual void OnInitialize() {};

private:
    void Update();
    void Initialize(float radius, int r, int g, int b, int a);

    friend class GameManager;
    friend Scene;
};

#include "SFMLEntity.inl"