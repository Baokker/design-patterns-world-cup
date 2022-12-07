#include <iostream>
#include "Servant/Servant.h"
#include "Visitor/Visitor.h"
#include "ChainOfResponsibility/ChainOfResponsibility.h"
#include "Facade/Facade.h"

using namespace std;

int main()
{
	testServant();
	testVisitor();
	testChainOfResponsibility();
	testFacade();

	return 0;
}