#include "global_include.h"
#include "FSM.h"

#include "State.h"

FSM::FSM()
{
}

FSM::~FSM()
{
	Release();
}

void FSM::Initialize()
{
	Release();
}

void FSM::Update()
{
	if (_curState)
	{
		_curState->OnUpdate();
	}
}

void FSM::Release()
{
	for (size_t i = 0; i < _states.size(); ++i)
	{
		delete _states[i];
	}

	_states.clear();
}

void FSM::AddState(State* state)
{
	assert(state);

	_states.push_back(state);
}

void FSM::ChangeState(int index)
{
	assert(_states.size() <= index);

	if (_curState)
	{
		_curState->OnExit();
	}

	_curState = _states[index];
	assert(_curState);

	_curState->OnEnter();
}
