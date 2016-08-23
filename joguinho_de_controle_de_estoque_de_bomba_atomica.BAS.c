#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <SOIL.h>

#define PI 3.14159265
#define ARATIO 1.777777

GLuint tex_Splash[24];
int teste = 0;
char* filePath;

int strEq(char* str1, char*str2){
    int i,value = 1;
    for(i=0;str1[i]!='\0';i++)
        if(str1[i]!=str2[i]){
            value=0;
            break;
        }
    return value;
}

void drawText(void* font, char* text, float x, float y){
  glRasterPos2f(x, y);
  for (unsigned int i = 0;i<strlen(text);i++) {
     glutBitmapCharacter(font, text[i]);
  }
   glFlush();
}

void drawRectangle(int x0, int y0, int x1, int y1, char* color){

    glColor3f(1, 1, 1);
    if(strEq(color,"black")){
        glColor3f(0, 0, 0);
    }else if(strEq(color,"red")){
        glColor3f(1, 0, 0);
    }else if(strEq(color,"green")){
        glColor3f(0, 1, 0);
    }else if(strEq(color,"blue")){
        glColor3f(0, 0, 1);
    }else if(strEq(color,"yellow")){
        glColor3f(1, 1, 0);
    }else if(strEq(color,"magenta")){
        glColor3f(1, 0, 1);
    }else if(strEq(color,"cyan")){
        glColor3f(0, 1, 1);
    }else if(strEq(color,"grey")){
        glColor3f(0.6, 0.6, 0.6);
    }else if(strEq(color,"violet")){   //mish 153,112,205 ou 99,70,CD
        glColor3f(0.6, 0.4392156, 0.80392156);
    }
   glBegin(GL_POLYGON);
        glVertex3f(x0, y0, 0);
        glVertex3f(x1, y0, 0);
        glVertex3f(x1, y1, 0);
        glVertex3f(x0, y1, 0);
    glEnd();

    glFlush();

}

int getNumberAlgo(int num){
  int divisor=1;
  int numberAlgo=0;
  do{
    numberAlgo++;
    divisor*=10;
  }while(num/divisor>0);
  return numberAlgo;
}
char getCharEqInt(int i){
  switch (i) {
    default: return '0';
    case 1: return '1';
    case 2: return '2';
    case 3: return '3';
    case 4: return '4';
    case 5: return '5';
    case 6: return '6';
    case 7: return '7';
    case 8: return '8';
    case 9: return '9';
  }
}
void getAnimatedFiles(char* str1,int index,char*str2){
  int fullsize=getNumberAlgo(index)+strlen(str1)+strlen(str2)+1;
  filePath=(char*)realloc(filePath,fullsize*sizeof(char));
  int idxBkp=index;
  for(int i=0;i<fullsize;i++){
    if(i<strlen(str1))
      filePath[i]=str1[i];
    else if(i>=strlen(str1)&&i<strlen(str1)+getNumberAlgo(index)){
      filePath[i]=getCharEqInt((idxBkp-idxBkp%(int)round(pow(10,getNumberAlgo(idxBkp)-1)))/(int)round(pow(10,getNumberAlgo(idxBkp)-1)));
      idxBkp=idxBkp%(int)round(pow(10,getNumberAlgo(idxBkp)-1));
    }else
      filePath[i]=str2[i-strlen(str1)-getNumberAlgo(index)];

  }
}

void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);



    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex_Splash[teste]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-80, -80,  0);
    glTexCoord2f(1, 0); glVertex3f(80, -80,  0);
    glTexCoord2f(1, 1); glVertex3f( 80,  80,  0);
    glTexCoord2f(0, 1); glVertex3f(-80,  80,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
  //  drawText(GLUT_BITMAP_TIMES_ROMAN_24,getAnimatedFiles("Splash/",50,".png"), 0,0);
    glFlush();
  }


// Inicia algumas variáveis de estado
void setup(void)
{
  filePath=(char*)malloc(1);
    // cor para limpar a tela
    glClearColor(1, 1, 1, 0);      // branco
    for(int i=0;i<24;i++){
        getAnimatedFiles("Splash/",i,".png");
      tex_Splash[i]=SOIL_load_OGL_texture(
                      filePath,
                        SOIL_LOAD_AUTO,
                        SOIL_CREATE_NEW_ID,
                        SOIL_FLAG_INVERT_Y
                      );
                    }
                      filePath=(char*)realloc(filePath,1);
}

// Callback de redimensionamento
void reshape(int w, int h)
{
  w=h*ARATIO;
  glutReshapeWindow( w, h);

   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-w/2, w/2, -h/2, h/2, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glViewport(0,0,w,h);
}

// Callback de evento de teclado
void keyboard(unsigned char key, int x, int y)
{
   switch(key)
   {
      // Tecla ESC
      case 27:
         exit(0);
         break;
         case '+':
           teste++;
           glutPostRedisplay();
           break;
           case '-':
             teste--;
             glutPostRedisplay();
             break;
      default:
         break;
   }
}

// Rotina principal
int main(int argc, char **argv)
{
    // Acordando o GLUT
    glutInit(&argc, argv);

    // Definindo a versão do OpenGL que vamos usar
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    // Configuração inicial da janela do GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);

    // Abre a janela
    glutCreateWindow("JCEBA.BAS");

    // Registra callbacks para alguns eventos
    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    setup();

    // Entra em loop e nunca sai
    glutMainLoop();
    return 0;
}
