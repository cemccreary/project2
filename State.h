//
//  State.h
//

#ifndef State_h
#define State_h


#include "MathVector.h"

class State : public MathVector {
public:
	State() : MathVector(4) {
	x = 0;
	y = 0;
	delta = 0;
	theta = 0;
}
	State(double x, double y, double delta, double theta) : MathVector(4){
		this->x = x;
		this->y = y;
		this->delta = delta;
		this->theta = theta;

			
	}
	~State() { }
	State(const State& other) : MathVector(4) {
		*this = other;
	}
	double getX(){
		return x;
	}
	double getY(){
		return y;
	}
	double getDelta(){
		return delta;
	}
	double getTheta(){
		return theta;
	}
	void setX(double newX){
		x = newX;
	}
	void setY(double newY){
		y = newY;
	}
	void setDelta(double newDelta){
		delta = newDelta;
	}
	void setTheta(double newTheta){
		theta = newTheta;
	}

private:
	double x; 
	double y; 
	double delta; 
	double theta;
};

#endif /* State_h */
