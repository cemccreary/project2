//
//  Vehicle.hpp
//

#ifndef Vehicle_h
#define Vehicle_h


#include "State.h"
#include "Input.h"

class Vehicle {

public:
	// vehicle should start at 0, 0, 0, 0 if nothing is passed in. It should
	// allocate a default value of State of 0, 0, 0, 0
	Vehicle();
	// vehicle should make a copy of the data in x0 and allocate new memory
	// to hold its state value
	Vehicle(State x0, double wheelbase){
		this->state = new State(x0);
		this->wheelbase = wheelbase;
	}
	// implementation should delete the state variable data
	~Vehicle(){
		delete state;
	}
	// return the wheelbase value
	double getWheelbase(){
		return this->wheelbase;
	}
	// returns a pointer to the current state. The calling object should make
	// a deep copy of the data if it wants to keep it
	State* update(Input* u, double ts = 0.1);
	// returns a pointer to the current state. The calling object should make
	// a deep copy of the data if it wants to keep it
	State* getState(){
		return state;
	}


private:
	double wheelbase;
	State* state;


};

#endif /* Vehicle_h */
