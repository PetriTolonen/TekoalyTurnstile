#pragma once
#include "TurnstileGate.h"
#include "TurnstileState.h"

class TurnstileGate;

class TurnstileStateMachine
{
public:
	TurnstileStateMachine(TurnstileGate* gate) : gate(gate)
	{
		std::cout << "TMS constructor" << std::endl;
	}
	~TurnstileStateMachine(){}

	void Coin()
	{
		currentState->coin();
	}
	void Pass()
	{
		currentState->pass();
	}

	void resetAlarm()
	{
		currentState->reset();
	}

	void ready()
	{
		currentState->ready();
	}

	void setCurrentState(TurnstileState* state){ this->currentState = state; }

	TurnstileGate* getGate(){ return gate; }
private:
	TurnstileState* currentState;
	TurnstileGate* gate;
};