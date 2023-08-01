#include "global_include.h"
#include "GameObject.h"

#include "Transform.h"
#include "Component.h"

GameObject::GameObject()
	: _transform(nullptr)
{
}

GameObject::~GameObject()
{
	Release();
}

void GameObject::Initialize()
{
	_transform = AddComponent(new Transform());
}

void GameObject::FixedUpdate()
{
	for (size_t i = 0; i < _components.size(); ++i)
	{
		_components[i]->FixedUpdate();
	}
}

void GameObject::Update()
{
	for (size_t i = 0; i < _components.size(); ++i)
	{
		_components[i]->Update();
	}
}

void GameObject::LateUpdate()
{
	for (size_t i = 0; i < _components.size(); ++i)
	{
		_components[i]->LateUpdate();
	}
}

void GameObject::Release()
{
	for (size_t i = 0; i < _components.size(); ++i)
	{
		delete _components[i];
		_components[i] = nullptr;
	}

	_components.clear();
}