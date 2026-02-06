# Simple Robot Internal Message Bus

SRIMB è un semplice sistema di scambio di messaggi attraverso un'architettura publisher, subscriber sviluppato appositamente 
per **Infinity-Autopilot** ma portabile su qualsiasi altro sistema robotico.
Il sistema è basato su un modello **Latest-Sample** dove viene salvato solo l'ultimo messaggio, non prevede code, quindi se un subscriber si perde
un messaggio non c'è modo di recuperarlo.

## Topics
SRIMB si basa sulla pubblicazione di topics ovvero prototipi di messaggio facilmente definibili all'interno della cartella topics seguendo questo template:
```cpp
```

## Esempio di utilizzo
### Publisher
```cpp
```

### Subscriber
```cpp
```