/*
 * Charactor.cpp
 *
 *  Created on: Jan 12, 2012
 *      Author: dong
 */

#include "Animation.cpp"
#include "StateStructure.cpp"
#include <SFML/Graphics.hpp>

class charactor{
private:
	animation walk;
	statestructure data;
	Sprite person;
	animation vertdown;
	animation vertup;
	animation thrust;
	animation startvertdown;
	animation startvertup;
	animation startthrust;
	bool anistop;
	bool animationlock;
	bool stoped;
	void (charactor::*unlocked)(bool);

public:
	charactor(){
		walk.setanimation("./walk/", 10);
		startvertdown.setanimation("./vertdown/0.png",1,true);
		startvertup.setanimation("./vertup/0.png",1,true);
		startthrust.setanimation("./thrust/0.png",1,true);
		vertup.setanimation("./vertup/",5);
		vertdown.setanimation("./vertdown/",5);
		thrust.setanimation("./thrust/",5);

		data.setstatestructure(4);
		data.collisondata(356,629);
		person.SetImage(*walk.update(&anistop,true));
		person.SetPosition(100,0);
		data.setposition(100,0);
		animationlock=false;
	}

	void foward(bool exmp=false){
		if(exmp || !animationlock){
		person.Move(12,0);
		data.move(12,0);
		person.SetImage(*walk.update(&anistop,true));
		stoped = false;
		}
	}
	void backwards(bool exmp=false){
		if(exmp || !animationlock){
		person.Move(-12,0);
		data.move(-12,0);
		person.SetImage(*walk.update(&anistop,true));
		stoped = false;
		}
	}

	void stopmoving(){
		if (!stoped) {person.SetImage(*walk.reset());stoped = true;}
	}

	void update(){
		if(animationlock) (*this.*unlocked)(true);
	}

	void startvertdownnow(bool exmp=false){
		if(!animationlock || exmp){
			animationlock=true;
			person.SetImage(*startvertdown.update(&anistop));
			unlocked = &charactor::startvertdownnow;
		}
	}

	void vertdownnow(bool exmp=false){
		if (animationlock){
			person.SetImage(*vertdown.update(&anistop));
			animationlock = !anistop;
			if (anistop) person.SetImage(*walk.reset());
			unlocked = &charactor::vertdownnow;
		}
		else {
			animationlock = false;
		}
	}

	void startvertupnow(bool exmp=false){
			if(!animationlock || exmp){
				animationlock=true;
				person.SetImage(*startvertup.update(&anistop));
				unlocked = &charactor::startvertupnow;
			}
		}

		void vertupnow(bool exmp=false){
			if (animationlock){
				person.SetImage(*vertup.update(&anistop));
				animationlock = !anistop;
				if (anistop) person.SetImage(*walk.reset());
				unlocked = &charactor::vertupnow;
			}
			else {
				animationlock = false;
			}
		}

		void startthrustnow(bool exmp=false){
				if(!animationlock || exmp){
					animationlock=true;
					person.SetImage(*startthrust.update(&anistop));
					unlocked = &charactor::startthrustnow;
				}
			}

			void thrustnow(bool exmp=false){
				if (animationlock){
					person.SetImage(*thrust.update(&anistop));
					animationlock = !anistop;
					if (anistop) person.SetImage(*walk.reset());
					unlocked = &charactor::thrustnow;
				}
				else {
					animationlock = false;
				}
			}

	void reset(){
		animationlock=false;
		person.SetImage(*walk.reset());
	}

	Sprite * returnsprite(){
		return &person;
	}
};
