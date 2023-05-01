#define DEBUG
#define SET_MASK(bitPosition) ((volatile uint8_t)1 << bitPosition)
#define RESET_MASK(bitPosition) ((volatile uint8_t)0 << bitPosition)

#define BUILT_ACSR   *((volatile uint8_t*) 0x50)
#define BUILT_ADCSRB *((volatile uint8_t*) 0x7B)
#define BUILT_ADCSRA *((volatile uint8_t*) 0x7A)

volatile uint32_t currentTime;
volatile uint32_t previousTime;
volatile uint8_t detectFlag;


void setup() {
  //Select the AIN0 to the positive input to the analog comperator
  //BUILT_ACSR |= RESET_MASK(6);

  //ADC multiplexer selects the negative input to the analog comperator
   BUILT_ADCSRB |= SET_MASK(6);// ACME bit 1
   BUILT_ADCSRA |= RESET_MASK(7);//ADEN bit 0

  //MUX0 MUX1 MUX2 001 select analog comperator to negative input
   BUILT_ADCSRA |= SET_MASK(0);

  //Reset ACO bit to turn on the comperator(Optional)
   BUILT_ACSR |= RESET_MASK(7);

  //Set ACIS1 set and ACIS0 set to rising output interrupt mode
   BUILT_ACSR |= (SET_MASK(1) | SET_MASK(0));
}

void loop() {
  if( detectFlag == 1){
   uint32_t timeGap = currentTime - previousTime;
   #ifdef DEBUG
     Serial.println(timeGap);
   #endif
   
   if(timeGap >= 2000ul){
   #ifdef DEBUG
    Serial.println("clap");
   #endif
   }
   detectFlag = 0;
  }

}

ISR(ANALOG_COMP_vect){ 
   currentTime = millis();
   detectFlag = 1;
}
