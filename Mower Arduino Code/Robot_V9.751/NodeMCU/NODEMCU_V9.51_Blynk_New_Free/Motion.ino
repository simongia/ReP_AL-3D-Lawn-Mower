// Send the various WIFI codes to the MEGA


void Pause_Mower() {
  SerialDebug.println("");
  SerialDebug.println("Pause/Stop");
  Mower_Docked = 0;  
  Mower_Parked = 1; 
  Mower_Running = 0;                                             
  Tracking_Wire = 0;                                                
  Docked_Counts = 0;
  transmit_blynk_code = 1;
  Transmit_Blynk_Data_to_Mega();
  }

void Going_Home() {
  SerialDebug.println("");
  SerialDebug.println("Go to Dock");
  Mower_Docked = 0;  
  Mower_Parked = 0; 
  Mower_Running = 0;                                             
  Tracking_Wire = 1;                                                
  Docked_Counts = 0;
  transmit_blynk_code = 2;
  Transmit_Blynk_Data_to_Mega();
  }

void StartMower() {
  SerialDebug.println("");
  SerialDebug.println("Quick Start");
  Mower_Docked = 0;
  Mower_Parked = 0;
  Mower_Running = 1;
  Tracking_Wire = 0; 
  transmit_blynk_code = 3;                                            // Code used to let MEGA know what to do
  Transmit_Blynk_Data_to_Mega();                                      // Transmits that code to the MEGA
  }

void Exit_Dock() {
  SerialDebug.println("");
  SerialDebug.println("Exit Dock");
  Mower_Docked = 0;
  Mower_Parked = 0;
  Mower_Running = 0;
  Tracking_Wire = 1; 
  Mower_Docked_Filter = 0;
  transmit_blynk_code = 4;
  Transmit_Blynk_Data_to_Mega();
  }


void Set_To_AUTO_Mode() {
    SerialDebug.println("");
    SerialDebug.println("AUTO Mode Selected");
    Mower_Docked = 0;
    transmit_blynk_code = 6;
    Transmit_Blynk_Data_to_Mega();
    delay(100);
    }


void Set_To_Manuel_Mode() {
    SerialDebug.println("");
    SerialDebug.println("Manuel Mode Selected");
    Mower_Docked = 0;
    Mower_Parked = 0;
    Mower_Running = 0;
    Tracking_Wire = 0; 
    Docked_Counts = 0;
    Blade_ON = false;
    transmit_blynk_code = 5; 
    Transmit_Blynk_Data_to_Mega();
    delay(100);
    }

void Set_To_Setup_Mode() {
    SerialDebug.println("");
    SerialDebug.println("Manuel Mode Selected");
    Mower_Docked = 0;
    Mower_Parked = 0;
    Mower_Running = 0;
    Tracking_Wire = 0; 
    Docked_Counts = 0;
    Blade_ON = false;
    transmit_blynk_code = 13;
    Transmit_Blynk_Data_to_Mega();
    Receive_Setup_Data_MEGA(); 
    delay(100);
    }

void Set_To_Automatic_Mode_Random() {
    SerialDebug.println("");
    SerialDebug.println("Automatic Mode RANDOM Selected");
    transmit_blynk_code = 6;
    Transmit_Blynk_Data_to_Mega();
    delay(100);
    Automatic_Mode = 1;
    }

void Set_To_Automatic_Mode_Parallel() {
    SerialDebug.println("");
    SerialDebug.println("Automatic Mode PARALLEL Selected");
    transmit_blynk_code = 12;
    Transmit_Blynk_Data_to_Mega();
    delay(100);
    Automatic_Mode = 2;
    }

void Set_To_Automatic_Mode_Spiral() {
    SerialDebug.println("");
    SerialDebug.println("Automatic Mode SPIRAL Selected");
    transmit_blynk_code = 11;
    Transmit_Blynk_Data_to_Mega();
    delay(100);
    Automatic_Mode = 3;
    }

    


  
