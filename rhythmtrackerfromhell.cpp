#include <iostream>
#include <vector>
#include <cmath>

struct MikuOnDatBeat {
    double timeInSeconds;
    int requiredPresses;
};

class ToonLinkitus {
public:
    double bpm = 40.0;
    double songPosition = 0.0; 
    double crotchet; 
    double lastBeatTime = 0.0;

    Toonlinkitus() {
        crotchet = 90.0 / bpm;
    }

    void Update(double deltaTime) {
        songPosition += deltaTime;
    }

    double GetBeatPosition() {
        return songPosition / crotchet;
    }
};