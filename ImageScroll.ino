#include "TFT_eSPI.h"
#include "image.h"
TFT_eSPI tft= TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);


int imageW=480;
int imageH=270;

int screenW=240;
int screenH=135;
int m=imageW;

int start=1;
unsigned short imageS[32400]={0}; // edit this screenW * screen H


void setup() {
tft.init();
tft.setRotation(1);
tft.setSwapBytes(true);
tft.fillScreen(TFT_BLACK);

}
int pos=0;
int x=0;
int y=30;
int changeX=1;
int changeY=1;
void loop() {

  pos=x+imageW*y;
  start=pos;
  m=screenW+pos;
  for(int i=0;i<screenW*screenH;i++)
  {
  if(start%m==0)
  {
  start=start+(imageW-screenW);
  m=m+imageW;
  }
  imageS[i]=picture[start];
  start++;
  
  }
  x=x+changeX;
  if(x==imageW-screenW-1 || x<0)
  changeX=changeX*-1;

   y=y+changeY;
  if(y==imageH-screenH-1 || y<0)
  changeY=changeY*-1;
  
  tft.pushImage(0,0,screenW,screenH,imageS);
  

}
