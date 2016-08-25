//JCEBAS.GL.h
double R=0,G=0,B=0,A=0;
int sR=1,sG=1,sB=1;
#define CHANGES 10
#define COLORSCALE 0.0039215686
#define STEPCOLORSIZE 1

//coloquei esses defines aqui
#define PI 3.14159265
#define worldWidth 800
#define worldHeight 600
//#define worldHeight 800
//^assim os quadrados ficam quadrados,prefiro

//implementei
void drawPolygon(float raio,unsigned long int lados,float x0,float y0,float z)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x0,y0,z);
    for(int i=0;i<=lados;i++)
    {
        glVertex3f(cos(2*PI*i/lados)*raio+x0,sin(2*PI*i/lados)*raio+y0,z);
    }
    glEnd();
}

void selectColor(char* color) {
  R=1;G=1;B=1;
  if(strEq(color,"black")){
      R=0;G=0;B=0;
  }else if(strEq(color,"red")){
      R=1;G=0;B=0;
  }else if(strEq(color,"green")){
      R=0;G=1;B=0;
  }else if(strEq(color,"blue")){
      R=0;G=0;B=1;
  }else if(strEq(color,"yellow")){
      R=1;G=1;B=0;
  }else if(strEq(color,"magenta")){
      R=1;G=0;B=1;
  }else if(strEq(color,"cyan")){
      R=0;G=1;B=1;
  }else if(strEq(color,"grey")){
      R=0.6;G=0.6;B=0.6;
  }else if(strEq(color,"violet")){   //mish 153,112,205 ou 99,70,CD
      R=0.6;G=0.4392156;B=0.80392156;
  }
  glColor3f(R, G, B);
}

void drawText(void* font, char* text, float x, float y,float z){
  glRasterPos3f(x, y,z);
  for (unsigned int i = 0;i<strlen(text);i++) {
     glutBitmapCharacter(font, text[i]);
  }
  //� melhor deixar isso na fun�ao draw,pq se n da bosta
   //glutSwapBuffers();
   //ou usar o post redisplay,mais pra frente a gente v�
   //glutPostRedisplay();
    //por enquanto bora deixar o comando pra desenhar manual e no main,acho q fica melhor
}

//agora precisa do z,pra fazer coisas no fundo background
void drawRectangle(float x0, float y0, float x1, float y1,float z){

   glBegin(GL_POLYGON);
        glVertex3f(x0, y0, z);
        glVertex3f(x1, y0, z);
        glVertex3f(x1, y1, z);
        glVertex3f(x0, y1, z);

    glEnd();

    //glutSwapBuffers();
    //mesma coisa
    //glutPostRedisplay();
}

void drawTexture(float x0, float y0, float x1, float y1,GLuint textureIndex){
  glColor3f(1, 1, 1);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, textureIndex);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0); glVertex3f(x0, y0,  0);
  glTexCoord2f(1, 0); glVertex3f(x1, y0,  0);
  glTexCoord2f(1, 1); glVertex3f(x1, y1,  0);
  glTexCoord2f(0, 1); glVertex3f(x0, y1,  0);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  glFlush();
  glColor3f(R, G, B);
}

void genColor(){
    if(rand()%CHANGES==0)
        switch(rand()%7){
            case 0:
                sR=1,sG=1,sB=-1;
            break;

            case 1:
                sR=1,sG=-1,sB=1;
            break;

            case 2:
                sR=1,sG=-1,sB=-1;
            break;

            case 3:
                sR=-1,sG=1,sB=1;
            break;

            case 4:
                sR=-1,sG=1,sB=-1;
            break;

            case 5:
                sR=-1,sG=-1,sB=1;
            break;

            case 6:
                sR=-1,sG=-1,sB=-1;
            break;
        }
    R+=COLORSCALE*STEPCOLORSIZE*sR;
    G+=COLORSCALE*STEPCOLORSIZE*sG;
    B+=COLORSCALE*STEPCOLORSIZE*sB;
    if(R<0)R=0;
    if(R>1)R=1;
    if(G>1)G=1;
    if(G<0)G=0;
    if(B>1)B=1;
    if(B<0)B=0;
    //glutPostRedisplay();
}
