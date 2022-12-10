#include<iostream>
#include"State.h"
using namespace std;
//state Pattern
//in this pattern ,athletes change states to play differenr games
State::State(){}
State::~State() {}
GroupStageState::GroupStageState(){}
GroupStageState::~GroupStageState() {}
void GroupStageState::handle(Context* pContext)
{
	cout << "Ŀǰ��С�����׶Σ�" << endl;
	pContext->changeState(new TransitionSectionA());
}

TransitionSectionA::TransitionSectionA() {}
TransitionSectionA::~TransitionSectionA() {}
void TransitionSectionA::handle(Context* pContext)
{
	cout << "С�����׶μ���ת��Ϊ��̭���׶Σ�" << endl;
	pContext->changeState(new KnockOutState());
}

KnockOutState::KnockOutState() {}
KnockOutState::~KnockOutState() {}
void KnockOutState::handle(Context* pContext)
{
	cout << "Ŀǰ����̭���׶Σ�" << endl;
	pContext->changeState(new TransitionSectionB());
}

TransitionSectionB::TransitionSectionB() {}
TransitionSectionB::~TransitionSectionB() {}
void TransitionSectionB::handle(Context* pContext)
{
	cout << "С�����׶μ���ӭ�����ľ����׶Σ�" << endl;
	pContext->changeState(new FinalState());
}

FinalState::FinalState() {}
FinalState::~FinalState() {}
void FinalState::handle(Context* pContext)
{
	cout << "Ŀǰ�Ǿ����׶Σ�" << endl;
	cout << "���еı���״̬ת����ϣ�" << endl;
}

Context::Context(State* pstate)
{
	this->_state = pstate;
}
Context::~Context() {}
void Context::request()
{
	if (this->_state != NULL)
	{
		this->_state->handle(this);
	}
}
void Context::changeState(State* pstate)
{
	this->_state = pstate;
}
int testState()
{
	State* pstate = new GroupStageState();
	Context* pContext = new Context(pstate);
	pContext->request();
	pContext->request();
	pContext->request();
	pContext->request();
	pContext->request();
	delete pstate;
	delete pContext;

	cout << endl;

	return 0;
}