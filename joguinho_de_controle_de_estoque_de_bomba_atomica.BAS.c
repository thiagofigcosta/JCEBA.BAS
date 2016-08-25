//main
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <SOIL.h>

#include "JCEBA.Util.h"
#include "JCEBA.GL.h"
#include "JCEBA.Lists.h"
#include "JCEBA.Strings.h"

char ENTER;
int currentScreen=SPLASH;
GLuint tex_Splash[24];

void menu()
{

    selectColor("red");//cores arbitrarias,serao texturas
    glCallList(fullscreenBackground);
    selectColor("grey");
    glCallList(title);
    glCallList(subtitle);
    menuList();
    glutSwapBuffers();
}

void preMenu()
{
    selectColor("red");
    glCallList(fullscreenBackground);
    glColor4f(0.6,0.6,0.6,A);
    glCallList(title);
    if(A>=1)
    {
        glColor4f(0.6,0.6,0.6,(A-1)*2);
        glCallList(subtitle);
    }
    if(A>=2)
    {
        glColor4f(1,1,0,(A-2)*4);
        drawText(GLUT_BITMAP_HELVETICA_18,pressEnterToContinue,-155,-200,0.9);
    }
    glutSwapBuffers();
    if(ENTER)
        currentScreen=MENU;
}

void splash()
{
    /*
        <3
    */
    glutSwapBuffers();
    currentScreen=PREMENU;//pr�-menu foi boa
}

void game()
{
    /*
        <3
    */
    glutSwapBuffers();
}

void options()
{
    /*
        <3
    */
    glutSwapBuffers();
}

void howto()
{
    /*
        <3
    */
    glutSwapBuffers();
}

void credits()
{
    /*
        <3
    */
    glutSwapBuffers();
}


void drawScene(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    selectColor("green");//provavelmente vai ser removido depois
    drawText(GLUT_BITMAP_HELVETICA_18,"0",mouseX,mouseY,0.9);
    switch(currentScreen)
    {
        case SPLASH:        splash();break;
        case MENU:          menu();break;
        case PREMENU:       preMenu();break;
        case JOGO:          game();break;
        case OPCOES:        options();break;
        case INSTRUCOES:    howto();break;
        case CREDITOS:      credits();break;
    }
}

void setup(void){
    filePath=(char*)malloc(1);
    glClearColor(1, 1, 1, 0);

    for(int i=0;i<24;i++){
      getAnimatedFiles("Splash/corpLogo/",i,".png");
      //textura comentada =/
      //tex_Splash[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    }

    filePath=(char*)realloc(filePath,1);
    glEnable(GL_DEPTH_TEST);//coordenada z
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    createList();
    //glutWarpPointer	(1,1);


    //muda o cursor(interessante mais p frente):
    //glutSetCursor(GLUT_CURSOR_NONE);
}

void reshape(int width, int height){
    if(width<worldWidth||height<worldHeight){
        glutReshapeWindow(worldWidth,worldHeight);
        currentWidth=worldWidth;
    }

  float aspectRatio = (float)width/(float)height;
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(aspectRatio * -worldWidth/2, aspectRatio* worldWidth/2,
          -worldHeight/2, worldHeight/2,-1.0, 1.0);
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

void mouseMotion(int x,int y)
{
    //precisa melhorar isso depois,com as coisas q o prof vai passar deve dar
    //ou entao talvez de com o glut 1.1 q eu n consigo iniciar
    //tenta colocar s� MouseX=x e MouseY=-y,talvez com o opengl 1.1 isso funcione
    mouseX=x-400;
    mouseY=-y+300;
}

void update(int n)
{
    if(currentScreen==PREMENU)
    {
        A+=0.01;
    }
    glutPostRedisplay();
    glutTimerFunc(33, update, 0);
}

void idle(){

}

int main(int argc, char **argv){
    setStrings();
    glutInit(&argc, argv);

    //comentados pq essas 2 fun�ao n roda no meu PC =/
    //glutInitContextVersion(1, 1);
    //glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    //GLUT_DOUBLE � melhor,� so substituir glflush() por glutswapbuffers()
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(worldWidth, worldHeight);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("JCEBA.BAS");

    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);
    glutIdleFunc(idle);
    glutPassiveMotionFunc(mouseMotion);
    setup();
    glutMainLoop();
    return 0;
}
