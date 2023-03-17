// State Machine Implemntation

// Changing the LEDs status based on the number of times the Button S1 is pressed.
#define ZERO 0
#define TIME 50
#define VAL_EIGHT 8

// State Machine Implemntation

// Changing the LEDs status based on the number of times the Button S1 is pressed.

// Initializing a global variable state with "initial state 0"
unsigned int state = ZERO;

void setup()
{
  // Define pins 2 as INPUT
  DDRD &= ~0b00000100;
  // Define pins 11,12,13 as OUTPUTs
  DDRB |= 0b00111000;
}

void loop()
{
  unsigned char btn1;
  // Extract information about pin 2
  // to find if button is pressed/released
  btn1 = PIND & 0b00000100;
  if (btn1 != ZERO) // button is pressed
  {
    delay(TIME); // basic debouncing after pressing
    // Wait while button is pressed
    // Read the value over and over again..
    while((PIND & 0b00000100) != ZERO);
    delay(TIME); // basic debouncing after releasing
    
    ++state; // Increment state by 1
    if (state == VAL_EIGHT)
        state = ZERO; // Return to the initial state
    
    switch(state){
     case 0:
      PORTB &= ~0b00111000; // Turn OFF 3 LEDS
      break;
     case 1:
      PORTB &= ~0b00110000; // Turn OFF LED1, LED2
      PORTB |=  0b00001000; // Turn ON LED3
      break;
     case 2:
      PORTB &= 0b0011000; // Turn OFF LED1, LED3
      PORTB |= 0b00010000; // Turn ON LED2
      break;
     case 3:
      PORTB &= ~0b00100000; // Turn OFF LED1
      PORTB |=  0b00011000; // Turn ON LED2, LED3
      break;
     case 4:
      PORTB &= ~0b00011000; // Turn OFF LED2, LED3
      PORTB |=  0b00100000; // Turn ON LED1
      break;
     case 5:
      PORTB &= ~0b00010000; // Turn OFF LED2
      PORTB |=  0b00101000; // Turn ON LED1, LED3
      break;
     case 6:
      PORTB &= ~0b00001000; // Turn OFF LED3
      PORTB |=  0b00110000; // Turn ON LED1, LED2
      break;
     case 7:
      PORTB |= 0b00111000; // Turn ON LED1, LED2, LED3
      break;
     default:
      // Add some code..
      printf("monkey \n\r");
      break;
    }
    
    
  }
  
}
