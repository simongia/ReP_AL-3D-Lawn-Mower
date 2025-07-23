
// Actions for the buttons pressed in the APP
// The Virtual pin numbers give the identification for the button



BLYNK_WRITE(V1) {       // Start / Stop Mowing Function / Right
  int pinValue = param.asInt();
  bool Skip = 0;                                      // needed otherwise a start stop command is given
  SerialDebug.println(pinValue);
  if (pinValue == 1) {  
    
    if ((Mower_Parked == 1) && (Automatic_Mode == 1))     {  
      StartMower();  
      Skip = 1;
      delay(100); 
      }
    if (((Mower_Running == 1) || (Tracking_Wire == 1)) && (Skip == 0)) {
      Pause_Mower();
      delay(100);   
      }
    if (Mower_Docked == 1) {
      SerialDebug.println("Mower Docked");
      }   
    if (Manuel_Mode == 1) {   
      SerialDebug.println("Right");
      transmit_blynk_code = 10;  //+10 added to the code TX
      Transmit_Blynk_Data_to_Mega();
      delay(200);    
      }
    if (Mower_Setup_Mode == 1) {       
      Set_ON_OFF_Setup_Status();
      }     
    }

  }


BLYNK_WRITE(V2) {     // Exit Dock Function / FWD / UP
  int pinValue = param.asInt(); 
  SerialDebug.println(pinValue);
  if (pinValue == 1) {

    if (Mower_Docked == 1) {
      lcd_upper.print(0,0,"--EXIT--");
      Exit_Dock();
      delay(1000);
      }
    if (Manuel_Mode == 1) {    
      SerialDebug.println("Forward");
      transmit_blynk_code = 7;  //+10 added to the code TX
      Transmit_Blynk_Data_to_Mega();
      delay(200);     
      }
    if (Mower_Setup_Mode == 1) {       
      LCD_Scroll_Menu = LCD_Scroll_Menu - 1;   
      if (LCD_Scroll_Menu < 1) LCD_Scroll_Menu = Max_Options;
      SerialDebug.print(F("LCD_Scroll_Menu:"));
      SerialDebug.println(LCD_Scroll_Menu);
      delay(50);
      }  
   }

}



BLYNK_WRITE(V3) {      // Go to Docking Station / Left / OFF
  int pinValue = param.asInt(); 
  SerialDebug.println(pinValue);
  if (pinValue == 1) {

    if ( ((Mower_Running == 1) || (Mower_Parked == 1)) && (Automatic_Mode == 1))    {
      Going_Home();
      delay(100);
      }
    
   if (Manuel_Mode == 1) {    
        SerialDebug.println("Left");
        transmit_blynk_code = 9;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        delay(200);     
        }

   if (Mower_Docked == 1) {
      SerialDebug.println("Mower Already Docked");
      }   
      
      }
  }




BLYNK_WRITE(V4) {      // Execute / Down / Back
  int pinValue = param.asInt(); 
  SerialDebug.println(pinValue);
  if (pinValue == 1) {
   

   if (Manuel_Mode == 1) {    
        SerialDebug.println("Backwards");
        transmit_blynk_code = 8;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        delay(200);     
        } 
         
    
    if (Mower_Setup_Mode == 1) {
        LCD_Scroll_Menu = LCD_Scroll_Menu + 1; 
        if (LCD_Scroll_Menu > Max_Options) LCD_Scroll_Menu = 1;
        SerialDebug.print(F("LCD_Scroll_Menu:"));
        SerialDebug.println(LCD_Scroll_Menu);
        delay(50); 
        }
    
    if (Mower_Parked == 1) {
        SerialDebug.println("Set to Docked");
        transmit_blynk_code = 192;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        delay(200);    
        }
    
    }
 }



//  Mode Slider
BLYNK_WRITE(V7) {
  switch (param.asInt())  
  {
    case 1: { // Item 1
        SerialDebug.println("Automatic Mode");
        Manuel_Mode = 0;
        Automatic_Mode = 1;
        Mower_Setup_Mode = 0;
        Mower_Parked = 1;
        Mower_Docked = 0;
        Mower_Running = 0;  
        Set_To_AUTO_Mode();
        break;
        }
    
    case 2: { // Item 2
        SerialDebug.println("Manuel Mode");
        Manuel_Mode = 1;
        Tracking_Wire = 0;
        Automatic_Mode = 0;
        Mower_Setup_Mode = 0;
        Mower_Parked = 1;
        Mower_Docked = 0;
        Mower_Running = 0; 
        Set_To_Manuel_Mode();
        break;
        }
    case 3: { // Item 3
        SerialDebug.println("Setup Mode");
        Manuel_Mode = 0;
        Tracking_Wire = 0;
        Automatic_Mode = 0;
        Mower_Setup_Mode = 1;
        Mower_Parked = 0;
        Mower_Docked = 0;
        Mower_Running = 0;  
        LCD_Scroll_Menu = 1;
        SerialDebug.println("");
        SerialDebug.println("Blade OFF");
        Blade_ON = false;
        transmit_blynk_code = 190;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Set_To_Setup_Mode();
        break;
        }
    }
  SerialDebug.println("Clearing LCD's");
  lcd_upper.clear();
  delay(100);
  lcd_lower.clear();
  delay(100);
  SerialDebug.println("LCD Cleared");
 }


// Pattern Slider
BLYNK_WRITE(V8) {
  switch (param.asInt())
  {
    case 1: { // Item 1
        if ((Manuel_Mode != 1) && (Mower_Setup_Mode !=1)) {
          Pattern_Mow = 1;
          Manuel_Mode = 0;        
          Set_To_Automatic_Mode_Random();
          }
        if (Manuel_Mode == 1) {
          SerialDebug.println("");
          SerialDebug.println("Blade OFF");
          Blade_ON = false;
          transmit_blynk_code = 190;  //+10 added to the code TX
          Transmit_Blynk_Data_to_Mega();
          }
        break;
      }
    case 2: { // Item 2
        if ((Manuel_Mode != 1) && (Mower_Setup_Mode !=1)) {
          Manuel_Mode = 0;
          Pattern_Mow = 2;
          Set_To_Automatic_Mode_Parallel();
          }
        if (Manuel_Mode == 1) {
          SerialDebug.println("");
          SerialDebug.println("Blade OFF");
          Blade_ON = false;
          transmit_blynk_code = 190;  //+10 added to the code TX
          Transmit_Blynk_Data_to_Mega();
          }
        break;
        }
    
    case 3: { // Item 3              
        if ((Manuel_Mode != 1) && (Mower_Setup_Mode !=1)) {
          Manuel_Mode = 0;
          Pattern_Mow = 3;
          Set_To_Automatic_Mode_Spiral();
          }
        if (Manuel_Mode == 1) {
          SerialDebug.println("");
          SerialDebug.println("Blade ON");
          Blade_ON = true;
          transmit_blynk_code = 191;  //+10 added to the code TX
          Transmit_Blynk_Data_to_Mega();
          }
        break;
        }

    
      }
   
}



BLYNK_WRITE(V27)  {                      
  int pinValue = param.asInt();
  if (pinValue == 1) {
  
  if (Manuel_Mode == 1) {                // Check its in Manuel Mode.

        transmit_blynk_code = 46;  //+10 added to the code TX means 56 on the MEGA
        Transmit_Blynk_Data_to_Mega();
        Blynk.virtualWrite(V1, HIGH);           // Docking Button ON
        Blynk.virtualWrite(V11, 0);
        Automatic_Mode = 1;
        Manuel_Mode = 0;
        Blynk.virtualWrite(V27, 0);       // Go To Dock Button
        Blynk.virtualWrite(V4, 1023);       // Go To Dock Button
        } 
    }
  }


BLYNK_WRITE(V65)   {                    // Drill Hole
  int pinValue = param.asInt(); // assigning incoming value from pin V10 to a variable
    if (pinValue == 1) {
    SerialDebug.println("");
    SerialDebug.println("Drill Activated");
    transmit_blynk_code = 65;  //+10 added to the code TX
    Transmit_Blynk_Data_to_Mega();
    }

  }



// Reset Mower MEGA
BLYNK_WRITE(V51)      {                  
      SerialDebug.print("|MEGA ERROR");
      digitalWrite(D5, HIGH); 
      digitalWrite(D5, LOW); 
      delay(1000);
      digitalWrite(D5, HIGH); 
      delay(2000);
      Total_Error = 0;
      Error_Loop = 0;
      Error_Volt = 0;
      }
