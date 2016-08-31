//JCEBA.Util.h
char* filePath;

typedef struct point{
  float x;
  float y;
} Point;
typedef struct rectangle{
  Point p0;
  Point p1;
} JRectangle;

bool ENTER=0,MOUSE1=0;
float currentWidth=worldWidth,currentHeight=worldHeight;
int mouseX=0,mouseY=0;
int players=1;
int player1,player2,stage;
JRectangle pos_Explosion;

Point* mapPoints;

char* getLanguageStr(int n){
    switch(n){
        case 0: return "portugues";
        case 1: return "english";
        case 2: return "russkiy";
        case 3: return "hangug-ui";
        case 4: return "alearabia";
    }
}

float simplifyAngle(float Angle){
  int signal=1;
  if(Angle<0){
    signal*=-1;
    Angle*=-1;
  }
  while (Angle>360) {
    Angle-=360;
  }
  if(signal<0)
    Angle=360-Angle;
  if(Angle>180)
    Angle-=180;
  return Angle;
}

float radToAngle(float RAD,bool simplify){
  if(simplify)
    return simplifyAngle(RAD*180/PI);
  return RAD*180/PI;
}

float angleToRad(float RAD){
  return RAD*PI/180;
}

void setMapConfig(int n){
  if(n<1){
    nMapGen=250;                 //quantidade de pontos gerados
    variationMapGen=60;        //variacao maxima entre pontos
    smallVariationMapGen=10;    //variacao entre pontos
    mountainVariationMapGen=20;//variacao entre pontos no modo montanha
    mountainVerticalSize=100;   //tamanho maximo vertical da montanha
    mountainHorizontalSize=55;  //tamanho horizontal da montanha EM QUANTIDADE DE PONTOS
    mountainChance=120;          //chance de gerar uma montanha EM QUANTIDADE DE PONTOS  ((1*nMapGen)/mountainChance)%
    return;
  }
    nMapGen=mapType[n].nMapGen;
    variationMapGen=mapType[n].variationMapGen;
    smallVariationMapGen=mapType[n].smallVariationMapGen;
    mountainVariationMapGen=mapType[n].mountainVariationMapGen;
    mountainVerticalSize=mapType[n].mountainVerticalSize;
    mountainHorizontalSize=mapType[n].mountainHorizontalSize;
    mountainChance=mapType[n].mountainChance;
}

int strEq(char* str1, char*str2){
    int i,value = 1;
    for(i=0;str1[i]!='\0';i++)
        if(str1[i]!=str2[i]){
            value=0;
            break;
        }
    return value;
}

char* newPath(char* path){
  if(strEq(elementalPath,""))
    return path;
  else
    return strcat(elementalPath,path);
}

int getLanguageInt(char* in){
  if(strEq(in,"portugues"))
    return 0;
  if(strEq(in,"english"))
    return 1;
  if(strEq(in,"russkiy"))
    return 2;
  if(strEq(in,"hangug-ui"))
    return 3;
  if(strEq(in,"alearabia"))
    return 4;
  return 0;
}

int getNumberAlgo(int num){
  int divisor=1;
  int numberAlgo=0;
  do{
    numberAlgo++;
    divisor*=10;
  }while(num/divisor>0);
  return numberAlgo;
}

int randCountry(){
  switch (rand()%5) {
    case 0: return BRASIL;
    case 1: return RUSSIA;
    case 2: return ISLAMIC;
    case 3: return USA;
    case 4: return KOREA;
  }
}

char getCharEqInt(int i){
  switch (i) {
    default: return '0';
    case 1: return '1';
    case 2: return '2';
    case 3: return '3';
    case 4: return '4';
    case 5: return '5';
    case 6: return '6';
    case 7: return '7';
    case 8: return '8';
    case 9: return '9';
  }
}
void getAnimatedFiles(char* str1,int index,char*str2){
  str1=newPath(str1);
  int fullsize=getNumberAlgo(index)+strlen(str1)+strlen(str2)+1;
  filePath=(char*)realloc(filePath,fullsize*sizeof(char));
  int idxBkp=index;
  for(int i=0;i<fullsize;i++){
    if(i<strlen(str1))
      filePath[i]=str1[i];
    else if(i>=strlen(str1)&&i<strlen(str1)+getNumberAlgo(index)){
      filePath[i]=getCharEqInt((idxBkp-idxBkp%(int)round(pow(10,getNumberAlgo(idxBkp)-1)))/(int)round(pow(10,getNumberAlgo(idxBkp)-1)));
      idxBkp=idxBkp%(int)round(pow(10,getNumberAlgo(idxBkp)-1));
    }else
      filePath[i]=str2[i-strlen(str1)-getNumberAlgo(index)];
  }
}

void mapGen(){
  mapPoints=(Point*)realloc(mapPoints,(nMapGen+2)*sizeof(Point));
  float tmpWidth=-worldWidth/2;
  float randN0,randN1,randN2;
  int mapSignal=-1;
  int genaretingMountain=0,currentImountain=0;
  for(int i=1;i<=nMapGen;i++){
    mapPoints[i].x=tmpWidth;
    randN0=rand();
    randN1=(randN0/23.0-(int)randN0/23);
    if(i==1)
      randN2=(float)randN1*((rand()%(int)(variationMapGen/randN1/2)*10000))/10000;
    else{
      if(!(rand()%mountainChance)&&!genaretingMountain){
        genaretingMountain=1;
        currentImountain=i;
      }else if(i-currentImountain>=mountainHorizontalSize)
        genaretingMountain=0;
      if(!genaretingMountain)
        randN2=(float)randN1*((rand()%(int)(smallVariationMapGen/randN1/2)*10000))/10000;
      else
        randN2=(float)randN1*((rand()%(int)(mountainVariationMapGen/randN1/2)*10000))/10000;
    }
    if(rand()%2&&genaretingMountain==0) mapSignal*=-1;

    if(!genaretingMountain)
      mapPoints[i].y=averageGroundSpawn+randN2*mapSignal;
    else if(i-currentImountain>=mountainHorizontalSize/2)
      mapPoints[i].y=mapPoints[i-1].y+randN2*mapSignal;
    else
      mapPoints[i].y=mapPoints[i-1].y-randN2*mapSignal;

    if(!genaretingMountain){
      if(mapPoints[i].y>averageGroundSpawn+variationMapGen)mapPoints[i].y=averageGroundSpawn+variationMapGen;
      if(mapPoints[i].y<averageGroundSpawn-variationMapGen)mapPoints[i].y=averageGroundSpawn-variationMapGen;
    }else{
      if(mapPoints[i].y>averageGroundSpawn+mountainVerticalSize)mapPoints[i].y=averageGroundSpawn+mountainVerticalSize;
      if(mapPoints[i].y<averageGroundSpawn-mountainVerticalSize)mapPoints[i].y=averageGroundSpawn-mountainVerticalSize;
    }
    tmpWidth+=worldWidth/nMapGen*1.1;
    //printf("x:%.2f y:%.2f\n",mapPoints[i].x,mapPoints[i].y );
    //printf("randN:%.2f   randN1:%.2f   randN2:%.2f\n",randN0,randN1,randN2);
  }
  mapPoints[0].x=-worldWidth/2;
  mapPoints[0].y=-worldHeight/2;
  mapPoints[nMapGen].x=worldWidth/2;
  mapPoints[nMapGen+1].x=worldWidth/2;
  mapPoints[nMapGen+1].y=-worldHeight/2;
}

float dynamicX(float x){
  return x*currentWidth/worldWidth;
}

float dynamicY(float y){
  return y*currentHeight/worldHeight;
}
