#pragma once

#include "ofMain.h"
#include "wiringPi.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void rampUp();
		void rampDown();

		void tick();
		void pulse(int pos_pin, int neg_pin);

		bool sensor14;

		ofSoundPlayer sound;

		int A_PIN;
};
