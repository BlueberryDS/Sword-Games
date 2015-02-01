//============================================================================
// Name        : swords.cpp
// Author      : dong shi
// Version     :
// Copyright   : free
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Mainwindow.cpp"
#include "StrokeHandler.cpp"
#include "Charactor.cpp"
#include <iostream>
using namespace std;
using namespace sf;

int main() {
	Event event;
	mainwindow win;
	SH strokehandler(win.height(), win.width());
	bool winOpen=true;
	charactor test;

	statestructure state;
	statestructure state2;
	state.setposition(0,0);
	state.collisondata(100,100);
	state2.setposition(1,1);
	state2.collisondata(50,50);
	cout<<state.checkoverlapagainst(&state2,100,100)<<endl;



	while(winOpen){
		win.win.Clear(Color::White);
		test.update();

			while (win.getevent(&event)){//SFML events

			    		if (event.Type == Event::KeyPressed){
			    			if (event.Key.Code == Key::Escape) winOpen = false;
			    		}

			    		if(event.Type == Event::MouseButtonPressed){
			    			if(event.MouseButton.Button == Mouse::Left){
			    				strokehandler.startstroke(event.MouseButton.X, event.MouseButton.Y);
			    						switch (strokehandler.getstartstroke()){
			    						case leftdown:
			    						case rightdown:
			    						case down:
			    							test.startvertdownnow();
			    							break;
			    						case rightup:
			    						case leftup:
			    						case up:
			    							test.startvertupnow();
			    							break;
			    						case 3://right, using numaric
			    							test.startthrustnow();
			    							break;
			    						default:
			    							cout<<'?'<<endl;
			    						}
			    			}
			    		}
			    		if (event.Type == Event::MouseButtonReleased) {
			    			if(event.MouseButton.Button == Mouse::Left){
			    				strokehandler.endstroke(event.MouseButton.X, event.MouseButton.Y);
			    				switch (strokehandler.getstroke()){
	    						case leftdown:
	    						case rightdown:
			    				case down:
	    							test.vertdownnow();
	    							break;
	    						case rightup:
	    						case leftup:
	    						case up:
	    							test.vertupnow();
	    							break;
	    						case 3://right, using numaric
	    							test.thrustnow();
	    							break;
	    						default:
	    							test.reset();
			    				}
			    			}
			    		}
			}

		//realtime inputs
			const sf::Input& input = win.win.GetInput();
		if(input.IsKeyDown(Key::Right)) test.foward();
		if(input.IsKeyDown(Key::Left)) test.backwards();
		if((!input.IsKeyDown(Key::Right))&&(!input.IsKeyDown(Key::Left))) test.stopmoving();

			win.win.Draw(*test.returnsprite());
			win.display();
	}
	return 0;
}
