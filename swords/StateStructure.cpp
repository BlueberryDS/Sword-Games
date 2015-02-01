/*
 * StateStructure.cpp
 *
 *  Created on: Jan 11, 2012
 *      Author: dong
 */
#include "STATES.cpp"

class statestructure{
private:
	bool btwn(int one , int x, int two){
		return (one<x && x<two);
	}

	bool*states;
	unsigned int index;
	struct xandy{
		unsigned int x;
		unsigned int y;
	}boxsize, position;

	bool checkoverlap(unsigned int x, unsigned int y,unsigned int sizex, unsigned int sizey){
		if((btwn(position.x, x, position.x+boxsize.x)||btwn(position.x, x+sizex, position.x+boxsize.x))
				&&(btwn(position.y, y, position.y+boxsize.y)||btwn(position.y, y+sizey, position.y+boxsize.y)))return true;
		return false;
	}

public:
	statestructure( unsigned int statenum){
		states=new bool[statenum];
		index=statenum;
		for(unsigned int count=0; count<index; count++){
			states[count]=false;
		}
	}

	statestructure(){

	}

	void setstatestructure(unsigned int statenum){
		states=new bool[statenum];
		index=statenum;
	}

	bool setstate(unsigned int state){
		if (state<index){
			states[state]=true;
			return true;
		}
		return false;
	}
	bool getstate(unsigned int state){
		if (state<index){
			return states[state];
		}
	}

	void collisondata(unsigned int sizex, unsigned int sizey){
		boxsize.x=sizex;
		boxsize.y=sizey;
	}

	void setposition(unsigned int x, unsigned int y){
		position.x=x;
		position.y=y;
	}

	void move(unsigned int x, unsigned int y){
		position.x+=x;
		position.y+=y;
	}

	unsigned int getwidth(){
		return boxsize.x;
	}
	unsigned int getheight(){
		return boxsize.y;
	}

	unsigned int getx(){
		return position.x;
	}
	unsigned int gety(){
		return position.y;
	}

	bool checkoverlapagainst(statestructure * target, unsigned int newx,unsigned int newy, bool tryagain=false){
		return target->checkoverlap(newx,newy,boxsize.x,boxsize.y)||tryagain||target->checkoverlapagainst(this,newx, newy);
	}

};
