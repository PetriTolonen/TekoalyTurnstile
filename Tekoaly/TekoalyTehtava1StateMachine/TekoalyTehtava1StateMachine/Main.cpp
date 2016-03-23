#include <windows.h>
#include <iostream>

class TurnstileGate
{
public:
	TurnstileGate();
	~TurnstileGate();

	void Lock(){ std::cout << " Lock " << std::endl; }
	void Unlock(){ std::cout << " Unlock " << std::endl; }
	void Alarm(){ std::cout << " Alarm " << std::endl; }
	void ThankYou(){ std::cout << " ThankYou " << std::endl; }
	void ThankYouOff(){ std::cout << " ThankYouOff " << std::endl; }
	void ResetAlarm(){ std::cout << " ResetAlarm " << std::endl; }
};

class TurnstileStateMachine : public TurnstileGate
{
public:
	TurnstileStateMachine(){}
	~TurnstileStateMachine(){}

	void Coin(){ }
	void Pass(){ }
	void SetState(){}
};

class TurnstileState
{

};

int main()
{
	bool exit = false;

	while (exit == false)
	{
		if (GetAsyncKeyState('1'))
		{
			std::cout << " 1 " << std::endl;
		}
		if (GetAsyncKeyState('2'))
		{
			std::cout << " 2 " << std::endl;
		}
		if (GetAsyncKeyState('3'))
		{
			std::cout << " 3 " << std::endl;
		}
		if (GetAsyncKeyState('4'))
		{
			std::cout << " 4 " << std::endl;
		}

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			exit = true;
		}
	}

	return 1;
}