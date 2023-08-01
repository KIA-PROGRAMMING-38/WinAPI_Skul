#pragma once
#include "GameObject.h"

class Animator;

class Skul : public GameObject
{
public:
	Skul();
	~Skul();

public:
	virtual void Initialize() override;
	virtual void FixedUpdate() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;

private:
	Animator* _animator = nullptr;
	wstring _animName = L"";
};

