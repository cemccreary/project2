#include "MathVector.h"
#include <algorithm>
using namespace std;

bool is_digits(const std::string &str)
{
	return str.find_first_not_of(" -.0123456789") == string::npos;
}
//MathVector definition
MathVector::MathVector(int numElements){
	this->numElements = numElements;
	elements.resize(numElements);
}

//readElements definition
bool MathVector::readElements(string str){
	stringstream linestream(str);
	string token;
	int i = 0;
	int numCommas = count(str.begin(), str.end(), ',');
	//cout << "numCommas: " << numCommas << endl;
	while (getline(linestream, token, ',')){ 
		i++;
		bool x = is_digits(token);
		if (x != false && i <= numElements){
			elements[i - 1] = stod(token);
		}
		if (numElements < i && x == true){
			//cout << "i: " << i << endl << "numElements: " << numElements << endl << "elements.size()" << elements.size() << endl;
			cout /*<< " numElements < i && x == true "*/ << "Unable to read line [" << str << "] (more than " << numElements << " elements)" << endl;
			return false;
		}
		if (x == false){
			//cout << "i: " << i << endl << "numElements: " << numElements << endl << "elements.size()" << elements.size() << endl;
			cout /*<< " x == false "*/ << "Unable to read element " << i - 1 << " of [" << str << "] (expected " << numElements << " elements)" << endl;
			return false;
		}
	}
	if (i < numElements && i == numCommas){
		//cout << "i: " << i << endl << "numElements: " << numElements << endl << "elements.size()" << elements.size() << endl;
		cout/* << " numElements && i == numCommas "*/ << "Unable to read element " << i << " of [" << str << "] (expected " << numElements << " elements)" << endl;
		return false;
	}
	if (numCommas < numElements && i < numElements){
		//cout << "i: " << i << endl << "numElements: " << numElements << endl << "elements.size()" << elements.size() << endl;
		cout /*<< "numCommas < numElements && i < numElements "*/ << "Unable to read element " << i - 1 << " of [" << str << "] (expected " << numElements << " elements)" << endl;
		return false;
	}
	//cout << "i: " << i << endl << "numElements: " << numElements << endl << "elements.size()" << elements.size() << endl;
	return true;
}

string MathVector::toString() {
	stringstream ss;
	if (numElements > 0){
		ss << elements.at(0);
		for (unsigned int i = 1; i < elements.size(); i++){
			ss << ", " << elements.at(i);
		}
	}
	return ss.str();
}

