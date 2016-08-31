void mouseAction(int isHuman){ if(DEBUG) printf("mouse action\n");
  if(players==1&&playerTurn==2&&isHuman){
    mouseClicked=0;
    return;
  }
  if(isHuman&&playerTurn==1&&P1_state==5){
    mouseClicked=0;
    return;
  }
  if(isHuman&&playerTurn==2&&P2_state==5){
    mouseClicked=0;
    return;
  }
  if(mouseClicked&&gameCalled&&P1_life>0&&P2_life>0&&pause>0){if(DEBUG) printf("mouse clicked\n");
    //quando foi clicado
    if(playerTurn==1){
      P1_state=3;
    }else{
      P2_state=3;
    }
    angle=getAngle(1);
    if(!BulletIsVisible&&lastShoot!=playerTurn)initBulletConfigs(playerTurn);
    if(MOUSE1==0){if(DEBUG) printf("mouse released\n");
      //borda de descida
      if(!BulletIsVisible&&lastShoot!=playerTurn){
        if(P1_state==3)
            P1_nextAnimation=3;
        if(P2_state==3)
            P2_nextAnimation=3;
        execPlayerAnimations(0);
        shootBullet(angle,strengh,1);
      }
      mouseClicked=0;
    }
  }
}


void keyboardAction(char* action,int isHuman){
if(currentScreen==JOGO){
  if(players==1&&isHuman&&playerTurn==2) return;
  if(strEq(action,"changeAmmo")){
    if(!BulletIsVisible)
      if(!Bullet_type){
        if(playerTurn==1){
          if(P1_Bombs>0){
            Bullet_type=1;
            P1_Bombs--;
          }
        }else{
          if(P2_Bombs>0){
            Bullet_type=1;
            P2_Bombs--;
          }
        }
      }
  }
  if(playerTurn==1&&P1_state==3) return;
  if(playerTurn==2&&P2_state==3&&players==2) return;
  if(strEq(action,"jump")){
      if(jumping==0)
        jumping=1;
  }else if(strEq(action,"moveLeft")){
    walking=1;
    if(playerTurn==1){
      P1_Ori=-1;
      movePlayer(1,"left",(P1_Hspeed-moveVelocity)*1/FPS);
      P1_state=1;
    }else{
      P2_Ori=-1;
      movePlayer(2,"left",(P2_Hspeed-moveVelocity)*1/FPS);
      P2_state=1;
    }
  }else if(strEq(action,"moveRight")){
    walking=1;
    if(playerTurn==1){
      P1_Ori=1;
      movePlayer(1,"right",(P1_Hspeed+moveVelocity)*1/FPS);
      P1_state=1;
    }else{
      P2_Ori=1;
      movePlayer(2,"right",(P2_Hspeed+moveVelocity)*1/FPS);
      P2_state=1;
    }
  }
}
}
