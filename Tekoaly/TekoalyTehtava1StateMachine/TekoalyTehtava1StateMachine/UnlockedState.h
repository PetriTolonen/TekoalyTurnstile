#pragma once
#include "TurnstileState.h"
#include <iostream>
#include "LockedState.h"

class UnLockedState : public TurnstileState
{
public:
	UnLockedState(TurnstileStateMachine* TSM) : TurnstileState(TSM){ std::cout << "unlocked constructor" << std::endl; }
	~UnLockedState(){}

	void coin()
	{
		m_TSM->getGate()->ThankYou();
	}

	void pass()
	{
		m_TSM->getGate()->Unlock();
		m_TSM->setCurrentState();
	}
};