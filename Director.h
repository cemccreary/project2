#ifndef Director_h
#define Director_h
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

class Director {
public:
	Director(double x, double y, double delta, double theta, double wheelbase, double velocity, double deltaDot){
		pastX = x;
		pastY = y;
		pastDelta = delta;
		pastTheta = theta;
		//velocity
		pastVelocity = velocity;
		//velocity angular rate of change for tire angle
		pastDeltaDot = deltaDot;
		//wheelbase
		wheelBase = wheelbase;
	}
	//double getx2() {
	//	return x1;
	//}
	////do 4th
	//double getx2(){
	//	return x2;
	//}
	////do 1st
	//double getx3(){
	//	return x3;
	//}
	////do 2nd
	//double getx4(){
	//	return x4;
	//}
	/*void setx3(double inU2Angular) {
		x3 = inU2Angular ;
	}*/
	/*void setx4(double inU1Velocity, double inLWheelbase, double inU2Angular) {
		x4 = inU1Velocity * (1 / inLWheelbase) * sin(inU2Angular);
	}*/
	/*void setu1(double inU1Velocity){
		u1 = inU1Velocity;
	}
	void setu2(double inU2deltDot){
		u2 = inU2deltDot;
	}*/
	void printInitial(){
		std::cout << pastX << "," << pastY << "," << pastDelta << "," << pastTheta;
	}
	void printCurrentValues(){
		cout << setprecision(3) << fixed << currentX << "," << currentY << "," << currentDelta << "," << currentTheta;
	}
	void calculateAndPrint(){
		currentDelta = pastDelta + 0.1 * pastDeltaDot;
		currentTheta = pastTheta + 0.1 * pastVelocity * (1 / wheelBase) * sin(pastDelta);
		currentX = pastX + 0.1 * pastVelocity * cos(pastDelta) * cos(pastTheta);
		currentY = pastY + 0.1 * pastVelocity * cos(pastDelta) * sin(pastTheta);
		cout << setprecision(3) << fixed << currentX << "," << currentY << "," << currentDelta << "," << currentTheta;
	}
	void setCurrentX(){
		currentX = pastX + 0.1 * pastVelocity * cos(pastDelta) * cos(pastTheta);
	}
	void setCurrentY(){
		currentY = pastY + 0.1 * pastVelocity * cos(pastDelta) * sin(pastTheta);
	}
	void setCurrentDelta(){
		currentDelta = pastDelta + 0.1 * pastDeltaDot;
	}
	void setCurrentTheta(){
		currentTheta = pastTheta + 0.1 * pastVelocity * (1 / wheelBase) * sin(pastDelta);
	}
	//after a state is printed, send the used values to these functions
	void setPastX(double usedX){
		pastX = usedX;
	}
	void setPastY(double usedY){
		pastY = usedY;
	}
	void setPastDelta(double usedDelta){
		pastDelta = usedDelta;
	}
	void setPastTheta(double usedTheta){
		pastTheta = usedTheta;
	}
	void setPastVelocity(double usedVelocity){
		pastVelocity = usedVelocity;
	}
	void setPastDeltaDot(double usedDeltaDot){
		pastVelocity = usedDeltaDot;
	}
	
	double wheelBase;

	double currentX;
	double currentY;
	double currentDelta;
	double currentTheta;

	double pastX;
	double pastY;
	double pastDelta;
	double pastTheta;
	double pastVelocity;
	double pastDeltaDot;
	
	
	//double x1;
	//double x2;
	//double x3;
	//double x4;
	////velocity
	//double u1;
	////velocity angular rate of change for tire angle
	//double u2;
	////wheelbase
	//double L;
};

#endif