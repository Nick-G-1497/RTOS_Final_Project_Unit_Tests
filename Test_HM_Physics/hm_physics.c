#include "hm_physics.h"
#include <math.h>



void update_position(ShieldPosition_t* shield, Harkonnen_Mass_Position_t* state, GameConfigurations_t* config){
    // check if the mass is already bumping into the canyon walls
        // if so don't update the position
        // else bounce the ball off the canyon wall
    
    float updated_x = state->x + state->velocity_x * config->tau_phy;

    if ( (updated_x < state->max_x) && (updated_x > state->min_x) )
    {
        state->x = state->x + state->velocity_x * config->tau_phy;
        // printf("\n Position : %f ", state->x);
    }

    else if ( updated_x >= state->max_x)
    {
        state->x = state->max_x;
        state->velocity_x = - (state->velocity_x);
    }

    else if (updated_x <= state->min_x)
    {
        state->x = state->min_x;
        state->velocity_x = - (state->velocity_x);
    }


    // update the velocity
    state->velocity_y = state->velocity_y - (config->gravity*config->tau_phy) ;

    float updated_y = state->y + state->velocity_y * config->tau_phy;

    if (updated_y <= 0)
    {
        // if the mass does come into contact with the shield
        if ( ( state-> x  <= (shield->x + config->length_P/2) ) && ( state->x >= (shield->x - config->length_P/2) ))
        {
            // calculate kinetic energy
            float kinetic_energy = ( state->mass*(state->velocity_y*state->velocity_y) ) / 2 ;
            printf("\n Old Kinetic Energy %f \n", kinetic_energy);
            // scale the kinetic energy
            if (shield->isBoosted)
            {
                kinetic_energy = kinetic_energy * config->kinetic_energy_increase_from_boost/100 ;
            }
            else 
            {
                kinetic_energy = kinetic_energy * config->kinetic_energy_conserved_from_bounce/100;
            }

            float new_velocity = sqrtf( (2*kinetic_energy) / state->mass );
            // update the velocity
            state->velocity_y =  new_velocity;
            // printf("\n New Kinetic Energy %f \n", kinetic_energy);
            // printf("\n New Velocity %f \n", new_velocity);
            // printf("\n Collision \n");
            state->y = 0;
        }
        else
        {
            // printf("\n No Collision \n");
            state->y = 127;
        }

        
    }
    else{

        // if the mass does not come into contact with the shield
        state->y = updated_y;
    }

}
