/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

struct TimedText {
  float start;
  //float end;
  char *text;
};

TimedText timed_text [] = { 
{908.58, "fo" },
{911.39, "bo" },
{914.13, "fo" },
{917.04, "bo" },
{920.01, "fo" },
{923.02, "bo" },
{925.8, "fo" },
{928.7, "bo" },
{931.49, "fo" },
{934.2, "bo" },
{936.87, "fo" },
{938.9, "bowo" },
{941.49, "fummsbo" },
{943.7, "bowo" },
{946.28, "fummsbo" },
{948.8, "bowo" },
{951.15, "fummsbo" },
{954, "bowo" },
{956.45, "fummsbo" },
{959.2, "bowo" },
{961.68, "fummsbo" },
{964.51, "bowo" },
{966.9, "fummsbo" },
{969.01, "boworo" },
{971.59, "fummsbowo" },
{974.2, "boworo" },
{976.75, "fummsbowo" },
{979.61, "boworo" },
{981.99, "fummsbowo" },
{985.07, "boworo" },
{987.69, "fummsbowo" },
{990.5, "boworo" },
{993.2, "fummsbowo" },
{996.43, "boworo" },
{999.18, "fummsbowo" },
{1002.05, "boworotaa" },
{1004.53, "fummsbowotaa" },
{1007.2, "boworotaa" },
{1010.26, "fummsbowotaa" },
{1013.3, "boworotaa" },
{1015.94, "fummsbowotaa" },
{1019.07, "boworotaa" },
{1021.46, "fummsbowotaa" },
{1024.7, "boworotaa" },
{1027.37, "fummsbowotaa" },
{1030.53, "boworotaa" },
{1032.88, "fummsbowotaa" },
{1035.2, "boworotaazaa" },
{1037.56, "fummsbowotaazaa" },
{1040.59, "boworotaazaa" },
{1043.2, "fummsbowotaazaa" },
{1046.29, "boworotaazaa" },
{1048.74, "fummsbowotaazaa" },
{1051.92, "boworotaazaa" },
{1054.62, "fummsbowotaazaa" },
{1057.75, "boworotaazaa" },
{1060.24, "fummsbowotaazaa" },
{1063.31, "boworotaazaa" },
{1065.89, "fummsbowotaazaa" },
{1068.94, "boworotaazaaUu" },
{1071.27, "fummsbowotaazaaUu" },
{1074.2, "boworotaazaaUu" },
{1076.8, "fummsbowotaazaaUu" },
{1079.7, "boworotaazaaUu" },
{1082.02, "fummsbowotaazaaUu" },
{1084.91, "boworotaazaaUu" },
{1087.32, "fummsbowotaazaaUu" },
{1090.19, "boworotaazaaUu" },
{1092.66, "fummsbowotaazaaUu" },
{1095.66, "boworotaazaaUu" },
{1098.27, "fummsbowotaazaaUu" },
{1101.36, "boworotaazaaUu po" },
{1103.65, "fummsbowotaazaaUu po" },
{1106.83, "boworotaazaaUu po" },
{1109.51, "fummsbowotaazaaUu po" },
{1112.65, "boworotaazaaUu po" },
{1115.3, "fummsbowotaazaaUu po" },
{1118.7, "boworotaazaaUu po" },
{1121.29, "fummsbowotaazaaUu po" },
{1124.37, "boworotaazaaUu po" },
{1126.84, "fummsbowotaazaaUu po" },
{1129.74, "boworotaazaaUu po" },
{1132.12, "fummsbowotaazaaUu po" },
{1135.01, "boworotaazaaUu pogo" },
{1137.6, "fummsbowotaazaaUu pogo" },
{1140.9, "boworotaazaaUu pogo" },
{1143.72, "fummsbowotaazaaUu pogo" },
{1147.1, "boworotaazaaUu pogo" },
{1149.59, "fummsbowotaazaaUu pogo" },
{1152.77, "boworotaazaaUu pogo" },
{1155.49, "fummsbowotaazaaUu pogo" },
{1158.97, "boworotaazaaUu pogo" },
{1161.62, "fummsbowotaazaaUu pogo" },
{1164.7, "boworotaazaaUu pogiff" },
{1173.66, "fummsbowotaazaaUu pogiff" },
{1176.65, "boworotaazaaUu pogiff" },
{1179.41, "fummsbowotaazaaUu pogiff" },
{1182.76, "boworotaazaaUu pogiff" },
{1185.44, "fummsbowotaazaaUu pogiff" },
{1188.62, "boworotaazaaUu pogiff" },
{1191.36, "fummsbowotaazaaUu pogiff" },
{1194.57, "boworotaazaaUu pogiff" },
{1197.1, "fummsbowotaazaaUu pogiff" },
{1200.15, "boworotaazaaUu pogiff" },
{1202.63, "fummsbowotaazaaUu pogiff" },
};

int num_texts = sizeof timed_text / sizeof timed_text[0];

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float start_offset = timed_text[0].start;
char buffer[16];

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  delay(50);
  
  float secs = (float)millis()/1000 + start_offset;
  //Serial.println(secs);
  for (int i = 0; i < num_texts; i++) {
    if (secs >= timed_text[i].start && (i == num_texts - 1 || secs <= timed_text[i+1].start)) {
      lcd.setCursor(0, 0);
      sprintf(buffer, "%-16s", timed_text[i].text);
      lcd.print(buffer);
      
      if (strlen(timed_text[i].text) > 16) {
        // consider splitting at word boundaries
        //char * words;
        //words = strtok(timed_text[i].text, " ");
        // then add back into strings 16 chars at a time
        lcd.setCursor(0, 1);
        sprintf(buffer, "%-16s", timed_text[i].text + 16);
        lcd.print(buffer);
      } else {
        lcd.setCursor(0, 1);
        lcd.print("                ");
      }
    }
  }
}

