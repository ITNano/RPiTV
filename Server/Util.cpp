include <string>
#include <list>

using namespace std;

class Util{
	public:
		static string* splitString(string s, char delimiter);
}

string* splitString(string s, string delimiter){
	list<string> result;
	size_t pos = 0;
	string token;
	while((pos = s.find(delimiter)) != string::npos){
		token = s.substr(0, pos);
		result.push_front(token);
		s.erase(0, pos+delimiter.length());
	}

	//Copy result to array
	string* arr = new string[result.size()];
	copy(result.begin(), result.end(), arr);
	return arr;
}