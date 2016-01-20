#include <string>

using namespace std;

class CommandHandler{
	public:
		virtual void handleCommand(Command* c);
		virtual void getName();
}