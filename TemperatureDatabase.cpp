#include "TemperatureDatabase.h"

#include <fstream>
#include <string>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	string location = "";
	int year = 0;
    int month = 0;
    double temperature= 0;
	ifstream tempData;
	tempData.open(filename);
	if(!tempData.is_open()) {
        cout << "Error: Unable to open file " << filename << endl;
        exit(1);
    }
	else {
		while(!tempData.eof()) {
			tempData >> location;
			tempData >> year;
			tempData >> month;
			tempData >> temperature;
			records.insert(location, year, month, temperature);
		}
	}
	tempData.close();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
}
