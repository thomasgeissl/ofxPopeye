#pragma once
#include "ofxOscReceiver.h"

class ofxPopeye
{
public:
	void setup(int port)
	{
		_oscReceiver.setup(port);
	}
	void update()
	{
		while (_oscReceiver.hasWaitingMessages())
		{
			ofxOscMessage m;
			_oscReceiver.getNextMessage(m);

			if (m.getAddress() == "/popeye/")
			{
				// mouseYf = m.getArgAsFloat(1);
			}
		}
	}

private:
	ofxOscReceiver _oscReceiver;
};