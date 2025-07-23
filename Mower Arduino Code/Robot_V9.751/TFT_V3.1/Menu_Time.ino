
// Settings Menu
//*********************************

void Print_Time_Menu() {

      // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons

    tft.fillScreen(BLACK);
    int Start_X = 100;
    int Start_Y = 80;
    int Menu_Btn_Space = 100;          // Space between the adjacent buttons
    int Button_W = 150;                // width of the button
    int Button_H = 60;                // height of the button

    int Menu_Spacing = 20;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Txt_Size_Main_Menu = 2;
    int Column_Spacing = 100; 



    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(20, 10);            // Text Coordinates X, Y
    tft.print(F("Time / Alarm Settings"));  
    
    
    
    //Alarm 1

    // Prints the Alarm menu botttuns.
    // Alarsm which are on are shwon in green.
   
    int Button_X = Start_X;
    int Button_Y = Start_Y;
   
    if (Alarm_1_ON == 0) OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLACK, WHITE, BLACK, "Alarm 1>", 2);
    if (Alarm_1_ON == 1) OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLACK, GREEN, BLACK, "Alarm 1>", 2);
    OPTION1_BTN.drawButton(false);
    
    //Alarm 2
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    if (Alarm_2_ON == 0) OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLACK, WHITE, BLACK, "Alarm 2>", 2);
    if (Alarm_2_ON == 1) OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLACK, GREEN, BLACK, "Alarm 2>", 2);
    OPTION2_BTN.drawButton(false);

    //Alarm 3
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    if (Alarm_3_ON == 0) OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLACK, WHITE, BLACK, "Alarm 3>", 2);
    if (Alarm_3_ON == 1) OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLACK, GREEN, BLACK, "Alarm 3>", 2);
    OPTION3_BTN.drawButton(false);

    //Set Time
    
    Button_X = Start_X + (Button_W + Column_Spacing) ;
    Button_Y = Start_Y;    
    
    OPTION4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, MAGENTA, MAGENTA, WHITE, "Set Time >", 2);
    OPTION4_BTN.drawButton(false);
    
    
// Done Button

    DONE3_BTN.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Done", 2);
    DONE3_BTN.drawButton(false);
  
}


void React_to_Button_Press_Time() {


    // Alarm 1 button is pressed
    if (OPTION1_BTN.justPressed()) {
          Alarm_X_Selected = 1;
          Menu_Complete_AlarmX = false;     
          tft.fillScreen(BLACK);
          Serial.println(F("Set Alarm 1"));
          Menu_Active = 20;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
          Serial.println("RX Alarm 1");
          delay(Receive_Values_Delay + 800);
          Receive_Alarm1_Data();       

          if (Alarm_1_Action > 5) Alarm_1_Action = 1;
                   
          Alarm_X_ON      = Alarm_1_ON;                 
          Alarm_X_Hour    = Alarm_1_Hour;               
          Alarm_X_Minute  = Alarm_1_Minute;             
          Alarm_X_Repeat  = Alarm_1_Repeat;                
          Alarm_X_Action  = Alarm_1_Action;
          Print_AlarmX_Menu();

          while (Menu_Complete_AlarmX == false) {
            Sense_Button_AlarmX();
            React_to_Button_AlarmX();
            }
    }
          
    if (OPTION2_BTN.justPressed()) {
          Alarm_X_Selected = 2;
          Menu_Complete_AlarmX = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Set Alarm 2"));
          Menu_Active = 21;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
          Serial.println("RX Alarm 2");
          delay(Receive_Values_Delay + 800);
          Receive_Alarm2_Data();  

          if (Alarm_2_Action > 5) Alarm_2_Action = 1;
          
          Alarm_X_ON     = Alarm_2_ON;                 
          Alarm_X_Hour   = Alarm_2_Hour;               
          Alarm_X_Minute = Alarm_2_Minute;             
          Alarm_X_Repeat = Alarm_2_Repeat;                
          Alarm_X_Action = Alarm_2_Action;
          Print_AlarmX_Menu();

          while (Menu_Complete_AlarmX == false) {
            Sense_Button_AlarmX();
            React_to_Button_AlarmX();
            }
    }
          

    if (OPTION3_BTN.justPressed()) {
          Alarm_X_Selected = 3;
          Menu_Complete_AlarmX = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Set Alarm 3"));
          Menu_Active = 22;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
          Serial.println("RX Alarm 3");
          delay(Receive_Values_Delay + 800);
          Receive_Alarm3_Data(); 

          if (Alarm_3_Action > 5) Alarm_3_Action = 1;
          
          Alarm_X_ON     = Alarm_3_ON;                 
          Alarm_X_Hour   = Alarm_3_Hour;               
          Alarm_X_Minute = Alarm_3_Minute;             
          Alarm_X_Repeat = Alarm_3_Repeat;                
          Alarm_X_Action = Alarm_3_Action; 
          Print_AlarmX_Menu();

          while (Menu_Complete_AlarmX == false) {
            Sense_Button_AlarmX();
            React_to_Button_AlarmX();
            }
    }


    if (OPTION4_BTN.justPressed()) {
          Menu_Complete_Set_Time = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Set Time"));
          Menu_Active = 23;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
          Serial.println("RX Time Data");
          delay(Receive_Values_Delay + 400);
          Receive_Set_Time_Data();  
          Print_Set_Time_Menu();

          while (Menu_Complete_Set_Time == false) {
            Sense_Button_Set_Time();
            React_to_Button_Set_Time();
            }
    }


 // Action if Done is pressed
 if (DONE3_BTN.justPressed()) {
         Menu_Complete_Time = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Time Data Saved and TX"));
         Menu_Active = 98;
         Send_Menu_Selected_To_Mower_MEGA();
         Print_Settings_Menu();
         }  

}
    


void Sense_Button_Press_Time() {
    down = Touch_getXY();
    OPTION1_BTN.press                 (down && OPTION1_BTN.contains(pixel_x, pixel_y));
    OPTION2_BTN.press                 (down && OPTION2_BTN.contains(pixel_x, pixel_y));
    OPTION3_BTN.press                 (down && OPTION3_BTN.contains(pixel_x, pixel_y));
    OPTION4_BTN.press                 (down && OPTION4_BTN.contains(pixel_x, pixel_y));
    DONE3_BTN.press                   (down && DONE3_BTN.contains(pixel_x, pixel_y));

    if (OPTION1_BTN.justReleased())        OPTION1_BTN.drawButton();
    if (OPTION2_BTN.justReleased())        OPTION2_BTN.drawButton();
    if (OPTION3_BTN.justReleased())        OPTION3_BTN.drawButton();
    if (OPTION4_BTN.justReleased())        OPTION4_BTN.drawButton();
    if (DONE3_BTN.justReleased())          DONE3_BTN.drawButton();

}
