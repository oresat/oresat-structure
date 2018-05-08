/*
  
Created 14 March 2018
by John George and Calvin Young

This program controls the battery circuit for the burnwire testing apparatus for the OreSat project (http://oresat.org/).

The apparatus consists of a 3.7 volt single-cell LiPo battery controlled via an Arduino Uno using a ZXMP6A17 MOSFET. As a
safety measure, a mechanical switch is located upstream of the battery.  A monofilament nylon line is pulled taut by a 
spring-loaded hand-made limit switch.  A resistive element (either nichrome wire or a packaged resistor) is in contact with 
the line.  A shunt is placed in line with the circuit in order to measure current and a voltage probe is located on the 
other side of the resistive element.  When the battery circuit is opened, the resistive element (typically around 0.5 to 
1 ohm) heats up and severs the line.  This triggers the limit switch which shuts off the battery circuit.  Voltage, current, 
and time data are sent over serial to be saved as a CSV.

*/

// Initialize Pins and Variables
const byte voltage = A0;
const byte current = A1;
const byte snap = 2; // Must be 2 or 3 (on Arduino Uno) for attachInterrupt()
volatile byte battery = 13; // Controlled by MOSFET
volatile byte led_cold = 12; // Blue
volatile byte led_hot = 10; // Yellow
volatile bool killed = false; // All variables passed to ISR should be volatile
unsigned long time_start = 0;
unsigned long time_current = 0;
unsigned long time_startup = 5; // Delay before experiment
unsigned long time_max = 45; // Failsafe (seconds)

void setup() {
  // Initialize Serial Connection
  Serial.begin(9600);f
  

  // Initialize Pins
  pinMode(led_cold, OUTPUT);
  pinMode(led_hot, OUTPUT);
  pinMode(battery, OUTPUT);
  pinMode(voltage, INPUT);
  pinMode(current, INPUT);
  pinMode(snap, INPUT_PULLUP);

  // Initialize Interrupt
  attachInterrupt(digitalPinToInterrupt(snap), kill, CHANGE);

  // Start with Cold Battery
  digitalWrite(led_hot, LOW);
  digitalWrite(led_cold, HIGH);
  digitalWrite(battery, HIGH);

  // Wait for User Input
  Serial.print(time_max);
  Serial.print(" second failsafe.\n");
  Serial.print(time_startup);
  Serial.print(" second countdown timer.\nFlip switch to ON.\nPress any key to begin test...");
  while (Serial.available() < 1) { delay(100); }

  // Start Experiment
  Serial.print("\n\nInput received. Test beginning in ");
  Serial.print(time_startup);
  Serial.print(" seconds...");
  delay(time_startup*1000);
  time_start = millis();
  Serial.print("\n\nBattery hot!\n\n");
  digitalWrite(led_hot, HIGH);
  digitalWrite(led_cold, LOW);
  digitalWrite(battery, LOW);
  killed = false; // in case it got killed before start
}

void loop() {
  // Update Timer
  time_current = millis() - time_start;
  
  if (time_current > time_max*1000) { 
    // Failsafe
    kill(); 
    Serial.print("\nFailsafe!\n"); }
  else {
    // Print Measurements to Record as CSV
    Serial.print(time_current);
    Serial.print(",");
    Serial.print(analogRead(voltage));
    Serial.print(",");
    Serial.print(analogRead(current));
    Serial.print("\n");
  }

  // Kill Program Dead (can't use delay in ISR)
  if (killed) { 
    Serial.print("\nBattery cold! Flip switch to OFF before disconnecting or resetting."); 
    while(true) { delay(100000); } }
}

void kill() {
  // Kill Battery
  digitalWrite(battery, HIGH);
  digitalWrite(led_hot, LOW);
  digitalWrite(led_cold, HIGH);
  killed = true;
}
