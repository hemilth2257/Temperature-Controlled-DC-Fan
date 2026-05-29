// --- PIN CONFIGURATION ---
const int ntcPin = A0;          // NTC sensor junction
const int tensDigit = 10;       // Common Cathode for Tens display
const int onesDigit = 11;       // Common Cathode for Ones display

// Segment Pins: A, B, C, D, E, F, G
const int segments[7] = {2, 3, 4, 5, 6, 7, 8};

// --- SEGMENT MAP (Common Cathode) ---
// High = LED ON, Low = LED OFF
byte const numMap[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

void setup() {
  pinMode(tensDigit, OUTPUT);
  pinMode(onesDigit, OUTPUT);
  for (int i = 0; i < 7; i++) {
    pinMode(segments[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // 1. Read Temperature
  int analogValue = analogRead(ntcPin);
  
  // Convert analog to Celsius (Approximate for 10k NTC)
  // This is a simplified linear mapping for testing
  int tempC = map(analogValue, 0, 1023, 100, 0); 
  
  // 2. Display Logic (Multiplexing)
  unsigned long startMillis = millis();
  while (millis() - startMillis < 200) { // Display the number for 200ms
    showDigit(tensDigit, tempC / 10);    // Show Tens
    delay(5); 
    showDigit(onesDigit, tempC % 10);    // Show Ones
    delay(5);
  }

  Serial.print("Temperature: ");
  Serial.println(tempC);
}

void showDigit(int digitPin, int number) {
  // Turn off both digits first to prevent "ghosting"
  digitalWrite(tensDigit, HIGH); 
  digitalWrite(onesDigit, HIGH);

  // Set the segments for the specific number
  for (int i = 0; i < 7; i++) {
    digitalWrite(segments[i], bitRead(numMap[number], i));
  }

  // Turn on the selected digit (Low = Active for Common Cathode)
  digitalWrite(digitPin, LOW);
}
