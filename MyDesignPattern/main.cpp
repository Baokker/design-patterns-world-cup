#include <iostream>
#include "Servant/Servant.h"
#include "Visitor/Visitor.h"
#include "ChainOfResponsibility/ChainOfResponsibility.h"
#include "Facade/Facade.h"

using namespace std;

int main()
{
	TestServant();
	TestVisitor();
	TestChainOfResponsibility();
	TestFacade();

	return 0;
}