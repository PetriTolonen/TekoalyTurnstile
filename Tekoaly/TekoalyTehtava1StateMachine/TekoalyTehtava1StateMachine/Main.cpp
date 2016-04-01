#include <windows.h>
#include <iostream>
#include "TurnstileStateMachine.h"
#include "TurnstileGate.h"

int main()
{
	TurnstileGate* gate = new TurnstileGate();
	TurnstileStateMachine* TSM = new TurnstileStateMachine(gate);

	bool exit = false;

	while (exit == false)
	{
		if (GetAsyncKeyState('1'))
		{
			TSM->Coin();
			Sleep(1000);
		}
		if (GetAsyncKeyState('2'))
		{
			TSM->Pass();
			Sleep(1000);
		}
		if (GetAsyncKeyState('3'))
		{
			TSM->resetAlarm();
		}
		if (GetAsyncKeyState('4'))
		{
			TSM->ready();
		}

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			exit = true;
		}
	}

	delete gate;
	delete TSM;

	return 1;
}