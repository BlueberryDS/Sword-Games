/*
 * Animation.cpp
 *
 *  Created on: Jan 11, 2012
 *      Author: dong
 */
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>
		using namespace std;
		using namespace sf;

	class animation{//does not include sprite, only manages images
	private:
		Image * images;
		int frameindex;
		int frames;
		bool stillframe;

	public:
		animation(string imagefolder, int frames, bool still=false){
			if(still){
				stillframe=true;
				images=new Image;
				images->LoadFromFile(imagefolder);
			}
			else {images = new Image[frames];
			for (int index=0;index<frames;index++){
				stringstream out;
				out<<index;
				if(images[index].LoadFromFile(imagefolder+out.str()))
					cout<<"image loading failed at"<<imagefolder+out.str()<<endl;
			}
			frameindex=0;
			frames=frames;
			stillframe=false;
			}
		}

		animation(){

		}

		void setanimation(string imagefolder, int framenum, bool still=false){
			if(still){
				stillframe=true;
				images=new Image;
				images->LoadFromFile(imagefolder);
			}
			else {images = new Image[framenum];
			for (int index=0;index<framenum;index++){
				stringstream out;
				out<<index;
				if(!images[index].LoadFromFile(imagefolder+out.str()+".png"))
					cout<<"image loading failed at"<<imagefolder+out.str()<<endl;
			}
			frameindex=0;
			frames=framenum;
			stillframe=false;
			}
		}

		Image * update(bool * fail, bool allowrepeat=false){
			if(stillframe){
				return images;
			}

			int returnframe=frameindex;
			frameindex++;

			if(frameindex == frames){
				if(allowrepeat){
					returnframe=0, frameindex=1;
				}
				else{
					*fail=true;
					frameindex=0;
					return &(images[0]);
				}
			}
			*fail=false;
			return &(images[returnframe]);

		}

		Image * reset(){
			frameindex=0;
			return &(images[0]);
		}
	};






