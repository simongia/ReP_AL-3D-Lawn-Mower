// Routine to check the bumper Switch
// The global variable Bump is then activated so the Mower can react to the bumper being activated

void Check_Bumper() {

if (Bumper_Activate_Frnt == true) {

  if (digitalRead(Microswitch_2))   Bump_Frnt_LH = false;    // The switch is not activated the variable Bump is false
  if (!digitalRead(Microswitch_2))  Bump_Frnt_LH = true;     // The switch is activated the variable Bump is true
  
  if (digitalRead(Microswitch_1))   Bump_Frnt_RH = false;    // The switch is not activated the variable Bump is false
  if (!digitalRead(Microswitch_1))  Bump_Frnt_RH = true;     // The switch is activated the variable Bump is true
  
  if ((Bump_Frnt_LH == false) && (Bump_Frnt_RH == false))  Bumper = false;
  
  if ((Bump_Frnt_LH == true ) || (Bump_Frnt_RH == true) )  {
    Bumper = true;
    Motor_Action_Stop_Motors();
    
    #if defined(LCD_KEYPAD)
    lcd.clear();
    lcd.print("BUMPER");
    lcd.setCursor(0,1);
    lcd.print("ACTIVATED");
    delay(1000);
    lcd.clear();
    #endif
  }

  }


}




void Start_Bumper_Bar_Test() {
        #if defined(LCD_KEYPAD)
        Setup_Microswitches();
        Menu_Complete = false;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("LH Bar: ");
          lcd.setCursor(0,1);
          lcd.print("RH Bar: ");

        while (Menu_Complete == false) {
          Read_Membrane_Keys();                                               // Check if a button has been pressed
          lcd.setCursor(8,0);
          if (digitalRead(Microswitch_2))   lcd.print("        ");        // Check if the LH microswitch is not activated
          if (!digitalRead(Microswitch_2))  lcd.print("BUMP    ");        // Check if the LH microswitch is activated
        
          lcd.setCursor(8,1);
          if (digitalRead(Microswitch_1))   lcd.print("        ");        // Check if the RH microswitch is not activated
          if (!digitalRead(Microswitch_1))  lcd.print("BUMP    ");        // Check if the RH microswitch is activated        

             // Cancel the test by pressing the Stop key
             if(!Stop_Key_X){
              Menu_Complete = true;
              lcd.clear();
              lcd.print("Stop Test");
              delay(2000);
              lcd.clear();
              }
           }
  #endif
  
}
