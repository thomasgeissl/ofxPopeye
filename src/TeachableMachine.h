#pragma once
#include "ofxOscReceiver.h"
#include "ofMain.h"

namespace ofxPopeye
{
    class TeachableMachine
    {
    public:
        void setConfidence(std::string label, float confidence)
        {
            _confidences[label] = confidence;
            _lastUpdatedTimestamp = ofGetElapsedTimeMillis();
        }
        static bool cmp(std::pair<std::string, float> &a,
                        std::pair<std::string, float> &b)
        {
            return a.second < b.second;
        }
        std::vector<std::pair<std::string, float>> getSorted()
        {
            std::vector<std::pair<std::string, float>> result;
            for (auto &it : _confidences)
            {
                result.push_back(it);
            }
            std::sort(result.begin(), result.end(), cmp);
            return result;
        }

        std::map<std::string, float> _confidences;
        uint64_t _lastUpdatedTimestamp;
    };
};