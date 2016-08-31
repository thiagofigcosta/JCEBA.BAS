//main
#include <stdio.h>
#include "JCEBA.Util.h"
#include "JCEBA.GL.h"
#include "JCEBA.AL.h"
#include "JCEBA.Strings.h"
#include "JCEBA.LoadFiles.h"
#include "JCEBA.Scenes.h"
#include "JCEBA.Buttons.h"

#define DEBUG 1 //colocar usar coisas

int currentScreen=MENU; //currentScreen=SPLASH;
//animacoes
int idxSplash=0;
float FPS=1;

void menu(){
    glColor4f(1,1,1,1);
    glCallList(fullscreenBackground);
    glColor4f(1,1,1,1);
    glCallList(title);
    glCallList(subtitle);
    glColor4f(R, G, B, A);
    currentScreen=actionButtons(MENU);
}

void preMenu(){

    glCallList(fullscreenBackground);

    if(A>=1)
    {
        glColor4f(1,1,1,(A-1)*2);
        glCallList(subtitle);
        glColor4f(R, G, B, A);
    }
    if(A>=2)
    {
        glColor4f(1,1,0,(A-2)*4);
<<<<<<< HEAD
        drawText(GLUT_BITMAP_HELVETICA_18,str_pressEnterToContinue,pos_pressEnterToContinue,0.9);
=======
        drawText(GLUT_BITMAP_HELVETICA_18,pressEnterToContinue,pos_pressEnterToContinue,0.9);
>>>>>>> master
    }
    if(ENTER||MOUSE1)
    {
        currentScreen=MENU;
        ENTER=0;
    }
}

void splash(){
  pos_Splash.p0.x=-worldWidth/2;pos_Splash.p0.y=-114;
  pos_Splash.p1.x=worldWidth/2;pos_Splash.p1.y=114;
  if(DEBUG) printf("splash.");
  //glCallList(Splash);
  glColor4f(1,1,1,1);
  if(idxSplash<nOfSplashImgs-1)
    drawTexture(pos_Splash,1,tex_Splash[idxSplash]);
  else
    drawTexture(pos_Splash,1,tex_Splash[nOfSplashImgs-1]);
  glColor4f(R, G, B, A);
  if(idxSplash>=nOfSplashImgs+16){
    currentScreen=PREMENU;
    if(DEBUG) printf("..OK\n");
  }
}

void game(){

}

void options(){
    glColor3f(1,1,1);
    glCallList(sub0Background);
    selectColor("yellow");
    glCallList(optionsMenu);
    selectColor("grey");
    currentScreen=actionButtons(OPCOES);
}

void howto(){
    glColor3f(1,1,1);
    glCallList(sub1Background);
    selectColor("yellow");
    glCallList(instructionsMenu);
    selectColor("grey");
    currentScreen=actionButtons(INSTRUCOES);
}

void credits(){

}

void numPlayers(){
    selectColor("red");
    glCallList(fullscreenBackground);
    selectColor("grey");
    currentScreen=actionButtons(NUM_JOGADORES);
}

void chooseChars(){
    FPS=90;
    glColor4f(1,1,1,1);
    glCallList(mapBackground);
    if(players==2){
      if(player1==BRASIL) drawTexture(pos_flagBR,1,tex_X);
      if(player1==RUSSIA) drawTexture(pos_flagRussia,1,tex_X);
      if(player1==KOREA) drawTexture(pos_flagKorea,1,tex_X);
      if(player1==ISLAMIC) drawTexture(pos_flagIslamic,1,tex_X);
      if(player1==USA) drawTexture(pos_flagUSA,1,tex_X);
    }
    glColor4f(R, G, B, A);
    currentScreen=actionButtons(ESC_PERSONAGEM);
}

void prePartida(){

}

void drawScene(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    selectColor("green");//provavelmente vai ser removido depois
    //drawText(GLUT_BITMAP_HELVETICA_18,"0",mouseX,mouseY,0.9);
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
        case SAIR:          exit(0);break;
    }
    glutSwapBuffers();
}

void setup(void){
    glClearColor(0, 0, 0, 0);
    if(DEBUG) printf("carregando arquivos...");
    loadFiles();
    if(DEBUG) printf("OK\n");
    if(DEBUG) printf("definindo coordenadas...");
    defineCords();
    if(DEBUG) printf("OK\n");
    glEnable(GL_DEPTH_TEST);//coordenada z
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    createList();
    //glutWarpPointer	(1,1);
    //muda o cursor(interessante mais p frente):
    //glutSetCursor(GLUT_CURSOR_NONE);
}

void reshape(int width, int height){
  currentWidth=(int)height*worldWidth/worldHeight;
  currentHeight=(int)height;

  if(width<worldWidth||height<worldHeight){
      currentWidth=worldWidth;
      currentHeight=worldHeight;
  }

  glutReshapeWindow(currentWidth,currentHeight);
  glutPostRedisplay();

  glViewport(0, 0, currentWidth, currentHeight);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-currentWidth/2, currentWidth/2, -currentHeight/2, currentHeight/2, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y){
   switch(key){
    case 13:
        ENTER=1;
       break;
    case 27://esc
         exit(0);
      break;

      default:
         break;
   }
}

void mousePassiveMotion(int x,int y){
    //precisa melhorar isso depois,com as coisas q o prof vai passar deve dar
    //ou entao talvez de com o glut 1.1 q eu n consigo iniciar
    //tenta colocar s MouseX=x e MouseY=-y,talvez com o opengl 1.1 isso funcione
    mouseX=x-(currentWidth/2);
    mouseY=-y+(currentHeight/2);
}

void mouseActiveMotion(int x,int y){
    //precisa melhorar isso depois,com as coisas q o prof vai passar deve dar
    //ou entao talvez de com o glut 1.1 q eu n consigo iniciar
    //tenta colocar s MouseX=x e MouseY=-y,talvez com o opengl 1.1 isso funcione
    MOUSE1=0;
    mouseX=x-(currentWidth/2);
    mouseY=-y+(currentHeight/2);
}

void update(int n){
    switch(currentScreen){
        case SPLASH:{
          FPS=300;
          idxSplash++;
        }break;
        case PREMENU:{
            FPS=74.29;
            A+=0.01;
        }break;
        case MENU:{

        }break;
        case JOGO:{

        }break;
        case OPCOES:{

        }break;
        case INSTRUCOES:{

        }break;
        case CREDITOS:{

        }break;
    }
    glutPostRedisplay();
    glutTimerFunc(FPS/3.28083, update, 0);//(double)FPS/3.28083
}

void idle(){
}

void mousePress(int button,int state,int x,int y){
    if(button==GLUT_LEFT_BUTTON){
        if(state==GLUT_DOWN)
            MOUSE1=1;
        if(state==GLUT_UP)
            MOUSE1=0;
    }
}

int main(int argc, char **argv){
    if(DEBUG) printf("definindo idioma...");
    setStrings();
    if(DEBUG) printf("OK\n");
    glutInit(&argc, argv);
    alutInit(&argc, argv);

    if(DEBUG) printf("carregando openAL...");
    ALinit();
    if(DEBUG) printf("OK\n");

    //alSourcePlay(source[0]); TOCA MSUICA
    //alSourcePause(source[0]); pausa MSUICA
    //alSourceStop(source[0]); para MSUICA

    //comentados pq essas 2 fun�ao n roda no meu PC =/
    //glutInitContextVersion(1, 1);
    //glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(worldWidth, worldHeight);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("JCEBA.BAS");

    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);
    glutIdleFunc(idle);
    glutPassiveMotionFunc(mousePassiveMotion);
    glutMotionFunc(mouseActiveMotion);
    glutMouseFunc(mousePress);
    if(DEBUG) printf("configurando sistema...");
    setup();
    if(DEBUG) printf("OK\n");
    if(DEBUG) printf("entrando no GLUT loop...\n");
    glutMainLoop();
    return 0;
}
