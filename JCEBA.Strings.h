char language[15]="portuguese";
char pressEnterToContinue[29];

void setStrings(){
  if(strEq(language,"portuguese")){
      strcpy(pressEnterToContinue,"Pressione ENTER para iniciar");
  }else if(strEq(language,"english")){
      strcpy(pressEnterToContinue,"Press ENTER to continue");
  }

}
