char language[15]="portuguese";
char pressEnterToContinue[35];

char btn_1P[35];
char btn_2P[35];
char btn_Off[35];
char btn_HowTo[35];
char btn_Play[35];
char btn_On[35];
char btn_Options[35];
char btn_Exit[35];
char btn_Back[35];

char howToPlay[4];
char music[10];
char wind[10];
char mapgen[20];
char difficulty[15];
char lifeInitAmount[35];
char bombInitAmount[50];

void setStrings(){
  if(strEq(language,"portuguese")){
      strcpy(btn_1P,"Buttons/pt/woglow/1Jogador.png");
      strcpy(btn_2P,"Buttons/pt/woglow/2Jogadores.png");
      strcpy(btn_Off,"Buttons/pt/woglow/Desligado.png");
      strcpy(btn_HowTo,"Buttons/pt/woglow/Instrucoes.png");
      strcpy(btn_Play,"Buttons/pt/woglow/Jogar.png");
      strcpy(btn_On,"Buttons/pt/woglow/Ligado.png");
      strcpy(btn_Options,"Buttons/pt/woglow/Opcoes.png");
      strcpy(btn_Exit,"Buttons/pt/woglow/Sair.png");
      strcpy(btn_Back,"Buttons/pt/woglow/Voltar.png");
      strcpy(pressEnterToContinue,"Pressione ENTER para iniciar");
      strcpy(howToPlay,"WIP");
      strcpy(music,"Musica:");
      strcpy(wind,"Vento:");
      strcpy(mapgen,"Geracao de mapa:");
      strcpy(difficulty,"Dificuldade:");
      strcpy(lifeInitAmount,"Quantidade inicial de vidas:");
      strcpy(bombInitAmount,"Quantidade inicial de bombas atomicas:");
  }else if(strEq(language,"english")){
      strcpy(pressEnterToContinue,"Press ENTER to continue");
  }

}
