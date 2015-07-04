#include "definitions.h"

int checkBit(unsigned int number, int bitNumber) {
	return (number>>bitNumber)&1;
}

std::vector<std::string> splitString(std::string toSplit) {
	return splitString(toSplit,"\t");
}

std::vector<std::string> splitString(std::string toSplit, std::string delimeter) {
	std::vector<std::string> splitted;
	while (toSplit.length()>0) {
		std::string lastVal = toSplit;
		splitted.push_back(toSplit.substr(0,toSplit.find(delimeter)));
		toSplit = toSplit.substr(toSplit.find(delimeter)+1);
		if (!toSplit.compare(lastVal)) {
			splitted.push_back(toSplit);
			toSplit = "";
		}
	}
	return splitted;
}
