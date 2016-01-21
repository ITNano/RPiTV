#include <string>
#include <map>

class Command{

	public:
		Command(std::string* rawCommand);
		void setCommand(std::string cmd){this->cmd = cmd;}
		std::string getCommand(){return this->cmd;}
		void setParameter(std::string key, std::string value);
		std::string getParameter(std::string key);
		bool hasParameter(std::string key);

		void print();
	private:
		std::string cmd;
		std::map<std::string,std::string> params;

};
