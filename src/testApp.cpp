#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup() {
  kinect.init();
  kinect.open();

  colorImg.allocate(kinect.width, kinect.height);
  
  depthMap.allocate(kinect.width, kinect.height);
  depthMapThreshNear.allocate(kinect.width, kinect.height);
  depthMapThreshFar.allocate(kinect.width, kinect.height);
  
  thresholdNear = 230;
	thresholdFar  = 70;
  
  
}

//--------------------------------------------------------------
void testApp::update() {
  kinect.update();
  
  if( kinect.isFrameNew() ) {
    depthMap.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height);
    /*
    depthMapThreshNear = depthMap;
    depthMapThreshFar = depthMap;
    depthMapThreshNear.threshold(thresholdNear, true);
    depthMapThreshFar.threshold(thresholdFar);
    cvAnd(depthMapThreshNear.getCvImage(), depthMapThreshFar.getCvImage(), depthMap.getCvImage(), NULL);
     */
  }
}

//--------------------------------------------------------------
void testApp::draw() {
  depthMap.draw(0, 0, kinect.width, kinect.height);
}

//--------------------------------------------------------------
void testApp::exit() {

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key) {

}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
  
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
  
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
  
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
  
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}



