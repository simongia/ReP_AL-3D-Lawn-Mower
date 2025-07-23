
// Transmits 7 Data Values to the TFT MEGA on Serial3 Com Port.
// The data values are declared below for the different Menu
// Commands.  This standardises the data transfer method for all
// functions.
//
// Values are transfered from the Mower MEGA to the TFT MEGA for editing in
// the TFT GUI.  The values are then sent back and stored to dueFlashStorage on the MOWER
// MEGA so the mower can carry out the instructions according to the user settings


void TX_7_Data_Values() {
      Serial.println("Sending Data Sets");
	byte data[15];
	data[0] = 18; // Packet ID

	data[1]=Data1;
	data[2]=Data1 >> 8;
	data[3]=Data2;
	data[4]=Data2 >> 8;
	data[5]=Data3;
	data[6]=Data3 >> 8;
	data[7]=Data4;
	data[8]=Data4 >> 8;
	data[9]=Data5;
	data[10]=Data5 >> 8;
	data[11]=Data6;
	data[12]=Data6 >> 8;
	data[13]=Data7;
	data[14]=Data7 >> 8;

    SerialCom3.sendMsg (data, sizeof (data));

    //Check_TX_Received_PacketNum(17);

      Serial.print(F("Data1:"));
      Serial.println(Data1);
      Serial.print(F("Data2:"));
      Serial.println(Data2);
      Serial.print(F("Data3:"));
      Serial.println(Data3);  
      Serial.print(F("Data4:"));
      Serial.println(Data4);
      Serial.print(F("Data5:"));
      Serial.println(Data5);
      Serial.print(F("Data6:"));
      Serial.println(Data6);
      Serial.print(F("Data7:"));
      Serial.println(Data7);    
      }


void Send_Data_To_TFT() {
    // Depending on the code received the following data set is sent through the Serial 3 port.
    
    // Menu Sonar
    if (TFT_Menu_Command == 10) {
      Serial.println("TX Sonar to TFT");
      Data1 = Sonar_1_Activate;
      Data2 = Sonar_2_Activate;
      Data3 = Sonar_3_Activate;
      Data4 = maxdistancesonar;
      Data5 = Max_Sonar_Hit;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();

      Serial.print(F("S1 ON = "));
      Serial.println(Sonar_1_Activate);
      Serial.print(F("S2 ON = "));
      Serial.println(Sonar_2_Activate);
      Serial.print(F("S3 ON = "));
      Serial.println(Sonar_3_Activate);
      Serial.print(F("Sonar Max Distance = "));
      Serial.println(maxdistancesonar);
      Serial.print(F("Sonar Sensitivity = "));
      Serial.println(Max_Sonar_Hit);
      Serial.println(F(" "));
      }

    
// 11 is sometimes read if a serial port miscommunication occurs therefore this
// number is not used to start communication from the MEGA:
    if (TFT_Menu_Command == 11) {
      Serial.println("False Command");      
      }


// Navigation Menu is selected on the TFT
    if (TFT_Menu_Command == 9) {
      Serial.println("TX Nav to TFT");
      
      Serial3.print(GPS_Enabled);
      Serial3.println("\a");
      delay(200);  

      Serial.print(F("GPS Enabled = "));
      Serial.println(GPS_Enabled);   
      }


// Battery Menu is selected on the TFT
    if (TFT_Menu_Command == 26) {
      Serial.println("TX Battery to TFT");
      float Temp = Battery_Min * 10;          // Create Temp float value to transfer the decimal to the int
      int Temp2 = Temp;
      Data1 = Temp2;
      Data2 = Low_Battery_Instances_Chg;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();
      Serial.print(F("Battery Min = "));
      Serial.println(Battery_Min);
      Serial.print(F("Battery Sensitivity = "));
      Serial.println(Low_Battery_Instances_Chg);
      Serial.println(" ");
      }

// Setup Other Menu is selected on the TFT
    if (TFT_Menu_Command == 30) {
      Serial.println("Setup Other");
      Data1 = PCB;
      Data2 = Robot_Type;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();
      Serial.print(F("PCB = "));
      if (PCB == 1) Serial.println(F("Enabled"));
      if (PCB == 0) Serial.println(F("Disabled"));
      }


      
// Perimeter Wire Menu is selected on the TFT
    if (TFT_Menu_Command == 6) {
      Serial.println("TX Perimeter to TFT");
      Data1 = Perimeter_Wire_Enabled;
      Data2 = WIFI_Enabled;
      Data3 = Bumper_Activate_Frnt;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();
      Serial.print(F("Wire Sensor ON = "));
      Serial.println(Perimeter_Wire_Enabled);
      Serial.print(F("WIFI Enabled = "));
      Serial.println(WIFI_Enabled);
      Serial.print(F("Bumper ON = "));
      Serial.println(Bumper_Activate_Frnt);
      Serial.println(F(" "));
      }


// Rain Sensor Menu is selected on the TFT
    if (TFT_Menu_Command == 12) {
      Serial.println("TX Rain to TFT");
      Data1 = Rain_Sensor_Installed;
      Data2 = Rain_Total_Hits_Go_Home;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();

      Serial.print(F("Rain Sensor ON = "));
      Serial.println(Rain_Sensor_Installed);
      Serial.print(F("Rain Sensitivity = "));
      Serial.println(Rain_Total_Hits_Go_Home);
      Serial.println(F(" "));
      }


// Wheel Motor Menu is selected on the TFT Screen
    if (TFT_Menu_Command == 14) {
      Serial.println("TX Wheel PWM to TFT");
      Data1 = PWM_MaxSpeed_LH;
      Data2 = PWM_MaxSpeed_RH;
      Data3 = PWM_Slow_Speed_LH;
      Data4 = PWM_Slow_Speed_RH;
      Data5 = Slow_Speed_MAG / 10;
      Data6 = Wheels_Activate;  // RVES added
      Data7 = 0;
      TX_7_Data_Values();

      Serial.print(F("PWM LH = "));
      Serial.println(PWM_MaxSpeed_LH);
      Serial.print(F("PWM RH = "));
      Serial.println(PWM_MaxSpeed_RH);
      Serial.print(F("PWM S LH = "));
      Serial.println(PWM_Slow_Speed_LH);
      Serial.print(F("PWM S RH = "));
      Serial.println(PWM_Slow_Speed_RH);
      Serial.print(F("Slow MAG = "));
      Serial.println(Slow_Speed_MAG);
      Serial.print(F("Wheels_Activate = ")); // RVES added
      Serial.println(Wheels_Activate); // RVES added
      Serial.println(F(" ")); 
      }
      
      

// Blade Motor Menu is selected on the TFT Screen
    if (TFT_Menu_Command == 15) {

      Serial.println("TX Blade Data to TFT");
      Data1 = PWM_Blade_Speed;
      Data2 = Cutting_Blades_Activate;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data6 = 0;
      TX_7_Data_Values();
     
      Serial.print(F("Blade Motor PWM = "));
      Serial.println(PWM_Blade_Speed);
      Serial.print(F("Cutting Blade Activated = "));
      Serial.println(Cutting_Blades_Activate);
      Serial.println(F(" "));
      }


// Motion Turns Menu is selected on the TFT Screen
    if (TFT_Menu_Command == 16) {

      Serial.println("TX Turns Data to TFT");
      Data1 = Max_Cycles_Straight / 10 ;
      Data2 = Mower_Turn_Delay_Min / 100;
      Data3 = Mower_Turn_Delay_Max / 100;
      Data4 = Mower_Reverse_Delay / 100;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();
      
      Serial.print(F("Max Mow L = "));
      Serial.println(Max_Cycles_Straight);
      Serial.print(F("Turn Min = "));
      Serial.println(Mower_Turn_Delay_Min);
      Serial.print(F("Turn Max = "));
      Serial.println(Mower_Turn_Delay_Max);
      Serial.print(F("Reverse = "));
      Serial.println(Mower_Reverse_Delay);
      Serial.println(F(" "));

}


// Tracking to Exit Menu is selected on the TFT Screen
    if (TFT_Menu_Command == 17) {
      Serial.println("TX Exit to TFT");

      Data1 = Track_Wire_Zone_1_Cycles / 100 ;
      Data2 = Track_Wire_Zone_2_Cycles / 100;
      Data3 = CCW_Tracking_To_Start;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();
      Serial.print(F("Track Wire Zone 1 = "));
      Serial.println(Track_Wire_Zone_1_Cycles);    
      Serial.print(F("Track Wire Zone 2 = "));
      Serial.println(Track_Wire_Zone_2_Cycles);      
      if (CCW_Tracking_To_Start == 0) {
        CW_Tracking_To_Start = 1;
        CCW_Tracking_To_Charge = 1;
        CW_Tracking_To_Charge = 0;
        Serial.println(F("Tracking to Charge = CCW"));
        Serial.println(F("Tracking to Start = CW"));
        }        
      if (CCW_Tracking_To_Start == 1) {
        CW_Tracking_To_Start = 0;
        CCW_Tracking_To_Charge = 0;
        CW_Tracking_To_Charge = 1;        
        Serial.println(F("Tracking to Charge = CW"));
        Serial.println(F("Tracking to Start = CCW"));       
        }
    }


// Charging Options Menu is selected on the TFT Screen
    if (TFT_Menu_Command == 8) {
      Serial.println("TX Tracking to TFT");
    
      Serial3.print(Use_Charging_Station);
      Serial3.println("\a");
      delay(300); 

      Serial.print(F("Use Charging Station = "));
      Serial.println(Use_Charging_Station); 
      } 


// Find Wire Menu is selected on the TFT Screen
    if (TFT_Menu_Command == 18) {
      Serial.println("TX Find Wire to TFT");
      Data1 = Max_Cycle_Wire_Find / 100 ;
      Data2 = Max_Cycle_Wire_Find_Back / 10;
      Data3 = Home_Wire_Compass_Heading;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();
      Serial.print(F("Wire Find Forwards / cylces = "));
      Serial.println(Max_Cycle_Wire_Find);      
      Serial.print(F("Wire Find Backwards / cylces = "));
      Serial.println(Max_Cycle_Wire_Find_Back);
      Serial.print(F("Home Compass Heading / degrees "));
      Serial.println(Home_Wire_Compass_Heading);      
      }

// Tracking PID Menu is selected on the TFT Screen
    if (TFT_Menu_Command == 19) {
      Serial.println("TX Find Wire to TFT");
      
      Serial3.print(Max_Tracking_Turn_Left / 10);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Max_Tracking_Turn_Right / 10);
      Serial3.println("\b");
      delay(200);  

      Serial3.print(P * 100);
      Serial3.println("\c");
      delay(200);  

      Serial.print(F("Max Cycles Left Wheel = "));
      Serial.println(Max_Tracking_Turn_Left);
      Serial.print(F("Max Cycles Right Wheel = "));
      Serial.println(Max_Tracking_Turn_Right);         
      Serial.print(F("PID P = "));
      Serial.println(P);
      Serial.println(F(" "));     
      }


// Compass Menu is selected on the TFT Screen
    if (TFT_Menu_Command == 27) {
      Serial.println("TX Compass to TFT");
      
      Serial3.print(Compass_Activate);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Compass_Heading_Hold_Enabled);
      Serial3.println("\b");
      delay(300);  

      Serial3.print(CPower * 10);
      Serial3.println("\c");
      delay(300);  
      
      Serial3.print(Compass_Setup_Mode);
      Serial3.println("\d");
      delay(200);  

      Serial.print(F("Compass Activated = "));
      Serial.println(Compass_Activate);
      Serial.print(F("Heading Hold Enabled = "));
      Serial.println(Compass_Heading_Hold_Enabled);          
      Serial.print(F("Compass Power = "));
      Serial.println(CPower);    
      Serial.print(F("Compass Setup Mode = "));
      Serial.println(Compass_Setup_Mode); 
      }


// GYRO Menu is selected on the TFT Screen
    if (TFT_Menu_Command == 28) {

      Serial3.print(GYRO_Enabled);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(GPower * 10);
      Serial3.println("\b");
      delay(300);

      Serial.print(F("GYRO Enabled= "));
      Serial.println(GYRO_Enabled); 
      Serial.print(F("GYRO Power = "));
      Serial.println(GPower);     
    }


// GPS Menu
    if (TFT_Menu_Command == 32) {
      Serial.println("GPS Enabled");

      Serial3.print(GPS_Enabled);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(GPS_Type);
      Serial3.println("\b");
      delay(300);

    Serial.print(F("GPS: "));
        if (GPS_Enabled == 1) Serial.println("ON");
        if (GPS_Enabled == 0) Serial.println("OFF");    
    Serial.print(F("GPS Type: "));
        if (GPS_Type == 1) Serial.println("ReP_AL");
        if (GPS_Type == 2) Serial.println("PIXHAWK");    
        if (GPS_Type == 3) Serial.println("Spare");      
    }


// Wheel Blockage Menu is selected on the TFT Screen
    if (TFT_Menu_Command == 29) {

      Serial.println("TX Wheel Block to TFT");
      Data1 = Wheel_Amp_Sensor_ON;
      float Temp = Max_Wheel_Amps * 100;
      int Temp2 = Temp;
      Data2 = Temp2;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();

    Serial.print(F("Wheel Amp ON: "));
        if (Wheel_Amp_Sensor_ON == 1) Serial.println("ON");
        if (Wheel_Amp_Sensor_ON == 0) Serial.println("OFF");   
    Serial.print(F("Wheel Amps Max: "));
    Serial.println(Max_Wheel_Amps);     
    }

// Alarm 1 Menu is selected on the TFT Screen
    if (TFT_Menu_Command == 20) {
      Serial.println("TX Alarm1 TFT");

      Data1 = Alarm_1_ON;
      Data2 = Alarm_1_Hour;
      Data3 = Alarm_1_Minute;
      Data4 = Alarm_1_Repeat;
      Data5 = Alarm_1_Action;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();

      Serial.print(F("Alarm 1 ON = "));
      Serial.println(Alarm_1_ON);
      Serial.print(F("Alarm 1 Time = "));
      Serial.print(Alarm_1_Hour);
      Serial.print(F(":"));
      Serial.println(Alarm_1_Minute);
      Serial.print(F("Alarm 1 Repeat = "));
      Serial.println(Alarm_1_Repeat);
      Serial.print(F("Alarm 1 Action = "));
      Serial.println(Alarm_1_Action);    
      }


// Alarm 2 Menu is selected on the TFT Screen
    if (TFT_Menu_Command == 21) {
      Serial.println("TX Alarm2 TFT");
      
      Data1 = Alarm_2_ON;
      Data2 = Alarm_2_Hour;
      Data3 = Alarm_2_Minute;
      Data4 = Alarm_2_Repeat;
      Data5 = Alarm_2_Action;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();

      Serial.print(F("Alarm 2 ON = "));
      Serial.println(Alarm_2_ON);
      Serial.print(F("Alarm 2 Time = "));
      Serial.print(Alarm_2_Hour);
      Serial.print(F(":"));
      Serial.println(Alarm_2_Minute);
      Serial.print(F("Alarm 2 Repeat = "));
      Serial.println(Alarm_2_Repeat);
      Serial.print(F("Alarm 2 Action = "));
      Serial.println(Alarm_2_Action);    
      }


// Alarm 3 Menu is selected on the TFT Screen
    if (TFT_Menu_Command == 22) {
      Serial.println("TX Alarm3 TFT");
      
      Data1 = Alarm_3_ON;
      Data2 = Alarm_3_Hour;
      Data3 = Alarm_3_Minute;
      Data4 = Alarm_3_Repeat;
      Data5 = Alarm_3_Action;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();

      Serial.print(F("Alarm 3 ON = "));
      Serial.println(Alarm_3_ON);
      Serial.print(F("Alarm 3 Time = "));
      Serial.print(Alarm_3_Hour);
      Serial.print(F(":"));
      Serial.println(Alarm_3_Minute);
      Serial.print(F("Alarm 3 Repeat = "));
      Serial.println(Alarm_3_Repeat);
      Serial.print(F("Alarm 3 Action = "));
      Serial.println(Alarm_3_Action);    
      }


// Set Time Menu is selected on the TFT Screen
    if (TFT_Menu_Command == 23) {
      Serial.println("Set Time TFT");
      if (PCB == 0) {
        Time t = rtc.time();
        Time_Hour = t.hr;
        Time_Minute = t.min;
        Time_Date = t.date;
        Time_Month = t.mon;
        Time_Year = t.yr;
        Time_Day = t.day;
        }
      if (PCB == 1) {
        byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
        Read_DS3231_PCB_Time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
        Time_Hour = hour;
        Time_Minute = minute;
        Time_Second = second;
        Time_Date = dayOfMonth;
        Time_Month = month;
        Time_Year = year;
        Time_Day = dayOfWeek;
        }
 
      Serial3.print(Time_Hour);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Time_Minute);
      Serial3.println("\b");
      delay(200);

      Serial3.print(Time_Date);
	  Serial3.println("\e");
	  delay(200);

      Serial3.print(Time_Month);
	  Serial3.println("\f");
	  delay(200);

      Serial3.print(Time_Year);
	  Serial3.println("\w");
	  delay(200);

      Serial3.print(Time_Day);
	  Serial3.println("\h");
	  delay(200);
/*
      Serial.print(F("DateTime Now = "));
      Serial.print(Time_Year);
      Serial.print(F("-"));
      if (Time_Month < 10) Serial.print(F("0"));
      Serial.print(Time_Month);
	  Serial.print(F("-"));
	  if (Time_Date < 10) Serial.print(F("0"));
	  Serial.print(Time_Date);
	  Serial.print(F(" "));
	  if (Time_Hour < 10) Serial.print(F("0"));
      Serial.print(Time_Hour);
      Serial.print(F(":"));
      if (Time_Minute < 10) Serial.print(F("0"));
      Serial.println(Time_Minute);
      */
	  PrintTimeToSerial(2, Time_Year, Time_Month, Time_Date, Time_Hour, Time_Minute, 0, Time_Day, 1);
      }



// Tip Sensor Menu is selected on the TFT Screen
    if (TFT_Menu_Command == 24) {

      Serial.println("TX Tip Sensor to TFT");
      Data1 = Angle_Sensor_Enabled;
      Data2 = Tip_Over_Sensor_Enabled;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();
      Serial.print(F("Angle ON = "));
      Serial.println(Angle_Sensor_Enabled);
      Serial.print(F("Tip ON = "));
      Serial.println(Tip_Over_Sensor_Enabled);
      Serial.println(" ");
}


// Pattern Mow Menu is selected on the TFT Screen
    if (TFT_Menu_Command == 25) {
      Serial.println("TX Pattern to TFT");
      Data1 = Pattern_Mow;
      Data2 = Turn_90_Delay_LH / 10;
      Data3 = Turn_90_Delay_RH / 10;
      Data4 = Move_to_next_line_delay / 10;
      Data5 = Line_Length_Cycles;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();
      if (Pattern_Mow == 0) Serial.println("OFF");
      if (Pattern_Mow == 1) Serial.println("Parallel");  
      if (Pattern_Mow == 2) Serial.println("Spiral"); 
      Serial.print(F("Turn 90° LH= "));
      Serial.println(Turn_90_Delay_LH);  
      Serial.print(F("Turn 90° RH= "));
      Serial.println(Turn_90_Delay_RH);      
      Serial.print(F("Distance to next row= "));
      Serial.println(Move_to_next_line_delay);      
      Serial.print(F("Row Length = "));
      Serial.println(Line_Length_Cycles);  
      Serial.println(" "); 
}



// Initial Start Up Values requested from the TFT
// The TFT first sends a request for the MEGA to 
    if (TFT_Menu_Command == 55) {
      Serial.println("TX Start Up Values TFT - Alarms");

      Data1 = Alarm_1_ON;
      Data2 = Alarm_2_ON;
      Data3 = Alarm_3_ON;
      //Data4 = reserve;
      //Data5 = reserve;
      Data6 = GPS_Enabled;
      Data7 = Perimeter_Wire_Enabled;
      TX_7_Data_Values();

      Serial.print(F("Alarm 1 ON = "));
      Serial.println(Alarm_1_ON);
      Serial.print(F("Alarm 2 ON = "));
      Serial.println(Alarm_2_ON);
      Serial.print(F("Alarm 3 ON = "));
      Serial.println(Alarm_3_ON);

      Serial.print(F("GPS:"));
      if (GPS_Enabled == 1) Serial.println("ON");   
      if (GPS_Enabled == 0) Serial.println("OFF"); 
      Serial.print(F("WIRE:"));
      if (Perimeter_Wire_Enabled == 1) Serial.println("ON");   
      if (Perimeter_Wire_Enabled == 0) Serial.println("OFF"); 

}


	// Date
	if (TFT_Menu_Command == 56) {
		Serial.println("TX Start Up Values TFT - DateTime");

		Get_Current_Time_Print_On_Serial_Monitor();

		if (PCB == 0) {
			//Time t = rtc.time();
			Serial.println("Using Clock Module None PCB");
	    }
		else if (PCB == 1) {
			Serial.println("Using PCB Clock");
	        //byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
	        //Read_DS3231_PCB_Time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
	    }

		Data1 = Time_Year;
		Data2 = Time_Month;
		Data3 = Time_Date;
		Data4 = Time_Hour;
		Data5 = Time_Minute;
		Data6 = Time_Day;
		Data7 = 0;
		TX_7_Data_Values();
/*
		Serial.print(F("DateTime: "));
		Serial.print(Time_Year);
		Serial.print(F("-"));
		if (Time_Month < 10) Serial.print(F("0"));
		Serial.print(Time_Month);
		Serial.print(F("-"));
		if (Time_Date < 10) Serial.print(F("0"));
		Serial.print(Time_Date);
		Serial.print(F(" "));
		if (Time_Hour < 10) Serial.print("0");
		Serial.print(Time_Hour);
		Serial.print(F(":"));
		if (Time_Minute < 10) Serial.print("0");
		Serial.print(Time_Minute);

		Serial.print(F(" DOW:"));
		Serial.println(Time_Day);
		*/
		PrintTimeToSerial(2, Time_Year, Time_Month, Time_Date, Time_Hour, Time_Minute, 0, Time_Day, 1);
	}


// Test Wire Sensor
    if (TFT_Menu_Command == 41) {
      Serial.println("Test Wire Sensor");

      bool Test_Complete = 0;

      for (int i = 0; i <= 30; i++) {

          if (i > 28) Test_Complete = 1;
            ADCMan.run();
            // ADCMan.setCapture(pinPerimeterLeft, 1, 0);
          
            if (millis() >= nextTime)  {
              nextTime = millis() + 50;
              if (perimeter.isInside(0) != inside) {
                inside = perimeter.isInside(0);
                counter++;
              }
            }
     
          Serial3.print((perimeter.isInside(0)));
          Serial3.println("\a");
          delay(300);  
    
          Serial3.print(perimeter.getMagnitude(0));
          Serial3.println("\b");
          delay(200);  

          Serial3.print(Test_Complete);
          Serial3.println("\c");
          delay(200);  
    
          Serial.print(F("IN/Out:"));
          Serial.print(perimeter.isInside(0));
          Serial.print(F("   MAG:"));
          Serial.print(perimeter.getMagnitude(0)); 
          Serial.print(F("   i:"));
          Serial.println(i);
          }
      Serial.println(F("Test Completed"));
      }


// Start Sonar Test
  if (TFT_Menu_Command == 45) {
    Serial.println(F("Sonar Test"));
    bool Test_Complete = 0;

    // turn on the Sonoar Sensors for the test
    int Sonar1_Status = Sonar_1_Activate; 
    int Sonar2_Status = Sonar_2_Activate; 
    int Sonar3_Status = Sonar_3_Activate; 

    Serial.println(F("Activating Sonar Array"));
    Sonar_1_Activate = 1;
    Sonar_2_Activate = 1;
    Sonar_3_Activate = 1;    
    
      for (int i = 0; i <= 30; i++) {

        if (i > 28) Test_Complete = 1;
        if (Sonar_1_Activate == 1) distance1 = PingSonarY(trigPin1, echoPin1, 1, 1, 1, 5, 0);          //SONAR1
        if (Sonar_1_Activate == 0) distance1 = 999;
        delay(15);       
        if (Sonar_2_Activate == 1) distance2 = PingSonarY(trigPin2, echoPin2, 2, 2, 2, 0, 0);         //SONAR2
        if (Sonar_2_Activate == 0) distance1 = 999;
        delay(15);
        if (Sonar_3_Activate == 1) distance3 = PingSonarY(trigPin3, echoPin3, 3, 3, 3, 10, 0);          //SONAR3
        if (Sonar_3_Activate == 0) distance1 = 999;
        delay(15);
        
        Serial3.print(distance1);
        Serial3.println("\a");
        delay(300);  
    
        Serial3.print(distance2);
        Serial3.println("\b");
        delay(200);  

        Serial3.print(distance3);
        Serial3.println("\c");
        delay(200); 

        Serial3.print(Test_Complete);
        Serial3.print("\d");
        delay(200);    

        Serial.print("  Test Complete");
        Serial.println(Test_Complete);
      
      
      }
    Serial.println(F("Sonar Test Complete"));

    Serial.println(F("Restting Sonar Array ON/OFFStatus"));
    Sonar_1_Activate = Sonar1_Status;
    Sonar_2_Activate = Sonar2_Status;
    Sonar_3_Activate = Sonar3_Status;   

    }


// Start Compass Test
  if (TFT_Menu_Command == 48) {
    Serial.println(F("Compass Test"));
    bool Test_Complete = 0;
    // turn on the Compass Sensor for the test
    int Compass_Status = Compass_Activate; 

    if (Compass_Activate == 0) {
        Serial.println(F("Turning on Compass for Test"));
        Compass_Activate = 1;
        Setup_DFRobot_QMC5883_HMC5883L_Compass();                     // USes the DFRobot Library
        }

      int Cycles = 40;

      for (int i = 0; i <= Cycles; i++) {

        if (i > (Cycles - 2) ) Test_Complete = 1;
        Get_Compass_Reading();

        int Compass_Degrees_TX = Compass_Heading_Degrees;
        delay(300);
        
        Serial3.print(Heading * 10);
        Serial3.println("\a");
        delay(300);  
      
        Serial3.print(Compass_Degrees_TX);
        Serial3.println("\b");
        delay(300); 

        Serial.print("Heading: ");
        Serial.print(Heading);
        Serial.print("  Degrees: ");
        Serial.println(Compass_Degrees_TX);
  
     
        Serial3.print(Test_Complete);
        Serial3.println("\c");
        delay(300);    


      }

    Serial.print(F("Returning Compass ON/OFF to original state"));
    Compass_Activate = Compass_Status; 
    Serial.print(F("Compass Test Complete"));
    Serial.println(Test_Complete);
    }


// Start GYRO Test
  if (TFT_Menu_Command == 39) {
    Serial.println(F("GYRO Test"));
    bool Test_Complete = 0;

      int Cycles = 60;

      for (int i = 0; i <= Cycles; i++) {

        if (i > (Cycles - 2) ) Test_Complete = 1;
        Get_GYRO_Reading();
        Print_GYRO_Reading();

       
        Serial3.print(GYRO_Angle_X);
        Serial3.println("\a");
        delay(300);  
      
        Serial3.print(GYRO_Angle_Y);
        Serial3.println("\b");
        delay(300); 
    
        Serial3.print(Test_Complete);
        Serial3.println("\c");
        delay(300);    

        //Serial.print("Angle X: ");
        //Serial.print(GYRO_Angle_X);
        //Serial.print(" Angle Y: ");
        //Serial.println(GYRO_Angle_Y);

      }

    Serial.print(F("Compass Test Complete"));
    Serial.println(Test_Complete);
    }


// Start Volt Amp Test
  if (TFT_Menu_Command == 47) {
    Serial.println(F("Volt Amp Test"));
    bool Test_Complete = 0;

      for (int i = 0; i <= 30; i++) {

        if (i > 28) Test_Complete = 1;
        
        Read_Serial1_Nano();
        delay(200);

        int VoltsRX = (Volts * 100) / 2;
   
        Serial3.print(VoltsRX);
        Serial3.println("\a");
        delay(100);  
    
        Serial3.print(Amps * 100);
        Serial3.println("\b");
        delay(100); 
        
        Serial3.print(Test_Complete);
        Serial3.println("\c");
        delay(300);    

        Serial.print("VoltsRX: ");
        Serial.print(VoltsRX);
        Serial.print("  Volts: ");
        Serial.print(Volts);
        Serial.print("  Amps: ");
        Serial.println(Amps);
      }

    Serial.print(F("Volt Amp Test Complete"));
    Serial.println(Test_Complete);
    }

// Start Tilt Test
  if (TFT_Menu_Command == 40) {
    Serial.println(F("Tilt Test"));
    bool Test_Complete = 0;
    Setup_Tilt_Tip_Safety();

      for (int i = 0; i <= 30; i++) {

        if (i > 28) Test_Complete = 1;
        
        Check_Tilt_Tip_Angle(); 
        delay(200);
   
        Serial3.print(Tilt_Angle_Sensed);
        Serial3.println("\a");
        delay(100);  
    
        Serial3.print(Tilt_Orientation_Sensed);
        Serial3.println("\b");
        delay(100); 
        
        Serial3.print(Test_Complete);
        Serial3.println("\c");
        delay(300);    

        Serial.print(F("   Data sent"));

        Serial.print(F("  Test Completed "));
        Serial.println(Test_Complete);
      }

    Serial.print(F("Tilt Test Complete : "));
    Serial.println(Test_Complete);
    }



// Start Bumper Test
  if (TFT_Menu_Command == 50) {
    Serial.println(F("Bumper Bar Test"));
    
    Setup_Microswitches();
    
    bool Test_Complete = 0;
    bool Bump_LH;
    bool Bump_RH;

      for (int i = 0; i <= 30; i++) {

        if (i > 28) Test_Complete = 1;
        
        if (digitalRead(Microswitch_2))  Bump_LH = 0; 
        if (!digitalRead(Microswitch_2)) Bump_LH = 1;
        if (digitalRead(Microswitch_1))  Bump_RH = 0; 
        if (!digitalRead(Microswitch_1)) Bump_RH = 1;
        delay(200);

 
        Serial3.print(Bump_LH);
        Serial3.println("\a");
        delay(100);  
    
        Serial3.print(Bump_RH);
        Serial3.println("\b");
        delay(100); 
        
        Serial3.print(Test_Complete);
        Serial3.println("\c");
        delay(300);    

        Serial.print("Bump LH: ");
        Serial.print(Bump_LH);
        Serial.print("  Bump RH: ");
        Serial.println(Bump_RH);
      }

    Serial.print(F("Volt Bumper Test Complete"));
    Serial.println(Test_Complete);
    }


}




void Send_Mower_Tracking_Data() {
    	byte data[7];
    	data[0] = 11; // Packet ID
    	data[1]=Turn_To_Home;
    	data[2]=Find_Wire_Track;
    	data[3]=Go_To_Charging_Station;
    	data[4]=Mower_Docked;
    	data[5]=Robot_Status_Value;
    	data[6]=Mower_Error_Value;
    	SerialCom3.sendMsg (data, sizeof (data));
      }

void Send_Mower_Error_Data() {
        
        Serial3.print(Robot_Status_Value);
        Serial3.println("\a");
        delay(300); 

        Serial3.print(Mower_Error_Value);
        Serial3.println("\b");
        delay(300); 
        
        Serial.print("Sending Error Data to TFT");

        Serial.println(F(""));
        Serial.print(F("|RSV:"));
        Serial.print(Robot_Status_Value); 
        Serial.print(F("|ME:"));
        Serial.print(Mower_Error_Value); 
        Serial.println(F(""));
        }

void Send_Mower_Setup_Data() {
        
        Serial3.print(Robot_Status_Value);
        Serial3.println("\a");
        delay(300); 
        
        Serial.print(F("TX Setup to TFT"));
        Serial.print(F("|RSV:"));
        Serial.print(Robot_Status_Value); 

        }



void Send_Mower_Running_Data() {
    float VoltsTX1 = Volts * 100;
    VoltsTX = VoltsTX1;
    Bumper_Status = Bumper;
    float WheelAmpsTX1 = WheelAmps * 100;
    WheelAmpsTX = WheelAmpsTX1;
    Compass_Heading_DegreesTX = Compass_Heading_Degrees;
  	byte data[19];
  	data[0] = 12; // Packet ID

  	data[1] = Sonar_Status;
  	data[2] = Outside_Wire;
  	data[3] = Bumper_Status;
  	data[4] = Robot_Status_Value;
  	data[5] = Mower_Error_Value;
  	data[6] = Tilt_Angle_Sensed;
  	data[7] = VoltsTX;
  	data[8] = VoltsTX >> 8;
  	data[9] = GPS_Inside_Fence;
  	data[10]= GPS_Lock_OK;
  	data[11]= Loop_Cycle_Mowing;
  	data[12]= Loop_Cycle_Mowing >> 8;
  	data[13]= Compass_Steering_Status;
  	data[14]= WheelAmpsTX;
  	data[15]= WheelAmpsTX >> 8;
  	data[16]= Compass_Heading_DegreesTX;
  	data[17]= Compass_Heading_DegreesTX >> 8;

  	bitWrite(data[18],0,Wheel_Blocked_Status);
  	//bitWrite(data[18],1,reserve);
  	//bitWrite(data[18],2,reserve);
  	//bitWrite(data[18],3,reserve);
  	//bitWrite(data[18],4,reserve);
  	//bitWrite(data[18],5,reserve);
  	//bitWrite(data[18],6,reserve);
  	//bitWrite(data[18],7,reserve);

  	SerialCom3.sendMsg (data, sizeof (data));

	Calculate_TFT_Robot_Status_Value();

	Serial.print(F("|S:"));
	Serial.print(Sonar_Status);
	Serial.print(F("|W:"));
	Serial.print(Outside_Wire);
	Serial.print(F("|B:"));
	Serial.print(Bumper_Status);
	Serial.print(F("|RSV:"));
	Serial.print(Robot_Status_Value);
	Serial.print(F("|ME:"));
	Serial.print(Mower_Error_Value);
	Serial.print(F("|Tip:"));
	Serial.print(Tilt_Angle_Sensed);
	Serial.print(F("|VTX:"));
	Serial.print(VoltsTX);
	if (GPS_Enabled) {
		Serial.print(F("|GPS Inside Fence:"));
		if (GPS_Inside_Fence == 0) Serial.print("OUT");
		if (GPS_Inside_Fence == 1) Serial.print("IN");
		Serial.print(F("|GPS Lock:"));
		if (GPS_Lock_OK == 0) Serial.print("No lock");
		if (GPS_Lock_OK == 1) Serial.print("RTK FIX");
	}
}


void Send_Aerator_Running_Data() {
    float VoltsTX1 = Volts * 100;
    VoltsTX = VoltsTX1;
    Bumper_Status = Bumper;
    float WheelAmpsTX1 = WheelAmps * 100;
    WheelAmpsTX = WheelAmpsTX1;
    Compass_Heading_DegreesTX = Compass_Heading_Degrees;
    byte data[19];
    data[0] = 12; // Packet ID

    data[1] = Sonar_Status;
    data[2] = Outside_Wire;
    data[3] = Drill_Status;
    data[4] = Robot_Status_Value;
    data[5] = Mower_Error_Value;
    data[6] = Tilt_Angle_Sensed;
    data[7] = VoltsTX;
    data[8] = VoltsTX >> 8;
    data[9] = GPS_Inside_Fence;
    data[10]= GPS_Lock_OK;
    data[11]= Loop_Cycle_Mowing;
    data[12]= Loop_Cycle_Mowing >> 8;
    data[13]= Compass_Steering_Status;
    data[14]= WheelAmpsTX;
    data[15]= WheelAmpsTX >> 8;
    data[16]= Compass_Heading_DegreesTX;
    data[17]= Compass_Heading_DegreesTX >> 8;

    bitWrite(data[18],0,Wheel_Blocked_Status);
    //bitWrite(data[18],1,reserve);
    //bitWrite(data[18],2,reserve);
    //bitWrite(data[18],3,reserve);
    //bitWrite(data[18],4,reserve);
    //bitWrite(data[18],5,reserve);
    //bitWrite(data[18],6,reserve);
    //bitWrite(data[18],7,reserve);

    SerialCom3.sendMsg (data, sizeof (data));

  Calculate_TFT_Robot_Status_Value();


        Serial.print(F("|S:"));          
        Serial.print(Sonar_Status);
        Serial.print(F("|W:"));
        Serial.print(Outside_Wire);  
        Serial.print(F("|B:"));
        Serial.print(Bumper_Status); 
        Serial.print(F("|RSV:"));
        Serial.print(Robot_Status_Value);  
        Serial.print(F("|ME:"));
        Serial.print(Mower_Error_Value); 
        Serial.print(F("|Tip:"));
        Serial.print(Tilt_Angle_Sensed);     
        Serial.print(F("|VTX:"));
        Serial.print(VoltsTX);
        if (GPS_Enabled) {
			Serial.print(F("|GPS Inside Fence:"));
			if (GPS_Inside_Fence == 0) Serial.print("OUT");
			if (GPS_Inside_Fence == 1) Serial.print("IN");
			Serial.print(F("|GPS Lock:"));
			if (GPS_Lock_OK == 0) Serial.println("No lock");
			if (GPS_Lock_OK == 1) Serial.println("RTK FIX");
        }
	}


//*********

void Send_PIXHAWK_Running_Data() {
        int Delay_running = 10;
        int spare = 0;
        
        Serial.print(F("TX:"));
       
        Serial3.print(PWM_Arduino_LH);
        Serial3.println(F("\a"));        
        delay(Delay_running);
    
        Serial3.print(PWM_Arduino_RH);
        Serial3.println(F("\b"));
        delay(Delay_running);        
        
        Serial3.print(spare);
        Serial3.println("\c");
        delay(Delay_running);    

        Serial3.print(spare);
        Serial3.println("\s");
        delay(Delay_running);    

        Serial3.print(spare);      
        Serial3.println("\e");
        delay(Delay_running); 
  
        Serial3.print(spare);      
        Serial3.println("\f");
        delay(Delay_running); 
        
        Serial3.print(spare);      
        Serial3.println("\g");
        delay(Delay_running);

        Serial3.print(spare);      
        Serial3.println("\h");
        delay(Delay_running);

        Serial3.print(cycles);      
        Serial3.println("\i");
        delay(Delay_running);        

        Serial.print(F("|LW:"));          
        Serial.print(PWM_Arduino_LH);
        Serial.print(F("|RW:"));
        Serial.print(PWM_Arduino_RH);  

        Serial.print(F("|C:"));
        Serial.print(cycles);  
        Serial.print(F("|"));
        }


// Sends Wheel Amp Data during Test
void Send_Wheel_Amp_Data() {
        Serial3.print(Wheel_Blocked);      
        Serial3.println("\a");
        delay(300);
        }



// Transfers the values to the TFT in Docked Mode.
void Send_Mower_Docked_Data()  {

      Calculate_TFT_Robot_Status_Value();
      // Reformat Volts value for transmission
      float VoltsTX1 = Volts * 100;
      VoltsTX = VoltsTX1;

    	byte data[15];
    	data[0] = 10; // Packet ID

    	data[1]   = Time_Year;
    	data[2]   = Time_Year >> 8;
		  data[3]   = Time_Month;
		  data[4]   = Time_Date;
		  data[5]   = Time_Hour;
		  data[6]   = Time_Minute;
		  data[7]   = Time_Second;
		  data[8]   = Time_Day;

    	data[9]   = VoltsTX;
    	data[10]  = VoltsTX >> 8;
    	data[11]  = Robot_Status_Value;
    	data[12]  = Mower_Error_Value;
    	data[13]  = Charging;

      int GPS_Lock_OK_Docked_TX;
      if (GPS_Lock_OK == 0) GPS_Lock_OK_Docked_TX = 2;
      if (GPS_Lock_OK == 1) GPS_Lock_OK_Docked_TX = 5;
    	data[14]=GPS_Lock_OK_Docked_TX;

    	SerialCom3.sendMsg (data, sizeof (data));


        Serial.print(F("|VTX:"));
        Serial.print(VoltsTX);
        Serial.print(F("|RSV:"));
        Serial.print(Robot_Status_Value);            
        Serial.print(F("|ME:"));
        Serial.print(Mower_Error_Value);                 
        Serial.print(F("|C:"));
        Serial.print(Charging); 
        Serial.print(F("|LOCK:"));
        Serial.print(GPS_Lock_OK);            
        } 

void Calculate_TFT_Robot_Status_Value() {

  //    Mower Status Values
  //    1 = Docked
  //    2 = Parked
  //    3 = Setup App
  //    4 = Error State
  //    5 = Mowing
  //    6 = Manual Mode
  //    7 = Tracking
  //    8 = Rain
  //    9 = Exiting Dock
  //    11 = Manual Mode


   Robot_Status_Value = 0;

   if ((Wire_Detected == 1) && (Tilt_Orientation_Sensed == 0)) {
      Mower_Error = 0;
      if ((Mower_Docked == 1) || (Mower_Parked == 1)) {   
         Mower_Error_Value = 0;
         }
   }

   
   
   if (Wire_Detected == 0) {

        // If the mower is running and no wire is detected then the full error screen is displayed
        if (Mower_Running == 1) {
              Mower_Error = 1;
              Mower_Error_Value = 1;     // 1 = No Wire Detected
              }
        // If the mower is docked then the Wire Off message is displayed on the docked screen. 
        if ((Mower_Docked == 1) || (Mower_Parked == 1)) {
              Mower_Error_Value = 1;
              }
        }


   if (Mower_Docked == 1)           Robot_Status_Value = 1;
   if (Mower_Parked == 1)           Robot_Status_Value = 2; 
   
   if (Mower_Parked_Low_Batt == 1)  {
     Robot_Status_Value = 4;  // Error Mode
     Mower_Error_Value = 2;   // 2 = Low Battery
     }
   
   if (Mower_Error == 1)                                    Robot_Status_Value = 4;  // Error
   if (Mower_Error == 3) {
        Robot_Status_Value = 4;  // Error
        Mower_Error_Value = 3;   
        }
   
   //NEW
   if (Mower_Setup_Mode == 1)                               Robot_Status_Value = 3;
   if (Mower_Running == 1)                                  Robot_Status_Value = 5;
   if (Manual_Mode == 1)                                    Robot_Status_Value = 6;
   if (Tracking_Wire == 1)                                  Robot_Status_Value = 7;
   if (Rain_Hit_Detected == 1)                              Robot_Status_Value = 8;
   if (Exiting_Dock == 1)                                   Robot_Status_Value = 9;
   }
