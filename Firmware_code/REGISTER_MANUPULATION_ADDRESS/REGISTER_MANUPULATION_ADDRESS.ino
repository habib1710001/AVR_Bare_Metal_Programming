#define MASK(x) ({\
                  ((uint8_t)1<<(x));\
                 })
#define BUILT_PORTB *((volatile uint8_t*) 0x25)// a pointer that holds an address 0x25 and dereferenced
#define BUILT_DDRB *((volatile uint8_t*) 0x24)

void setup(){
  //volatile uint8_t* ddrbBuilt = 0x24;
  //*ddrbBuilt = 32; 
  BUILT_DDRB = MASK(5);
 }

void loop(){
  //volatile uint8_t* portbBuilt = 0x25; // address of PORT B data register
  //*portbBuilt = 32;
  //Better alternative
  BUILT_PORTB = MASK(5);

  for(uint32_t i = 0; i < 1000000; i++){
   //*portbBuilt = 32;
   BUILT_PORTB = MASK(5); 
  }

  //*portbBuilt = 0;
  BUILT_PORTB = 0;

  for(uint32_t i = 0; i < 1000000; i++){
   //*portbBuilt = 0; 
   BUILT_PORTB = 0;
  }
}
