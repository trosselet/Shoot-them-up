#pragma once

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Scene;

class SFMLEntity : public Entity
{
    struct Target
    {
        sf::Vector2i position;
        float distance;
        bool isSet;
    };

private:
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
    float GetRadius() const override { return mShape.getRadius(); }

    std::pair<float, float> GetPosition(float ratioX, float ratioY) const override;
    sf::Vector2f GetPosition() const;

    bool IsColliding(Entity* other) const override;
    bool IsInside(float x, float y) const override;

    void Destroy() override;
    bool ToDestroy() const override;

    int GetTag() const override { return mTag; }
    void SetTag(int tag) override { mTag = tag; }

    template<typename T>
    T* GetScene() const;

    template<typename T>
    T CreateSFMLEntity(float radius, int r, int g, int b, int a);


    sf::CircleShape* GetShape() { return &mShape; }
    template<typename T>
    T* GetShape();

    Scene* GetScene() const;
    float GetDeltaTime() const;

protected:
    SFMLEntity() = default;
    ~SFMLEntity() = default;

    virtual void OnUpdate() {}
    virtual void OnCollision(SFMLEntity* collidedWith) {}
    virtual void OnInitialize() {}

private:
    void Update();
    void Initialize(float radius, int r, int g, int b, int a);

    friend class GameManager;
    friend Scene;
};
