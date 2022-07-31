#include "ofApp.h"

void ofApp::setup()
{
    ofSetBackgroundColor(16, 16, 16);
    ofSetVerticalSync(true);
    ofEnableDepthTest();

    auto mirrored = true;
    _popeye.setup(8000, mirrored);
}

void ofApp::exit()
{
}

void ofApp::update()
{
    _popeye.update();
}

void ofApp::draw()
{
    // _cam.begin();
    ofSetColor(ofColor::white);
    auto width = ofGetWidth();
    auto height = ofGetHeight();
    // ofPushMatrix();
    // ofTranslate(-width / 2, -height / 2);
    for (auto hand : _popeye._hands)
    {
        // auto position = hand.getPosition(ofxPopeye::Hand::POINT::INDEX_FINGER_TIP);
        for (auto position : hand._positions)
        {
            ofDrawCircle(ofMap(position.x, 0, 1, width / 2 - 100, width / 2 + 100), ofMap(position.y, 0, 1, height / 2 - 100, height / 2 + 100), 5);
        }
    }

    for (auto pose : _popeye._poses)
    {
        // auto position = hand.getPosition(ofxPopeye::Hand::POINT::INDEX_FINGER_TIP);
        auto index = 0;
        for (auto position : pose._positions)
        {
            ofSetColor(ofColor::white);
            ofDrawCircle(ofMap(position.x, 0, 1, width / 2 - 100, width / 2 + 100), ofMap(position.y, 0, 1, height / 2 - 100, height / 2 + 100), 5);
            ofSetColor(ofColor::red);
            ofDrawBitmapString(ofToString(index),ofMap(position.x, 0, 1, width / 2 - 100, width / 2 + 100), ofMap(position.y, 0, 1, height / 2 - 100, height / 2 + 100) );
            index++;
        }
    }
    // ofPopMatrix();

    // _cam.end();
}

void ofApp::keyPressed(int key)
{
}
void ofApp::keyReleased(int key) {}
void ofApp::mouseMoved(int x, int y) {}
void ofApp::mouseDragged(int x, int y, int button) {}
void ofApp::mousePressed(int x, int y, int button) {}
void ofApp::mouseReleased(int x, int y, int button) {}
void ofApp::mouseEntered(int x, int y) {}
void ofApp::mouseExited(int x, int y) {}
void ofApp::windowResized(int w, int h) {}
void ofApp::gotMessage(ofMessage msg) {}
void ofApp::dragEvent(ofDragInfo dragInfo) {}
