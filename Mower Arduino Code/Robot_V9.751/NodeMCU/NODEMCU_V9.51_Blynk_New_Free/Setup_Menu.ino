

void Print_LCD_Setup_Scroll() {

// can I use the widget function of Blank to say upper or lower?

    int ON_OFF_Position = 13;
    
  
    //Print Cursor
    X_Print = 0;
    Y_Print = 1;   
    lcd_upper.print(X_Print,Y_Print,">");
    
    //Print Line 1
    X_Print = 1;
    Y_Print = 1;
    Print_LCD_List_Upper(LCD_Scroll_Menu);
    X_Print = ON_OFF_Position;
    Y_Print = 1; 
    Define_ON_OFF_Status_of_Setting_Upper(LCD_Scroll_Menu);       
    
    X_Print = 1;
    Y_Print = 0;
    Print_LCD_List_Lower(LCD_Scroll_Menu + 1);
    X_Print = ON_OFF_Position;
    Y_Print = 0;
    Define_ON_OFF_Status_of_Setting_lower(LCD_Scroll_Menu + 1);
    
    X_Print = 1;
    Y_Print = 1; 
    Print_LCD_List_Lower(LCD_Scroll_Menu + 2);   
    X_Print = ON_OFF_Position;
    Y_Print = 1;
    Define_ON_OFF_Status_of_Setting_lower(LCD_Scroll_Menu + 2);   
 
}



void Print_LCD_List_Upper (byte LCD_Scroll_Menu) {     
 
     if (LCD_Scroll_Menu == 1)  lcd_upper.print(X_Print,Y_Print,"1  FPV CAM :");
     if (LCD_Scroll_Menu == 2)  lcd_upper.print(X_Print,Y_Print,"2  Alarm 1 :");
     if (LCD_Scroll_Menu == 3)  lcd_upper.print(X_Print,Y_Print,"3  Alarm 2 :");
     if (LCD_Scroll_Menu == 4)  lcd_upper.print(X_Print,Y_Print,"4  Alarm 3 :");  
     if (LCD_Scroll_Menu == 5)  lcd_upper.print(X_Print,Y_Print,"5  Compass :");
     if (LCD_Scroll_Menu == 6)  lcd_upper.print(X_Print,Y_Print,"6  HeadHold:");   
     if (LCD_Scroll_Menu == 7)  lcd_upper.print(X_Print,Y_Print,"7  GYRO    :");
     if (LCD_Scroll_Menu == 8)  lcd_upper.print(X_Print,Y_Print,"8  Sonar1  :");   
     if (LCD_Scroll_Menu == 9)  lcd_upper.print(X_Print,Y_Print,"9  Sonar2  :");
     if (LCD_Scroll_Menu == 10) lcd_upper.print(X_Print,Y_Print,"10 Sonar3  :");   
     if (LCD_Scroll_Menu == 11) lcd_upper.print(X_Print,Y_Print,"11 Bumper  :");   
     
     if (LCD_Scroll_Menu == 12) lcd_upper.print(X_Print,Y_Print,"12 GPS     :");
     if (LCD_Scroll_Menu == 13) lcd_upper.print(X_Print,Y_Print,"13 Angle Se:");
     if (LCD_Scroll_Menu == 14) lcd_upper.print(X_Print,Y_Print,"14 Tip Sen :");
     if (LCD_Scroll_Menu == 15) lcd_upper.print(X_Print,Y_Print,"15 WheelAMP:");
     if (LCD_Scroll_Menu == 16) lcd_upper.print(X_Print,Y_Print,"16 Wheel ON:");
     if (LCD_Scroll_Menu == 17) lcd_upper.print(X_Print,Y_Print,"17 W Ramps :");
     if (LCD_Scroll_Menu == 18) lcd_upper.print(X_Print,Y_Print,"18 MAGSpeed:");
     if (LCD_Scroll_Menu == 19) lcd_upper.print(X_Print,Y_Print,"19 WireActi:");
     if (LCD_Scroll_Menu == 20) lcd_upper.print(X_Print,Y_Print,"20 Docking :");
     if (LCD_Scroll_Menu == 21) lcd_upper.print(X_Print,Y_Print,"21         :");
     if (LCD_Scroll_Menu == 22) lcd_upper.print(X_Print,Y_Print,"22         :");
     if (LCD_Scroll_Menu == 23) lcd_upper.print(X_Print,Y_Print,"23         :");
     if (LCD_Scroll_Menu == 24) lcd_upper.print(X_Print,Y_Print,"24         :");
     if (LCD_Scroll_Menu == 25) lcd_upper.print(X_Print,Y_Print,"25         :");
     if (LCD_Scroll_Menu == 26) lcd_upper.print(X_Print,Y_Print,"26         :");
     
     }




void Print_LCD_List_Lower (byte LCD_Scroll_Menu) {     
 
     if (LCD_Scroll_Menu == 1)  lcd_lower.print(X_Print,Y_Print,"1  FPV CAM :");
     if (LCD_Scroll_Menu == 2)  lcd_lower.print(X_Print,Y_Print,"2  Alarm 1 :");
     if (LCD_Scroll_Menu == 3)  lcd_lower.print(X_Print,Y_Print,"3  Alarm 2 :");
     if (LCD_Scroll_Menu == 4)  lcd_lower.print(X_Print,Y_Print,"4  Alarm 3 :");  
     if (LCD_Scroll_Menu == 5)  lcd_lower.print(X_Print,Y_Print,"5  Compass :");
     if (LCD_Scroll_Menu == 6)  lcd_lower.print(X_Print,Y_Print,"6  HeadHold:");   
     if (LCD_Scroll_Menu == 7)  lcd_lower.print(X_Print,Y_Print,"7  GYRO    :");
     if (LCD_Scroll_Menu == 8)  lcd_lower.print(X_Print,Y_Print,"8  Sonar1  :");   
     if (LCD_Scroll_Menu == 9)  lcd_lower.print(X_Print,Y_Print,"9  Sonar2  :");
     if (LCD_Scroll_Menu == 10) lcd_lower.print(X_Print,Y_Print,"10 Sonar3  :");   
     if (LCD_Scroll_Menu == 11) lcd_lower.print(X_Print,Y_Print,"11 Bumper  :");   
     
     if (LCD_Scroll_Menu == 12) lcd_lower.print(X_Print,Y_Print,"12 GPS     :");
     if (LCD_Scroll_Menu == 13) lcd_lower.print(X_Print,Y_Print,"13 Angle Se:");
     if (LCD_Scroll_Menu == 14) lcd_lower.print(X_Print,Y_Print,"14 Tip Sen :");
     if (LCD_Scroll_Menu == 15) lcd_lower.print(X_Print,Y_Print,"15 WheelAmp:");
     if (LCD_Scroll_Menu == 16) lcd_lower.print(X_Print,Y_Print,"16 Wheel ON:");
     if (LCD_Scroll_Menu == 17) lcd_lower.print(X_Print,Y_Print,"17 W-Ramps :");
     if (LCD_Scroll_Menu == 18) lcd_lower.print(X_Print,Y_Print,"18 MAGSpeed:");
     if (LCD_Scroll_Menu == 19) lcd_lower.print(X_Print,Y_Print,"19 WireActi:");
     if (LCD_Scroll_Menu == 20) lcd_lower.print(X_Print,Y_Print,"20 Docking :");
     if (LCD_Scroll_Menu == 21) lcd_lower.print(X_Print,Y_Print,"21         :");
     if (LCD_Scroll_Menu == 22) lcd_lower.print(X_Print,Y_Print,"22         :");
     if (LCD_Scroll_Menu == 23) lcd_lower.print(X_Print,Y_Print,"23         :");
     if (LCD_Scroll_Menu == 24) lcd_lower.print(X_Print,Y_Print,"24         :");
     if (LCD_Scroll_Menu == 25) lcd_lower.print(X_Print,Y_Print,"25         :");
     if (LCD_Scroll_Menu == 26) lcd_lower.print(X_Print,Y_Print,"26         :");
     }
  




void Define_ON_OFF_Status_of_Setting_Upper(byte LCD_Scroll_Menu) {
  
    if (LCD_Scroll_Menu == 1)  {
      if (FPV_CAM_Status == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (FPV_CAM_Status == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
    }      
    if (LCD_Scroll_Menu == 2)  {
      if (Alarm_1_ON == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (Alarm_1_ON == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
    }
    if (LCD_Scroll_Menu == 3)  {
      if (Alarm_2_ON == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (Alarm_2_ON == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
    }
    if (LCD_Scroll_Menu == 4)  {
      if (Alarm_3_ON == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (Alarm_3_ON == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
    }
    if (LCD_Scroll_Menu == 5)  {
      if (Compass_Activate == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (Compass_Activate == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
    }
    if (LCD_Scroll_Menu == 6)  {
      if (Compass_Heading_Hold_Enabled == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (Compass_Heading_Hold_Enabled == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
    }
    if (LCD_Scroll_Menu == 7)  {
      if (GYRO_Enabled == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (GYRO_Enabled == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
    }
    if (LCD_Scroll_Menu == 8)  {
      if (SONAR_1_Activate == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (SONAR_1_Activate == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 9)  {
      if (SONAR_2_Activate == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (SONAR_2_Activate == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
      }  
    if (LCD_Scroll_Menu == 10)  {
      if (SONAR_3_Activate == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (SONAR_3_Activate == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 11)  {
      if (Bumper_Activate_Frnt == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (Bumper_Activate_Frnt == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
      }


    if (LCD_Scroll_Menu == 12)  {
      if (GPS_Enabled == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (GPS_Enabled == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 13)  {
      if (Angle_Sensor_Enabled  == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (Angle_Sensor_Enabled  == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 14)  {
      if (Tip_Over_Sensor_Enabled  == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (Tip_Over_Sensor_Enabled  == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 15)  {
      if (Wheel_Amp_Sensor_ON   == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (Wheel_Amp_Sensor_ON   == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 16)  {
      if (Wheels_Activate   == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (Wheels_Activate   == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 17)  {
      if (Ramp_Motor_ON   == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (Ramp_Motor_ON   == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 18)  {
      if (MAG_Speed_Adjustment   == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (MAG_Speed_Adjustment   == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 19)  {
      if (Perimeter_Wire_Enabled   == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (Perimeter_Wire_Enabled   == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 20)  {
      if (Use_Charging_Station    == 1) lcd_upper.print(X_Print,Y_Print,"ON "); 
      if (Use_Charging_Station    == 0) lcd_upper.print(X_Print,Y_Print,"OFF"); 
      }

}


void Define_ON_OFF_Status_of_Setting_lower(byte LCD_Scroll_Menu) {
  
    if (LCD_Scroll_Menu == 1)  {
      if (FPV_CAM_Status == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (FPV_CAM_Status == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
    }      
    if (LCD_Scroll_Menu == 2)  {
      if (Alarm_1_ON == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (Alarm_1_ON == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
    }
    if (LCD_Scroll_Menu == 3)  {
      if (Alarm_2_ON == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (Alarm_2_ON == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
    }
    if (LCD_Scroll_Menu == 4)  {
      if (Alarm_3_ON == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (Alarm_3_ON == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
    }
    if (LCD_Scroll_Menu == 5)  {
      if (Compass_Activate == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (Compass_Activate == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
    }
    if (LCD_Scroll_Menu == 6)  {
      if (Compass_Heading_Hold_Enabled == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (Compass_Heading_Hold_Enabled == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
    }
    if (LCD_Scroll_Menu == 7)  {
      if (GYRO_Enabled == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (GYRO_Enabled == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
    }
    if (LCD_Scroll_Menu == 8)  {
      if (SONAR_1_Activate == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (SONAR_1_Activate == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
    }
    if (LCD_Scroll_Menu == 9)  {
      if (SONAR_2_Activate == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (SONAR_2_Activate == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
    }  
    if (LCD_Scroll_Menu == 10)  {
      if (SONAR_3_Activate == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (SONAR_3_Activate == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
    }
    if (LCD_Scroll_Menu == 11)  {
      if (Bumper_Activate_Frnt == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (Bumper_Activate_Frnt == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
    }

    if (LCD_Scroll_Menu == 12)  {
      if (GPS_Enabled == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (GPS_Enabled == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 13)  {
      if (Angle_Sensor_Enabled  == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (Angle_Sensor_Enabled  == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 14)  {
      if (Tip_Over_Sensor_Enabled  == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (Tip_Over_Sensor_Enabled  == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 15)  {
      if (Wheel_Amp_Sensor_ON   == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (Wheel_Amp_Sensor_ON   == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 16)  {
      if (Wheels_Activate   == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (Wheels_Activate   == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 17)  {
      if (Ramp_Motor_ON   == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (Ramp_Motor_ON   == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 18)  {
      if (MAG_Speed_Adjustment   == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (MAG_Speed_Adjustment   == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 19)  {
      if (Perimeter_Wire_Enabled   == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (Perimeter_Wire_Enabled   == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
      }
    if (LCD_Scroll_Menu == 20)  {
      if (Use_Charging_Station    == 1) lcd_lower.print(X_Print,Y_Print,"ON "); 
      if (Use_Charging_Station    == 0) lcd_lower.print(X_Print,Y_Print,"OFF"); 
      }


}


void Set_ON_OFF_Setup_Status() {

    bool skip = 0;
    
    if (LCD_Scroll_Menu == 1)  {
      if (FPV_CAM_Status == 1) {
        SerialDebug.println("CAM OFF");
        FPV_CAM_Status = 0;
        digitalWrite(D6, LOW);
        delay(100);
        skip = 1;
        }
      if ((FPV_CAM_Status == 0) && (skip == 0)) {
        SerialDebug.println("CAM ON");
        FPV_CAM_Status = 1;
        digitalWrite(D6, HIGH);
        }
      }   


    if (LCD_Scroll_Menu == 2)  {
      if (Alarm_1_ON == 1) {
        SerialDebug.println(F("Alarm 1 OFF"));
        transmit_blynk_code = 48;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Alarm_1_ON = 0;
        skip = 1;
        }
      if ((Alarm_1_ON == 0) && (skip == 0)) {
        SerialDebug.println(F("Alarm 1 ON"));
        transmit_blynk_code = 47; //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Alarm_1_ON = 1;
        }
      } 


    if (LCD_Scroll_Menu == 3)  {
      if (Alarm_2_ON == 1) {
        SerialDebug.println(F("Alarm 2 OFF"));
        transmit_blynk_code = 50;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Alarm_2_ON = 0;
        skip = 1;
        }
      if ((Alarm_2_ON == 0) && (skip == 0)) {
        SerialDebug.println(F("Alarm 2 ON"));
        transmit_blynk_code = 49; //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Alarm_2_ON = 1;
        }
      } 


    if (LCD_Scroll_Menu == 4)  {
      if (Alarm_3_ON == 1) {
        SerialDebug.println(F("Alarm 3 OFF"));
        transmit_blynk_code = 52;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Alarm_3_ON = 0;
        skip = 1;
        }
      if ((Alarm_3_ON == 0) && (skip == 0)) {
        SerialDebug.println(F("Alarm 3 ON"));
        transmit_blynk_code = 51; //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Alarm_3_ON = 1;
        }
      } 



    if (LCD_Scroll_Menu == 5)  {
      if (Compass_Activate == 1) {
        SerialDebug.println(F("Compass OFF"));
        transmit_blynk_code = 31;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Compass_Activate = 0;
        skip = 1;
        }
      if ((Compass_Activate == 0) && (skip == 0)) {
        SerialDebug.println(F("Compass ON"));
        transmit_blynk_code = 30;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Compass_Activate = 1;
        }
      } 

    if (LCD_Scroll_Menu == 6)  {
      if (Compass_Heading_Hold_Enabled == 1) {
        SerialDebug.println(F("Compass Heading Hold OFF"));
        transmit_blynk_code = 33;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Compass_Heading_Hold_Enabled = 0;
        skip = 1;
        }
      if ((Compass_Heading_Hold_Enabled == 0) && (skip == 0)) {
        SerialDebug.println(F("Compass Heading Hold ON"));
        transmit_blynk_code = 32;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Compass_Heading_Hold_Enabled = 1;
        }
      } 

    if (LCD_Scroll_Menu == 7)  {
      if (GYRO_Enabled == 1) {
        SerialDebug.println(F("GYRO OFF"));
        transmit_blynk_code = 35;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        GYRO_Enabled = 0;
        skip = 1;
        }
      if ((GYRO_Enabled == 0) && (skip == 0)) {
        SerialDebug.println(F("GYRO ON"));
        transmit_blynk_code = 34;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        GYRO_Enabled = 1;
        }
      } 


    if (LCD_Scroll_Menu == 8)  {
      if (SONAR_1_Activate == 1) {
        SerialDebug.println(F("SONAR 1 OFF"));
        transmit_blynk_code = 38;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        SONAR_1_Activate = 0;
        skip = 1;
        }
      if ((SONAR_1_Activate == 0) && (skip == 0)) {
        SerialDebug.println(F("SONAR 1 ON"));
        transmit_blynk_code = 37;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        SONAR_1_Activate = 1;
        }
      } 

    if (LCD_Scroll_Menu == 9)  {
      if (SONAR_2_Activate == 1) {
        SerialDebug.println(F("SONAR 2 OFF"));
        transmit_blynk_code = 40;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        SONAR_2_Activate = 0;
        skip = 1;
        }
      if ((SONAR_1_Activate == 0) && (skip == 0)) {
        SerialDebug.println(F("SONAR 2 ON"));
        transmit_blynk_code = 39;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        SONAR_2_Activate = 1;
        }
      } 

    if (LCD_Scroll_Menu == 10)  {
      if (SONAR_3_Activate == 1) {
        SerialDebug.println(F("SONAR 3 OFF"));
        transmit_blynk_code = 42;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        SONAR_3_Activate = 0;
        skip = 1;
        }
      if ((SONAR_3_Activate == 0) && (skip == 0)) {
        SerialDebug.println(F("SONAR 3 ON"));
        transmit_blynk_code = 41;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        SONAR_3_Activate = 1;
        }
      } 



    if (LCD_Scroll_Menu == 11)  {
      if (Bumper_Activate_Frnt == 1) {
        SerialDebug.println(F("Bumper OFF"));
        transmit_blynk_code = 44;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Bumper_Activate_Frnt = 0;
        skip = 1;
        }
      if ((Bumper_Activate_Frnt == 0) && (skip == 0)) {
        SerialDebug.println(F("Bumper ON"));
        transmit_blynk_code = 43;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Bumper_Activate_Frnt = 1;
        }
      } 

    if (LCD_Scroll_Menu == 12)  {
      if (GPS_Enabled == 1) {
        SerialDebug.println(F("GPS OFF"));
        transmit_blynk_code = 56;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        GPS_Enabled = 0;
        skip = 1;
        }
      if ((GPS_Enabled == 0) && (skip == 0)) {
        SerialDebug.println(F("GPS ON"));
        transmit_blynk_code = 55;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        GPS_Enabled = 1;
        }
      } 

    if (LCD_Scroll_Menu == 13)  {
      if (Angle_Sensor_Enabled == 1) {
        SerialDebug.println(F("Angle Sensor OFF"));
        transmit_blynk_code = 58;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Angle_Sensor_Enabled = 0;
        skip = 1;
        }
      if ((Angle_Sensor_Enabled  == 0) && (skip == 0)) {
        SerialDebug.println(F("Angle Sensor ON"));
        transmit_blynk_code = 57;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Angle_Sensor_Enabled  = 1;
        }
      } 

    if (LCD_Scroll_Menu == 14)  {
      if (Tip_Over_Sensor_Enabled == 1) {
        SerialDebug.println(F("Tip Over Sensor OFF"));
        transmit_blynk_code = 60;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Tip_Over_Sensor_Enabled = 0;
        skip = 1;
        }
      if ((Tip_Over_Sensor_Enabled  == 0) && (skip == 0)) {
        SerialDebug.println(F("Tip Over Sensor ON"));
        transmit_blynk_code = 59;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Tip_Over_Sensor_Enabled  = 1;
        }
      } 

    if (LCD_Scroll_Menu == 15)  {
      if (Wheel_Amp_Sensor_ON == 1) {
        SerialDebug.println(F("Wheel Amp Sensor OFF"));
        transmit_blynk_code = 62;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Wheel_Amp_Sensor_ON = 0;
        skip = 1;
        }
      if ((Wheel_Amp_Sensor_ON  == 0) && (skip == 0)) {
        SerialDebug.println(F("Wheel Amp Sensor ON"));
        transmit_blynk_code = 61;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Wheel_Amp_Sensor_ON  = 1;
        }
      }       

    if (LCD_Scroll_Menu == 16)  {
      if (Wheels_Activate == 1) {
        SerialDebug.println(F("Wheel Motor Activate OFF"));
        transmit_blynk_code = 92;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Wheels_Activate = 0;
        skip = 1;
        }
      if ((Wheels_Activate  == 0) && (skip == 0)) {
        SerialDebug.println(F("Wheel Motor Activate ON"));
        transmit_blynk_code = 91;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Wheels_Activate  = 1;
        }
      }  
     
    if (LCD_Scroll_Menu == 17)  {
      if (Ramp_Motor_ON == 1) {
        SerialDebug.println(F("Wheel Ramps OFF"));
        transmit_blynk_code = 94;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Ramp_Motor_ON = 0;
        skip = 1;
        }
      if ((Ramp_Motor_ON  == 0) && (skip == 0)) {
        SerialDebug.println(F("Wheel Ramps ON"));
        transmit_blynk_code = 93;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Ramp_Motor_ON  = 1;
        }
      }       
     
     
    if (LCD_Scroll_Menu == 18)  {
      if (MAG_Speed_Adjustment == 1) {
        SerialDebug.println(F("MAG Speed OFF"));
        transmit_blynk_code = 96;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        MAG_Speed_Adjustment = 0;
        skip = 1;
        }
      if ((MAG_Speed_Adjustment  == 0) && (skip == 0)) {
        SerialDebug.println(F("MAG Speed ON"));
        transmit_blynk_code = 95;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        MAG_Speed_Adjustment  = 1;
        }
      }   


    if (LCD_Scroll_Menu == 19)  {
      if (Perimeter_Wire_Enabled == 1) {
        SerialDebug.println(F("Perimeter Wire OFF"));
        transmit_blynk_code = 98;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Perimeter_Wire_Enabled = 0;
        skip = 1;
        }
      if ((Perimeter_Wire_Enabled  == 0) && (skip == 0)) {
        SerialDebug.println(F("Perimeter Wire ON"));
        transmit_blynk_code = 97;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Perimeter_Wire_Enabled  = 1;
        }
      } 


    if (LCD_Scroll_Menu == 20)  {
      if (Use_Charging_Station == 1) {
        SerialDebug.println(F("Docking OFF"));
        transmit_blynk_code = 100;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Use_Charging_Station = 0;
        skip = 1;
        }
      if ((Use_Charging_Station  == 0) && (skip == 0)) {
        SerialDebug.println(F("Docking ON"));
        transmit_blynk_code = 99;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Use_Charging_Station  = 1;
        }
      } 

  
  
  delay(1000);  // Allow changes to take effect
  }
