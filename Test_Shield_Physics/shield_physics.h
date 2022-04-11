/**
 * @file Shield_Physics.h
 * @author Nick Goralka (NickGoralka@gmail.com)
 * @brief Physics Engine for Shield
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "config.h"

#ifndef __SHIELD_PHYSICS__
#define __SHIELD_PHYSICS__

/**
 * @brief 
 * 
 * @param state 
 * @param config 
 */
void init (ShieldPosition_t* state, GameConfigurations_t* config);


/**
 * @brief Update the shield's acceleration
 * 
 */
void update_acceleration (ShieldPosition_t* state, GameConfigurations_t* config);

/**
 * @brief Update the shield's velocity
 * 
 */
void update_velocity (ShieldPosition_t* state, GameConfigurations_t* config);


/**
 * @brief Update the shield's position
 * 
 */
void update_position (ShieldPosition_t* state, GameConfigurations_t* config);

#endif
