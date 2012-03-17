#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"
#include "ofxSlitScan.h"

class testApp : public ofBaseApp {
	public:

		void setup();
		void update();
		void draw();
		void exit();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
  
    ofxKinect kinect;
  
  ofVideoPlayer video;
    
    ofxCvColorImage		colorImg;
  
    ofxCvGrayscaleImage depthMap;			        // grayscale depth image
    ofxCvGrayscaleImage depthMapThreshNear;		// the near thresholded image
    ofxCvGrayscaleImage depthMapThreshFar;		// the far thresholded image
    ofxCvGrayscaleImage whiteImage;           // white image for creating inverse
  
    int thresholdNear;
    int thresholdFar;
  
    ofxSlitScan warp;
  
    bool depth, inverse, fullscreen;
		
};
