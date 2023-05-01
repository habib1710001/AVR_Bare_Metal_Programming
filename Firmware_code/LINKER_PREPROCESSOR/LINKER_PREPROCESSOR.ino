#include "library.c"   // copy paste data inside the library.txt

#define BUILT_PORTB *((volatile uint8_t*) 0x25)// #define FIND replace
#define BUILT_DDRB  *((volatile uint8_t*) 0x24)// #define FIND replace

#define MASK(bitPosition)((uint8_t)1 << bitPosition)

void setup(){
  BUILT_DDRB |= MASK(5); // pin 13 as output
}

void loop(){
  BUILT_PORTB ^= MASK(5);
  builtDelay(100000);
}  
