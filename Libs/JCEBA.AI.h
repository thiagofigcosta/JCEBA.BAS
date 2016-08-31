#define chanceWalk 3
#define chanceToEasyAtomic 16
#define MAXsleep 600
#define MINsleep 181
#define chanceJump 15
#define chanceWalkR 4
#define sleepFPS 9000
#define chanceToChangeAngle 16
#define distToChangeAngle 160
#define randAngle 100
#define offSetAngle 10
//angulo 0-120
int WalkR=50;
int WalkL=80;
float AIangle=(rand()%randAngle)+offSetAngle;
float AIstrengh=0;
float AILaststrengh=0;
float sleepAItime=0;

void moveAI(int n){
  if(pause<0)
    return;
  if(n==1){
    keyboardAction("moveRight",0);
    if(DEBUG)printf("Steep right exec!\n");
  }
  if(n==2){
    keyboardAction("moveLeft",0);
    if(DEBUG)printf("Steep left exec!\n");
  }
}

void AIendTurn(int n){
  if(difficulty==1){
    AIangle=(rand()%randAngle)+offSetAngle;
    AIstrengh=(rand()%(MAXstrengh-MINstrengh))+MINstrengh;
    if(rand()%chanceToEasyAtomic==0)
      keyboardAction("changeAmmo",0);
  }else if(difficulty==2){
    if(rand()%chanceToEasyAtomic==0)
      keyboardAction("changeAmmo",0);
    if(-20<disFromP1&&disFromP1<20)
      keyboardAction("changeAmmo",0);
    if(rand()%chanceToChangeAngle==0||disFromP1<-distToChangeAngle||disFromP1>distToChangeAngle){
      AIangle=(rand()%randAngle)+offSetAngle;
    }else{
      if(rand()%2==0)
        AIangle+=(rand()%666)/100.0;
      else
        AIangle-=(rand()%666)/100.0;
      }
    strengh=AILaststrengh;
    if(strengh==0) AIstrengh=(rand()%(MAXstrengh-MINstrengh))+MINstrengh;
    if(disFromP1>0){
      strengh-=(disFromP1/1.35002)+(rand()%(int)(disFromP1*1000))/1000.0;
    }else{
      strengh+=(disFromP1/1.35002)+(rand()%(int)(disFromP1*1000))/1000.0;
    }
    AILaststrengh=strengh;
  }else if(difficulty==3){
    if(-10<disFromP1&&disFromP1<10)
      keyboardAction("changeAmmo",0);
    if(rand()%(chanceToEasyAtomic/2)==0)
      keyboardAction("changeAmmo",0);
    AIangle=(randAngle-1-offSetAngle)/2+offSetAngle;
    AIstrengh=MINstrengh*1.3;
    float pX,pY;
    float MPVSpeed=0,MPHSpeed=0;
    bool end=false;
    while(true) {
      MPVSpeed=sin(angleToRad(AIangle))*AIstrengh;
      if(MPVSpeed<0)
        MPVSpeed*=-1;
      MPHSpeed=cos(angleToRad(AIangle))*AIstrengh;
      if(MPHSpeed>0)MPHSpeed*=-1;
      pY=pos_P2.p0.y+PlayerHEIGHTSHOT;
      pX=pos_P2.p0.x;
      if(!end)
      while(pX>-worldWidth/2&&pX<worldWidth/2&&pY>-worldHeight/2){
        pX+=(MPHSpeed+wind)/FPS;
        pY+=MPVSpeed/FPS;
        MPVSpeed+=gravity*(1/FPS);
        if(!(pX>pos_P1.p1.x||pX<pos_P1.p0.x||pY>pos_P1.p1.y||pY<pos_P1.p0.y))
          end=1;
        if(end) break;
      }
      if(end){
        if(pY>pos_P1.p0.y+PlayerSIZEY/2){
          AIstrengh+=(MAXstrengh-MINstrengh)/50;
        }else{
          AIstrengh+=(MAXstrengh-MINstrengh)/38;
        }
      break;}
      AIstrengh++;
      if(AIstrengh>=MAXstrengh){
        AIstrengh=MINstrengh*1.3;
        AIangle++;
        if(AIangle>=offSetAngle+randAngle-1){
          AIangle=(rand()%randAngle)+offSetAngle;
          AIstrengh=(rand()%(MAXstrengh-MINstrengh))+MINstrengh;
          break;
        }
      }
    }
  }
  P2_state=3;
  P2_nextAnimation=3;
  if(!BulletIsVisible&&lastShoot!=playerTurn)initBulletConfigs(playerTurn);
  execPlayerAnimations(0);
  shootBullet(angleToRad(AIangle),-AIstrengh,0);
  if(DEBUG)printf("IA shot: Speed:%f  Angle(º):%f\n",AIstrengh,AIangle);
  mouseClicked=0;
  P2_Ori=-1;
}

void AIturn(){
  if(!alreadyAI&&playerTurn==2&&P2_life>0){
    WalkR=((worldWidth/2)-(pos_P2.p0.x+(PlayerSIZEX/2)))/moveVelocity*FPS;
    WalkL=(pos_P2.p0.x+(PlayerSIZEX/2))/moveVelocity*FPS;
    alreadyAI=true;
  for(int i=0;i<3;i++)
    if(rand()%chanceJump==0)
      keyboardAction("jump",0);
  if(rand()%chanceWalk==0){
    if(rand()%chanceWalkR==0){
      int temp=rand()%WalkR;
      if(temp<WalkR*0.2)
        temp=(int)WalkR*0.2;
      for(int i=0;i<temp;i++){
        glutTimerFunc(sleepFPS/FPS*i,moveAI,1);
        sleepAItime=sleepFPS/FPS*i;
        if(DEBUG)printf("Steep right registred(%f)!\n",sleepAItime);
      }
    }else{
      int temp=rand()%WalkL;
      if(temp<WalkL*0.2)
        temp=(int)WalkL*0.2;
      for(int i=0;i<temp;i++){
        glutTimerFunc(sleepFPS/FPS*i,moveAI,2);
        sleepAItime=sleepFPS/FPS*i;
        if(DEBUG)printf("Steep left registred(%f)!\n",sleepAItime);
      }
    }
  }
  glutTimerFunc(sleepAItime+(1/FPS*(rand()%(MAXsleep-MINsleep)+MINsleep)),AIendTurn,0);
  }
}
