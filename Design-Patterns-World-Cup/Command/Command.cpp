#include "Command.h"


void testCommand()
{
	CommandScoreReceiver* receiver = new CommandScoreReceiver();
	ScoreForm* scoreForm = new ScoreForm();

	scoreForm->recordScore(new HeadStrike(receiver, "������", 1));
	scoreForm->recordScore(new HeadStrike(receiver, "������", 1));
	scoreForm->recordScore(new HeadStrike(receiver, "����͢", 2));
	scoreForm->undo();
	scoreForm->recordScore(new FootStrike(receiver, "������", 1));
	scoreForm->recordScore(new FootStrike(receiver, "����͢", 2));
	scoreForm->recordScore(new FootStrike(receiver, "������", 1));
	scoreForm->undo();
	scoreForm->recordScore(new LongStrike(receiver, "������", 1));
	scoreForm->recordScore(new LongStrike(receiver, "����͢", 2));
	scoreForm->recordScore(new LongStrike(receiver, "������", 1));
	scoreForm->undo();
	delete scoreForm;
}
