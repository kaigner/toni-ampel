 int shiftPin = 12;
int storePin = 8;
int dataPin = 11;

int ampel_all[16] = {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

int ampel_gelb[16] = {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0};
int ampel_gruen[16] = {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0};
int ampel_rot[16] = {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1};
int ampel_reset[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int muster[16];
void setup() {
  Serial.begin(9600);
  pinMode(shiftPin, OUTPUT);
  pinMode(storePin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  // Alle Pins auf LOW (Paranoia-Modus)
  digitalWrite(storePin, LOW);
  digitalWrite(shiftPin, LOW);
  digitalWrite(dataPin, LOW);

  // Ampelsteuerung
  led_ausgabe(ampel_rot);
  delay(20000);
  led_ausgabe(ampel_gelb);
  delay(4000);
  led_ausgabe(ampel_gruen);
  delay(15000);
  led_ausgabe(ampel_gelb);
  delay(4000);
}

void led_ausgabe(int arr[]) {
  memcpy( muster, arr, 16*sizeof(int) );
  for (int i=0; i<16; i++) {
    digitalWrite(shiftPin, LOW);
    digitalWrite(dataPin, muster[i]);
    digitalWrite(shiftPin, HIGH);
  }
  digitalWrite(storePin, HIGH);
  digitalWrite(storePin, LOW);
}


