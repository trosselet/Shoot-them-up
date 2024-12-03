#include "pch.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
#include "SampleScene.h"

#include <cstdlib>
#include <crtdbg.h>

int main() 
{
    GameManager* pInstance = GameManager::Get();

	pInstance->Initialize(1280, 720, "SampleScene");
	
	pInstance->LaunchScene<SampleScene>();

	return 0;
}