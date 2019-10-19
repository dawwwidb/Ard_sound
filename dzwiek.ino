/*
 * Signed-off-by: Dawid Be <dawwwidb@gmail.com>
 * Zabawy z dzwiękiem w Arduino
 */

#define Port_Sound 10

void led(int port);                                         //zmiana stanu na porcie-diodzie
void beep_a(int port, int czas_ms);                         //ton 2000Hz na porcie port o czasie trwania czas_ms
void syrena(int port, int czas_ms, int Powtorki);           //syrena - zagraj Powtorki razy dwa naprzemienne dźwięki
void sound (int port, int czestotliwosc_start, int czestotliwosc_koniec, int Krokow);          //graj na porcie dzwięki od czestotliwosc_start do czestotliwosc_koniec w Krokow krokach


void setup() {
  
  // Definicja portow
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Port_Sound, OUTPUT);

  //Start Serial
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {

Serial.println("Start");

Serial.println("Led");
led(LED_BUILTIN);

Serial.println("Beep");
beep_a(Port_Sound, 250);  //beep 250ms on i 250ms off
delay(1000);

Serial.println("Syrena");
syrena(Port_Sound,200,5); //syrena 5x200ms on/off
delay(1000);

Serial.println("Sound");
sound (Port_Sound, 100, 1000, 10);
delay(1000);

Serial.println("Pauza");
delay(5000);
}



void led(int port)
  {
    digitalWrite (port, !digitalRead(port));//zmiana stanu na porcie
  }

void beep_a(int port, int czas_ms) 
  {
      tone(port, 2000); //Wygeneruj sygnał o częstotliwości 2000Hz 
      delay(czas_ms);  
      noTone(port);
  }
  
void syrena(int port, int czas_ms, int powtorki)
  {
    for(int i=0;i<powtorki;i++)
      {
        tone(port, 2300); //Wygeneruj sygnał o częstotliwości 4300Hz  
        delay(czas_ms);  
        tone(port, 1500); //Wygeneruj sygnał o częstotliwości 3500Hz
        delay(czas_ms);
      }
  noTone(Port_Sound);   
  }

void sound (int port, int f1, int f2,  int kroki)                      //graj na porcie dzwięków f1-f2
{  
  int krok=f2/kroki;
  Serial.print("Sound od ");Serial.println(f1);
  Serial.print("Sound do ");Serial.println(f2);
  Serial.print("Sound krokow ");Serial.println(kroki);
  Serial.print("Sound krok ");Serial.println(krok);

  for (int i=f1;i<=f2;i+=krok)
  {
    Serial.print("Sound  ");Serial.println(i);
    tone (port, i,1000 );
    delay(300);
  }
  noTone(Port_Sound);
}
