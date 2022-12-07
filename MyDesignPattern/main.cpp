#include <iostream>
#include "Servant/Servant.h"
#include "Visitor/Visitor.h"
#include "ChainOfResponsibility/ChainOfResponsibility.h"
#include "Facade/Facade.h"
#include "Iterator/Iterator.h"
#include "Adapter/Adapter.h"
#include "TemplateMethod/TemplateMethod.h"

using namespace std;

int main()
{
	TestServant();
	TestVisitor();
	TestChainOfResponsibility();
	TestFacade();
	testIterator();
	testAdaptor();
	testTemplateMethod();

	return 0;
}