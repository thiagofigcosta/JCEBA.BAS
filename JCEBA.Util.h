//JCEBA.Util.h

//parametros pra passar no drawScene do main
#define SPLASH -111
#define PREMENU -117
#define MENU -112
#define JOGO -113
#define OPCOES -114
#define INSTRUCOES -115
#define CREDITOS -116


char* filePath;
float currentWidth,currentHeight;
int mouseX=0,mouseY=0;

//tem uma fun�ao q faz isso no string.h ��
int strEq(char* str1, char*str2){
    int i,value = 1;
    for(i=0;str1[i]!='\0';i++)
        if(str1[i]!=str2[i]){
            value=0;
            break;
        }
    return value;
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
