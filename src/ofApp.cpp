#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){

  // sensor1 = false;
  // sensor4 = false;

  if(wiringPiSetup() == -1){
    printf("Error on wiringPi setup\n");
}

    positive_polarity = true;

    pinMode(1,OUTPUT);
    pinMode(4,OUTPUT);

}

//--------------------------------------------------------------
void ofApp::update(){

  tick();
  usleep(1000000);
  std::cout << "tick" << '\n';

}

//--------------------------------------------------------------
void ofApp::draw(){


}
//--------------------------------------------------------------
void ofApp::tick(){

//cout << "hello" << endl;
  // if (positive_polarity){
	// //cout << sensor5 << endl;
  //     sensor1 = true;
  //     sensor4 = false;
  //     usleep(30);
  //     sensor1 = false;
  // }else{
  //
  //   sensor4 = true;
  //   sensor1 = false;
  //   usleep(30);
  //   sensor4 = false;
  // }
  //
  // positive_polarity = false;

  if (positive_polarity){

      digitalWrite(1, HIGH);
      digitalWrite(4, LOW);
      delay(500);
      digitalWrite(1, LOW);
    }else{
      digitalWrite(4, HIGH);
      digitalWrite(1, LOW);
      delay(500);
      digitalWrite(4, LOW);
    }

    //positive_polarity = false;

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
