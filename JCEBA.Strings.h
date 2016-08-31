char language[15]="portuguese";
<<<<<<< HEAD
=======
char pressEnterToContinue[35];
>>>>>>> master

char btn_1P[35];
char btn_2P[35];
char btn_Off[35];
char btn_HowTo[35];
char btn_Play[35];
char btn_On[35];
char btn_Options[35];
char btn_Exit[35];
char btn_Back[35];

<<<<<<< HEAD
char str_pressEnterToContinue[35];
char str_howToPlay[4];
char str_music[10];
char str_sound[10];
char str_Language[10];
char str_wind[10];
char str_mapgen[20];
char str_difficulty[15];
char str_lifeInitAmount[35];
char str_bombInitAmount[50];
=======
char howToPlay[4];
char music[10];
char wind[10];
char mapgen[20];
char difficulty[15];
char lifeInitAmount[35];
char bombInitAmount[50];
>>>>>>> master

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
<<<<<<< HEAD
      strcpy(str_pressEnterToContinue,"Pressione ENTER para iniciar");
      strcpy(str_howToPlay,"WIP");
      strcpy(str_music,"Musica:");
      strcpy(str_wind,"Vento:");
      strcpy(str_mapgen,"Geracao de mapa:");
      strcpy(str_difficulty,"Dificuldade:");
      strcpy(str_lifeInitAmount,"Quantidade inicial de vidas:");
      strcpy(str_bombInitAmount,"Quantidade inicial de bombas atomicas:");
      strcpy(str_sound,"Som:");
      strcpy(str_Language,"Idioma:");
  }else if(strEq(language,"english")){
      strcpy(btn_1P,"Buttons/en/woglow/1Player.png");
      strcpy(btn_2P,"Buttons/en/woglow/2Players.png");
      strcpy(btn_Off,"Buttons/en/woglow/Off.png");
      strcpy(btn_HowTo,"Buttons/en/woglow/Instructions.png");
      strcpy(btn_Play,"Buttons/en/woglow/Play.png");
      strcpy(btn_On,"Buttons/en/woglow/On.png");
      strcpy(btn_Options,"Buttons/en/woglow/Options.png");
      strcpy(btn_Exit,"Buttons/en/woglow/Exit.png");
      strcpy(btn_Back,"Buttons/en/woglow/Back.png");
      strcpy(str_pressEnterToContinue,"Press ENTER to continue");
      strcpy(str_howToPlay,"WIP");
      strcpy(str_music,"Music:");
      strcpy(str_wind,"Wind:");
      strcpy(str_mapgen,"Map gen:");
      strcpy(str_difficulty,"Difficulty:");
      strcpy(str_lifeInitAmount,"Initial amount of lives:");
      strcpy(str_bombInitAmount,"Initial amount of atomic bombs:");
      strcpy(str_sound,"Sound:");
      strcpy(str_Language,"Language:");
=======
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
>>>>>>> master
  }

}
