
//states you need to write
//title screen animation
//title screen-press a to begin
//game play 
//you lose, converted to borg
//you win, save picard from borg
//play again screen

#include "star.h"
#include <Arduboy2.h>
#include<ArduboyTones.h>
//ArduboyTones sound(arduboy.audio.enabled);
Arduboy2 ad;
#define WIDTH 128
#define HEIGHT 48



const unsigned char image[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xe0, 0x30, 0xc8, 0xf4, 0xfa, 
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 
    0xfd, 0xfd, 0xfd, 0x02, 0x3c, 0xc4, 0xf2, 0xfd, 
    0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 
    0xfd, 0xfd, 0xfd, 0xf8, 0x02, 0x04, 0x18, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0x3f, 0x40, 0x9f, 0x3f, 0x7f, 
    0xff, 0xff, 0xff, 0xfc, 0xfe, 0xfa, 0xfa, 0xf6, 
    0xca, 0x1a, 0xe2, 0xfa, 0xfa, 0xfa, 0xfa, 0xfa, 
    0x7a, 0x8a, 0x22, 0x9a, 0xe6, 0xfa, 0xfa, 0xfa, 
    0xfa, 0xfa, 0x3a, 0xf8, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0x7f, 0x83, 0xe4, 0xfa, 0xfa, 0xfa, 0xfa, 
    0xfa, 0xfa, 0xfa, 0xfa, 0xfc, 0xff, 0xff, 0xff, 
    0xff, 0x3f, 0xc7, 0x11, 0x02, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0xc0, 0x60, 0x80, 0xe0, 
    0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf5, 
    0xf6, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x9f, 0xe3, 
    0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 
    0xf3, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 
    0xe3, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x0f, 
    0xe1, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xcd, 
    0xe0, 0xeb, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 
    0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0x90, 
    0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 
    0xe8, 0xe8, 0xe8, 0xe8, 0xc8, 0x80, 0x20, 0xd0, 
    0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 
    0xe8, 0xe8, 0x68, 0x90, 0xe8, 0xe8, 0xe8, 0xe8, 
    0xe8, 0xe8, 0x90, 0xd0, 0xe8, 0xe8, 0xe8, 0xe8, 
    0xe8, 0xe8, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x17, 0x17, 
    0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
    0x07, 0x07, 0x0b, 0x0b, 0x05, 0x08, 0x16, 0x17, 
    0x17, 0x17, 0x17, 0x17, 0x07, 0x17, 0x17, 0x17, 
    0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
    0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x07, 0x17, 
    0x17, 0x17, 0x17, 0x17, 0x17, 0x0b, 0x00, 0x17, 
    0x17, 0x17, 0x17, 0x17, 0x17, 0x0b, 0x06, 0x17, 
    0x97, 0xd7, 0x17, 0xf7, 0xe7, 0xe7, 0xe7, 0xe7, 
    0xe7, 0x37, 0x97, 0x57, 0x17, 0xd7, 0xd4, 0xd7, 
    0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xc7, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0x7f, 0x8f, 0xd1, 0xd6, 0xd7, 
    0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 
    0x17, 0xdb, 0xd4, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 
    0xd7, 0xd7, 0xb7, 0x57, 0x97, 0x17, 0x17, 0x17, 
    0x17, 0x09, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3c, 
    0xc7, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x0f, 
    0xe1, 0x1c, 0xc3, 0xf8, 0xff, 0xff, 0xff, 0xff, 
    0x7f, 0x0f, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0x7f, 0x8f, 0xe3, 0xfc, 0xff, 0xff, 0xff, 0xff, 
    0x3f, 0x8f, 0xaf, 0xaf, 0xef, 0x0f, 0xe7, 0xfc, 
    0xff, 0xff, 0xff, 0xff, 0x7f, 0x8f, 0x1f, 0x7f, 
    0xff, 0xff, 0xff, 0xfe, 0xf0, 0xc3, 0x00, 0xc0, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x30, 0x4c, 0x21, 0xbc, 
    0xbf, 0xbf, 0xbf, 0xbf, 0x3f, 0x47, 0x18, 0x07, 
    0xb8, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x5f, 0x43, 
    0xb0, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x5f, 0x03, 
    0xbc, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 
    0xbf, 0xbf, 0xbf, 0x47, 0xb8, 0xbf, 0xbf, 0xbf, 
    0xbf, 0xbf, 0x4f, 0x23, 0x04, 0x00, 0x07, 0x38, 
    0x03, 0x1f, 0xbf, 0xbf, 0xbf, 0xbf, 0xbe, 0xb0, 
    0x43, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    
  };



#define S_WIDTH 128
#define S_HEIGHT 64
//gamestate and justpressed state
int gamestate = 0;
int jpress = 0;

//intro variables for cases
int background = 0;
int jp = 0;

//energy bolt
int bheight = 4;
int bwidth = 1;

//lives
int elives = 3;
int blives = 3;

//ent dimensions
int ex = 20;
int ey = 35;
//borg dimensions
int bx = 105;
int by = 25;
int br = 1;
int bd = 1;

//bolt dimensions
int boltx = ex;
int jpressa = 0;

bool fire = false;
      
void setup() {
  // put your setup code here, to run once:
  ad.boot();
  srand(7/8);
  ad.setFrameRate(60);
  ad.clear();
}

void captainsLog(){
  ad.drawRect(0,0,128,24);
  ad.setCursor(8,3);
  ad.print("FIRST OFFICER'S LOG");
  ad.setCursor(16,12);
  ad.print("STARDATE 12241.8");
}

void stars(){
  ad.drawPixel(8,30);ad.drawPixel(35,24);ad.drawPixel(115,12);ad.drawPixel(60,5);ad.drawPixel(130,20);
  ad.drawPixel(23,34);ad.drawPixel(1,10);ad.drawPixel(90,13);ad.drawPixel(30,60);ad.drawPixel(10,63);
  ad.drawPixel(50,52);ad.drawPixel(64,35);ad.drawPixel(100,50);ad.drawPixel(120,60);ad.drawPixel(80,55);
  
}

void enterprise(){
  ad.fillCircle(ex,ey,5,WHITE);
  ad.drawCircle(ex,ey,4,BLACK);
  ad.fillCircle(ex,ey,1,BLACK);
  ad.fillRect(ex-10,ey-1,7,3,WHITE);
  ad.fillRect(ex-15,ey-5,9,2,WHITE);
  ad.fillRect(ex-15,ey+4,9,2,WHITE);
}

void borg(){
  ad.fillRect(bx,by,20,20,WHITE);
  ad.drawRect(bx,by+5,15,15,BLACK);
  ad.drawRect(bx-3,by-3,10,20,BLACK);
  ad.drawRect(bx+10,by-8,8,17,BLACK);
  ad.drawRect(bx,by+7,3,22,BLACK);
  ad.drawRect(bx+8,by+10,15,15,BLACK);
  ad.drawRect(bx+17,by+15,10,10,BLACK);
}
void bolt(){
  ad.fillRect(bolt,ey,4,2,WHITE);
  boltx += 2;
}
void loop() {
  if(!ad.nextFrame()){
    return;  
  ad.pollButtons();
  }
  ad.clear();
  switch(gamestate){
    case 0:
      ad.drawBitmap(0, 0, image, WIDTH, HEIGHT, 1);
      stars();
      ad.setCursor(10,55);
      ad.print("PRESS A TO CONTINUE");
    //title screen stars
    //music (the four classic star trek notes)
    //logo + TNG music
    //press a to begin
    if(ad.pressed(RIGHT_BUTTON) and jpress== 0){
      jpress= 1;
      gamestate = 1;
      }
      break;
    case 1:
    //backgroud info
      switch(background){
        case 0:
          ad.clear();
          captainsLog();
          ad.print("\n\n In a failed mission\n to make contact with\n THE BORG, Capt. Jean\n Luc Picard....(DOWN)");
          if(ad.pressed(B_BUTTON) and jp ==0){
            jp=1;
            background = 1;
          }
          break;
        case 1:
          ad.clear();
          captainsLog();
          ad.print("\n\n has been captured!\n The USS ENTERPRISE\n must destroy THE\n BORG's energy source");          
          if(ad.pressed(B_BUTTON) and jp ==0){
            jp =1;
            background = 2;
          }
          break;
        case 2:
          ad.clear();
          captainsLog();
          ad.print("\n\n to prevent Captain\n Picard from being\n turned into THE\n LOCUTUS OF THE BORG!\n ---------------------");
          if(ad.pressed(B_BUTTON) and jp ==0){
            jp = 1;
            background = 3;
          }
          break;
         case 3:
          ad.setCursor(0,4);
          ad.print("\n\n\n to prevent Captain\n Picard from being\n turned into THE\n LOCUTUS OF THE BORG!\n ---------------------");
          ad.setCursor(8,4);
          ad.print("   ---PRESS R---");
          ad.print("\n  ---TO CONTINUE---");
          ad.drawRect(0,0,128,24);
      }
      if(ad.pressed(RIGHT_BUTTON) and jpress== 0){
      jpress= 1;
      gamestate = 2;
      }
      break;
 //-----------------------------------------GAMEPLAY-----------------------------------------------------------------------------
    case 2:
      stars();
    //gameplay, shooting at borg
      ad.print("TIM:");
      ad.print(elives);
      ad.setCursor(90,0);
      ad.print("BORG:");
      ad.print(blives);
      enterprise();
      //enterprise moves
      if(ad.pressed(UP_BUTTON) and ey >15){
        ey -=2;
      }
      if(ad.pressed(DOWN_BUTTON)and ey+6<63){
        ey+=2;
      }
      if(ad.pressed(A_BUTTON) and jpressa ==0){
        fire=true;
        jpressa = 1;
      }
      //make cpu moves below
      borg();

      if(br==1){
        bx+=1;
      }
      if(br ==-1){
        bx -=1;
      }
      if(bd ==1){
        by+=1;
      }
      if (bd==-1){
        by-=1;
      }
      if(by<=10){
        bd =1;
      }
      if(by>=50){
        bd=-1;
      }
      if(bx<=70){
        br +=1;
      }
      if(bx>=110){
        br -=1;
      }
      if(ey<=by){
        by +=1;
        
      }
      //ad.fillRect(boltx,ey,5,2,WHITE);
      //if(boltfire = 1){
        //boltx +=1;
      //}
     
      if(ad.pressed(RIGHT_BUTTON) and jpress== 0){
      jpress= 1;
      gamestate = 3;
      }
      break;

      

 //-----------------------------------------------------------------------//
    case 3:
    //you win, picard saved pic
    //press a to play again
      ad.print("win");
      if(ad.pressed(RIGHT_BUTTON) and jpress== 0){
      jpress= 1;
      gamestate = 2;
      }
      break;
    case 4:
      ad.print("lose");
      if(ad.pressed(RIGHT_BUTTON) and jpress== 0){
      jpress= 1;
      gamestate = 2;
      }
    //you lose, locutus of the borg merges u; YOU WILL BE ASSIMILATED
    //press a to play again
      break;
  }
  if(ad.notPressed(RIGHT_BUTTON)){
    jpress=0;
  }
  if(ad.notPressed(B_BUTTON)){
    jp = 0;
  }
  if(ad.notPressed(A_BUTTON)){
    jpressa = 0;
  }
  ad.display();
}
    

   
