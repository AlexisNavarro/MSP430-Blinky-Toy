#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"


void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static int state_count = 0;


  
  if(++blink_count == 1){
    // function_assembly(); /* dimming doesn't work only the buzzer*/
    switch_interrupt_handler();
    blink_count = 0;
 }//end if

}//end wdt
