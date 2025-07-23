
// Menu cretaed when the Exit Dock button is pressed on the main menu


void Print_Exit_Dock_Menu() {

      // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons
    tft.fillScreen(BLACK);
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
    

    int Button_X = Start_X;
    int Button_Y = Start_Y + (Button_H + Menu_Spacing);    
    
    //Re-Print Exit Dock
    OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, WHITE, BLACK, "Exit Dock", 2);
    OPTION2_BTN.drawButton(false);

    //Draw Connecting Line
    tft.fillRect( (Button_X + (0.5 * Button_W) ) , Button_Y, 70, 5, WHITE);

    // Reset the Height of the buttons    
    Button_H = Button_H - 15;
    
    // Draw first button on the top row again
    Button_Y = Start_Y + (0.2 * Button_H);
    
    // Second part of connecting line from the top position again
    tft.fillRect( (Button_X + (Button_W + Menu_Btn_Space) ) , Button_Y, 5, 150, WHITE);
    
    //Zone 1 button
    Button_X = Start_X  + (Button_W + Menu_Btn_Space);
    Button_Y = Button_Y;    
    OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, BLUE, YELLOW, "Zone 1", 2);
    OPTION1_BTN.drawButton(false);
   
    //Zone 2 Button  
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, YELLOW, BLACK, "Zone 2", 2);
    OPTION2_BTN.drawButton(false);

    //Mow The Line Button  
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);   
    OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, MAGENTA, YELLOW, "Mow Line", 2);
    OPTION3_BTN.drawButton(false);

    // Cancel Button
    Cancel_ED_btn.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Cancel", 2);
    Cancel_ED_btn.drawButton(false);
}


void React_to_Button_Press_Exit_Dock() {

    // Actions Zone 1 is pressed
    if (OPTION1_BTN.justPressed()) {
        // Add Conencting Line   
        tft.fillRect( 296, 85, 40, 5, WHITE);
        // Add Vertcial Line
        tft.fillRect( 385, 85, 5, 150, WHITE);
        Add_Time_To_Exit_Dock();
        Exit_Zone = 1;                // Confirms Zone 1 as the exit point
        Menu_Complete_2 = false;
        while (Menu_Complete_2 == false) {
          Sense_Button_Exit_Dock_Time();
          React_to_Exit_Dock_Time();
          }
        Menu_Complete_Exit_Dock = true;
        Mower_Error_Value = 0;
        Robot_Status_Value = 9;
        Print_Confirmation_Text_Exit_Dock();
        Menu_Complete_Main = true;
        }

    // Actions Zone 2 is pressed
    if (OPTION2_BTN.justPressed()) {
        // Add Conencting Line  
        tft.fillRect( 296, 150, 40, 5, WHITE);
        // Add Vertcial Line
        tft.fillRect( 385, 85, 5, 150, WHITE);
        Add_Time_To_Exit_Dock();
        Exit_Zone = 2;                // Confirms Zone 2 as the exit point
        Menu_Complete_2 = false;
        while (Menu_Complete_2 == false) {
          Sense_Button_Exit_Dock_Time();
          React_to_Exit_Dock_Time();
          }
        Menu_Complete_Exit_Dock = true;
        Mower_Error_Value = 0;
        Robot_Status_Value = 9;
        Print_Confirmation_Text_Exit_Dock();
        Menu_Complete_Main = true;
        }


    // Action if Mow Line is pressed
    if (OPTION3_BTN.justPressed()) {
        // Add Conencting Line  
        tft.fillRect( 296, 215, 40, 5, WHITE);
        // Add Vertcial Line
        tft.fillRect( 385, 85, 5, 150, WHITE);
        Add_Time_To_Exit_Dock();
        Exit_Zone = 3;                // Confirms Zone 2 as the exit point
        Menu_Complete_2 = false;
        while (Menu_Complete_2 == false) {
          Sense_Button_Exit_Dock_Time();
          React_to_Exit_Dock_Time();
          }
        Menu_Complete_Exit_Dock = true;   // Remove this to go to another screen i.e. the Mowing Screen
        Mower_Error_Value = 0;
        Robot_Status_Value = 9;
        Print_Confirmation_Text_Exit_Dock();
        Menu_Complete_Main = true;
        }

    // Action if cancel is pressed
    if (Cancel_ED_btn.justPressed()) {
         Menu_Complete_Exit_Dock = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Main Screen Selected"));
         Menu_Active = 1;
         Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
         delay(200);
         if ((Robot_Status_Value == 1) || (Robot_Status_Value == 2) || (Robot_Status_Value == 0)) {              // 1 = Docked
            tft.fillScreen(BLACK);
            if (Draw_Pictures == 1) bmpDraw("mower1.bmp", 150, 90);      //Draw the mower picture
            delay(100);
            Print_Main_Menu_Graphic();
            Check_For_Active_Alarms();
            }
        }
}



void Sense_Button_Press_Exit_Dock() {
    down = Touch_getXY();
    OPTION1_BTN.press       (down && OPTION1_BTN.contains(pixel_x, pixel_y));
    OPTION2_BTN.press       (down && OPTION2_BTN.contains(pixel_x, pixel_y));
    OPTION3_BTN.press       (down && OPTION3_BTN.contains(pixel_x, pixel_y));
    Cancel_ED_btn.press     (down && Cancel_ED_btn.contains(pixel_x, pixel_y));

    if (OPTION1_BTN.justReleased())     OPTION1_BTN.drawButton();
    if (OPTION2_BTN.justReleased())     OPTION2_BTN.drawButton();
    if (OPTION3_BTN.justReleased())     OPTION3_BTN.drawButton();
    if (Cancel_ED_btn.justReleased()) Cancel_ED_btn.drawButton();
    
}



void Add_Time_To_Exit_Dock()  {

    int Start_X = 70;
    int Start_Y = 80;
    int Menu_Btn_Space = 30;          // Space between the buttons
    int Button_W = 130;                // width of the button
    int Button_H = 60;                // height of the button

    int Menu_Spacing = 20;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Txt_Size_Main_Menu = 2;

    //1 hr mow Button  
    int Button_X = Start_X + (2* (Button_W + Menu_Btn_Space));
    int Button_Y = Start_Y + (0.2 * Button_H); 

    // Reset the Height of the buttons    
    Button_H = Button_H - 15;

    OPTION4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, YELLOW, BLACK, "1hr Mow", 2);
    OPTION4_BTN.drawButton(false);

    //2 hr mow Button  
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);   
    OPTION5_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, MAGENTA, YELLOW, "2hr Mow", 2);
    OPTION5_BTN.drawButton(false);

    //Max mow Button  
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    OPTION6_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, RED, YELLOW, "Max Mow", 2);
    OPTION6_BTN.drawButton(false);

    }


// Command to the MOWER MEGA comes from this part after the type of mow and the
// Time has been selected
//*****************************************************************************
void React_to_Exit_Dock_Time() {


    // Actions 1h is pressed
    if (OPTION4_BTN.justPressed()) {
        Mow_Time = 1;
        Menu_Active = 93;
        Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
        Transmit_Mower_Start_Conditions_Exit_Dock();
        Menu_Complete_2 = true;  
        }

    // Action if 2 hr is pressed
    if (OPTION5_BTN.justPressed()) {
       Mow_Time = 2;
       Menu_Active = 93;
       Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
       Transmit_Mower_Start_Conditions_Exit_Dock();
       Menu_Complete_2 = true; 
       }

    // Action if max mow is pressed
    if (OPTION6_BTN.justPressed()) {
       Mow_Time = 3;
       Menu_Active = 93;
       Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
       Transmit_Mower_Start_Conditions_Exit_Dock();
       Menu_Complete_2 = true;          
       }

    // Action if cancel is pressed
    if (Cancel_ED_btn.justPressed()) {
         Menu_Complete_2 = true;
         Menu_Complete_Exit_Dock = true;
         tft.fillScreen(BLACK);
         delay(200);
        }
}


void Sense_Button_Exit_Dock_Time() {
    down = Touch_getXY();
    OPTION4_BTN.press       (down && OPTION4_BTN.contains(pixel_x, pixel_y));       // hr1
    OPTION5_BTN.press       (down && OPTION5_BTN.contains(pixel_x, pixel_y));       // hr2
    OPTION6_BTN.press       (down && OPTION6_BTN.contains(pixel_x, pixel_y));   // Max Mow
    Cancel_ED_btn.press     (down && Cancel_ED_btn.contains(pixel_x, pixel_y)); // Cancel

    if (OPTION4_BTN.justReleased())       OPTION4_BTN.drawButton(); 
    if (OPTION5_BTN.justReleased())       OPTION5_BTN.drawButton();
    if (OPTION6_BTN.justReleased())       OPTION6_BTN.drawButton();
    if (Cancel_ED_btn.justReleased())     Cancel_ED_btn.drawButton();
    }


void Print_Confirmation_Text_Exit_Dock() {
      tft.fillScreen(BLACK);

      // Draw White Circle with Green Arrow Down
      tft.fillCircle(70, 150, 70, GREEN);                       // X, Y, Radius
      tft.fillTriangle(30,120 , 110,120, 70,200,  WHITE);       // Point left XY, Point right XY, Point top XY
      tft.drawTriangle(30,120 , 110,120, 70,200,  BLACK);       // Point left XY, Point right XY, Point top XY

      // Write Text information
      tft.setTextSize(6); 
      tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
      tft.setCursor(150, 95);            // Text Coordinates X, Y
      tft.print(F("EXIT DOCK")); 
      tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
      tft.setTextSize(4); 
      tft.setCursor(150, 150);            // Text Coordinates X, Y
      tft.print(F("Zone: ")); 
      tft.print(Exit_Zone);
      tft.setCursor(150, 190);            // Text Coordinates X, Y      
      tft.setTextSize(3); 

      if ((Mow_Time < 3) && (Mow_Time > 0))  {
        tft.print(F("Mow Time: "));  
        tft.print(Mow_Time);      
        tft.print(F(" hrs"));  
        tft.setCursor(150, 220);            // Text Coordinates X, Y
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
            
      if ((Mow_Time == 3) || (Mow_Time == 0)) {
        tft.print("Max Mow Time");  
        delay(2000);  
        tft.fillScreen(BLACK);
        }
      }
