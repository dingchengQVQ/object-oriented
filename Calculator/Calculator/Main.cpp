#include "Calculator.h"
#include <iostream>
using namespace std;

int main()
{
	string input;
	Scan scanMachine;
	Print printMachine;

	cin>>input;

	if (scanMachine.ToStringQueue(input))
	{
		printMachine.PrintQueue(scanMachine.m_scanstring);
	}
	else
	{
		cout<<"����λ����10λ������,���������룡";
	}

	system("pause");

	

}