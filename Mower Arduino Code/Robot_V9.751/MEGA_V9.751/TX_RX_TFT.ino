 // Listens to the serial 3 port if a menu command has been executed.
void Check_TFT_Serial_Input() {
	byte recvBuff [3] = {0};

	if (SerialCom3.update ())
	{
	  byte length = SerialCom3.getLength ();
	  if (length > sizeof (recvBuff)) length = sizeof (recvBuff);
	  memcpy (&recvBuff, SerialCom3.getData (), length);

	  if (recvBuff[0] == 21) {
		  TFT_Menu_Command =   recvBuff[1] | recvBuff[2] << 8;
		  Serial.print(F("|TFTserIn:OK|"));

		  Confirm_TX_or_RX_Action();    // Prints the Menu Selected
		  Confirm_RX();
		  delay(5);
		  Send_Data_To_TFT();                                   // Send data to TFT - depends on menu code received
		  Receive_Data_From_TFT();                              // Receive Data from TFT - depends on menu code received
	  }
	}  // end if something received
}



void Activate_TFT_Menu() {

        Serial.println();
        Serial.println(F("TFT Menu Activated"));
        Menu_Complete_TFT = false;                                // Menu complete will return to the normal loop
        Serial.println("waiting for command");
     
     while (Menu_Complete_TFT == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
          Check_TFT_Serial_Input();
          if (TFT_Menu_Command == 1) Menu_Complete_TFT = true;  
          if (Mower_PIXHAWK == 1) Run_in_TFT_PIXHAWK_Mode();        // Runs the Mower even though its in the TFT Menu
          }

      }



void Run_in_TFT_PIXHAWK_Mode() {

   
   while (Mower_PIXHAWK == true) {  
     Check_TFT_Serial_Input();
     Check_PIXHAWK();       
     if (PIXHAWK_Armed == 1) Check_PIXHAWK_PWM();  
     Serial.println("");   
     }
  
}

void Confirm_RX() {      
      // confirms to the TFT that a request for data transfer has been received.
  	byte data[3];
  	data[0] = 22; // Packet ID

  	int TFT_Menu_Command_Buf = TFT_Menu_Command * 3;
  	data[1]=TFT_Menu_Command_Buf;
  	data[2]=TFT_Menu_Command_Buf >> 8;

  	SerialCom3.sendMsg (data, sizeof (data));
      Serial.print("Confirmstion Code Sent : ");
      Serial.println(TFT_Menu_Command * 3); 
      }




// Based on the code received this menu confirms the menu item to be used.
void Confirm_TX_or_RX_Action() {

Serial.print("TFT Menu Command: ");
Serial.print(TFT_Menu_Command );
Serial.print(" = ");

if (TFT_Menu_Command == 1)  Serial.println(F("Main Menu"));
if (TFT_Menu_Command == 2)  Serial.println(F("Quick Start Menu"));
if (TFT_Menu_Command == 3)  Serial.println(F("Exit Dock Menu"));
if (TFT_Menu_Command == 4)  Serial.println(F("Options Menu"));
if (TFT_Menu_Command == 5)  Serial.println(F("Time Menu"));
if (TFT_Menu_Command == 6)  Serial.println(F("Sensors Menu"));
if (TFT_Menu_Command == 7)  Serial.println(F("Motion Menu"));
if (TFT_Menu_Command == 8)  Serial.println(F("Tracking Menu"));
if (TFT_Menu_Command == 9)  Serial.println(F("Navigation Menu"));
if (TFT_Menu_Command == 10) Serial.println(F("Sonar Menu"));
//  Leave 11 Free.
if (TFT_Menu_Command == 12) Serial.println(F("Rain Sensor Menu"));
if (TFT_Menu_Command == 13) Serial.println(F("Stop Menu"));
if (TFT_Menu_Command == 14) Serial.println(F("Wheel Motor Menu"));
if (TFT_Menu_Command == 15) Serial.println(F("Blade Motor Menu"));
if (TFT_Menu_Command == 16) Serial.println(F("Movement Menu"));
if (TFT_Menu_Command == 17) Serial.println(F("Tracking Exit Points"));
if (TFT_Menu_Command == 18) Serial.println(F("Find Wire"));
if (TFT_Menu_Command == 19) Serial.println(F("Track PID"));
if (TFT_Menu_Command == 20) Serial.println(F("Set Alarm 1"));
if (TFT_Menu_Command == 21) Serial.println(F("Set Alarm 2"));
if (TFT_Menu_Command == 22) Serial.println(F("Set Alarm 3"));
if (TFT_Menu_Command == 23) Serial.println(F("Set Time"));
if (TFT_Menu_Command == 24) Serial.println(F("Tip Sensor Menu"));
if (TFT_Menu_Command == 25) Serial.println(F("Pattern Menu"));
if (TFT_Menu_Command == 26) Serial.println(F("Battery Menu"));
if (TFT_Menu_Command == 27) Serial.println(F("Compass Menu"));
if (TFT_Menu_Command == 28) Serial.println(F("GYRO Menu"));
if (TFT_Menu_Command == 29) Serial.println(F("Wheel Block Amps Menu"));
if (TFT_Menu_Command == 30) Serial.println(F("Setup Other Menu"));
if (TFT_Menu_Command == 31) Serial.println(F("PIXHAWK Go Menu"));
if (TFT_Menu_Command == 32) Serial.println(F("GPS Main Menu"));

if (TFT_Menu_Command == 38) Serial.println(F("Wheel Amp Test"));
if (TFT_Menu_Command == 39) Serial.println(F("GYRO Test"));
if (TFT_Menu_Command == 40) Serial.println(F("Tilt Test"));
if (TFT_Menu_Command == 41) Serial.println(F("Wire Test"));
if (TFT_Menu_Command == 42) Serial.println(F("Relay Test"));
if (TFT_Menu_Command == 43) Serial.println(F("Wheel Test"));
if (TFT_Menu_Command == 44) Serial.println(F("Blade Test"));
if (TFT_Menu_Command == 45) Serial.println(F("Sonar Test"));
if (TFT_Menu_Command == 46) Serial.println(F("Turn Test"));
if (TFT_Menu_Command == 47) Serial.println(F("Volt Amp Test"));
if (TFT_Menu_Command == 48) Serial.println(F("Compass Test"));
if (TFT_Menu_Command == 49) Serial.println(F("Go Home Test"));
if (TFT_Menu_Command == 50) Serial.println(F("Bumper Bar"));
if (TFT_Menu_Command == 55) Serial.println(F("Start-Up Value"));
if (TFT_Menu_Command == 56) Serial.println(F("Start-Up Value Date"));
if (TFT_Menu_Command == 57) Serial.println(F("TX Docked Info"));
if (TFT_Menu_Command == 58) Serial.println(F("Mower Running"));
if (TFT_Menu_Command == 59) Serial.println(F("Test Lift Mechanism"));
if (TFT_Menu_Command == 60) Serial.println(F("Test Lift Mechanism UP"));
if (TFT_Menu_Command == 61) Serial.println(F("Test Lift Mechanism DOWN"));
if (TFT_Menu_Command == 62) Serial.println(F("Initiate Drill Test"));
if (TFT_Menu_Command == 63) Serial.println(F("PIXHAWK Test"));
if (TFT_Menu_Command == 64) Serial.println(F("Start PWM Read"));
if (TFT_Menu_Command == 65) Serial.println(F("Wheel Test Method 2"));
if (TFT_Menu_Command == 66) Serial.println(F("Left Front Forwards"));
if (TFT_Menu_Command == 67) Serial.println(F("Left Front Backwards"));
if (TFT_Menu_Command == 68) Serial.println(F("Right Front Forwards"));
if (TFT_Menu_Command == 69) Serial.println(F("Right Front Backwards"));
if (TFT_Menu_Command == 70) Serial.println(F("Left Rear Forwards"));
if (TFT_Menu_Command == 71) Serial.println(F("Left Rear Backwards"));
if (TFT_Menu_Command == 72) Serial.println(F("Right Rear Forwards"));
if (TFT_Menu_Command == 73) Serial.println(F("Right Rear Backwards"));
if (TFT_Menu_Command == 74) Serial.println(F("Right Rear Backwards"));
if (TFT_Menu_Command == 75) Serial.println(F("Right Rear Backwards"));

if (TFT_Menu_Command == 99) Serial.println(F("Break TX loop and wait for data..."));
}
