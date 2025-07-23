// All the recieved information functions

void Receive_All_From_MEGA() {

  SerialDebug.print(F("|RX_MEGA:"));
  
  #if not defined(WEBSERVER)
  byte recvBuff [7] = {0};
  #else
  byte recvBuff [53] = {0};
  #endif // -(WEBSERVER)-

  int recvVal = 0;

	if (NodeMCUCom.update ()) {
  
	  byte length = NodeMCUCom.getLength ();
	  if (length > sizeof (recvBuff)) length = sizeof (recvBuff);
	  memcpy (&recvBuff, NodeMCUCom.getData (), length);

    Pattern_Mow = 0;
    
	  val_VoltNow                     = recvBuff[0] | recvBuff[1] << 8;
	  Loop_Cycle_Mowing               = recvBuff[2] | recvBuff[3] << 8;

	  Mower_Docked                    = bitRead(recvBuff[4],0);
	  Mower_Running                   = bitRead(recvBuff[4],1);
	  Mower_Parked                    = bitRead(recvBuff[4],2);
    Tracking_Wire                   = bitRead(recvBuff[4],3);
    Rain_Detected                   = bitRead(recvBuff[4],4);
    Wire_Detected                   = bitRead(recvBuff[4],5);
    Mower_Setup_Mode                = bitRead(recvBuff[4],6);   
	  Charge_Detected                 = recvBuff[5];
    Pattern_Mow                     = recvBuff[6];
    Pattern_Mow  = Pattern_Mow + 1;   // Adds 1 to the numbers as the Mower MEGA numbers are 0,1,2 for the pattern mdoes...
    

		#if defined(WEBSERVER)
		Mower_RunBack                   = recvBuff[12];
		Robot_Status_Value              = recvBuff[13];
		Mower_Error_Value               = recvBuff[14];
		Compass_Steering_Status         = recvBuff[15];
		int WheelAmpsRX                 = recvBuff[16] | recvBuff[17] << 8;
		WheelAmps                       = (float)WheelAmpsRX / 100;
		int Compass_Heading_DegreesRX   = recvBuff[18] | recvBuff[19] << 8;
		Compass_Heading_Degrees         = (float)Compass_Heading_DegreesRX;
		Manouver_Turn_Around_Phase      = recvBuff[20];
		Manouver_Turn_Around_Sonar_Phase= recvBuff[21];
		//reserve                       = recvBuff[22];
		PWM_Right                       = recvBuff[23];
		PWM_Left                        = recvBuff[24];
		int Compass_ErrorRX             = recvBuff[25] | recvBuff[26] << 8;
		Compass_Error                   = ((float)Compass_ErrorRX - 1000) / 100;
		int AmpsRX                      = (recvBuff[27] << 8) | recvBuff[28] ;
		Amps = ((float)AmpsRX - 1000) / 100;
		distance1                       = recvBuff[29] | recvBuff[30] << 8;
		distance2                       = recvBuff[31] | recvBuff[32] << 8;
		distance3                       = recvBuff[33] | recvBuff[34] << 8;
		
		Sonar_Status                    = bitRead(recvBuff[35],0);
		Outside_Wire                    = bitRead(recvBuff[35],1);
		Bumper                          = bitRead(recvBuff[35],2);
		Tilt_Angle_Sensed               = bitRead(recvBuff[35],3);
		GPS_Inside_Fence                = bitRead(recvBuff[35],4);
		Tilt_Orientation_Sensed         = bitRead(recvBuff[35],5);
		Wheel_Blocked_Status            = bitRead(recvBuff[35],6);
		Wheels_Activate                 = bitRead(recvBuff[35],7);
    
		Ramp_Motor_ON                   = bitRead(recvBuff[36],1);
		MAG_Speed_Adjustment            = bitRead(recvBuff[36],2);
		Perimeter_Wire_Enabled          = bitRead(recvBuff[36],3);
		Use_Charging_Station            = bitRead(recvBuff[36],4);
		Blade_flagRun                   = bitRead(recvBuff[36],5);
		Fake_All_Settings               = bitRead(recvBuff[36],6);
		Fake_Loops                      = bitRead(recvBuff[36],7);
    
		Fake_Wire                       = bitRead(recvBuff[37],1);
		Fake_WheelAmp                   = bitRead(recvBuff[37],2);
		// = bitRead(recvBuff[34],4);
		Time_Year                       = recvBuff[38] | recvBuff[39] << 8;
		Time_Month                      = recvBuff[40];
		Time_Date                       = recvBuff[41];
		Time_Hour                       = recvBuff[42];
		Time_Minute                     = recvBuff[43];
		Time_Second                     = recvBuff[44];
		Time_Day                        = recvBuff[45];
		Wheel_Status_Value              = recvBuff[46];
		MAG_Now                         = recvBuff[47] | recvBuff[48] << 8;
		Sonar_Hit_1_Total               = recvBuff[49];
		Sonar_Hit_2_Total               = recvBuff[50];
		Sonar_Hit_3_Total               = recvBuff[51];
		Low_Battery_Detected            = recvBuff[52];                                


    #endif // -(WEBSERVER)-
		RX_data_from_Mega_updated = true;
    SerialDebug.print(F("|RX_OK:"));
	  }                                                   // end if something received


    BatteryVoltage = val_VoltNow/100;
	  
	  if(RX_data_from_Mega_updated == true) {
        SerialDebug.print(F("|Time:"));
    		if (Time_Hour < 10) SerialDebug.print("0");
    		SerialDebug.print(Time_Hour);
    		SerialDebug.print(F(":"));
    		if (Time_Minute < 10) SerialDebug.print("0");
    		SerialDebug.print(Time_Minute);
    
        SerialDebug.print("|A:");
        SerialDebug.print(Amps);
    
        SerialDebug.print("|V:");
        SerialDebug.print(BatteryVoltage);
        SerialDebug.print("|");

        SerialDebug.print("|RSV:");
        SerialDebug.print(Robot_Status_Value);
        SerialDebug.print("|");
    
        
        if (Mower_Docked == 1) SerialDebug.print(F("DockedRX|"));
        if (Mower_Parked == 2) SerialDebug.print(F("ParkedRX|"));
        if (Tracking_Wire == 4) SerialDebug.print(F("TrackingRX|"));
        if (Rain_Detected == 5) SerialDebug.print(F("RainRX|"));
        if (Wire_Detected == 6) SerialDebug.print(F("WireRX|"));
        if (Mower_Setup_Mode == 7) SerialDebug.print(F("SetupRX|"));

        

        if   (Robot_Status_Value == 1) SerialDebug.print(F("Docked|"));
        else if (Robot_Status_Value == 2) SerialDebug.print(F("Parked|"));
        else if (Robot_Status_Value == 4) SerialDebug.print(F("Mower Error|"));
        else if (Robot_Status_Value == 5) SerialDebug.print(F("Running|"));
        else if (Robot_Status_Value == 6) SerialDebug.print(F("Manuel Mode|"));
        else if (Robot_Status_Value == 7) SerialDebug.print(F("Tracking_Wire|"));
        else if (Robot_Status_Value == 9) SerialDebug.print(F("Exiting_Dock|"));
        //else if (Robot_Status_Value == 1) SerialDebug.print(F("Park_Low_Batt|")); //TODO

    
        if (Mower_Running == 1) {
    			SerialDebug.print("|VLow:");
    			SerialDebug.print(Low_Battery_Detected);
          }

        if (Mower_Docked == 1 || Mower_Parked == 1) {
			    SerialDebug.print("|Charging:");
			    SerialDebug.print(Charge_Detected);
          }

        SerialDebug.print("|MAG:");
        SerialDebug.print(MAG_Now);

        SerialDebug.print(F("|Wire:"));
        if (Wire_Detected == 0) SerialDebug.print(F("OFF"));
        if (Wire_Detected == 1) SerialDebug.print(F("ON"));
   
        
              #if defined(WEBSERVER)
              if (Perimeter_Wire_Enabled) {
                  if (Wire_Detected == 0) SerialDebug.print(F("OFF"));
                  if (Wire_Detected == 1) SerialDebug.print(F("ON"));
                  }
              else SerialDebug.print(F("Disabled"));
              #endif // -(WEBSERVER)-

        if (Mower_Running == 1) {
      			SerialDebug.print("|A:");
      			SerialDebug.print(Tilt_Angle_Sensed);
      
      			SerialDebug.print("|O:");
      			SerialDebug.print(Tilt_Orientation_Sensed);
      
      			SerialDebug.print("|WA:");
      			SerialDebug.print(WheelAmps);
      
      			SerialDebug.print("|S2:");
      			SerialDebug.print(distance2);
      			SerialDebug.print("cm/");
      			SerialDebug.print(Sonar_Hit_2_Total);
      
      			SerialDebug.print("|S1:");
      			SerialDebug.print(distance1);
      			SerialDebug.print("cm/");
      			SerialDebug.print(Sonar_Hit_1_Total);
      
      			SerialDebug.print("|S3:");
      			SerialDebug.print(distance3);
      			SerialDebug.print("cm/");
      			SerialDebug.print(Sonar_Hit_3_Total);
            }

        SerialDebug.print(F("|Wheel:"));
        if 		(Wheel_Status_Value == 1) SerialDebug.print(F("FULL"));
        else if (Wheel_Status_Value == 2) SerialDebug.print(F("R-FULL"));
        else if (Wheel_Status_Value == 3) SerialDebug.print(F("S-FULL"));
        else if (Wheel_Status_Value == 4) SerialDebug.print(F("SLOW"));
        else if (Wheel_Status_Value == 5) SerialDebug.print(F("For"));
        else if (Wheel_Status_Value == 6) SerialDebug.print(F("Rev"));
        else if (Wheel_Status_Value == 7) SerialDebug.print(F("OFF"));
        else if (Wheel_Status_Value == 8) SerialDebug.print(F("TL_"));
        else if (Wheel_Status_Value == 9) SerialDebug.print(F("TR_"));
        else if (Wheel_Status_Value == 10) SerialDebug.print(F("CIRCLE"));
        SerialDebug.print("|");

        if (Mower_Running == 1) {
			SerialDebug.print("|Loop:");
			SerialDebug.print(Loop_Cycle_Mowing);
        }

        if (Mower_Running == 1 && Loop_Cycle_Mowing % 20 == 0) {
			SerialDebug.print(F("|Comp°:"));
			SerialDebug.print(Compass_Heading_Degrees);
			SerialDebug.print(F("|C_Err:"));
			SerialDebug.print(Compass_Error);
			if (Compass_Error < 0) { Serial.print(F("|SR")); }  // Steer right
			else { Serial.print(F("|SL")); }                    // Steer left
			SerialDebug.print(F("|PWM_R:"));
			SerialDebug.print(PWM_Right);
			SerialDebug.print(F("|PWM_L:"));
			SerialDebug.print(PWM_Left);
        }
        if      (Loop_Cycle_Mowing < 50) { Serial.print(F("C-Lock:OFF")); }
        else if (Loop_Cycle_Mowing > 50) { Serial.print(F("C-Lock:ON_")); }

        SerialDebug.print(F("|Blades:"));
        if (Blade_flagRun) SerialDebug.print(F("ON_"));
        else SerialDebug.print(F("OFF"));

        SerialDebug.print(F("|ME:"));
        SerialDebug.print(Mower_Error_Value);

        SerialDebug.print(F("|RAIN:"));
        SerialDebug.print(Rain_Detected);
 
        SerialDebug.print(F("|WireOUT:"));
        SerialDebug.print(Outside_Wire);      

        SerialDebug.print(F("|AUTO_Mode:"));
        SerialDebug.print(Automatic_Mode);    

        //RX_data_from_Mega_updated = false;
        SerialDebug.println("");
	}

}



void Receive_Setup_Data_MEGA() {

  SerialDebug.print(F("|RX_SETUP:"));
    
  byte recvBuff [21] = {0};
  int recvVal = 0;

  if (NodeMCUCom.update ()) {
  
    byte length = NodeMCUCom.getLength ();
    if (length > sizeof (recvBuff)) length = sizeof (recvBuff);
    memcpy (&recvBuff, NodeMCUCom.getData (), length);


    Alarm_1_ON                      = bitRead(recvBuff[0],0);
    Alarm_2_ON                      = bitRead(recvBuff[0],1);
    Alarm_3_ON                      = bitRead(recvBuff[0],2);
    Compass_Activate                = bitRead(recvBuff[0],3);
    Compass_Heading_Hold_Enabled    = bitRead(recvBuff[0],4);
    GYRO_Enabled                    = bitRead(recvBuff[0],5);
    SONAR_1_Activate                = bitRead(recvBuff[0],6);
    SONAR_2_Activate                = bitRead(recvBuff[0],7);

    SONAR_3_Activate                = bitRead(recvBuff[1],0);
    Bumper_Activate_Frnt            = bitRead(recvBuff[1],1);
    GPS_Enabled                     = bitRead(recvBuff[1],2);
    Angle_Sensor_Enabled            = bitRead(recvBuff[1],3);
    Tip_Over_Sensor_Enabled         = bitRead(recvBuff[1],4);
    Wheel_Amp_Sensor_ON             = bitRead(recvBuff[1],5);
    Wheels_Activate                 = bitRead(recvBuff[1],6);
    Ramp_Motor_ON                   = bitRead(recvBuff[1],7);
    
    int Spare = 0;
    
    MAG_Speed_Adjustment            = bitRead(recvBuff[2],0);
    Perimeter_Wire_Enabled          = bitRead(recvBuff[2],1);
    Use_Charging_Station            = bitRead(recvBuff[2],2);
    Spare                           = bitRead(recvBuff[2],3);
    Spare                           = bitRead(recvBuff[2],4);
    Spare                           = bitRead(recvBuff[2],5);
    Spare                           = bitRead(recvBuff[2],6);
    Spare                           = bitRead(recvBuff[2],7);

    RX_data_from_Mega_updated = true;
    SerialDebug.print(F("|RX_OK:"));
    }                                                   // end if something received

    if(RX_data_from_Mega_updated == true) {
      SerialDebug.print(F("Setup:"));
      SerialDebug.print(Mower_Setup_Mode);
      SerialDebug.print(F("|Alarm1:"));
      SerialDebug.print(Alarm_1_ON);
      SerialDebug.print(F("|Alarm2:"));
      SerialDebug.print(Alarm_2_ON);
      SerialDebug.print(F("|Alarm3:"));
      SerialDebug.print(Alarm_3_ON);
      SerialDebug.print(F("|Compass:"));
      SerialDebug.print(Compass_Activate);
      SerialDebug.print(F("|Heading Hold:"));
      SerialDebug.print(Compass_Heading_Hold_Enabled);
      SerialDebug.print(F("|GYRO:"));
      SerialDebug.print(GYRO_Enabled);
      SerialDebug.print(F("|Sonar1:"));
      SerialDebug.print(SONAR_1_Activate);
      SerialDebug.print(F("|Sonar2:"));
      SerialDebug.print(SONAR_2_Activate);
      SerialDebug.print(F("|Sonar3:"));
      SerialDebug.print(SONAR_3_Activate);
      SerialDebug.print(F("|Bumper:"));
      SerialDebug.print(Bumper_Activate_Frnt); 
      SerialDebug.print(F("|GPS:"));
      SerialDebug.print(GPS_Enabled);
      SerialDebug.print(F("|AngleSensor:"));
      SerialDebug.print(Angle_Sensor_Enabled );
      SerialDebug.print(F("|TipOverSensor:"));
      SerialDebug.print(Tip_Over_Sensor_Enabled);
      SerialDebug.print(F("|WheelAmpSensor:"));
      SerialDebug.print(Wheel_Amp_Sensor_ON);
      SerialDebug.print(F("|WheelsActivate:"));
      SerialDebug.print(Wheels_Activate);
      SerialDebug.print(F("|Ramp:"));
      SerialDebug.print(Ramp_Motor_ON);    
      SerialDebug.print(F("|MAG_Speed:"));
      SerialDebug.print(MAG_Speed_Adjustment);       
      SerialDebug.print(F("|WIRE_ON:"));
      SerialDebug.print(Perimeter_Wire_Enabled);     
      SerialDebug.print(F("|UseCharge:"));
      SerialDebug.print(Use_Charging_Station);     
      //SerialDebug.print(F(":"));
      SerialDebug.println();         
    }



}
