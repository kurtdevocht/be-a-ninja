// Om een servo-motor aan te sturen hebben we een extra biobliotheek nodig: Servo.h
#include <Servo.h>

// Hey arduino, ik wil een servo-motor aansturen! Ik noem hem 'mijnServoMotor'
Servo mijnServoMotor;


// De functie 'setup()' wordt 1 keer uitgevoerd als de Arduino opstart.
// Alles wat je bij het opstarten wil instellen dient dus binnen de functie 'setup()' te gebeuren.
void setup() {

  // Aan pin 2 komt de drukknop, dat is een input
  pinMode(2, INPUT_PULLUP);

  // De servo-motor komt aan pin 3
  mijnServoMotor.attach(3);

  // Aan pin 10 komt de beeper, dat is een output
  pinMode(10, OUTPUT);
  
}


// Nadat de functie setup() klaar is wordt de functie 'loop()' eindeloos herhaald.
void loop() {

  // Eerst checken we of de drukknop ingedrukt is:
  //
  //   - met de functie 'digitalRead' lezen we de status van een pin uit.
  //   - 'digitalRead' geeft 'LOW' terug als de pin laag is (OV / GND)
  //   - 'digitalRead' geeft 'HIGH' terug als de pin hoog is (5V)
  //
  // Als de drukknop ingedrukt is dan wordt de pin met de 0V (GND) verbonden.
  // Als 'digitalRead' LOW terugeeft weten we dus dat de drukknop ingedrukt is
  if( digitalRead( 2 ) == LOW )
  {
    // Yes! De drukknop is ingedrukt! Tijd om te lanceren!


    // Eerst een paar beepjes...
    for( int i = 0; i < 3; i++) // Herhaal 3 keer...
    {
      tone( 10, 2000); // Start een lage toon op pin 10
      delay( 500);     // Wacht een halve seconde (500ms)
      noTone( 10 );    // Stilte aub op pin 10...
      delay( 500);     // Wacht een halve seconde (500ms)
    }
    // Start een hoge toon op pin 10
    tone( 10, 4000);

    // Wacht 500ms
    delay( 500);

    // Zet de servo-motor in lanceerpositie (40°)
    mijnServoMotor.write(40);
    
    // Wacht 500ms en zet de beeper daarna uit
    delay(500);
    noTone( 10);

    // Wacht 2 seconden (zodat de motor zeker 2 seconden in lanceerpositie blijft)
    delay( 2000);
  }
  else // Deze 'else' hoort bij de 'if' => Hier kom je dus als de drukop niet is ingedrukt
  {
    // De drukknop is niet ingedrukt...
    // => Zet de servo-motor in startpositie (120°)
     mijnServoMotor.write(120);
  }
}
