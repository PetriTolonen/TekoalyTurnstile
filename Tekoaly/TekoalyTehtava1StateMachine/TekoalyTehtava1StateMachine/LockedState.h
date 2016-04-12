#pragma once
#include "TurnstileState.h"

#include <iostream>

class LockedState : public TurnstileState
{
public:
	LockedState(TurnstileStateMachine* TSM) : TurnstileState(TSM){ std::cout << "locked constructor" << std::endl; }
	~LockedState(){}

	void coin()
	{
		m_TSM->getGate()->Unlock();
		m_TSM->SetUnLockeState();
	}

	void pass()
	{
		m_TSM->getGate()->Alarm();
		m_TSM->SetViolationState();
	}
};