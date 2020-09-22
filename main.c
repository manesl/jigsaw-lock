/*
 * File:   project_main.c
 * Author: mane2
 *
 * Created on April 9, 2020, 8:41 PM
 */

//Task1:Display two images
//Task2:When you select one image, that image will be displayed but zoomed one and in center!
//Task3:extract the ID's of button to create an unique code
//Task4:use rand() to generate user id, srand() generates a seed for rand() using time(0)
//task5:re-organizing the code
//task6:creating a text entry box to get data
//task7:extracting the data from text entry box and checking whether the entered user id exists or not?
//task8:seed func
//task9:randomized blocks
//task10:re-organizing the code with different variable names, not possible, code runs erratic, 
//task10_new:make the both halves right and good transitions(why can't we add next button)
//task11:working with c data structure
//task12:delete buttons added and flash memory

#include "xc.h" // pic uc

#include "PICconfig.h" // clock
#include "HardwareProfile.h" // touch screen specs

#include "uMedia.h" //spi 

#include "Graphics/GOL.h" //msg call back, draw call back, delete by obj id
#include "Graphics/Graphics.h" //you get color from this, InitGraph(), SetColor(), ClearDevice()
#include "TouchScreen.h" //for touch screen ofcourse

#include "M25P80.h" //for flash memeory which i ll be using soon

#include "e.h"//btn1, bt3,4,5,6
#include "f.h"//btn2, bt7,8,9,10
#include "ar.h"

#include "LCDTerminal.h" //lcd init(), lcd put string()
#include "TimeDelay.h"//delays are never used
#include "Primitive.h"//this have all the basic functions

#include <stdio.h> //for sprintf this help us to display are variable values in string format! Remember!
#include <stdlib.h> //for rand and srand
#include <string.h> //for char or something
#include <stdbool.h>//for bool boolean
#include<time.h> //for srand seed as time(0)

#define PERIOD_MS 1 //1ms every 1 ms?
#define __ISR __attribute__((interrupt, shadow, no_auto_psv)) //just a macro to shorten things
#define TICK_PERIOD(ms) (GetPeripheralClock() *(ms))/8000 //why 8000, god knows?

//#define FONTDEFAULT TerminalFont
void Delay_us(unsigned long delay);


//for password
//int a[4]={0,0,0,0}; //a 4 bit code will be stored
int j=0;
int k=0;
int id=0; //for single user the id is generated
//char char_id[8]={0,0,0,0,0,0,0,0};//see the value which i extract from the text entry buffer comes like "21422//0//0//0"
//for the comparison purpose we want the id from random function to be stored as integer first then in string format like the one above "21422//0//0//0"
char print_user_id[]="";// to tell the user what user id is generated for him/her!
//int c[4]={0,0,0,0}; // to re enter the password combination

//void* id_entered;
//char match_user_id[]="";
TEXTENTRY *my;
TEXTENTRY *my2;
int id_entered[10]={0,0,0,0,0,0,0,0,0,0};
int id_entered2[10]={0,0,0,0,0,0,0,0,0,0};
XCHAR* textArray_TXE_2[]={"1","2","3","4","5","6","7","8","9","0","X","E"};
//char value[8]={0,0,0,0,0,0,0,0};//this is where you get the user entered value
int seed=0;

//just a string
char s[]="select an image";
char p_comb[]="";

//for password combination
int x1[4]={0,0,0,0};
int x2[4]={0,0,0,0};
int y1[4]={0,0,0,0};
int y2[4]={0,0,0,0};
int set;
int m=0;


void Delay_us(unsigned long delay)
{
    long i;
    for (i = 0; i < delay; i++)
    {
    __asm__ volatile ("repeat #39");
    __asm__ volatile ("nop");
    }
}

void TickInit(unsigned period_ms) //i think this should be capital and integer datatype //so may be  by default it takes int
{
    TMR3 = 0;//clear timer reg
    PR3 = TICK_PERIOD(period_ms); //a value given to match 
    
    T3CONbits.TCKPS=1; //prescale to 1:8
    
    IFS0bits.T3IF = 0;
    IEC0bits.T3IE = 1;
    T3CONbits.TON = 1;
}

void __ISR _T3Interrupt(void)
{
    _T3IF = 0; //seeing this I need to set the period register value and turn on the timer etc, check adc_uart_60Mhz_main.c
    TouchDetectPosition(); //after every 1 ms we will call this function to update the XY position if the finger again touches the screen, or we slide the finger across the screen
}

void start_init(void)
{
    //Initializations LCD and Touch
    uMBInit();//this is for SPI=Serial Flash, yes!
    LCDInit();
    
    DisplayBacklightOn();
    TickInit(1); //so every 1 ms we will look for a touch event
    TouchInit(NULL, NULL, NULL, NULL);//output black screen 
    LCDClear();
    Delay_us(100000);
    Delay_us(100000);
    Delay_us(100000);
    Delay_us(100000);
    DisplayBacklightOff();
   
    //GOL Initialization
    GOLInit();
    ClearDevice();
    DisplayBacklightOn(); 
}

void custom_init(void)
{
    DisplayBacklightOn();
    LCDInit();
    DisplayBacklightOff();
    GOLInit();
    DisplayBacklightOn();
}

struct mul_users //global struct
{
    /*char char_id[8]={0,0,0,0,0,0,0,0};
    char value[8]={0,0,0,0,0,0,0,0};
    int a[4]={0,0,0,0};
    int c[4]={0,0,0,0};
    int y=0; //there are only two images option, so whether the user selects the first or second matters*/
    char char_id[8];
    char value[8]; //use?
    int a[4];
    int c[4];
    int y;
    //int v;
}; //be default created space for 10 users

//struct mul_users user[10]={0,0,0,0,0,0,0,0,0,0};
struct mul_users user[10];
//struct mul_users user[10];
char c_value[8]={0,0,0,0,0,0,0,0};
//special screen variables
int x=1;
int b=1;//button create variables
//int y=1;//to recreate new buttons


int u=0;//by default for the user, will increment if the button is again pressed
int p;//for existing user

void DeleteObjects(void)
{
    int i=1;
    for(i=1;i<25;i++)
    {
        GOLDeleteObjectByID(i);
    }
}

int main(void) 
{
    //struct mul_users user[10]={0,0,0,0,0,0,0,0,0,0};
    GOL_MSG msg; //C data structures, GOL_MSG is a datatype like int, char but this would be medley of that

    start_init(); 
    /*struct
    {
     char *char_id[8] ={0,0,0,0,0,0,0,0};
     char *value[8] ={0,0,0,0,0,0,0,0};
     int a[4]={0,0,0,0};
     int c[4]={0,0,0,0};
    } user[10]; //be default created space for 10 users*/
    
    
    while(1)
    {
        switch(x)
        {
            case 1://screen 1
                if(b==1)
                {
                    //SetColor(BLACK);
                    //LCDSetXY(1,10);
                    //LCDPutString(s);
                    DeleteObjects();
                    custom_init();
                    
                    BtnCreate(21, 0, 0, 100, 100, 0, BTN_DRAW, NULL, "Create", NULL); //left, top, right, bottom = >> id, x1, y1, x2, y2 //create
                    BtnCreate(22, 105, 0, 205, 100, 0, BTN_DRAW, NULL, "Login", NULL); //left, top, right, bottom = >> id, x1, y1, x2, y2 //login
                    //PutImage(270, 190, (void*) &ar, IMAGE_NORMAL);
                    b=0;//button is created once
                }                
                if(GOLDraw())
                {
                    TouchGetMsg(&msg);
                    GOLMsg(&msg);
                }
                break;
            case 2://screen 1
                if(b==1)
                {
                    //GOLDeleteObjectByID(21);
                    //GOLDeleteObjectByID(22);
                    
                    DeleteObjects();
                    custom_init();
                    SetColor(BLACK);
                    LCDSetXY(1,10);
                    LCDPutString(s);
                    
                    BtnCreate(1, 0, 0, 100, 100, 0, BTN_DRAW, (void*)&e, NULL, NULL); //left, top, right, bottom = >> id, x1, y1, x2, y2
                    BtnCreate(2, 105, 0, 205, 100, 0, BTN_DRAW, (void*)&f, NULL, NULL); //left, top, right, bottom = >> id, x1, y1, x2, y2
                    //PutImage(270, 190, (void*) &ar, IMAGE_NORMAL);
                    b=0;//button is created once
                }                
                if(GOLDraw())
                {
                    TouchGetMsg(&msg);
                    GOLMsg(&msg);
                }
                break;
                
            case 3: //for screen 2 image 1
                if(b==1)
                {
                    /*GOLDeleteObjectByID(1);
                    GOLDeleteObjectByID(2);*/
                    DeleteObjects();
                    custom_init();
                    SetColor(RED);
                    OutTextXY(0,0, p_comb);
                    user[u].y=1;
                    BtnCreate(3, 110, 70, 160, 120, 0, BTN_DRAW, (void*)&e_1, NULL, NULL);
                    BtnCreate(4, 161, 70, 211, 120, 0, BTN_DRAW, (void*)&e_2, NULL, NULL);
                    BtnCreate(5, 110, 121, 160, 171, 0, BTN_DRAW, (void*)&e_3, NULL, NULL);
                    BtnCreate(6, 161, 121, 211, 171, 0, BTN_DRAW, (void*)&e_4, NULL, NULL);
                    PutImage(270, 190, (void*) &ar, IMAGE_NORMAL);
                    b=0;
                }
                if(GOLDraw())
                {
                    TouchGetMsg(&msg);
                    GOLMsg(&msg);
                    
                    if(j==4)
                    {
                        //wait for tapping
                        while(TouchGetX() <0); //wait for tapping
                        while(TouchGetX() >0); //wait for release
                        x=5;
                        b=1;
                    }
                }
                break;
                
            case 4: //for screen 2 image 2 ~ screen 3
                if(b==1)
                {
                    /*GOLDeleteObjectByID(1);
                    GOLDeleteObjectByID(2);*/
                    DeleteObjects();
                    //4 buttons creation  
                    custom_init();
                    SetColor(RED);
                    OutTextXY(0,0, p_comb);
                    user[u].y=2;
                    BtnCreate(7, 110, 70, 160, 120, 0, BTN_DRAW, (void*)&f_1, NULL, NULL);
                    BtnCreate(8, 161, 70, 211, 120, 0, BTN_DRAW, (void*)&f_2, NULL, NULL);
                    BtnCreate(9, 110, 121, 160, 171, 0, BTN_DRAW, (void*)&f_3, NULL, NULL);
                    BtnCreate(10, 161, 121, 211, 171, 0, BTN_DRAW, (void*)&f_4, NULL, NULL);
                    PutImage(270, 190, (void*) &ar, IMAGE_NORMAL);
                    b=0;
                }
                if(GOLDraw())
                {
                    TouchGetMsg(&msg);
                    GOLMsg(&msg);
                    if(j==4)
                    {
                        while(TouchGetX() <0); //wait for tapping
                        while(TouchGetX() >0); //wait for release
                        x=5;
                        b=1;
                    }
                }
                break;
                
            case 5: //user id created screen
                if(b==1)
                {
                /*GOLDeleteObjectByID(3);
                GOLDeleteObjectByID(4);
                GOLDeleteObjectByID(5);
                GOLDeleteObjectByID(6);
                    
                GOLDeleteObjectByID(7);
                GOLDeleteObjectByID(8);
                GOLDeleteObjectByID(9);
                GOLDeleteObjectByID(10);*/
                
                DeleteObjects();
                custom_init();  
                PutImage(270, 190, (void*) &ar, IMAGE_NORMAL);
                //my=TeCreate(11, 84, 86, 234, 236, TE_DRAW, 4, 3, textArray_TXE_2, id_entered, 30, NULL, NULL );
                b=0;
                }
                srand(seed);
                id=rand();
                //user[u].v=id;
                //sprintf(user[u].char_id,"%d",id); //storing the user id 
                sprintf(print_user_id, "The allocated user_id is %d", id);
                //LCDSetXY(1,2);
                //LCDPutString(print_user_id);//13163
                SetColor(RED);
                OutTextXY(0,0,print_user_id);
                while(TouchGetX() <0); //wait for tapping
                while(TouchGetX() >0); //wait for release
                //Delay_us(10000);
                //Delay_us(10000);
                x=6;
                b=1;
                seed++;//the next seed will generate new values
                break;
            case 6: //lets keep 6-7-8 for create user and 10-11-12 for existing user
                if(b==1)
                {
                    DeleteObjects();
                    custom_init();
                    //clear the buffer
                    my=TeCreate(20, 84, 86, 234, 236, TE_DRAW, 4, 3, textArray_TXE_2, id_entered, 30, NULL, NULL );
                    TeSetKeyCommand(my, 10, TE_DELETE_COM);
                    TeSetKeyCommand(my, 11, TE_ENTER_COM);
                    TeClearBuffer(my);
                    PutImage(270, 190, (void*) &ar, IMAGE_NORMAL);
                    sprintf(user[u].char_id,"%d",id);
                    b=0;
                }

                if(GOLDraw())
                {
                    TouchGetMsg(&msg);
                    GOLMsg(&msg);  
                }
                break;
            case 7:
                if(b==1)
                {
                    //int location[3]; //we will use random_numbers[4]
                    int i=0;
                    
                    //GOLDeleteObjectByID(20);
                    DeleteObjects();
                    custom_init();
                    SetColor(RED);
                    OutTextXY(0,0,"enter the combination");
                    
                    
                    srand(seed); //now seed is 1, previously it was 0, generated user id
                    seed++;//seed becomes 2
                    
                    //logic to generate unique sequence of random numbers with non repeats
                    int random_numbers[4]={5,5,5,5};
                    int count =0;
                    int l;
    
                    //srand(1);
	
                    while(count <4) 
                    {
                        int randNum;
                        randNum = rand()%4; //Generate a random number
                        bool found =false; //assume the random number hasnt been generated

                        //make sure the random number hasnt already been generated
                        for (l = 0; l < 4; l++) 
                        {
                            if(random_numbers[l] ==randNum) 
                            {
                                found =true;
                                break; //once we have located the number we dont need to continue checking
                            }
                        }

                        //we have a new random number
                        if(!found) 
                        {
                            random_numbers[count] = randNum;
                            count++;
                        }
                    }
                    
                    
                    for(i=0; i<4; i++)
                    {
                        set=random_numbers[i];
                        select_location(set); 
                    }
                    
                    if(user[u].y==1)
                    {
                    BtnCreate(11, x1[0], y1[0], x2[0], y2[0], 0, BTN_DRAW, (void*)&e_1, NULL, NULL); //btn 3
                    BtnCreate(12, x1[1], y1[1], x2[1], y2[1], 0, BTN_DRAW, (void*)&e_2, NULL, NULL); //btn 4
                    BtnCreate(13, x1[2], y1[2], x2[2], y2[2], 0, BTN_DRAW, (void*)&e_3, NULL, NULL); //btn 5
                    BtnCreate(14, x1[3], y1[3], x2[3], y2[3], 0, BTN_DRAW, (void*)&e_4, NULL, NULL); //btn 6
                    PutImage(270, 190, (void*) &ar, IMAGE_NORMAL);
                    //while(1);
                    b=0;
                    }
                    else if(user[u].y==2)
                    {
                    BtnCreate(15, x1[0], y1[0], x2[0], y2[0], 0, BTN_DRAW, (void*)&f_1, NULL, NULL); //btn 3
                    BtnCreate(16, x1[1], y1[1], x2[1], y2[1], 0, BTN_DRAW, (void*)&f_2, NULL, NULL); //btn 4
                    BtnCreate(17, x1[2], y1[2], x2[2], y2[2], 0, BTN_DRAW, (void*)&f_3, NULL, NULL); //btn 5
                    BtnCreate(18, x1[3], y1[3], x2[3], y2[3], 0, BTN_DRAW, (void*)&f_4, NULL, NULL); //btn 6
                    PutImage(270, 190, (void*) &ar, IMAGE_NORMAL);
                    //while(1);
                    b=0;  
                    }
                }
                
                if(GOLDraw())
                {
                    TouchGetMsg(&msg);
                    GOLMsg(&msg);
                    if(k==4)
                    {
                        while(TouchGetX() <0); //wait for tapping
                        while(TouchGetX() >0); //wait for release
                        x=8;
                        b=1;
                    }
                }
                break;
            case 8://the matching thingy
                if(b==1)
                {
                /*GOLDeleteObjectByID(3);
                GOLDeleteObjectByID(4);
                GOLDeleteObjectByID(5);
                GOLDeleteObjectByID(6);*/
                DeleteObjects();
                custom_init();
                PutImage(270, 190, (void*) &ar, IMAGE_NORMAL);
                b=0;
                }
                if(user[u].a[0]==user[u].c[0] && user[u].a[1]==user[u].c[1] && user[u].a[2]==user[u].c[2] && user[u].a[3]==user[u].c[3])
                {
                    SetColor(RED);
                    OutTextXY(0,0,"Login success");
                    
                    
                    //reinitialize every global counter
                    //j
                    //k
                    while(TouchGetX() <0); //wait for tapping
                    while(TouchGetX() >0); //wait for release
                    x=9;
                    //ask for creation of new user, increment u!!!!!
                }
                else
                {
                    SetColor(RED);
                    OutTextXY(0,0,"Combination incorrect");
                    while(TouchGetX() <0); //wait for tapping
                    while(TouchGetX() >0); //wait for release
                    x=9;
                    
                }
                break;
            case 9://this is for next user
                j=0;
                k=0;
                id=0;
                m=0;
                b=1;
                x=1;
                break; 





                
            case 10: //lets keep 6-7-8 for create user and 10-11-12 for existing user
                if(b==1)
                {
                    DeleteObjects();
                    custom_init();
                    //clear the buffer
                    my2=TeCreate(23, 84, 86, 234, 236, TE_DRAW, 4, 3, textArray_TXE_2, id_entered2, 30, NULL, NULL );
                    TeSetKeyCommand(my2, 10, TE_DELETE_COM);
                    TeSetKeyCommand(my2, 11, TE_ENTER_COM);
                    //TeClearBuffer(my2); //this is the buffer for text entry of existing users//after this my char_id is turning 0
                    PutImage(270, 190, (void*) &ar, IMAGE_NORMAL);
                    //sprintf(user[u].char_id,"%d",id);//need to find out u
                    b=0;
                }

                if(GOLDraw())
                {
                    TouchGetMsg(&msg);
                    GOLMsg(&msg);  
                }
                break;
            case 11:
                if(b==1)
                {
                    //int location[3]; //we will use random_numbers[4]
                    int i=0;
                    
                    //GOLDeleteObjectByID(20);
                    DeleteObjects();
                    custom_init();
                    SetColor(RED);
                    OutTextXY(0,0,"enter the combination");
                    
                    
                    srand(seed); //now seed is 1, previously it was 0, generated user id
                    seed++;//seed becomes 2
                    
                    //logic to generate unique sequence of random numbers with non repeats
                    int random_numbers[4]={5,5,5,5};
                    int count =0;
                    int l;
    
                    //srand(1);
	
                    while(count <4) 
                    {
                        int randNum;
                        randNum = rand()%4; //Generate a random number
                        bool found =false; //assume the random number hasnt been generated

                        //make sure the random number hasnt already been generated
                        for (l = 0; l < 4; l++) 
                        {
                            if(random_numbers[l] ==randNum) 
                            {
                                found =true;
                                break; //once we have located the number we dont need to continue checking
                            }
                        }

                        //we have a new random number
                        if(!found) 
                        {
                            random_numbers[count] = randNum;
                            count++;
                        }
                    }
                    
                    
                    for(i=0; i<4; i++)
                    {
                        set=random_numbers[i];
                        select_location(set); 
                    }
                    
                    if(user[p].y==1)
                    {
                    BtnCreate(11, x1[0], y1[0], x2[0], y2[0], 0, BTN_DRAW, (void*)&e_1, NULL, NULL); //btn 3
                    BtnCreate(12, x1[1], y1[1], x2[1], y2[1], 0, BTN_DRAW, (void*)&e_2, NULL, NULL); //btn 4
                    BtnCreate(13, x1[2], y1[2], x2[2], y2[2], 0, BTN_DRAW, (void*)&e_3, NULL, NULL); //btn 5
                    BtnCreate(14, x1[3], y1[3], x2[3], y2[3], 0, BTN_DRAW, (void*)&e_4, NULL, NULL); //btn 6
                    PutImage(270, 190, (void*) &ar, IMAGE_NORMAL);
                    //while(1);
                    b=0;
                    }
                    else if(user[p].y==2)
                    {
                    BtnCreate(15, x1[0], y1[0], x2[0], y2[0], 0, BTN_DRAW, (void*)&f_1, NULL, NULL); //btn 3
                    BtnCreate(16, x1[1], y1[1], x2[1], y2[1], 0, BTN_DRAW, (void*)&f_2, NULL, NULL); //btn 4
                    BtnCreate(17, x1[2], y1[2], x2[2], y2[2], 0, BTN_DRAW, (void*)&f_3, NULL, NULL); //btn 5
                    BtnCreate(18, x1[3], y1[3], x2[3], y2[3], 0, BTN_DRAW, (void*)&f_4, NULL, NULL); //btn 6
                    PutImage(270, 190, (void*) &ar, IMAGE_NORMAL);
                    //while(1);
                    b=0;  
                    }
                }
                
                if(GOLDraw())
                {
                    TouchGetMsg(&msg);
                    GOLMsg(&msg);
                    if(k==4)
                    {
                        while(TouchGetX() <0); //wait for tapping
                        while(TouchGetX() >0); //wait for release
                        x=12;
                        b=1;
                    }
                }
                break;
            case 12://the matching thingy
                if(b==1)
                {
                /*GOLDeleteObjectByID(3);
                GOLDeleteObjectByID(4);
                GOLDeleteObjectByID(5);
                GOLDeleteObjectByID(6);*/
                DeleteObjects();
                custom_init();
                PutImage(270, 190, (void*) &ar, IMAGE_NORMAL);
                b=0;
                }
                if(user[p].a[0]==user[p].c[0] && user[p].a[1]==user[p].c[1] && user[p].a[2]==user[p].c[2] && user[p].a[3]==user[p].c[3])
                {
                    SetColor(RED);
                    OutTextXY(0,0,"Login success");
                    
                    
                    //reinitialize every global counter
                    //j
                    //k
                    while(TouchGetX() <0); //wait for tapping
                    while(TouchGetX() >0); //wait for release
                    x=9;
                    //ask for creation of new user, increment u!!!!!
                }
                else
                {
                    SetColor(RED);
                    OutTextXY(0,0,"Combination incorrect");
                    while(TouchGetX() <0); //wait for tapping
                    while(TouchGetX() >0); //wait for release
                    x=9;
                    
                }
                break;
       }
        
    }
    return 0;
}


//int set;
void select_location(set)
{
    switch(set)
    {
        case 0: //1st place
            x1[m]=110;
            y1[m]=70;
            x2[m]=160;
            y2[m]=120;
            m++;
            break;
            
        case 1: //2nd
            x1[m]=161;
            y1[m]=70;
            x2[m]=211;
            y2[m]=120;
            m++;
            break;
            
        case 2: //3rd
            x1[m]=110;
            y1[m]=121;
            x2[m]=160;
            y2[m]=171;
            m++;
            break;
            
        case 3: //4th
            x1[m]=161;
            y1[m]=121;
            x2[m]=211;
            y2[m]=171;
            m++;
            break;            
    }
}

WORD GOLMsgCallback( WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg)
{
    //struct mul_users user[10];
    //struct mul_users user[10]={0,0,0,0,0,0,0,0,0,0};
    
    if(pObj->ID == 1)
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
            x=3; //screen 2 for image 1
            b=1; //to create new buttons
         }     
    }
    
    if(pObj->ID == 2)
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
            x=4; //screen 2 for image 2
            b=1; //to create new buttons
         }     
    }
    
    
    
    //next buttons are for password creation
    if(pObj->ID == 3)
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
            /*LCDSetXY(1,10);
            LCDPutString("Button 10 is pressed");*/
            user[u].a[j] = pObj->ID;
            j++;
            while(TouchGetX() >0); //wait for release
            // to create a distinction between two taps
            
         }     
    }
    
    if(pObj->ID == 4)
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
         /*LCDSetXY(1,10);
         LCDPutString("Button 10 is pressed");*/
         user[u].a[j] = pObj->ID;
         j++;
         while(TouchGetX() >0); 
         }     
    }
    
    if(pObj->ID == 5)
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
         /*LCDSetXY(1,10);
         LCDPutString("Button 10 is pressed");*/
         user[u].a[j] = pObj->ID;
         j++;
         while(TouchGetX() >0); 
         }     
    }
    if(pObj->ID == 6)
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
         /*LCDSetXY(1,10);
         LCDPutString("Button 10 is pressed");*/
         user[u].a[j] = pObj->ID;
         j++;
         while(TouchGetX() >0); 
         }     
    }
    //when the combination will be entered again
    if(pObj->ID == 11)//3
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
            /*LCDSetXY(1,10);
            LCDPutString("Button 10 is pressed");*/
             
            if(x!=11)
            {
                user[u].c[k] = 3;
                k++;
                while(TouchGetX() >0);
            }
            else
            {
                user[p].c[k] = 3;
                k++;
                while(TouchGetX() >0);
            }
                
         }     
    }
    
    if(pObj->ID == 12)//4
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
         /*LCDSetXY(1,10);
         LCDPutString("Button 10 is pressed");*/
         if(x!=11)
            {
                user[u].c[k] = 4;
                k++;
                while(TouchGetX() >0);
            }
            else
            {
                user[p].c[k] = 4;
                k++;
                while(TouchGetX() >0);
            }
         }     
    }
    
    if(pObj->ID == 13)//5
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
         /*LCDSetXY(1,10);
         LCDPutString("Button 10 is pressed");*/
         if(x!=11)
            {
                user[u].c[k] = 5;
                k++;
                while(TouchGetX() >0);
            }
            else
            {
                user[p].c[k] = 5;
                k++;
                while(TouchGetX() >0);
            } 
         }     
    }
    if(pObj->ID == 14)//6
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
         /*LCDSetXY(1,10);
         LCDPutString("Button 10 is pressed");*/
         if(x!=11)
            {
                user[u].c[k] = 6;
                k++;
                while(TouchGetX() >0);
            }
            else
            {
                user[p].c[k] = 6;
                k++;
                while(TouchGetX() >0);
            } 
         }     
    }
    
    if(pObj->ID == 7)
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
         /*LCDSetXY(1,10);
         LCDPutString("Button 10 is pressed");*/
         user[u].a[j] = pObj->ID;
         j++;
         while(TouchGetX() >0); 
         }     
    }
    if(pObj->ID == 8)
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
         /*LCDSetXY(1,10);
         LCDPutString("Button 10 is pressed");*/
         user[u].a[j] = pObj->ID;
         j++;
         while(TouchGetX() >0); 
         }     
    }
    if(pObj->ID == 9)
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
         /*LCDSetXY(1,10);
         LCDPutString("Button 10 is pressed");*/
         user[u].a[j] = pObj->ID;
         j++;
         while(TouchGetX() >0); 
         }     
    }
    if(pObj->ID == 10)
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
         /*LCDSetXY(1,10);
         LCDPutString("Button 10 is pressed");*/
         user[u].a[j] = pObj->ID;
         j++;
         while(TouchGetX() >0); 
         }     
    }
    
    if(pObj->ID == 15)//7
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
         /*LCDSetXY(1,10);
         LCDPutString("Button 10 is pressed");*/
         if(x!=11)
            {
                user[u].c[k] = 7;
                k++;
                while(TouchGetX() >0);
            }
            else
            {
                user[p].c[k] = 7;
                k++;
                while(TouchGetX() >0);
            } 
         }     
    }
        if(pObj->ID == 16)//8
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
         /*LCDSetXY(1,10);
         LCDPutString("Button 10 is pressed");*/
         if(x!=11)
            {
                user[u].c[k] = 8;
                k++;
                while(TouchGetX() >0);
            }
            else
            {
                user[p].c[k] = 8;
                k++;
                while(TouchGetX() >0);
            } 
         }     
    }
        if(pObj->ID == 17)//9
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
         /*LCDSetXY(1,10);
         LCDPutString("Button 10 is pressed");*/
         if(x!=11)
            {
                user[u].c[k] = 9;
                k++;
                while(TouchGetX() >0);
            }
            else
            {
                user[p].c[k] = 9;
                k++;
                while(TouchGetX() >0);
            } 
         }     
    }
        if(pObj->ID == 18)//10
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
         /*LCDSetXY(1,10);
         LCDPutString("Button 10 is pressed");*/
         if(x!=11)
            {
                user[u].c[k] = 0;
                k++;
                while(TouchGetX() >0);
            }
            else
            {
                user[p].c[k] = 0;
                k++;
                while(TouchGetX() >0);
            } 
         }     
    }
    
    if(pObj->ID==20)//text entry box
    {
        BOOL z;
        //BOOL del;
        z = TeIsKeyPressed(my, 11);
        //del = TeIsKeyPressed(my, 10);
        /*if(del==TRUE)
        {
            TE_DELETE_COM;
        }*/
        if(z==TRUE)
        {
            OutTextXY(0,0,"User ID entered");
            /*Delay_us(10000);
            Delay_us(10000);
            Delay_us(10000);
            Delay_us(10000);
            Delay_us(10000);*/
        

            int i;
            for(i=0; i<10; i++)
            {
                c_value[i]=*TeGetBuffer(my);//this return the value
                TeGetBuffer(my)++;
            }
                    
                    bool found = false;
                    //int p; //tells us which user it is or person it is whose id exists
                    while(!found) 
                    {
                        //int u;

                        for (u = 0; u < 10; u++) //we have 10 users from 0-9
                        {
                            if(c_value[0]==user[u].char_id[0]) 
                            {
                                int i=1; //think if comparing length first, save processor cycles
                                for(i=1; i<8; i++)
                                {
                                    if(c_value[i]==user[u].char_id[i])
                                    {
                                        
                                        if(i==7)
                                        {
                                            //p=u; //we got the serial no.
                                            found=true; //we discovered that the user id exists
                                            OutTextXY(0,20,"User ID exists");
                                            while(TouchGetX() <0); //wait for tapping
                                            while(TouchGetX() >0); //wait for release
                                            x=7;
                                            b=1;
                                            //break;
                                        }
                                        continue;
                                    }
                   
                                    else
                                    {
                                        break;
                                    }
                                }
                                
                                if(found)
                                {
                                    break; //why to increment u and do further checking?
                                    
                                }
                            }
                        }

                        //we have a new random number
                        if(!found)
                        {
                            OutTextXY(0,20,"Invalid User id"); //give three attempts
                            break;//this helps us breaking from the while 
                        }
                        
                        
                    }//work on this section to traverse for the user id
                    
                    /*if(user[u].char_id[0]== user[u].value[0])
                    {
                        int i;
                        for (i=0; i<8; i++)
                        {
                            if(user[u].char_id[i]==user[u].value[i])
                            {

                                if(i==7)
                                {
                                    OutTextXY(0,20,"User ID exists");
                                    while(TouchGetX() <0); //wait for tapping
                                    while(TouchGetX() >0); //wait for release
                                    x=7;
                                    b=1;
                                }
                                continue;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }*/
            }
    }
    
    
     if(pObj->ID == 21)//10
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
         /*LCDSetXY(1,10);
         LCDPutString("Button 10 is pressed");*/
         //c[k] = 0;
         //k++; 
             x=2;
             b=1;
             u++;
         //while(TouchGetX() >0); //wait for release
         }     
    }
    
     if(pObj->ID == 22)//10
    {
         if(objMsg == BTN_MSG_PRESSED)
         {
         /*LCDSetXY(1,10);
         LCDPutString("Button 10 is pressed");*/
         //c[k] = 0;
         //k++;
            x=10;
            b=1;
            //we need to find out u
         //while(TouchGetX() >0); //wait for release
         }     
    }
    
    if(pObj->ID == 23)
    {
        BOOL z;
        z = TeIsKeyPressed(my2, 11);

        if(z==TRUE)
        {
            OutTextXY(0,0,"User ID entered");
            /*Delay_us(10000);
            Delay_us(10000);
            Delay_us(10000);
            Delay_us(10000);
            Delay_us(10000);*/
        

            int i;
            for(i=0; i<10; i++)
            {
                c_value[i]=*TeGetBuffer(my2);//this return the value
                TeGetBuffer(my2)++;
            }
                    
                    bool found = false;
                    //int p; //tells us which user it is or person it is whose id exists
                    while(!found) 
                    {
                        //int u;

                        for (p = 0; p < 10; p++) //we have 10 users from 0-9
                        {
                            if(c_value[0]==user[p].char_id[0]) 
                            {
                                int i=1; //think if comparing length first, save processor cycles
                                for(i=1; i<8; i++)
                                {
                                    if(c_value[i]==user[p].char_id[i])
                                    {
                                        
                                        if(i==7)
                                        {
                                            //p=u; //we got the serial no.
                                            found=true; //we discovered that the user id exists
                                            OutTextXY(0,20,"User ID exists");
                                            while(TouchGetX() <0); //wait for tapping
                                            while(TouchGetX() >0); //wait for release
                                            x=11;
                                            b=1;
                                            //break;
                                        }
                                        continue;
                                    }
                   
                                    else
                                    {
                                        break;
                                    }
                                }
                                
                                if(found)
                                {
                                    break; //why to increment u and do further checking?
                                    
                                }
                            }
                        }

                        //we have a new random number
                        if(!found)
                        {
                            OutTextXY(0,20,"Invalid User id"); //give three attempts
                            break;//this helps us breaking from the while 
                        }
                        
                        
                    }
           
        }
    }
    return 1;
}//GOL Msg Callback

WORD GOLDrawCallback()
{
    return 1;
} //GOL Draw Callback
