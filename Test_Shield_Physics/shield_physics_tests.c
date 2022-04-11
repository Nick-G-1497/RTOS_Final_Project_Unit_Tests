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
#include "shield_physics.h"
#include "config.h"
#include "config_types.h"

#include <stdlib.h>

#include <stdio.h>



// Note: the name in the first parameter slot must match all tests in that group
CTEST_DATA(shield_physics) {

    float expected_position0[8];
    float expected_velocity0[8];
    float expected_acceleration0[8];

    float actual_position0[8];
    float actual_velocity0[8];
    float actual_acceleration0[8];


    float expected_position1[8];
    float expected_velocity1[8];
    float expected_acceleration1[8];

    float actual_position1[8];
    float actual_velocity1[8];
    float actual_acceleration1[8];

    float expected_position2[8];
    float expected_velocity2[8];
    float expected_acceleration2[8];

    float actual_position2[8];
    float actual_velocity2[8];
    float actual_acceleration2[8];

    
    float expected_position3[8];
    float expected_velocity3[8];
    float expected_acceleration3[8];

    float actual_position3[8];
    float actual_velocity3[8];
    float actual_acceleration3[8];

    
    float expected_position4[8];
    float expected_velocity4[8];
    float expected_acceleration4[8];

    float actual_position4[8];
    float actual_velocity4[8];
    float actual_acceleration4[8];


    
    float expected_position5[16];
    float expected_velocity5[16];
    float expected_acceleration5[16];

    float actual_position5[16];
    float actual_velocity5[16];
    float actual_acceleration5[16];



    ShieldPosition_t shield;
    ShieldPosition_t shield1;
    ShieldPosition_t shield2;
    ShieldPosition_t shield3;
    ShieldPosition_t shield4;
    ShieldPosition_t shield5;

    GameConfigurations_t config;


};

CTEST_SETUP(shield_physics) {


    // Initialize config data
    GameConfigurations_t config = {
        .version = 2,
        .gravity = -9.8,
        .canyon_size = 127,
        .tau_phy = 1,
        .initial_horizontal_position = 69,
        .user_defined_mode_input = 4,
        .exclusively_passive_bounce_kinetic_energy_reduction = 0.4,

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

        .exclusively_passive_bounce_kinetic_energy_reduction = 100,
        .kinetic_energy_increase_from_boost = 100,
        .arming_window_before_impact_for_boost = 10,
        .recharge_time_after_discharge_for_boost = 10,

        .num_laser_activations = 10,
        .laser_automatic_control = true,



    };

    data->config = config; 

    

    // Instantiate a shield
    ShieldPosition_t shield0 = {
        .x = 1,
        .max_x = 126,
        .min_x = 0,
        .velocity_x = 0,
        .acceleration_x = 0,
        .isBoosted = false,
        .current_force = 5,
        .mass = config.mass_P
    };

    
    data->shield = shield0;



    data->expected_position0[0] = 1;
    data->expected_velocity0[0] = 0;
    data->expected_acceleration0[0] = 0;

    data->expected_position0[1] = 2;
    data->expected_velocity0[1] = 1;
    data->expected_acceleration0[1] = 1;

    data->expected_position0[2] = 4;
    data->expected_velocity0[2] = 2;
    data->expected_acceleration0[2] = 1;  


    data->expected_position0[3] = 7;
    data->expected_velocity0[3] = 3;
    data->expected_acceleration0[3] = 1;     


    data->expected_position0[4] = 11;
    data->expected_velocity0[4] = 4; 
    data->expected_acceleration0[4] = 1; 

    data->expected_position0[5] = 16;
    data->expected_velocity0[5] = 5;
    data->expected_acceleration0[5] = 1;

    data->expected_position0[6] = 22;
    data->expected_velocity0[6] = 6;
    data->expected_acceleration0[6] = 1;

    data->expected_position0[7] = 29;
    data->expected_velocity0[7] = 7;
    data->expected_acceleration0[7] = 1;

    for (int i = 0; i < 8; i++)
    {
        data->actual_position0[i] =  data->shield.x;
        data->actual_velocity0[i] = data->shield.velocity_x;
        data->actual_acceleration0[i] = data->shield.acceleration_x;

        update_acceleration(&data->shield, &data->config);
        update_velocity(&data->shield, &data->config);
        update_position(&data->shield, &data->config);
    }


        // Instantiate a shield
    ShieldPosition_t shield1 = {
        .x = 120,
        .max_x = 127,
        .min_x = 0,
        .velocity_x = 0,
        .acceleration_x = 0,
        .isBoosted = false,
        .current_force = 5,
        .mass = config.mass_P
    };

    
    data->shield1 = shield1;

    data->expected_position1[0] = 120;
    data->expected_velocity1[0] = 0;
    data->expected_acceleration1[0] = 0;

    data->expected_position1[1] = 121;
    data->expected_velocity1[1] = 1;
    data->expected_acceleration1[1] = 1;

    data->expected_position1[2] = 123;
    data->expected_velocity1[2] = 2;
    data->expected_acceleration1[2] = 1;  


    data->expected_position1[3] = 126;
    data->expected_velocity1[3] = 3;
    data->expected_acceleration1[3] = 1;     


    data->expected_position1[4] = 127;
    data->expected_velocity1[4] = 0; 
    data->expected_acceleration1[4] = 0; 

    data->expected_position1[5] = 127;
    data->expected_velocity1[5] = 0;
    data->expected_acceleration1[5] = 0;

    data->expected_position1[6] = 127;
    data->expected_velocity1[6] = 0;
    data->expected_acceleration1[6] = 0;

    data->expected_position1[7] = 127;
    data->expected_velocity1[7] = 0;
    data->expected_acceleration1[7] = 0;

    for (int i = 0; i < 8; i++)
    {
        data->actual_position1[i] =  data->shield1.x;
        data->actual_velocity1[i] = data->shield1.velocity_x;
        data->actual_acceleration1[i] = data->shield1.acceleration_x;

        update_acceleration(&data->shield1, &data->config);
        update_velocity(&data->shield1, &data->config);
        update_position(&data->shield1, &data->config);
    }


    ShieldPosition_t shield2 = {
        .x = 7,
        .max_x = 127,
        .min_x = 0,
        .velocity_x = 0,
        .acceleration_x = 0,
        .isBoosted = false,
        .current_force = -5,
        .mass = config.mass_P        
    };

    data->shield2 = shield2;

    for (int i = 0; i < 8; i++)
    {
        data->actual_position2[i] =  data->shield2.x;
        data->actual_velocity2[i] = data->shield2.velocity_x;
        data->actual_acceleration2[i] = data->shield2.acceleration_x;

        update_acceleration(&data->shield2, &data->config);
        update_velocity(&data->shield2, &data->config);
        update_position(&data->shield2, &data->config);
    }



    data->expected_position2[0] = 7;
    data->expected_velocity2[0] = 0;
    data->expected_acceleration2[0] = 0;

    data->expected_position2[1] = 6;
    data->expected_velocity2[1] = -1;
    data->expected_acceleration2[1] = -1;

    data->expected_position2[2] = 4;
    data->expected_velocity2[2] = -2;
    data->expected_acceleration2[2] = -1;  


    data->expected_position2[3] = 1;
    data->expected_velocity2[3] = -3;
    data->expected_acceleration2[3] = -1;     


    data->expected_position2[4] = 0;
    data->expected_velocity2[4] = 0; 
    data->expected_acceleration2[4] = 0; 

    data->expected_position2[5] = 0;
    data->expected_velocity2[5] = 0;
    data->expected_acceleration2[5] = 0;

    data->expected_position2[6] = 0;
    data->expected_velocity2[6] = 0;
    data->expected_acceleration2[6] = 0;

    data->expected_position2[7] = 0;
    data->expected_velocity2[7] = 0;
    data->expected_acceleration2[7] = 0;


    ShieldPosition_t shield3 = {
        .x = 69,
        .max_x = 127,
        .min_x = 0,
        .velocity_x = 0,
        .acceleration_x = 0,
        .isBoosted = false,
        .current_force = 5,
        .mass = config.mass_P        
    };

    data->shield3 = shield3;

    for (int i = 0; i < 8; i++)
    {
        data->actual_position3[i] =  data->shield3.x;
        data->actual_velocity3[i] = data->shield3.velocity_x;
        data->actual_acceleration3[i] = data->shield3.acceleration_x;

        // printf("[*] Time %d - Position %f  - Velocity %f - Acceleration %f \n", i,
        //                                                         data->actual_position3[i], 
        //                                                         data->actual_velocity3[i], 
        //                                                         data->actual_acceleration3[i]);

        if (i == 4)
        {
            data->shield3.current_force = -5;
        }

        update_acceleration(&data->shield3, &data->config);
        update_velocity(&data->shield3, &data->config);
        update_position(&data->shield3, &data->config);
    }

    data->expected_position3[0] = 69;
    data->expected_velocity3[0] = 0;
    data->expected_acceleration3[0] = 0;

    data->expected_position3[1] = 70;
    data->expected_velocity3[1] = 1;
    data->expected_acceleration3[1] = 1;

    data->expected_position3[2] = 72;
    data->expected_velocity3[2] = 2;
    data->expected_acceleration3[2] = 1;  


    data->expected_position3[3] = 75;
    data->expected_velocity3[3] = 3;
    data->expected_acceleration3[3] = 1;     


    data->expected_position3[4] = 79;
    data->expected_velocity3[4] = 4; 
    data->expected_acceleration3[4] = 1; 

    data->expected_position3[5] = 82;
    data->expected_velocity3[5] = 3;
    data->expected_acceleration3[5] = -1;

    data->expected_position3[6] = 84;
    data->expected_velocity3[6] = 2;
    data->expected_acceleration3[6] = -1;

    data->expected_position3[7] = 85;
    data->expected_velocity3[7] = 1;
    data->expected_acceleration3[7] = -1;


    ShieldPosition_t shield4 = {
        .x = 69,
        .max_x = 127,
        .min_x = 0,
        .velocity_x = 0,
        .acceleration_x = 0,
        .isBoosted = false,
        .current_force = -5,
        .mass = config.mass_P        
    };


    data->shield4 = shield4;

    for (int i = 0; i < 8; i++)
    {
        data->actual_position4[i] =  data->shield4.x;
        data->actual_velocity4[i] = data->shield4.velocity_x;
        data->actual_acceleration4[i] = data->shield4.acceleration_x;

        // printf("[*] Time %d - Position %f  - Velocity %f - Acceleration %f \n", i,
        //                                                         data->actual_position4[i], 
        //                                                         data->actual_velocity4[i], 
        //                                                         data->actual_acceleration4[i]);

        if (i == 4)
        {
            data->shield4.current_force = 5;
        }

        update_acceleration(&data->shield4, &data->config);
        update_velocity(&data->shield4, &data->config);
        update_position(&data->shield4, &data->config);
    }

    data->expected_position4[0] = 69;
    data->expected_velocity4[0] = 0;
    data->expected_acceleration4[0] = 0;

    data->expected_position4[1] = 68;
    data->expected_velocity4[1] = -1;
    data->expected_acceleration4[1] = -1;

    data->expected_position4[2] = 66;
    data->expected_velocity4[2] = -2;
    data->expected_acceleration4[2] = -1;  


    data->expected_position4[3] = 63;
    data->expected_velocity4[3] = -3;
    data->expected_acceleration4[3] = -1;     


    data->expected_position4[4] = 59;
    data->expected_velocity4[4] = -4; 
    data->expected_acceleration4[4] = -1; 

    data->expected_position4[5] = 56;
    data->expected_velocity4[5] = -3;
    data->expected_acceleration4[5] = 1;

    data->expected_position4[6] = 54;
    data->expected_velocity4[6] = -2;
    data->expected_acceleration4[6] = 1;

    data->expected_position4[7] = 53;
    data->expected_velocity4[7] = -1;
    data->expected_acceleration4[7] = 1;



    
    ShieldPosition_t shield5 = {
        .x = 69,
        .max_x = 200,
        .min_x = 0,
        .velocity_x = 0,
        .acceleration_x = 0,
        .isBoosted = false,
        .current_force = 5,
        .mass = config.mass_P        
    };


    data->shield5 = shield5;

    for (int i = 0; i < 16; i++)
    {
        data->actual_position5[i] =  data->shield5.x;
        data->actual_velocity5[i] = data->shield5.velocity_x;
        data->actual_acceleration5[i] = data->shield5.acceleration_x;


        if (i == 3)
        {
            data->shield5.current_force = 0;
        }

        if (i == 8)
        {
            data->shield5.current_force = 5;
        }
        if (i == 9)
        {
            data->shield5.current_force = 10;
        }
        if (i == 11)
        {
            data->shield5.current_force = 15;
        }
        if (i == 13)
        {
            data->shield5.current_force = -15;
        }

        // printf("\n[*] Time %d - Position %f  - Velocity %f - Acceleration %f - Force %f \n", i,
        //                                                         data->actual_position5[i], 
        //                                                         data->actual_velocity5[i], 
        //                                                         data->actual_acceleration5[i],
        //                                                         data->shield5.current_force);   

        update_acceleration(&data->shield5, &data->config);
        update_velocity(&data->shield5, &data->config);
        update_position(&data->shield5, &data->config);
    }

    data->expected_position5[0] = 69;
    data->expected_velocity5[0] = 0;
    data->expected_acceleration5[0] = 0;

    data->expected_position5[1] = 70;
    data->expected_velocity5[1] = 1;
    data->expected_acceleration5[1] = 1;

    data->expected_position5[2] = 72;
    data->expected_velocity5[2] = 2;
    data->expected_acceleration5[2] = 1;  


    data->expected_position5[3] = 75;
    data->expected_velocity5[3] = 3;
    data->expected_acceleration5[3] = 1;     


    data->expected_position5[4] = 78;
    data->expected_velocity5[4] = 3; 
    data->expected_acceleration5[4] = 0; 

    data->expected_position5[5] = 81;
    data->expected_velocity5[5] = 3;
    data->expected_acceleration5[5] = 0;

    data->expected_position5[6] = 84;
    data->expected_velocity5[6] = 3;
    data->expected_acceleration5[6] = 0;

    data->expected_position5[7] = 87;
    data->expected_velocity5[7] = 3;
    data->expected_acceleration5[7] = 0;

    data->expected_position5[8] = 90;
    data->expected_velocity5[8] = 3;
    data->expected_acceleration5[8] = 0;

    data->expected_position5[9] = 94;
    data->expected_velocity5[9] = 4;
    data->expected_acceleration5[9] = 1;

    data->expected_position5[10] = 100;
    data->expected_velocity5[10] = 6;
    data->expected_acceleration5[10] = 2;

    data->expected_position5[11] = 108;
    data->expected_velocity5[11] = 8;
    data->expected_acceleration5[11] = 2;

    data->expected_position5[12] = 119;
    data->expected_velocity5[12] = 11;
    data->expected_acceleration5[12] = 3;

    data->expected_position5[13] = 133;
    data->expected_velocity5[13] = 14;
    data->expected_acceleration5[13] = 3;

    data->expected_position5[14] = 144;
    data->expected_velocity5[14] = 11;
    data->expected_acceleration5[14] = -3;

    data->expected_position5[15] = 152;
    data->expected_velocity5[15] = 8;
    data->expected_acceleration5[15] = -3;

}

CTEST2(shield_physics, init) {
    printf("\nCheck that the data has been initialized correctly\n");

    ASSERT_EQUAL(5, data->shield.current_force);
    ASSERT_EQUAL(5, data->shield.mass);

}

CTEST2(shield_physics, constant_force) {
    printf("\nChecking that the physics engine behaves as expected when constant force is applied\n");

    for (int i = 0; i < 8; i++)
    {
        // printf("\nExpected : %f        Actual : %f\n", data->expected_position1[i], data->actual_position1[i]);
        ASSERT_EQUAL(data->expected_position0[i], data->actual_position0[i]);
        ASSERT_EQUAL(data->expected_velocity0[i], data->actual_velocity0[i]);
        ASSERT_EQUAL(data->expected_acceleration0[i], data->actual_acceleration0[i]);
    }
}


CTEST2(shield_physics, collision) {
    printf("\nCheck that shield stops when it collides with canyon wall\n");

    printf("----------> Collision with the right wall\n");
    for (int i = 0; i < 8; i++)
    {
        // printf("\nExpected : %f        Actual : %f\n", data->expected_position0[i], data->actual_position0[i]);
        ASSERT_EQUAL(data->expected_position1[i], data->actual_position1[i]);
        ASSERT_EQUAL(data->expected_velocity1[i], data->actual_velocity1[i]);
        ASSERT_EQUAL(data->expected_acceleration1[i], data->actual_acceleration1[i]);
    }

    printf("----------> Collision with the left wall\n");

    for (int i = 0; i < 8; i++)
    {
        // printf("\nExpected : %f        Actual : %f\n", data->expected_position0[i], data->actual_position0[i]);
        ASSERT_EQUAL(data->expected_position2[i], data->actual_position2[i]);
        ASSERT_EQUAL(data->expected_velocity2[i], data->actual_velocity2[i]);
        ASSERT_EQUAL(data->expected_acceleration2[i], data->actual_acceleration2[i]);
    }

}

CTEST2(shield_physics, deceleration) {
    printf("\nCheck that shield decelerates as opposed force is applied\n");


    printf("\n ----------> Negative Decelleration Test \n");
    for (int i = 0; i < 8; i++)
    {
        // printf("\nExpected : %f        Actual : %f\n", data->expected_position3[i], data->actual_position3[i]);
        ASSERT_EQUAL(data->expected_position3[i], data->actual_position3[i]);
        ASSERT_EQUAL(data->expected_velocity3[i], data->actual_velocity3[i]);
        ASSERT_EQUAL(data->expected_acceleration3[i], data->actual_acceleration3[i]);
    }

    printf("\n ----------> Postiive Decelleration Test \n");    
    for (int i = 0; i < 8; i++)
    {
        // printf("\nExpected : %f        Actual : %f\n", data->expected_position3[i], data->actual_position3[i]);
        ASSERT_EQUAL(data->expected_position4[i], data->actual_position4[i]);
        ASSERT_EQUAL(data->expected_velocity4[i], data->actual_velocity4[i]);
        ASSERT_EQUAL(data->expected_acceleration4[i], data->actual_acceleration4[i]);
    }
}
CTEST2(shield_physics, variable_acceleration) {
    printf("\nCheck that shield adapts to a variable acceleration\n");

    for (int i = 0; i < 16; i++)
    {
        
        ASSERT_EQUAL(data->expected_position5[i], data->actual_position5[i]);
        ASSERT_EQUAL(data->expected_velocity5[i], data->actual_velocity5[i]);
        ASSERT_EQUAL(data->expected_acceleration5[i], data->actual_acceleration5[i]);
    }
}

// CTEST_DATA(shield_physics_1) {

// };

