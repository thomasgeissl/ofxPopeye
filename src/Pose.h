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
			if (index >= 0)
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
			if (id == "nose")
			{
				return POINT::NOSE;
			}
			if (id == "left_eye_inner")
			{
				return POINT::LEFT_EYE_INNER;
			}
			if (id == "left_eye")
			{
				return POINT::LEFT_EYE;
			}
			if (id == "left_eye_outer")
			{
				return POINT::LEFT_EYE_OUTER;
			}
			if (id == "right_eye_inner")
			{
				return POINT::RIGHT_EYE_INNER;
			}
			if (id == "right_eye")
			{
				return POINT::RIGHT_EYE;
			}
			if (id == "right_eye_outer")
			{
				return POINT::RIGHT_EYE_OUTER;
			}
			if (id == "left_ear")
			{
				return POINT::LEFT_EAR;
			}
			if (id == "right_ear")
			{
				return POINT::RIGHT_EAR;
			}
			if (id == "mouth_left")
			{
				return POINT::MOUTH_LEFT;
			}
			if (id == "mouth_right")
			{
				return POINT::MOUTH_RIGHT;
			}
			if (id == "left_shoulder")
			{
				return POINT::LEFT_SHOULDER;
			}
			if (id == "right_shoulder")
			{
				return POINT::RIGHT_SHOULDER;
			}
			if (id == "left_elbow")
			{
				return POINT::LEFT_ELBOW;
			}
			if (id == "right_elbow")
			{
				return POINT::RIGHT_ELBOW;
			}
			if (id == "left_wrist")
			{
				return POINT::LEFT_WRIST;
			}
			if (id == "right_wrist")
			{
				return POINT::RIGHT_WRIST;
			}
			if (id == "left_pinky")
			{
				return POINT::LEFT_PINKY;
			}
			if (id == "right_pinky")
			{
				return POINT::RIGHT_PINKY;
			}
			if (id == "left_index")
			{
				return POINT::LEFT_INDEX;
			}
			if (id == "right_index")
			{
				return POINT::RIGHT_INDEX;
			}
			if (id == "left_thumb")
			{
				return POINT::LEFT_THUMB;
			}
			if (id == "right_thumb")
			{
				return POINT::RIGHT_THUMB;
			}
			if (id == "left_hip")
			{
				return POINT::LEFT_HIP;
			}
			if (id == "right_hip")
			{
				return POINT::RIGHT_HIP;
			}
			if (id == "left_knee")
			{
				return POINT::LEFT_KNEE;
			}
			if (id == "right_knee")
			{
				return POINT::RIGHT_KNEE;
			}
			if (id == "left_ankle")
			{
				return POINT::LEFT_ANKLE;
			}
			if (id == "right_ankle")
			{
				return POINT::RIGHT_ANKLE;
			}
			if (id == "left_heel")
			{
				return POINT::LEFT_HEEL;
			}
			if (id == "right_heel")
			{
				return POINT::RIGHT_HEEL;
			}
			if (id == "left_foot_index")
			{
				return POINT::LEFT_FOOT_INDEX;
			}
			if (id == "right_foot_index")
			{
				return POINT::RIGHT_FOOT_INDEX;
			}

			return -1;
		}
		glm::vec3 _positions[33];
		uint64_t _lastUpdatedTimestamp;
	};
};