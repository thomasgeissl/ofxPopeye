#include "ofApp.h"

void ofApp::setup()
{
    ofSetBackgroundColor(16, 16, 16);
    ofSetVerticalSync(true);
    ofEnableDepthTest();

    _popeye.setup(8000);
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
        auto position = hand.getPosition(ofxPopeye::Hand::POINT::INDEX_FINGER_TIP);

        ofDrawCircle(ofMap(position.x, 0, 2, width / 2 - 100, width / 2 + 100), ofMap(position.y, 0, 2, height / 2 - 100, height / 2 + 100), 20);
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
