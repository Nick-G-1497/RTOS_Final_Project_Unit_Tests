#include "shield_physics.h"


void update_acceleration(ShieldPosition_t* state, GameConfigurations_t* config)
{
    // Get the current force being applied to the shield

    
    float F = state->current_force;
    float m = state->mass;

    // printf("\n Force: %f \n", F);
    // printf("\n Mass : %f", m);


    state->acceleration_x = F/m;

    // printf("\n Acceleration : %f ", state->acceleration_x);

}


void update_velocity(ShieldPosition_t* state, GameConfigurations_t* config)
{
    // printf("\n  Before - Velocity : %f ", state->velocity_x);
    state->velocity_x = state->velocity_x + (state->acceleration_x * config->tau_phy);
    // printf("\n  After - Velocity : %f ", state->velocity_x);   
}

void update_position(ShieldPosition_t* state, GameConfigurations_t* config)
{
    // check if the shield is already bumping into the canyon walls
        // if so don't update the position
        // else update the position
    
    float updated_x = state->x + state->velocity_x * config->tau_phy;

    if ( (updated_x < state->max_x) && (updated_x > state->min_x) )
    {
        state->x = state->x + state->velocity_x * config->tau_phy;
        // printf("\n Position : %f ", state->x);
    }

    else if ( updated_x >= state->max_x)
    {
        state->x = state->max_x;
        state->velocity_x = 0;
        state->acceleration_x = 0;
    }

    else if (updated_x <= state->min_x)
    {
        state->x = state->min_x;
        state->velocity_x = 0;
        state->acceleration_x = 0;
    }
        

}
