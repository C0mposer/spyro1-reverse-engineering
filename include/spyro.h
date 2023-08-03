#ifndef SPYRO_H
#define SPYRO_H

#include "common.h"

//*~~~~~~~~~
//*Constants
//*~~~~~~~~~

typedef enum SpyroStates
{
    IDLE_STANDING = 0x0,
    BEGIN_WALK = 0x1,
    WALKING = 0x2,
    END_WALK = 0x3,
    PIVOT = 0x4,
    JUMP = 0x5,
    FLOP = 0x6,
    HURT_ZAPPED = 0x7,
    ROLL_LEFT = 0x9,
    ROLL_RIGHT = 0xA,
    CHARGE = 0xB,
    BONK = 0xC,
    LEDGE_PEER = 0xD,
    HURT_PITCH_HIGH = 0xE,
    GLIDE = 0xF,
    TRIANGLE_DROP = 0x10,
    WHIRLWIND = 0x11,
    IDLE_LOOK_AROUND = 0x12,
    ROLL_DOWN_SLOPE = 0x13,
    CHARGING_AIR = 0x14,
    UPHILL_WALK = 0x15,
    HURT_ROLL = 0x16,
    PULL_BACK_GLIDE = 0x17,
    CHARGING_AIR_SC_JUMP = 0x18,
    HURT_SQUISHED = 0x19,
    CANNON_ROTATE = 0x1A,
    HURT_YAW = 0x1B,
    HURT_PITCH_LOW = 0x1C,
    DROWNING = 0x1D,
    DEATH_SPIN = 0x1E,
    DEATH_SQUISHED = 0x1F,
    SUPERFLY = 0x20,
    SUPERFLY_ASCENDING = 0x21,
    SUPERFLY_DESCENDING = 0x22,
    IDLE_SIT = 0x27,
    SUPERCHARGE = 0x2C
}SpyroStates;

/**
 * @brief  This is the main Spyro struct.
 * @details This is what Spyro uses for most of his data: position, velocity, animations, color filter, angle, etc.
 */ 
typedef struct Spyro
{

struct Vec3 position;                               //? Spyro's position vector.

struct Angle_u8 RelativeSparxAngle;                  //? Something to do with sparx's rotation based on spyros angle I think.

char pad1;
int unkown1;
int unkown2;

char currentAnim;                                   //? Spyros current animation.
char nextAnim;                                      //? Spyros next animation.

char maybe_currentAnimDupe;
char maybe_nextAnimDupe;
char maybe_currentAnimDupe2;
char maybe_nextAnimDupe2;

char currentKeyfame;                                //? The current animation keyframe.
char nextKeyframe;                                  //? The next animation keyframe.

char maybe_keyframeDupe1;
char maybe_keyframeDupe2;
char maybe_keyframeDupe3;
char maybe_keyframeDupe4;
char maybe_AnimSpeedRelated;
char maybe_animSpeedRelatedDupe1;
char maybe_animSpeedRelatedDupe2;
char unkown3;


RGBA_u8 colorFilter;                       //? The color filter to apply to spyro. Used during fairy kiss, electric shock, etc.

short maybe_weirdDamageAnimRelated;
short unkown4;
int pad2;
int unkown5;
int unkown6;
int unkown7;
int unkown8;
int unkown9;
int pad3;
int pad4;
int pad5;
int maybe_animUpdateRelated;

char animSpeed;                                     //? The speed at which to play the animations.

char unkown10;
char unkown11;
char unkown12;
int maybe_animStateRelated;
int maybe_headAnimRelated;
int unkown_anim1;
int maybe_headAnimRelated2;
int maybe_tailAnimRelated;
int unkown13;
int maybe_tailAnimRelated2;

int state;                                          //? Spyro's current state.

int subState;                                       //? Spyro's current substate.

int framesInCurrentState;	                        //? The amount of frames spent in the current state. Used for calculations for jumping, boking, damage, time sensitive states, etc

int unkown14;
int unkown15;

struct Vec3 maybe_positionRelative;

int timer_framesIdle;                               //? The amount of frames you have spent idleing.

int timer_framesInAir;                              //? The amount of frames spyro has spent in the air.


int unkown_heightRelated;
int unkown_angleRelated;
int unkown_angleRelated2;
int unkown_angleRelated3;
int unkown_angleRelated4;
int unkown_angleRelated5;
int unkown_portalRelated;
int unkown_portalRelated2;
int unkown_portalRelated3;
int unkown_landingMomentumRelated;
int unkown_angleRelated6;
int unkown_angleRelated7;



struct Vec3 groundedChargeMomentum;                 //? Spyro's grounded charge momentum vector.

struct Vec3 walkingMomentum;                        //? Spyro's walking momentum vector.

struct Vec3 groundedChargeMomentum2;                //? Spyro's groundedChargeMomentum vector again? Unsure.

struct Vec3 airMomentum;                            //? Spyro's air momentum vector.

int unkown_angleRelated8;
int unkown16;
int unkown17;
int unkown18;
int unkown19;
int maybe_glideAndWalkOffLedgeZMomentum;

int absoluteMomentum;

struct Angle angle;                                 //? Spyro's angle vector.

int maybe_speedRelated;
int unkown21;                               
int unkown22;
int unkown23;
int unkown24;
int unkown25;
int unkown26;

int walkingAcceleration;                            //? Spyro's walking acceleration.

int turnAcceleration;
int z_Acceleration;

int hasUsedGlide;                                   //? bool for if Spyro has used glide or not yet, since can only use once in this game.     

int isGliding;                                      //? bool for if Spyro is currently gliding.

int neutralJumpZPos;

int isGrounded;                                     //? bool for if Spyro is currently grounded.

int iFramesTimer;                                   //? Timer for the amount of invincibility frames Spyro should have. Counts down to 0 every frame unless set every frame to a value.

int health;                                         //? Spyro's health value. Sparx's color get's set based on this value.

int drownTimer;                                     //? Timer for the amount of time left to drown I think, I didn't double check lol.

int maybe_superchargeRelated;

int isOverGoop;                                     //? bool for if Spyro is currently over goop.

int maybe_drowningRelated;

int unkown32;

struct Vec3 lastGroundedPosition;                   //? Spyro's last grounded position vector.

int unkown33;
int unkown34;
int unkown35;

int autoFlameRelated;

int maybe_isFlaming;
int unkown36;
int maybe_flameChargeTimerRelated;

SpyroHeadAngle TargetHeadAngle;                     //? Spyro's target head angle vector.

SpyroHeadAngle headAngle;                           //? Spyro's head angle vector.

int maybe_headRollTransitionSpeed;
int maybe_headPitchTransitionSpeed;
int maybe_headYawTransitionSpeed;

int maybe_smokeFlameStuff1;
int maybe_smokeFlameStuff2;
int maybe_smokeFlameStuff3;
int maybe_smokeFlameStuff4;
int maybe_smokeFlameStuff5;

int unkown37;
int unkown38;
int unkown39;

int maybe_tailRelated;
int maybe_chargeTimerRelated;

int isMovementLocked;                               //? Value for if spyro can input or not. Counts down from any value to 0 every frame if not set every frame to a value manually.

int maybe_weirdResearchThis;

int unkownOops;
int unkown40;
int unkown41;
int unkown42;
int unkown43;
int unkown44;
int unkown45;
int unkown46;
int unkown47;
int unkown48;
int unkown49;
int unkown50;
int unkown51;
int unkown52;
int unkown53;
int unkown54;
int unkown55;
int unkown56;
int unkown57;
int unkown58;
int unkown59;

int canSuperfly;                                           //? bool for if Spyro can superfly or not.
int isOnSuperchargeGround;                                 //? bool for if Spyro is on supercharge ground or not.

int maybe_pitchRelatedFlag;

int rollMomentum;                                           //? Spyro's roll momentum.
int pitchMomentum;                                          //? Spyro's pitch momentum.


}Spyro;

//*~~~~~~~~~~~~~~~~~
//*In Game Variables
//*~~~~~~~~~~~~~~~~~

/**
 * @brief  This is where spyro is in ram. This is the 1 instance of the spyro struct
 * @note Address: 0x80078A58
 * @see Spyro
 */ 
extern Spyro _spyro;


//! All of these below can be accessed through the spyro struct above, but I figuerd it be helpful to have all these addresses labled for the documentation
/**
 * @brief  Spyro's X Position Coordinate
 * @note Address: 0x80078A58
 * @see Spyro
 */ 
extern int _spyroXPosition;

/**
 * @brief  Spyro's Y Position Coordinate
 * @note Address: 0x80078A5C
 * @see Spyro
 */ 
extern int _spyroYPosition;

/**
 * @brief  Spyro's Z Position Coordinate
 * @note Address: 0x80078A60
 * @see Spyro
 */ 
extern int _spyroZPosition;

/**
 * @brief  Spyro's Yaw Rotation Angle
 * @note Address: 0x80078b74
 * @see Spyro
 */ 
extern int _spyroAngleYaw;

/**
 * @brief  Spyro's Pitch Rotation Angle
 * @note Address: 0x80078b78
 * @see Spyro
 */ 
extern int _spyroAnglePitch;

/**
 * @brief  Spyro's Roll Rotation Angle
 * @note Address: 0x80078b7C
 * @see Spyro
 */ 
extern int _spyroAngleRoll;

/**
 * @brief  This is the color filter applied on top of spyro in RGBA format
 * @details  This is what gets applied to spyro during superflame.
 * @note Address: 0x80078a80
 * @see Spyro RGBA_u8
 */ 
extern RGBA_u8 _spyroColorFilter;

/**
 * @brief  This is spyro's current active state.
 * @details  Full list of states in the SpyroStates enum. (Walking, Gliding, Charging, etc.)
 * @note Address: 0x80078ad0
 * @see Spyro SpyroStates
 */ 
extern int _spyroState;

/**
 * @brief  This is spyro's current active sub-state.
 * @details  Need to research sub-state more.
 * @note Address: 0x80078ad4
 * @see Spyro SpyroStates
 */ 
extern int _spyroSubState;

/**
 * @brief  The amount of time in frames spent in the current state. Used for calculations for jumping, boking, damage, time sensitive states, etc
 * @details  Need to research sub-state more.
 * @note Address: 0x80078ad8
 * @see Spyro
 */ 
extern int _spyroFramesInCurrentState;

/**
 * @brief  Spyros grouded charging momentum vector.
 * @note Address: 0x80078b28
 * @see Spyro
 */ 
extern Vec3 _spyroGroundedChargeMomentum;

/**
 * @brief  Spyros walking momentum vector.
 * @note Address: 0x80078b34
 * @see Spyro
 */ 
extern Vec3 _spyroWalkingChargeMomentum;

/**
 * @brief  Spyros air momentum vector.
 * @note Address: 0x80078b4c
 * @see Spyro
 */ 
extern Vec3 _spyroAirMomentum;

/**
 * @brief  Spyros absolute momentum as a scalar.
 * @note Address: 0x80078b70
 * @see Spyro
 */ 
extern int _spyroAbsoluteMomentum;

/**
 * @brief bool for if Spyro has used his glide or not yet.
 * @note Address: 0x80078ba8
 * @see Spyro
 */ 
extern int _spyroHasUsedGlide;

/**
 * @brief bool for if Spyro is currently gliding or not.
 * @note Address: 0x80078bac
 * @see Spyro
 */ 
extern int _spyroIsGliding;

/**
 * @brief bool for if Spyro is currently grounded or not.
 * @note Address: 0x80078bb4
 * @see Spyro
 */ 
extern int _spyroIsGrounded;

/**
 * @brief Timer for how many more frames spyro should have invulnerability. 
 * @details Automatically decrements by 1 every frame until 0. Spyro will have invulnerability if it is any number above 0.
 * @note Address: 0x80078bb8
 * @see Spyro
 */ 
extern int _spyroIFramesTimer;

/**
 * @brief Spyros current health 
 * @details This value is tied to sparx's color also. If spyro health reaches 0, sparx will disapear.
 * @note Address: 0x80078bbc
 * @see Spyro
 */ 
extern int _spyroHealth;

/**
 * @brief A timer that stops the player from being able to move spyro.
 * @details This timer decrements by 1 every frame until it reaches 0. Once it reaches 0 the player can input again.
 * @note Address: 0x80078c48
 * @see Spyro
 */ 
extern int _spyroIsMovementLocked;

/**
 * 
 * @brief A bool for if spyro can superfly currently.
 * @details This can be set to true in any level
 * @note Address: 0x80078ca4
 * @see Spyro
 */ 
extern int _spyroCanSuperFly;

/**
 * 
 * @brief A bool for if spyro is currently on supercharge ground.
 * @details This doesn't give spyro supercharge state, but gives him the weird properties of being on a supercharge ground, like the extra charge in air height.
 * @note Address: 0x80078ca8
 * @see Spyro
 */ 
extern int _spyroIsOnSuperchargeGround;


#endif //SPYRO_H