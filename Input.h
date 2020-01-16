//
//  Input.h
//

#ifndef Input_h
#define Input_h


#include "MathVector.h"

class Input : public MathVector {
public:
	Input() : MathVector(2) {
	}
	Input(double v, double delta) : MathVector(2){
		velocity.push_back(v);
		deltaDot.push_back(delta);
	}
	~Input() { }
	Input(const Input& other);
	void updateInput(double v, double delta){
		velocity.push_back(v);
		deltaDot.push_back(delta);
	}
	double getV(int index){
		return velocity.at(index);
	}
	double getDeltaDot(int index){
		return deltaDot.at(index);
	}
private:
	vector<double> velocity;
	vector<double> deltaDot;
};

#endif /* Input_h */
