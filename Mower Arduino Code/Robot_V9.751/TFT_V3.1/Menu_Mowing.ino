// MAIN SCREEN
//*********************************

void Print_Mowing_Menu_Graphic() {
    
    tft.fillScreen(BLACK);
    //bmpDraw("mower4.bmp", 150, 60);      //Draw the mower picture
      // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons

    int Start_X = 80;
    int Start_Y = 130;
    int Menu_Btn_Space = 100;          // Space between the adjacent buttons
    int Button_W = 130;                // width of the button
    int Button_H = 130;                // height of the button

    int Menu_Spacing = 20;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Txt_Size_Main_Menu = 2;



    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(20, 10);            // Text Coordinates X, Y
    if (Robot_Type == 1) tft.print(F("REP_AL Robot Lawn Mower: ")); 
    if (Robot_Type == 2) tft.print(F("REP_AL Robot Aerator: "));
    tft.print(Version);
    
    
    
    //STOP Button
    int Button_X = Start_X;
    int Button_Y = Start_Y;   
    OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "STOP", 2);
    OPTION1_BTN.drawButton(false);

    //Draw_Mower_Diagram();

		refreshTFT = true; 
		Label_TFT_Loop_Info_Mowing();
		Label_TFT_Mower_Messages_Mowing();
}
    
 

void React_to_Button_Press_Mowing() {

    // Actions if STOP button is pressed
    if (OPTION1_BTN.justPressed()) {
          Menu_Active = 13;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected   
          Menu_Complete_Stop = false;  
          tft.fillScreen(BLACK); 
          Serial.println(F("Quick Go Screen Selected"));
          Print_Stop_Menu_Graphic();   
          // Sense for the buttons until an option is pressed.
          while (Menu_Complete_Stop == false) {
            Sense_Button_Press_Stop();
            React_to_Button_Press_Stop();
            }
          
        }


}
    
void Sense_Button_Press_Mowing() {
    down = Touch_getXY();
    OPTION1_BTN.press                  (down && OPTION1_BTN.contains(pixel_x, pixel_y));  // STOP BUTTON
    if (OPTION1_BTN.justReleased())     OPTION1_BTN.drawButton();

}




  
