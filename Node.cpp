#include <string>
#include "Node.h"

using namespace std;

// Default constructor
Node::Node(): next(nullptr) {} // remember to initialize next to nullptr

// Parameterized constructor
Node::Node(string id, int year, int month, double temperature): next(nullptr) {
	setid(id);
	setYear(year);
	setMonth(month);
	setTemp(temperature);
	data.id = id;
	data.year = year;
	data.month = month;
	data.temperature = temperature;
}
// remember to initialize next to nullptr

bool Node::operator<(const Node& b) {
	string location1 = this->id;
	string location2 = b.id;
	if(location1.compare(location2) == 0) {
		int year1 = this->year;
		int year2 = b.year;
		if(year1 == year2) {
			int month1 = this->month;
			int month2 = b.month;
			if(month1 < month2) {
				return true;
			}
			else {
				return false;
			}
		}
		else if(year1 < year2) {
			return true;
		}
		else if(year1 > year2) {
			return false;
		}
	}
	else if(location1.compare(location2) < 0) {
		return true;
	}
	else if(location1.compare(location2) > 0) {
		return false;
	}
	return this->data < b.data;
}

string Node::getid() {return id;}

int Node::getYear() {return year;}

int Node::getMonth() {return month;}

double Node::getTemp() {return temperature;}

void Node::setid(string id) {
	this->id = id;
}
void Node::setYear(int year) {
	this->year = year;
}
void Node::setMonth(int month) {
	this->month = month;
} 
void Node::setTemp(double temperature) {
	this->temperature = temperature;
}