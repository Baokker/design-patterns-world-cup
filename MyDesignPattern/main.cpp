#include <iostream>
#include "Servant/Servant.h"
#include "Visitor/Visitor.h"
#include "ChainOfResponsibility/ChainOfResponsibility.h"
#include "Facade/Facade.h"
#include "Iterator/Iterator.h"
#include "Adapter/Adapter.h"
#include "TemplateMethod/TemplateMethod.h"
#include "Decorator/Decorator.h"

using namespace std;

int main()
{
	testServant();
	testVisitor();
	testChainOfResponsibility();
	testFacade();
	testIterator();
	testAdaptor();
	testTemplateMethod();
	testDecorate();
	return 0;
}