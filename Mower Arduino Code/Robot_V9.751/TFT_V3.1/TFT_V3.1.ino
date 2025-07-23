// ReP_AL Mower / Aerator Project Touchscreen Control


#define SerialMEGA Serial1              // Serial port for communication with Mower Mega
#include "SerialCom_non_blocking.h"
SerialCom SerialComMEGA (SerialMEGA, 40);

#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#include <TouchScreen.h>
#include <SPI.h>                        // f.k. for Arduino-1.5.2
#define USE_SDFAT
#include <SdFat.h>                      // Use the SdFat library
SdFatSoftSpi<12, 11, 13> SD;            //Bit-Bang on the Shield pins
#include <EEPROM.h>
  
#define MINPRESSURE 485                 // if multiple buttons are pressing increase this value
#define MAXPRESSURE 1000

#define SD_CS     10
#define NAMEMATCH ""                    // "" matches any name
#define NAMEMATCH "tiger"               // *tiger*.bmp
#define PALETTEDEPTH   8                // support 256-colour Palette
#define BMPIMAGEOFFSET 54
#define BUFFPIXEL      20

char namebuf[32] = "/";                 //BMP files in root directory
//char namebuf[32] = "/bitmaps/";       //BMP directory e.g. files in /bitmaps/*.bmp

File root;
int pathlen;

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSerif12pt7b.h>

#include <FreeDefaultFonts.h>


// ALL Touch panels and wiring is DIFFERENT
// copy-paste results from TouchScreen_Calibr_native.ino
// Ensure Landscape 3 is used as the calibration 

// You can try one of the following setups which I have successfully used 
// for screens I have received just remove the // next to the setup you want to use and insert in the setup not required.

// Screen Setup 1
const int XP = 8, XM = A2, YP = A3, YM = 9;                           //ID=0x9341               
const int TS_LEFT = 960, TS_RT = 94, TS_TOP = 910, TS_BOT = 108;       

// Screen Setup 2
//const int XP = 6, XM = A2, YP = A1, YM = 7;                             //ID=0x9486
//const int TS_LEFT = 960, TS_RT = 94, TS_TOP = 108, TS_BOT = 910; 

    

// Set the PIN OUTS for the Touch Screen Shield.
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

// declare all of the buttons to draw on the screen
Adafruit_GFX_Button UP1_BTN, UP2_BTN, UP3_BTN, UP4_BTN, UP5_BTN, UP6_BTN,
                    DOWN1_BTN, DOWN2_BTN, DOWN3_BTN, DOWN4_BTN, DOWN5_BTN, DOWN6_BTN,
                    OPTION_A_BTN, OPTION_B_BTN, OPTION_C_BTN, OPTION_D_BTN, OPTION_E_BTN,
                    OPTION1_BTN, OPTION2_BTN, OPTION3_BTN, OPTION4_BTN, OPTION5_BTN,
                    OPTION6_BTN, SAVE_BTN, SAVE4_BTN,
                    DONE_BTN, DONE2_BTN, DONE3_BTN,
                    Test1_btn, Test2_btn, Test3_btn, Test4_btn, Test5_btn,

                    Spare_btn,   

                    Save_Wheels_btn, Save_Blade_btn, Save_Movement_btn,
                    Save_Track_Find_Wire_btn, Save_Track_PID_btn,
                    
                    Next_btn,                  
                    Done4_btn, Done5_btn, Done6_btn, Done_GPS_btn,
                    
                                    
                    Cancel_QG_btn, Cancel_ED_btn, Clear_Error_btn,
                    Create_Fence_btn, Save_GPS_Point_btn, Save_Fence_btn,
                    Done_Compass_btn, Save_Wheel_Amp_btn;
                    

char Version[16] = "V9.751";

unsigned long time;
long Minutes_Passed;

bool refreshTFT = true;     
int   pixel_x, pixel_y;     //Touch_getXY() updates global vars
bool  down;
int   Loop = 0;
bool  Menu_Complete;
bool  Menu_Complete_2;
bool  Menu_Complete_Main;
bool  Menu_Complete_Mowing;
bool  Menu_Complete_Setup_Other;
bool  Menu_Complete_Settings;
bool  Menu_Complete_Settings_2;
bool  Menu_Complete_Settings_3;
bool  Menu_Complete_Stop;
bool  Menu_Complete_Motion;
bool  Menu_Complete_Sensors;
bool  Menu_Complete_Sensors_2;
bool  Menu_Complete_Sonar;
bool  Menu_Complete_Battery;
bool  Menu_Complete_Rain;
bool  Menu_Complete_Wheels;
bool  Menu_Complete_Blade;
bool  Menu_Complete_Movement;
bool  Menu_Complete_Tracking;
bool  Menu_Complete_Tracking_Exit;
bool  Menu_Complete_Track_PID;
bool  Menu_Complete_Find_Wire;
bool  Menu_Complete_GPS_Settings;
bool  Menu_Complete_Navigation;
bool  Menu_Complete_Time;
bool  Menu_Complete_AlarmX;
bool  Menu_Complete_Set_Time;
bool  Menu_Complete_Tests;
bool  Menu_Complete_Testing_2;
bool  Menu_Complete_Testing_3;
bool  Menu_Complete_Wire_Test;
bool  Menu_Complete_Sonar_Test;
bool  Menu_Complete_Compass_Test;
bool  Menu_Complete_GYRO_Test;
bool  Menu_Complete_Volt_Amp_Test;
bool  Menu_Complete_Tilt_Test;
bool  Menu_Complete_Bumper_Test;
bool  Menu_Complete_Quick_Start;
bool  Menu_Complete_Exit_Dock;
bool  Menu_Complete_Tip_Setup;
bool  Menu_Complete_Pattern;
bool  Menu_Complete_GPS_New_Fence;
bool  Menu_Complete_Compass;
bool  Menu_Complete_GPS;
bool  Menu_Complete_GYRO;
bool  Menu_Complete_Wheel_Amp_Test;
bool  Menu_Complete_Wheel_Amp_Block;
bool  Menu_Complete_Lift_Menu;
bool  Menu_Complete_Pixhawk_Menu;
bool  Menu_Complete_Wheel_Test;


int  Robot_Status_Value = 1;
int  Robot_Status_Value_Last = 1;
int  Mower_Error_Value = 0;
int  Mower_Error_Value_Last = 0;

int Clear_EEPROM;

bool Error_Printed_1 = 0;
bool Setup_Printed = 0;
bool Manual_Printed = 0;


// RX Transfer
int Data1;
int Data2;
int Data3;
int Data4;
int Data5;
int Data6;
int Data7;

// Docking
bool Docking_Complete;
bool Turn_To_Home;
bool Find_Wire_Track;
bool Go_To_Charging_Station; 
int Charging;
int Charging_Last;

// Mower Running Data
int Sonar_Status;
int Sonar_Status_Last;
int Wire_Status;
int Wire_Status_Last;
int Bumper_Status;
int Bumper_Status_Last;
int Loops;
int Loops_Last;
int Compass_Steering_Status;
int Compass_Steering_Status_Last;
int GPS_In_Out_TX = 1;
bool Wheel_Blocked_Status;
bool Wheel_Blocked_Status_Last;

// Aerator Running Status
int Drill_Status;
int Drill_Status_Last;
int Holes_Drilled_Today;
int Holes_Drilled_Total;
bool Count_New_Hole = false;

// TX Selected Menu Transmission
bool Quick_Go;
bool Exit_Dock;
bool Options;

// Sonar
int distance1;
int distance2;
int distance3;
int Wire_Sensor_Count;
int Sonar_Test_Cycles;

// Bumper
bool Bump_LH;
bool Bump_RH;



// GYRO
int GYRO_X_Angle;
int GYRO_Y_Angle;
int GYRO_Enabled;
float GPower;

// Wheel Blocked
int Wheel_Blocked;
int Test_Method;

// Motor Menu

int PWM_MaxSpeed_LH;
int PWM_MaxSpeed_RH;
int PWM_Slow_Speed_LH;
int PWM_Slow_Speed_RH;
int Slow_Speed_MAG;
float Bar_Height;
float Gauge_Level_LH_Full;
float Gauge_Level_RH_Full;
float Gauge_Level_LH_Wire;
float Gauge_Level_RH_Wire;
float Gauge_Level_LH_Slow;
float Gauge_Level_RH_Slow;
bool Wheels_Activate; // RVES added

int Bar_Pos_X;                                 
int Bar_Pos_Y; 
int Bar_Width;
int Button_W;
int LH_RH_Spacing;

int   Wheel_Amp_Sensor_ON;
float Max_Wheel_Amps;
int WheelAmpsRX;		// RVES added
int WheelAmpsRX_Last; 	// RVES added


//Tracking
  bool Use_Charging_Station;       
  bool CW_Tracking_To_Charge;      
  bool CCW_Tracking_To_Charge;     
  bool CW_Tracking_To_Start;   
  bool CCW_Tracking_To_Start;
  int  Track_Wire_Zone_1_Cycles;
  int  Track_Wire_Zone_2_Cycles;
  int  Max_Tracking_Turn_Right;
  int  Max_Tracking_Turn_Left; 
  int  Max_Cycle_Wire_Find;    
  int  Max_Cycle_Wire_Find_Back;    
  int  Home_Wire_Compass_Heading;
  float P;  
  
  bool  Compass_Activate;
  bool  Compass_Heading_Hold_Enabled;
  float CPower;
       //GPS_Enabled_Last = GPS_Enabled;
   
//Compass
int    Compass_Heading_Degrees;
int	   Compass_Heading_Degrees_Last; 
float  Heading;
int    Compass_Setup_Mode;

  int Pos_X1;
  int Pos_Y1;

  int Pos_X2;
  int Pos_Y2;
  int Pos_X3;
  int Pos_Y3;
  int Pos_X4;
  int Pos_Y4;  
  int Pos_X5;
  int Pos_Y5;  
  int Pos_X6;
  int Pos_Y6;
  int Pos_X7;
  int Pos_Y7;
  int Button_X1;
  int Button_Y1;
  int Button_X2;
  int Button_Y2;
  int Button_X3;
  int Button_Y3;
  int Button_X4;
  int Button_Y4;
  int Button_X5;
  int Button_Y5;

//
  
// Blade Menu
bool Cutting_Blades_Activate;
float Gauge_Level_Blade;
int PWM_Blade_Speed;

int  Menu_Active;

int Command_Check;
int Transmission_OK;

// Sonar RX TX Values
int  Sonar_1_Activate;
int  Sonar_2_Activate;
int  Sonar_3_Activate;
int  Max_Sonar_Hit;
int  maxdistancesonar;

// Battery RX TX Values
float Battery;
float Battery_Last;
float Battery_Max; 
float Battery_Min; 
float Volts;
float Amps;
byte  Low_Battery_Instances_Chg;

// Rain RX TX Values
bool Rain_Sensor_Installed;  
int  Rain_Total_Hits_Go_Home;

//Wire WIFI RX TX Values
int Perimeter_Wire_Enabled;
int WIFI_Enabled;
int Bumper_Activate_Frnt;

// Wire Sensor
int INOUT;
int MAG;

// Tilt Sensor
bool Tilt_Angle_Sensed = 1;
bool Tilt_Angle_Sensed_Last = 1;
bool Tilt_Orientation_Sensed;
int  Angle_Sensor_Enabled;
int  Tip_Over_Sensor_Enabled;

// Movement

int Mower_Turn_Delay_Min;
int Mower_Turn_Delay_Max;
int Mower_Reverse_Delay;
int Max_Cycles_Straight;
int Label_X;
int Label_Y;
int Offset_Btn;

// Pattern_Mow
int Pattern_Mow;

int Turn_90_Delay_LH;           // adjust this number so the mower turns 90° Left
int Turn_90_Delay_RH;           // adjust this number so the mower turns 90° Right
int Move_to_next_line_delay;    // distance between lines
int Line_Length_Cycles;         // length of the line mowed
int Max_Cycles_Spirals;
float Compass_Mow_Direction;

// Exit Dock
int  Exit_Zone;
int  Mow_Time;

int   Value_1;
int   Value_2;
int   Value_3;
int   Value_4;
int   Value_5;
int   Value_6;
int   Value_7;
int   Value_8;


int   Value_All;
float Value_All_Float;
int   Value_X_All;
int   Value_Y_All;
int   Int_Float;

int   Txt_Size_Value;

// Position of the input value in the menu
int   Value_X1;
int   Value_Y1;
int   Value_X2;
int   Value_Y2;
int   Value_X3;
int   Value_Y3;
int   Value_X4;
int   Value_Y4;
int   Value_X5;
int   Value_Y5;
int   Value_X6;
int   Value_Y6;
int   Value_X7;
int   Value_Y7;
int   Value_X8;
int   Value_Y8;

// Time

  int  Alarm_X_Selected;
  bool Alarm_X_ON;                 
  int  Alarm_X_Hour;               
  int  Alarm_X_Minute;             
  bool Alarm_X_Repeat;                
  int  Alarm_X_Action = 1;

  bool Alarm_1_ON;                 
  int  Alarm_1_Hour;               
  int  Alarm_1_Minute;             
  bool Alarm_1_Repeat;                
  int  Alarm_1_Action; 


  bool Alarm_2_ON;                 
  int  Alarm_2_Hour;               
  int  Alarm_2_Minute;             
  bool Alarm_2_Repeat;                
  int  Alarm_2_Action; 

  bool Alarm_3_ON;                 
  int  Alarm_3_Hour;               
  int  Alarm_3_Minute;             
  bool Alarm_3_Repeat;                
  int  Alarm_3_Action; 

  byte Time_Second;
  byte Time_Minute;
  byte Time_Hour;
  byte Time_Date;
  byte Time_Month;
  int  Time_Year;
  byte Time_Day;
  int  Time_Loop = 1;


  int Spare = 0;

// GPS Menu

  bool  GPS_Enabled;
  bool  GPS_Enabled_Last;
  int   GPS_WIFI_Enabled = 0;
  int   Fence = 0;
  int   Simulation_Mode = 0;
  int   GPS_Lock_OK_TX;
  int   GPS_Type = 2;

  int   cycles;
  int   PWM_Arduino_LH;
  int   PWM_Arduino_RH;
  
// Pixhawk
bool PIXHAWK_Armed;
int PIXHAWK_Mode;

// Set the screen size, calibration
bool Touch_getXY(void) {
    TSPoint p = ts.getPoint();
    pinMode(YP, OUTPUT);      //restore shared pins
    pinMode(XM, OUTPUT);
    digitalWrite(YP, HIGH);   //because TFT control pins
    digitalWrite(XM, HIGH);
    bool pressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);
    if (pressed) {
        
        
        // Use this setting for Landscape 330
        pixel_x = map(p.y, TS_LEFT, TS_RT, 480, 0); //.kbv makes sense to me
        pixel_y = map(p.x, TS_TOP, TS_BOT, 320, 0);

   
    }
    return pressed;
}

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GREY    0x8410

// SETTINGS  -  EPROM Saved values will override these settings
//********************************************************

  int  Robot_Type                  = 1;                          // Set to 1 for Robot Mower & 2 for Robot Aerator
  bool Draw_Pictures = 1;
  int  PCB;
  int  Delay_Transmit = 400;
  int  Receive_Values_Delay = 750;
  int  Battery_Display = 2;
  bool Debug_RX_Transfer = 1;
  int  TFT_Check = 2000;
  int  RX_Delay = 1350;

/************************************************************************************************************/
      // struct for timer function in general.ino file
    struct timerVar_t
    {
    signed long ACC = 0;
    signed long REF = (signed long)millis();
    int PRE;
    bool flagRun = 0;
    };
    timerVar_t T10,T11,T12,T40,T50,T51,T52,T53,T70,T90;

    int Command; // Serial Command Input
    bool F_EN[33]; // Blocking bit for quick enable/ disable function

    String dayAsString(byte dayNo) {
      switch (dayNo) {
        case 1: return "Su";
        case 2: return "Mo";
        case 3: return "Tu";
        case 4: return "We";
        case 5: return "Th";
        case 6: return "Fr";
        case 7: return "Sa";
        default: return "??";
        }
    return "(unknown day)";
    }

/************************************************************************************************************/

void setup(void){

    Serial.begin(115200);         // Start the serial monitor
    SerialMEGA.begin(57600);      // 9600 Start the serial for transmitting the commands to the main MEGA on the mower
    Serial2.begin(9600);          // Start the serial to communicate with the GPS NodeMCU board
	  SerialComMEGA.begin();

    uint16_t ID = tft.readID();
    Serial.print(F("TFT ID = 0x"));
    Serial.println(ID, HEX);
    Load_EEPROM_Values();           // Load saved settings on TFT MEGA
    if (Robot_Type == 1) Serial.println(F("ReP_AL Mower Touchscreen"));
    if (Robot_Type == 2) Serial.println(F("ReP_AL Aerator Touchscreen"));
    Serial.print(F("Version: "));
    Serial.println(Version);
    Serial.println(F("Please Wait....."));
    if (ID == 0xD3D3) ID = 0x9486; // write-only shield
    tft.begin(ID);
    //tft.setRotation(1); 
    tft.setRotation(3);            //0 = PORTRAIT USB Top Right   1 = Landscape USB TL   2 =    Portrait USB BL    3 = Landacape USB  BR
    tft.fillScreen(BLACK);
    

    bool good = SD.begin(SD_CS);
    if (!good) {
      Serial.print(F("cannot start SD"));
        // Draw Red Circle with !
      tft.fillCircle(70, 150, 70, RED);             // X, Y, Radius
      tft.fillRect(60, 105, 20, 60 , WHITE);        // X, Y, Width, Height
      tft.fillRect(60, 175, 20, 20 , WHITE);        // X, Y, Width, Height  
      tft.setTextSize(3); 
      tft.setTextColor(GREEN, BLACK);           // Text Colour/ Background Colour
      tft.setCursor(50, 100); 
      tft.println(F("Cannot start SD !"));
      tft.setCursor(50, 130); 
      tft.println(F("SD Card Missing ?"));
      tft.setTextSize(2);
      tft.setCursor(50, 160); 
      tft.println(F("Continuing with pictures OFF"));
      tft.setCursor(50, 180); 
      tft.println(F("Check Card / Load BMPs."));
      Draw_Pictures = 0;
      delay(5000);
      tft.fillScreen(BLACK);
      //while (1);
    }


tft.setTextSize(2); 
tft.setTextColor(GREEN, BLACK);           // Text Colour/ Background Colour
tft.setCursor(0, 0);                      // Text Coordinates X, Y
if (Robot_Type == 1) tft.print(F("REP_AL Robot Lawn Mower: "));
if (Robot_Type == 2) tft.print(F("REP_AL Robot Aerator: "));
tft.println(Version);
tft.println(F(" "));
tft.println(F("STARTING TFT MENU"));
tft.println(F("PLEASE WAIT...."));
tft.println(F(" "));

if (Draw_Pictures == 1 ) bmpDraw("logo.bmp", 75, 80);
Get_Initial_Values();
delay(1000);   // just to display the logo :)
tft.fillScreen(BLACK);


for(int i=0; i<33; i++) { F_EN[i] = true; } // for CT debug
}  


void loop() {


  // Mower Status Values
  //    1 = Docked
  //    2 = Parked
  //    3 = Seup Mode APP
  //    4 = Error State
  //    5 = Mowing
  //    6 = Manual
  //    7 = Tracking
  //    8 = 
  //    9 = Exiting Dock


// Mower is in the Docked / Parked Status
//*************************************************************************************************
if ((Robot_Status_Value == 1) || (Robot_Status_Value == 2)) {
    Serial.println(F(""));
    if (Robot_Status_Value == 1) Serial.println(F("Mower is Docked"));
    if (Robot_Status_Value == 2) Serial.println(F("Mower is Parked"));
    if (Draw_Pictures == 1) {
      if (Robot_Type == 1) bmpDraw("mower1.bmp", 150, 90);      //Draw the mower picture
      if (Robot_Type == 2) bmpDraw("mower1.bmp", 150, 90);      //Draw the mower picture
      }
    delay(100);
    Print_Main_Menu_Graphic();
    Check_For_Active_Alarms();
    Menu_Complete_Main = false;
    Error_Printed_1 = 0;                                          // Clear the Error Drawn
    Setup_Printed = 0;                                            // Clear Setup on TFT
    Manual_Printed = 0;                                           // Clear Manual on TFT

    // Loop this code until the touchscreen is pressed
    while (Menu_Complete_Main == false) {
    		      Check_Serial_Input();  // RVES added
              Receive_Docked_Data();                                                               // Recieve the dock data from the MEGA and the mower status value
              Calculate_TFT_Time();
              if (TimerDelayOn(T12, 30000) || refreshTFT) Print_Date_TFT();   // Print the date on the TFT screen
              if (TimerDelayOn(T10, 10000) || refreshTFT) Print_Time_TFT();   //CT 30ms                                                        // Print the time on the TFT screen
              if ((TimerDelayOn(T11, 10000) || refreshTFT) && Battery > 8 ) Print_Battery_Graphic();                                           // Print the volts.
              Print_Error_Messages_Docked();  //CT 25ms                                            // Print any error messages to the TFT screen which can be fixed e.g. Wire OFF
              Print_Mower_Status();      //CT 60ms                                                 // Print the mower status to the TFT Screen
              refreshTFT = false;                                                                  // 
              
              // Wait a while to see if the TFT screen is touched.
              Sense_Button_Press_Main();
              React_to_Button_Press_Main();

              // Check if a valid Mower Status value has been received other than 1 = Docked and 2 = Parked
              // If a valid value is received then break the loop and set up the TFT screen for that mode.
              if ((Robot_Status_Value == 4) || (Robot_Status_Value == 5) || (Robot_Status_Value == 7) || (Robot_Status_Value == 9) || (Robot_Status_Value == 3) || (Robot_Status_Value == 6)) {
                  Serial.print(F("Mower Status Command Received. RSV = "));
                  Serial.println(Robot_Status_Value);
                  Menu_Complete_Main = true;  //  Break the while loop if the mower is not docked anymore but not for a missed RX = 0
                  }
              RuntimeMeasuring(); // loop cycle time measuring
              }
    
    tft.fillScreen(BLACK);
    }


//Mower is in Setup.
//*************************************************************************************************
if (Robot_Status_Value == 3) {
    Serial.println(F("Mower is in Setup APP Mode"));
    Print_Confirmation_Text_Setup(); 
    
    while (Robot_Status_Value == 3) {      
          Serial.print(F("Setup Mode: "));
          Receive_Setup_Data();
          Print_Confirmation_Text_Setup();                                            
          }
    tft.fillScreen(BLACK);
    }


//Mower is in Manual Mode.
//*************************************************************************************************
if (Robot_Status_Value == 6) {
    Serial.println(F("Mower is in Manual Drive Mode"));
    Print_Confirmation_Text_Manual_Mode(); 
    
    while (Robot_Status_Value == 6) {      
          Serial.print(F("Manual Mode: "));
          Receive_Docked_Data();
          Print_Confirmation_Text_Manual_Mode();   
          Serial.println(F(""));                                         
          }
    tft.fillScreen(BLACK);
    }


//Mower is in an Error State.
//*************************************************************************************************
if (Robot_Status_Value == 4) {
    Serial.println(F("Mower is in Error State"));
    Print_Confirmation_Text_ERROR(); 
    // Print Clear Error Button
    // Clear_Error_btn.initButton(&tft, 400, 260, 100, 60, WHITE, CYAN, BLACK, "CLEAR", 2);
    // Clear_Error_btn.drawButton(false);
    
    while (Robot_Status_Value == 4) {      
          Receive_Error_Data();
          Print_Confirmation_Text_ERROR();                                            
          }
    tft.fillScreen(BLACK);
    }


// Mower is Running and Mowing the Lawn
//*************************************************************************************************
if (Robot_Status_Value == 5) {
    Serial.println(F("Mower is Mowing"));
    Menu_Complete_Mowing = false;
    Loop = 0;
    Print_Mowing_Menu_Graphic();

    // Actions to continously monitor while mowing
    while (Menu_Complete_Mowing == false) { 
    	  Check_Serial_Input();  

        //Clear_TFT_Loop_Info_Mowing();                                     // Clear the last Loop Value
        if (Robot_Type == 1) Receive_Mower_Running_Data();                  // Large update when mower is stopped
        if (Robot_Type == 2) Receive_Aerator_Running_Data();                // Large update when mower is stopped
        if ((TimerDelayOn(T50, 10000)) && Battery > 8 ) Print_Battery_Graphic();
        if (TimerDelayOn(T51, 1000) || refreshTFT) {
        	Clear_TFT_Loop_Info_Mowing();
        	Update_TFT_Loop_Info_Mowing();                                    // Print the new Loop value
          }

        Update_TFT_Mower_Messages_Mowing();                                 // Update the TFT with central messages about the mowers status
        if ((Robot_Status_Value != 5) && (Robot_Status_Value != 0))  Menu_Complete_Mowing = true;
     
        // Give time for the touch screen to sense the STOP button being pressed
        Sense_Button_Press_Mowing();
        React_to_Button_Press_Mowing();
        refreshTFT = false;
		    RuntimeMeasuring(); // loop cycle time measuring             
        }
  tft.fillScreen(BLACK);
  }


//Mower is Tracking Home
//*************************************************************************************************
if (Robot_Status_Value == 7) {
    Serial.println(F("Mower is Tracking"));
    Print_Menu_Docking_Screen();
    
    while ((Docking_Complete == false) && (Robot_Status_Value ==7)) {
       Receive_Mower_Tracking_Data();
       delay(200);
       Print_Docking_Stage();      
       }
  tft.fillScreen(BLACK);
 }

//Mower is Exiting Dock
//*************************************************************************************************
if (Robot_Status_Value == 9) {
    Serial.println(F("Mower is Exiting the Dock")); 
    while (Robot_Status_Value == 9) {          
          Receive_Mower_Tracking_Data();
          Print_Confirmation_Text_Exit_Dock(); 
          }
    tft.fillScreen(BLACK);
    }



 }
