//texturas
#define nOfSplashImgs 24
GLuint tex_Splash[nOfSplashImgs];
GLuint tex_JCEBA,tex_mundiMap,tex_Joguinho,tex_MainMenu,tex_btn_1P,tex_btn_2P,tex_btn_Off,tex_btn_HowTo,tex_btn_Play,tex_btn_On,tex_btn_Options,tex_btn_Exit,tex_btn_Back;
GLuint tex_flagUSA,tex_flagBR,tex_flagKorea,tex_flagIsla,tex_flagRussia,tex_SubMenu0,tex_SubMenu1,tex_X;

void loadFiles(){
  filePath=(char*)malloc(1);

  for(int i=0;i<nOfSplashImgs;i++){
    getAnimatedFiles("Splash/corpLogo/",i,".png");
    tex_Splash[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  }
  tex_JCEBA=SOIL_load_OGL_texture("Splash/gameLogo/JCEBA3.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_Joguinho=SOIL_load_OGL_texture("Splash/gameLogo/JCEBA4.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_MainMenu=SOIL_load_OGL_texture("GUIandHUD/mainmenu.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_1P=SOIL_load_OGL_texture(btn_1P,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_2P=SOIL_load_OGL_texture(btn_2P,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_Off=SOIL_load_OGL_texture(btn_Off,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_HowTo=SOIL_load_OGL_texture(btn_HowTo,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_Play=SOIL_load_OGL_texture(btn_Play,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_On=SOIL_load_OGL_texture(btn_On,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_Options=SOIL_load_OGL_texture(btn_Options,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_Exit=SOIL_load_OGL_texture(btn_Exit,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_Back=SOIL_load_OGL_texture(btn_Back,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_mundiMap=SOIL_load_OGL_texture("Maps/worldMap.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);

  tex_flagUSA=SOIL_load_OGL_texture("Flags/usa.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_flagBR=SOIL_load_OGL_texture("Flags/brasil.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_flagKorea=SOIL_load_OGL_texture("Flags/coreia.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_flagIsla=SOIL_load_OGL_texture("Flags/islamico.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_flagRussia=SOIL_load_OGL_texture("Flags/russia.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_SubMenu0=SOIL_load_OGL_texture("GUIandHUD/submenu0.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_SubMenu1=SOIL_load_OGL_texture("GUIandHUD/submenu1.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_X=SOIL_load_OGL_texture("GUIandHUD/X.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);


  loadSound("c.wav",AL_TRUE);
  //alSourcePlay(ALsource[0]);

  filePath=(char*)realloc(filePath,1);

}
