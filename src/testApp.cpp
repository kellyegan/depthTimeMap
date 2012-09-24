#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup() {
  ofSetFrameRate(24);

  kinect.init();
  kinect.open();
  
  video.loadMovie("Symptoms1940_deinterlaced.mov");
  video.play();
  video.setSpeed(1.0);
  
  depth = false;
  inverse = false;
  fullscreen = false;

  colorImg.allocate(kinect.width, kinect.height);
  
  depthMap.allocate(kinect.width, kinect.height);
  depthMapThreshNear.allocate(kinect.width, kinect.height);
  depthMapThreshFar.allocate(kinect.width, kinect.height);
  
  thresholdNear = 230;
	thresholdFar  = 100;
  
  warp.setup(kinect.width, kinect.height, 128);
  warp.setBlending(true);
  warp.setDelayMap(depthMap.getPixels(), OF_IMAGE_GRAYSCALE);
  
  whiteImage.allocate(kinect.width, kinect.height);
  whiteImage.set(255.0);
}

//--------------------------------------------------------------
void testApp::update() {
  kinect.update();
  video.idleMovie();

  if( video.isFrameNew() ) {
    //inputImage.setFromPixels(video.getPixels(), vidWidth, vidHeight);
    //warp.addImage(video.getPixels());
  }
  
  
  if( kinect.isFrameNew() ) {
    
    warp.addImage(kinect.getPixels());
    
    
    depthMap.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height);
    
    depthMapThreshNear = depthMap;
    depthMapThreshFar = depthMap;
    //depthMapThreshNear.threshold(thresholdNear, true);
    depthMapThreshFar.threshold(thresholdFar);
    cvAnd(depthMapThreshNear.getCvImage(), depthMapThreshFar.getCvImage(), depthMap.getCvImage(), NULL);
    
    depthMap.blurHeavily();
    depthMap.dilate_3x3();
    //depthMap.blurHeavily();
    if( inverse ) {
      depthMap.absDiff(whiteImage);
    }
    
    warp.setDelayMap(depthMap.getPixels(), OF_IMAGE_GRAYSCALE);
  }
}

//--------------------------------------------------------------
void testApp::draw() {
  if(depth) {
    depthMap.draw(0, 0, ofGetWidth(), ofGetHeight());
  } else {
    warp.getOutputImage()->draw(0, 0, ofGetWidth(), ofGetHeight());
  }
}

//--------------------------------------------------------------
void testApp::exit() {
  
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key) {
  //Convert uppercase to lowercase
  if (key >=65 && key <= 90) {
    key += 32; 
  }
  switch (key) {
    case OF_KEY_UP:
      thresholdFar++;
      break;
    case OF_KEY_DOWN:
      thresholdFar--;
      break;
    case 'd':
      depth = !depth;
      break;
    case 'i':
      inverse = !inverse;
      break;
    case 'f':
      fullscreen = !fullscreen;
      ofSetFullscreen(fullscreen);
      break;
    default:
      break;
  }
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



