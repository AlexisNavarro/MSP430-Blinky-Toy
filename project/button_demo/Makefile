# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf 

#additional rules for files
button.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o led.o switches.o buttonMain.o buzzer.o wdInterruptHandler.o stateMachines.o function.o  ../lib/libTimer.a 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf *~* *#*

buttonMain.o: buttonMain.c

led.o: led.c led.h

switches.o: switches.c switches.h

stateMachines.o: stateMachines.c stateMachines.h

p1_interrupt_handler.o: p1_interrupt_handler.c

buzzer.o: buzzer.c buzzer.h

function.o: switches.h

wdInterruptHandler.o: wdInterruptHandler.c buzzer.h led.h switches.h stateMachines.h 
