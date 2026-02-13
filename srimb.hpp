#pragma once
#include "srimb_topic.hpp"

struct SRIMB_Sub {
    uint64_t last_generation = 0;
};

template<typename T>
inline void srimb_publish(SRIMB_Topic<T>& topic, const T& data, uint64_t now)
{
    topic.data = data;
    topic.timestamp = now;
    topic.generation++;
};

template<typename T>
inline bool srimb_copy(SRIMB_Topic<T>& topic, SRIMB_Sub& sub, T& out, uint64_t& timestamp ) {
    if (sub.last_generation == topic.generation)
        return false;

    out = topic.data;
    timestamp = topic.timestamp;
    sub.last_generation = topic.generation;
    return true;
};

