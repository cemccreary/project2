#define _USE_MATH_DEFINES
#include "Project2.h"
#include "MathVector.h"
#include "Vehicle.h"
#include "Director.h"
#include <iomanip>
#include <cmath>
#include <math.h>

string trim(string input)
{
	string out = "";
	for (unsigned int i = 0; i < input.size(); ++i)
	{
		if (input.at(i) != ' ' && input.at(i) != '\n' && input.at(i) != '\t')
		{
			out = out + input.at(i);
		}
	}
	return out;
}


int project2Read(string inFilename, string outFilename){
	ofstream ofs(outFilename);
	streambuf *standardOutOutputStreamBuffer = cout.rdbuf();
	cout.rdbuf(ofs.rdbuf());

	ifstream inF;
	inF.open(inFilename);
	ofstream outF;
	outF.open(outFilename);
	
	if (inF){
		//cout << "File: " << inFilename << " open" << endl;
		string currline;
		string trash;

		//Reading in Wheelbase
		stringstream s1;
		MathVector Read1(1);
		getline(inF, currline);
		s1.str(currline);
		s1 >> trash;
		s1 >> currline;
		if (currline == ""){
			return 0;
	}
		//
		cout.rdbuf(standardOutOutputStreamBuffer);
		if (!Read1.readElements(currline)){
			return 0;
		}
		cout.rdbuf(ofs.rdbuf());

		//Reading in initial state
		stringstream s2;
		State Read2;
		getline(inF, currline);
		s2.str(currline);
		s2 >> trash;
		s2 >> currline;
		//
		cout.rdbuf(standardOutOutputStreamBuffer);
		if (!Read2.readElements(currline)){
			return 0;
		}
		cout.rdbuf(ofs.rdbuf());
		//Assigning wheelbase
		Vehicle ReadWheelbase(Read2, Read1.getElements().at(0));

		cout.rdbuf(standardOutOutputStreamBuffer);
		cout << "Stat x0 " << ReadWheelbase.getState()->getElements().at(2) << endl;
		cout.rdbuf(ofs.rdbuf());
		//cout << "ReadWheelbase.getWheelbase(): " << ReadWheelbase.getWheelbase() << endl;
		//cout << "Gets: " << Read2.getX() << "," << Read2.getY() << "," << Read2.getDelta() << "," << Read2.getTheta() << endl;

		//Reading in Dt
		stringstream s3;
		MathVector Read3(1);
		getline(inF, currline);
		s3.str(currline);
		s3 >> trash;
		s3 >> currline;
		cout.rdbuf(standardOutOutputStreamBuffer);
		if (!Read3.readElements(currline)){
			return 0;
		}
		cout.rdbuf(ofs.rdbuf());
		
		//Reading Inputs
		Input TheInput;
		getline(inF, currline);
		//currline = trim(currline);
		cout.rdbuf(standardOutOutputStreamBuffer);
		if (!TheInput.readElements(currline)){
			return 0;
		}
		cout.rdbuf(ofs.rdbuf());

		TheInput.updateInput(TheInput.getElements().at(0), TheInput.getElements().at(1));
		//passing initial values to initialize TheDirector
		Director TheDirector(Read2.getElements().at(0), Read2.getElements().at(1), Read2.getElements().at(2), Read2.getElements().at(3), ReadWheelbase.getWheelbase(), TheInput.getElements().at(0), TheInput.getElements().at(1));
		
		// intial dt and print intitial dt
		double time = 0;
		cout << setprecision(3) << fixed << time << ",";

		//printing initial values
		TheDirector.printInitial();
		cout << setprecision(3) << fixed << "," << TheInput.getElements().at(0) << "," << TheInput.getElements().at(1);
		//cout << TheInput.getV(0) << "," << TheInput.getDeltaDot(0) << endl;
		
		
		double wheelBase = ReadWheelbase.getWheelbase();
		double pastX = Read2.getElements().at(0);
		double pastY = Read2.getElements().at(1);
		double pastDelta = Read2.getElements().at(2);
		double pastTheta = Read2.getElements().at(3);
		double pastVelocity = TheInput.getElements().at(0);
		double pastDeltaDot = TheInput.getElements().at(1);
		
		double currentX = pastX;
		double currentY = pastY;
		double currentDelta = pastDelta;
		double currentTheta = pastTheta;

		int a = 1;
		//getline loop
		for (unsigned int i = 0; getline(inF, currline); i++){
			//cout << setprecision(3) << fixed << "," << TheInput.getElements().at(0) << "," << TheInput.getElements().at(1) << endl;
			//s4.str(currline);
			//currline = trim(currline);

			//get past state
			//set current state
			cout << endl;
			//Dt increments
			time = (0.1) * a;
			a++;
			cout << setprecision(3) << fixed << time << ",";

			currentDelta = pastDelta + (0.100 * pastDeltaDot);
			if (currentDelta < -0.5236){
				currentDelta = -0.5236;
			}
			if (currentDelta > 0.5236){
				currentDelta = 0.5236;
			}
			currentTheta = pastTheta + (0.100 * pastVelocity * (1.0 / wheelBase) * sin(pastDelta));
			while (currentTheta < 0){
				currentTheta = currentTheta + (2 * M_PI);
			}
			while (currentTheta > 2 * M_PI){
				currentTheta = currentTheta - (2 * M_PI);
			}
			currentX = pastX + (0.100 * pastVelocity * cos(pastDelta) * cos(pastTheta));
			currentY = pastY + (0.100 * pastVelocity * cos(pastDelta) * sin(pastTheta));
			
			cout << setprecision(3) << fixed << currentX << "," << currentY << "," << currentDelta << "," << currentTheta;

			//read input
			cout.rdbuf(standardOutOutputStreamBuffer);
			TheInput.readElements(currline);
			cout.rdbuf(ofs.rdbuf());

			pastX = currentX;
			pastY = currentY;
			pastDelta = currentDelta;
			pastTheta = currentTheta;
			pastVelocity = TheInput.getElements().at(0);
			pastDeltaDot = TheInput.getElements().at(1);
			
			
			cout << setprecision(3) << fixed << "," << TheInput.getElements().at(0) << "," << TheInput.getElements().at(1);
			//set inputs in Director
			/*TheDirector.setCurrentDelta();
			TheDirector.setCurrentTheta();
			TheDirector.setCurrentX();
			TheDirector.setCurrentY();*/
			
			//print current values of x, y, delta, theta
			//TheDirector.printCurrentValues();
			
			//read input
			/*cout.rdbuf(standardOutOutputStreamBuffer);
			TheInput.readElements(currline);
			cout.rdbuf(ofs.rdbuf());*/
			//assign new elements to pastVelocity and pastDeltaDot in TheDirector
			/*TheDirector.setPastVelocity(TheInput.getElements().at(0));
			TheDirector.setPastDeltaDot(TheInput.getElements().at(1));*/

			//assign used values to past values in TheDirector
			/*TheDirector.setPastX(TheDirector.currentX);
			TheDirector.setPastY(TheDirector.currentY);
			TheDirector.setPastDelta(TheDirector.currentDelta);
			TheDirector.setPastTheta(TheDirector.currentTheta);*/
		}

		cout << endl;
		time = (0.1) * a;
		a++;
		cout << setprecision(3) << fixed << time << ",";

		currentDelta = pastDelta + (0.100 * TheInput.getElements().at(1));
		if (currentDelta < -0.5236){
			currentDelta = -0.5236;
		}
		if (currentDelta > 0.5236){
			currentDelta = 0.5236;
		}
		currentTheta = pastTheta + (0.100 * TheInput.getElements().at(0) * (1.0 / wheelBase) * sin(pastDelta));
		if (currentTheta < 0){
			currentTheta = 0;
		}
		if (currentTheta > 2 * M_PI){
			currentTheta = 2 * M_PI;
		}
		currentX = pastX + (0.100 * TheInput.getElements().at(0) * cos(pastDelta) * cos(pastTheta));
		currentY = pastY + (0.100 * TheInput.getElements().at(0) * cos(pastDelta) * sin(pastTheta));
		cout << setprecision(3) << fixed << currentX << "," << currentY << "," << currentDelta << "," << currentTheta << endl;
		//set inputs in Director
		/*TheDirector.setCurrentDelta();
		TheDirector.setCurrentTheta();
		TheDirector.setCurrentX();
		TheDirector.setCurrentY();
		*/

		/*cout << endl;
		time = (0.1)*a;
		cout << setprecision(3) << fixed << time << ",";*/
		//print current values of x, y, delta, theta
		//TheDirector.printCurrentValues();
	}
	cout.rdbuf(standardOutOutputStreamBuffer);
	ofs.close();

	return 0;
}

