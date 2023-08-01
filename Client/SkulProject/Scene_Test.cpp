#include "global_include.h"
#include "Scene_Test.h"

#include "Skul.h"
#include "Transform.h"

void Scene_Test::Initialize()
{
	GameObject* newGameObject = nullptr;

	newGameObject = new Skul(L"Idle");
	newGameObject->Initialize();
	newGameObject->GetTransform()->SetPosition(Vector2(100.f, 100.f));
	AddObject(newGameObject, GroupType::Player);

	newGameObject = new Skul(L"Move");
	newGameObject->Initialize();
	newGameObject->GetTransform()->SetPosition(Vector2(400.f, 100.f));
	AddObject(newGameObject, GroupType::Player);

	newGameObject = new Skul(L"Attack");
	newGameObject->Initialize();
	newGameObject->GetTransform()->SetPosition(Vector2(200.f, 400.f));
	AddObject(newGameObject, GroupType::Player);
}

void Scene_Test::Release()
{
	ReleaseDynamicObject();
}
