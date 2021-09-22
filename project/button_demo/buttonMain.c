#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "stateMachines.h"

void main(void) 
{  
  configureClocks();
  switch_init();
  led_init();
  buzzer_init();

  // function_assembly(); /*uncomment to try out the assembly code
  enableWDTInterrupts();

  or_sr(0x18);  // CPU off, GIE on
} 
