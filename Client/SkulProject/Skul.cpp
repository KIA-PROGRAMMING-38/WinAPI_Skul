#include "global_include.h"
#include "Skul.h"

#include "ResourceManager.h"

#include "Transform.h"
#include "Texture.h"
#include "Animator.h"

Skul::Skul()
{
}

Skul::~Skul()
{
}

void Skul::Initialize()
{
	GameObject::Initialize();

	Texture* texture = ResourceManager::GetInstance()->LoadTexture(L"Player", L"Character\\Player.bmp");
	_animator = AddComponent(new Animator());
	_animator->CreateAnimation(L"Idle", texture, Vector2(0.f, 0.f), Vector2(100.f, 100.f), Vector2(100.f, 0.f), 0.7f, 4);
	_animator->CreateAnimation(L"Move", texture, Vector2(0.f, 200.f), Vector2(100.f, 100.f), Vector2(100.f, 0.f), 0.5f, 8);
	_animator->CreateAnimation(L"Attack", texture, Vector2(0.f, 500.f), Vector2(100.f, 100.f), Vector2(100.f, 0.f), 0.6f, 5);
	_animator->Play(_animName, true);

	GetTransform()->SetScale(Vector2(2.f, 2.f));
}

void Skul::FixedUpdate()
{
	GameObject::FixedUpdate();
}

void Skul::Update()
{
	GameObject::Update();
}

void Skul::LateUpdate()
{
	GameObject::LateUpdate();
}

void Skul::Render(HDC hDC)
{
	_animator->Render(hDC);
}
