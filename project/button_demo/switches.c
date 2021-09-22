#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"

char switch_state_down1, switch_state_down2, switch_state_down3, switch_state_down4;
char switch_state_changed; /* effectively boolean */
static char state = 0;

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  
  if(p2val & SW1 ? 0 : 1){
    switch_state_adv(0);
  }
  if(p2val & SW2 ? 0 : 1){
    switch_state_adv(1);
  }
  if(p2val & SW3 ? 0 : 1){
    switch_state_adv(2);
  }

  if(p2val & SW4 ? 0 : 1){
    switch_state_adv(3);
  }
  led_update();

  
  //this works to press the buttons, use this if you want to see a basic pattern.
  /*switch_state_down1 = (p2val & SW1) ? 0 : 1;
  switch_state_down2 = (p2val & SW2) ? 0 : 1;
  switch_state_down3 = (p2val & SW3) ? 0 : 1;
  switch_state_down4 = (p2val & SW4) ? 0 : 1;
  switch_state_changed = 1;
  led_update();
  */
  
}//end switch_interrupt_handler
