

#include <stdint.h>
#include <stdbool.h>

#ifndef __CONFIG_TYPES__
#define __CONFIG_TYPES__

/**
 * @brief Harkonnen Mass Position type
 */
typedef struct Harkonnen_Mass_Position_t
{
  uint8_t x;
  uint8_t y;
  float velocity_x;
  float velocity_y;
} Harkonnen_Mass_Position_t;




typedef struct BoostConfig_t {
    float kinetic_energy_increase;
    uint16_t arming_window_before_impact;
    uint16_t recharge_time_after_discharge;
} BoostConfig_t;

typedef struct  LaserConfig_t{
    uint16_t num_activations;
    bool automatic_control;
} LaserConfig_t;


typedef struct BounceFromCanyonWalls_t{
    bool enabled;
    bool limited;
    float max_platform_bounce_speed;
} BounceFromCanyonWalls_t;




typedef struct HarkonnenMassConfig_t {
    /***********************************************************************
     * Harkonnen Mass Configurations
     * ********************************************************************/

    /**
     * @brief The number of Holtzman Masses to fall before
     * the battle is won
     * 
     */
    uint8_t total_num;

    /**
     * @brief The diameter of each HM on the display
     * 
     */
    float display_diameter;

    /**
     * @brief Initial Conditions for HM
     * @details  [enum: Fixed=0.  127+ are available for user-defined modes]
     * 
     */
    uint8_t initial_conditions_x;

    uint8_t initial_conditions_y;

    float initial_velocity_x;
    float initial_velocity_y;
} HarkonnenMassConfig_t;


typedef struct PlatformConfig_t{
    /******************************************************************************************
     * Platform Configurations
     * ***************************************************************************************/

    bool automatic_control;

    float mass_force;
    float mass;
    float length;
} PlatformConfig_t;

#endif
