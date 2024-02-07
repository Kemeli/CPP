#include "Data.hpp"
#include <iostream>

Data::Data() : dataValue(0) {}

Data::Data(const Data &obj) : dataValue(obj.dataValue) {
}

Data &Data::operator=(const Data &obj) {
	if (this != &obj) {
		dataValue = obj.dataValue;
	}
	return *this;
}

Data::~Data() {}

int Data::getDataValue() const {
	return dataValue;
}

void Data::setDataValue(int value) {
	dataValue = value;
}
