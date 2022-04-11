/**
 * @file shield_physics_tests.c
 * @author Nick Goralka
 * @brief Unit Tests for Shield Physics
 * @version 0.1
 * @date 2022-04-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>
#include "ctest.h"
#include "config.h"
// #include "config_types.h"
#include "hm_physics.h"

#include <stdlib.h>

#include <stdio.h>



// Note: the name in the first parameter slot must match all tests in that group
CTEST_DATA(hm_physics) {

    float expected_position_x0[8];
    float expected_velocity_x0[8];

    float expected_position_y0[8];
    float expected_velocity_y0[8];

    float actual_position_x0[8];
    float actual_velocity_x0[8];

    float actual_position_y0[8];
    float actual_velocity_y0[8];

    float expected_position_x1[8];
    float expected_velocity_x1[8];

    float expected_position_y1[8];
    float expected_velocity_y1[8];

    float actual_position_x1[8];
    float actual_velocity_x1[8];

    float actual_position_y1[8];
    float actual_velocity_y1[8];

    float expected_position_x2[8];
    float expected_velocity_x2[8];

    float expected_position_y2[8];
    float expected_velocity_y2[8];

    float actual_position_x2[8];
    float actual_velocity_x2[8];

    float actual_position_y2[8];
    float actual_velocity_y2[8];

    
    float expected_position_x3[8];
    float expected_velocity_x3[8];

    float expected_position_y3[8];
    float expected_velocity_y3[8];

    float actual_position_x3[8];
    float actual_velocity_x3[8];

    float actual_position_y3[8];
    float actual_velocity_y3[8];




    ShieldPosition_t shield;

    Harkonnen_Mass_Position_t HM0;
    Harkonnen_Mass_Position_t HM1;
    Harkonnen_Mass_Position_t HM2;
    Harkonnen_Mass_Position_t HM3;

    GameConfigurations_t config;


};

CTEST_SETUP(hm_physics) {


    // Initialize config data
    GameConfigurations_t config = {
        .version = 2,
        .gravity = 1,
        .canyon_size = 127,
        .tau_phy = 1,
        .initial_horizontal_position = 69,
        .user_defined_mode_input = 4,
        // .exclusively_passive_bounce_kinetic_energy_reduction = 0.4,

        .num_HM = 25,
        .display_diameter_HM = 5,
        .initial_conditions_HM = 0,
        .initial_velocity_x_HM = 0,
        .initial_horizontal_position = 0,
        
        .mass_force_P = 50,
        .mass_P = 5,
        .length_P = 2,
        .automatic_control_platform = false,


        .cw_bounce_enabled = false,
        .cw_bounce_limited = true,
        .max_platform_bounce_speed = 10,

        .kinetic_energy_conserved_from_bounce = 80,
        .kinetic_energy_increase_from_boost = 120,
        .arming_window_before_impact_for_boost = 10,
        .recharge_time_after_discharge_for_boost = 10,

        .num_laser_activations = 10,
        .laser_automatic_control = true,



    };

    data->config = config; 


    ShieldPosition_t shield = {
        .x = 5,
        .max_x = 127,
        .min_x = 0,
        
        .velocity_x = 0,
        .acceleration_x = 0,
        .isBoosted = false,

        .current_force = 0,
        .mass = 0
    };

    data->shield = shield;

    Harkonnen_Mass_Position_t HM0 = 
    {
        .x = 5,
        .y = 69,

        .velocity_x = 0,
        .velocity_y = 0,

        .max_x = 127,
        .min_x = 0,

        .mass = 5
    };

    data->HM0 = HM0;

    printf("\n");

    for (int i = 0; i < 8; i++)
    {
        data->actual_position_x0[i] =  data->HM0.x;
        data->actual_position_y0[i] = data->HM0.y;
 
        data->actual_velocity_x0[i] = data->HM0.velocity_x;
        data->actual_velocity_y0[i] = data->HM0.velocity_y;

        // printf("[*] Time %d - Position (%f, %f)  - Velocity (%f, %f) \n", i,
        //                                                         data->actual_position_x0[i],
        //                                                         data->actual_position_y0[i], 
        //                                                         data->actual_velocity_x0[i], 
        //                                                         data->actual_velocity_y0[i]);

        
        update_position(&data->shield, &data->HM0, &data->config);
    }

    data->expected_position_x0[0] = 5;
    data->expected_position_x0[1] = 5;
    data->expected_position_x0[2] = 5;
    data->expected_position_x0[3] = 5;
    data->expected_position_x0[4] = 5;
    data->expected_position_x0[5] = 5;
    data->expected_position_x0[6] = 5;
    data->expected_position_x0[7] = 5;

    data->expected_position_y0[0] = 69;
    data->expected_position_y0[1] = 68;
    data->expected_position_y0[2] = 66;
    data->expected_position_y0[3] = 63;
    data->expected_position_y0[4] = 59;
    data->expected_position_y0[5] = 54;
    data->expected_position_y0[6] = 48;
    data->expected_position_y0[7] = 41;


     Harkonnen_Mass_Position_t HM1 = 
    {
        .x = 5,
        .y = 10,

        .velocity_x = 0,
        .velocity_y = 0,

        .max_x = 127,
        .min_x = 0,

        .mass = 5
    };

    data->HM1 = HM1;

    printf("\n");

    for (int i = 0; i < 8; i++)
    {
        data->actual_position_x1[i] =  data->HM1.x;
        data->actual_position_y1[i] = data->HM1.y;
 
        data->actual_velocity_x1[i] = data->HM1.velocity_x;
        data->actual_velocity_y1[i] = data->HM1.velocity_y;

        // printf("[*] Time %d - Position (%f, %f)  - Velocity (%f, %f) \n", i,
        //                                                         data->actual_position_x1[i],
        //                                                         data->actual_position_y1[i], 
        //                                                         data->actual_velocity_x1[i], 
        //                                                         data->actual_velocity_y1[i]);

        
        update_position(&data->shield, &data->HM1, &data->config);
    }

    data->expected_position_x1[0] = 5;
    data->expected_position_x1[1] = 5;
    data->expected_position_x1[2] = 5;
    data->expected_position_x1[3] = 5;
    data->expected_position_x1[4] = 5;
    data->expected_position_x1[5] = 5;
    data->expected_position_x1[6] = 5;
    data->expected_position_x1[7] = 5;

    data->expected_position_y1[0] = 10;
    data->expected_position_y1[1] = 9;
    data->expected_position_y1[2] = 7;
    data->expected_position_y1[3] = 4;
    data->expected_position_y1[4] = 0;
    data->expected_position_y1[5] = 2;
    data->expected_position_y1[6] = 3;
    data->expected_position_y1[7] = 3;


    Harkonnen_Mass_Position_t HM2 = 
    {
        .x = 5,
        .y = 69,

        .velocity_x = -1,
        .velocity_y = 0,

        .max_x = 127,
        .min_x = 0,

        .mass = 5
    };

    data->HM2 = HM2;

    printf("\n");


    for (int i = 0; i < 8; i++)
    {
        data->actual_position_x2[i] =  data->HM2.x;
        data->actual_position_y2[i] = data->HM2.y;
 
        data->actual_velocity_x2[i] = data->HM2.velocity_x;
        data->actual_velocity_y2[i] = data->HM2.velocity_y;

        // printf("[*] Time %d - Position (%f, %f)  - Velocity (%f, %f) \n", i,
        //                                                         data->actual_position_x2[i],
        //                                                         data->actual_position_y2[i], 
        //                                                         data->actual_velocity_x2[i], 
        //                                                         data->actual_velocity_y2[i]);

        
        update_position(&data->shield, &data->HM2, &data->config);
    }
    

    data->expected_position_x2[0] = 5;
    data->expected_position_x2[1] = 4;
    data->expected_position_x2[2] = 3;
    data->expected_position_x2[3] = 2;
    data->expected_position_x2[4] = 1;
    data->expected_position_x2[5] = 0;
    data->expected_position_x2[6] = 1;
    data->expected_position_x2[7] = 2;

    data->expected_position_y2[0] = 69;
    data->expected_position_y2[1] = 68;
    data->expected_position_y2[2] = 66;
    data->expected_position_y2[3] = 63;
    data->expected_position_y2[4] = 59;
    data->expected_position_y2[5] = 54;
    data->expected_position_y2[6] = 48;
    data->expected_position_y2[7] = 41;

    data->expected_velocity_x2[0] = -1;
    data->expected_velocity_x2[1] = -1;
    data->expected_velocity_x2[2] = -1;
    data->expected_velocity_x2[3] = -1;
    data->expected_velocity_x2[4] = -1;
    data->expected_velocity_x2[5] = 1;
    data->expected_velocity_x2[6] = 1;
    data->expected_velocity_x2[7] = 1;


    data->expected_velocity_y2[0] = 0;
    data->expected_velocity_y2[1] = -1;
    data->expected_velocity_y2[2] = -2;
    data->expected_velocity_y2[3] = -3;
    data->expected_velocity_y2[4] = -4;
    data->expected_velocity_y2[5] = -5;
    data->expected_velocity_y2[6] = -6;
    data->expected_velocity_y2[7] = -7;



    data->shield.isBoosted = true;

    Harkonnen_Mass_Position_t HM3 = 
    {
        .x = 5,
        .y = 10,

        .velocity_x = 0,
        .velocity_y = 0,

        .max_x = 127,
        .min_x = 0,

        .mass = 5
    };

    data->HM3 = HM3;

    printf("\n");

    for (int i = 0; i < 8; i++)
    {
        data->actual_position_x3[i] =  data->HM3.x;
        data->actual_position_y3[i] = data->HM3.y;
 
        data->actual_velocity_x3[i] = data->HM3.velocity_x;
        data->actual_velocity_y3[i] = data->HM3.velocity_y;

        // printf("[*] Time %d - Position (%f, %f)  - Velocity (%f, %f) \n", i,
        //                                                         data->actual_position_x3[i],
        //                                                         data->actual_position_y3[i], 
        //                                                         data->actual_velocity_x3[i], 
        //                                                         data->actual_velocity_y3[i]);

        
        update_position(&data->shield, &data->HM3, &data->config);
    }
    

    data->expected_position_x3[0] = 5;
    data->expected_position_x3[1] = 5;
    data->expected_position_x3[2] = 5;
    data->expected_position_x3[3] = 5;
    data->expected_position_x3[4] = 5;
    data->expected_position_x3[5] = 5;
    data->expected_position_x3[6] = 5;
    data->expected_position_x3[7] = 5;

    data->expected_position_y3[0] = 10;
    data->expected_position_y3[1] = 9;
    data->expected_position_y3[2] = 7;
    data->expected_position_y3[3] = 4;
    data->expected_position_y3[4] = 0;
    data->expected_position_y3[5] = 3;
    data->expected_position_y3[6] = 5;
    data->expected_position_y3[7] = 6;

    data->expected_velocity_x3[0] = 0;
    data->expected_velocity_x3[1] = 0;
    data->expected_velocity_x3[2] = 0;
    data->expected_velocity_x3[3] = 0;
    data->expected_velocity_x3[4] = 0;
    data->expected_velocity_x3[5] = 0;
    data->expected_velocity_x3[6] = 0;
    data->expected_velocity_x3[7] = 0;


    data->expected_velocity_y3[0] = 0;
    data->expected_velocity_y3[1] = -1;
    data->expected_velocity_y3[2] = -2;
    data->expected_velocity_y3[3] = -3;
    data->expected_velocity_y3[4] = 4.381781;
    data->expected_velocity_y3[5] = 3.381781;
    data->expected_velocity_y3[6] = 2.381781;
    data->expected_velocity_y3[7] = 1.381781;


}

CTEST2(hm_physics, init) {
    printf("\nCheck that the data has been initialized correctly\n");



}

CTEST2(hm_physics, Normal_Falling) {
    printf("\nChecking that the physics engine behaves as expected when constant force is applied\n");
    
    for (int i = 0; i < 8; i++)
    {
        // printf("\nExpected : %f        Actual : %f\n", data->expected_position0[i], data->actual_position0[i]);
        ASSERT_EQUAL(data->expected_position_x0[i], data->actual_position_x0[i]);
        ASSERT_EQUAL(data->expected_position_y0[i], data->actual_position_y0[i]);

        // ASSERT_EQUAL(data->expected_velocity_x0[i], data->actual_velocity_x0[i]);
        // ASSERT_EQUAL(data->expected_velocity_y0[i], data->actual_velocity_y0[i]);
    }


}


CTEST2(hm_physics, Wall_Collision) {
    printf("\nCheck that mass bounces off the wall when it collides with the wall\n");

        for (int i = 0; i < 8; i++)
    {
        // printf("\nExpected : %f        Actual : %f\n", data->expected_position0[i], data->actual_position0[i]);
        ASSERT_EQUAL(data->expected_position_x2[i], data->actual_position_x2[i]);
        ASSERT_EQUAL(data->expected_position_y2[i], data->actual_position_y2[i]);

        ASSERT_EQUAL(data->expected_velocity_x2[i], data->actual_velocity_x2[i]);
        ASSERT_EQUAL(data->expected_velocity_y2[i], data->actual_velocity_y2[i]);
    }

    
}
CTEST2(hm_physics, Shield_Collision_No_Boost) {
    printf("\nCheck that mass' trajectory matches what we would expect when the mass collides with an unboosted shield\n");

    for (int i = 0; i < 8; i++)
    {
        // printf("\nExpected : %f        Actual : %f\n", data->expected_position0[i], data->actual_position0[i]);
        ASSERT_EQUAL(data->expected_position_x1[i], data->actual_position_x1[i]);
        ASSERT_EQUAL(data->expected_position_y1[i], data->actual_position_y1[i]);

        // ASSERT_EQUAL(data->expected_velocity_x1[i], data->actual_velocity_x1[i]);
        // ASSERT_EQUAL(data->expected_velocity_y1[i], data->actual_velocity_y1[i]);
    }

}

CTEST2(hm_physics, Shield_Collision_With_Boost) {
    printf("\nCheck that mass' trajectory matches what we would expect when the mass collides with a boosted shield\n");


    for (int i = 0; i < 8; i++)
    {
        // printf("\nExpected : %f        Actual : %f\n", data->expected_position0[i], data->actual_position0[i]);
        ASSERT_EQUAL(data->expected_position_x3[i], data->actual_position_x3[i]);
        ASSERT_EQUAL(data->expected_position_y3[i], data->actual_position_y3[i]);

        ASSERT_EQUAL(data->expected_velocity_x3[i], data->actual_velocity_x3[i]);
        ASSERT_EQUAL(data->expected_velocity_y3[i], data->actual_velocity_y3[i]);
    }

}

// CTEST_DATA(shield_physics_1) {

// };

