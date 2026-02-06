# Simple Robot Internal Message Bus

SRIMB è un semplice sistema di scambio di messaggi attraverso un'architettura publisher, subscriber sviluppato appositamente 
per **Infinity-Autopilot** ma portabile su qualsiasi altro sistema robotico.
Il sistema è basato su un modello **Latest-Sample** dove viene salvato solo l'ultimo messaggio, non prevede code, quindi se un subscriber si perde
un messaggio non c'è modo di recuperarlo.

## Topics
SRIMB si basa sulla pubblicazione di topics ovvero prototipi di messaggio facilmente definibili all'interno della cartella topics seguendo questo template:
### Single topic instance
```cpp
```
### Multiple topic instance
SRIMB supporta anche **Multiple-Instance topics**, ovvero permette di pubblicare diversi messaggi con lo stesso topic, questo è fondamentale quando si hanno più task che pubblicano lo stesso topic come ad esempio un sistema che ha più IMU.

```topics/imu.hpp```
```cpp
#pragma once
#include "../srimb/srimb_topic.hpp"

constexpr uint8_t IMU_INSTANCES = 2;

struct ImuData {
    float ax, ay, az;
    float gx, gy, gz;
};

extern UORB_Topic<ImuData> topic_imu[IMU_INSTANCES];
```

```topics/imu.cpp```
```cpp
#include "imu.hpp"

UORB_Topic<ImuData> topic_imu[IMU_INSTANCES];
```

## Esempio di utilizzo
### Publisher
```cpp
#include "topics/imu.hpp"
#include "srimb/srimb.hpp"


void ImuDriverTask(uint8_t instance)
{
    ImuData imu;

    // leggi il sensore giusto
    read_imu_hw(instance, imu);

    srimb_publish(topic_imu[instance], imu, micros());
}
```

### Subscriber
```cpp
#include "topics/imu.hpp"
#include "srimb/srimb.hpp"

SRIMB_Sub imu_sub[IMU_INSTANCES];

void EstimatorTask()
{
    for (int i = 0; i < IMU_INSTANCES; i++) {
        if (srimb_copy(topic_imu[i], imu_sub[i], imu, t)) {
            ekf.update_imu(i, imu);
        }
    }
}
```