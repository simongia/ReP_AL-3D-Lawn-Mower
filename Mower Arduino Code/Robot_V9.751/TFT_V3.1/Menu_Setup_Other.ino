void Print_Setup_Other_Menu() {  

    tft.fillScreen(BLACK);
    //if (Draw_Pictures == 1)   bmpDraw("Rain.bmp", 270, 60);      //Draw the mower picture
    delay(100);    
   
    // Framework for the + - buttons - setting the start position of the + button wil automatically then space the - button

    int Start_X = 10;
    int Start_Y = 50;
    int Menu_Btn_Space = 100;          // Space between the text and the -ve button
    int Button_W = 120;                // width of the button
    int Button_H = 60;                // height of the button
    int Button_Spacing = 5;           // Space between the -ve and +ve buttons
    int Txt_Size_Label = 1;           // Test size iof the label above the value
    Txt_Size_Value = 2;               // Text size of the value that is changing
    int Menu_Spacing = 65;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Offset_Btn = 25;
    int Txt_Size_Main_Menu = 2;
    int Column_Spacing = 200;         // Distance between the Left Hand and Right Hand Columns


    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(10, 10);            // Text Coordinates X, Y
    tft.print(F("Other Setup Options"));  
    
    
    
    // Full Pictures ON/OFF
    //------------------------------------------------------------
    
    int Label_X = Start_X;                           // Starting X Point.
    int Label_Y = Start_Y;                           // Starting Y Point

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("TFT Pictures ON/OFF"));  
    
    int Button_X = Label_X + (0.5 * Button_W);
    int Button_Y = Label_Y + Offset_Btn + (0.3 * Button_H);

    Value_X1 = Button_X;
    Value_Y1 = Button_Y;
    
    if (Draw_Pictures == 1) OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    if (Draw_Pictures == 0) OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    OPTION1_BTN.drawButton(false);


    //Use PCB Option

    Label_X = Start_X;                           // Starting X Point.
    Label_Y = Button_Y + Menu_Spacing;                           // Starting Y Point

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("USE PCB"));  
    
    Button_X = Label_X + (0.5 * Button_W);
    Button_Y = Label_Y + Offset_Btn + (0.3 * Button_H);   

    Value_X2 = Button_X;
    Value_Y2 = Button_Y;
    
    if (PCB == 1) OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    if (PCB == 0) OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    OPTION2_BTN.drawButton(false);



    //Select Mower Type

    Label_X = Start_X  + 200;                                            // Starting X Point.
    Label_Y = Start_Y;                           // Starting Y Point

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Robot Type"));  
    
    Button_X = Label_X + (0.5 * Button_W);
    Button_Y = Label_Y + Offset_Btn + (0.3 * Button_H);   

    Value_X3 = Button_X;
    Value_Y3 = Button_Y;
    
    if (Robot_Type == 1) OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "MOWER", 2);
    if (Robot_Type == 2) OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, YELLOW, BLACK, "AERATOR", 2);
    OPTION3_BTN.drawButton(false);



    // CLEAR EEPROM

    Label_X = Start_X  + 200;                                            // Starting X Point.
    Label_Y = Button_Y + Menu_Spacing;                            // Starting Y Point

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("CLEAR EEPROM MEGA & TFT !!"));  
    
    Button_X = Label_X + (0.5 * Button_W);
    Button_Y = Label_Y + Offset_Btn + (0.3 * Button_H);   

    Value_X4 = Button_X;
    Value_Y4 = Button_Y;
    
    OPTION4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "No", 2);
    OPTION4_BTN.drawButton(false);


// Save Button

    SAVE_BTN.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    SAVE_BTN.drawButton(false);


}


void React_to_Button_Press_Setup_Other() {

 // If the Angle Sensor Button is pressed
 if (OPTION1_BTN.justPressed() ) {

        int Button_W = 120;                // width of the button
        int Button_H = 60;                // height of the button
        
        int Button_X = Value_X1;
        int Button_Y = Value_Y1;
        bool Changed = 0;

        if ((Draw_Pictures == 1) && (Changed ==0))  {
          Draw_Pictures = 0;
          Changed = 1;
          OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          OPTION1_BTN.drawButton(false);
          }
        
        if ((Draw_Pictures == 0) && (Changed ==0)) {
          Draw_Pictures = 1;
          Changed = 1;
          OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          OPTION1_BTN.drawButton(false);
        }
  delay(200);
 }


 // If the PCB Enabled Button is pressed
 if (OPTION2_BTN.justPressed() ) {

        int Button_W = 120;                // width of the button
        int Button_H = 60;                // height of the button
        
        int Button_X = Value_X2;
        int Button_Y = Value_Y2;
        bool Changed = 0;

        if ((PCB == 1) && (Changed ==0))  {
          PCB = 0;
          Changed = 1;
          OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          OPTION2_BTN.drawButton(false);
          }
        
        if ((PCB == 0) && (Changed ==0)) {
          PCB = 1;
          Changed = 1;
          OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          OPTION2_BTN.drawButton(false);
        }
  delay(200);
 }


 // If the Robot Type
 if (OPTION3_BTN.justPressed() ) {

        int Button_W = 120;                // width of the button
        int Button_H = 60;                // height of the button
        
        int Button_X = Value_X3;
        int Button_Y = Value_Y3;
        bool Changed = 0;

        if ((Robot_Type == 2) && (Changed == 0))  {
          Robot_Type = 1;
          Changed = 1;
          OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "Mower", 2);
          OPTION3_BTN.drawButton(false);
          }
        
        if ((Robot_Type == 1) && (Changed == 0)) {
          Robot_Type = 2;
          Changed = 1;
          OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, YELLOW, BLACK, "Aerator", 2);
          OPTION3_BTN.drawButton(false);
        }
  delay(200);
 }


 // CLEAR EEPROM
 if (OPTION4_BTN.justPressed() ) {

        int Button_W = 120;                // width of the button
        int Button_H = 60;                // height of the button
        
        int Button_X = Value_X4;
        int Button_Y = Value_Y4;
        bool Changed = 0;

        if ((Clear_EEPROM == 5) && (Changed == 0))  {
          Clear_EEPROM = 0;
          Changed = 1;
          OPTION4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "Cancel", 2);
          OPTION4_BTN.drawButton(false);
          }
        
        if ((Clear_EEPROM == 0) && (Changed == 0)) {
          Clear_EEPROM = 5;
          Changed = 1;
          OPTION4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "CLEAR", 2);
          OPTION4_BTN.drawButton(false);
        }
  delay(200);
 }

 
 // Action if Tip ensor Save is pressed
 if (SAVE_BTN.justPressed()) {
         Menu_Complete_Setup_Other = true;        

         if (Clear_EEPROM == 0)  {
         tft.fillScreen(BLACK);
         Serial.println(F("Tip Sensor Data Saved and TX"));
         EEPROM.write(2, 1);
         EEPROM.write(3, Draw_Pictures);          
         EEPROM.write(4, 1);
         EEPROM.write(5, Robot_Type);          
         Menu_Active = 930;
         Send_Menu_Selected_To_Mower_MEGA();
         Transmit_Setup_Other_Values();     
         }

         //Clear the TFT EEPROM
         if (Clear_EEPROM == 5)  {          
          Clear_EEPROM_Setings();
          tft.fillScreen(BLACK);
          tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
          tft.setCursor(50, 50);            // Text Coordinates X, Y
          tft.setTextSize(3); 
          tft.println("CLEARING ALL EEPROM!!");
          tft.setCursor(50, 80);            // Text Coordinates X, Y
          tft.print("Now..POWER CYCLE ROBOT");
          delay(3000);
         
         Menu_Active = 930;
         Send_Menu_Selected_To_Mower_MEGA();
         Transmit_Setup_Other_Values();
         Clear_EEPROM = 0;
         }
         
         
         Print_Settings_2_Menu();
         }  


        
}


void Sense_Button_Press_Setup_Other() {
    down = Touch_getXY();
    OPTION1_BTN.press (down && OPTION1_BTN.contains(pixel_x, pixel_y));
    OPTION2_BTN.press (down && OPTION2_BTN.contains(pixel_x, pixel_y));
    OPTION3_BTN.press (down && OPTION3_BTN.contains(pixel_x, pixel_y));
    OPTION4_BTN.press (down && OPTION4_BTN.contains(pixel_x, pixel_y));
    SAVE_BTN.press   (down && SAVE_BTN.contains(pixel_x, pixel_y));

    if (OPTION1_BTN.justReleased())  OPTION1_BTN.drawButton();
    if (OPTION2_BTN.justReleased())  OPTION2_BTN.drawButton();
    if (OPTION3_BTN.justReleased())  OPTION3_BTN.drawButton();
    if (OPTION4_BTN.justReleased())  OPTION4_BTN.drawButton();
    if (SAVE_BTN.justReleased())    SAVE_BTN.drawButton();
}
