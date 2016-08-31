int idxSplash=-1,idxCredits=0;
int idxGG=0;
int auxPrepartida=-1;
bool gameCalled=0;
bool menuCalled=0;
bool preMenuCalled=0;
bool creditsCalled=0;
bool optionsCalled=0;
bool howToCalled=0;
bool numPlayersCalled=0;
bool chooseCharsCalled=0;
bool prePartidaCalled=0;
bool splashCalled=0;
bool escape=0;
bool restart=0;

void HUD(){
  char varTemp[50];
  if(players==2){
    if(playerTurn==2){
      glColor4f(1,1,1,1);
      for(int i=0;i<P2_life;i++)
        refreshHeart(i);
      selectColor("yellow");
      drawText(GLUT_BITMAP_HELVETICA_18,"Player 2",pos_player,1);
      drawText(GLUT_BITMAP_HELVETICA_18,str_Lifes,pos_life,1);
      drawText(GLUT_BITMAP_HELVETICA_18,str_wind,pos_wind2,1);
      if(wind<0)
        snprintf(varTemp, 50, "%d", -wind);
      else
        snprintf(varTemp, 50, "%d", wind);
      drawText(GLUT_BITMAP_HELVETICA_18,varTemp,pos_VARwind,1);
      drawText(GLUT_BITMAP_HELVETICA_18,str_Angle,pos_angle,1);
      snprintf(varTemp, 50, "%.2f", simplifyAngle(getAngle(0)));
      drawText(GLUT_BITMAP_HELVETICA_18,varTemp,pos_VARangle,1);
      drawText(GLUT_BITMAP_HELVETICA_18,str_Strength,pos_strength,1);
      drawText(GLUT_BITMAP_HELVETICA_18,str_AtomicBombs,pos_bombs,1);
      snprintf(varTemp, 50, "%d", P2_Bombs);
      drawText(GLUT_BITMAP_HELVETICA_18,varTemp,pos_VARbombs,1);
      drawText(GLUT_BITMAP_HELVETICA_18,str_Projetile,pos_projetile,1);
      if(cheatMode)
        drawText(GLUT_BITMAP_HELVETICA_18,str_CheatOn,pos_cheat,1);
      glColor4f(1,1,1,1);
      if(Bullet_type){
        if(player2==BRASIL)
          refreshShowBullet(tex_BulletDolly);
        else
          refreshShowBullet(tex_BulletAtomic);
      }else{
        if(player2==BRASIL)
          refreshShowBullet(tex_BulletBanana);
        else
          refreshShowBullet(tex_BulletRocket);
      }
      refreshShowStrength();
      glLineWidth(2);
      glColor4f(1,1,1,1);
      glBegin(GL_LINE_LOOP);
        if(!ainRadius)glVertex3f(mouseX,mouseY,1);
        else{
          float nX=cos(getAngle(1))*ainRadius,nY=sin(getAngle(1))*ainRadius;
          if(nX<0||mouseX<pos_P2.p0.x)nX*=-1;
          if((nY<0&&(!canAimDown||(players==1&&playerTurn==2)))||(playerTurn==2&&mouseX<pos_P2.p0.x&&players==2))nY*=-1;
          glVertex3f(nX,nY,1);
        }
        glVertex3f(pos_P2.p0.x,pos_P2.p1.y,1);
      glEnd();
      return;
    }
  }
  glColor4f(1,1,1,1);
  for(int i=0;i<P1_life;i++)
    refreshHeart(i);
  selectColor("yellow");
  drawText(GLUT_BITMAP_HELVETICA_18,"Player 1",pos_player,1);
  drawText(GLUT_BITMAP_HELVETICA_18,str_Lifes,pos_life,1);
  drawText(GLUT_BITMAP_HELVETICA_18,str_wind,pos_wind2,1);
  if(wind<0)
    snprintf(varTemp, 50, "%d", -wind);
  else
    snprintf(varTemp, 50, "%d", wind);
  drawText(GLUT_BITMAP_HELVETICA_18,varTemp,pos_VARwind,1);
  drawText(GLUT_BITMAP_HELVETICA_18,str_Angle,pos_angle,1);
  snprintf(varTemp, 50, "%.2f", simplifyAngle(getAngle(0)));
  drawText(GLUT_BITMAP_HELVETICA_18,varTemp,pos_VARangle,1);
  drawText(GLUT_BITMAP_HELVETICA_18,str_Strength,pos_strength,1);
  drawText(GLUT_BITMAP_HELVETICA_18,str_AtomicBombs,pos_bombs,1);
  snprintf(varTemp, 50, "%d", P1_Bombs);
  drawText(GLUT_BITMAP_HELVETICA_18,varTemp,pos_VARbombs,1);
  drawText(GLUT_BITMAP_HELVETICA_18,str_Projetile,pos_projetile,1);
  if(cheatMode)
    drawText(GLUT_BITMAP_HELVETICA_18,str_CheatOn,pos_cheat,1);
  glColor4f(1,1,1,1);
  if(Bullet_type&&playerTurn==1){
    if(player1==BRASIL)
      refreshShowBullet(tex_BulletDolly);
    else
      refreshShowBullet(tex_BulletAtomic);
  }else{
    if(player1==BRASIL)
      refreshShowBullet(tex_BulletBanana);
    else
      refreshShowBullet(tex_BulletRocket);
  }
  refreshShowStrength();
  if(playerTurn==1){
  glColor4f(1,1,1,1);
  glLineWidth(2);
  glBegin(GL_LINE_LOOP);
  if(!ainRadius)glVertex3f(mouseX,mouseY,1);
  else{
    float nX=cos(getAngle(1))*ainRadius,nY=sin(getAngle(1))*ainRadius;
    if(nX<0||mouseX<pos_P1.p1.x)nX*=-1;
    if((nY<0&&(!canAimDown||(players==1&&playerTurn==2)))||(playerTurn==2&&mouseX<pos_P2.p0.x&&players==2))nY*=-1;
    glVertex3f(nX,nY,1);
  }
    glVertex3f(pos_P1.p1.x,pos_P1.p1.y,1);
  glEnd();
}
}
void game(){
  if(!gameCalled){
    changeResolution();
    stopAllSounds(-1);
    initPlayerConfigs();
    setMapConfig(mapPreConfig);
    mapGen(); refreshMapList(useStencil);
    initBulletConfigs(playerTurn);
    mouseClicked=0;MOUSE1=0;idxGG=-1;lastShoot=0;
    prePartidaCalled=0;menuCalled=0;canGG=0; creditsCalled=0;
    strengh=MINstrengh;
    if(stage==BRASIL){ refreshBackground(tex_backBR); if(musicState)alSourcePlay(ALsource[5]);}
    if(stage==RUSSIA) {refreshBackground(tex_backRussia);if(musicState)alSourcePlay(ALsource[8]);}
    if(stage==KOREA) {refreshBackground(tex_backKorea);if(musicState)alSourcePlay(ALsource[7]);}
    if(stage==ISLAMIC) {refreshBackground(tex_backIslamic);if(musicState)alSourcePlay(ALsource[6]);}
    if(stage==USA) {refreshBackground(tex_backUSA);if(musicState)alSourcePlay(ALsource[9]);}
    gameCalled=1;
  }
  if(pause>0){
    if(cheatMode&&MOUSE1){
      selectColor("red");
      drawMissilePath();
    }
    glColor4f(1,1,1,1);
    glCallList(Background);
    glCallList(MAP);
    applyGravity();
    if(idxExplosion>0){
      if(explodeAtomic)
        selectColor("green");
      if(explodeNumber==1)
        refreshExplosion(tex_Explosion1[idxExplosion]);

      glColor4f(1,1,1,1);
    }
    if(players==1&&playerTurn==2&&P2_state!=2)
      AIturn();
    playerBehave();
    if(BulletIsVisible)
      BulletBehave();
    if(canGG) gg();
    glColor4f(1,1,1,1);
    refreshP1(pos_P1,P1_currentTex,P1_Ori);//
    if(player1==player2){
      selectColor("red");
      refreshP2(pos_P2,P2_currentTex,P2_Ori);
      glColor4f(1,1,1,1);
    }else
      refreshP2(pos_P2,P2_currentTex,P2_Ori);
  }else{

    glColor4f(1,1,1,1);
    glCallList(Background);
    glCallList(MAP);
    refreshP1(pos_P1,P1_currentTex,P1_Ori);//
    if(player1==player2){
      selectColor("red");
      refreshP2(pos_P2,P2_currentTex,P2_Ori);
      glColor4f(1,1,1,1);
    }else
      refreshP2(pos_P2,P2_currentTex,P2_Ori);

    glColor3f(0,0,1);
    if(escape){
      glRasterPos3f(-350,0,1);
      for (unsigned int i = 0;i<strlen(str_escape);i++) {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str_escape[i]);
      }
    }else if(restart){
      glRasterPos3f(-350,0,1);
      for (unsigned int i = 0;i<strlen(str_restart);i++) {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str_restart[i]);
      }
    }else{
      glRasterPos3f(-350,0,1);
      for (unsigned int i = 0;i<strlen(str_pause);i++) {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str_pause[i]);
      }
    }

    glColor4f(1,1,1,1);
    if(escape)
      escape=actionButtons(201);
    if(restart)
      restart=actionButtons(202);
    glColor4f(0,0,0,0.5);
    drawRectangle(pos_global,1);
  }
  if(pause>0&&P1_life>0&&P2_life>0)
    HUD();
}

void gg(){
  normalizeSprites();
  if(players==1){
    glColor4f(1,1,1,1);
    if(P1_life<=0){
      if(idxGG<0)idxGG=0;
      //continue e sair perdeu 1p
      currentScreen=actionButtons(98);
    }else if(P2_life<=0){
      if(idxGG<0){idxGG=0;
        if(stage==USA)  stage=0;
        if(stage==RUSSIA)stage=USA;
        if(stage==KOREA) stage=RUSSIA;
        if(stage==ISLAMIC) stage=KOREA;
        if(stage==BRASIL)stage=ISLAMIC;
      }
      if(stage==0) {
        //continue ganhou tudo 1p
        currentScreen=actionButtons(99);
      }else{//prox
        //continue e sair ganhou 1p
        currentScreen=actionButtons(98);
      }
    }
  }else{
    if(idxGG<0)idxGG=0;
    //continue 2p
    currentScreen=actionButtons(101);
  }
  glColor4f(1,1,1,1);
  glCallList(G1);
  if(idxGG>=45)
    glCallList(G2);
  selectColor("yellow");
  if(idxGG>=90)
    if(P1_life<=0){
      if(player2==BRASIL) refreshWhoWon(str_BRWon);
      if(player2==RUSSIA) refreshWhoWon(str_RussiaWon);
      if(player2==KOREA) refreshWhoWon(str_KoreaWon);
      if(player2==ISLAMIC) refreshWhoWon(str_IslamicWon);
      if(player2==USA) refreshWhoWon(str_USAWon);
    }else if(P2_life<=0){
      if(player1==BRASIL) refreshWhoWon(str_BRWon);
      if(player1==RUSSIA) refreshWhoWon(str_RussiaWon);
      if(player1==KOREA) refreshWhoWon(str_KoreaWon);
      if(player1==ISLAMIC) refreshWhoWon(str_IslamicWon);
      if(player1==USA) refreshWhoWon(str_USAWon);
    }
}
void menu(){
    glColor4f(1,1,1,1);
    if(!menuCalled){changeResolution(); menuCalled=1; optionsCalled=0; howToCalled=0; numPlayersCalled=0;stopAllSounds(3); prePartidaCalled=0;
    ALint state;
    alGetSourcei(ALsource[3],AL_SOURCE_STATE,&state);
      if(AL_PLAYING != state)
        if(musicState)alSourcePlay(ALsource[3]);
    refreshLanguage();
    refreshBackground(tex_MainMenu);
    }
    glCallList(Background);
    glColor4f(1,1,1,1);
    glCallList(title);
    glCallList(subtitle);
    glColor4f(R, G, B, A);
    currentScreen=actionButtons(MENU);
}

void preMenu(){
    glColor4f(1,1,1,1);
    if(!preMenuCalled){changeResolution();refreshBackground(tex_MainMenu); preMenuCalled=1; menuCalled=0; A=0;stopAllSounds(3); if(musicState)alSourcePlay(ALsource[3]);}
    glCallList(Background);
    glColor4f(1,1,1,A);
    glCallList(title);
    if(A>=1)
    {
        glColor4f(1,1,1,(A-1)*2);
        glCallList(subtitle);
        glColor4f(R, G, B, A);
    }
    if(A>=2)mapGen(); refreshMapList(0);
    {
        glColor4f(1,1,0,(A-2)*4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_pressEnterToContinue,pos_pressEnterToContinue,0.9);
    }
    if(ENTER||MOUSE1)
    {
        currentScreen=MENU;
        ENTER=0;
    }
}

void splash(){
  if(!splashCalled){
    changeResolution();
    if(rand()%arcoIrisChance==0){
      if(soundState)alSourcePlay(ALsource[0]);
    }else{
      if(soundState)alSourcePlay(ALsource[1]);
    }
  splashCalled=1;
  }
  pos_Splash.p0.x=-worldWidth/2;pos_Splash.p0.y=-114;
  pos_Splash.p1.x=worldWidth/2;pos_Splash.p1.y=114;
  if(DEBUG) printf("splash.");
  glColor4f(1,1,1,1);
  if(idxSplash==nOfSplashImgs-3)
    if(soundState)alSourcePlay(ALsource[2]);
  if(idxSplash<nOfSplashImgs-1)
    drawTexture(pos_Splash,1,tex_Splash[idxSplash],1);
  else
    drawTexture(pos_Splash,1,tex_Splash[nOfSplashImgs-1],1);
  glColor4f(R, G, B, A);
  if(idxSplash>=nOfSplashImgs+16){
    currentScreen=PREMENU;
    if(DEBUG) printf("..OK\n");
  }
}

void options(){
    glColor3f(1,1,1);
    if(!optionsCalled){refreshBackground(tex_SubMenu0); optionsCalled=1; menuCalled=0;stopAllSounds(3);}
    glCallList(Background);
    selectColor("yellow");
    glCallList(optionsMenu);
    selectColor("grey");
    currentScreen=actionButtons(OPCOES);
    currentOptions();
}
void mapEdit(){
    glColor3f(1,1,1);
    if(!optionsCalled){refreshBackground(tex_SubMenu0); optionsCalled=1; menuCalled=0;stopAllSounds(3);mapGen();alreadyGenMap=false; refreshMapList(0);}
    glCallList(Background);
    if(alreadyGenMap)glCallList(MAP);
    selectColor("yellow");
    glCallList(mapMenu);
    selectColor("grey");
    currentScreen=actionButtons(EDICAO_MAPA);
    currentMapOptions();
}

void howto(){
    glColor3f(1,1,1);
    if(!howToCalled){changeResolution();refreshBackground(tex_SubMenu1); howToCalled=1; menuCalled=0;stopAllSounds(3);}
    glCallList(Background);
    selectColor("yellow");
    glCallList(instructionsMenu);
    selectColor("grey");
    currentScreen=actionButtons(INSTRUCOES);
}

void credits(){
  if(!creditsCalled){refreshLanguage();preMenuCalled=0;stopAllSounds(-1);idxCredits=0;creditsCalled=1;alSourcePlay(ALsource[22]);}
  glColor4f(1,1,1,1);
  if(idxCredits<nOfCredits){
    refreshBackground(tex_Credits[idxCredits]);
    if(DEBUG) printf("idx: %d\n",idxCredits);
  }else{
    if(bugMODE)refreshBackground(tex_bixao);
    if(idxCredits>nOfCredits+23)
      currentScreen=PREMENU;
  }
  glCallList(Background);
  idxCredits++;
}

void numPlayers(){
    selectColor("red");
    if(!numPlayersCalled){changeResolution();refreshBackground(tex_MainMenu); numPlayersCalled=1; menuCalled=0; chooseCharsCalled=0;stopAllSounds(3);}
    glCallList(Background);
    selectColor("grey");
    currentScreen=actionButtons(NUM_JOGADORES);
}

void chooseChars(){
    FPS=90;
    stage=0;
    glColor4f(1,1,1,1);
    if(!chooseCharsCalled){changeResolution();refreshBackground(tex_mundiMap); chooseCharsCalled=1; numPlayersCalled=0; prePartidaCalled=0;stopAllSounds(3);}
    glCallList(Background);
    currentScreen=actionButtons(ESC_PERSONAGEM);
    if(players==2&&!permitEqualCountrys){
      if(player1==BRASIL) refreshFlagXes(pos_flagBR);//drawTexture(pos_flagBR,1,tex_X);
      if(player1==RUSSIA) refreshFlagXes(pos_flagRussia);//drawTexture(pos_flagRussia,1,tex_X);
      if(player1==KOREA) refreshFlagXes(pos_flagKorea);//drawTexture(pos_flagKorea,1,tex_X);
      if(player1==ISLAMIC) refreshFlagXes(pos_flagIslamic);//drawTexture(pos_flagIslamic,1,tex_X);
      if(player1==USA) refreshFlagXes(pos_flagUSA); //drawTexture(pos_flagUSA,1,tex_X);
    }
    glColor4f(R, G, B, A);
}

void prePartida(){
  glColor4f(1,1,1,1);
  if(!prePartidaCalled){changeResolution();refreshBackground(tex_mundiMap); stopAllSounds(3);prePartidaCalled=1; greyShade=0.5; chooseCharsCalled=0; gameCalled=0;
    ALint state;
    alGetSourcei(ALsource[3],AL_SOURCE_STATE,&state);
      if(AL_PLAYING != state)
        if(musicState)alSourcePlay(ALsource[3]);
  }
  glCallList(Background);
  if (players==1){
    stage=player2;
    if(player2>BRASIL){
      glCallList(flagBR);
      refreshFlagXes(pos_flagBR);
    }
    if(player2>ISLAMIC){
      glCallList(flagIsla);
      refreshFlagXes(pos_flagIslamic);
    }
    if(player2>KOREA){
      glCallList(flagKorea);
      refreshFlagXes(pos_flagKorea);
    }
    if(player2>RUSSIA){
      glCallList(flagRussia);
      refreshFlagXes(pos_flagRussia);
    }
  }else if(stage==0){
    stage=randCountry();
  }

  currentScreen=actionButtons(PRE_PARTIDA);
  //selectColor("penis");
  glColor3f(greyShade,greyShade,greyShade);
  if(stage==BRASIL)  glCallList(flagBR);//drawTexture(pos_flagBR,1,tex_flagBR,1);
  if(stage==RUSSIA) glCallList(flagRussia);//drawTexture(pos_flagRussia,1,tex_flagRussia);
  if(stage==KOREA) glCallList(flagKorea);//drawTexture(pos_flagKorea,1,tex_flagKorea);
  if(stage==ISLAMIC) glCallList(flagIsla);//rawTexture(pos_flagIslamic,1,tex_flagIsla);
  if(stage==USA) glCallList(flagUSA);//drawTexture(pos_flagUSA,1,tex_flagUSA);
}
