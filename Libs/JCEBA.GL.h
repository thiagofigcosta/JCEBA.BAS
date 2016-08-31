double R=0,G=0,B=0,A=0;
float greyShade=0;
int sR=1,sG=1,sB=1;
#define COLORSCALE 0.0039215686


//implementei
void drawPolygon(float raio,unsigned long int lados,Point p,float z)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(p.x,p.y,z);
    for(int i=0;i<=lados;i++)
    {
        glVertex3f(cos(2*PI*i/lados)*raio+p.x,sin(2*PI*i/lados)*raio+p.y,z);
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

void drawText(void* font, char* text, Point p,float z){
  glRasterPos3f(p.x,p.y,z);
  for (unsigned int i = 0;i<strlen(text);i++) {
     glutBitmapCharacter(font, text[i]);
  }
}

void drawRectangle(JRectangle r,float z){
   glBegin(GL_POLYGON);
        glVertex3f(r.p0.x, r.p0.y, z);
        glVertex3f(r.p1.x, r.p0.y, z);
        glVertex3f(r.p1.x, r.p1.y, z);
        glVertex3f(r.p0.x, r.p1.y, z);
    glEnd();
}

void drawTexture(JRectangle r,float z,GLuint textureIndex, int orientation){
  //glColor4f(1,1,1,A);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_ALPHA_TEST);
  if(!bugMODE||currentScreen==SPLASH||currentScreen==CREDITOS)
    glBindTexture(GL_TEXTURE_2D, textureIndex);
  else
    selectColor("violet");
  glBegin(GL_QUADS);
  if(orientation<0){
    glTexCoord2f(1, 0); glVertex3f(r.p0.x, r.p0.y, z);
    glTexCoord2f(0, 0); glVertex3f(r.p1.x, r.p0.y, z);
    glTexCoord2f(0, 1); glVertex3f(r.p1.x, r.p1.y, z);
    glTexCoord2f(1, 1); glVertex3f(r.p0.x, r.p1.y, z);
  }else{
    glTexCoord2f(0, 0); glVertex3f(r.p0.x, r.p0.y, z);
    glTexCoord2f(1, 0); glVertex3f(r.p1.x, r.p0.y, z);
    glTexCoord2f(1, 1); glVertex3f(r.p1.x, r.p1.y, z);
    glTexCoord2f(0, 1); glVertex3f(r.p0.x, r.p1.y, z);
  }
  glEnd();
  glDisable(GL_TEXTURE_2D);
  glDisable(GL_ALPHA_TEST);
  glColor4f(1,1,1,1);
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
