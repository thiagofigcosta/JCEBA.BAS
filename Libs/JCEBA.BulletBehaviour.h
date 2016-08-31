JRectangle pos_Bullet;
JRectangle pos_Smoke;
int idxExplosion=-1;
int explodeNumber;
bool explodeAtomic;
int Bullet_owner;
bool Bullet_type=0; //0-rocket;1-atomic
bool BulletIsVisible;
int BulletOri;
GLuint BulletCurrentTex;
float Bullet_Vspeed,Bullet_Hspeed,Bullet_Angle;
float idxSmokeSprite=0;
int lastShoot=0;
float lastBulletX,lastBulletY;
void destroyBullet(int n);

void explode1(int n){
    if(!n){
      explodeAtomic=Bullet_type;
      idxExplosion=0;
      explodeNumber=1;
      pos_Explosion.p0.x=pos_Bullet.p0.x-(BulletSIZEX/1.3);pos_Explosion.p0.y=(pos_Bullet.p1.y-pos_Bullet.p0.y)/2+pos_Bullet.p0.y;
      pos_Explosion.p1.x=pos_Explosion.p0.x+(80*(explodeAtomic+1));pos_Explosion.p1.y=pos_Explosion.p0.y+(80*(explodeAtomic+1));
    }
    if(idxExplosion>=nOfExplosion1Imgs-1)
      idxExplosion=-1;
    else
      glutTimerFunc(animationSpeed*1000/FPS,explode1,1);
    idxExplosion++;
}

void initBulletConfigs(int owner){
  Bullet_owner=owner;
  Bullet_Vspeed=0;
  Bullet_Hspeed=0;
  BulletIsVisible=0;
  idxSmokeSprite=0;
  BulletOri=1;
  Bullet_Angle=0;
  if(owner==1){
    pos_Bullet.p0.y=pos_P1.p0.y+PlayerHEIGHTSHOT;pos_Bullet.p1.y=pos_Bullet.p0.y+BulletSIZEY;
    pos_Bullet.p0.x=pos_P1.p1.x;pos_Bullet.p1.x=pos_Bullet.p0.x+BulletSIZEX;
    if(Bullet_type){
      pos_Bullet.p1.y+=BulletSIZEY/1.3;
      pos_Bullet.p1.x+=BulletSIZEX/1.3;
    }
    lastBulletX=pos_Bullet.p0.x;
  }else{
    pos_Bullet.p0.y=pos_P2.p0.y+PlayerHEIGHTSHOT;pos_Bullet.p1.y=pos_Bullet.p0.y-BulletSIZEY;
    pos_Bullet.p0.x=pos_P2.p0.x;pos_Bullet.p1.x=pos_Bullet.p0.x-BulletSIZEX;
    if(Bullet_type){
      pos_Bullet.p1.y-=BulletSIZEY/1.3;
      pos_Bullet.p1.x-=BulletSIZEX/1.3;
    }
    lastBulletX=pos_Bullet.p1.x;
  }
  lastBulletY=(pos_Bullet.p1.y-pos_Bullet.p0.y)/2+pos_Bullet.p0.y;
}

void moveBullet(char* way, float steeps){
  //if(playerTurn==1)printf("x0:%f y0:%f    x1:%f y1:%f\n",pos_Bullet.p0.x,pos_Bullet.p0.y,pos_Bullet.p1.x,pos_Bullet.p1.y);
  lastBulletY=pos_Bullet.p0.y;
  if(BulletOri==1&&!(players==1&&playerTurn==2)){
    if(Bullet_owner==1)
      lastBulletX=pos_Bullet.p1.x-BulletSIZEX;
    else
      lastBulletX=pos_Bullet.p1.x-BulletSIZEX/4;
  }else{
    if(Bullet_owner==1)
      lastBulletX=pos_Bullet.p1.x+BulletSIZEX/1.5;
    else
      lastBulletX=pos_Bullet.p1.x+BulletSIZEX*2;
  }
  if(strEq(way,"up")||strEq(way,"down")){
      pos_Bullet.p0.y+=steeps;
      pos_Bullet.p1.y+=steeps;
      if(pos_Bullet.p0.y>worldHeight)destroyBullet(0);
      if(pos_Bullet.p0.y<-worldHeight/2)destroyBullet(0);
  }else if(strEq(way,"right")||strEq(way,"left")){
      pos_Bullet.p0.x+=steeps;
      pos_Bullet.p1.x+=steeps;
      if(pos_Bullet.p1.x>worldWidth/2)destroyBullet(0);
      if(pos_Bullet.p0.x<-worldWidth/2)destroyBullet(0);
    }
    if(bugMODE) movePlayer(playerTurn,way,steeps);
}

int checkCollision(){
  if(!BulletIsVisible)
    return 0;
  if(Bullet_owner==2){
    if(pos_Bullet.p0.x>=pos_P1.p0.x&&pos_Bullet.p0.x<=pos_P1.p1.x)
      if(pos_Bullet.p0.y>=pos_P1.p0.y&&pos_Bullet.p0.y<=pos_P1.p1.y)
        return 1;
  }else{
    if(pos_Bullet.p1.x>=pos_P2.p0.x&&pos_Bullet.p1.x<=pos_P2.p1.x)//pos_Bullet.p0.x<=pos_P2.p0.x&&pos_Bullet.p1.x<=pos_P2.p1.x
      if(pos_Bullet.p0.y>=pos_P2.p0.y&&pos_Bullet.p0.y<=pos_P2.p1.y)
        return 2;
  }
  for(int i=0;i<=nMapGen;i++){
      if(playerTurn==1){
        if(pos_Bullet.p0.x<=mapPoints[i].x && mapPoints[i].x<=pos_Bullet.p1.x)
        if(worldHeight/-2<pos_Bullet.p0.y&&mapPoints[i].y>pos_Bullet.p0.y)
          return 3;//erro
      }else{
        if(pos_Bullet.p1.x<=mapPoints[i].x && mapPoints[i].x<=pos_Bullet.p0.x)
        if(worldHeight/-2<pos_Bullet.p0.y&&mapPoints[i].y>pos_Bullet.p0.y)
          return 3;//erro
      }
    }
  return 0;
}

void smokeBullet(){
  if(BulletIsVisible&&pause>0){
    if(idxSmokeSprite>=nOfSmokeImgs-1)
      idxSmokeSprite=0;
    idxSmokeSprite+=1/FPS*animationSpeed*2;
    float divisor=2;
    if(Bullet_type)
      divisor=1.3;
    if(BulletOri){
      pos_Smoke.p0.x=lastBulletX;pos_Smoke.p0.y=lastBulletY;
      pos_Smoke.p1.x=pos_Smoke.p0.x-(BulletSIZEX/divisor*2);pos_Smoke.p1.y=pos_Smoke.p0.y+(pos_Bullet.p1.y-pos_Bullet.p0.y);
    }else{
      pos_Smoke.p0.x=lastBulletX;pos_Smoke.p0.y=lastBulletY;
      pos_Smoke.p1.x=pos_Smoke.p0.x-(BulletSIZEX/divisor*2);pos_Smoke.p1.y=pos_Smoke.p0.y+(pos_Bullet.p1.y-pos_Bullet.p0.y);
    }
  }
}

void bulletRotate(float Angle,bool smoke,bool banana){
    Angle=radToAngle(Angle,0);
    //if(DEBUG) printf("rotate angle:%f\n",Angle);
    glPushMatrix();
    if(banana){
      if(Bullet_owner==1){
          glTranslatef((pos_Bullet.p0.x+(BulletSIZEX/2))*1,(pos_Bullet.p0.y+(BulletSIZEY/2))*1,0);
          glRotatef(Angle,0,0,1);
          glTranslatef((pos_Bullet.p0.x+(BulletSIZEX/2))*-1,(pos_Bullet.p0.y+(BulletSIZEY/2))*-1,0);
      }else{
          glTranslatef((pos_Bullet.p1.x+(BulletSIZEX/2))*1,(pos_Bullet.p1.y+(BulletSIZEY/2))*1,0);
          glRotatef(Angle,0,0,1);
          glTranslatef((pos_Bullet.p1.x+(BulletSIZEX/2))*-1,(pos_Bullet.p1.y+(BulletSIZEY/2))*-1,0);
      }
      refreshBullet(pos_Bullet,BulletCurrentTex,1);
    }else{
      if(BulletOri==1&&!(players==1&&playerTurn==2)){
          glTranslatef((pos_Bullet.p0.x+(BulletSIZEX/2))*1,(pos_Bullet.p0.y+(BulletSIZEY/2))*1,0);
          glRotatef(Angle,0,0,1);
          glTranslatef((pos_Bullet.p0.x+(BulletSIZEX/2))*-1,(pos_Bullet.p0.y+(BulletSIZEY/2))*-1,0);
          if(playerTurn==1)
            refreshBullet(pos_Bullet,BulletCurrentTex,1);
          else
          refreshBullet(pos_Bullet,BulletCurrentTex,-1);
      }else{
          glTranslatef((pos_Bullet.p1.x+(BulletSIZEX/2))*1,(pos_Bullet.p1.y+(BulletSIZEY/2))*1,0);
          glRotatef(Angle,0,0,1);
          glTranslatef((pos_Bullet.p1.x+(BulletSIZEX/2))*-1,(pos_Bullet.p1.y+(BulletSIZEY/2))*-1,0);
          if(Bullet_owner==2)
            refreshBullet(pos_Bullet,BulletCurrentTex,1);
          else
            refreshBullet(pos_Bullet,BulletCurrentTex,-1);
      }
    }
    glPopMatrix();
    if(smoke){
      glPushMatrix();
      if(BulletOri==1&&!(players==1&&playerTurn==2)){
        glTranslatef((pos_Bullet.p0.x+(BulletSIZEX/2))*1,(pos_Bullet.p0.y+(BulletSIZEY/2))*1,0);//glTranslatef((pos_Smoke.p0.x+(0))*1,(pos_Smoke.p0.y+((pos_Smoke.p1.y-pos_Smoke.p0.y)/2))*1,0);
        glRotatef(Angle,0,0,1);
        glTranslatef((pos_Bullet.p0.x+(BulletSIZEX/2))*-1,(pos_Bullet.p0.y+(BulletSIZEY/2))*-1,0);//glTranslatef((pos_Smoke.p0.x+(0))*-1,(pos_Smoke.p0.y+((pos_Smoke.p1.y-pos_Smoke.p0.y)/2))*-1,0);
      }else{
        glTranslatef((pos_Bullet.p1.x+(BulletSIZEX/2))*1,(pos_Bullet.p1.y+(BulletSIZEY/2))*1,0);//glTranslatef((pos_Smoke.p1.x+(0))*1,(pos_Smoke.p0.y+((pos_Smoke.p1.y-pos_Smoke.p0.y)/2))*1,0);
        glRotatef(Angle,0,0,1);
        glTranslatef((pos_Bullet.p1.x+(BulletSIZEX/2))*-1,(pos_Bullet.p1.y+(BulletSIZEY/2))*-1,0);//glTranslatef((pos_Smoke.p1.x+(0))*-1,(pos_Smoke.p0.y+((pos_Smoke.p1.y-pos_Smoke.p0.y)/2))*-1,0);
      }
      refreshSmoke(pos_Smoke,tex_Smoke[(int)idxSmokeSprite],BulletOri);
      glPopMatrix();
    }
}

void bulletTransform(){
    float Angle;
  if(!Bullet_type){
  if(Bullet_owner==1){
    if(player1==BRASIL){
      Bullet_Angle+=bananaSpinSpeed;
      if(Bullet_Angle>2*PI)
        Bullet_Angle=0;
      bulletRotate(Bullet_Angle,0,1);
      return;
    }
  }
  if(Bullet_owner==2){
    if(player2==BRASIL){
      Bullet_Angle+=bananaSpinSpeed;
      if(Bullet_Angle>2*PI)
        Bullet_Angle=0;
      bulletRotate(Bullet_Angle,0,1);
      return;
    }
  }
}
  Bullet_Angle=atan(Bullet_Vspeed/Bullet_Hspeed);
  bulletRotate(Bullet_Angle,!Bullet_type,0);
}

void BulletBehave(){
  if(Bullet_Hspeed!=0){
    moveBullet("left",(Bullet_Hspeed+wind)*1/FPS);
  }
  if(Bullet_Vspeed!=0){
    moveBullet("up",Bullet_Vspeed*1/FPS);
  }
  if(Bullet_type){//atomic
    if(Bullet_owner==1){
      if(player1==BRASIL)
        BulletCurrentTex=tex_BulletDolly;
      else
        BulletCurrentTex=tex_BulletAtomic;
      }
      if(Bullet_owner==2){
        if(player2==BRASIL)
          BulletCurrentTex=tex_BulletDolly;
        else
          BulletCurrentTex=tex_BulletAtomic;
        }
    }else{
      if(Bullet_owner==1){
        if(player1==BRASIL)
          BulletCurrentTex=tex_BulletBanana;
        else
          BulletCurrentTex=tex_BulletRocket;
        }
        if(Bullet_owner==2){
          if(player2==BRASIL)
            BulletCurrentTex=tex_BulletBanana;
          else
            BulletCurrentTex=tex_BulletRocket;
          }
    }
  if(Bullet_owner==1){
    if(player1!=BRASIL||Bullet_type==1)
      smokeBullet();
  }else{
    if(player2!=BRASIL||Bullet_type==1)
      smokeBullet();
  }
  bulletTransform();
  int collision=checkCollision();
  switch (collision) {
    default:break;
    case 1://acertou player 1
      explode1(0);
      if(Bullet_type){
        P1_life-=damageAtomic/2;
        if(P1_life<0)P1_life=0;
        if(P1_life==0){
          P1currentIndexAnimation=0;
          P1_state=4;
          if(soundState)alSourcePlay(ALsource[12+rand()%2]);
        }else{
          P1_state=2;
          P1currentIndexAnimation=0;
          if(soundState)alSourcePlay(ALsource[10+rand()%2]);
          if(soundState)alSourcePlay(ALsource[18]);
        }
      }else{
        P1_life-=damageRocket/2;
        if(P1_life<0)P1_life=0;
        if(P1_life==0){
          P1currentIndexAnimation=0;
          P1_state=4;
          if(soundState)alSourcePlay(ALsource[12+rand()%2]);
        }else{
          P1_state=2;
          P2currentIndexAnimation=0;
          if(soundState)alSourcePlay(ALsource[10+rand()%2]);
        }
      }

    break;
    case 2://acertou player 2
      explode1(0);
      if(Bullet_type){
        P2_life-=damageAtomic/2;
        if(P2_life<0)P2_life=0;
        if(P2_life==0){
          P2currentIndexAnimation=0;
          P2_state=4;
          if(soundState)alSourcePlay(ALsource[12+rand()%2]);
        }else{
          P2_state=2;
          if(soundState)alSourcePlay(ALsource[10+rand()%2]);
          if(soundState)alSourcePlay(ALsource[18]);
        }
      }else{
        P2_life-=damageRocket/2;
        if(P2_life<0)P2_life=0;
        if(P2_life==0){
          P2currentIndexAnimation=0;
          P2_state=4;
          if(soundState)alSourcePlay(ALsource[12+rand()%2]);
        }else{
          P2_state=2;
          if(soundState)alSourcePlay(ALsource[10+rand()%2]);
        }
      }

    break;
    case 3://acertou o mapa
    if(DEBUG) printf("Mapa acertado\n");
    if(Bullet_type){
      if(soundState)alSourcePlay(ALsource[18]);
    }else{
      if(soundState)alSourcePlay(ALsource[20]);
    }
    explode1(0);
      float currentPoints=1;
      float MAXdamage;
      if(Bullet_type)
        MAXdamage=damageAtomic*0.67;
      else
        MAXdamage=damageRocket*1.3;
      float nPoints=BulletSIZEX*MAXdamage/worldWidth*nMapGen;
      float damagePercent=0;
      for(int i=1;i<=nMapGen;i++){
        if(pos_Bullet.p0.x-(nPoints*2)<=mapPoints[i].x && mapPoints[i].x<=pos_Bullet.p1.x+(nPoints*2)){
          if(DEBUG)printf("damage:%f    MADDAM:%f\n",damagePercent,MAXdamage);
              if(!bugMODE)
                mapPoints[i].y-=damagePercent;//*mapPoints[i].y*0.8;
              else
                mapPoints[i].y+=damagePercent/4;//*mapPoints[i].y*0.8;

              if(mapPoints[i].y<averageGroundSpawn-MAXdestructionHeight)
                mapPoints[i].y=averageGroundSpawn-MAXdestructionHeight;
              if(currentPoints<nPoints/1.5)
                damagePercent+=MAXdamage*(25/nPoints);//*nPoints/worldWidth/3;
              else
                damagePercent-=MAXdamage*(25/nPoints);//*nPoints/worldWidth/3;
              if(damagePercent<0)
                damagePercent=0;
              currentPoints++;
          }
      }
      refreshMapList(useStencil);
    break;
  }
  if(collision>0){
    destroyBullet(0);
  }
}


void destroyBullet(int n){
  if(BulletIsVisible&&lastShoot==playerTurn){
  Bullet_type=0;
  if(playerTurn==1){
    P1_state=0;
    playerTurn=2;
  }else{
    P2_state=0;
    playerTurn=1;
    disFromP1=((pos_P1.p1.x-pos_P1.p0.x)/2+pos_P1.p0.x)-(pos_Bullet.p0.x);
  }
  if(windState) wind=((rand()%3)+1)*windForce;
    else wind=0;
  alSourceStop(ALsource[14]);alSourceStop(ALsource[15]);alSourceStop(ALsource[16]);
  if(windState) alSourcePlay(ALsource[(wind/windForce)-1+14]);
  if(windForce&&rand()%2) wind*=-1;
  if(Bullet_type){
    if(soundState)alSourcePlay(ALsource[18]);
  }else{
    if(soundState)alSourcePlay(ALsource[20]);
  }
  BulletIsVisible=0;
  strengh=MINstrengh;
  alreadyAI=false;
}
}

void shootBullet(float Angle,float speed,bool isHuman){
  if(Bullet_type){
    if(soundState)alSourcePlay(ALsource[19]);
  }else{
    if(soundState)alSourcePlay(ALsource[21]);
  }
  if(playerTurn==1){
    P1_state=0;
    Bullet_owner=1;
  }else{
    P2_state=0;
    Bullet_owner=2;
  }
  BulletIsVisible=1;
  Bullet_Angle=Angle;
  Bullet_Vspeed=sin(Angle)*speed;
  if((Bullet_Vspeed<0&&(!canAimDown||(players==1&&playerTurn==2)))||(playerTurn==2&&mouseX<pos_P2.p0.x&&players==2))
    Bullet_Vspeed*=-1;
  Bullet_Hspeed=cos(Angle)*speed;

  if(isHuman){
  if(Bullet_Hspeed<0)Bullet_Hspeed*=-1;
  if(Bullet_owner==1&&mouseX<pos_P1.p1.x){
      Bullet_Hspeed*=-1;
      BulletOri*=-1;
    }
    if(Bullet_owner==2&&mouseX<pos_P2.p0.x){
      Bullet_Hspeed*=-1;
      BulletOri*=-1;
    }
  }
  lastShoot=playerTurn;
  if(DEBUG)printf("angle: %f, strengh:%f\n",getAngle(0),speed);
  if(DEBUG)printf("BulletVS:%f  BulletHS:%f  BulletORI:%.1d\n",Bullet_Vspeed,Bullet_Hspeed,BulletOri);
  if(timeToDestroyBullet)glutTimerFunc(1000*timeToDestroyBullet, destroyBullet, 0);
}
