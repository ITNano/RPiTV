#include <string>
#include <map>

class Command{

	public:
		Command(string rawCommand);
		void setCommand(string cmd){this->cmd = cmd;}
		string getCommand(){return this->cmd;}
		void setParameter(string key, string value);
		string getParameter(string key);
		bool hasParameter(string key);

		void print();
	private:
		string cmd;
		map<string,string> params;

}