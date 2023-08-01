#include "global_include.h"
#include "Skul.h"

#include "ResourceManager.h"

#include "Transform.h"
#include "Texture.h"
#include "Animator.h"
#include "Collider.h"

Skul::Skul()
{
}

Skul::~Skul()
{
}

void Skul::Initialize()
{
	Character::Initialize();

	Texture* texture = ResourceManager::GetInstance()->LoadTexture(L"Player", L"Character\\Player.bmp");
	Animator* animator = GetComponent<Animator>();
	animator->CreateAnimation(L"Idle", texture, Vector2(0.f, 0.f), Vector2(100.f, 100.f), Vector2(100.f, 0.f), 0.7f, 4);
	animator->CreateAnimation(L"Move", texture, Vector2(0.f, 200.f), Vector2(100.f, 100.f), Vector2(100.f, 0.f), 0.5f, 8);
	animator->CreateAnimation(L"Attack", texture, Vector2(0.f, 500.f), Vector2(100.f, 100.f), Vector2(100.f, 0.f), 0.6f, 5);
	animator->Play(L"Idle", true);

	GetTransform()->SetScale(Vector2(2.f, 2.f));
	GetComponent<Collider>()->SetScale(Vector2(100.f, 100.f));
}

void Skul::FixedUpdate()
{
	Character::FixedUpdate();
}

void Skul::Update()
{
	Character::Update();
}

void Skul::LateUpdate()
{
	Character::LateUpdate();
}

void Skul::Render(HDC hDC)
{
	Character::Render(hDC);
	RenderCollider(hDC);
}
