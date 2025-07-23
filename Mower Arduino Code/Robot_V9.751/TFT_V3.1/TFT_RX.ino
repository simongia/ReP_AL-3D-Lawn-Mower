
// Data received from the Main Arduino MEGA Board on the mower
// ************************************************************


void Receive_7_Data_Sets() {
  Serial.println("Receiving Data Sets");
	byte recvBuff [15] = {0};
	bool confRecv = false;
	while(!confRecv) {
		if (SerialComMEGA.update ())
		{
		  byte length = SerialComMEGA.getLength ();
		  if (length > sizeof (recvBuff)) length = sizeof (recvBuff);
		  memcpy (&recvBuff, SerialComMEGA.getData (), length);

		  if (recvBuff[0] == 18) {
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


void Clear_Data_Streams() {
  Data1 = 0;
  Data2 = 0;
  Data3 = 0;
  Data4 = 0;
  Data5 = 0;
  Data6 = 0;
  Data7 = 0;

}


void Set_TFT_Screen_Pos() {
      tft.setTextSize(2); 
      tft.setTextColor(GREEN, BLACK);           // Text Colour/ Background Colour
      tft.setCursor(0, 100);                      // Text Coordinates X, Y
      }


void Receive_Tracking_Data() {
   String Serial1_RX_Value  = "";                                           

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' ) {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
        } 
        else if (recieved == '\a') {
          Use_Charging_Station = Serial1_RX_Value.toInt();                                 
          Serial1_RX_Value = ""; // changed to string
          } 
    
    else Serial.print(F("No Data Received|"));
    } 

      Serial.print(F("Use Charging Station = "));
      Serial.println(Use_Charging_Station); 
      
      Serial.println(F(" "));
}


void Receive_Setup_Other_Data() {
   String Serial1_RX_Value  = "";                                           

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b') {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
        } 
        else if (recieved == '\a') {
          PCB = Serial1_RX_Value.toInt();                                 
          Serial1_RX_Value = ""; // changed to string
          } 
       else if (recieved == '\b') {
          Robot_Type = Serial1_RX_Value.toInt();                               
          Serial1_RX_Value = "";
          } 
       else if (recieved == '\b') {
          Clear_EEPROM = Serial1_RX_Value.toInt();                               
          Serial1_RX_Value = "";
          } 
    
    else Serial.print(F("No Data Received|"));
    } 

      Serial.print(F("PCB = "));
      if (PCB == 1) Serial.println(F("Enabled"));
      if (PCB == 0) Serial.println(F("Disabled"));
      Serial.print(F("Robot Type = "));
      if (Robot_Type == 1) Serial.println(F("Mower"));
      if (Robot_Type == 2) Serial.println(F("Aerator"));
      Serial.println(" ");
}


void Receive_Track_PID_Data() {

    String Serial1_RX_Value  = "";                                            

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;         
        } 
        else if (recieved == '\a') {
          Max_Tracking_Turn_Left = Serial1_RX_Value.toInt();                                 
          Serial1_RX_Value = ""; // changed to string
          } 
       else if (recieved == '\b') {
          Max_Tracking_Turn_Right = Serial1_RX_Value.toInt();                               
          Serial1_RX_Value = "";
          } 
       else if (recieved == '\c') {
          P = Serial1_RX_Value.toInt();                               
          Serial1_RX_Value = "";
          }
    
    else Serial.print(F("No Data Received|"));
    }

      Serial.print(F("Max Cyckes Left Wheel = "));
      Max_Tracking_Turn_Left = Max_Tracking_Turn_Left * 10;
      Serial.println(Max_Tracking_Turn_Left);

      Serial.print(F("Max Cyckes Right Wheel = "));
      Max_Tracking_Turn_Right = Max_Tracking_Turn_Right * 10;
      Serial.println(Max_Tracking_Turn_Right);
          
      Serial.print(F("PID P = "));
      P = P / 100;
      Serial.println(P);

      Serial.println(F(" "));
}




void Receive_Compass_Data() {

    String Serial1_RX_Value  = "";                                              

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d') {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
        } 
        else if (recieved == '\a') {
          Compass_Activate = Serial1_RX_Value.toInt();                                 
          Serial1_RX_Value = ""; // changed to string
          } 
       else if (recieved == '\b') {
          Compass_Heading_Hold_Enabled = Serial1_RX_Value.toInt();                                
          Serial1_RX_Value = "";
          } 
       else if (recieved == '\c') {
          CPower = Serial1_RX_Value.toInt();                                
          Serial1_RX_Value = "";
          }
       else if (recieved == '\d') {
          Compass_Setup_Mode = Serial1_RX_Value.toInt();                                
          Serial1_RX_Value = "";
          }

    else Serial.print(F("No Data Received|"));
    }

      Serial.print(F("Compass Activated = "));
      Serial.println(Compass_Activate);

      Serial.print(F("Heading Hold Enabled = "));
      Serial.println(Compass_Heading_Hold_Enabled);
          
      Serial.print(F("Compass Power = "));
      CPower = CPower / 10;
      Serial.println(CPower);
      
      Serial.print(F("Compass Setup Mode = "));
      Serial.println(Compass_Setup_Mode);

      Serial.println(F(" "));
}



          
void Receive_GYRO_Data() {

  String Serial1_RX_Value  = "";                                              

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b') {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
        } 
       else if (recieved == '\a') {
          GYRO_Enabled = Serial1_RX_Value.toInt();                                
          Serial1_RX_Value = "";
          }
       else if (recieved == '\b') {
          GPower = Serial1_RX_Value.toInt();                                
          Serial1_RX_Value = "";
          }

    else Serial.print(F("No Data Received|"));
    }

      Serial.print(F("GYRO Enabled = "));
      Serial.println(GYRO_Enabled);
      Serial.print(F("GPower = "));      
      GPower = GPower / 10;
      Serial.println(GPower);
  }


void Receive_Navigation_Data() {

    String Serial1_RX_Value  = "";                                              

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a') {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
        } 
       else if (recieved == '\a') {
          GPS_Enabled = Serial1_RX_Value.toInt();                                
          Serial1_RX_Value = "";
          }
    
    else Serial.print(F("No Data Received|"));
    }

      Serial.print(F("GPS Enabled = "));
      Serial.println(GPS_Enabled);
      Serial.println(F(" "));
}


void Receive_Alarm1_Data() {

  String Serial1_RX_Value  = "";                                            

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' && recieved != '\e' ) {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Alarm_1_ON = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Alarm_1_Hour = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Alarm_1_Minute = Serial1_RX_Value.toInt();                           
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\d') {
      Alarm_1_Repeat = Serial1_RX_Value.toInt();                       
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\e') {
      Alarm_1_Action = Serial1_RX_Value.toInt();                          
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }


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


void Receive_Alarm2_Data() {

  String Serial1_RX_Value  = "";                                            

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' && recieved != '\e' ) {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Alarm_2_ON = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Alarm_2_Hour = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Alarm_2_Minute = Serial1_RX_Value.toInt();                           
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\d') {
      Alarm_2_Repeat = Serial1_RX_Value.toInt();                       
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\e') {
      Alarm_2_Action = Serial1_RX_Value.toInt();                          
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }


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

void Receive_Alarm3_Data() {

  String Serial1_RX_Value  = "";                                            

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' && recieved != '\e' ) {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Alarm_3_ON = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Alarm_3_Hour = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Alarm_3_Minute = Serial1_RX_Value.toInt();                           
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\d') {
      Alarm_3_Repeat = Serial1_RX_Value.toInt();                       
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\e') {
      Alarm_3_Action = Serial1_RX_Value.toInt();                          
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }


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


void Receive_Set_Time_Data() {

  String Serial1_RX_Value  = "";                                            

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Time_Hour = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Time_Minute = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }

      Serial.print(F("Time Now = "));
      Serial.print(Time_Hour);
      Serial.print(F(":"));
      Serial.println(Time_Minute);  
}


void Receive_Wire_Sensor_Data() {

  String Serial1_RX_Value  = "";                                            

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      INOUT = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      MAG = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Menu_Complete_Wire_Test = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }
    Serial.print(F("IN/Out:"));
    Serial.print(INOUT);
    Serial.print(F(" MAG:"));
    Serial.print(MAG); 
    Serial.print(F(" Test Complete:"));
    Serial.println(Menu_Complete_Wire_Test); 
}



void Receive_Sonar_Test_Data() {

  String Serial1_RX_Value  = "";                                            

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      distance1 = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      distance2 = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      distance3 = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\d') {
      Menu_Complete_Sonar_Test = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }
    Serial.print(F("Sonar 1:"));
    Serial.print(distance1);
    Serial.print(F("  Sonar 2:"));
    Serial.print(distance2);
    Serial.print(F("  Sonar 3:"));
    Serial.print(distance3);
    Serial.print(F(" Test Complete:"));
    Serial.println(Menu_Complete_Wire_Test); 
}


void Receive_Compass_Sensor_Data() {
  String Serial1_RX_Value  = "";                                            

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Heading = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Compass_Heading_Degrees = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Menu_Complete_Compass_Test = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }
    Heading = Heading / 10;
    
    Serial.print("Heading: ");
    Serial.print(Heading);
    Serial.print("  Degrees: ");
    Serial.print(Compass_Heading_Degrees);
    Serial.print("  Test Completed: ");
    Serial.println(Menu_Complete_Compass_Test); 
}


void Receive_GYRO_Sensor_Data() {
  String Serial1_RX_Value  = "";                                            

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      GYRO_X_Angle = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      GYRO_Y_Angle = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Menu_Complete_GYRO_Test = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }

    
    Serial.print("GYRO X Angle: ");
    Serial.print(GYRO_X_Angle);
    Serial.print("  GYRO_Y_Angle: ");
    Serial.print(GYRO_Y_Angle);
    Serial.print("  Test Completed: ");
    Serial.println(Menu_Complete_GYRO_Test); 
}


void Receive_Volt_Amp_Sensor_Data() {
  String Serial1_RX_Value  = "";                                            

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Volts = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Amps = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Menu_Complete_Volt_Amp_Test = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }
    Volts = (Volts * 2) / 100;
    Amps = Amps / 100;
    
    Serial.print("Volt: ");
    Serial.print(Volts);
    Serial.print("  Amps: ");
    Serial.print(Amps);
    Serial.print("  Test Completed: ");
    Serial.println(Menu_Complete_Volt_Amp_Test); 
}



void Receive_Bumper_Sensor_Data() {
  String Serial1_RX_Value  = "";                                            

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Bump_LH = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Bump_RH = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Menu_Complete_Bumper_Test = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }
    
    Serial.print("LH: ");
    Serial.print(Bump_LH);
    Serial.print("  RH: ");
    Serial.print(Bump_RH);
    Serial.print("  Test Completed: ");
    Serial.println(Menu_Complete_Bumper_Test); 
}

void Receive_Tilt_Sensor_Data() {
  String Serial1_RX_Value  = "";                                            

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Tilt_Angle_Sensed = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Tilt_Orientation_Sensed = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Menu_Complete_Tilt_Test = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }
    
    Serial.print("Tilt: ");
    Serial.print(Tilt_Angle_Sensed);
    Serial.print("  Orientation: ");
    Serial.print(Tilt_Orientation_Sensed);
    Serial.print("  Test Completed: ");
    Serial.println(Menu_Complete_Tilt_Test); 
}



void Get_Initial_Values() {

    Serial.println(F("RX Start Up Values"));
    // Halts the MEGA from TX data to the NodeMCU etc and puts it into a wait mode
    Menu_Active = 99;
    Send_Menu_Selected_To_Mower_MEGA();  

    // delay(3000); //NODELAY_SERIALCOM dissabled
    Menu_Active = 55;                           // Code to tell the Mower MEGA which data to transmit.
    Send_Menu_Selected_To_Mower_MEGA();         // Send the code to the Mower MEGA which data should be transfered
    
    // delay(RX_Delay + 2100); //NODELAY_SERIALCOM dissabled                   // Wait time for the Mower MEGA to transmit the data.
    Receive_7_Data_Sets();                      // Recieve data sets from the Mower MEGA
    Alarm_1_ON             = Data1;             // Fill the variable values with the data sets
    Alarm_2_ON             = Data2;
    Alarm_3_ON             = Data3;
    Time_Hour              = Data4;
    Time_Minute            = Data5;
    GPS_Enabled            = Data6;
    Perimeter_Wire_Enabled = Data7;
    Clear_Data_Streams();

    if (Debug_RX_Transfer == 1) {              // Display the received values on the TFT Screen if required.        
      tft.setCursor(0, 100); 
      tft.setTextSize(2); 
      tft.print(F("Alarm 1:"));
      tft.println(Alarm_1_ON);
      tft.print(F("Alarm 2:"));
      tft.println(Alarm_2_ON);
      tft.print(F("Alarm 3:"));
      tft.println(Alarm_3_ON); 
      tft.print(F("Time:"));
      tft.print(Time_Hour);
      tft.print(F(":"));
      if (Time_Minute < 10) tft.print("0");
      tft.println(Time_Minute);     
      tft.print(F("GPS:"));
      if (GPS_Enabled == 1) tft.println("ON");   
      if (GPS_Enabled == 0) tft.println("OFF"); 
      tft.print(F("WIRE:"));
      if (Perimeter_Wire_Enabled == 1) tft.println("ON");   
      if (Perimeter_Wire_Enabled == 0) tft.println("OFF"); 
      delay(TFT_Check);
      tft.fillScreen(BLACK);     
      }

      Serial.print(F("Alarm 1 ON = "));
      Serial.println(Alarm_1_ON);
      Serial.print(F("Alarm 2 ON = "));
      Serial.println(Alarm_2_ON);
      Serial.print(F("Alarm 3 ON = "));
      Serial.println(Alarm_3_ON);
      Serial.print(F("|Time:"));
      Serial.print(Time_Hour);
      Serial.print(F(":"));
      if (Time_Minute < 10) Serial.print(F("0"));
      Serial.println(Time_Minute);
      Serial.print(F("GPS:"));
      if (GPS_Enabled == 1) Serial.println(F("ON"));   
      if (GPS_Enabled == 0) Serial.println(F("OFF")); 
      Serial.print(F("WIRE:"));
      if (Perimeter_Wire_Enabled == 1) Serial.println(F("ON"));   
      if (Perimeter_Wire_Enabled == 0) Serial.println(F("OFF")); 

      Menu_Active = 1;                          // Breaks the MEGA Loop waiting for data
      Send_Menu_Selected_To_Mower_MEGA();       // Sends the command
}

    

void Receive_Mower_Tracking_Data() {
	byte recvBuff [7] = {0};

	if (SerialComMEGA.update ())
	{
	  byte length = SerialComMEGA.getLength ();
	  if (length > sizeof (recvBuff)) length = sizeof (recvBuff);
	  memcpy (&recvBuff, SerialComMEGA.getData (), length);

	  if (recvBuff[0] == 11) {
		  Turn_To_Home            = recvBuff[1];
		  Find_Wire_Track         = recvBuff[2];
		  Go_To_Charging_Station  = recvBuff[3];
		  Docking_Complete        = recvBuff[4];
		  Robot_Status_Value      = recvBuff[5];
		  Mower_Error_Value       = recvBuff[6];
		  Serial.print(F("|RecvTD:OK|"));
	  }
	}  

    Serial.print("Turn To Home");
    Serial.print(Turn_To_Home);
    Serial.print("  Find Wire Track ");
    Serial.print(Find_Wire_Track);
    Serial.print("  Go To Charging Station: ");
    Serial.print(Go_To_Charging_Station); 
    Serial.print("  Docking complete: ");
    Serial.print(Docking_Complete); 
    Serial.print(F("  Mower Status = "));
    Serial.println(Robot_Status_Value);
}


void Receive_Wheel_Amp_Data() {

  String Serial1_RX_Value  = "";                                            

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Wheel_Blocked = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
    else Serial.print(F("No Data Received|"));
  }
        Serial.print(F("Wheel Status: "));
        if (Wheel_Blocked == 1) Serial.println("Blocked");
        if (Wheel_Blocked == 0) Serial.println("- - - -");
    
}



void Receive_Mower_Running_Data() {
  int VoltsTX;
	byte recvBuff [19] = {0};
	if (SerialComMEGA.update ())
	{
	  byte length = SerialComMEGA.getLength ();
	  if (length > sizeof (recvBuff)) length = sizeof (recvBuff);
	  memcpy (&recvBuff, SerialComMEGA.getData (), length);

	  if (recvBuff[0] == 12) {
		  Sonar_Status            = recvBuff[1];
		  Wire_Status             = recvBuff[2];
		  Bumper_Status           = recvBuff[3];
		  Robot_Status_Value      = recvBuff[4];
		  Mower_Error_Value       = recvBuff[5];
		  Tilt_Angle_Sensed       = recvBuff[6];
		  VoltsTX                 = recvBuff[7] | recvBuff[8] << 8;
		  GPS_In_Out_TX           = recvBuff[9];
		  GPS_Lock_OK_TX          = recvBuff[10];
		  Loops                   = recvBuff[11] | recvBuff[12] << 8;
		  Compass_Steering_Status = recvBuff[13];
		  WheelAmpsRX             = recvBuff[14] | recvBuff[15] << 8;
		  //WheelAmps = WheelAmpsRX / 100;
		  Compass_Heading_Degrees = recvBuff[16] | recvBuff[17];

		  Wheel_Blocked_Status    = bitRead(recvBuff[18],0);
		  //reserve =  = bitRead(recvBuff[18],1);
		  //reserve =  = bitRead(recvBuff[18],2);
		  //reserve =  = bitRead(recvBuff[18],3);
		  //reserve =  = bitRead(recvBuff[18],4);
		  //reserve =  = bitRead(recvBuff[18],5);
		  //reserve =  = bitRead(recvBuff[18],6);
		  //reserve =  = bitRead(recvBuff[18],7);

      if (Robot_Status_Value == 0) {
        Robot_Status_Value = Robot_Status_Value_Last;         // if a 0 is received it can turn the TFT black as it jumps out of a mode
        }

		  Serial.print(F("|RunDataRecv:OK|"));
	  }
	}  

        Serial.println(F("Sending Running Data to TFT"));
        Serial.print(F("|S:"));
        Serial.print(Sonar_Status);
        Serial.print(F("|W:"));
        Serial.print(Wire_Status);    
        Serial.print(F("|BU:"));
        Serial.print(Bumper_Status);               
        Serial.print(F("|RS:"));
        Serial.print(Robot_Status_Value);
        Serial.print(F("|Tip:"));
        Serial.print(Tilt_Angle_Sensed);
        Battery = VoltsTX;
        Battery = Battery / 100;
        Serial.print(F("|VoltsRX = "));
        if (VoltsTX > 0) Serial.print(Battery);
        else Serial.print("XX.XX");
        Serial.print(F("|GPS:"));
        if (GPS_In_Out_TX == 1) Serial.print("INSIDE");
        if (GPS_In_Out_TX == 0) Serial.print("OUTSIDE");        
        Serial.print(F("|GPS:"));
        if (GPS_Lock_OK_TX == 1) Serial.print("RTKFIX");
        if (GPS_Lock_OK_TX == 0) Serial.print("No Lock");
        
        Serial.print(F("|Lo:"));
    		Serial.print(Loops);
    		Serial.print(F("|CS:"));
    		Serial.print(Compass_Steering_Status);
    		Serial.print(F("|C�:"));
    		Serial.print(Compass_Heading_Degrees);
    		Serial.print(F("|WARx:"));
    		Serial.print(WheelAmpsRX);
        Serial.print(F("|"));
}


void Receive_Aerator_Running_Data() {
                                  
  int VoltsTX;
  byte recvBuff [19] = {0};
  if (SerialComMEGA.update ())
  {
    byte length = SerialComMEGA.getLength ();
    if (length > sizeof (recvBuff)) length = sizeof (recvBuff);
    memcpy (&recvBuff, SerialComMEGA.getData (), length);

    if (recvBuff[0] == 12) {
      Sonar_Status              = recvBuff[1];
      Wire_Status               = recvBuff[2];
      Drill_Status              = recvBuff[3];
      Robot_Status_Value        = recvBuff[4];
      Mower_Error_Value         = recvBuff[5];
      Tilt_Angle_Sensed         = recvBuff[6];
      VoltsTX                   = recvBuff[7] | recvBuff[8] << 8;
      GPS_In_Out_TX             = recvBuff[9];
      GPS_Lock_OK_TX            = recvBuff[10];
      Loops                     = recvBuff[11] | recvBuff[12] << 8;
      Compass_Steering_Status   = recvBuff[13];
      WheelAmpsRX               = recvBuff[14] | recvBuff[15] << 8;
      //WheelAmps               = WheelAmpsRX / 100;
      Compass_Heading_Degrees   = recvBuff[16] | recvBuff[17];

      Wheel_Blocked_Status = bitRead(recvBuff[18],0);
      //reserve =  = bitRead(recvBuff[18],1);
      //reserve =  = bitRead(recvBuff[18],2);
      //reserve =  = bitRead(recvBuff[18],3);
      //reserve =  = bitRead(recvBuff[18],4);
      //reserve =  = bitRead(recvBuff[18],5);
      //reserve =  = bitRead(recvBuff[18],6);
      //reserve =  = bitRead(recvBuff[18],7);

      Serial.print(F("|RunDataRecv:OK|"));

      if (Robot_Status_Value == 0) {
        Robot_Status_Value = Robot_Status_Value_Last;         // if a 0 is received it can turn the TFT black as it jumps out of a mode
        }
    
    }
  } 

      
        Serial.println(F("Sending Running Data to TFT"));
        Serial.print(F("|S:"));
        Serial.print(Sonar_Status);
        Serial.print(F("|W:"));
        Serial.print(Wire_Status);    
        Serial.print(F("|BU:"));
        Serial.print(Bumper_Status);               
        Serial.print(F("|MS:"));
        Serial.print(Robot_Status_Value);
        Serial.print(F("|Tip:"));
        Serial.print(Tilt_Angle_Sensed);
        Battery = VoltsTX;
        Battery = Battery / 100;
        Serial.print(F("VoltsRX = "));
        if (VoltsTX > 0) Serial.print(Battery);
        else Serial.print("XX.XX");
        Serial.print(F("|GPS:"));
        if (GPS_In_Out_TX == 1) Serial.print("INSIDE");
        if (GPS_In_Out_TX == 0) Serial.print("OUTSIDE");        
        Serial.print(F("|GPS:"));
        if (GPS_Lock_OK_TX == 1) Serial.print("RTKFIX");
        if (GPS_Lock_OK_TX == 0) Serial.print("No Lock");    

}

//****

void Receive_PIXHAWK_Running_Data() {

  String Serial1_RX_Value  = "";    
  int Spare1;      
  int Spare2;
  int Spare3;
  int Spare4;
  int Spare5;
  int Spare6;
  int Spare7;                                  

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\s' && recieved != '\e' 
    && recieved != '\f' && recieved != '\g' && recieved != '\h' && recieved != '\i' ) { 
              
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      PWM_Arduino_LH = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      PWM_Arduino_RH = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Spare1 = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\s') {
      Spare2 = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\e') {
      Spare3 = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\f') {
      Spare4 = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\g') {
      Spare5 = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\h') {
      Spare6 = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\i') {
      cycles = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
    else Serial.print(F("No Data Received|"));
  }
      
        Serial.print(F("|LW:"));          
        Serial.print(PWM_Arduino_LH);
        Serial.print(F("|RW:"));
        Serial.print(PWM_Arduino_RH);  
        Serial.print(F("|S1:"));
        Serial.print(Spare1); 
        Serial.print(F("|S2:"));
        Serial.print(Spare2);  
        Serial.print(F("|S3:"));
        Serial.print(Spare3); 
        Serial.print(F("|S4:"));
        Serial.print(Spare4);     
        Serial.print(F("|S5:"));
        Serial.print(Spare5);          
        Serial.print(F("|S6:"));
        Serial.print(Spare6);     
        Serial.print(F("|Cy:"));
        Serial.println(cycles); 

}


void Receive_Docked_Data() {

  int VoltsTX;
  byte recvBuff [15] = {0};

  if (SerialComMEGA.update ())
  {
    byte length = SerialComMEGA.getLength ();
    if (length > sizeof (recvBuff)) length = sizeof (recvBuff);
    memcpy (&recvBuff, SerialComMEGA.getData (), length);

    if (recvBuff[0] == 10) {
      Time_Year           = recvBuff[1] | recvBuff[2] << 8;
      Time_Month          = recvBuff[3];
      Time_Date           = recvBuff[4];
      Time_Hour           = recvBuff[5];
      Time_Minute         = recvBuff[6];
      Time_Second         = recvBuff[7];
      Time_Day            = recvBuff[8];      
      VoltsTX             = recvBuff[9] | recvBuff[10] << 8;
      Robot_Status_Value  = recvBuff[11];
      Mower_Error_Value   = recvBuff[12];
      Charging            = recvBuff[13];
      GPS_Lock_OK_TX      = recvBuff[14];
      Serial.print(F("|RecvDD:OK|"));
    }
  }  
      
      Battery = VoltsTX;
      Battery = Battery / 100;
      Serial.print(F("VoltsRX = "));
      if (VoltsTX > 0) Serial.print(Battery);
      else Serial.print("XX.XX");

      Serial.print(F("|ME:"));
      Serial.print(Mower_Error_Value);
      Serial.print(F("|C: "));
      Serial.print(Charging);
      Serial.print(F("|"));
      Serial.print(F("MS "));
      if (Robot_Status_Value == 0) {
        Robot_Status_Value = Robot_Status_Value_Last;         // if a 0 is received it can turn the TFT black as it jumps out of a mode
        }
      if (Robot_Status_Value == 1) Serial.print("Dock");
      if (Robot_Status_Value == 2) Serial.print("Park");
      if (Robot_Status_Value == 3) Serial.print("Setup App");
      if (Robot_Status_Value == 4) Serial.print("Err ");
      if (Robot_Status_Value == 5) Serial.print("Run ");
      if (Robot_Status_Value == 6) Serial.print("Manual ");
      if (Robot_Status_Value == 9) Serial.print("Exit");

      Robot_Status_Value_Last = Robot_Status_Value;
      
      Serial.print(F("|"));
      Serial.print(F("GPS:"));
      Serial.print(GPS_Lock_OK_TX);
      if (GPS_Lock_OK_TX == 5) Serial.print("RTKFIX");
      if (GPS_Lock_OK_TX == 2) Serial.print("No Lock");
      if (GPS_Lock_OK_TX == 0) Serial.print(" ");    
      
      
}



void Receive_Error_Data() {

  String Serial1_RX_Value  = "";                                            

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a' && recieved != '\b') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Robot_Status_Value = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Mower_Error_Value = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
    
    else Serial.print(F("No Data Received|"));
  }
      
      if ((Mower_Error_Value == 1) && (Robot_Status_Value == 0)) Robot_Status_Value = 2;
      if ((Mower_Error_Value == 0) && (Robot_Status_Value == 1)) Robot_Status_Value = 2;
      
      Serial.print(F("Mower Status = "));
      Serial.print(Robot_Status_Value);
      Serial.print(F("  Mower Error = "));
      Serial.println(Mower_Error_Value);

}



void Receive_Setup_Data() {

  String Serial1_RX_Value  = "";                                            

  while (SerialMEGA.available() > 0) {
    
    char recieved = SerialMEGA.read();
    if ( recieved != '\a') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Robot_Status_Value = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 

    
    else Serial.print(F("No Data Received|"));
  }
      
      if (Robot_Status_Value == 0) {
        Robot_Status_Value = 3;        // avoids any loss of communication errors a 0 value will make the TFT go black
        Serial.print(F("****"));
        }
      Serial.print(F("MSV = "));
      Serial.println(Robot_Status_Value);

}



void Receive_GPS_Data() {

String Serial1_RX_Value  = "";                                              
  while (Serial1.available() > 0) {
  
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      GPS_Enabled = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      }
      else if (recieved == '\b') {
      GPS_Type = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      }        

   else Serial.print(F("No Data Received|"));   
   }

    Serial.print(F("GPS: "));
        if (GPS_Enabled == 1) Serial.println("ON");
        if (GPS_Enabled == 0) Serial.println("OFF");    
    Serial.print(F("GPS Type: "));
        if (GPS_Type == 1) Serial.println("ReP_AL");
        if (GPS_Type == 2) Serial.println("PIXHAWK");    
        if (GPS_Type == 3) Serial.println("Spare");   
}



void Receive_GPS_Settings_Data() {

String Serial2_RX_Value  = "";                                              
  while (Serial2.available() > 0) {
  
    char recieved = Serial2.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
      Serial2_RX_Value = Serial2_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      GPS_WIFI_Enabled = Serial2_RX_Value.toInt();                                 
      Serial2_RX_Value = ""; // changed to string
      }
      else if (recieved == '\b') {
      Simulation_Mode = Serial2_RX_Value.toInt();                                 
      Serial2_RX_Value = ""; // changed to string
      }        
      else if (recieved == '\c') {
      Fence = Serial2_RX_Value.toInt();                                 
      Serial2_RX_Value = ""; // changed to string
      }  
   else Serial.print(F("No Data Received|"));   
   }
      Serial.print(F("GPS_WIFI_Enabled = "));
      if (GPS_WIFI_Enabled == 1) Serial.println("Enabled");
      if (GPS_WIFI_Enabled == 0) Serial.println("Disabled");
      Serial.print(F("Simulation Mode = "));
      if (Simulation_Mode == 1) Serial.println("Enabled");
      if (Simulation_Mode == 0) Serial.println("Disabled");
      Serial.print(F("Fence = "));
      Serial.println(Fence);
      Serial.println(F(" "));
}
