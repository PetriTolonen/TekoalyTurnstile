#pragma once
#include "TurnstileGate.h"
#include "LockedState.h"
#include "UnlockedState.h"
#include "Violation.h"

class TurnstileGate;

class TurnstileStateMachine
{
public:
	TurnstileStateMachine(TurnstileGate* gate) : gate(gate)
	{
		std::cout << "TMS constructor starts" << std::endl;
		lockedstate = new LockedState(this);
		unlockedstate = new UnLockedState(this);
		violation = new Violation(this);
		std::cout << "TMS constructor ends" << std::endl;
	}
	~TurnstileStateMachine(){}

	void Coin()
	{
		state->coin();
	}
	void Pass()
	{
		state->pass();
	}

	void resetAlarm()
	{
		state->reset();
	}

	void ready()
	{
		state->ready();
	}

	void SetLockedState(){ this->state = lockedstate; }
	void SetUnLockeState(){ this->state = unlockedstate; }
	void SetViolationState()
	{
		this->state->setalarm();
		this->state = violation;
	}
	TurnstileGate* getGate(){ return gate; }
private:
	TurnstileState* state;
	TurnstileGate* gate;
	LockedState* lockedstate;
	UnLockedState* unlockedstate;
	Violation* violation;
};