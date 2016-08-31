//listas
int title,subtitle,playIcon,optionsIcon,howtoIcon,
    quitIcon,fullscreenFront,optionsMenu,backButton,instructionsMenu,
    onePlayerButton,mapMenu,twoPlayersButton,Background,Smoke,G1,G2,WhoWon,continueIcon,parabol,heart,showBullet,scenarioExplode,Example;

int flagBR,flagUSA,flagIsla,flagKorea,flagRand,flagRussia,btnPlay2,MAP,flagXes,P1,P2,Bullet,showStrength,restore,mapConfigs;

JRectangle pos_global,pos_btnBack,pos_flagBR,pos_flagUSA,pos_flagIslamic,pos_flagKorea,pos_flagRussia,pos_title,
          pos_subtitle,pos_btnPlay,pos_btnOptions,pos_btnHowTo,pos_btnQuit,pos_btn1P,pos_btn2P,
          pos_Splash,pos_btnPlay2,pos_G1,pos_G2, pos_standartHeart,pos_ShowBullet,pos_showStrength,pos_flagRand;

Point pos_music, pos_wind,pos_mapgen,pos_difficulty,pos_lifeInitAmount,pos_bombInitAmount, pos_instructions,
      pos_pressEnterToContinue,pos_sound,pos_language,pos_WhoWon,pos_life,pos_player,pos_cheat,pos_angle,pos_VARangle,
      pos_strength,pos_resolution,pos_FPS,pos_bombs,pos_VARbombs,pos_projetile,pos_wind2,pos_VARwind,pos_currentMap;

void defineCords(){
  mapPoints=(Point*)malloc(1*sizeof(Point));
  pos_global.p0.x=-currentWidth/2;pos_global.p0.y=-currentHeight/2;
  pos_global.p1.x=currentWidth/2;pos_global.p1.y=currentHeight/2;
  pos_btnBack.p0.x=-350;pos_btnBack.p0.y=-250;pos_btnBack.p1.x=-230;pos_btnBack.p1.y=-220;
  pos_flagBR.p0.x=-180;pos_flagBR.p0.y=-160;pos_flagBR.p1.x=-80;pos_flagBR.p1.y=-90;
  pos_flagUSA.p0.x=-270;pos_flagUSA.p0.y=45;pos_flagUSA.p1.x=-170;pos_flagUSA.p1.y=115;
  pos_flagIslamic.p0.x=20;pos_flagIslamic.p0.y=-50;pos_flagIslamic.p1.x=120;pos_flagIslamic.p1.y=30;
  pos_flagKorea.p0.x=230;pos_flagKorea.p0.y=20;pos_flagKorea.p1.x=330;pos_flagKorea.p1.y=90;
  pos_flagRussia.p0.x=160;pos_flagRussia.p0.y=150;pos_flagRussia.p1.x=260;pos_flagRussia.p1.y=220;
  pos_flagRand.p0.x=220;pos_flagRand.p0.y=-180;pos_flagRand.p1.x=300;pos_flagRand.p1.y=-130;

  pos_standartHeart.p0.x=-150;pos_standartHeart.p0.y=266;pos_standartHeart.p1.x=pos_standartHeart.p0.x+20;pos_standartHeart.p1.y=pos_standartHeart.p0.y+20;
  pos_ShowBullet.p0.x=300;pos_ShowBullet.p0.y=-280;pos_ShowBullet.p1.x=pos_ShowBullet.p0.x+55;pos_ShowBullet.p1.y=pos_ShowBullet.p0.y+40;

  pos_title.p0.x=-400;pos_title.p0.y=0;pos_title.p1.x=400;pos_title.p1.y=250;
  pos_subtitle.p0.x=-350;pos_subtitle.p0.y=-100;pos_subtitle.p1.x=350;pos_subtitle.p1.y=20;
  pos_G1.p0.x=-200;pos_G1.p0.y=0;pos_G1.p1.x=0;pos_G1.p1.y=200;
  pos_G2.p0.x=0;pos_G2.p0.y=0;pos_G2.p1.x=200;pos_G2.p1.y=200;

  pos_btnPlay.p0.x=-50;pos_btnPlay.p0.y=-160;pos_btnPlay.p1.x=50;pos_btnPlay.p1.y=-130;
  pos_btnPlay2.p0.x=230;pos_btnPlay2.p0.y=-250;pos_btnPlay2.p1.x=350;pos_btnPlay2.p1.y=-220;
  pos_btnOptions.p0.x=-60;pos_btnOptions.p0.y=-200;pos_btnOptions.p1.x=60;pos_btnOptions.p1.y=-170;
  pos_btnHowTo.p0.x=-70;pos_btnHowTo.p0.y=-240;pos_btnHowTo.p1.x=70;pos_btnHowTo.p1.y=-210;
  pos_btnQuit.p0.x=-40;pos_btnQuit.p0.y=-280;pos_btnQuit.p1.x=40;pos_btnQuit.p1.y=-250;

  pos_btn1P.p0.x=-80;pos_btn1P.p0.y=-160;pos_btn1P.p1.x=80;pos_btn1P.p1.y=-130;
  pos_btn2P.p0.x=-80;pos_btn2P.p0.y=-200;pos_btn2P.p1.x=80;pos_btn2P.p1.y=-170;

  pos_showStrength.p0.x=-150;pos_showStrength.p0.y=-280;pos_showStrength.p1.x=pos_showStrength.p0.x+140;pos_showStrength.p1.y=pos_showStrength.p0.y+35;

  pos_FPS.x=-350;pos_FPS.y=-170;
  pos_resolution.x=-350;pos_resolution.y=190;
    pos_music.x=-350;pos_music.y=150;
    pos_sound.x=-350;pos_sound.y=110;
    pos_wind.x=-350;pos_wind.y=70;
    pos_difficulty.x=-350;pos_difficulty.y=30;
    pos_lifeInitAmount.x=-350;pos_lifeInitAmount.y=-10;
    pos_bombInitAmount.x=-350;pos_bombInitAmount.y=-50;
    pos_mapgen.x=-350;pos_mapgen.y=-90;
    pos_language.x=-350;pos_language.y=-130;
  pos_WhoWon.x=-43;pos_WhoWon.y=-30;

  pos_life.x=-200;pos_life.y=270;
  pos_player.x=-350;pos_player.y=270;
  pos_cheat.x=240;pos_cheat.y=270;
  pos_wind2.x=145;pos_wind2.y=270;
  pos_VARwind.x=205;pos_VARwind.y=270;
  pos_angle.x=-380;pos_angle.y=-270;
  pos_strength.x=-235;pos_strength.y=-270;
  pos_bombs.x=0;pos_bombs.y=-270;
  pos_projetile.x=200;pos_projetile.y=-270;

  pos_VARangle.x=-310;pos_VARangle.y=-270;
  pos_VARbombs.x=150;pos_VARbombs.y=-270;

  pos_instructions.x=-350;pos_instructions.y=150;
  pos_pressEnterToContinue.x=-115;pos_pressEnterToContinue.y=-200;
}

void createList()
{
    Background=glGenLists(1);
    title=glGenLists(1);
    subtitle=glGenLists(1);
    playIcon=glGenLists(1);
    optionsIcon=glGenLists(1);
    howtoIcon=glGenLists(1);
    quitIcon=glGenLists(1);
    optionsMenu=glGenLists(10);
    backButton=glGenLists(1);
    instructionsMenu=glGenLists(14);
    onePlayerButton=glGenLists(1);
    twoPlayersButton=glGenLists(1);
    flagBR=glGenLists(1);
    flagUSA=glGenLists(1);
    flagIsla=glGenLists(1);
    flagKorea=glGenLists(1);
    flagRussia=glGenLists(1);
    flagRand=glGenLists(1);
    btnPlay2=glGenLists(1);
    MAP=glGenLists(1);
    flagXes=glGenLists(1);
    P1=glGenLists(1);
    P2=glGenLists(1);
    Bullet=glGenLists(1);
    Smoke=glGenLists(1);
    G1=glGenLists(1);
    G2=glGenLists(1);
    WhoWon=glGenLists(1);
    continueIcon=glGenLists(1);
    parabol=glGenLists(1);
    heart=glGenLists(1);
    showBullet=glGenLists(1);
    showStrength=glGenLists(1);
    scenarioExplode=glGenLists(1);
    mapMenu=glGenLists(8);
    restore=glGenLists(1);
    mapConfigs=glGenLists(1);
    Example=glGenLists(1);

    glNewList(mapMenu,GL_COMPILE);
      drawText(GLUT_BITMAP_HELVETICA_18,str_currentMap,pos_resolution,1);
        drawText(GLUT_BITMAP_HELVETICA_18,str_gndPoints,pos_music,1);
        drawText(GLUT_BITMAP_HELVETICA_18,str_varBtwPoints,pos_sound,1);
        drawText(GLUT_BITMAP_HELVETICA_18,str_minVarBtwPnts,pos_wind,1);
        drawText(GLUT_BITMAP_HELVETICA_18,str_varBtwMountains,pos_difficulty,1);
        drawText(GLUT_BITMAP_HELVETICA_18,str_mountainVsize,pos_lifeInitAmount,1);
        drawText(GLUT_BITMAP_HELVETICA_18,str_mountainHsize,pos_bombInitAmount,1);
        drawText(GLUT_BITMAP_HELVETICA_18,str_mountainChance,pos_mapgen,1);
    glEndList();

    glNewList(restore,GL_COMPILE);
        drawTexture(pos_btnPlay2,1,tex_btn_defaults,1);glEndList();
    glNewList(Example,GL_COMPILE);
        drawTexture(pos_btnPlay2,1,tex_btn_example,1);glEndList();

    glNewList(mapConfigs,GL_COMPILE);
        drawTexture(pos_btnQuit,0.99,tex_btn_mapconfigs,1);glEndList();
    glNewList(backButton,GL_COMPILE);
        drawTexture(pos_btnBack,0.99,tex_btn_Back,1);glEndList();
        glNewList(flagRand,GL_COMPILE);
          drawTexture(pos_flagRand,0.4,tex_flagRand,1);glEndList();
        glNewList(flagBR,GL_COMPILE);
          drawTexture(pos_flagBR,0.4,tex_flagBR,1);glEndList();
        glNewList(flagUSA,GL_COMPILE);//100x 70y
            drawTexture(pos_flagUSA,0.4,tex_flagUSA,1);glEndList();
        glNewList(flagIsla,GL_COMPILE);
            drawTexture(pos_flagIslamic,0.4,tex_flagIsla,1);glEndList();
        glNewList(flagKorea,GL_COMPILE);
            drawTexture(pos_flagKorea,0.4,tex_flagKorea,1);glEndList();
        glNewList(flagRussia,GL_COMPILE);
            drawTexture(pos_flagRussia,0.4,tex_flagRussia,1);glEndList();
        glNewList(G1,GL_COMPILE);
            drawTexture(pos_G1,1,tex_G,1);glEndList();
        glNewList(G2,GL_COMPILE);
            drawTexture(pos_G2,1,tex_G,1);glEndList();
        glNewList(continueIcon,GL_COMPILE);
            drawTexture(pos_btnPlay2,0.99,tex_btn_Continue,1);glEndList();
        glNewList(title,GL_COMPILE);
            drawTexture(pos_title,0,tex_JCEBA,1);glEndList();
    glNewList(subtitle,GL_COMPILE);    //subtitulo
        drawTexture(pos_subtitle,0.1,tex_Joguinho,1);glEndList();

        glNewList(playIcon,GL_COMPILE);    //jogar
            drawTexture(pos_btnPlay,0.5,tex_btn_Play,1);glEndList();
            glNewList(btnPlay2,GL_COMPILE);    //jogar
                drawTexture(pos_btnPlay2,1,tex_btn_Play,1);glEndList();
    glNewList(optionsIcon,GL_COMPILE);    //opcoes
        drawTexture(pos_btnOptions,0.5,tex_btn_Options,1);glEndList();
    glNewList(howtoIcon,GL_COMPILE);    //instrucoes
        drawTexture(pos_btnHowTo,0.5,tex_btn_HowTo,1);glEndList();
    glNewList(quitIcon,GL_COMPILE);    //sair
        drawTexture(pos_btnQuit,0.99,tex_btn_Exit,1);glEndList();

    glNewList(optionsMenu,GL_COMPILE);
        drawText(GLUT_BITMAP_HELVETICA_18,"FPS:",pos_FPS,0.4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_resolution,pos_resolution,0.4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_music,pos_music,0.4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_wind,pos_wind,0.4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_mapgen,pos_mapgen,0.4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_difficulty,pos_difficulty,0.4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_lifeInitAmount,pos_lifeInitAmount,0.4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_bombInitAmount,pos_bombInitAmount,0.4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_sound,pos_sound,0.4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_Language,pos_language,0.4);
    glEndList();

    glNewList(instructionsMenu,GL_COMPILE);
      pos_instructions.y=200;
      drawText(GLUT_BITMAP_HELVETICA_18,str_howToPlay0,pos_instructions,0.4);pos_instructions.y-=40;
      drawText(GLUT_BITMAP_HELVETICA_18,str_howToPlay1,pos_instructions,0.4);pos_instructions.y-=20;
      drawText(GLUT_BITMAP_HELVETICA_18,str_howToPlay2,pos_instructions,0.4);pos_instructions.y-=20;
      drawText(GLUT_BITMAP_HELVETICA_18,str_howToPlay3,pos_instructions,0.4);pos_instructions.y-=40;
      drawText(GLUT_BITMAP_HELVETICA_18,str_howToPlay4,pos_instructions,0.4);pos_instructions.y-=20;
      drawText(GLUT_BITMAP_HELVETICA_18,str_howToPlay5,pos_instructions,0.4);pos_instructions.y-=20;
      drawText(GLUT_BITMAP_HELVETICA_18,str_howToPlay6,pos_instructions,0.4);pos_instructions.y-=40;
      drawText(GLUT_BITMAP_HELVETICA_18,str_howToPlay7,pos_instructions,0.4);pos_instructions.y-=20;
      drawText(GLUT_BITMAP_HELVETICA_18,str_howToPlay8,pos_instructions,0.4);pos_instructions.y-=20;
      drawText(GLUT_BITMAP_HELVETICA_18,str_howToPlay9,pos_instructions,0.4);pos_instructions.y-=20;
      drawText(GLUT_BITMAP_HELVETICA_18,str_howToPlay10,pos_instructions,0.4);pos_instructions.y-=20;
      drawText(GLUT_BITMAP_HELVETICA_18,str_howToPlay11,pos_instructions,0.4);pos_instructions.y-=20;
      drawText(GLUT_BITMAP_HELVETICA_18,str_howToPlay12,pos_instructions,0.4);pos_instructions.y-=20;
      drawText(GLUT_BITMAP_HELVETICA_18,str_howToPlay13,pos_instructions,0.4);
    glEndList();

    glNewList(onePlayerButton,GL_COMPILE);
        drawTexture(pos_btn1P,0.5,tex_btn_1P,1);glEndList();
    glNewList(twoPlayersButton,GL_COMPILE);
        drawTexture(pos_btn2P,0.5,tex_btn_2P,1);glEndList();
}

void refreshFlagXes(JRectangle pos){
  glNewList(flagXes,GL_COMPILE_AND_EXECUTE);
    drawTexture(pos,0.5,tex_X,1);glEndList();
}

void refreshP1(JRectangle pos, GLuint tex, int orientation){
  glNewList(P1,GL_COMPILE_AND_EXECUTE);
    drawTexture(pos,0.52,tex,orientation);glEndList();
}

void refreshP2(JRectangle pos, GLuint tex, int orientation){
  glNewList(P2,GL_COMPILE_AND_EXECUTE);
    drawTexture(pos,0.52,tex,orientation);glEndList();
}

void refreshSmoke(JRectangle pos, GLuint tex, int ori){
  glNewList(Smoke,GL_COMPILE_AND_EXECUTE);
    drawTexture(pos,0.441,tex,ori);glEndList();
}

void refreshWhoWon(char* str){
  glNewList(WhoWon,GL_COMPILE_AND_EXECUTE);
      drawText(GLUT_BITMAP_HELVETICA_18,str,pos_WhoWon,1);
  glEndList();
}

void refreshBullet(JRectangle pos, GLuint tex, int orientation){
  glNewList(Bullet,GL_COMPILE_AND_EXECUTE);
    drawTexture(pos,0.44,tex,orientation);glEndList();
}

void refreshBackground(GLuint texture){
  glNewList(Background,GL_COMPILE);
      drawTexture(pos_global,-0.9,texture,1);glEndList();
}

void refreshShowBullet(GLuint texture){
  glNewList(showBullet,GL_COMPILE_AND_EXECUTE);
      drawTexture(pos_ShowBullet,1,texture,1);glEndList();
}
void refreshExplosion(GLuint texture){
  glNewList(scenarioExplode,GL_COMPILE_AND_EXECUTE);
      drawTexture(pos_Explosion,0.51,texture,1);glEndList();
}

void refreshShowStrength(){
  selectColor("black");
  glNewList(showBullet,GL_COMPILE_AND_EXECUTE);
  glLineWidth(1.6);
  glBegin(GL_LINE_LOOP);
       glVertex3f(pos_showStrength.p0.x, pos_showStrength.p0.y, 1);
       glVertex3f(pos_showStrength.p1.x, pos_showStrength.p0.y, 1);
       glVertex3f(pos_showStrength.p1.x, pos_showStrength.p1.y, 1);
       glVertex3f(pos_showStrength.p0.x, pos_showStrength.p1.y, 1);
   glEnd();
   if(players==1&&playerTurn==2){
     glEndList();
     return;
     }
     selectColor("violet");
     float barSize=((strengh-MINstrengh)*(140-1)/(MAXstrengh-MINstrengh));
     if(barSize<0)
      barSize*=-1;
     glBegin(GL_POLYGON);
          glVertex3f(pos_showStrength.p0.x+0.5, pos_showStrength.p0.y+0.5, 1);
          glVertex3f(pos_showStrength.p0.x-0.5+barSize, pos_showStrength.p0.y+0.5, 1);
          glVertex3f(pos_showStrength.p0.x-0.5+barSize, pos_showStrength.p1.y-0.5, 1);
          glVertex3f(pos_showStrength.p0.x+0.5, pos_showStrength.p1.y-0.5, 1);
      glEnd();
  glEndList();
}

void refreshHeart(int n){
  glNewList(heart,GL_COMPILE_AND_EXECUTE);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_ALPHA_TEST);
  glBindTexture(GL_TEXTURE_2D, tex_Heart);
  float aux=(pos_standartHeart.p1.x-pos_standartHeart.p0.x);
  if(aux<0)
    aux*=1;
  glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(pos_standartHeart.p0.x+n*aux, pos_standartHeart.p0.y, 1);
    glTexCoord2f(1, 0); glVertex3f(pos_standartHeart.p1.x+n*aux, pos_standartHeart.p0.y, 1);
    glTexCoord2f(1, 1); glVertex3f(pos_standartHeart.p1.x+n*aux, pos_standartHeart.p1.y, 1);
    glTexCoord2f(0, 1); glVertex3f(pos_standartHeart.p0.x+n*aux, pos_standartHeart.p1.y, 1);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  glDisable(GL_ALPHA_TEST);
  glColor4f(1,1,1,1);
  glEndList();
}

void refreshMapList(int stencil){
  if(stencil){
    glNewList(MAP,GL_COMPILE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_STENCIL_TEST);
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glDepthMask(GL_FALSE);
    glStencilFunc(GL_NEVER, 1, 0xFF);
    glStencilOp(GL_REPLACE, GL_KEEP, GL_KEEP);
    glStencilMask(0xFF);
    glClear(GL_STENCIL_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_QUAD_STRIP);//GL_LINE_LOOP
    for(int i=nMapGen+1;i>=0;i--){
      glVertex3f(mapPoints[i].x, -worldHeight/2,0.5);
      glVertex3f(mapPoints[i].x, mapPoints[i].y,0.5);
    }
    glEnd();
    if(stage==BRASIL)glBindTexture(GL_TEXTURE_2D, tex_texBR);
    if(stage==RUSSIA) glBindTexture(GL_TEXTURE_2D, tex_texRussia);;
    if(stage==KOREA) glBindTexture(GL_TEXTURE_2D, tex_texKorea);
    if(stage==ISLAMIC) glBindTexture(GL_TEXTURE_2D, tex_texIslamic);
    if(stage==USA) glBindTexture(GL_TEXTURE_2D, tex_texUSA);
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
      glDepthMask(GL_TRUE);
      glStencilMask(0x00);
      // aq
      glStencilFunc(GL_EQUAL, 0, 0xFF);
      //aq
      glStencilFunc(GL_EQUAL, 1, 0xFF);
      //aq
      glBegin(GL_POLYGON);
      glTexCoord2f(0, 0); glVertex3f(-worldWidth/2, -worldHeight/2, 0.5);
      glTexCoord2f(1, 0); glVertex3f(worldWidth/2, -worldHeight/2, 0.5);
      glTexCoord2f(1, 1); glVertex3f(worldWidth/2, worldHeight/2, 0.5);
      glTexCoord2f(0, 1); glVertex3f(-worldWidth/2,worldHeight/2, 0.5);
      glEnd();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_STENCIL_TEST);
    glEndList();
  }else{
    glNewList(MAP,GL_COMPILE);
    selectColor("violet");
    glBegin(GL_QUAD_STRIP);//GL_LINE_LOOP
    for(int i=nMapGen+1;i>=0;i--){
      glVertex3f(mapPoints[i].x, -worldHeight/2,0.5);
      glVertex3f(mapPoints[i].x, mapPoints[i].y,0.5);
    }
    glEnd();
    glEndList();
    glColor4f(1,1,1,1);
  }
}
