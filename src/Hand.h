#pragma once
#include "ofxOscReceiver.h"
#include "ofMain.h"

namespace ofxPopeye
{
	class Hand
	{
	public:
		enum POINT
		{
			WRIST = 0,
			THUMB_CMC,
			THUMB_MCP,
			THUMB_IP,
			THUMB_TIP,
			INDEX_FINGER_MCP,
			INDEX_FINGER_PIP,
			INDEX_FINGER_DIP,
			INDEX_FINGER_TIP,
			MIDDLE_FINGER_MCP,
			MIDDLE_FINGER_PIP,
			MIDDLE_FINGER_DIP,
			MIDDLE_FINGER_TIP,
			RING_FINGER_MCP,
			RING_FINGER_PIP,
			RING_FINGER_DIP,
			RING_FINGER_TIP,
			PINKY_MCP,
			PINKY_PIP,
			PINKY_DIP,
			PINKY_TIP
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
			if (id == "wrist")
			{
				return POINT::WRIST;
			}
			else if (id == "thumb_cmc")
			{
				return POINT::THUMB_CMC;
			}
			else if (id == "thumb_mcp")
			{
				return POINT::THUMB_MCP;
			}
			else if (id == "thumb_ip")
			{
				return POINT::THUMB_IP;
			}
			else if (id == "thumb_tip")
			{
				return POINT::THUMB_TIP;
			}
			else if (id == "index_finger_mcp")
			{
				return POINT::INDEX_FINGER_MCP;
			}
			else if (id == "index_finger_pip")
			{
				return POINT::INDEX_FINGER_PIP;
			}
			else if (id == "index_finger_dip")
			{
				return POINT::INDEX_FINGER_DIP;
			}
			else if (id == "index_finger_tip")
			{
				return POINT::INDEX_FINGER_TIP;
			}
			else if (id == "middle_finger_mcp")
			{
				return POINT::MIDDLE_FINGER_MCP;
			}
			else if (id == "middle_finger_pip")
			{
				return POINT::MIDDLE_FINGER_PIP;
			}
			else if (id == "middle_finger_dip")
			{
				return POINT::MIDDLE_FINGER_DIP;
			}
			else if (id == "middle_finger_tip")
			{
				return POINT::MIDDLE_FINGER_TIP;
			}
			else if (id == "ring_finger_mcp")
			{
				return POINT::RING_FINGER_MCP;
			}
			else if (id == "ring_finger_pip")
			{
				return POINT::RING_FINGER_PIP;
			}
			else if (id == "ring_finger_dip")
			{
				return POINT::RING_FINGER_DIP;
			}
			else if (id == "ring_finger_tip")
			{
				return POINT::RING_FINGER_TIP;
			}
			else if (id == "pinky_mcp")
			{
				return POINT::PINKY_MCP;
			}
			else if (id == "pinky_pip")
			{
				return POINT::PINKY_PIP;
			}
			else if (id == "pinky_dip")
			{
				return POINT::PINKY_DIP;
			}
			else if (id == "pinky_tip")
			{
				return POINT::PINKY_TIP;
			}
			return -1;
		}
		glm::vec3 _positions[21];
		uint64_t _lastUpdatedTimestamp;
	};
};