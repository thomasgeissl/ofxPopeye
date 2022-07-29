#pragma once
#include "ofxOscReceiver.h"
#include "./Hand.h"

namespace ofxPopeye
{
	class Manager
	{
	public:
		void setup(int port)
		{
			_oscReceiver.setup(port);
		}
		void update()
		{
			// receive positions
			while (_oscReceiver.hasWaitingMessages())
			{
				ofxOscMessage m;
				_oscReceiver.getNextMessage(m);
				auto parts = ofSplitString(m.getAddress(), "/");
				// TODO: prefix
				if (parts[1] == "popeye" && parts[2] == "hands")
				{
					auto handIndex = ofToInt(parts[3]);
					auto partId = parts[4];
					auto x = m.getArgAsFloat(0);
					auto y = m.getArgAsFloat(1);
					auto z = m.getArgAsFloat(2);
					if (handIndex >= _hands.size())
					{
						_hands.resize(handIndex + 1);
					}
					_hands[handIndex].setPosition(partId, x, y, z);
				}
			}

			auto timestamp = ofGetElapsedTimeMillis();
			for (auto i = 0; i < _hands.size(); i++)
			{
				if (timestamp - _hands[i]._lastUpdatedTimestamp > 500)
				{
					_hands.erase(_hands.begin() + i);
					break;
				}
			}
		}

		// private:
		ofxOscReceiver _oscReceiver;
		std::vector<Hand> _hands;
	};
};