void Receive_7_Data_Sets_Serial3() {
  
  Serial.println("Receiving Data Sets");

	byte recvBuff [15] = {0};
	bool confRecv = false;
	int testNum=0; //timeout
	while(!confRecv && testNum<500) {
		if (SerialCom3.update ())
		{
		  byte length = SerialCom3.getLength ();
		  if (length > sizeof (recvBuff)) length = sizeof (recvBuff);
		  memcpy (&recvBuff, SerialCom3.getData (), length);

		  if (recvBuff[0] == 17) {
			  Data1 = recvBuff[1] | recvBuff[2] << 8;
			  Data2 = recvBuff[3] | recvBuff[4] << 8;
			  Data3 = recvBuff[5] | recvBuff[6] << 8;
			  Data4 = recvBuff[7] | recvBuff[8] << 8;
			  Data5 = recvBuff[9] | recvBuff[10] << 8;
			  Data6 = recvBuff[11] | recvBuff[12] << 8;
			  Data7 = recvBuff[13] | recvBuff[14] << 8;

			  Serial.println("Data Sets Received");
			  confRecv = true;
		  }
		}  // end if something received
		testNum++; delay(1);
	}

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
  Serial.println(F(""));
}




void Receive_Data_From_TFT()  {

  // Receive the Sonar Values Back again
  if (TFT_Menu_Command == 910) {     
      Serial.println(F("Receiving Sonar Data from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Sonar_1_Activate  = Data1;
      Sonar_2_Activate  = Data2;
      Sonar_3_Activate  = Data3;
      maxdistancesonar  = Data4;
      Max_Sonar_Hit     = Data5;
      Data6 = 0;
      Data7 = 0;
      Serial.print(F("S1 ON = "));
      Serial.println(Sonar_1_Activate);
      Serial.print(F("S2 ON = "));
      Serial.println(Sonar_2_Activate);
      Serial.print(F("S3 ON = "));
      Serial.println(Sonar_3_Activate);
      Serial.print(F("Max Distance = "));
      Serial.println(maxdistancesonar);
      Serial.print(F("Sensitivity = "));
      Serial.println(Max_Sonar_Hit);

      #if defined(BOARD_DUE)
      dueFlashStorage.write(37, 1);
      dueFlashStorage.write(38, Sonar_1_Activate);
      dueFlashStorage.write(39, 1);
      dueFlashStorage.write(40, Sonar_2_Activate);
      dueFlashStorage.write(41, 1);
      dueFlashStorage.write(42, Sonar_3_Activate);
      dueFlashStorage.write(65, 1);
      dueFlashStorage.write(66, maxdistancesonar); 
      dueFlashStorage.write(63, 1);
      dueFlashStorage.write(64, Max_Sonar_Hit);         
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      EEPROM.write(37, 1);
      EEPROM.write(38, Sonar_1_Activate);
      EEPROM.write(39, 1);
      EEPROM.write(40, Sonar_2_Activate);
      EEPROM.write(41, 1);
      EEPROM.write(42, Sonar_3_Activate);
      EEPROM.write(65, 1);
      EEPROM.write(66, maxdistancesonar); 
      EEPROM.write(63, 1);
      EEPROM.write(64, Max_Sonar_Hit);         
      Serial.println(F("Saved to EEPROM"));
      #endif

          
      Serial.println(F(" "));
      }

// Receive the Battery Values Back again
  if (TFT_Menu_Command == 911) {
      Serial.println(F("Receiving Battery Data from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Battery_Min               = Data1;
      Low_Battery_Instances_Chg = Data2;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;                                          
      Serial.print(F("Battery Min = "));
      Battery_Min = Battery_Min / 10;    
      Serial.println(Battery_Min);      
      Serial.print(F("Battery Sensitivity = "));
      Serial.println(Low_Battery_Instances_Chg);

      #if defined(BOARD_DUE)
      dueFlashStorage.write(25, 1);
      dueFlashStorage.write(26, (Battery_Min * 10));   
      dueFlashStorage.write(85, 1);
      dueFlashStorage.write(86, Low_Battery_Instances_Chg); 
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      EEPROM.write(25, 1);
      EEPROM.write(26, (Battery_Min * 10));   
      EEPROM.write(85, 1);
      EEPROM.write(86, Low_Battery_Instances_Chg); 
      Serial.println(F("Saved to EEPROM"));
      #endif
      
      Serial.println(F(" "));
      }
  
// Receive the Sensor Menu 1 Values Back again
  if (TFT_Menu_Command == 96) {
      Serial.println(F("Receiving Sensor Menu 1 Values from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Perimeter_Wire_Enabled  = Data1;
      WIFI_Enabled            = Data2;
      Bumper_Activate_Frnt    = Data3;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;  
      Serial.print(F("Wire Module Activated = "));
      Serial.println(Perimeter_Wire_Enabled);
      Serial.print(F("WIFI Enabled = "));
      Serial.println(WIFI_Enabled);
      Serial.print(F("Bumper Activated = "));
      Serial.println(Bumper_Activate_Frnt);    

      #if defined(BOARD_DUE)
      dueFlashStorage.write(67 , 1);
      dueFlashStorage.write(68 , Perimeter_Wire_Enabled);
      dueFlashStorage.write(81 , 1);
      dueFlashStorage.write(82 , WIFI_Enabled);
      dueFlashStorage.write(90 , 1);
      dueFlashStorage.write(91 , Bumper_Activate_Frnt);
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      EEPROM.write(67 , 1);
      EEPROM.write(68 , Perimeter_Wire_Enabled);
      EEPROM.write(81 , 1);
      EEPROM.write(82 , WIFI_Enabled);
      EEPROM.write(90 , 1);
      EEPROM.write(91 , Bumper_Activate_Frnt);
      Serial.println(F("Saved to EEPROM"));
      #endif

      
      Serial.println(F(" "));
  }



// Receive the Rain Sensor Values Back again
  if (TFT_Menu_Command == 912) {
      Serial.println(F("Receiving Rain Sensor Values from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Rain_Sensor_Installed   = Data1;
      Rain_Total_Hits_Go_Home = Data2;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;  
      Serial.print(F("Rain ON = "));
      Serial.println(Rain_Sensor_Installed);
      Serial.print(F("Sensitivity = "));
      Serial.println(Rain_Total_Hits_Go_Home);   

      #if defined(BOARD_DUE)
      dueFlashStorage.write(77 , 1);
      dueFlashStorage.write(78 , Rain_Sensor_Installed);
      dueFlashStorage.write(79, 1);
      dueFlashStorage.write(80, Rain_Total_Hits_Go_Home);   
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      EEPROM.write(77 , 1);
      EEPROM.write(78 , Rain_Sensor_Installed);
      EEPROM.write(79, 1);
      EEPROM.write(80, Rain_Total_Hits_Go_Home);   
      Serial.println(F("Saved to EEPROM"));
      #endif
      
      Serial.println(F(" "));
    }


// Receive the Mower Motor Values Back again
  if (TFT_Menu_Command == 914) {
      Serial.println(F("Receiving Mower Motor Values from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      PWM_MaxSpeed_LH   = Data1;
      PWM_MaxSpeed_RH   = Data2;
      PWM_Slow_Speed_LH = Data3;
      PWM_Slow_Speed_RH = Data4;
      Slow_Speed_MAG    = Data5;
      Wheels_Activate   = Data6;
      Data7 = 0;  
      Serial.print(F("Wheel Motor PWM LH = "));
      Serial.println(PWM_MaxSpeed_LH);
      Serial.print(F("Wheel Motor PWM RH = "));
      Serial.println(PWM_MaxSpeed_RH);
      Serial.print(F("Wheel Motor Wire Speed PWM LH = "));
      Serial.println(PWM_Slow_Speed_LH);
      Serial.print(F("Wheel Motor Wire Speed PWM RH = "));
      Serial.println(PWM_Slow_Speed_RH);
      Serial.print(F("Slow Speed MAG = "));     
      Slow_Speed_MAG = Slow_Speed_MAG * 10;
      Serial.println(Slow_Speed_MAG);
      Serial.print(F("Wheels_Activate = ")); // RVES added
	  Serial.println(Wheels_Activate); // RVES added
      Serial.println(F(" "));     

       #if defined(BOARD_DUE)
      dueFlashStorage.write(13, 1);
      dueFlashStorage.write(14, PWM_MaxSpeed_LH);
      dueFlashStorage.write(15, 1);
      dueFlashStorage.write(16, PWM_MaxSpeed_RH);    
      dueFlashStorage.write(94, 1);
      dueFlashStorage.write(95, PWM_Slow_Speed_LH);
      dueFlashStorage.write(96, 1);
      dueFlashStorage.write(97, PWM_Slow_Speed_RH);   
      dueFlashStorage.write(98, 1);
      dueFlashStorage.write(99, ((Slow_Speed_MAG * -1 ) / 10));   
      Serial.println(F("Saved to dueFlashStorage"));
      #endif


       #if defined(BOARD_MEGA)
      EEPROM.write(13, 1);
      EEPROM.write(14, PWM_MaxSpeed_LH);
      EEPROM.write(15, 1);
      EEPROM.write(16, PWM_MaxSpeed_RH);    
      EEPROM.write(94, 1);
      EEPROM.write(95, PWM_Slow_Speed_LH);
      EEPROM.write(96, 1);
      EEPROM.write(97, PWM_Slow_Speed_RH);   
      EEPROM.write(98, 1);
      EEPROM.write(99, ((Slow_Speed_MAG * -1 ) / 10));
      EEPROM.write(123, 1);
	  EEPROM.write(124, Wheels_Activate);
      Serial.println(F("Saved to EEPROM"));
      #endif

      
      Serial.println(F(" "));
  }

  
// Receive the Mower Motor Values Back again
  if (TFT_Menu_Command == 915) {
      Serial.println(F("Receiving Blade Motor Values from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      PWM_Blade_Speed           = Data1;
      Cutting_Blades_Activate   = Data2;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;   
      Serial.print(F("Blade Motor PWM = "));
      Serial.println(PWM_Blade_Speed);
      Serial.print(F("Cutting Blade Activated = "));
      Serial.println(Cutting_Blades_Activate);

      #if defined(BOARD_DUE)
      dueFlashStorage.write(17, 1);
      dueFlashStorage.write(18, PWM_Blade_Speed);   
      dueFlashStorage.write(83 , 1);
      dueFlashStorage.write(84 , Cutting_Blades_Activate);
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      EEPROM.write(17, 1);
      EEPROM.write(18, PWM_Blade_Speed);   
      EEPROM.write(83 , 1);
      EEPROM.write(84 , Cutting_Blades_Activate);
      Serial.println(F("Saved to EEPROM"));
      #endif
      
      Serial.println(F(" "));
  }



// Receive Movement Values from TFT
  if (TFT_Menu_Command == 916) {
      Serial.println(F("Receiving Movement Values from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Max_Cycles_Straight    = Data1;
      Mower_Turn_Delay_Min   = Data2;
      Mower_Turn_Delay_Max   = Data3;
      Mower_Reverse_Delay    = Data4;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;   
      Serial.print(F("Max Mow Length = "));
      Max_Cycles_Straight = Max_Cycles_Straight * 10;
      Serial.println(Max_Cycles_Straight);    
      Serial.print(F("Turn Angle Min = "));
      Mower_Turn_Delay_Min = Mower_Turn_Delay_Min * 100;
      Serial.println(Mower_Turn_Delay_Min);
      Serial.print(F("Turn Angle Max = "));
      Mower_Turn_Delay_Max = Mower_Turn_Delay_Max * 100;
      Serial.println(Mower_Turn_Delay_Max);
      Serial.print(F("Reverse Distance = "));
      Mower_Reverse_Delay = Mower_Reverse_Delay * 100;
      Serial.println(Mower_Reverse_Delay);

      #if defined(BOARD_DUE)
      //dueFlashStorage
      dueFlashStorage.write(57, 1);
      dueFlashStorage.write(58, (Max_Cycles_Straight / 10));
      dueFlashStorage.write(31, 1);
      dueFlashStorage.write(32, (Mower_Turn_Delay_Min/100));
      dueFlashStorage.write(33, 1);
      dueFlashStorage.write(34, (Mower_Turn_Delay_Max/100));
      dueFlashStorage.write(35, 1);
      dueFlashStorage.write(36, (Mower_Reverse_Delay/100));
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      //EEPROM
      EEPROM.write(57, 1);
      EEPROM.write(58, (Max_Cycles_Straight / 10));
      EEPROM.write(31, 1);
      EEPROM.write(32, (Mower_Turn_Delay_Min/100));
      EEPROM.write(33, 1);
      EEPROM.write(34, (Mower_Turn_Delay_Max/100));
      EEPROM.write(35, 1);
      EEPROM.write(36, (Mower_Reverse_Delay/100));
      Serial.println(F("Saved to EEPROM"));
      #endif

      
      Serial.println(F(" "));
  }



// Receive the Mower Motor Values Back again
  if (TFT_Menu_Command == 917) {
      Serial.println(F("Receiving Track Exit Values from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Track_Wire_Zone_1_Cycles  = Data1 * 100;
      Track_Wire_Zone_2_Cycles  = Data2 * 100;
      CCW_Tracking_To_Start     = Data3;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;  
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

      #if defined(BOARD_DUE)
      //dueFlashStorage
      dueFlashStorage.write(43, 1);
      dueFlashStorage.write(44, (Track_Wire_Zone_1_Cycles/100));
      dueFlashStorage.write(45, 1);
      dueFlashStorage.write(46, (Track_Wire_Zone_2_Cycles/100));
      dueFlashStorage.write(49 , 1);
      dueFlashStorage.write(50 , CW_Tracking_To_Charge);                
      dueFlashStorage.write(51 , 1);
      dueFlashStorage.write(52 , CCW_Tracking_To_Charge);       
      dueFlashStorage.write(53 , 1);
      dueFlashStorage.write(54 , CW_Tracking_To_Start);                
      dueFlashStorage.write(55 , 1);
      dueFlashStorage.write(56 , CCW_Tracking_To_Start);  
      Serial.println(F("Saved to dueFlashStorage"));
      #endif


      #if defined(BOARD_MEGA)
      //EEPROM
      EEPROM.write(43, 1);
      EEPROM.write(44, (Track_Wire_Zone_1_Cycles/100));
      EEPROM.write(45, 1);
      EEPROM.write(46, (Track_Wire_Zone_2_Cycles/100));
      EEPROM.write(49 , 1);
      EEPROM.write(50 , CW_Tracking_To_Charge);                
      EEPROM.write(51 , 1);
      EEPROM.write(52 , CCW_Tracking_To_Charge);       
      EEPROM.write(53 , 1);
      EEPROM.write(54 , CW_Tracking_To_Start);                
      EEPROM.write(55 , 1);
      EEPROM.write(56 , CCW_Tracking_To_Start);  
      Serial.println(F("Saved to EEPROM"));
      #endif

      
      Serial.println(F(" "));
  }


// Receive the Mower Motor Values Back again
  if (TFT_Menu_Command == 918) {
      Serial.println(F("Receiving Find Wire Values from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Max_Cycle_Wire_Find       = Data1 * 100;
      Max_Cycle_Wire_Find_Back  = Data2 * 10;
      Home_Wire_Compass_Heading = Data3;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;   
      Serial.print(F("Wire Find Forwards / Cycles = "));
      Serial.println(Max_Cycle_Wire_Find);
      Serial.print(F("Wire Find Forwards / Cycles = "));
      Serial.println(Max_Cycle_Wire_Find_Back);    
      Serial.print(F("Home Compass Heading / degrees "));
      Serial.println(Home_Wire_Compass_Heading);  

       #if defined(BOARD_DUE)
      // dueFlashStorage
      dueFlashStorage.write(69, 1);
      dueFlashStorage.write(70, (Max_Cycle_Wire_Find/10));
      dueFlashStorage.write(71, 1);
      dueFlashStorage.write(72, (Max_Cycle_Wire_Find_Back/10));
      dueFlashStorage.write(27, 1);
      dueFlashStorage.write(28, (Home_Wire_Compass_Heading/10));   
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

       #if defined(BOARD_MEGA)
      // EEPROM
      EEPROM.write(69, 1);
      EEPROM.write(70, (Max_Cycle_Wire_Find/10));
      EEPROM.write(71, 1);
      EEPROM.write(72, (Max_Cycle_Wire_Find_Back/10));
      EEPROM.write(27, 1);
      EEPROM.write(28, (Home_Wire_Compass_Heading/10));   
      Serial.println(F("Saved to EEPROM"));
      #endif

      
      Serial.println(F(" "));
  }


// Charging Station Options
  if (TFT_Menu_Command == 98) {
      Serial.println(F("Charging Station"));
      Receive_7_Data_Sets_Serial3();
      Use_Charging_Station = Data1;
      Data2 = 0;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("Use Charging Station = "));
      Serial.println(Use_Charging_Station);   

      #if defined(BOARD_DUE)
      // dueFlashStorage
      dueFlashStorage.write(47 , 1);
      dueFlashStorage.write(48 , Use_Charging_Station);
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      // EEPROM
      EEPROM.write(47 , 1);
      EEPROM.write(48 , Use_Charging_Station);
      Serial.println(F("Saved to EEPROM"));
      #endif

      
      Serial.println(F(" "));
      }



// Receive the Mower Start Conditions from the TFT Screen
  if (TFT_Menu_Command == 93) {
      Serial.println(F("RX Mower Exit Dock Start"));
      Receive_7_Data_Sets_Serial3();
      Exit_Zone     = Data1;
      Mow_Time_Set  = Data2;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("Exit Zone Selected = "));
      Serial.println(Exit_Zone);
      Serial.print(F("Mow Time Selected = "));
      if ( (Mow_Time_Set == 1) || (Mow_Time_Set == 2 ) ){
          Serial.print(Mow_Time_Set);
          Serial.println(F(" hrs"));
          }
      if (Mow_Time_Set == 3) Serial.println(F("Max Mow Time"));
      Serial.println(F(" "));

    if (Exit_Zone == 1) Track_Wire_Itterations = Track_Wire_Zone_1_Cycles;
    if (Exit_Zone == 2) Track_Wire_Itterations = Track_Wire_Zone_2_Cycles;
    if (Exit_Zone == 3) {
      Track_Wire_Itterations = Track_Wire_Zone_2_Cycles;
      Blade_Override = 1;
    }


    if (Mow_Time_Set ==3) Alarm_Timed_Mow_ON = 0;
    if (Mow_Time_Set < 3) {
        if (PCB == 0) {
          Time t = rtc.time();
          }
        if (PCB == 1) Display_DS3231_Time();
        Alarm_Timed_Mow_ON = 1;                          // Activate the Mow Timer Alarm
        Alarm_Timed_Mow_Hour = Time_Hour +  Mow_Time_Set;     // Sets time to (+Mow_Time_Set 1 or 2 )hour later.
        Alarm_Timed_Mow_Minute = Time_Minute;                  // Minutes are the same
        }
    
    TFT_Menu_Command = 1; 

    Serial.println("In TFT RX Function");
    Check_Mower_Status();
    Manouver_Exit_To_Zone_X();                           // Exit the Dock                
    }


// Receive PID Values
  if (TFT_Menu_Command == 919) {
      Serial.println(F("RX PID Values from TFT"));
      Receive_7_Data_Sets_Serial3();
      Max_Tracking_Turn_Left  = Data1 * 10;
      Max_Tracking_Turn_Right = Data2 * 10;
      P                       = Data3;
      P                       = P / 100;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("Max Cycles Left Wheel = "));
      Serial.println(Max_Tracking_Turn_Left);      
      Serial.print(F("Max Cycles Right Wheel = "));
      Serial.println(Max_Tracking_Turn_Right);               
      Serial.print(F("PID P = "));
      Serial.println(P);
      
      #if defined(BOARD_DUE)
      // dueFlashStorage
      dueFlashStorage.write(73, 1);
      dueFlashStorage.write(74, (Max_Tracking_Turn_Right/10));
      dueFlashStorage.write(75, 1);
      dueFlashStorage.write(76, (Max_Tracking_Turn_Left/10));
      dueFlashStorage.write(21, 1);
      dueFlashStorage.write(22, (P*100));  
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      // EEPROM
      EEPROM.write(73, 1);
      EEPROM.write(74, (Max_Tracking_Turn_Right/10));
      EEPROM.write(75, 1);
      EEPROM.write(76, (Max_Tracking_Turn_Left/10));
      EEPROM.write(21, 1);
      EEPROM.write(22, (P*100));  
      Serial.println(F("Saved to EEPROM"));
      #endif

      
      Serial.println(F(" "));
      }


// Receive the Compass data from TFT
  if (TFT_Menu_Command == 926) {
      Serial.println(F("RX Compass from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Compass_Activate              = Data1;
      Compass_Heading_Hold_Enabled  = Data2;
      CPower                        = Data3;
      CPower                        = CPower / 10;
      Compass_Setup_Mode            = Data4;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("Compass Activated = "));
      Serial.println(Compass_Activate);
      Serial.print(F("Heading Hold Enabled = "));
      Serial.println(Compass_Heading_Hold_Enabled);        
      Serial.print(F("Compass Power = "));
      Serial.println(CPower);
      Serial.print(F("Compas Setup Mode = "));
      Serial.println(Compass_Setup_Mode); 

      #if defined(BOARD_DUE)
      // dueFlashStorage
      dueFlashStorage.write(19 , 1);
      dueFlashStorage.write(20 , Compass_Activate);
      dueFlashStorage.write(59 , 1);
      dueFlashStorage.write(60 , Compass_Heading_Hold_Enabled);
      dueFlashStorage.write(61, 1);
      dueFlashStorage.write(62, (CPower*10)); 
      dueFlashStorage.write(113, 1);
      dueFlashStorage.write(114, Compass_Setup_Mode); 
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      // EEPROM
      EEPROM.write(19 , 1);
      EEPROM.write(20 , Compass_Activate);
      EEPROM.write(59 , 1);
      EEPROM.write(60 , Compass_Heading_Hold_Enabled);
      EEPROM.write(61, 1);
      EEPROM.write(62, (CPower*10)); 
      EEPROM.write(113, 1);
      EEPROM.write(114, Compass_Setup_Mode); 
      Serial.println(F("Saved to EEPROM"));
      #endif
      
      Serial.println(F(" "));
      }


// Receive the Compass data from TFT
  if (TFT_Menu_Command == 927) {
      Serial.println(F("RX Compass from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      GPS_Enabled                   = Data1;
      GPS_Type                      = Data2;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("GPS: "));
        if (GPS_Enabled == 1) Serial.println("ON");
        if (GPS_Enabled == 0) Serial.println("OFF");    
      Serial.print(F("GPS Type: "));
        if (GPS_Type == 1) Serial.println("ReP_AL");
        if (GPS_Type == 2) {
          Serial.println("PIXHAWK");    
          Setup_PIXHAWK();
          }
        if (GPS_Type == 3) Serial.println("Spare");   

        

      #if defined(BOARD_DUE)
      // dueFlashStorage
      dueFlashStorage.write(107 , 1);
      dueFlashStorage.write(108 , GPS_Enabled);
      dueFlashStorage.write(125 , 1);
      dueFlashStorage.write(126 , GPS_Type);
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      // EEPROM
      EEPROM.write(107 , 1);
      EEPROM.write(108 , GPS_Enabled);
      EEPROM.write(125 , 1);
      EEPROM.write(126 , GPS_Type);
      Serial.println(F("Saved to EEPROM"));
      #endif
      
      Serial.println(F(" "));
      }



// Receive the GYRO data from TFT
  if (TFT_Menu_Command == 928) {
      Serial.println(F("RX GYRO from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      GYRO_Enabled  = Data1;
      GPower        = Data2;
      GPower        = GPower / 10;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("GYRO Enabled = "));
      Serial.println(GYRO_Enabled);
      Serial.print(F("GYRO Power = "));
      Serial.println(GPower);      
      if (GYRO_Enabled == 1) Setup_Gyro();

      #if defined(BOARD_DUE)
      dueFlashStorage.write(109 , 1);
      dueFlashStorage.write(110, GYRO_Enabled);
      dueFlashStorage.write(111, 1);
      dueFlashStorage.write(112, (GPower*10)); 
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      EEPROM.write(109 , 1);
      EEPROM.write(110, GYRO_Enabled);
      EEPROM.write(111, 1);
      EEPROM.write(112, (GPower*10)); 
      Serial.println(F("Saved to EEPROM"));
      #endif
      
      Serial.println(F(" ")); 
      }



// Receive the Time Alarm data from TFT
  if (TFT_Menu_Command == 920) {
      Serial.println(F("RX Alarm 1 TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Alarm_1_ON     = Data1;
      Alarm_1_Hour   = Data2;
      Alarm_1_Minute = Data3;
      Alarm_1_Repeat = Data4;
      Alarm_1_Action = Data5;
      Data6 = 0;
      Data7 = 0; 
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

      #if defined(BOARD_DUE)
      //dueFlashStorage
      dueFlashStorage.write(1, 1);
      dueFlashStorage.write(2, Alarm_1_Hour);
      dueFlashStorage.write(3, Alarm_1_Minute);
      dueFlashStorage.write(4, Alarm_1_ON);
      dueFlashStorage.write(87, Alarm_1_Action);
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      //EEPROM
      EEPROM.write(1, 1);
      EEPROM.write(2, Alarm_1_Hour);
      EEPROM.write(3, Alarm_1_Minute);
      EEPROM.write(4, Alarm_1_ON);
      EEPROM.write(87, Alarm_1_Action);
      Serial.println(F("Saved to EEPROM"));
      #endif
      
      Serial.println(F(" "));    
  }




// Receive the Alarm 2 data from TFT
  if (TFT_Menu_Command == 921) {
      Serial.println(F("RX Alarm 2 TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Alarm_2_ON     = Data1;
      Alarm_2_Hour   = Data2;
      Alarm_2_Minute = Data3;
      Alarm_2_Repeat = Data4;
      Alarm_2_Action = Data5;
      Data6 = 0;
      Data7 = 0; 
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

      #if defined(BOARD_DUE)
      //dueFlashStorage
      dueFlashStorage.write(5, 1);
      dueFlashStorage.write(6, Alarm_2_Hour);
      dueFlashStorage.write(7, Alarm_2_Minute);
      dueFlashStorage.write(8, Alarm_2_ON);
      dueFlashStorage.write(88, Alarm_2_Action);
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      //EEPROM
      EEPROM.write(5, 1);
      EEPROM.write(6, Alarm_2_Hour);
      EEPROM.write(7, Alarm_2_Minute);
      EEPROM.write(8, Alarm_2_ON);
      EEPROM.write(88, Alarm_2_Action);
      Serial.println(F("Saved to EEPROM"));
      #endif

      
      Serial.println(F(" "));    
      }


// Receive the Alarm 3 data from TFT
  if (TFT_Menu_Command == 922) {
      Serial.println(F("RX Alarm 3 TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Alarm_3_ON     = Data1;
      Alarm_3_Hour   = Data2;
      Alarm_3_Minute = Data3;
      Alarm_3_Repeat = Data4;
      Alarm_3_Action = Data5;
      Data6 = 0;
      Data7 = 0; 
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

      #if defined(BOARD_DUE)
      //dueFlashStorage
      dueFlashStorage.write(9, 1);
      dueFlashStorage.write(10, Alarm_3_Hour);
      dueFlashStorage.write(11, Alarm_3_Minute);
      dueFlashStorage.write(12, Alarm_3_ON);
      dueFlashStorage.write(89, Alarm_3_Action);
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      //EEPROM
      EEPROM.write(9, 1);
      EEPROM.write(10, Alarm_3_Hour);
      EEPROM.write(11, Alarm_3_Minute);
      EEPROM.write(12, Alarm_3_ON);
      EEPROM.write(89, Alarm_3_Action);
      Serial.println(F("Saved to EEPROM"));
      #endif
      
      Serial.println(F(" "));    
      }



// Receive the Time data from TFT
  if (TFT_Menu_Command == 923) {
      Serial.println(F("RX DateTime from TFT ..."));
      String Serial3_RX_Value  = "";          
      int set_hour;
      int set_min;
      int set_year;
      int set_month;
      int set_date;
      int set_day;
      Receive_7_Data_Sets_Serial3();
      set_hour   = Data1;
      set_min    = Data2;
      set_year   = Data3;
      set_month  = Data4;
      set_date   = Data5;
      set_day    = Data6;
      Data7 = 0; 

       if (PCB == 0) {           
          rtc.writeProtect(false);
          rtc.halt(false);
          /*
          Serial.print(F("Clock: "));
          Serial.print(set_hour);
          Serial.print(":");
          if (set_min < 10) Serial.print("0");
          Serial.println(set_min);
          Serial.print(F("Date: "));
		  Serial.print(set_year);
		  Serial.print("-");
		  if (set_month < 10) Serial.print("0");
		  Serial.print(set_month);
		  Serial.print("-");
		  if (set_date < 10) Serial.print("0");
		  Serial.print(set_date);
		  Serial.print(F(" "));
	      char buf[15];
	      const String day = dayAsString((Time::Day)set_day);
	      snprintf(buf, sizeof(buf), " %s", day.c_str());
		  Serial.println(buf);
*/
          PrintTimeToSerial(2, set_year, set_month, set_date, set_hour, set_min, 00, set_day, 1);

          Time t(set_year, set_month, set_date, set_hour, set_min, 00, (Time::Day)set_day);            // Year XXXX, Month XX, Day XX, Hour XX, Minute XX, Second, kXYZday
          rtc.time(t);    
          delay(200);
          rtc.writeProtect(true);
          rtc.halt(true);
          rtc.time(t); 
          }

      if (PCB == 1) {
          Set_DS3231_Time(00,set_min, set_hour, set_day, set_date, set_month, set_year);    //second, minute, hour, dayof week, day of month, month, year
          Serial.println(F("TIME SAVED"));
          delay(2000);
          }
  
  }



  if (TFT_Menu_Command == 929) {
        Serial.println(F("RX Wheel Block"));                               
        Receive_7_Data_Sets_Serial3();
        Wheel_Amp_Sensor_ON   = Data1;
        Max_Wheel_Amps        = Data2;                         // Directly place Data 2 into value to ensure float is not lost
        Max_Wheel_Amps        = Max_Wheel_Amps / 100;
        Data3 = 0;
        Data4 = 0;
        Data5 = 0;
        Data6 = 0;
        Data7 = 0;   
        Serial.print(F("Wheel Amp ON: "));
        if (Wheel_Amp_Sensor_ON == 1) Serial.println(F("ON"));
        if (Wheel_Amp_Sensor_ON == 0) Serial.println(F("OFF"));   
        Serial.print(F("Wheel Amps Max: "));
        Serial.print(Max_Wheel_Amps);

        #if defined(BOARD_DUE)
        //dueFlashStorage Saved Values
        dueFlashStorage.write(115, 1);
        dueFlashStorage.write(116, Wheel_Amp_Sensor_ON);
        dueFlashStorage.write(117, 1);
        dueFlashStorage.write(118, Max_Wheel_Amps * 10);
        Serial.println(F("Saved to dueFlashStorage"));
        #endif

        #if defined(BOARD_MEGA)
        //EEPROM Saved Values
        EEPROM.write(115, 1);
        EEPROM.write(116, Wheel_Amp_Sensor_ON);
        EEPROM.write(117, 1);
        EEPROM.write(118, Max_Wheel_Amps * 10);
        Serial.println(F("Saved to EEPROM"));
        #endif
        
        Serial.println(F(" "));  
       }


  if (TFT_Menu_Command == 924) {
      Serial.println(F("RX Tip from TFT ..."));                               
      Receive_7_Data_Sets_Serial3();
      Angle_Sensor_Enabled    = Data1;
      Tip_Over_Sensor_Enabled = Data2;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;   
      Serial.print(F("Tilt Angle Sensor = "));
      Serial.println(Angle_Sensor_Enabled);
      Serial.print(F("Tip Over Sensor = "));
      Serial.println(Tip_Over_Sensor_Enabled);
      Serial.println(F(" "));
      
      #if defined(BOARD_DUE)
      //dueFlashStorage Saved Values
      dueFlashStorage.write(29, 1);
      dueFlashStorage.write(30, Angle_Sensor_Enabled);
      dueFlashStorage.write(92, 1);
      dueFlashStorage.write(93, Tip_Over_Sensor_Enabled);
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      //EEPROM Saved Values
      EEPROM.write(29, 1);
      EEPROM.write(30, Angle_Sensor_Enabled);
      EEPROM.write(92, 1);
      EEPROM.write(93, Tip_Over_Sensor_Enabled);
      Serial.println(F("Saved to EEPROM"));
      #endif
      
      Serial.println(F(" "));  
      }



// Receive the Pattern Values Back again
  if (TFT_Menu_Command == 925) {
      Serial.println(F("RX Pattern from TFT"));
      Receive_7_Data_Sets_Serial3();
      Pattern_Mow             = Data1;
      Turn_90_Delay_LH        = Data2 * 10;
      Turn_90_Delay_RH        = Data3 * 10;
      Move_to_next_line_delay = Data4 * 10;
      Line_Length_Cycles      = Data5;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("Pattern Mow: "));
      if (Pattern_Mow == 0) Serial.println(F("OFF"));
      if (Pattern_Mow == 1) Serial.println(F("Parallel"));  
      if (Pattern_Mow == 2) Serial.println(F("Spiral"));      
      Serial.print(F("Turn 90° LH= "));
      Serial.println(Turn_90_Delay_LH);
      Serial.print(F("Turn 90° RH= "));
      Serial.println(Turn_90_Delay_RH);
      Serial.print(F("Distance to next row= "));
      Serial.println(Move_to_next_line_delay);          
      Serial.print(F("Line_Length_Cycles= "));
      Serial.println(Line_Length_Cycles); 
      
      #if defined(BOARD_DUE)
      //dueFlashStorage Saved Values
      dueFlashStorage.write(23, 1);
      dueFlashStorage.write(24, Pattern_Mow);
      dueFlashStorage.write(101, 1);
      dueFlashStorage.write(102, Turn_90_Delay_LH / 10);
      dueFlashStorage.write(103, 1);
      dueFlashStorage.write(104, Turn_90_Delay_RH / 10);
      dueFlashStorage.write(105, 1);
      dueFlashStorage.write(106, Line_Length_Cycles / 10);
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      //EEPROM Saved Values
      EEPROM.write(23, 1);
      EEPROM.write(24, Pattern_Mow);
      EEPROM.write(101, 1);
      EEPROM.write(102, Turn_90_Delay_LH / 10);
      EEPROM.write(103, 1);
      EEPROM.write(104, Turn_90_Delay_RH / 10);
      EEPROM.write(105, 1);
      EEPROM.write(106, Line_Length_Cycles / 10);
      Serial.println(F("Saved to EEPROM"));
      #endif

      
      Serial.println(F(" "));  
  }



// Receive the Other SETUP Values from the TFT
  if (TFT_Menu_Command == 930) {
      Serial.println(F("RX PCB from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      PCB               = Data1;
      Robot_Type        = Data2;
      int Clear_EEPROM  = Data3;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("PCB = "));
      if (PCB == 1) Serial.println(F("Enabled"));
      if (PCB == 0) Serial.println(F("Disabled"));
      if (Robot_Type == 1) Serial.println(F("Robot = Mower"));
      if (Robot_Type == 2) Serial.println(F("Robot = Aerator"));
     
      
      #if defined(BOARD_DUE)
      // dueFlashStorage
      dueFlashStorage.write(119 , 1);
      dueFlashStorage.write(120, PCB);      
      dueFlashStorage.write(121 , 1);
      dueFlashStorage.write(122, Robot_Type);     
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      // EEPROM      
      EEPROM.write(119 , 1);
      EEPROM.write(120, PCB);      
      EEPROM.write(121 , 1);
      EEPROM.write(122, Robot_Type);    
      Serial.println(F("Saved to EEPROM"));
      #endif
      
      Serial.println(F(" "));

      if (Clear_EEPROM == 5) {
        Serial.println(F(""));
        Serial.println(F(""));
        Serial.println(F("CLEARING ALL EEPROM MEGA SETTINGS"));
        Serial.println(F(""));
        Serial.println(F(""));
        Clear_EERPOM_Data();
        Clear_EEPROM = 0;
      }
      
      Serial.println(F(" "));

}



// Receive the Navigation data from TFT
  if (TFT_Menu_Command == 299) {
      Serial.println(F("Receiving Navigation Values from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      GPS_Enabled             = Data1;
      Data2 = 0;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("GPS Enabled = "));
      Serial.println(GPS_Enabled);
      if ((GPS_Enabled == 1) && (GPS_Type == 1)) Setup_ADCMan();
      if ((GPS_Enabled == 1) && (GPS_Type == 2)) Setup_PIXHAWK();
      Serial.println(" ");
      
      #if defined(BOARD_DUE)
      // dueFlashStorage
      dueFlashStorage.write(107 , 1);
      dueFlashStorage.write(108, GPS_Enabled);     
      Serial.println(F("Saved to dueFlashStorage"));
      #endif

      #if defined(BOARD_MEGA)
      // EEPROM
      EEPROM.write(107 , 1);
      EEPROM.write(108, GPS_Enabled);     
      Serial.println(F("Saved to EEPROM"));
      #endif
      
      Serial.println(F(" "));
      }
  

// Receive the Mower Start Conditions from the TFT Screen
  if (TFT_Menu_Command == 92) {
      Serial.println(F("RX Mower Start Values"));
      Receive_7_Data_Sets_Serial3();
      Mow_Time_Set = Data1;
      Data2 = 0;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.println(F("Quick Start Selected"));
      Serial.print(F("Mow Time Selected = "));
      if ( (Mow_Time_Set == 1) || (Mow_Time_Set == 2 ) ){
          Serial.print(Mow_Time_Set);
          Serial.println(" hrs");
          }
      if (Mow_Time_Set == 3) Serial.println(F("Max Mow Time"));

      Serial.println(F(" "));

    if (Mow_Time_Set == 3) Alarm_Timed_Mow_ON = 0;
    if (Mow_Time_Set < 3) {
        if (PCB == 0) {Time t = rtc.time();}
        if (PCB == 1) Display_DS3231_Time();
        Alarm_Timed_Mow_ON = 1;                          // Activate the Mow Timer Alarm
        Alarm_Timed_Mow_Hour = Time_Hour +  Mow_Time_Set;     // Sets time to (+Mow_Time_Set 1 or 2 )hour later.
        Alarm_Timed_Mow_Minute = Time_Minute;                  // Minutes are the same
        }
           
    Serial.print(F("Mow Time Ends: "));
    if (Alarm_Timed_Mow_Hour > 23) Alarm_Timed_Mow_Hour = Alarm_Timed_Mow_Hour - 24;
    if (Alarm_Timed_Mow_Hour < 10) Serial.print(F("0"));
    Serial.print(Alarm_Timed_Mow_Hour);
    Serial.print(F(":"));
    if (Alarm_Timed_Mow_Minute < 10) Serial.print(F("0"));
    Serial.print(Alarm_Timed_Mow_Minute);       
    
    TFT_Menu_Command = 1; 
    Manouver_Start_Mower();                              // Quick Start
                        
    }

// Receive the Mower Conditions from the TFT Screen after Goto Dock 
// is pressed

  if (TFT_Menu_Command == 94) {
      Serial.println(F("TFT Says Go To Dock"));
      delay(1100);
      String Serial3_RX_Value  = "";                                              
      TFT_Menu_Command = 1; 
      Mower_Parked  = 0;  
      Mower_Running = 1;                              // As the TFT Menu is only hiding the running status in the background.
      Check_Mower_Status();
      if (Use_Charging_Station == 1) Manouver_Go_To_Charging_Station();  // Go to Dock                     
      }




// Start Relay Test
  if (TFT_Menu_Command == 42) {
    Serial.println(F("Running Relay Test"));
    Test_Relay();
    }

// Start Wheel Motor Test
  if (TFT_Menu_Command == 43) {
    Serial.println(F("Running Wheel Test"));
    Test_Wheel_Motors();

    }

// Start Wheel Amp Test
  if (TFT_Menu_Command == 38) {
    Serial.println(F("Running Wheel Amp Test"));
    Test_Wheel_Amps();
    }

// Start Motor Test
  if (TFT_Menu_Command == 44) {
    
    if (Robot_Type == 1) {
      Serial.println(F("Running Blade Motor Test"));
      Test_Mower_Blade_Motor();
      }
    
    if (Robot_Type == 2) {
      Serial.println(F("Running Drill Motor Test"));
      Turn_On_Relay();
      delay(7000);
      Motor_Action_Spin_Drill();
      Drill_ON = 1;
      delay(3000);
      Motor_Action_Stop_Drill();      
      delay(1000);
      Turn_Off_Relay();
      Drill_ON = 0;
      }
   
    }


// Lift Mechanisam Up
  if (TFT_Menu_Command == 60) {
      Serial.println(F("Lift Mechanism Up 10mm"));
    Setup_Microswitches();
    int cycles = 0;
    bool Stop = 0;
    Turn_On_Relay();
    delay(2000);
    Check_End_Stops();

  
   while ((End_Stop_Upper == false) && (cycles < 1000) && (Stop == 0)) {
      Spikes_Up();      
      Check_End_Stops();
      cycles ++;
      Serial.print("Cycles:");
      Serial.println(cycles);
      Check_Serial_Input();
      if (Command == 32) Stop = 1;
      }
    
    Command = 0;
    Motor_Action_Stop_Spikes();
    Turn_Off_Relay();
    }

// Lift Mechanisam Up
  if (TFT_Menu_Command == 61) {
    Serial.println(F("Lift Mechanism Down 10mm"));
    Setup_Microswitches();
    
    int cycles = 0;
    bool Stop = 0;
    
    Turn_On_Relay();
    delay(2000);
    Check_End_Stops();

    //1200 Cycles is full
      
    while ((End_Stop_Lower == false) && (cycles < 1000) && (Stop == 0)) {
      Spikes_Down();      
      Check_End_Stops();
      cycles ++;
      Serial.print("Cycles:");
      Serial.println(cycles);
      Check_Serial_Input();
      if (Command == 32) Stop = 1;
      }
    
    Command = 0;
    Motor_Action_Stop_Spikes();
    Turn_Off_Relay();
    }
      

// Test Drill Cycle
  if (TFT_Menu_Command == 62) {  
    Initiate_Drill_Cycle();
    Turn_Off_Relay();  
  }
  


// PIXHAWK Wheel Motor Test
  if (TFT_Menu_Command == 64) {
    Serial.println(F("PIXHAWK Motor Test"));

    Pixhawk_Motor_Test_Initiate = 0;
    Turn_On_Relay();
    SetPins_ToGoForwards();
    delay(1000);
    cycles = 0;

      
    while (cycles < 500) {
      cycles ++;
      Serial.print("Cycles:");
      Serial.print(cycles);  
      Serial.print(" | ");
      Check_PIXHAWK_PWM();
      Send_PIXHAWK_Running_Data();    
      Serial.println("");    
      }

    Serial.println(F("Test Completed"));
    Turn_Off_Relay();
    Command = 0;
    }

// PIXHAWK Disarm
  if (TFT_Menu_Command == 31) {
    Serial.println("");
    Serial.println(F("Mower set to PIXHAWK Mode"));
    Serial.println("");
    Mower_Docked = 0;
    Mower_PIXHAWK = 1; 
  }


// PIXHAWK Disarm
  if (TFT_Menu_Command == 74) {
    Serial.println("");
    Serial.println("DIS-ARMING PIXHAWK");
    Serial.println("");
    Command_long_Disarm();    
  }


// PIXHAWK ARM
  if (TFT_Menu_Command == 75) {
    Serial.println("");
    Serial.println("ARMING PIXHAWK");
    Serial.println("");
    Command_long_ARM();    
  }

// PIXHAWK Guided
  if (TFT_Menu_Command == 76) {
    Serial.println("");
    Serial.println("PIXHAWK - Guided");
    Serial.println("");
    Guided_Mode();   
  }

// PIXHAWK Auto
  if (TFT_Menu_Command == 77) {
    Serial.println("");
    Serial.println("PIXHAWK - Auto");
    Serial.println("");
    Auto_Mode();    
  }

// PIXHAWK Acro
  if (TFT_Menu_Command == 78) {
    Serial.println("");
    Serial.println("PIXHAWK - Acro");
    Serial.println("");
    Acro_Mode();    
  }

// PIXHAWK EXIT
  if (TFT_Menu_Command == 79) {
    Serial.println("");
    Serial.println("EXIT PIXHAWK Mode");
    Command_long_Disarm();
    Turn_Off_Relay();
    Serial.println(F("Mower set to ReP_AL Mode"));
    Serial.println("");
    Mower_Docked = 1;
    Mower_PIXHAWK = 0; 
    Serial.println("");

  }
  
// Receive the Stop Mower Command Red Button
  if (TFT_Menu_Command == 13) {
      Manouver_Park_The_Mower();
      TFT_Menu_Command = 1;
      if (Robot_Type == 2) Stop = 1;   // Aborts the drill sequence
      }



// Receive the Mower Start Conditions from the TFT Screen
  if (TFT_Menu_Command == 49) {
      Serial.println(F("TFT Says Go To Dock"));
      delay(1100);
      String Serial3_RX_Value  = "";                                              
    TFT_Menu_Command = 1; 
    if (Use_Charging_Station == 1) Manouver_Go_To_Charging_Station();  // Go to Dock
                        
    }

// Test Left Front Wheel Forwards Motion
  if (TFT_Menu_Command == 66) {
    Serial.println(F("LH Front Wheel FWD"));
    Turn_On_Relay();
    Motor_Action_Stop_Motors();
    Set_Mecanum_Forwards_Left_Front();
    Full_Speed_Mecanum_Left_Front();
    delay(2000);
    Motor_Action_Stop_Motors();  
    }


// Test Left Front Wheel backwards Motion
  if (TFT_Menu_Command == 67) {
    Serial.println(F("LH Front Wheel REV"));
    Turn_On_Relay();
    Motor_Action_Stop_Motors();
    Set_Mecanum_Backwards_Left_Front();
    Full_Speed_Mecanum_Left_Front();
    delay(2000);
    Motor_Action_Stop_Motors();  
    }

// Test Right Front Wheel Forwards Motion
  if (TFT_Menu_Command == 68) {
    Serial.println(F("RH Front Wheel FWD"));
    Turn_On_Relay();
    Motor_Action_Stop_Motors();
    Set_Mecanum_Forwards_Right_Front();
    Full_Speed_Mecanum_Right_Front();
    delay(2000);
    Motor_Action_Stop_Motors();  
    }


// Test Right Front Wheel backwards Motion
  if (TFT_Menu_Command == 69) {
    Serial.println(F("RH Front Wheel REV"));
    Turn_On_Relay();
    Motor_Action_Stop_Motors();
    Set_Mecanum_Backwards_Right_Front();
    Full_Speed_Mecanum_Right_Front();
    delay(2000);
    Motor_Action_Stop_Motors();  
    }


// Test Left Rear Wheel Forwards Motion
  if (TFT_Menu_Command == 70) {
    Serial.println(F("LH Rear Wheel FWD"));
    Turn_On_Relay();
    Motor_Action_Stop_Motors();
    
    if (Robot_Type == 1) {
      Set_Mower_Forwards_Left();
      Motor_Action_Go_Full_Speed();
      }   
    
    if (Robot_Type == 2) {
      Set_Mecanum_Forwards_Left_Rear();
      Full_Speed_Mecanum_Left_Rear();
      }
    delay(2000);
    Motor_Action_Stop_Motors();  
    }


// Test Left Rear Wheel Backwards Motion
  if (TFT_Menu_Command == 71) {
    Serial.println(F("LH Rear Wheel REV"));
    Turn_On_Relay();
    Motor_Action_Stop_Motors();
    
    if (Robot_Type == 1) {
      Set_Mower_Backwards_Left();
      Motor_Action_Go_Full_Speed();
      }   
    
    if (Robot_Type == 2) {
      Set_Mecanum_Backwards_Left_Rear();
      Full_Speed_Mecanum_Left_Rear();
      }
    delay(2000);
    Motor_Action_Stop_Motors();  
    }


// Test Right Rear Wheel Forwards Motion
  if (TFT_Menu_Command == 72) {
    Serial.println(F("RH Rear Wheel FWD"));
    Turn_On_Relay();
    Motor_Action_Stop_Motors();
    if (Robot_Type == 1) {
      Set_Mower_Forwards_Right();
      Motor_Action_Go_Full_Speed();
      }   
    
    if (Robot_Type == 2) {
      Set_Mecanum_Forwards_Right_Rear();
      Full_Speed_Mecanum_Right_Rear();
      }
    delay(2000);
    Motor_Action_Stop_Motors();  
    }


// Test Right Rear Wheel Backwards Motion
  if (TFT_Menu_Command == 73) {
    Serial.println(F("RH Rear Wheel REV"));
    Turn_On_Relay();
    Motor_Action_Stop_Motors();
    
    if (Robot_Type == 1) {
      Set_Mower_Backwards_Right();
      Motor_Action_Go_Full_Speed();
      }   
    if (Robot_Type == 2) {
      Set_Mecanum_Backwards_Right_Rear();
      Full_Speed_Mecanum_Right_Rear();
      }

    delay(2000);
    Motor_Action_Stop_Motors();  
    }

// Exit and turn off relay
  if (TFT_Menu_Command == 80) {
    Serial.println(F("Motor Test Finished"));
    Turn_Off_Relay();
    Motor_Action_Stop_Motors();  
    }


}



  

  
