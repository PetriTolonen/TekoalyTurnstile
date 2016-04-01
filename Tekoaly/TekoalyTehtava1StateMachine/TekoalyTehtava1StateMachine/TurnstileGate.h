#pragma once
#include <iostream>

class TurnstileGate
{
public:
	TurnstileGate(){};
	~TurnstileGate(){};

	void Lock(){ std::cout << " Lock " << std::endl; }
	void Unlock(){ std::cout << " Unlock " << std::endl; }
	void Alarm(){ std::cout << " Alarm " << std::endl; }
	void ThankYou(){ std::cout << " ThankYou " << std::endl; }
	void ThankYouOff(){ std::cout << " ThankYouOff " << std::endl; }
	void ResetAlarm(){ std::cout << " ResetAlarm " << std::endl; }
};