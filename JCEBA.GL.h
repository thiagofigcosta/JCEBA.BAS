double R=0,G=0,B=0;
int sR=1,sG=1,sB=1;
#define CHANGES 10
#define COLORSCALE 0.0039215686
#define STEPCOLORSIZE 1

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

void drawText(void* font, char* text, float x, float y){
  glRasterPos2f(x, y);
  for (unsigned int i = 0;i<strlen(text);i++) {
     glutBitmapCharacter(font, text[i]);
  }
   glFlush();
}

void drawRectangle(float x0, float y0, float x1, float y1){
   glBegin(GL_POLYGON);
        glVertex3f(x0, y0, 0);
        glVertex3f(x1, y0, 0);
        glVertex3f(x1, y1, 0);
        glVertex3f(x0, y1, 0);
    glEnd();
    glFlush();
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
}
