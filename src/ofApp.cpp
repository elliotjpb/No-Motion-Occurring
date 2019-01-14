#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  //audio set up
  sound.load("audio.wav");
  sound.play();
  sound.setVolume(1);
  sound.setSpeed(0.1);
  //Interfacing with GPIO pins with wiriringPi
  A_PIN = 14;

  if(wiringPiSetup() == -1){
    printf("Error on wiringPi setup\n");
}
    pinMode(14,INPUT);
    sensor14 = false;
}

//--------------------------------------------------------------
void ofApp::update(){

  if(digitalRead(14)!=0){
    sensor14 = true;
    std::cout << "true" << '\n'; //sound playing slow
} else {
    sensor14 = false;
    std::cout << "false" << '\n'; //sound playing normal
}

  if (sensor14 == true){
    rampDown(); //When motion detected play sound really slow
  }
  if (sensor14 == false){
    rampUp(); // When no motion detected play sound normally
  }

}

//--------------------------------------------------------------
void ofApp::draw(){


}

//--------------------------------------------------------------
void ofApp::rampUp(){

    float checkUp;

    checkUp = sound.getSpeed();

    if (checkUp < 0.2){

        for(float j = 0.1; j < 1.1; j = j + 0.1){
            usleep(100000);//slight delay to gradually increase value.
            sound.setSpeed(j);
            cout << j << endl;
        }

    }else if (checkUp > 0.2){

        sound.setSpeed(1);
    }

}
//--------------------------------------------------------------
void ofApp::rampDown(){

    float checkDown;

    checkDown = sound.getSpeed();

    if (checkDown > 0.2){

    for(float a = 1; a > 0; a = a - 0.1){
            usleep(100000); //delay
            sound.setSpeed(a);
            //cout << "ramp down : " << a << endl;
            cout << a << endl;
        }

    }else if (checkDown < 0.2){

        sound.setSpeed(0.1);
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){


}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
