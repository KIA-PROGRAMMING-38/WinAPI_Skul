#pragma once

class GameObject;

class State
{
public:
	State(GameObject* gameObject);
	virtual ~State();

public:
	virtual void OnEnter() {}
	virtual void OnUpdate() {}
	virtual void OnExit() {}

private:
	GameObject* _owner;
};

