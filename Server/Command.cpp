#include <string>
#include <map>
#include <iostream>
#include "Command.h"
#include "Util.h"

using namespace std;

Command::Command(string* rawCommand){
	list<string> parts = Util::splitString(rawCommand->substr(0, rawCommand->size()-1), "\",");
	list<string> subparts;
	string name, value;
	list<string>::const_iterator iterator;
	for(iterator = parts.begin(); iterator != parts.end(); iterator++){
		subparts = Util::splitString(*iterator, "=");
		if(subparts.size() == 2){
			list<string>::const_iterator innerIterator = subparts.begin();
			name = *innerIterator;
			value = *(++innerIterator);
			//Clean up from quotes etc.
			name = name.substr(1, name.size()-2);
			value = value.substr(1, value.size()-1);
			if(name.compare("command") == 0){
				this->setCommand(value);
			}
			else{
				this->setParameter(name, value);
			}
		}else{
			cout << "Invalid part of command found: " << *iterator << endl;
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

void Command::print(){
	cout << "Command: " << this->cmd << endl;
	cout << "Params (" << params.size() << "): ";
	map<string, string>::const_iterator iterator = params.begin();
	for(;iterator != params.end(); ){
		cout << iterator->first << "=" << iterator->second;
		iterator++;
		if(iterator != params.end()){
			cout << ", ";
		}
	}
	cout << endl;
}
