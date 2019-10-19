
#define Port_Sound 10

void port_a(int port, bool stan);
void port_a(int port, bool stan, int pauza_ms);
void beep_a(int port, bool stan_poczatkowy, int czas_ms);



void setup() {
  
  // Definicja portow
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Port_Sound, OUTPUT);

  //Start Serial
  Serial.begin(9600);
  Serial.println("Start");

  
}

// the loop function runs over and over again forever
void loop() {

beep_a(LED_BUILTIN,HIGH,250);


  tone (Port_Sound, 2000);
  delay(500);


Serial.println();
Serial.println("Czestotliwosc 0.1-1kHz: ");
for (int i=1;i<=10;i++)
{
  tone (Port_Sound, i*100,1000 );
  Serial.print (i);
    delay(300);
}

noTone(Port_Sound);
delay(5000);
}



void port_a(int port, bool stan)
  {
    digitalWrite(port, stan);   // ustawia port na stan
  }

  
void port_a(int port, bool stan, int pauza_ms)  //przeciążenie funkcji
  {
    digitalWrite(port, stan);   // ustawia port na stan
    delay(pauza_ms);            // pauza
  }


void beep_a(int port, bool stan_poczatkowy, int czas_ms) 
  {
    digitalWrite(port, stan_poczatkowy);   // ustawia port na stan
    delay(czas_ms);            // pauza
    digitalWrite(port, !stan_poczatkowy);   // ustawia port na stan

  /*
   * port_a(port, stan_poczatkowy)
   * delay(pauza_ms);            // pauza
   * port_a(port, !stan_poczatkowy)
   */
  }
