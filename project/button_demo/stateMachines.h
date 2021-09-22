#ifndef stateMachine_included
#define stateMachine_included

void state_advance();

void toggle_red_on();
void toggle_red_off();
void toggle_green_on();
void toggled_green_off();

void red_dim();
void green_dim();
void red_dim_25();
void green_dim_25();

void switch_state_adv(int);

void state_dimming();
void change_states();

#endif // included
