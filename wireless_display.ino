#include <LiquidCrystal.h>

LiquidCrystal lcd (4, 5, 6, 7, 8, 9);

int i = 15;
String msg;
String oldmsg;
String newmsg;

void setup() 
{
  lcd.begin(16,2);
  Serial.begin(9600);

}

void loop() 
{

     if(Serial.available()!=0)
  {
  msg = Serial.readString();
  msg.trim();
  Serial.println(msg);
  if(msg != oldmsg)
  {
    newmsg = msg;
  }
  lcd.clear();
  lcd.setCursor(i, 1);
  lcd.print(newmsg);
  i--;
  if(i<=0 )
  {
    i = 15;
  }
  msg = oldmsg;
  }
     else
    {
    lcd.setCursor(0, 0);
  lcd.print("Wireless Notice");
  lcd.setCursor(0, 1);
  lcd.print("     Board     ");
  delay(2000);
  lcd.clear();
    }
}
