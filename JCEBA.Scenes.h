//listas
int fullscreenBackground,title,subtitle,playIcon,optionsIcon,howtoIcon,
    quitIcon,fullscreenFront,optionsMenu,backButton,instructionsMenu,
    onePlayerButton,twoPlayersButton,mapBackground,sub0Background,sub1Background;

int flagBR,flagUSA,flagIsla,flagKorea,flagRussia;

Rectangle pos_global,pos_btnBack,pos_flagBR,pos_flagUSA,pos_flagIslamic,pos_flagKorea,pos_flagRussia,pos_title,
          pos_subtitle,pos_btnPlay,pos_btnOptions,pos_btnHowTo,pos_btnQuit,pos_btn1P,pos_btn2P,
          pos_Splash;

Point pos_music, pos_wind,pos_mapgen,pos_difficulty,pos_lifeInitAmount,pos_bombInitAmount, pos_instructions,
      pos_pressEnterToContinue,pos_sound,pos_language;

void defineCords(){
  pos_global.p0.x=-currentWidth/2;pos_global.p0.y=-currentHeight/2;
  pos_global.p1.x=currentWidth/2;pos_global.p1.y=currentHeight/2;
  pos_btnBack.p0.x=-350;pos_btnBack.p0.y=-250;pos_btnBack.p1.x=-230;pos_btnBack.p1.y=-220;
  pos_flagBR.p0.x=-180;pos_flagBR.p0.y=-160;pos_flagBR.p1.x=-80;pos_flagBR.p1.y=-90;
  pos_flagUSA.p0.x=-270;pos_flagUSA.p0.y=45;pos_flagUSA.p1.x=-170;pos_flagUSA.p1.y=115;
  pos_flagIslamic.p0.x=20;pos_flagIslamic.p0.y=-50;pos_flagIslamic.p1.x=120;pos_flagIslamic.p1.y=30;
  pos_flagKorea.p0.x=230;pos_flagKorea.p0.y=20;pos_flagKorea.p1.x=330;pos_flagKorea.p1.y=90;
  pos_flagRussia.p0.x=160;pos_flagRussia.p0.y=150;pos_flagRussia.p1.x=260;pos_flagRussia.p1.y=220;

  pos_title.p0.x=-400;pos_title.p0.y=0;pos_title.p1.x=400;pos_title.p1.y=250;
  pos_subtitle.p0.x=-350;pos_subtitle.p0.y=-100;pos_subtitle.p1.x=350;pos_subtitle.p1.y=20;

  pos_btnPlay.p0.x=-50;pos_btnPlay.p0.y=-160;pos_btnPlay.p1.x=50;pos_btnPlay.p1.y=-130;
  pos_btnOptions.p0.x=-60;pos_btnOptions.p0.y=-200;pos_btnOptions.p1.x=60;pos_btnOptions.p1.y=-170;
  pos_btnHowTo.p0.x=-70;pos_btnHowTo.p0.y=-240;pos_btnHowTo.p1.x=70;pos_btnHowTo.p1.y=-210;
  pos_btnQuit.p0.x=-40;pos_btnQuit.p0.y=-280;pos_btnQuit.p1.x=40;pos_btnQuit.p1.y=-250;

  pos_btn1P.p0.x=-80;pos_btn1P.p0.y=-160;pos_btn1P.p1.x=80;pos_btn1P.p1.y=-130;
  pos_btn2P.p0.x=-80;pos_btn2P.p0.y=-200;pos_btn2P.p1.x=80;pos_btn2P.p1.y=-170;

  pos_music.x=-350;pos_music.y=150;
  pos_wind.x=-350;pos_wind.y=110;
  pos_mapgen.x=-350;pos_mapgen.y=70;
  pos_difficulty.x=-350;pos_difficulty.y=30;
  pos_lifeInitAmount.x=-350;pos_lifeInitAmount.y=-10;
  pos_bombInitAmount.x=-350;pos_bombInitAmount.y=-50;
  pos_sound.x=-350;pos_bombInitAmount.y=-90;
  pos_language.x=-350;pos_bombInitAmount.y=-130;
  pos_instructions.x=-350;pos_instructions.y=150;
  pos_pressEnterToContinue.x=-115;pos_pressEnterToContinue.y=-200;
}

void createList()
{
    fullscreenBackground=glGenLists(1);
    fullscreenFront=glGenLists(1);
    title=glGenLists(1);
    subtitle=glGenLists(1);
    playIcon=glGenLists(1);
    optionsIcon=glGenLists(1);
    howtoIcon=glGenLists(1);
    quitIcon=glGenLists(1);
    optionsMenu=glGenLists(8);
    backButton=glGenLists(1);
    instructionsMenu=glGenLists(1);
    onePlayerButton=glGenLists(1);
    twoPlayersButton=glGenLists(1);
    mapBackground=glGenLists(1);
    flagBR=glGenLists(1);
    flagUSA=glGenLists(1);
    flagIsla=glGenLists(1);
    flagKorea=glGenLists(1);
    flagRussia=glGenLists(1);
    sub0Background=glGenLists(1);
    sub1Background=glGenLists(1);


    glNewList(fullscreenBackground,GL_COMPILE);
        drawTexture(pos_global,-0.9,tex_MainMenu);glEndList();
    glNewList(sub0Background,GL_COMPILE);
            drawTexture(pos_global,-0.9,tex_SubMenu0);glEndList();
    glNewList(sub1Background,GL_COMPILE);
        drawTexture(pos_global,-0.9,tex_SubMenu1);glEndList();

        glNewList(mapBackground,GL_COMPILE);
            drawTexture(pos_global,-0.9,tex_mundiMap);glEndList();

    glNewList(backButton,GL_COMPILE);
        drawTexture(pos_btnBack,0.4,tex_btn_Back);glEndList();

        glNewList(flagBR,GL_COMPILE);
          drawTexture(pos_flagBR,0.4,tex_flagBR);glEndList();
        glNewList(flagUSA,GL_COMPILE);//100x 70y
            drawTexture(pos_flagUSA,0.4,tex_flagUSA);glEndList();
        glNewList(flagIsla,GL_COMPILE);
            drawTexture(pos_flagIslamic,0.4,tex_flagIsla);glEndList();
        glNewList(flagKorea,GL_COMPILE);
            drawTexture(pos_flagKorea,0.4,tex_flagKorea);glEndList();
        glNewList(flagRussia,GL_COMPILE);
            drawTexture(pos_flagRussia,0.4,tex_flagRussia);glEndList();

    glNewList(title,GL_COMPILE);
        drawTexture(pos_title,0,tex_JCEBA);glEndList();
    glNewList(subtitle,GL_COMPILE);    //subtitulo
        drawTexture(pos_subtitle,0.1,tex_Joguinho);glEndList();

    glNewList(playIcon,GL_COMPILE);    //jogar
        drawTexture(pos_btnPlay,0.5,tex_btn_Play);glEndList();
    glNewList(optionsIcon,GL_COMPILE);    //opcoes
        drawTexture(pos_btnOptions,0.5,tex_btn_Options);glEndList();
    glNewList(howtoIcon,GL_COMPILE);    //instrucoes
        drawTexture(pos_btnHowTo,0.5,tex_btn_HowTo);glEndList();
    glNewList(quitIcon,GL_COMPILE);    //sair
        drawTexture(pos_btnQuit,0.5,tex_btn_Exit);glEndList();

    glNewList(optionsMenu,GL_COMPILE);
        drawText(GLUT_BITMAP_HELVETICA_18,str_music,pos_music,0.4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_wind,pos_wind,0.4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_mapgen,pos_mapgen,0.4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_difficulty,pos_difficulty,0.4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_lifeInitAmount,pos_lifeInitAmount,0.4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_bombInitAmount,pos_bombInitAmount,0.4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_sound,pos_sound,0.4);
        drawText(GLUT_BITMAP_HELVETICA_18,str_Language,pos_language,0.4);
    glEndList();
    //vamo deixar pra cirar os botoes qnd aprendermos a transladar eles

    glNewList(instructionsMenu,GL_COMPILE);
        drawText(GLUT_BITMAP_HELVETICA_18,str_howToPlay,pos_instructions,0.4);
    glEndList();

    glNewList(onePlayerButton,GL_COMPILE);
        drawTexture(pos_btn1P,0.5,tex_btn_1P);glEndList();
    glNewList(twoPlayersButton,GL_COMPILE);
        drawTexture(pos_btn2P,0.5,tex_btn_2P);glEndList();


}
