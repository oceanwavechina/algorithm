#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;


template<typename T>
string binary_str(T x) {
	ostringstream oss;
	oss << bitset<(sizeof(T)) *8>(x);
	return oss.str();
}

class Formatter {
public:
	Formatter(const string& suffix) { 
		_oss_result << suffix << "\n";
	}
    ~Formatter() {
        cout << _oss_result.str() << endl;
    }

	void AddLine(const string& line) {
		_oss_result << "\t" << line << "\n";
	}
    
    friend Formatter& operator<< (Formatter &os, ostringstream &oss) {
        os._oss_result << "\t" << oss.str() << "\n";
        oss.str("");
		return os;
	}

private:
	ostringstream _oss_result;
};