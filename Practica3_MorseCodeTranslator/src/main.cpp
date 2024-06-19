#include <Arduino.h>

int ledPin = 17;

const char* letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."          // S-Z
};

const char* numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

int dotDelay = 200;
String message = "";

void flashDotOrDash(char dotOrDash)
{
  digitalWrite(ledPin, HIGH);
  if (dotOrDash == '.')
  {
    delay(dotDelay);           
  }
  else // must be a -
  {
    delay(dotDelay * 3);           
  }
  digitalWrite(ledPin, LOW);    
  delay(dotDelay); // gap between flashes
}

void flashSequence(const char* sequence)
{
   int i = 0;
   while (sequence[i] != '\0')
   {
       flashDotOrDash(sequence[i]);
       i++;
   }
   delay(dotDelay * 3);    // gap between letters
}

void setup()                 
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()                    
{
  while (Serial.available()) {
    char c = Serial.read();
    Serial.print(c);  // Print the character to the Serial Monitor
    if (c == '\n') {
      for (int i = 0; i < message.length(); i++) {
        char ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
          flashSequence(letters[ch - 'a']);
        }
        else if (ch >= 'A' && ch <= 'Z') {
          flashSequence(letters[ch - 'A']);
        }
        else if (ch >= '0' && ch <= '9') {
          flashSequence(numbers[ch - '0']);
        }
        else if (ch == ' ') {
          delay(dotDelay * 4);  // gap between words  
        }
      }
      message = "";  // Clear the message
    } else {
      message += c;
    }
  }
}
