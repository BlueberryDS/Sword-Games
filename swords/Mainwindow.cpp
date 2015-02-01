/*
 * Mainwindow.cpp
 *
 *  Created on: Jan 8, 2012
 *      Author: dong
 */
#include <SFML/Graphics.hpp>
#include <iostream>
namespace sf{

class mainwindow{
private:
public:
	RenderWindow win;
		mainwindow(){
		win.Create(VideoMode::GetDesktopMode(), "Sword Game - By Dong",Style::Fullscreen);
		win.Clear(Color::White);
		win.SetFramerateLimit(20);
	}
	void display(){
		win.Display();
	}
	bool getevent(Event * event){
		return win.GetEvent(*event);
	}
	int height(){
		return win.GetHeight();
	}
	int width(){
		return win.GetWidth();
	}
};
}
