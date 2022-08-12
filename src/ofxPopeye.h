#pragma once
#include "ofxOscReceiver.h"
#include "./Hand.h"
#include "./Pose.h"
#include "./TeachableMachine.h"

namespace ofxPopeye
{
	class Manager
	{
	public:
		void setup(int port, bool mirrored = false, std::string session = "")
		{
			_parameters.add(_session.set("session", session));
			_parameters.add(_mirrored.set("mirrored", mirrored));
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
				if (!_session->empty() && m.getAddress().rfind(_session, 0) != 0)
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
					_hands[handIndex].setPosition(partId, _mirrored ? 1 - x : x, y, z);
				}
				if (parts[index] == "popeye" && parts[index + 1] == "pose")
				{
					auto poseIndex = 0; // ofToInt(parts[3]);
					auto partId = parts[index + 2];
					auto x = m.getArgAsFloat(0);
					auto y = m.getArgAsFloat(1);
					auto z = m.getArgAsFloat(2);
					if (poseIndex >= _poses.size())
					{
						_poses.resize(poseIndex + 1);
					}
					_poses[poseIndex].setPosition(partId, _mirrored ? 1 - x : x, y, z);
				}

				if (parts[index] == "popeye" && parts[index + 1] == "tm")
				{
					auto label = parts[index + 2];
					auto confidence = m.getArgAsFloat(0);
					_teachableMachine.setConfidence(label, confidence);
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
			for (auto i = 0; i < _poses.size(); i++)
			{
				if (timestamp - _poses[i]._lastUpdatedTimestamp > 500)
				{
					_poses.erase(_poses.begin() + i);
					break;
				}
			}
		}

		// private:
		ofxOscReceiver _oscReceiver;
		std::vector<Hand> _hands;
		std::vector<Pose> _poses;
		TeachableMachine _teachableMachine;
		ofParameterGroup _parameters;
		ofParameter<std::string> _session;
		ofParameter<bool> _mirrored;
	};
};