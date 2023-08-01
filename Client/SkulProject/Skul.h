#pragma once
#include "Character.h"

class Skul : public Character
{
public:
	Skul();
	virtual ~Skul();

public:
	virtual void Initialize() override;
	virtual void FixedUpdate() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
};

