#pragma once

class TurnstileGate;
class LockedState;
class Violation;
class UnLockedState;
class TurnstileState;

class TurnstileStateMachine
{
public:
	TurnstileStateMachine(TurnstileGate* gate);
	~TurnstileStateMachine(){}

	void Coin();
	void Pass();

	void resetAlarm();

	void ready();

	void SetLockedState();
	void SetUnLockeState();
	void SetViolationState();
	TurnstileGate* getGate();
private:
	TurnstileState* state;
	TurnstileGate* gate;
	LockedState* lockedstate;
	UnLockedState* unlockedstate;
	Violation* violation;
};