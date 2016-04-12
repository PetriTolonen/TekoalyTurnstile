#pragma once
#include "TurnstileState.h"
#include <iostream>
class Violation : public TurnstileState
{
public:
	Violation(TurnstileStateMachine* TSM) : TurnstileState(TSM){ alarmreset = false; std::cout << "violation constructor" << std::endl; }
	~Violation(){}

	void coin()
	{
		std::cout << "violation!!" << std::endl;
	}

	void pass()
	{
		std::cout << "violation!!" << std::endl;
	}

	void reset()
	{
		m_TSM->getGate()->ResetAlarm();
		alarmreset = true;
	}

	void ready()
	{
		if (alarmreset == true)
		{
			
			m_TSM->SetLockedState();
		}		
	}

	void setalarm()
	{
		m_TSM->getGate()->Alarm();
		alarmreset = false;
	}

private:
	bool alarmreset;
};
