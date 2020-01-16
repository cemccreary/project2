#include "Director.h"
#include "Input.h"
#include "MathVector.h"
#include "Project2.h"
#include "State.h"
#include "Vehicle.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* arg[]){
	
	if (argc == 1){
		cout << " inputFile outputFile" << endl;
		return 0;
	}
	
	project2Read(arg[1], arg[2]);

	return 0;
}