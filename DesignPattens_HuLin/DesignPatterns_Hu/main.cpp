#include<iostream>
#include "Command/Command.h"
#include "Interpreter/Interpreter.h"
#include "Mediator/Mediator.h"
#include "Memento/Memento.h"
#include "NullObject/NullObject.h"
#include "Observer/Observer.h"
#include "PublishSubscribe/PublishSubscribe.h"
#include "TransferObject/TransferObject.h"

using namespace std;

void showGUI()
{
	cout << "----------------------------------------------------------" << endl << endl;
	cout << "��1---------------------Mediator--------------------------" << endl << endl;
	cout << "��2----------------------Memento--------------------------" << endl << endl;
	cout << "��3----------------------Observer-------------------------" << endl << endl;
	cout << "��4-------------------PublishSubscribe--------------------" << endl << endl;
	cout << "��5--------------------Command----------------------------" << endl << endl;
	cout << "��6--------------------Interpreter------------------------" << endl << endl;
	cout << "��7--------------------Null Object------------------------" << endl << endl;
	cout << "��8------------------Transfer Object----------------------" << endl << endl;
	cout << "----------------------------------------------------------" << endl << endl;
}

int main()
{
	string choice;

	showGUI();

	while (cin >> choice && choice != "END")
	{
		if (choice == "1")
			testMediator();
		else if (choice == "2")
			testObserver();
		else if (choice == "3")
			testMemento();
		else if (choice == "4")
			testPublishSubscribe();
		else if (choice == "5")
			testCommand();
		else if (choice == "6")
			testInterpreter();
		else if (choice == "7")
			testNullObject();
		else if (choice == "8")
			testTransferObject();

		showGUI();
	}

	return 0;
}