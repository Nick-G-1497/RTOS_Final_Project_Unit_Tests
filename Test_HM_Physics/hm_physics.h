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
#include <math.h>

#ifndef __HM_PHYSICS__
#define __HM_PHYSICS__

/**
 * @brief 
 * 
 * @param state 
 * @param config 
 */
void init (ShieldPosition_t* state, GameConfigurations_t* config);



/**
 * @brief Update the mass' velocity
 * 
 */
void update_velocity(Harkonnen_Mass_Position_t* state, GameConfigurations_t* config);


/**
 * @brief Update the mass' position
 * 
 */
void update_position(ShieldPosition_t* shield, Harkonnen_Mass_Position_t* state, GameConfigurations_t* config);

#endif
