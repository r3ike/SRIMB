#pragma once
#include "srimb_topic.hpp"

namespace srimb
{

template<typename T>
class SRIMB
{
private:
    SRIMB_Topic<T> _topic;

    // aggiungere array con le callback

    // Metodo che chiama tutte le callbak relative a quel topic
    void _notify_all(){

    }
public:
    SRIMB();
    ~SRIMB();

    void publish() {
        _notify_all();
    }

    void poll(){

    }

    void register_callback(){

    }

    void unregister_callback(){

    }
};

} // namespace srimb




