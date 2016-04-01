#pragma once

#include "TurnstileStateMachine.h"

class TurnstileStateMachine;
class TurnstileState
{
public:
	TurnstileState(TurnstileStateMachine* TSM): m_TSM(TSM){}
	virtual ~TurnstileState(){}
	virtual void coin(){}
	virtual void pass(){}
	virtual void reset(){}
	virtual void ready(){}

	virtual void setalarm(){}
protected:
	TurnstileStateMachine* m_TSM;
};