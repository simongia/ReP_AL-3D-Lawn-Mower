
// Menu cretaed when the Quick Go button is pressed on the main menu


void Print_Quick_Go_Menu() {
    tft.fillScreen(BLACK);
      // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons

    int Start_X = 70;
    int Start_Y = 80;
    int Menu_Btn_Space = 30;          // Space between the buttons
    int Button_W = 130;                // width of the button
    int Button_H = 60;                // height of the button

    int Menu_Spacing = 20;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Txt_Size_Main_Menu = 2;



    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(20, 10);            // Text Coordinates X, Y
    if (Robot_Type == 1) tft.print(F("REP_AL Robot Lawn Mower: ")); 
    if (Robot_Type == 2) tft.print(F("REP_AL Robot Aerator: "));
    tft.print(Version);
    
    
    
    //Re-Print Quick Go
    int Button_X = Start_X;
    int Button_Y = Start_Y;
    OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, YELLOW, BLACK, "Quick Go", 2);
    OPTION1_BTN.drawButton(false);

    //Draw Connecting Line
    tft.fillRect( (Button_X + (0.5 * Button_W) ) , Button_Y, 70, 5, WHITE);
    tft.fillRect( (Button_X + (Button_W + Menu_Btn_Space) ) , Button_Y, 5, 200, WHITE);

    // Reset the Height of the buttons
    Button_H = Button_H - 15;
    
   
    
    //Go Now Button
    Button_X = Start_X  + (Button_W + Menu_Btn_Space);
    Button_Y = Button_Y;    
    OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, RED, WHITE, "Just Go", 2);
    OPTION1_BTN.drawButton(false);

    int PIXHAWK_KEY_SPACE;
    
    if (GPS_Enabled == true) PIXHAWK_KEY_SPACE = 160;
    if (GPS_Enabled == false) PIXHAWK_KEY_SPACE = 0;
    
    
    if (GPS_Enabled == true) {
      //PIXHAWK Button
      Button_X = Start_X  + (Button_W + Menu_Btn_Space + PIXHAWK_KEY_SPACE);
      Button_Y = Button_Y;   
      OPTION5_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, BLUE, WHITE, "PIXHAWK", 2);
      OPTION5_BTN.drawButton(false);
      }
   
    //1 hr mow Button  
    Button_X = Button_X - PIXHAWK_KEY_SPACE;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    if (Robot_Type == 1) OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, YELLOW, BLACK, "1hr Mow", 2);
    if (Robot_Type == 2) OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, YELLOW, BLACK, "1hr Aer", 2);     
    OPTION2_BTN.drawButton(false);

    //2 hr mow Button  
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);   
    if (Robot_Type == 1) OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, MAGENTA, MAGENTA, YELLOW, "2hr Mow", 2);
    if (Robot_Type == 2) OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, MAGENTA, MAGENTA, YELLOW, "2hr Aer", 2);
    OPTION3_BTN.drawButton(false);

    //Max mow Button  
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    if (Robot_Type == 1) OPTION4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, YELLOW, BLACK, "Max Mow", 2);
    if (Robot_Type == 2) OPTION4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, YELLOW, BLACK, "Max Aer", 2);
    OPTION4_BTN.drawButton(false);


    // Cancel Button
    Cancel_QG_btn.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Cancel", 2);
    Cancel_QG_btn.drawButton(false);
}


void React_to_Button_Press_Quick_Go() {

    // Actions Just Go is pressed
    if (OPTION1_BTN.justPressed()) {
       Menu_Complete_Quick_Start = true;
       Menu_Complete_Main = true;
       Mow_Time = 3;
       Menu_Active = 92;
       Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
       Transmit_Mower_Start_Conditions_Quick_Start();
       Print_Confirmation_Text_Quick_Start();        
        }

    // Actions 1h is pressed
    if (OPTION2_BTN.justPressed()) {
       Menu_Complete_Quick_Start = true;
       Menu_Complete_Main = true;
       Mow_Time = 1;
       Mower_Error_Value = 0;
       Robot_Status_Value = 5;
       Menu_Active = 92;
       Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
       Transmit_Mower_Start_Conditions_Quick_Start();
       Print_Confirmation_Text_Quick_Start();       
       }


    // Action if 2 hr is pressed
    if (OPTION3_BTN.justPressed()) {
       Menu_Complete_Quick_Start = true;
       Menu_Complete_Main = true;
       Mow_Time = 2;
       Mower_Error_Value = 0;
       Robot_Status_Value = 5;
       Menu_Active = 92;
       Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
       Transmit_Mower_Start_Conditions_Quick_Start();
       Print_Confirmation_Text_Quick_Start();       
       }

    // Action if max mow is pressed
    if (OPTION4_BTN.justPressed()) {
       Menu_Complete_Quick_Start = true;
       Menu_Complete_Main = true;
       Mow_Time = 3;
       Mower_Error_Value = 0;
       Robot_Status_Value = 5;
       Menu_Active = 92;
       Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
       Transmit_Mower_Start_Conditions_Quick_Start();
       Print_Confirmation_Text_Quick_Start();       
       }


    // Action if Options is pressed
    if (OPTION5_BTN.justPressed()) {
          Menu_Complete_Settings = false;
          tft.fillScreen(BLACK);
          Serial.println(F("PIXHAWK Screen Selected"));
          Menu_Active = 31;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected     
          Print_PIXHAWK_Go_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Settings == false) {
            Sense_Button_Press_PIXHAWK_Go();
            React_to_Button_Press_PIXHAWK_Go();
            }
          
          
        }          
          
        
    
    
    // Action if cancel is pressed
    if (Cancel_QG_btn.justPressed()) {
         Menu_Complete_Quick_Start = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Main Screen Selected"));
         Menu_Active = 1;
         Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
         delay(200);
         if ((Robot_Status_Value == 0) ||(Robot_Status_Value == 1) || (Robot_Status_Value == 2)) {              // 1 = Docked  2 = Parked
            tft.fillScreen(BLACK);
            if (Draw_Pictures == 1) bmpDraw("mower1.bmp", 150, 90);      //Draw the mower picture
            delay(100);
            Print_Main_Menu_Graphic();
            Check_For_Active_Alarms();
            }
        }
}


void Sense_Button_Press_Quick_Go() {
    down = Touch_getXY();
    OPTION1_BTN.press    (down && OPTION1_BTN.contains(pixel_x, pixel_y));
    OPTION2_BTN.press    (down && OPTION2_BTN.contains(pixel_x, pixel_y));
    OPTION3_BTN.press    (down && OPTION3_BTN.contains(pixel_x, pixel_y));
    OPTION4_BTN.press    (down && OPTION4_BTN.contains(pixel_x, pixel_y));
    OPTION5_BTN.press    (down && OPTION5_BTN.contains(pixel_x, pixel_y));
    Cancel_QG_btn.press  (down && Cancel_QG_btn.contains(pixel_x, pixel_y));

    if (OPTION1_BTN.justReleased())    OPTION1_BTN.drawButton();
    if (OPTION2_BTN.justReleased())    OPTION2_BTN.drawButton();
    if (OPTION3_BTN.justReleased())    OPTION3_BTN.drawButton();
    if (OPTION4_BTN.justReleased())    OPTION4_BTN.drawButton();
    if (OPTION5_BTN.justReleased())    OPTION5_BTN.drawButton();
    if (Cancel_QG_btn.justReleased())  Cancel_QG_btn.drawButton();
    
}


void Print_Confirmation_Text_Quick_Start() {
      tft.fillScreen(BLACK);
     
      // Draw White Circle with Green Arrow Up
      tft.fillCircle(70, 150, 70, GREEN);                       // X, Y, Radius
      tft.fillTriangle(30,180 , 110,180, 70,100,  WHITE);       // Point left XY, Point right XY, Point top XY
      tft.drawTriangle(30,180 , 110,180, 70,100,  BLACK);       // Point left XY, Point right XY, Point top XY

      // Print Text Information
      tft.setTextSize(5); 
      tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
      tft.setCursor(150, 95);            // Text Coordinates X, Y
      tft.print(F("QUICK START"));  
      tft.setTextSize(3); 
      tft.setCursor(150, 150);            // Text Coordinates X, Y
  
      if (Mow_Time < 3)  {
        tft.print(F("Mow Time: "));  
        tft.print(Mow_Time);      
        tft.print(F(" hrs"));  
        tft.setCursor(150, 180);            // Text Coordinates X, Y
        tft.print(F("Mow Ends:"));
        int End_Time = Time_Hour + Mow_Time;
        if (End_Time > 23) End_Time = (End_Time - 24);
        if (End_Time < 10) tft.print(F("0"));
        tft.print(End_Time);
        tft.print(F(":"));
        if (Time_Minute < 10) tft.print("0");
        tft.print(Time_Minute);   
        delay(2000);  
        }     
            
      if (Mow_Time == 3) {
        tft.print("Max Mow Time");  
        delay(2000);  
        tft.fillScreen(BLACK);
        }


        }
