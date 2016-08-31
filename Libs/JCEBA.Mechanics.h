//D=VoT+0.5at²
int checkNormalForce(int id){
  if(id==1){  //player 1
    for(int i=1;i<=nMapGen;i++){
      if(mapPoints[i].x>=pos_P1.p0.x+offSetPlayerCollision&&mapPoints[i].x<=pos_P1.p1.x-offSetPlayerCollision)
        if(mapPoints[i].y>=pos_P1.p0.y){
          if(P1_Vspeed<0&&P1_currentAnimation==5){
            P1currentIndexAnimation=0;
            if(player1==BRASIL) P1_currentTex=tex_BRTouchGround;
            if(player1==RUSSIA) P1_currentTex=tex_RussiaTouchGround;
            if(player1==KOREA) P1_currentTex=tex_KoreaTouchGround;
            if(player1==ISLAMIC) P1_currentTex=tex_IslamicTouchGround;
            if(player1==USA) P1_currentTex=tex_USATouchGround;
          }
          return 1;
        }
      }
  }else{    //player 2
    for(int i=nMapGen;i>=1;i--){
      if(mapPoints[i].x>=pos_P2.p0.x+offSetPlayerCollision&&mapPoints[i].x<=pos_P2.p1.x-offSetPlayerCollision)
        if(mapPoints[i].y>=pos_P2.p0.y){
          if(P2_Vspeed<0&&P2_currentAnimation==5){
            P2currentIndexAnimation=0;
            if(player2==BRASIL) P2_currentTex=tex_BRTouchGround;
            if(player2==RUSSIA) P2_currentTex=tex_RussiaTouchGround;
            if(player2==KOREA) P2_currentTex=tex_KoreaTouchGround;
            if(player2==ISLAMIC) P2_currentTex=tex_IslamicTouchGround;
            if(player2==USA) P2_currentTex=tex_USATouchGround;
        }
        return 1;
      }
    }
  }
  return 0;
}

float getAngle(int isRAD){
    float tgH,tgW;
    float arcTG;
  if(playerTurn==1){//tg=sen/cos
    tgH=(float)mouseY-(PlayerHEIGHTSHOT+pos_P1.p0.y);
    tgW=(float)mouseX-pos_P1.p1.x;
  }else{
    tgH=(float)mouseY-(PlayerHEIGHTSHOT+pos_P2.p0.y);
    tgW=(float)mouseX-pos_P2.p0.x;
  }
  arcTG=atan(tgH/tgW);
  if(!isRAD)
    return radToAngle(arcTG,0);
  else
    return arcTG;
}

void drawMissilePath(){
  float pX,pY;
  float MPVSpeed=0,MPHSpeed=0;
  if(!mouseClicked||!MOUSE1)
    return;
  MPVSpeed=sin(getAngle(1))*strengh;
  if((MPVSpeed<0&&(!canAimDown||(players==1&&playerTurn==2)))||(playerTurn==2&&mouseX<pos_P2.p0.x&&players==2))
    MPVSpeed*=-1;
  MPHSpeed=cos(getAngle(1))*strengh;
  if(MPHSpeed<0)MPHSpeed*=-1;
  if(Bullet_owner==1&&mouseX<pos_P1.p1.x)
    MPHSpeed*=-1;
  if(Bullet_owner==2&&mouseX<pos_P2.p0.x)
    MPHSpeed*=-1;
  if(playerTurn==1){
    pY=pos_P1.p0.y+PlayerHEIGHTSHOT;
    pX=pos_P1.p1.x;
  }else{
    pY=pos_P2.p0.y+PlayerHEIGHTSHOT;
    pX=pos_P2.p0.x;
  }
glNewList(parabol,GL_COMPILE_AND_EXECUTE);
glLineWidth(1.5);
glBegin(GL_LINE_STRIP);
while (pX>-worldWidth/2&&pX<worldWidth/2&&pY>-worldHeight/2) {//MPVSpeed>0
  pX+=(MPHSpeed+wind)/FPS;
  pY+=MPVSpeed/FPS;
  glVertex3f(pX,pY,0.4);
  MPVSpeed+=gravity*(1/FPS);
}
glEnd();
glEndList();
}

void applyGravity(){
  if(!checkNormalForce(1)){//gravidade p1
    //movePlayer(1,"down",P1_Vspeed*(1/FPS)+gravity/2*(1/FPS)*(1/FPS));
    P1_Vspeed+=gravity*(1/FPS);
  }else if(P1_Vspeed<0)
    P1_Vspeed=0;

  if(!checkNormalForce(2)){//gravidade p2
    //movePlayer(1,"down",P2_Vspeed*(1/FPS)+gravity/2*(1/FPS)*(1/FPS));
    P2_Vspeed+=gravity*(1/FPS);
  }else if(P2_Vspeed<0)
    P2_Vspeed=0;

  if(BulletIsVisible)
    Bullet_Vspeed+=gravity*(1/FPS);
}
