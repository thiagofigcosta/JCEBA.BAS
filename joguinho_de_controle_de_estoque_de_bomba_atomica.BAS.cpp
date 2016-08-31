//main
#include "JCEBA.LoadLibs.h"

void drawScene(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if(triedReshapping)
        warnReshapping();
    switch(currentScreen){
        case SPLASH:        splash();break;
        case MENU:          menu();break;
        case PREMENU:       preMenu();break;
        case JOGO:          game();break;
        case NUM_JOGADORES: numPlayers();break;
        case ESC_PERSONAGEM:chooseChars();break;
        case PRE_PARTIDA:   prePartida();break;
        case OPCOES:        options();break;
        case INSTRUCOES:    howto();break;
        case CREDITOS:      credits();break;
        case EDICAO_MAPA:   mapEdit();break;
        case SAIR:          exit(0);break;
    }
    glutSwapBuffers();
}

void setup(void){
    srand(time(NULL));
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA|GLUT_DEPTH|GLUT_STENCIL|GLUT_ALPHA); //GLUT_DOUBLE|GLUT_DEPTH|GLUT_STENCIL
    glutInitWindowSize(worldWidth, worldHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("JCEBA.BAS");
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    refreshBackground(0);
}

void reshape(int width, int height){
  if((width!=currentWidth||height!=currentHeight)&&!fullscreen){
        glutReshapeWindow(currentWidth,currentHeight);
    triedReshapping=1;
  }
  glutPostRedisplay();
  glViewport(0, 0, currentWidth, currentHeight);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-worldWidth/2, worldWidth/2, -worldHeight/2, worldHeight/2, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y){
   switch(key){
    case 13:
        ENTER=1;
       break;
    case 27://esc
    if(currentScreen==JOGO&&!restart ){
      pause=-1;
      escape=1;
    }else
      exit(0);
    break;

    case 'a':case 'A':
        keyboardAction("moveLeft",1);
      break;

    case 'd':case 'D':
        keyboardAction("moveRight",1);
        if(currentScreen==SPLASH)
          DEBUG=true;
      break;

      case 'w':case 'W':
        keyboardAction("jump",1);
        break;

        case 't':case 'T':
          keyboardAction("changeAmmo",1);
          break;

      case 'c':case 'C':
        if(cheatMode)cheatMode=0;else cheatMode=1;
        break;

        case 'p':case 'P':
          if(currentScreen==JOGO&&!restart&&!escape)
            pause*=-1;
          break;

          case 'r':case 'R':
          if(currentScreen==JOGO&&pause>0){
            pause=-1;
            restart=1;
          }
            break;
      case'b':case'B':
        if(currentScreen==SPLASH)
          bugMODE=true;
      break;
      default:
         break;
   }
}

void update(int n){
    switch(currentScreen){
        case SPLASH:
          FPS=14;
          idxSplash++;
        break;
        case PREMENU:
            FPS=50;
            A+=0.01;
        break;
        case MENU:
          FPS=40;
        break;
        case PRE_PARTIDA:
          FPS=30;
          greyShade+=(float)0.08*auxPrepartida;
          if(greyShade>=0.9||greyShade<=0.1)
            auxPrepartida*=-1;
        break;
        case JOGO:
          FPS=gameFPS;
          if(pause>0){
            realizeJump();
            if(mouseClicked&&!BulletIsVisible){
              strengh+=(MAXstrengh-MINstrengh)/(FPS);
              if(strengh>=MAXstrengh)
                strengh=MINstrengh;
            }
          }
          if(idxGG>=0&&idxGG<8003)
            idxGG++;
        break;
        case OPCOES:
            FPS=40;
        break;
        case INSTRUCOES:
            FPS=40;
        break;
        case CREDITOS:
            if(idxCredits<1)
              FPS=0.13;
            else
            FPS=2;
        break;
    }
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, update, 0);
}

void idle(){
}

void mousePress(int button,int state,int x,int y){
    if(button==GLUT_LEFT_BUTTON){
        if(state==GLUT_DOWN){
            MOUSE1=1;
            MOUSE2=1;
            mouseClicked=1;
          }
      if(state==GLUT_UP){
            MOUSE1=0;
            MOUSE2=0;
        }
      mouseAction(1);
    }
}

void mousePassiveMotion(int x,int y){
  mouseX=x*((float)worldWidth/(float)currentWidth)-(worldWidth/2);
  mouseY=-y*((float)worldHeight/(float)currentHeight)+(worldHeight/2);
}

void mouseActiveMotion(int x,int y){
    MOUSE2=0;
    mouseX=x*((float)worldWidth/(float)currentWidth)-(worldWidth/2);
    mouseY=-y*((float)worldHeight/(float)currentHeight)+(worldHeight/2);
}

int main(int argc, char **argv){
    if(DEBUG) printf("definindo idioma...");
    setStrings();
    if(DEBUG) printf("OK\n");
    if(DEBUG) printf("definindo coordenadas...");
    defineCords();
    if(DEBUG) printf("OK\n");
    if(DEBUG) printf("iniciando openAL e openGL...");
    glutInit(&argc, argv);
    if(DEBUG) printf("OK\n");
    if(DEBUG) printf("carregando openAL...");
    ALinit();
    if(DEBUG) printf("OK\n");
    if(DEBUG) printf("carregando openGL...");
    setup();
    if(DEBUG) printf("OK\n");
    if(loadFromFiles){
      if(DEBUG) printf("carregndo configuracoes de jogo...");
      loadSettings();
      idxMap=mapPreConfig; if(idxMap==0)idxMap=1;
      if(DEBUG) printf("OK\n");
      if(DEBUG) printf("carregndo configuracoes de mapa...");
      loadMapSettings();
      if(DEBUG) printf("OK\n");
    }
    if(DEBUG) printf("registando callbacks...");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);
    glutIdleFunc(idle);
    glutPassiveMotionFunc(mousePassiveMotion);
    glutMotionFunc(mouseActiveMotion);
    glutMouseFunc(mousePress);
    if(DEBUG) printf("OK\n");
    if(DEBUG) printf("carregando arquivos...");
    loadFiles();
    if(DEBUG) printf("OK\n");
    if(DEBUG) printf("criando listas...");
    createList();
    if(DEBUG) printf("OK\n");

    if(DEBUG) printf("entrando no GLUT loop...OK\n");
    glutMainLoop();
    return 0;
}
