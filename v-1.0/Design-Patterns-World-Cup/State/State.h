#pragma once
#ifndef _STATE_H_
#define _STATE_H_
class Context;
class State
{
public:
	State();
	virtual ~State();
	virtual void handle(Context* pContext) = 0;
};
class GroupStageState :public State
{
public:
	GroupStageState();
	~GroupStageState();
	virtual void handle(Context* pContext);
};
class TransitionSectionA :public State
{
public:
	TransitionSectionA();
	~TransitionSectionA();
	virtual void handle(Context* pContext);
};
class KnockOutState :public State
{
public:
	KnockOutState();
	~KnockOutState();
	virtual void handle(Context* pContext);
};
class TransitionSectionB :public State
{
public:
	TransitionSectionB();
	~TransitionSectionB();
	virtual void handle(Context* pContext);
};
class FinalState :public State
{
public:
	FinalState();
	~FinalState();
	virtual void handle(Context* pContext);
};
class Context
{
public:
	Context(State* pstate);
	~Context();
	void request();
	void changeState(State* pstate);
private:
	State* _state;
};

int testState();

#endif // !_STATE_H_
