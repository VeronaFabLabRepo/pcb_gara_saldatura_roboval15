/******************************************************************************* 

		Verona FabLab
		Roboval 2015 - "Gara di Saldatura"
		
		Arduino Firmware for Hardware Test
		Program test Vers. 2.0 - 20-May-2015
		Reference A.G.
		
		Arduino Uno - Stand Alone circuit
		HW PCB Vesion 1.0  -  15-May-2015
		Reference A.C.
		

*******************************************************************************/

// External library
//   add here

//------------------------------------------------------------------------------


#define OCTAVE_OFFSET 0


// These values can also be found as constants in the Tone library (Tone.h); not used here.
// Reference: 440 Hz = A (La) note
int notes[] = { 0,
262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494,
523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988,
1047, 1109, 1175, 1245, 1319, 1397, 1480, 1568, 1661, 1760, 1865, 1976,
2093, 2217, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729, 3951
};


// RTTL Song
//char *song = "The Simpsons:d=4,o=5,b=160:c.6,e6,f#6,8a6,g.6,e6,c6,8a,8f#,8f#,8f#,2g,8p,8p,8f#,8f#,8f#,8g,a#.,8c6,8c6,8c6,c6";
//OK
//char *song = "Indiana:d=4,o=5,b=250:e,8p,8f,8g,8p,1c6,8p.,d,8p,8e,1f,p.,g,8p,8a,8b,8p,1f6,p,a,8p,8b,2c6,2d6,2e6,e,8p,8f,8g,8p,1c6,p,d6,8p,8e6,1f.6,g,8p,8g,e.6,8p,d6,8p,8g,e.6,8p,d6,8p,8g,f.6,8p,e6,8p,8d6,2c6";
//OK
//char *song = "TakeOnMe:d=4,o=4,b=160:8f#5,8f#5,8f#5,8d5,8p,8b,8p,8e5,8p,8e5,8p,8e5,8g#5,8g#5,8a5,8b5,8a5,8a5,8a5,8e5,8p,8d5,8p,8f#5,8p,8f#5,8p,8f#5,8e5,8e5,8f#5,8e5,8f#5,8f#5,8f#5,8d5,8p,8b,8p,8e5,8p,8e5,8p,8e5,8g#5,8g#5,8a5,8b5,8a5,8a5,8a5,8e5,8p,8d5,8p,8f#5,8p,8f#5,8p,8f#5,8e5,8e5";
//OK
//char *song = "Entertainer:d=4,o=5,b=140:8d,8d#,8e,c6,8e,c6,8e,2c.6,8c6,8d6,8d#6,8e6,8c6,8d6,e6,8b,d6,2c6,p,8d,8d#,8e,c6,8e,c6,8e,2c.6,8p,8a,8g,8f#,8a,8c6,e6,8d6,8c6,8a,2d6";
//OK
//char *song = "Muppets:d=4,o=5,b=250:c6,c6,a,b,8a,b,g,p,c6,c6,a,8b,8a,8p,g.,p,e,e,g,f,8e,f,8c6,8c,8d,e,8e,8e,8p,8e,g,2p,c6,c6,a,b,8a,b,g,p,c6,c6,a,8b,a,g.,p,e,e,g,f,8e,f,8c6,8c,8d,e,8e,d,8d,c";
//OK
//char *song = "Xfiles:d=4,o=5,b=125:e,b,a,b,d6,2b.,1p,e,b,a,b,e6,2b.,1p,g6,f#6,e6,d6,e6,2b.,1p,g6,f#6,e6,d6,f#6,2b.,1p,e,b,a,b,d6,2b.,1p,e,b,a,b,e6,2b.,1p,e6,2b.";
//char *song = "Looney:d=4,o=5,b=140:32p,c6,8f6,8e6,8d6,8c6,a.,8c6,8f6,8e6,8d6,8d#6,e.6,8e6,8e6,8c6,8d6,8c6,8e6,8c6,8d6,8a,8c6,8g,8a#,8a,8f";
//OK
//char *song = "20thCenFox:d=16,o=5,b=140:b,8p,b,b,2b,p,c6,32p,b,32p,c6,32p,b,32p,c6,32p,b,8p,b,b,b,32p,b,32p,b,32p,b,32p,b,32p,b,32p,b,32p,g#,32p,a,32p,b,8p,b,b,2b,4p,8e,8g#,8b,1c#6,8f#,8a,8c#6,1e6,8a,8c#6,8e6,1e6,8b,8g#,8a,2b";
//char *song = "Bond:d=4,o=5,b=80:32p,16c#6,32d#6,32d#6,16d#6,8d#6,16c#6,16c#6,16c#6,16c#6,32e6,32e6,16e6,8e6,16d#6,16d#6,16d#6,16c#6,32d#6,32d#6,16d#6,8d#6,16c#6,16c#6,16c#6,16c#6,32e6,32e6,16e6,8e6,16d#6,16d6,16c#6,16c#7,c.7,16g#6,16f#6,g#.6";
//char *song = "MASH:d=8,o=5,b=140:4a,4g,f#,g,p,f#,p,g,p,f#,p,2e.,p,f#,e,4f#,e,f#,p,e,p,4d.,p,f#,4e,d,e,p,d,p,e,p,d,p,2c#.,p,d,c#,4d,c#,d,p,e,p,4f#,p,a,p,4b,a,b,p,a,p,b,p,2a.,4p,a,b,a,4b,a,b,p,2a.,a,4f#,a,b,p,d6,p,4e.6,d6,b,p,a,p,2b";
//OK
char *song = "StarWars:d=4,o=5,b=45:32p,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#.6,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#6";
//OK
//char *song = "GoodBad:d=4,o=5,b=56:32p,32a#,32d#6,32a#,32d#6,8a#.,16f#.,16g#.,d#,32a#,32d#6,32a#,32d#6,8a#.,16f#.,16g#.,c#6,32a#,32d#6,32a#,32d#6,8a#.,16f#.,32f.,32d#.,c#,32a#,32d#6,32a#,32d#6,8a#.,16g#.,d#";
//OK
//char *song = "TopGun:d=4,o=4,b=31:32p,16c#,16g#,16g#,32f#,32f,32f#,32f,16d#,16d#,32c#,32d#,16f,32d#,32f,16f#,32f,32c#,16f,d#,16c#,16g#,16g#,32f#,32f,32f#,32f,16d#,16d#,32c#,32d#,16f,32d#,32f,16f#,32f,32c#,g#";
//OK
//char *song = "A-Team:d=8,o=5,b=125:4d#6,a#,2d#6,16p,g#,4a#,4d#.,p,16g,16a#,d#6,a#,f6,2d#6,16p,c#.6,16c6,16a#,g#.,2a#";
//OK
//char *song = "Flinstones:d=4,o=5,b=40:32p,16f6,16a#,16a#6,32g6,16f6,16a#.,16f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c6,d6,16f6,16a#.,16a#6,32g6,16f6,16a#.,32f6,32f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c6,a#,16a6,16d.6,16a#6,32a6,32a6,32g6,32f#6,32a6,8g6,16g6,16c.6,32a6,32a6,32g6,32g6,32f6,32e6,32g6,8f6,16f6,16a#.,16a#6,32g6,16f6,16a#.,16f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c.6,32d6,32d#6,32f6,16a#,16c.6,32d6,32d#6,32f6,16a#6,16c7,8a#.6";
//char *song = "Jeopardy:d=4,o=6,b=125:c,f,c,f5,c,f,2c,c,f,c,f,a.,8g,8f,8e,8d,8c#,c,f,c,f5,c,f,2c,f.,8d,c,a#5,a5,g5,f5,p,d#,g#,d#,g#5,d#,g#,2d#,d#,g#,d#,g#,c.7,8a#,8g#,8g,8f,8e,d#,g#,d#,g#5,d#,g#,2d#,g#.,8f,d#,c#,c,p,a#5,p,g#.5,d#,g#";
//OK
//char *song = "Gadget:d=16,o=5,b=50:32d#,32f,32f#,32g#,a#,f#,a,f,g#,f#,32d#,32f,32f#,32g#,a#,d#6,4d6,32d#,32f,32f#,32g#,a#,f#,a,f,g#,f#,8d#";
//OK
//char *song = "IPuffi:d=32,o=5,b=200:4c#6,16p,4f#6,p,16c#6,p,8d#6,p,8b,p,4g#,16p,4c#6,p,16a#,p,8f#,p,8a#,p,4g#,4p,g#,p,a#,p,b,p,c6,p,4c#6,16p,4f#6,p,16c#6,p,8d#6,p,8b,p,4g#,16p,4c#6,p,16a#,p,8b,p,8f,p,4f#";
//OK
//char *song = "MahnaMahna:d=16,o=6,b=125:c#,c.,b5,8a#.5,8f.,4g#,a#,g.,4d#,8p,c#,c.,b5,8a#.5,8f.,g#.,8a#.,4g,8p,c#,c.,b5,8a#.5,8f.,4g#,f,g.,8d#.,f,g.,8d#.,f,8g,8d#.,f,8g,d#,8c,a#5,8d#.,8d#.,4d#,8d#.";
//OK
//char *song = "LeisureSuit:d=16,o=6,b=56:f.5,f#.5,g.5,g#5,32a#5,f5,g#.5,a#.5,32f5,g#5,32a#5,g#5,8c#.,a#5,32c#,a5,a#.5,c#.,32a5,a#5,32c#,d#,8e,c#.,f.,f.,f.,f.,f,32e,d#,8d,a#.5,e,32f,e,32f,c#,d#.,c#";
//OK
//char *song = "MissionImp:d=16,o=6,b=95:32d,32d#,32d,32d#,32d,32d#,32d,32d#,32d,32d,32d#,32e,32f,32f#,32g,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,a#,g,2d,32p,a#,g,2c#,32p,a#,g,2c,a#5,8c,2p,32p,a#5,g5,2f#,32p,a#5,g5,2f,32p,a#5,g5,2e,d#,8d";


//------------------------------------------------------------------------------


// constants won't change. Used here to set a pin number :
// I/O 0 = PD0,RXD, IC Pin 2, RX
// I/O 1 = PD1,TXD, IC Pin 3, TX

// I/O 2 = PD2,INT0, IC Pin 4, DIG_4
const int LedNum3 =  2;          // the number of the LED #2

// I/O 3 = PD3,INT1, IC Pin 5, DIG_5
const int LedNum2 =  3;          // the number of the LED #3

// I/O 4 = PD4,T0, IC Pin 6, IN_7
const int LedNum8 = 4;        // the number of Led #8 or keyF2

// I/O 5 = PD5,T1, IC Pin 11, IN_6
const int AudioOut_B = 5;        // Audio Out IN_6  alias LedNum7 or keyF1

// I/O 6 = PD6,AIN0, IC Pin 12, IN_1  ##### Arrow SX #####  or A0
const int KeySX = 6;        // the number of the key #1

// I/O 7 = PD7,AIN1, IC Pin 13, IN_2  ##### Arrow DX ##### or A1
const int KeyDX = 7;        // the number of the key #2

// I/O 8 = PB0,CLKO, IC Pin 14, IN_3  ##### Arrow Up #####
const int KeyUp = 8;        // the number of the key #3

// I/O 9 = PB1,OC1A, IC Pin 15, IN_4  ##### Arrow Down #####
const int KeyDown = 9;        // the number of the key #4

// I/O 10 = PB2,OC1B, IC Pin 16, IN_5  ##### Home button #####
const int KeyHome = 10;        // the number of the key #5



// I/O 11 = PB3,MOSI, IC Pin 17, MOSI
const int SignalMOSI = 11;        // MOSI

// I/O 12 = PB4,MISO, IC Pin 18, MISO
const int SignalMISO = 12;        // MISO

// I/O 13 = PB5,SCK, IC Pin 19, SCK
const int SignalSCK = 13;        // SCK
  
  

// I/O 14 = PC0,ADC0, IC Pin 23, AUDIO_IN
const int SignalAnalogIn0 = 14;    // AUDIO_IN (A0)

// I/O 15 = PC1,ADC1, IC Pin 24, IN_8
const int SignalAnalogIn1 = 15;          // IN_8 (A1)  alias LedNum9 or keyF3



// I/O 16 = PC2,ADC2, IC Pin 25, DIG_6
const int LedNum1 = 16;        // DIG_6 (A2),  the number of the LED #1

// I/O 17 = PC3,ADC3, IC Pin 26, DIG_3
const int LedNum4 = 17;        // DIG_3 (A3),  the number of the LED #4

// I/O 18 = PC4,ADC4, IC Pin 27, DIG_2
const int LedNum5 = 18;        // DIG_2 (A4),  the number of the LED #5

// I/O 19 = PC5,ADC5, IC Pin 27, DIG_1
const int LedNum6 = 19;        // DIG_1 (A5),  the number of the LED #6
 


// Variables will change :

bool Debounce = HIGH;
bool reverse = HIGH;
byte index = 0;

      // Led number    1  2  3  4  5  6  7  8  9
int ledNumber[] = { 16, 3, 2, 17, 18, 19, 15, 4, 5 };

      // Led number    1  2  3  4  5  6  7  8  9  mirror of led state
int ledState[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };



// Generally, you shuould use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 500;           // interval at which to blink (milliseconds)



//=================================================================


void setup() { 
  
  // Input Signals
  pinMode(KeySX, INPUT);
  pinMode(KeyDX, INPUT);
  pinMode(KeyUp, INPUT);  
  pinMode(KeyDown, INPUT);  
  pinMode(KeyHome, INPUT);    
  pinMode(SignalAnalogIn0, INPUT);

  // Output Signals  
  pinMode(LedNum1, OUTPUT);
  pinMode(LedNum2, OUTPUT);
  pinMode(LedNum3, OUTPUT);
  pinMode(LedNum4, OUTPUT);  
  pinMode(LedNum5, OUTPUT);  
  pinMode(LedNum6, OUTPUT);
  pinMode(SignalAnalogIn1, OUTPUT);  
  pinMode(AudioOut_B, OUTPUT);
  pinMode(LedNum8, OUTPUT); 

  // ---------------------------------------------

   for (int index=0; index < 9; index++){
         ledState[index] = LOW;
   }

   // Routine to check Output quickly
   LedCheck();  
  
  // Debug
  //Start the serial connection with the computer to view the result open the serial monitor
  Serial.begin(9600); 
  Serial.println(" Ready ");  
  
}


//=================================================================


void loop()
{    
  //int AnalogValue1 = analogRead(SignalAnalogIn1);    // read analog signal from Arduino PIN 15 alias  // IN_8 (A1 Atmel)
  
  
  Main routine that check key pressure on board and activate sub-routine
  KeyCheck(); 
  
  // Time management task
  unsigned long currentMillis = millis(); 
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;   
	// do something
  } 
  Debounce = HIGH;        
}


//==================================================================================================================================

//     Test Function

// --------------------------------------------------------------------------------


void KeyCheck()
{
  ledState[1] = !digitalRead(KeyUp) && digitalRead(KeyDown) && digitalRead(KeySX);   // read UP button only
  digitalWrite(LedNum1, ledState[1]);       // Write status on Led1 (from up order)

  ledState[2] = !digitalRead(KeySX) && digitalRead(KeyDown) && digitalRead(KeyDX) && digitalRead(KeyUp);   // read the SX input button only  
  digitalWrite(LedNum2, ledState[2]);       // Write status on Led2 (from up order)
  
  ledState[3] = !digitalRead(KeyHome) && digitalRead(KeyDown);   // read the CENTER button only
  digitalWrite(LedNum3, ledState[3]);       // Write status on Led3 (from up order)

  ledState[4] = !digitalRead(KeyDX) && digitalRead(KeyDown) && digitalRead(KeySX);   // read DX button  only
  digitalWrite(LedNum4, ledState[4]);       // Write status on Led4 (from up order)  
  
  ledState[5] = !digitalRead(KeyDown) && digitalRead(KeyUp) && digitalRead(KeySX) && digitalRead(KeyHome) && digitalRead(KeyDX);   // read the DOWN button only
  digitalWrite(LedNum5,ledState[5]);       // Write status on Led5 (from up order)
  
  

  ledState[6] = !digitalRead(KeyDown) && !digitalRead(KeyUp);   // read the DOWN & UP togheter
  digitalWrite(LedNum6, ledState[6]);       // Write status on Led5 (from up order)

  ledState[7] = !digitalRead(KeyDown) && !digitalRead(KeySX);   // read the DOWN & SX togheter
  digitalWrite(SignalAnalogIn1, ledState[7]);       // Write status on Led5 (from up order)  

  ledState[8] = !digitalRead(KeyDown) && !digitalRead(KeyHome);   // read the DOWN & HOME togheter
  digitalWrite(LedNum8, ledState[8]);       // Write status on Led5 (from up order)  

  ledState[9] = !digitalRead(KeyDown) && !digitalRead(KeyDX);   // read the DOWN & DX togheter
  digitalWrite(AudioOut_B, ledState[9]);       // Write status on Led5 (from up order)  

  
  
  
  if  (!digitalRead(KeySX) && !digitalRead(KeyDX))
  {
    PhotoResistor();
  }

  if  (!digitalRead(KeySX) && !digitalRead(KeyUp))
  {
    Microphone();
  }
  
  if  (!digitalRead(KeySX) && !digitalRead(KeyHome))
  {
    // example of to set led ON
    digitalWrite(LedNum1, HIGH);
    digitalWrite(LedNum2, HIGH);
    digitalWrite(LedNum3, HIGH);
    digitalWrite(LedNum4, HIGH);
    digitalWrite(LedNum5, HIGH);
    digitalWrite(LedNum6, HIGH);

    // play song selected in header program
    play_rtttl(song);
     
	 // example of to set led OFF - optimization method
     for (int index=0; index < 5; index++){
         digitalWrite(ledNumber[index], LOW);   

     }         
  }  
}


// --------------------------------------------------------------------------------

// Function to convert analog value input in a 6 Bar-Led output

void Analog2Leds(int IntValue)
{
       switch (IntValue) {
        case 0: {
          digitalWrite(LedNum1, HIGH);
          digitalWrite(LedNum2, HIGH);
          digitalWrite(LedNum3, HIGH);
          digitalWrite(LedNum4, HIGH);
          digitalWrite(LedNum5, HIGH);
          digitalWrite(LedNum6, HIGH);
          }
          break;
        case 1: {
          digitalWrite(LedNum1, LOW);
          digitalWrite(LedNum2, HIGH);
          digitalWrite(LedNum3, HIGH);
          digitalWrite(LedNum4, HIGH);
          digitalWrite(LedNum5, HIGH);
          digitalWrite(LedNum6, HIGH);
          }
          break;
        case 2: {
          digitalWrite(LedNum1, LOW);
          digitalWrite(LedNum2, LOW);
          digitalWrite(LedNum3, HIGH);
          digitalWrite(LedNum4, HIGH);
          digitalWrite(LedNum5, HIGH);
          digitalWrite(LedNum6, HIGH);
          }
          break;
        case 3: {
          digitalWrite(LedNum1, LOW);
          digitalWrite(LedNum2, LOW);
          digitalWrite(LedNum3, LOW);
          digitalWrite(LedNum4, HIGH);
          digitalWrite(LedNum5, HIGH);
          digitalWrite(LedNum6, HIGH);
          }
          break;      
        case 4: {
          digitalWrite(LedNum1, LOW);
          digitalWrite(LedNum2, LOW);
          digitalWrite(LedNum3, LOW);
          digitalWrite(LedNum4, LOW);
          digitalWrite(LedNum5, HIGH);
          digitalWrite(LedNum6, HIGH);
          }
          break; 
        case 5: {
          digitalWrite(LedNum1, LOW);
          digitalWrite(LedNum2, LOW);
          digitalWrite(LedNum3, LOW);
          digitalWrite(LedNum4, LOW);
          digitalWrite(LedNum5, LOW);
          digitalWrite(LedNum6, HIGH);
          }
          break; 
        case 6: {
          digitalWrite(LedNum1, LOW);
          digitalWrite(LedNum2, LOW);
          digitalWrite(LedNum3, LOW);
          digitalWrite(LedNum4, LOW);
          digitalWrite(LedNum5, LOW);
          digitalWrite(LedNum6, LOW);
          }
          break; 
          
        default: {
          // if nothing else matches, do the default
          }// default is optional
      }
}  

// --------------------------------------------------------------------------------

// function to "read" analog value of photoresistor 

void PhotoResistor()
{
      int AnalogValue0 = analogRead(SignalAnalogIn0);    // read analog signal from Arduino PIN 14 alias  // AUDIO_IN (A0 Atmel)
      int valueScaled = map(AnalogValue0, 0, 1023, 0, 6); 
      Analog2Leds(valueScaled); 
}


// --------------------------------------------------------------------------------

// function to "read" analog value of microphone  ---  V-Meter function

void Microphone()
{
      int valueScaled = 0;
      int AnalogValue0 = analogRead(SignalAnalogIn0);    // read analog signal from Arduino PIN 14 alias  // AUDIO_IN (A0 Atmel)
      if (AnalogValue0 > 500) // theoretical value is 1024 / 2 = 512; adjust in according with your offset voltage board.
      {
        valueScaled = map(AnalogValue0, 500, 600, 0, 6); 
      } 
      else
      {
        valueScaled = 0;
      }    
      Serial.print(SignalAnalogIn0);
      Serial.print("  ");      
      Serial.println(valueScaled);      
      Analog2Leds(valueScaled);
}


// --------------------------------------------------------------------------------

// Turn on sequentially every Led and after turn off

void LedCheck()
{
   for (int index=0; index < 9; index++){
       digitalWrite(ledNumber[index], HIGH);
       delay(100);
   }         

   for (int index=0; index < 9; index++){
       digitalWrite(ledNumber[index], LOW);   
       delay(100);       
   }     

   tone(AudioOut_B, 1047,  2000);
   delay(1000);
   tone(AudioOut_B,880,  2000);   
   delay(1000);   
   noTone(AudioOut_B);

}


// --------------------------------------------------------------------------------

// Fucntion to turn-off all led/output

void AllLedOff()
{
   for (int index=0; index < 9; index++){
      digitalWrite(ledNumber[index], LOW);
   }         
}



//==================================================================================================================================

//     Music Function

//==================================================================================================================================


#define isdigit(n) (n >= '0' && n <= '9')


void play_rtttl(char *p)
{
  // Absolutely no error checking in here

  byte default_dur = 4;
  byte default_oct = 6;
  int bpm = 63;
  int num;
  long wholenote;
  long duration;
  byte note;
  byte scale;

  // format: d=N,o=N,b=NNN:
  // find the start (skip name, etc)

  while(*p != ':') p++;    // ignore name
  p++;                     // skip ':'

  // get default duration
  if(*p == 'd')
  {
    p++; p++;              // skip "d="
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    
    if(num > 0) default_dur = num;
    p++;                   // skip comma
  }

  //Serial.print("ddur: "); Serial.println(default_dur, 10);

  // get default octave
  if(*p == 'o')
  {
    p++; p++;              // skip "o="
    num = *p++ - '0';
    if(num >= 3 && num <=7) default_oct = num;
    p++;                   // skip comma
  }

  //Serial.print("doct: "); Serial.println(default_oct, 10);

  // get BPM
  if(*p == 'b')
  {
    p++; p++;              // skip "b="
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    bpm = num;
    p++;                   // skip colon
  }

  //Serial.print("bpm: "); Serial.println(bpm, 10);

  // BPM usually expresses the number of quarter notes per minute
  wholenote = (60 * 1000L / bpm) * 4;  // this is the time for whole note (in milliseconds)

  //Serial.print("wn: "); Serial.println(wholenote, 10);


  // now begin note loop
  while(*p)
  {
    // first, get note duration, if available
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    
    if(num) duration = wholenote / num;
    else duration = wholenote / default_dur;  // we will need to check if we are a dotted note after

    // now get the note
    note = 0;

    switch(*p)
    {
      case 'c':
        note = 1;
        break;
      case 'd':
        note = 3;
        break;
      case 'e':
        note = 5;
        break;
      case 'f':
        note = 6;
        break;
      case 'g':
        note = 8;
        break;
      case 'a':
        note = 10;
        break;
      case 'b':
        note = 12;
        break;
      case 'p':
      default:
        note = 0;
    }
    p++;

    // now, get optional '#' sharp
    if(*p == '#')
    {
      note++;
      p++;
    }

    // now, get optional '.' dotted note
    if(*p == '.')
    {
      duration += duration/2;
      p++;
    }
  
    // now, get scale
    if(isdigit(*p))
    {
      scale = *p - '0';
      p++;
    }
    else
    {
      scale = default_oct;
    }

    scale += OCTAVE_OFFSET;

    if(*p == ',')
      p++;       // skip comma for next note (or we may be at the end)

    // now play the note

    if(note)
    {
      //Serial.print("Playing: ");
      //Serial.print(scale, 10); Serial.print(' ');
      //Serial.print(note, 10); Serial.print(" (");
      //Serial.print(notes[(scale - 4) * 12 + note], 10);
      //Serial.print(") ");
      //Serial.println(duration, 10);      
      tone(AudioOut_B, notes[(scale - 4) * 12 + note]);
      delay(duration);
      noTone(AudioOut_B);
    }
    else
    {
      //Serial.print("Pausing: ");
      //Serial.println(duration, 10);
      delay(duration);
    }
  }
}


//==================================================================================================================================

// End of program



