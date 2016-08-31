//texturas
#define nOfSplashImgs 24
#define nOfDamageImgs 3
#define nOfDieImgs 6
#define nOfFallImgs 2
#define nOfIdleImgs 4
#define nOfShotImgs 4
#define nOfWalkImgs 6
#define nOfSmokeImgs 5
#define nOfExplosion1Imgs 24
#define nOfCredits 66

GLuint tex_Splash[nOfSplashImgs],tex_Credits[nOfCredits],tex_bixao,tex_Heart,tex_plusArrow,tex_minusArrow,tex_btn_defaults,tex_btn_mapconfigs;
GLuint tex_JCEBA,tex_mundiMap,tex_Joguinho,tex_MainMenu,tex_btn_1P,tex_btn_2P,tex_btn_Off,tex_btn_HowTo,tex_btn_Play,tex_btn_On,tex_btn_Options,tex_btn_Exit,tex_btn_Back;
GLuint tex_flagUSA,tex_flagBR,tex_flagKorea,tex_flagIsla,tex_flagRussia,tex_SubMenu0,tex_SubMenu1,tex_X,tex_texBR,tex_texRussia,tex_texIslamic,tex_texUSA,tex_texKorea,
       tex_backBR,tex_backKorea,tex_backRussia,tex_backUSA,tex_backIslamic,tex_btn_Continue,tex_flagRand,tex_btn_example;
GLuint tex_BRDie[nOfDieImgs],tex_BRFall[nOfFallImgs],tex_BRIdle[nOfIdleImgs],tex_BRShot[nOfShotImgs],tex_BRWalk[nOfWalkImgs],tex_BRDamage[nOfDamageImgs],tex_BRTouchGround;
GLuint tex_USADie[nOfDieImgs],tex_USAFall[nOfFallImgs],tex_USAIdle[nOfIdleImgs],tex_USAShot[nOfShotImgs],tex_USAWalk[nOfWalkImgs],tex_USADamage[nOfDamageImgs],tex_USATouchGround;
GLuint tex_IslamicDie[nOfDieImgs],tex_IslamicFall[nOfFallImgs],tex_IslamicIdle[nOfIdleImgs],tex_IslamicShot[nOfShotImgs],tex_IslamicWalk[nOfWalkImgs],tex_IslamicDamage[nOfDamageImgs],tex_IslamicTouchGround;
GLuint tex_KoreaDie[nOfDieImgs],tex_KoreaFall[nOfFallImgs],tex_KoreaIdle[nOfIdleImgs],tex_KoreaShot[nOfShotImgs],tex_KoreaWalk[nOfWalkImgs],tex_KoreaDamage[nOfDamageImgs],tex_KoreaTouchGround;
GLuint tex_RussiaDie[nOfDieImgs],tex_RussiaFall[nOfFallImgs],tex_RussiaIdle[nOfIdleImgs],tex_RussiaShot[nOfShotImgs],tex_RussiaWalk[nOfWalkImgs],tex_RussiaDamage[nOfDamageImgs],tex_RussiaTouchGround;
GLuint tex_Smoke[nOfSmokeImgs];
GLuint tex_BulletAtomic,tex_BulletRocket,tex_BulletDolly,tex_BulletBanana,tex_G,tex_Explosion1[nOfExplosion1Imgs];

void loadButtons(){
  tex_btn_1P=SOIL_load_OGL_texture(newPath(btn_1P),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_2P=SOIL_load_OGL_texture(newPath(btn_2P),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_Off=SOIL_load_OGL_texture(newPath(btn_Off),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_HowTo=SOIL_load_OGL_texture(newPath(btn_HowTo),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_Play=SOIL_load_OGL_texture(newPath(btn_Play),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_On=SOIL_load_OGL_texture(newPath(btn_On),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_Options=SOIL_load_OGL_texture(newPath(btn_Options),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_Exit=SOIL_load_OGL_texture(newPath(btn_Exit),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_Back=SOIL_load_OGL_texture(newPath(btn_Back),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_Continue=SOIL_load_OGL_texture(newPath(btn_Continue),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_defaults=SOIL_load_OGL_texture(newPath(btn_Defaults),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_mapconfigs=SOIL_load_OGL_texture(newPath(btn_MapOptions),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_btn_example=SOIL_load_OGL_texture(newPath(btn_example),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_RussiaTouchGround=SOIL_load_OGL_texture(newPath("Characters/Russia/fall/touchGround.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
}

void refreshLanguage(){
  strcpy(language,getLanguageStr(languageIdx));
        setStrings();loadButtons();createList();
}


void loadFiles(){
  filePath=(char*)malloc(1);

  for(int i=0;i<nOfSplashImgs;i++){
    getAnimatedFiles("Splash/corpLogo/",i,".png");
    tex_Splash[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  }
  tex_JCEBA=SOIL_load_OGL_texture(newPath("Splash/gameLogo/JCEBA3.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_Joguinho=SOIL_load_OGL_texture(newPath("Splash/gameLogo/JCEBA4.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_MainMenu=SOIL_load_OGL_texture(newPath("GUIandHUD/mainmenu.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);

  tex_mundiMap=SOIL_load_OGL_texture(newPath("Maps/worldMap.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);

  loadButtons();

  tex_flagRand=SOIL_load_OGL_texture(newPath("Maps/Flags/rand.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_flagUSA=SOIL_load_OGL_texture(newPath("Maps/Flags/usa.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_flagBR=SOIL_load_OGL_texture(newPath("Maps/Flags/brasil.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_flagKorea=SOIL_load_OGL_texture(newPath("Maps/Flags/coreia.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_flagIsla=SOIL_load_OGL_texture(newPath("Maps/Flags/islamico.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_flagRussia=SOIL_load_OGL_texture(newPath("Maps/Flags/russia.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_SubMenu0=SOIL_load_OGL_texture(newPath("GUIandHUD/submenu0.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_SubMenu1=SOIL_load_OGL_texture(newPath("GUIandHUD/submenu1.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_X=SOIL_load_OGL_texture(newPath("GUIandHUD/X.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_G=SOIL_load_OGL_texture(newPath("GUIandHUD/G.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_Heart=SOIL_load_OGL_texture(newPath("GUIandHUD/heart.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);

  tex_plusArrow=SOIL_load_OGL_texture(newPath("GUIandHUD/arrowMinus.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_minusArrow=SOIL_load_OGL_texture(newPath("GUIandHUD/arrowPlus.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_bixao=SOIL_load_OGL_texture(newPath("Splash/credits/bixhao.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);

  tex_texBR=SOIL_load_OGL_texture(newPath("Maps/Textures/brasil.jpg"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_texRussia=SOIL_load_OGL_texture(newPath("Maps/Textures/russia.jpg"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_texIslamic=SOIL_load_OGL_texture(newPath("Maps/Textures/islamico.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_texUSA=SOIL_load_OGL_texture(newPath("Maps/Textures/usa.jpg"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_texKorea=SOIL_load_OGL_texture(newPath("Maps/Textures/coreia.jpg"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_backBR=SOIL_load_OGL_texture(newPath("Maps/stageBrasil.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_backKorea=SOIL_load_OGL_texture(newPath("Maps/stageCoreia.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_backRussia=SOIL_load_OGL_texture(newPath("Maps/stageRussia.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_backUSA=SOIL_load_OGL_texture(newPath("Maps/stageUSA.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_backIslamic=SOIL_load_OGL_texture(newPath("Maps/stageIslamico.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);

  for(int i=0;i<nOfDamageImgs;i++){
    getAnimatedFiles("Characters/BR/damage/",i,".png");
    tex_BRDamage[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/USA/damage/",i,".png");
    tex_USADamage[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Korea/damage/",i,".png");
    tex_KoreaDamage[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Russia/damage/",i,".png");
    tex_RussiaDamage[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Islamic/damage/",i,".png");
    tex_IslamicDamage[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  }
  for(int i=0;i<nOfDieImgs;i++){
    getAnimatedFiles("Characters/BR/die/",i,".png");
    tex_BRDie[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/USA/die/",i,".png");
    tex_USADie[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Islamic/die/",i,".png");
    tex_IslamicDie[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Korea/die/",i,".png");
    tex_KoreaDie[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Russia/die/",i,".png");
    tex_RussiaDie[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  }
  for(int i=0;i<nOfFallImgs;i++){
    getAnimatedFiles("Characters/BR/fall/",i,".png");
    tex_BRFall[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/USA/fall/",i,".png");
    tex_USAFall[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Islamic/fall/",i,".png");
    tex_IslamicFall[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Korea/fall/",i,".png");
    tex_KoreaFall[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Russia/fall/",i,".png");
    tex_RussiaFall[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  }
  for(int i=0;i<nOfIdleImgs;i++){
    getAnimatedFiles("Characters/BR/idle/",i,".png");
    tex_BRIdle[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/USA/idle/",i,".png");
    tex_USAIdle[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Islamic/idle/",i,".png");
    tex_IslamicIdle[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Korea/idle/",i,".png");
    tex_KoreaIdle[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Russia/idle/",i,".png");
    tex_RussiaIdle[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  }
  for(int i=0;i<nOfShotImgs;i++){
    getAnimatedFiles("Characters/BR/shot/",i,".png");
    tex_BRShot[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/USA/shot/",i,".png");
    tex_USAShot[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Islamic/shot/",i,".png");
    tex_IslamicShot[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Korea/shot/",i,".png");
    tex_KoreaShot[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Russia/shot/",i,".png");
    tex_RussiaShot[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  }
  for(int i=0;i<nOfWalkImgs;i++){
    getAnimatedFiles("Characters/BR/walk/",i,".png");
    tex_BRWalk[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/USA/walk/",i,".png");
    tex_USAWalk[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Islamic/walk/",i,".png");
    tex_IslamicWalk[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Korea/walk/",i,".png");
    tex_KoreaWalk[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    getAnimatedFiles("Characters/Russia/walk/",i,".png");
    tex_RussiaWalk[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  }

  for(int i=0;i<nOfSmokeImgs;i++){
    getAnimatedFiles("Particles/missileSmoke/",i,".png");
    tex_Smoke[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  }

  for(int i=0;i<nOfExplosion1Imgs;i++){
    getAnimatedFiles("Particles/explosion0/",i,".png");
    tex_Explosion1[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  }

  tex_BulletAtomic=SOIL_load_OGL_texture(newPath("Characters/Ammo/atomic1.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_BulletRocket=SOIL_load_OGL_texture(newPath("Characters/Ammo/missile1.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_BulletDolly=SOIL_load_OGL_texture(newPath("Characters/Ammo/dolly.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_BulletBanana=SOIL_load_OGL_texture(newPath("Characters/Ammo/banana.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);

  tex_BRTouchGround=SOIL_load_OGL_texture(newPath("Characters/BR/fall/touchGround.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_USATouchGround=SOIL_load_OGL_texture(newPath("Characters/USA/fall/touchGround.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_IslamicTouchGround=SOIL_load_OGL_texture(newPath("Characters/Islamic/fall/touchGround.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  tex_KoreaTouchGround=SOIL_load_OGL_texture(newPath("Characters/Korea/fall/touchGround.png"),SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);

  loadSound("Sounds/Splash/zuimarcoiris.wav",1.5,AL_FALSE); //0
  loadSound("Sounds/Splash/zuim.wav",1.5,AL_FALSE);         //1
  loadSound("Sounds/Splash/plim.wav",1,AL_FALSE);         //2
  loadSound("Sounds/Music/Menu/2001.wav",1,AL_TRUE);     //3
  loadSound("Sounds/click.wav",1.1,AL_FALSE);              //4
  loadSound("Sounds/Music/Stage/brasilSOUND.wav",0.42,AL_TRUE);         //5
  loadSound("Sounds/Music/Stage/islamicSOUND.wav",0.5,AL_TRUE);     //6
  loadSound("Sounds/Music/Stage/koreaSOUND.wav",0.5,AL_TRUE);              //7
  loadSound("Sounds/Music/Stage/russiaSOUND.wav",0.5,AL_TRUE);         //8
  loadSound("Sounds/Music/Stage/usaSOUND.wav",0.5,AL_TRUE);     //9
  loadSound("Sounds/Char/damage1.wav",1.2,AL_FALSE);              //10
  loadSound("Sounds/Char/damage2.wav",1.2,AL_FALSE);         //11
  loadSound("Sounds/Char/die.wav",2.5,AL_FALSE);     //12
  loadSound("Sounds/Char/die2.wav",2.5,AL_FALSE);              //13
  loadSound("Sounds/Wind/vento1.wav",1,AL_TRUE);         //14
  loadSound("Sounds/Wind/vento2.wav",1,AL_TRUE);     //15
  loadSound("Sounds/Wind/vento3.wav",1,AL_TRUE);              //16
  loadSound("Sounds/Weapons/atomicComplete.wav",1.2,AL_FALSE);         //17
  loadSound("Sounds/Weapons/atomicExplosion.wav",2,AL_FALSE);     //18
  loadSound("Sounds/Weapons/atomicShot.wav",1.3,AL_FALSE);              //19
  loadSound("Sounds/Weapons/explosion.wav",2.5,AL_FALSE);     //20
  loadSound("Sounds/Weapons/shot.wav",1.3,AL_FALSE);              //21
  loadSound("Sounds/parabains.wav",1.3,AL_TRUE);              //22

  for(int i=0;i<nOfCredits;i++){
    getAnimatedFiles("Splash/credits/",i,".png");
    tex_Credits[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  }
  filePath=(char*)realloc(filePath,1);
}
