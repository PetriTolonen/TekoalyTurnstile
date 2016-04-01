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
		std::cout << "alarm!!!" << std::endl;
		alarmreset = false;
	}

private:
	bool alarmreset;
};
