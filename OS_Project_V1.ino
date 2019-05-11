#include <LiquidCrystal.h>
#include <Thread.h>

int redLedPin = 9;
int greenLedPin = 8;
int blueLedPin = 10;

int piezoPin = 6;

float d=587.33;
float D=622.25;
float e=659.26;
float f=698.46;
float c=523.25;
float A=440;
float g=392;

LiquidCrystal lcd(12,11,5,4,3,2);

//Red LED Thread
Thread redLedThread = Thread();

// callback for redLedThread
void blinkRedLed(){
	static bool redLedStatus = false;
	redLedStatus = !redLedStatus;
	digitalWrite(redLedPin, redLedStatus);
}

// Green LED Thread
Thread greenLedThread = Thread();

// callback for greenLedThread
void blinkGreenLed(){
  static bool greenLedStatus = false;
  greenLedStatus = !greenLedStatus;
  digitalWrite(greenLedPin, greenLedStatus);
}

// Blue LED Thread
Thread blueLedThread = Thread();

// callback for greenLedThread
void blinkBlueLed(){
  static bool blueLedStatus = false;
  blueLedStatus = !blueLedStatus;
  digitalWrite(blueLedPin, blueLedStatus);
}

// Music Thread
Thread musicThread = Thread();

// callback for musicThread
void infinityWarTheme(){
  
  // Line 1 
  
  tone(piezoPin,d,50);
  
  delay(500);
  
  tone(piezoPin,d,50);
  delay(100);
  tone(piezoPin,d,50);
  delay(100);
  tone(piezoPin,d,50);

  delay(300);

  tone(piezoPin,d,50);
  delay(100);
  tone(piezoPin,d,50);
  delay(100);
  tone(piezoPin,d,50);
  delay(100);
  tone(piezoPin,D,50);
  delay(100);
  tone(piezoPin,D,50);
  delay(100);
  tone(piezoPin,D,50);

  delay(300);

  tone(piezoPin,D,50);
  delay(100);
  tone(piezoPin,D,50);
  delay(100);
  tone(piezoPin,e,50);

  delay(300);

  // Line 2
  
  tone(piezoPin,e,50);
  delay(100);
  tone(piezoPin,e,50);
  delay(100);
  tone(piezoPin,e,50);
  delay(100);
  tone(piezoPin,e,50);
  delay(100);
  tone(piezoPin,f,50);
  delay(100);
  tone(piezoPin,f,50);
  delay(100);
  tone(piezoPin,f,50); 
  
  delay(300);

  tone(piezoPin,f,50);
  delay(100);
  tone(piezoPin,f,50);
  delay(100);
  tone(piezoPin,e,50);

  delay(300);
  
  tone(piezoPin,e,50);
  delay(100);
  tone(piezoPin,e,50);
  delay(100);
  tone(piezoPin,e,50);
  delay(100);
  tone(piezoPin,e,50);
  delay(100);
  tone(piezoPin,D,50);
  delay(100);
  tone(piezoPin,D,50);
  delay(100);
  tone(piezoPin,D,50);

  delay(300);

  // Line 3

  tone(piezoPin,D,50);
  delay(100);
  tone(piezoPin,D,50);

  delay(400);

  tone(piezoPin,c,50);

}

// LCD Thread Row 1
Thread lcdThread1 = Thread();

// callback for lcdThread
void lcdMessage1(){
  lcd.setCursor(0,0);
  lcd.print("OS Project");
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("                ");
}

// LCD Thread Row 2
Thread lcdThread2 = Thread();

// callback for lcdThread2
void lcdMessage2(){
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("Threads: 6");
}

void setup(){
	Serial.begin(9600);
  lcd.begin(16,2);
  // Red LED Setup 
	pinMode(redLedPin, OUTPUT);
	redLedThread.onRun(blinkRedLed);
	redLedThread.setInterval(500);

  // Green LED Setup
  pinMode(greenLedPin, OUTPUT);
  greenLedThread.onRun(blinkGreenLed);
  greenLedThread.setInterval(1000);

  // Blue LED Setup
  pinMode(blueLedPin, OUTPUT);
  blueLedThread.onRun(blinkBlueLed);
  blueLedThread.setInterval(2000);

  // Music Thread Setup
  musicThread.onRun(infinityWarTheme);
  musicThread.setInterval(20000);

  // LCD Thread 1
  lcdThread1.onRun(lcdMessage1);
  lcdThread1.setInterval(200);

  // LCD Thread 2
  lcdThread2.onRun(lcdMessage2);
  lcdThread2.setInterval(100);
}

void loop(){
	
	// Run Red LED Thread
	if(redLedThread.shouldRun()) {
    redLedThread.run();
	}

  // Run Green LED Thread
  if(greenLedThread.shouldRun()) {
     greenLedThread.run();
  }
 
  // Run Blue LED Thread
  if(blueLedThread.shouldRun()) {
    blueLedThread.run();
  }
  
  // Run Music Thread 
  if(musicThread.shouldRun()) {
    musicThread.run();
  }

  // Run LCD Thread 1 
  if(lcdThread1.shouldRun()) {
    lcdThread1.run();
  }
   
  // Run LCD Thread 2 
  if(lcdThread2.shouldRun()) {
    lcdThread2.run();  
  }
  
}
