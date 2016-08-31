#include <stdio.h>
#include <string.h>
#include <math.h>

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


int main(){
  char str2[] = "valeu";
  char str1[] = "C Progressivo";

  int index =38;
  int fullsize=getNumberAlgo(index)+strlen(str1)+strlen(str2)+1;
  char filePath[fullsize];
  int idxBkp=index;
  for(int i=0;i<fullsize;i++){
    if(i<strlen(str1)){
      filePath[i]=str1[i];
    }
    else if(i>=strlen(str1)&&i<strlen(str1)+getNumberAlgo(index)){
      filePath[i]=getCharEqInt((idxBkp-idxBkp%(int)pow(10,getNumberAlgo(idxBkp)-1))/(int)pow(10,getNumberAlgo(idxBkp)-1));
      printf("%d\n", idxBkp-idxBkp%(int)pow(10,getNumberAlgo(idxBkp)-1)/(int)pow(10,getNumberAlgo(idxBkp)-1));
      idxBkp=idxBkp%(int)pow(10,getNumberAlgo(idxBkp)-1);
    }else{
      filePath[i]=str2[i-strlen(str1)-getNumberAlgo(index)];
}
  }
  printf("\n\n%s string\n",filePath );


  return 0;
}
