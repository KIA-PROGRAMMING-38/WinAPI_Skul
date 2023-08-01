#include "global_include.h"
#include "Character.h"

#include "Animator.h"
#include "Collider.h"

Character::Character()
	: _animator(nullptr)
	, _bodyCollider(nullptr)
{
}

Character::~Character()
{
}

void Character::Initialize()
{
	GameObject::Initialize();

	_animator = AddComponent(new Animator());
	_bodyCollider = AddComponent(new Collider());

	_animator->Initialize();
	_bodyCollider->Initialize();
}

void Character::FixedUpdate()
{
	GameObject::FixedUpdate();
}

void Character::Update()
{
	GameObject::Update();
}

void Character::LateUpdate()
{
	GameObject::LateUpdate();
}

void Character::Render(HDC hDC)
{
	if (_animator)
	{
		_animator->Render(hDC);
	}
}

void Character::TakeDamage(int damage)
{
}

void Character::RenderCollider(HDC hDC)
{
	if (_bodyCollider)
	{
		_bodyCollider->Render(hDC);
	}
}
