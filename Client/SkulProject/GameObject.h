#pragma once
#include "IBehaviour.h"

class Component;
class Collider;
class Transform;

class GameObject : public IBehaviour
{
public:
	GameObject();
	virtual ~GameObject();

public:
	Transform* GetTransform() const { return _transform; }

public:
	virtual void Initialize();
	virtual void FixedUpdate();
	virtual void Update();
	virtual void LateUpdate();

public:
	virtual void OnCollisionEnter(Collider* collider) {}
	virtual void OnCollisionStay(Collider* collider) {}
	virtual void OnCollisionExit(Collider* collider) {}

public:
	template <typename T>
	T* AddComponent(T* component)
	{
		assert(component);

		_components.push_back(component);
		component->SetGameObject(this);

		return component;
	}
	template <typename T>
	T* GetComponent()
	{
		for (size_t i = 0; i < _components.size(); ++i)
		{
			if (typeid(_components[i]).name() == typeif(T).name())
				return dynamic_cast<T*>(_components[i]);
		}

		return nullptr;
	}

private:
	vector<Component*> _components;
	Transform* _transform;
};

