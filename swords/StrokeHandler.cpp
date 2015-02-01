/*
 * StrokeHandler.cpp
 *
 *  Created on: Jan 8, 2012
 *      Author: dong
 */

#include <SFML/Graphics.hpp>
#include <iostream>

enum stroke{
	fal = 0,
	down=1,
	up=2,
	right=3,
	left=4,
	rightup=5,//Diagonal in what direction, to what corner
	rightdown=6,
	leftup=7,
	leftdown=8
};
enum quad{
	A1=0,A2=1,A3=2,
	B1=3,B2=4,B3=5,
	C1=6,C2=7,C3=8,
	null
};

class SH {
private:

int xd;
int xdd;
int yd;
int ydd;

struct cord{
	int x;
	int y;
};

cord start;
cord end;

quad findquad(int x, int y){

	if(x<=xd){
		if(y<=yd){
			return A1;
		}
		if(y<=ydd){
			return B1;
		}
		if (y>ydd){
			return C1;
		}
	}
	if(x<=xdd){
		if(y<=yd){
			return A2;
		}
		if(y<=ydd){
			return B2;
		}
		if (y>ydd){
			return C2;
		}
	}
	if (x>xdd){
		if(y<=yd){
			return A3;
		}
		if(y<=ydd){
			return B3;
		}
		if (y>ydd){
			return C3;
		}
	}
	return null;
}


public:

bool done;

SH(int height, int width){
	xd=width/3;
	xdd=2*(width/3);
	yd=height/3;
	ydd=2*(height/3);
	done=false;
}

void startstroke (int x, int y){
	done=false;
	start.x=x;
	start.y=y;
}

stroke getstartstroke(){
	quad qauder = findquad(start.x, start.y);
		if (qauder == C2) return up;
		if (qauder == A2) return down;
		if (qauder == B1) return right;
		if (qauder == B3) return left;
		if (qauder == A1) return rightdown;
		if (qauder == C1) return rightup;
		if (qauder == C3) return leftup;
		if (qauder == A3) return leftdown;
		return fal;
}

void endstroke (int x, int y){
	done=true;
	end.x=x;
	end.y=y;
}

stroke getstroke(){
	if(!done) return fal;
	quad s=findquad(start.x,start.y);
	quad e=findquad(end.x, end.y);
	done = false;

	if (s == C2 && e == A2) return up;
	if (s == A2 && e == C2) return down;
	if (s == B1 && e == B3) return right;
	if (s == B3 && e == B1) return left;
	if (s == A1 && e == C3) return rightdown;
	if (s == C1 && e == A3) return rightup;
	if (s == C3 && e == A1) return leftup;
	if (s == A3 && e == C1) return leftdown;
	return fal;
}

};
