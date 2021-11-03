#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofEnableDepthTest();

	this->font_size = 30;
	ofTrueTypeFontSettings font_settings("fonts/msgothic.ttc", this->font_size);
	font_settings.antialiased = true;
	font_settings.addRanges(ofAlphabet::Japanese);
	this->font.load(font_settings);

	this->words = {

		u8"Ê¯Ëß°", u8"ÊÞ°½ÃÞ²"
	};
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.66666666666666666);

	for (int k = 0; k < 300; k++) {

		auto location = glm::vec3(0, 0, 300 + ofRandom(-50, 50));

		ofPushMatrix();

		ofRotateZ(ofRandom(-360, 360));
		ofRotateY(ofRandom(-360, 360));
		ofRotateX(ofRandom(-360, 360));

		ofTranslate(location);

		ofRotateZ(ofRandom(-360, 360));

		ofColor color;
		color.setHsb(ofRandom(255), 130, 255);
		ofSetColor(color);

		int word_index = ofRandom(this->words.size());
		this->font.drawString(this->words[word_index], this->font_size * -0.65, this->font_size * -0.5);

		ofPopMatrix();
	}

	this->cam.end();
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}