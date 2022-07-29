#pragma once
#include "ofxOscReceiver.h"
#include "ofMain.h"

namespace ofxPopeye
{
	class Pose
	{
	public:
		enum POINT
		{
			NOSE = 0,
			LEFT_EYE_INNER,
			LEFT_EYE,
			LEFT_EYE_OUTER,
			RIGHT_EYE_INNER,
			RIGHT_EYE,
			RIGHT_EYE_OUTER,
			LEFT_EAR,
			RIGHT_EAR,
			MOUTH_LEFT,
			MOUTH_RIGHT,
			LEFT_SHOULDER,
			RIGHT_SHOULDER,
			LEFT_ELBOW,
			RIGHT_ELBOW,
			LEFT_WRIST,
			RIGHT_WRIST,
			LEFT_PINKY,
			RIGHT_PINKY,
			LEFT_INDEX,
			RIGHT_INDEX,
			LEFT_THUMB,
			RIGHT_THUMB,
			LEFT_HIP,
			RIGHT_HIP,
			LEFT_KNEE,
			RIGHT_KNEE,
			LEFT_ANKLE,
			RIGHT_ANKLE,
			LEFT_HEEL,
			RIGHT_HEEL,
			LEFT_FOOT_INDEX,
			RIGHT_FOOT_INDEX
		};
		void setPosition(std::string id, float x, float y, float z)
		{
			auto index = getIndex(id);
			if (index > 0)
			{
				_positions[index] = glm::vec3(x, y, z);
			}
			_lastUpdatedTimestamp = ofGetElapsedTimeMillis();
		}
		glm::vec3 getPosition(POINT point)
		{
			return _positions[point];
		}

		// private:
		int getIndex(std::string id)
		{

			return -1;
		}
		glm::vec3 _positions[33];
		uint64_t _lastUpdatedTimestamp;
	};
};