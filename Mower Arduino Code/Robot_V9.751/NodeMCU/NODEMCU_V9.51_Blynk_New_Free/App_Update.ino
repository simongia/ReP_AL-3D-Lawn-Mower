void Update_Blynk_App_With_Status() {
   
   SerialDebug.print("APP Update..");     
   
		//Blynk.virtualWrite(V1, LOW);       
		//Blynk.virtualWrite(V2, LOW);   
		//Blynk.virtualWrite(V3, LOW);     
		//Blynk.virtualWrite(V4, LOW);            

   if (Tracking_Wire == 1) lcd_upper.print(0,0,"Tracking");
   if (Mower_Running == 1) lcd_upper.print(0,0,"-Mowing-");
   if (Mower_Parked == 1)  lcd_upper.print(0,0,"-Parked-");
   if (Mower_Docked == 1)  lcd_upper.print(0,0,"-Docked-");
      
    
    if ((Mower_Docked == 1) && (Automatic_Mode == 1)) {
      Blynk.setProperty(V1, "label", ".");
      Blynk.setProperty(V2, "label", "Exit Dock");
      Blynk.setProperty(V3, "label", ".");
      Blynk.setProperty(V4, "label", ".");
   
      Blynk.setProperty(V7, "label", Mode_Slider_Mower);
      Blynk.setProperty(V8, "label", Mode_Slider_Pattern);
      }

    if ((Tracking_Wire == 1) && (Automatic_Mode == 1)) {
      Blynk.setProperty(V1, "label", "Stop");
      Blynk.setProperty(V2, "label", ".");
      Blynk.setProperty(V3, "label", "Goto Dock");
      Blynk.setProperty(V4, "label", ".");
      Blynk.setProperty(V7, "label", Mode_Slider_Mower);
      Blynk.setProperty(V8, "label", Mode_Slider_Pattern);
      }

    if ((Mower_Parked == 1) && (Automatic_Mode == 1)) {
      Blynk.setProperty(V1, "label", "Start");
      Blynk.setProperty(V2, "label", ".");
      Blynk.setProperty(V3, "label", "Goto Dock");
      Blynk.setProperty(V4, "label", "Set as Docked");
      Blynk.setProperty(V7, "label", Mode_Slider_Mower);
      Blynk.setProperty(V8, "label", Mode_Slider_Pattern);

      }

    if (Mower_Running == 1) {
      Blynk.setProperty(V1, "label", "STOP");
      Blynk.setProperty(V2, "label", ".");
      Blynk.setProperty(V3, "label", "Goto Dock");
      Blynk.setProperty(V4, "label", ".");
      Blynk.setProperty(V7, "label", Mode_Slider_Mower);
      Blynk.setProperty(V8, "label", Mode_Slider_Pattern);
      }
    
    if (Manuel_Mode == 1) {
      Blynk.setProperty(V1, "label", "Right");
      Blynk.setProperty(V2, "label", "FWD");
      Blynk.setProperty(V3, "label", "Left");
      Blynk.setProperty(V4, "label", "REV");

      lcd_upper.print(0,1, "Manual");
      Blynk.virtualWrite(V7, 2);
      Blynk.setProperty(V7, "label", Mode_Slider_Mower);
      Blynk.setProperty(V8, "label", Mode_Slider_Blade);
      if (Blade_ON == false) {
        Blynk.virtualWrite(V8, 1);
        lcd_lower.print(5,0, " BLADE OFF ");
        }
      if (Blade_ON == true) lcd_lower.print(5,0, "!BLADE ON! ");
      }    
    
    if ((Mower_Setup_Mode == 1) && (Mower_Docked != 1)) {
      Blynk.setProperty(V1, "label", "On/Off");
      Blynk.setProperty(V2, "label", "Scroll Up");
      Blynk.setProperty(V3, "label", ".");
      Blynk.setProperty(V4, "label", "Scroll Down");
      Blynk.setProperty(V7, "label", Mode_Slider_Mower);
      lcd_upper.print(0,0, "Setup Mode");
      Blynk.virtualWrite(V7, 3);
      Print_LCD_Setup_Scroll();
      Blynk.setProperty(V8, "label", Model_Mower_Setup);
      
      }    

      
		//Mower_Docked_Filter_Last = Mower_Docked_Filter;

    if (((Mower_Docked == 1) || (Mower_Parked == 1) || (Mower_Running == 1)) && (Mower_Setup_Mode != 1) ) {
        // Update Voltage
        lcd_upper.print(9,0,"V");
        lcd_upper.print(10,0, BatteryVoltage);           
        // Update Wire Status
        if (Wire_Detected == 0) lcd_upper.print(8,1,"Wire:OFF");
        if (Wire_Detected == 1) lcd_upper.print(8,1,"Wire:ON ");
        Blynk.virtualWrite(V50, 1);
        }


    
    if ((Automatic_Mode == 1) && (Manuel_Mode != 1)) {
      lcd_upper.print(0,1, "-AUTO-");  
      Blynk.virtualWrite(V7, 1);
      if (Pattern_Mow == 1) {
        lcd_lower.print(7,0, " -RANDOM-");
        Blynk.virtualWrite(V8, 1);
      }
      if (Pattern_Mow == 2) {
        lcd_lower.print(7,0, " -Parall-");
        Blynk.virtualWrite(V8, 2);
      }
      if (Pattern_Mow == 3) {
        lcd_lower.print(7,0, " -Spiral-");
        Blynk.virtualWrite(V8, 3);
      }    
 
    if ((Loop_Cycle_Mowing > 1) && (Mower_Running == 1)) {
      lcd_lower.print(0,0,"L:");
      lcd_lower.print(2,0, Loop_Cycle_Mowing);
     }
    
    if (Mower_Running != 1) lcd_lower.print(0,0, "       ");
    
    }

    if (Mower_Setup_Mode != 1) {
        if (Charge_Detected == 4) lcd_lower.print(0,0,"Charge");
        if (Charge_Detected != 4) lcd_lower.print(0,0,"      ");
    
        if (Rain_Detected == 1) {
          lcd_lower.print(10,1,"Rain");
          }
        if (Rain_Detected == 0) {
          lcd_lower.print(10,1,"    ");
          }
    }

}
