void Check_Sonar_Sensors() {
  
  // Ping Sonar sensors

  //Clears the Trig Pin
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin3, LOW);

 // Pings each sonar at a 15ms interval

 if (Sonar_2_Activate == 1) distance2 = PingSonarX(trigPin2, echoPin2, 2, 2, 2, 0, 0);         //SONAR2
 if (Sonar_1_Activate == 1) distance1 = PingSonarX(trigPin1, echoPin1, 1, 1, 1, 1, 0);         //SONAR1
 if (Sonar_3_Activate == 1) distance3 = PingSonarX(trigPin3, echoPin3, 3, 3, 3, 2, 0);         //SONAR3

 }
  


/* SONAR Function
************************************************************************************/
// Function to Ping the Sonar calculate the distance from Object to the Sonars.
// Distance calculated is printed to serial printer and displays X or _ on the LCD Screen
// Distance calculated is then used for the object avoidance logic
// Sonars used can be activated in the settings.

int PingSonarX(int trigPinX, int echoPinX, int distanceX, long durationX, int sonarX, int LCDRow, int LCDColumn) {
  pinMode(trigPinX, OUTPUT);
  pinMode(echoPinX, INPUT);
  //Sets the trigPin at High state for 10 micro secs sending a sound wave
  digitalWrite(trigPinX, HIGH);
  digitalWrite(trigPinX, LOW);
  delayMicroseconds(10);

  /*Reads the echoPin for the bounced wave and records the time in microseconds*/

  durationX = pulseIn(echoPinX, HIGH, 10000);  //LOOP_OPTIMIZE added timeout 10ms - OK for detection object in distance 40cm
  // TODO test Arduino NewPing library https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home

  /*Calculates the distance in cm based on the measured time*/
  distanceX = durationX * 0.034 / 2;
  delay(5); //LOOP_OPTIMIZE removed

  /* If a 0 distance is measured normally the Sonar ping has not been received.
    distance is then set to 999cm so the missed ping is not seen as an object detected.*/
  if (distanceX == 0) {
    distanceX = 999;
    Serial.print(F("|S"));
    Serial.print(sonarX);
    Serial.print(F(":"));
    Serial.print(F("NP!"));
    Serial.print(F("|"));

    // Check why removed
    //if (sonarX == 1) Sonar_1_Error++;
    //if (sonarX == 2) Sonar_2_Error++;
    //if (sonarX == 3) Sonar_3_Error++;
    
    if (Sonar_1_Error > Sonar_Max_Error_Shutdown) {
      Sonar_1_Activate = 0;
      Serial.println(F(""));
      Serial.println(F("Sonar 1 - Shutdown Error - Check Wiring"));
      Serial.println(F(""));    
      
      }
    if (Sonar_2_Error > Sonar_Max_Error_Shutdown) {
      Sonar_2_Activate = 0;
      Serial.println(F(""));
      Serial.println(F("Sonar 2 - Shutdown Error - Check Wiring"));
      Serial.println(F(""));    
      }
    if (Sonar_3_Error > Sonar_Max_Error_Shutdown) {
      Sonar_3_Activate = 0;
      Serial.println(F(""));
      Serial.println(F("Sonar 3 - Shutdown Error - Check Wiring"));
      Serial.println(F(""));    
      }
  }

  /*Prints the Sonar letter and distance measured on the serial Monitor*/
  Serial.print(F("|S"));
  Serial.print(sonarX);
  Serial.print(F(":"));
  Serial.print(distanceX);
  Serial.print(F("cm"));
  Serial.print(F("/"));

  /*If sonar distance is less than maximum distance then an object is registered to avoid*/
  if (distanceX <= maxdistancesonar ) {
    //Prints that Sonar X has detected an object to the Mower LCD.
    
    #if defined(LCD_KEYPAD)
    lcd.setCursor(LCDRow, LCDColumn);                //sets location for text to be written
    lcd.print("X");
    #endif
    
    if (sonarX == 1) {
        Sonar_Hit_1_Total = (Sonar_Hit_1_Total + 1);
        Serial.print(Sonar_Hit_1_Total);
        Sonar_1_Error = 0;
        }
      if (sonarX == 2) {
        Sonar_Hit_2_Total = (Sonar_Hit_2_Total + 1);
        Serial.print(Sonar_Hit_2_Total);
        Sonar_2_Error = 0;
        }
      if (sonarX == 3) {
        Sonar_Hit_3_Total = (Sonar_Hit_3_Total + 1);
        Serial.print(Sonar_Hit_3_Total);
        Sonar_3_Error = 0;
        }      
    if ( (Sonar_Hit_1_Total == Max_Sonar_Hit) || (Sonar_Hit_2_Total == Max_Sonar_Hit) || (Sonar_Hit_3_Total == Max_Sonar_Hit) ) {
      Sonar_Hit = 1;  
      Print_Sonar_Hit();
      Serial.println(F(""));
      Serial.println("Sonar Hit Detected");
      }
    
    }

  /*If sonar distance is greater than maximum distance then no object is registered to avoid*/
  if (distanceX > maxdistancesonar) {
    //Prints that the path of Sonar X is open.
    
    #if defined(LCD_KEYPAD)
    lcd.setCursor(LCDRow, LCDColumn);                 //sets location for text to be written
    lcd.print("_");
    #endif
    
      if (sonarX == 1) {
        Sonar_Hit_1_Total = 0;
        Serial.print(Sonar_Hit_1_Total);
        }
      if (sonarX == 2) {
        Sonar_Hit_2_Total = 0;
        Serial.print(Sonar_Hit_2_Total);
        }
      if (sonarX == 3) {
        Sonar_Hit_3_Total = 0;
        Serial.print(Sonar_Hit_3_Total);
        }   
    }
   

  return distanceX;
  return sonarX;



}
