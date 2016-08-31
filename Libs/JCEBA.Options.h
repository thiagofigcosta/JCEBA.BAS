int resolutionIdx=0;
bool alreadyGenMap=false;
float triedReshapping=0;
void drawMapValue(int option);

JRectangle currentResolution,currentMusic,currentSound,currentWind,currentdifficulty,
          currentInitLives,currentInitBombs,currentMap,currentLanguage,arrowMinus,arrowPlus;

Point currentMapMenuValue;

void defineOPT(){
        currentResolution.p0.x=80;currentResolution.p1.x=200;currentResolution.p0.y=180;currentResolution.p1.y=210;
        currentMusic.p0.x=80;currentMusic.p1.x=200;currentMusic.p0.y=140;currentMusic.p1.y=170;
        currentSound.p0.x=80;currentSound.p1.x=200;currentSound.p0.y=100;currentSound.p1.y=130;
        currentWind.p0.x=80;currentWind.p1.x=200;currentWind.p0.y=60;currentWind.p1.y=90;
        currentdifficulty.p0.x=120;currentdifficulty.p1.x=160;currentdifficulty.p0.y=20;currentdifficulty.p1.y=50;
        currentInitLives.p0.x=120;currentInitLives.p1.x=160;currentInitLives.p0.y=-20;currentInitLives.p1.y=10;
        currentInitBombs.p0.x=120;currentInitBombs.p1.x=160;currentInitBombs.p0.y=-60;currentInitBombs.p1.y=-30;
        currentMap.p0.x=120;currentMap.p1.x=160;currentMap.p0.y=-100;currentMap.p1.y=-70;
        currentLanguage.p0.x=80;currentLanguage.p1.x=200;currentLanguage.p0.y=-140;currentLanguage.p1.y=-110;
        currentMapMenuValue.x=120;currentMapMenuValue.y=180;
}

char* getResolution(int n){
  switch (n) {
  case 0: return "800x600";
  case 1: return "866x650";
  case 2: return "933x700";
  case 3: return "fullscreen";
  }
}

char* getDifficulty(int n){
  switch (n) {
  case 1: return str_ez;
  case 2: return str_normal;
  case 3: return str_hard;
  }
}

char* getState(int n){
  switch (n) {
  case 0: return str_off;
  default: return str_on;
}
}

void drawCharValue(char* in){
    int tam=strlen(in);
    currentMapMenuValue.y-=40;
    currentMapMenuValue.x=115-((float)tam/2.0)*10;
    for(int i=0;i<tam;i++){
        currentMapMenuValue.x+=13;
       // drawText(GLUT_BITMAP_HELVETICA_18,algorithm(i,option)+48,currentMapMenuValue,0.5);
        glRasterPos3f(currentMapMenuValue.x,currentMapMenuValue.y,1);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, in[i]);
    }
}

void drawCurrentOptions()
{
    selectColor("yellow");
    currentMapMenuValue.y=230;
    drawCharValue(getResolution(resolutionIdx));
    drawCharValue(getState(musicState));
    drawCharValue(getState(soundState));
    drawCharValue(getState(windState));
    drawCharValue(getDifficulty(difficulty));
    drawMapValue(initPlayerLifes);
    drawMapValue(initPlayerBombs);
    drawMapValue(mapPreConfig);
    drawCharValue(getLanguageStr(languageIdx));
    drawMapValue(gameFPS);
}

int algorithm(int position,int number){
    int r;
    int i;
    for(i=0;i<position;i++)
    {
        number=(number-number%10)/10;
    }
    return number%10;
}

void drawMapValue(int option){
    currentMapMenuValue.y-=40;
    currentMapMenuValue.x=135-((float)getNumberAlgo(option)/2.0)*10;
    for(int i=0;i<getNumberAlgo(option);i++){
        currentMapMenuValue.x+=10;
       // drawText(GLUT_BITMAP_HELVETICA_18,algorithm(i,option)+48,currentMapMenuValue,0.5);
        glRasterPos3f(currentMapMenuValue.x,currentMapMenuValue.y,1);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, algorithm((getNumberAlgo(option)-i-1),option)+48);
    }
}

void drawCurrentMapOptions(){
    selectColor("yellow");
    currentMapMenuValue.y=230;
    if(DEBUG)printf("%d %d %d %d %d %d %d \n",nMapGen,variationMapGen,smallVariationMapGen,
           mountainVariationMapGen,mountainVerticalSize,mountainHorizontalSize,mountainChance);
    drawMapValue(idxMap);
    drawMapValue(nMapGen);
    drawMapValue(variationMapGen);
    drawMapValue(smallVariationMapGen);
    drawMapValue(mountainVariationMapGen);
    drawMapValue(mountainVerticalSize);
    drawMapValue(mountainHorizontalSize);
    drawMapValue(mountainChance);
}

void compareArrowsPress(JRectangle r,int optionIdx,int addValue)
{
    int currentOption,maxOptionValue,minOptionValue;
    switch (optionIdx){
        case 0:{currentOption=resolutionIdx; maxOptionValue=3; minOptionValue=0; }break;
        case 1:{currentOption=musicState; maxOptionValue=1; minOptionValue=0; }break;
        case 2:{currentOption=soundState; maxOptionValue=1; minOptionValue=0; }break;
        case 3:{currentOption=windState; maxOptionValue=1; minOptionValue=0; }break;
        case 4:{currentOption=difficulty; maxOptionValue=3; minOptionValue=1; }break;
        case 5:{currentOption=initPlayerLifes; maxOptionValue=9; minOptionValue=1; }break;
        case 6:{currentOption=initPlayerBombs; maxOptionValue=3; minOptionValue=0; }break;
        case 7:{currentOption=mapPreConfig; maxOptionValue=5; minOptionValue=0; }break;
        case 8:{currentOption=languageIdx; maxOptionValue=4; minOptionValue=0; }break;
        case 9:{currentOption=gameFPS/30; maxOptionValue=2; minOptionValue=1; }break;
        case 10:currentOption=idxMap; maxOptionValue=(numMaps-1); minOptionValue=1; break;
        case 11:{currentOption=mapType[idxMap].nMapGen; maxOptionValue=400; minOptionValue=50; }break;
        case 12:{currentOption=mapType[idxMap].variationMapGen; maxOptionValue=600; minOptionValue=smallVariationMapGen; }break;
        case 13:{currentOption=mapType[idxMap].smallVariationMapGen; maxOptionValue=variationMapGen; minOptionValue=0; }break;
        case 14:{currentOption=mapType[idxMap].mountainVariationMapGen; maxOptionValue=mountainVerticalSize; minOptionValue=0; }break;
        case 15:{currentOption=mapType[idxMap].mountainVerticalSize; maxOptionValue=400; minOptionValue=0; }break;
        case 16:{currentOption=mapType[idxMap].mountainHorizontalSize; maxOptionValue=nMapGen; minOptionValue=0; }break;
        case 17:{currentOption=mapType[idxMap].mountainChance; maxOptionValue=nMapGen; minOptionValue=0; }break;
    }
    if(mouseX>=r.p0.x&&mouseY>=r.p0.y&&mouseX<=r.p1.x&&mouseY<=r.p1.y){
        glColor3f(0.15,0.15,0.15);
        if(MOUSE2){
                MOUSE2=0;
                if(soundState)alSourcePlay(ALsource[4]);
                        currentOption+=addValue;
                        if(currentOption>maxOptionValue)
                            currentOption=minOptionValue;
                        if(currentOption<minOptionValue)
                            currentOption=maxOptionValue;
                        switch (optionIdx){
                        case 0:{resolutionIdx=currentOption;}break;
                        case 1:{musicState=currentOption; stopAllSounds(-1);
                          ALint state;
                          alGetSourcei(ALsource[3],AL_SOURCE_STATE,&state);
                            if(AL_PLAYING != state)
                              if(musicState)alSourcePlay(ALsource[3]);
                            }break;
                        case 2:{soundState=currentOption;}break;
                        case 3:{windState=currentOption;}break;
                        case 4:{difficulty=currentOption;}break;
                        case 5:{initPlayerLifes=currentOption;}break;
                        case 6:{initPlayerBombs=currentOption;}break;
                        case 7:{mapPreConfig=currentOption;}break;
                        case 8:{languageIdx=currentOption;refreshLanguage();refreshBackground(tex_SubMenu0);
                        }break;
                        case 9:{gameFPS=currentOption*30;}break;
                        case 10:{idxMap=currentOption; setMapConfig(idxMap);}break;
                        case 11:{mapType[idxMap].nMapGen=currentOption;setMapConfig(idxMap);}break;
                        case 12:{mapType[idxMap].variationMapGen=currentOption;setMapConfig(idxMap);}break;
                        case 13:{mapType[idxMap].smallVariationMapGen=currentOption;setMapConfig(idxMap);}break;
                        case 14:{mapType[idxMap].mountainVariationMapGen=currentOption;setMapConfig(idxMap);}break;
                        case 15:{mapType[idxMap].mountainVerticalSize=currentOption;setMapConfig(idxMap);}break;
                        case 16:{mapType[idxMap].mountainHorizontalSize=currentOption;setMapConfig(idxMap);}break;
                        case 17:{mapType[idxMap].mountainChance=currentOption;setMapConfig(idxMap);}break;
                        }
                  }
    }else glColor4f(1,1,1,1);

}

void drawArrows(bool isMapEditing){
    if(!isMapEditing){
        arrowMinus.p0.x=40;arrowMinus.p1.x=70;
        arrowPlus.p0.x=210;arrowPlus.p1.x=240;
        for(int i=0;i<10;i++){
            arrowMinus.p0.y=180+i*-40;arrowMinus.p1.y=210+i*-40;
            arrowPlus.p0.y=180+i*-40;arrowPlus.p1.y=210+i*-40;
            compareArrowsPress(arrowMinus,i,-1);
            drawTexture(arrowMinus,1,tex_minusArrow,1);
            compareArrowsPress(arrowPlus,i,1);
            drawTexture(arrowPlus,1,tex_plusArrow,1);
        }
    }
    else {
        arrowMinus.p0.x=40;arrowMinus.p1.x=70;
        arrowPlus.p0.x=210;arrowPlus.p1.x=240;
        for(int i=0;i<8;i++){
            arrowMinus.p0.y=180+i*-40;arrowMinus.p1.y=210+i*-40;
            arrowPlus.p0.y=180+i*-40;arrowPlus.p1.y=210+i*-40;
            if(i>=1){
            compareArrowsPress(arrowMinus,i+10,-5);
            drawTexture(arrowMinus,1,tex_minusArrow,1);
            compareArrowsPress(arrowPlus,i+10,5);
            drawTexture(arrowPlus,1,tex_plusArrow,1);
          }else{
            compareArrowsPress(arrowMinus,i+10,-1);
            drawTexture(arrowMinus,1,tex_minusArrow,1);
            compareArrowsPress(arrowPlus,i+10,1);
            drawTexture(arrowPlus,1,tex_plusArrow,1);
          }
        }
    }
}

void changeResolution()//y-3 ?-4
{
    int windowPosX=glutGet(GLUT_WINDOW_X),windowPosY=glutGet(GLUT_WINDOW_Y);
    if(fullscreen)
        windowPosX=10,windowPosY=30;
    switch(resolutionIdx){
    case 0:{currentWidth=800 ;currentHeight=600 ;fullscreen=false;}break;
    case 1:{currentWidth=866 ;currentHeight=650 ;fullscreen=false;}break;
    case 2:{currentWidth=933 ;currentHeight=700 ;fullscreen=false;}break;
    case 3:{fullscreen=true;}break;
    }
    if(!fullscreen){
        glutReshapeWindow(currentWidth,currentHeight);
        glutPositionWindow(windowPosX,windowPosY);
    }
    else{
        glutFullScreen();
        currentWidth=glutGet(GLUT_SCREEN_WIDTH);currentHeight=glutGet(GLUT_SCREEN_HEIGHT);
        windowPosX=0;windowPosY=20;
    }
}

void currentOptions(){
    selectColor("yellow");
    defineOPT();
    drawCurrentOptions();
    drawArrows(false);
    changeResolution();
    if(loadFromFiles)saveSettings();
}

void warnReshapping(){
    glColor4f(1,1,0,triedReshapping);
    Point reshapeWarning;
    reshapeWarning.x=-200;reshapeWarning.y=270;
    drawText(GLUT_BITMAP_HELVETICA_18,str_toReshape,reshapeWarning,0.99);
    if(triedReshapping>0)
        triedReshapping-=0.01;
    if(triedReshapping<=0)
        triedReshapping=0;
}

void currentMapOptions(){
    drawCurrentMapOptions();
    drawArrows(true);
    if(loadFromFiles)saveMapConfig();
}

void restoreDefaultSettings(){
    musicState=1;
    soundState=1;
    windState=1;
    difficulty=1;
    initPlayerLifes=3;
    initPlayerBombs=1;
    mapPreConfig=0;
    gameFPS=60;
    stopAllSounds(-1);
      ALint state;
      alGetSourcei(ALsource[3],AL_SOURCE_STATE,&state);
        if(AL_PLAYING != state)
          if(musicState)alSourcePlay(ALsource[3]);
}
