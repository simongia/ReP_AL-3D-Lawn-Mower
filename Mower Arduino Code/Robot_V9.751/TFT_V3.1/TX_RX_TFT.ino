

// Transmit functions to send data to the Main Arduino MEGA on the mower.
//************************************************************************

void Send_Menu_Selected_To_Mower_MEGA() {
    tft.fillScreen(BLACK);
    tft.setCursor(0, 0);  
    tft.setTextSize(3); 
    tft.setTextColor(WHITE, BLACK);           // Text Colour/ Background Colour
    tft.setCursor(50, 50); 
    tft.println(F("Please Wait.."));
    Transmit_Active_Menu_Interupt();          // Sends the menu number selected to the Mower MEGA
    Check_TX_Received();                      // Checks the number sent back by the MEGA
    
    if (Command_Check != (Menu_Active*3)) {
      Serial.print(F("TX Comfirmation Code !FAIL!:"));
      Serial.println(Command_Check);
      }
    if (Command_Check == (Menu_Active*3)) {
      Serial.print(F("TX Comfirmation Code:"));
      Serial.println(Command_Check);
      }
    
   
}

void Transmit_Active_Menu_Interupt() {
	byte data[3];
	data[0] = 21; // Packet ID

	data[1]=Menu_Active;
	data[2]=Menu_Active >> 8;

	SerialComMEGA.sendMsg (data, sizeof (data));
    Serial.print("TX Active=");
    Serial.println(Menu_Active);  
    }

// Feedback Loop to ensure the transmition is sent.
void Check_TX_Received() {
	byte recvBuff [3] = {0};
	bool confRecv = false;
	while(!confRecv) {
		if (SerialComMEGA.update ())
		{
		  byte length = SerialComMEGA.getLength ();
		  if (length > sizeof (recvBuff)) length = sizeof (recvBuff);
		  memcpy (&recvBuff, SerialComMEGA.getData (), length);

		  if (recvBuff[0] == 22) {
			  Command_Check =   recvBuff[1] | recvBuff[2] << 8;
			  Serial.print(F("|CheckTXRecv:OK|"));
			  confRecv = true;
		  }
		}  // end if something received
	}
}



void Send_Menu_Selected_To_Mower_MEGA_No_RX() {
    Serial.println(" ");
    delay(Delay_Transmit);
    Transmit_Active_Menu_Interupt();
     
    }



  




//************************************************************************
// Transmit functions to send data to the GPS NodeMCU on the mower.
//************************************************************************

void Send_Menu_Selected_To_GPS_NodeMCU() {
    Command_Check = 0;
    Serial.println(" ");
    tft.fillScreen(BLACK);
    tft.setCursor(0, 0);  
    tft.setTextSize(2); 
    tft.setTextColor(GREEN, BLACK);           // Text Colour/ Background Colour
    tft.setCursor(50, 50); 
    tft.println(F("Talking to GPS...."));
    Transmit_Active_Menu_Interupt_GPS();
    delay(1500);
        
    //Now check that the Transmition was succesfull.
    Check_TX_Received_GPS();

    
    if (Command_Check == ( Menu_Active * 3) ) Serial.println("TX GPS Conf");
    else {
      Serial.println("*TX GPS Lost*");
      Send_Menu_Selected_To_GPS_NodeMCU();
    }
    
}


void Transmit_Active_Menu_Interupt_GPS() {
    Serial2.print(Menu_Active);
    Serial2.println("\g");
    delay(100);
    Serial.print("TX GPS Menu = ");
    Serial.println(Menu_Active);  
    }


// Feedback Loop to ensure the transmition is sent.
void Check_TX_Received_GPS() {

  Serial.print("Check GPS Conf Code");
  String Serial2_RX_Value  = "";                                              
  while (Serial2.available() > 0) {
  
    char recieved = Serial2.read();
    if ( recieved != '\j') {   
      Serial2_RX_Value = Serial2_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\j') {
      Command_Check = Serial2_RX_Value.toInt();                                 
      Serial2_RX_Value = ""; // changed to string
      }   
  }

  delay(1000);
  
}
