#pragma once
#include "ofxOscReceiver.h"
#include "./Hand.h"

namespace ofxPopeye
{
	class Manager
	{
	public:
		void setup(int port, std::string session = "")
		{
			_session = session;
			_oscReceiver.setup(port);
		}
		void update()
		{
			// receive positions
			while (_oscReceiver.hasWaitingMessages())
			{
				ofxOscMessage m;
				_oscReceiver.getNextMessage(m);
				// if a session id is set and address does not start with session id then return
				if (!_session.empty() && m.getAddress().rfind(_session, 0) != 0)
				{
					return;
				}
				auto parts = ofSplitString(m.getAddress(), "/");
				auto index = 0;
				std::string part = "";
				while (index < parts.size() && parts[index] != "popeye")
				{
					index++;
				}
				if (parts[index] == "popeye" && parts[index + 1] == "hands")
				{
					auto handIndex = ofToInt(parts[index + 2]);
					auto partId = parts[index + 3];
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
		std::string _session;
	};
};