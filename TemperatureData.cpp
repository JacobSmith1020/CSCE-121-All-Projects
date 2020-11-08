/*
 * TemperatureData.cpp
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */

#include "TemperatureData.h"
using namespace std;

TemperatureData::TemperatureData() {} //initialize everything

TemperatureData::TemperatureData(string id, int year, int month, double temperature) {
	setid(id);
	setYear(year);
	setMonth(month);
	setTemp(temperature);
} //initialize everything


TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) {
	// Implement this
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
}

string TemperatureData::getid() {return id;}

int TemperatureData::getYear() {return year;}

int TemperatureData::getMonth() {return month;}

double TemperatureData::getTemp() {return temperature;}

void TemperatureData::setid(string id) {
	this->id = id;
}
void TemperatureData::setYear(int year) {
	this->year = year;
}
void TemperatureData::setMonth(int month) {
	this->month = month;
} 
void TemperatureData::setTemp(double temperature) {
	this->temperature = temperature;
}

