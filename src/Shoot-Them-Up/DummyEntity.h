#pragma once
#include "SFMLEntity.h"

class DummyEntity : public SFMLEntity
{
public:
	void OnCollision(SFMLEntity* other) override;
};

