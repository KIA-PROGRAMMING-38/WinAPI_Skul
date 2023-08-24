#include "State.h"

State::State(GameObject* gameObject)
	: _owner(gameObject)
{
}

State::~State()
{
}
