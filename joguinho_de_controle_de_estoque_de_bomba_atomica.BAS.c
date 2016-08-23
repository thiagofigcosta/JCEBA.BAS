#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <SOIL.h>

#include "JCEBA.Util.h"
#include "JCEBA.GL.h"

#define PI 3.14159265
#define worldWidth 800
#define worldHeight 600

GLuint tex_Splash[24];

void drawScene(void){
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void setup(void){
    filePath=(char*)malloc(1);
    glClearColor(1, 1, 1, 0);

    for(int i=0;i<24;i++){
      getAnimatedFiles("Splash/corpLogo/",i,".png");
      tex_Splash[i]=SOIL_load_OGL_texture(filePath,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    }

    filePath=(char*)realloc(filePath,1);
}

void reshape(int width, int height){
  float razaoAspecto = (float)width/(float)height;
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(razaoAspecto * -worldWidth/2, razaoAspecto* worldWidth/2,
          -worldHeight/2, worldHeight/2,-1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y){
   switch(key){
      case 27://esc
         exit(0);
      break;

      default:
         break;
   }
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(worldWidth, worldHeight);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("JCEBA.BAS");

    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    setup();
    glutMainLoop();
    return 0;
}
