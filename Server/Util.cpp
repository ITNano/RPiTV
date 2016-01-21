#include <string>
#include <list>
#include "Util.h"
#include <iostream>

using namespace std;

list<string> Util::splitString(string s, string delimiter){
	list<string> result;
	size_t pos = 0;
	string token;
	while((pos = s.find(delimiter)) != string::npos){
		token = s.substr(0, pos);
		result.push_back(token);
		s.erase(0, pos+delimiter.length());
	}

	if(s.size()>0){
		result.push_back(s);
	}

	return result;
}
