#include "Command.h"


void testCommand()
{
	CommandScoreReceiver* receiver = new CommandScoreReceiver();
	ScoreForm* scoreForm = new ScoreForm();

	scoreForm->recordScore(new HeadStrike(receiver, "ÆÏÌÑÑÀ", 1));
	scoreForm->recordScore(new HeadStrike(receiver, "ÆÏÌÑÑÀ", 1));
	scoreForm->recordScore(new HeadStrike(receiver, "°¢¸ùÍ¢", 2));
	scoreForm->undo();
	scoreForm->recordScore(new FootStrike(receiver, "ÆÏÌÑÑÀ", 1));
	scoreForm->recordScore(new FootStrike(receiver, "°¢¸ùÍ¢", 2));
	scoreForm->recordScore(new FootStrike(receiver, "ÆÏÌÑÑÀ", 1));
	scoreForm->undo();
	scoreForm->recordScore(new LongStrike(receiver, "ÆÏÌÑÑÀ", 1));
	scoreForm->recordScore(new LongStrike(receiver, "°¢¸ùÍ¢", 2));
	scoreForm->recordScore(new LongStrike(receiver, "ÆÏÌÑÑÀ", 1));
	scoreForm->undo();
	delete scoreForm;
}
