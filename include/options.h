#ifndef OPTIONS_H
#define OPTIONS_H

enum CameraMode
{
    CAMERA_MODE_ACTIVE = 0x02, 
    CAMERA_MODE_PASSIVE = 0x52
};

enum SpeakerSetup
{
    STEREO = 0x0,
    MONO = 0x1
};

enum PauseMenuState
{
    PAUSED_MAIN,
    PAUSED_OPTIONS,
    PAUSED_QUIT_GAME
};

#endif /* OPTIONS_H */
