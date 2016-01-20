#include <string>
#include <map>
#include <iostream>

using namespace std;

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

Command::Command(string rawCommand){
	string[] parts = Util.splitString(rawCommand, "\",");
	string[] subparts;
	string name, value;
	for(const string &part : parts){
		subparts = Util.splitString(part, "=");
		if(sizeof(subparts)>0 && sizeof(subparts)/sizeof(subparts[0]) == 2){
			name = subparts[0]->substr(1, subparts[0]->size()-2);
			value = subparts[1]->substr(1, subparts[1]->size()-1);
			if(name.compare("command") == 0){
				this->setCommand(value);
			}
			else{
				this->setParameter(name, value);
			}
		}else{
			cout << "Invalid part of command found: " << part;
		}
	}
}

void Command::setParameter(string key, string value){
	params.insert(pair<string, string>(key, value));
}

string Command::getParameter(string key){
	if(this->hasParameter(key))
		return params.find(key)->second;
	else
		return NULL;
}

bool Command::hasParameter(string key){
	return params.count(key)>0?true:false;
}

string Command::print(){
	cout << "Command: " << this->cmd << endl;
	cout << "Params: ";
	typedef map<string, string>::iterator it_type;
	for(it_type iterator = this->params.begin(); iterator != this->params.end(); iterator++){
		cout << iterator->first << "=" << iterator->second;
		if(iterator+1 != this->params.end()){
			cout << ", ";
		}
		cout << endl;
	}
}