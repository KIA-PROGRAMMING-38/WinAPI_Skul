#pragma once
#include "GameObject.h"

class Animator;
class Collider;

class Character abstract : public GameObject
{
protected:
	Character();
public:
	virtual ~Character();

public:
	virtual void Initialize() override;
	virtual void FixedUpdate() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;

public:
	void TakeDamage(int damage);

protected:
	void RenderCollider(HDC hDC);

private:
	Animator* _animator = nullptr;
	Collider* _bodyCollider = nullptr;
};

