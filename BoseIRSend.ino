#include <IRLib.h>
#include <Keypad.h>

const byte ROWS = 2; // two rows
const byte COLS = 2; // two columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2'},
  {'3','4'},
};
// Connect keypad ROW0, ROW1, to these Arduino pins.
byte rowPins[ROWS] = { 9, 8 };
// Connect keypad COL0, COL1 to these Arduino pins.
byte colPins[COLS] = { 11, 10 }; 

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define ledpin 12

IRsend My_Sender;

void setup()
{
  pinMode(ledpin,OUTPUT);
  digitalWrite(ledpin, LOW);
}

void loop()
{
  char key = kpd.getKey();
  if(key)  // Check for a valid key.
  {
    switch (key)
    {
      case '1': //POWER
	digitalWrite(ledpin, HIGH);
	My_Sender.send(NEC,0x5dd232cd, 32); 
	digitalWrite(ledpin, LOW);       
        break;
      
      case '2': //MUTE
        digitalWrite(ledpin, HIGH);
        My_Sender.send(NEC,0x5dd2807f, 32);
        digitalWrite(ledpin, LOW);
        break;
              
      case '3': //VOL +
        digitalWrite(ledpin, HIGH);
    	My_Sender.send(NEC,0x5dd2C03f, 32);
      	digitalWrite(ledpin, LOW);
        break;
                
      case '4': //VOL -
        digitalWrite(ledpin, HIGH);
    	My_Sender.send(NEC,0x5dd240bf, 32);
	digitalWrite(ledpin, LOW);
        break;       
    }
  }
}
