JRectangle pos_P1;
JRectangle pos_P2;
int P1currentIndexAnimation;
int P2currentIndexAnimation;
int P1_Bombs,P2_Bombs;
float P1_Vspeed,P1_Hspeed;
float P2_Vspeed,P2_Hspeed;
GLuint P1_currentTex,P2_currentTex;
int P1_state,P2_state, P1_life, P2_life;//0-iddle,1-walk,2-damage,3-shoting,4-dieing,5-falling
int P1_currentAnimation,P1_nextAnimation;
int P2_currentAnimation,P2_nextAnimation;
bool walking=0;
int jumping=0;
int P1_Ori,P2_Ori;

//declara funcoes interdependentes
void movePlayer(int player,char* way,float steeps);
void remPlayerFromInsideMap(int player);
void execPlayerAnimations(int n);
void gg();

void initPlayerConfigs(){
  pos_P1.p0.x=-360;
  pos_P1.p0.y=PlayerHEIGHTSPAWN;
  pos_P1.p1.x=pos_P1.p0.x+PlayerSIZEX;
  pos_P1.p1.y=pos_P1.p0.y+PlayerSIZEY;

  pos_P2.p1.x=360;
  pos_P2.p0.y=PlayerHEIGHTSPAWN;
  pos_P2.p0.x=pos_P2.p1.x-PlayerSIZEX;
  pos_P2.p1.y=pos_P2.p0.y+PlayerSIZEY;

  P1_Vspeed=0;
  P1_Hspeed=0;
  P2_Vspeed=0;
  P2_Hspeed=0;
  P1_Bombs=initPlayerBombs;
  P2_Bombs=initPlayerBombs;

  P1_state=0;//idle
  P2_state=0;//idle
  P1_life=initPlayerLifes;
  P2_life=initPlayerLifes;
  P1_currentAnimation=0;
  P1_nextAnimation=-1;
  P2_currentAnimation=0;
  P2_nextAnimation=-1;
  playerTurn=1;
  P1_Ori=1;
  P2_Ori=-1;
  jumping=0;
  P1currentIndexAnimation=0;
  P2currentIndexAnimation=0;
  glutTimerFunc(0, execPlayerAnimations, 1);
}

void ctrlPlayerAnimations(){
  if(P1_state==4&&P1_currentAnimation!=4){
    P1_currentAnimation=4; P1currentIndexAnimation=0;
  }else if(P1_state==3){
    if(P1_currentAnimation!=3){
        //mexer bracos
    }
  }else if(P1_state==2&&P1_currentAnimation!=2){
    P1_nextAnimation=2;
  }else if((P1_state==5&&P1_currentAnimation!=5)||(P1_Vspeed!=0&&P1_currentAnimation!=5)){
    P1_nextAnimation=5;
  }else if(P1_state==1&&P1_currentAnimation!=1){
    P1_nextAnimation=1;
  }else if(P1_currentAnimation!=0)
    P1_nextAnimation=0;

  if(P2_state==4&&P2_currentAnimation!=4){
    P2_currentAnimation=4; P2currentIndexAnimation=0;
  }else if(P2_state==3){
    if(P2_currentAnimation!=3){
      //mexer bracos
    }
  }else if(P2_state==2&&P2_currentAnimation!=2){
    P2_nextAnimation=2;
  }else if((P2_state==5&&P2_currentAnimation!=5)||(P2_Vspeed!=0&&P2_currentAnimation!=5))
    P2_nextAnimation=5;
  else if(P2_state==1&&P2_currentAnimation!=1)
    P2_nextAnimation=1;
  else if(P2_currentAnimation!=0)
    P2_nextAnimation=0;
}

void normalizeSprites(){
  if(P1_life<=0){
    if(player1==BRASIL) P1_currentTex=tex_BRDie[nOfDieImgs-1];
    if(player1==USA) P1_currentTex=tex_USADie[nOfDieImgs-1];
    if(player1==ISLAMIC) P1_currentTex=tex_IslamicDie[nOfDieImgs-1];
    if(player1==KOREA) P1_currentTex=tex_KoreaDie[nOfDieImgs-1];
    if(player1==RUSSIA) P1_currentTex=tex_RussiaDie[nOfDieImgs-1];

    if(player2==BRASIL) P2_currentTex=tex_BRTouchGround;
    if(player2==USA) P2_currentTex=tex_USATouchGround;
    if(player2==ISLAMIC) P2_currentTex=tex_IslamicTouchGround;
    if(player2==KOREA) P2_currentTex=tex_KoreaTouchGround;
    if(player2==RUSSIA) P2_currentTex=tex_RussiaTouchGround;
  }else if(P2_life<=0){
    if(player1==BRASIL) P1_currentTex=tex_BRTouchGround;
    if(player1==USA) P1_currentTex=tex_USATouchGround;
    if(player1==ISLAMIC) P1_currentTex=tex_IslamicTouchGround;
    if(player1==KOREA) P1_currentTex=tex_KoreaTouchGround;
    if(player1==RUSSIA) P1_currentTex=tex_RussiaTouchGround;

    if(player2==BRASIL) P2_currentTex=tex_BRDie[nOfDieImgs-1];
    if(player2==USA) P2_currentTex=tex_USADie[nOfDieImgs-1];
    if(player2==ISLAMIC) P2_currentTex=tex_IslamicDie[nOfDieImgs-1];
    if(player2==KOREA) P2_currentTex=tex_KoreaDie[nOfDieImgs-1];
    if(player2==RUSSIA) P2_currentTex=tex_RussiaDie[nOfDieImgs-1];
  }
}

void playerBehave(){
  if(P1_life<=0){
    P1_state=4;
    if(P1_Vspeed<0){
      movePlayer(1,"down",P1_Vspeed*1/FPS);
    }
    pos_P1.p1.x=pos_P1.p0.x+PlayerSIZEY;
    pos_P1.p1.y=pos_P1.p0.y+PlayerSIZEX;
  }else{
    if(P1_state!=2){
    if(P1_state!=3){
      if(P1_Vspeed!=0){
        movePlayer(1,"down",P1_Vspeed*1/FPS);
        P1_state=5;
      }
      if(P1_Hspeed!=0){
        movePlayer(1,"left",P1_Hspeed*1/FPS);
        P1_state=1;
      }else if(P1_Vspeed==0&&!walking){
        P1_state=0;
      }
    }else{
      if(P1_Vspeed!=0)
        movePlayer(1,"down",P1_Vspeed*1/FPS);
    }
  }
  }

  if(P2_life<=0){
    P2_state=4;
    if(P2_Vspeed<0){
      movePlayer(2,"down",P2_Vspeed*1/FPS);
    }
    pos_P2.p1.x=pos_P2.p0.x+PlayerSIZEY;
    pos_P2.p1.y=pos_P2.p0.y+PlayerSIZEX;
  }else{
    if(P2_state!=2){
    if(P2_state!=3){
    if(P2_Vspeed!=0){
      movePlayer(2,"down",P2_Vspeed*1/FPS);
      P2_state=5;
    }
    if(P2_Hspeed!=0){
      movePlayer(2,"left",P2_Hspeed*1/FPS);
      P2_state=1;
    }else if(P2_Vspeed==0&&!walking){
      P2_state=0;
    }
    }else{
      if(P2_Vspeed!=0)
        movePlayer(2,"down",P2_Vspeed*1/FPS);
    }
  }
  }
  walking=0;
  ctrlPlayerAnimations();
}

void realizeJump(){
  if(jumping>0){
    if(playerTurn==1){
      P1_state=5;
      if(jumping==1)P1_Vspeed+=jumpVelocity;
      else if(jumping==jumDuration/2)P1_Vspeed-=jumpVelocity;
    }else{
      P2_state=5;
      if(jumping==1)P2_Vspeed+=jumpVelocity;
      else if(jumping==jumDuration/2)P2_Vspeed-=jumpVelocity;
    }
    jumping++;
    if(jumping>=jumDuration)jumping=0;
  }
}

void movePlayer(int player,char* way,float steeps){
  if(strEq(way,"up")||strEq(way,"down")){
    if(player==1){
      pos_P1.p0.y+=steeps;
      pos_P1.p1.y+=steeps;
      if(pos_P1.p1.y>worldHeight/2){pos_P1.p1.y=(worldHeight/2)-1;pos_P1.p1.y=worldHeight/2-PlayerSIZEY-1;}
      if(pos_P1.p0.y<-worldHeight/2)pos_P1.p0.y=-worldHeight/2;
    }else{
      pos_P2.p0.y+=steeps;
      pos_P2.p1.y+=steeps;
      if(pos_P2.p1.y>worldHeight/2){pos_P2.p1.y=(worldHeight/2)-1;pos_P2.p0.y=worldHeight/2-PlayerSIZEY-1;}
      if(pos_P2.p0.y<-worldHeight/2)pos_P2.p0.y=-worldHeight/2;
    }
  }else if(strEq(way,"right")||strEq(way,"left")){
    if(player==1){
      pos_P1.p0.x+=steeps;
      pos_P1.p1.x+=steeps;
      if(pos_P1.p1.x>0){pos_P1.p1.x=0; pos_P1.p0.x=-PlayerSIZEX;}
      if(pos_P1.p0.x<-worldWidth/2){pos_P1.p0.x=-worldWidth/2;pos_P1.p1.x=pos_P1.p0.x+PlayerSIZEX;}
    }else{
      pos_P2.p0.x+=steeps;
      pos_P2.p1.x+=steeps;
      if(pos_P2.p1.x>worldWidth/2){pos_P2.p1.x=worldWidth/2;pos_P2.p0.x=pos_P2.p1.x-PlayerSIZEX;}
      if(pos_P2.p0.x<0){pos_P2.p0.x=0;pos_P2.p1.x=PlayerSIZEX; }
    }
  }
  remPlayerFromInsideMap(player);
}

void remPlayerFromInsideMap(int player){
  float highestDiference=0;
  float tmp;
  if(player==1){  //player 1
    for(int i=1;i<=nMapGen;i++){
      if(mapPoints[i].x>=pos_P1.p0.x+offSetPlayerCollision&&mapPoints[i].x<=pos_P1.p1.x-offSetPlayerCollision)
        if(mapPoints[i].y>pos_P1.p0.y){
          tmp=mapPoints[i].y-pos_P1.p0.y;
          if(tmp<0) tmp*=1;
          if(tmp>highestDiference)highestDiference=tmp;
        }
      }
  }else{    //player 2
    for(int i=nMapGen;i>=1;i--){
      if(mapPoints[i].x>=pos_P2.p0.x+offSetPlayerCollision&&mapPoints[i].x<=pos_P2.p1.x-offSetPlayerCollision)
        if(mapPoints[i].y>pos_P2.p0.y){
          tmp=mapPoints[i].y-pos_P2.p0.y;
          if(tmp<0) tmp*=1;
          if(tmp>highestDiference)highestDiference=tmp;
        }
      }
  }
  if(highestDiference>0)
    movePlayer(player,"up",highestDiference);
}

void execPlayerAnimations(int n){
  if(pause>0){
    if(P1_currentAnimation==5&&P1_state!=4){//fall
      if(P1currentIndexAnimation>=nOfFallImgs){
        P1currentIndexAnimation=0;
        if(P1_nextAnimation>=0&&P1_nextAnimation!=P1_currentAnimation){
          P1_currentAnimation=P1_nextAnimation;
          P1currentIndexAnimation=0;
        }
        P1_nextAnimation=-1;
      }
      if(player1==BRASIL&&P1_currentTex!=tex_BRTouchGround) P1_currentTex=tex_BRFall[P1currentIndexAnimation];
      if(player1==RUSSIA&&P1_currentTex!=tex_RussiaTouchGround) P1_currentTex=tex_RussiaFall[P1currentIndexAnimation];
      if(player1==KOREA&&P1_currentTex!=tex_KoreaTouchGround) P1_currentTex=tex_KoreaFall[P1currentIndexAnimation];
      if(player1==ISLAMIC&&P1_currentTex!=tex_IslamicTouchGround) P1_currentTex=tex_IslamicFall[P1currentIndexAnimation];
      if(player1==USA&&P1_currentTex!=tex_USATouchGround) P1_currentTex=tex_USAFall[P1currentIndexAnimation];
      P1currentIndexAnimation++;
    }else if(P1_life<=0){//die
      if(P1currentIndexAnimation>=nOfDieImgs){
        canGG=1;
      }else{P1currentIndexAnimation++;}
      if(player1==BRASIL) P1_currentTex=tex_BRDie[P1currentIndexAnimation];
      if(player1==RUSSIA) P1_currentTex=tex_RussiaDie[P1currentIndexAnimation];
      if(player1==KOREA) P1_currentTex=tex_KoreaDie[P1currentIndexAnimation];
      if(player1==ISLAMIC) P1_currentTex=tex_IslamicDie[P1currentIndexAnimation];
      if(player1==USA) P1_currentTex=tex_USADie[P1currentIndexAnimation];
    }else if(P1_currentAnimation==2){//damage
      if(P1currentIndexAnimation>=nOfDamageImgs){
        P1_state=0;
        P1currentIndexAnimation=0;
        if(P1_nextAnimation>=0&&P1_nextAnimation!=P1_currentAnimation){
          P1_currentAnimation=P1_nextAnimation;
          P1currentIndexAnimation=0;
        }
        P1_nextAnimation=-1;
      }
      if(player1==BRASIL) P1_currentTex=tex_BRDamage[P1currentIndexAnimation];
      if(player1==RUSSIA) P1_currentTex=tex_RussiaDamage[P1currentIndexAnimation];
      if(player1==KOREA) P1_currentTex=tex_KoreaDamage[P1currentIndexAnimation];
      if(player1==ISLAMIC) P1_currentTex=tex_IslamicDamage[P1currentIndexAnimation];
      if(player1==USA) P1_currentTex=tex_USADamage[P1currentIndexAnimation];
      P1currentIndexAnimation++;
    }else if(P1_currentAnimation==1){//walk
      if(P1currentIndexAnimation>=nOfWalkImgs){
        P1currentIndexAnimation=0;
        if(P1_nextAnimation>=0&&P1_nextAnimation!=P1_currentAnimation){
          P1_currentAnimation=P1_nextAnimation;
          P1currentIndexAnimation=0;
        }
        P1_nextAnimation=-1;
      }
      if(player1==BRASIL) P1_currentTex=tex_BRWalk[P1currentIndexAnimation];
      if(player1==RUSSIA) P1_currentTex=tex_RussiaWalk[P1currentIndexAnimation];
      if(player1==KOREA) P1_currentTex=tex_KoreaWalk[P1currentIndexAnimation];
      if(player1==ISLAMIC) P1_currentTex=tex_IslamicWalk[P1currentIndexAnimation];
      if(player1==USA) P1_currentTex=tex_USAWalk[P1currentIndexAnimation];
      P1currentIndexAnimation++;
    }else if(P1_currentAnimation==3){//shot
      if(P1currentIndexAnimation>=nOfShotImgs){
        P1currentIndexAnimation=0;
        if(P1_nextAnimation>=0&&P1_nextAnimation!=P1_currentAnimation){
          P1_currentAnimation=P1_nextAnimation;
          P1currentIndexAnimation=0;
        }
        P1_nextAnimation=-1;
      }
      if(player1==BRASIL) P1_currentTex=tex_BRShot[P1currentIndexAnimation];
      if(player1==RUSSIA) P1_currentTex=tex_RussiaShot[P1currentIndexAnimation];
      if(player1==KOREA) P1_currentTex=tex_KoreaShot[P1currentIndexAnimation];
      if(player1==ISLAMIC) P1_currentTex=tex_IslamicShot[P1currentIndexAnimation];
      if(player1==USA) P1_currentTex=tex_USAShot[P1currentIndexAnimation];
      P1currentIndexAnimation++;
    }else {//iddle
      if(P1currentIndexAnimation>=nOfIdleImgs){
        P1currentIndexAnimation=0;
        if(P1_nextAnimation>=0&&P1_nextAnimation!=P1_currentAnimation){
          P1_currentAnimation=P1_nextAnimation;
          P1currentIndexAnimation=0;
        }
        P1_nextAnimation=-1;
      }
      if(player1==BRASIL) P1_currentTex=tex_BRIdle[P1currentIndexAnimation];
      if(player1==RUSSIA) P1_currentTex=tex_RussiaIdle[P1currentIndexAnimation];
      if(player1==KOREA) P1_currentTex=tex_KoreaIdle[P1currentIndexAnimation];
      if(player1==ISLAMIC) P1_currentTex=tex_IslamicIdle[P1currentIndexAnimation];
      if(player1==USA) P1_currentTex=tex_USAIdle[P1currentIndexAnimation];
      P1currentIndexAnimation++;
  }

  if(P2_currentAnimation==5&&P2_life>0){//fall
    if(P2currentIndexAnimation>=nOfFallImgs){
      P2currentIndexAnimation=0;
      if(P2_nextAnimation>=0&&P2_nextAnimation!=P2_currentAnimation){
        P2_currentAnimation=P2_nextAnimation;
        P2currentIndexAnimation=0;
      }
      P2_nextAnimation=-1;
    }
    if(player2==BRASIL&&P2_currentTex!=tex_BRTouchGround) P2_currentTex=tex_BRFall[P2currentIndexAnimation];
    if(player2==RUSSIA&&P2_currentTex!=tex_RussiaTouchGround) P2_currentTex=tex_RussiaFall[P2currentIndexAnimation];
    if(player2==KOREA&&P2_currentTex!=tex_KoreaTouchGround) P2_currentTex=tex_KoreaFall[P2currentIndexAnimation];
    if(player2==ISLAMIC&&P2_currentTex!=tex_IslamicTouchGround) P2_currentTex=tex_IslamicFall[P2currentIndexAnimation];
    if(player2==USA&&P2_currentTex!=tex_USATouchGround) P2_currentTex=tex_USAFall[P2currentIndexAnimation];
    P2currentIndexAnimation++;
  }else if(P2_life<=0){//die
    if(P2currentIndexAnimation>=nOfDieImgs){
      canGG=1;
    }else{P2currentIndexAnimation++;}
    if(player2==BRASIL) P2_currentTex=tex_BRDie[P2currentIndexAnimation];
    if(player2==RUSSIA) P2_currentTex=tex_RussiaDie[P2currentIndexAnimation];
    if(player2==KOREA) P2_currentTex=tex_KoreaDie[P2currentIndexAnimation];
    if(player2==ISLAMIC) P2_currentTex=tex_IslamicDie[P2currentIndexAnimation];
    if(player2==USA) P2_currentTex=tex_USADie[P2currentIndexAnimation];
  }else if(P2_currentAnimation==2){//damage
    if(P2currentIndexAnimation>=nOfDamageImgs){
      P2_state=0;
      P2currentIndexAnimation=0;
      if(P2_nextAnimation>=0&&P2_nextAnimation!=P2_currentAnimation){
        P2_currentAnimation=P2_nextAnimation;
        P2currentIndexAnimation=0;
      }
      P2_nextAnimation=-1;
    }
    if(player2==BRASIL) P2_currentTex=tex_BRDamage[P2currentIndexAnimation];
    if(player2==RUSSIA) P2_currentTex=tex_RussiaDamage[P2currentIndexAnimation];
    if(player2==KOREA) P2_currentTex=tex_KoreaDamage[P2currentIndexAnimation];
    if(player2==ISLAMIC) P2_currentTex=tex_IslamicDamage[P2currentIndexAnimation];
    if(player2==USA) P2_currentTex=tex_USADamage[P2currentIndexAnimation];
    P2currentIndexAnimation++;
  }else if(P2_currentAnimation==1){//walk
    if(P2currentIndexAnimation>=nOfWalkImgs){
      P2currentIndexAnimation=0;
      if(P2_nextAnimation>=0&&P2_nextAnimation!=P2_currentAnimation){
        P2_currentAnimation=P2_nextAnimation;
        P2currentIndexAnimation=0;
      }
      P2_nextAnimation=-1;
    }
    if(player2==BRASIL) P2_currentTex=tex_BRWalk[P2currentIndexAnimation];
    if(player2==RUSSIA) P2_currentTex=tex_RussiaWalk[P2currentIndexAnimation];
    if(player2==KOREA) P2_currentTex=tex_KoreaWalk[P2currentIndexAnimation];
    if(player2==ISLAMIC) P2_currentTex=tex_IslamicWalk[P2currentIndexAnimation];
    if(player2==USA) P2_currentTex=tex_USAWalk[P2currentIndexAnimation];
    P2currentIndexAnimation++;
  }else if(P2_currentAnimation==3){//shot
    if(P2currentIndexAnimation>=nOfShotImgs){
      P2currentIndexAnimation=0;
      if(P2_nextAnimation>=0&&P2_nextAnimation!=P2_currentAnimation){
        P2_currentAnimation=P2_nextAnimation;
        P2currentIndexAnimation=0;
      }
      P2_nextAnimation=-1;
    }
    if(player2==BRASIL) P2_currentTex=tex_BRShot[P2currentIndexAnimation];
    if(player2==RUSSIA) P2_currentTex=tex_RussiaShot[P2currentIndexAnimation];
    if(player2==KOREA) P2_currentTex=tex_KoreaShot[P2currentIndexAnimation];
    if(player2==ISLAMIC) P2_currentTex=tex_IslamicShot[P2currentIndexAnimation];
    if(player2==USA) P2_currentTex=tex_USAShot[P2currentIndexAnimation];
    P2currentIndexAnimation++;
  }else {//iddle
    if(P2currentIndexAnimation>=nOfIdleImgs){
      P2currentIndexAnimation=0;
      if(P2_nextAnimation>=0&&P2_nextAnimation!=P2_currentAnimation){
        P2_currentAnimation=P2_nextAnimation;
        P2currentIndexAnimation=0;
      }
      P2_nextAnimation=-1;
    }
    if(player2==BRASIL) P2_currentTex=tex_BRIdle[P2currentIndexAnimation];
    if(player2==RUSSIA) P2_currentTex=tex_RussiaIdle[P2currentIndexAnimation];
    if(player2==KOREA) P2_currentTex=tex_KoreaIdle[P2currentIndexAnimation];
    if(player2==ISLAMIC) P2_currentTex=tex_IslamicIdle[P2currentIndexAnimation];
    if(player2==USA) P2_currentTex=tex_USAIdle[P2currentIndexAnimation];
    P2currentIndexAnimation++;
}
  }
  if(currentScreen==JOGO&&n==1)
    glutTimerFunc(1000/FPS*animationSpeed, execPlayerAnimations, 1);
}
