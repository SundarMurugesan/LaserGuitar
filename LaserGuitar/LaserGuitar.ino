/* ==================================================================
 * ----------------------Laser Guitar Sensor-------------------------
 * ==================================================================
 * turns on and off a light emitting diode(LED) connected to digital  
 * pin 13. The amount of time the LED will be on and off depends on
 * the value obtained by analogRead() that is depending of the amount
 * of light in the LDR
 *===================================================================
 *Sundar Murugesan and Warren Pinto
 *===================================================================
 */
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165 //
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220 // 
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294 //
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#include <Time.h>  

// notes in the melody:
int melody[] = {NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {4, 8, 8, 4,4,4,4,4 };
int t= NOTE_E3;

int LDR = 0;       // select the input pin for the LDR
int LDR2 = 1;       // select the input pin for the knob
int LDR3 = 2;       // select the input pin for the LDR
int ledPin = 3;   // select the pin for the LED
int val,val2;       // variable to store the value coming from the sensor
int knobREADIN = 3;       // variable to store the value coming from the sensor
int knobREADIN2 = 4;       // variable to store the value coming from the sensor
int knobREADIN3 = 5;       // variable to store the value coming from the sensor
int knob, knob2, knob3;

int val3 = 0;       // variable to store the value coming from the sensor
double temp, temp2, temp3;
boolean active; 

void setup()
{
  Serial.begin(9600);
  pinMode(LDR, INPUT);       // declare the LDR as an INPUT
  pinMode(LDR2, INPUT);       // declare the LDR as an INPUT
  pinMode(LDR3, INPUT);       // declare the LDR as an INPUT
    
  pinMode(knobREADIN, INPUT);       // declare the LDR as an INPUT
  pinMode(knobREADIN2, INPUT);       // declare the LDR as an INPUT
  pinMode(knobREADIN3, INPUT);       // declare the LDR as an INPUT
  pinMode(8, OUTPUT);  // declare the ledPin as an OUTPUT
 }

void loop() 
{
  val = analogRead(LDR);       // read the value from the sensor
  val2 = analogRead(LDR2);       // read the value from the sensor
  val3 = analogRead(LDR3);       // read the value from the sensor
    
  knob = analogRead(knobREADIN);       // read the value from the sensor
  knob2 = analogRead(knobREADIN2);       // read the value from the sensor
  knob3 = analogRead(knobREADIN3);       // read the value from the sensor
     
  Serial.println(knob3);
  digitalWrite(11, HIGH);
  Serial.println(val);
  Serial.println(val2);
  Serial.println(val3);
  Serial.println("*********************************");
 
   
  if(val > 900 && val2 > 900 && val3 > 900){
    int melody[] = {349, 349, 415, 466, 349, 349, 311, 330, 349, 349, 415, 466, 349, 349, 311, 330};
    int noteDuration = 0;
  // note durations: 4 = quarter note, 8 = eighth note, etc.:
    int noteDurations[] = {4, 4, 2, 2, 4, 4, 4, 4, 4, 4, 4, 2, 2, 4, 4, 4};

  for (int thisNote = 0; thisNote < 16; thisNote++)
  {
    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    if(thisNote  < 2 || thisNote  == 4 || thisNote == 5)
    {
       noteDuration = 1000/4;
    if(thisNote >= 2 && thisNote < 4)  
       noteDuration = 1000/2;
    }
    else
    {
      noteDuration = 1000/4;
      tone(8, melody[thisNote],noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    // stop the tone playing:
      noTone(2);
    }
  }
  else{
       if(val > 900)
       tone(8, knob, ((250))); //pin, note fequency, note duration
     
       if(val2 > 900)
       tone(8, knob2, ((250))); 
     
       if(val3 > 900)
       tone(8, knob3, ((200))); 
   }      
}
