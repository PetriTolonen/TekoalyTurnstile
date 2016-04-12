#include "TurnstileStateMachine.h"
#include "LockedState.h"
#include "UnlockedState.h"
#include "Violation.h"

TurnstileStateMachine::TurnstileStateMachine(TurnstileGate* gate) : gate(gate)
{
	std::cout << "TMS constructor starts" << std::endl;
	lockedstate = new LockedState(this);
	unlockedstate = new UnLockedState(this);
	violation = new Violation(this);

	SetLockedState();
	std::cout << "TMS constructor ends" << std::endl;
}

void TurnstileStateMachine::Coin()
{
	state->coin();
}
void TurnstileStateMachine::Pass()
{
	state->pass();
}

void TurnstileStateMachine::resetAlarm()
{
	state->reset();
}

void TurnstileStateMachine::ready()
{
	state->ready();
}

void TurnstileStateMachine::SetLockedState(){ this->state = lockedstate; }
void TurnstileStateMachine::SetUnLockeState(){ this->state = unlockedstate; }
void TurnstileStateMachine::SetViolationState()
{
	this->state->setalarm();
	this->state = violation;
}

TurnstileGate* TurnstileStateMachine::getGate()
{
	return gate;
}