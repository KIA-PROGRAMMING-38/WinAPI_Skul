#include "global_include.h"
#include "Scene_Test.h"

#include "Skul.h"
#include "Transform.h"

void Scene_Test::Initialize()
{
	GameObject* newGameObject = nullptr;

	newGameObject = new Skul();
	newGameObject->Initialize();
	newGameObject->GetTransform()->SetPosition(Vector2(100.f, 100.f));
	AddObject(newGameObject, GroupType::Player);
}

void Scene_Test::Release()
{
	ReleaseDynamicObject();
}
