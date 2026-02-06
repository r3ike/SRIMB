#pragma once
#include "../srimb_topic.hpp"

struct ImuData {
    float ax, ay, az;
    float gx, gy, gz;
};

extern SRIMB_Topic<ImuData> topic_imu;
