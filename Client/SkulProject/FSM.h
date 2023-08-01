#pragma once
#include "IBehaviour.h"

class State;

class FSM
{
public:
	FSM();
	~FSM();

public:
	void Initialize();
	void Update();
	void Release();

public:
	void AddState(State* state);
	void ChangeState(int index);

private:
	vector<State*> _states;
	State* _curState;
};

