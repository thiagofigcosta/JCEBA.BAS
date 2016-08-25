int compareButton(Rectangle r,int currentScreenValue,int nextScreenValue,int listValue)
{
    if(mouseX>=r.p0.x&&mouseY>=r.p0.y&&mouseX<=r.p1.x&&mouseY<=r.p1.y){
        glColor3f(0.15,0.15,0.15);//parte onde muda a textura
        if(MOUSE1){
                MOUSE1=0;
                    return nextScreenValue;}
    }else glColor4f(1,1,1,1);
            glCallList(listValue);
    return currentScreenValue;
}

int actionButtons(int screen)
{
    int returnValue;
    switch(screen)
    {
        case MENU:

            returnValue=compareButton(pos_btnPlay,screen,NUM_JOGADORES,playIcon);
            if(returnValue!=screen)
                return returnValue;

            returnValue=compareButton(pos_btnOptions,screen,OPCOES,optionsIcon);
            if(returnValue!=screen)
                return returnValue;

            returnValue=compareButton(pos_btnHowTo,screen,INSTRUCOES,howtoIcon);
            if(returnValue!=screen)
                return returnValue;

            returnValue=compareButton(pos_btnQuit,screen,SAIR,quitIcon);
            if(returnValue!=screen)
                return returnValue;

        return screen;

        case ESC_PERSONAGEM:
          returnValue=compareButton(pos_btnBack,screen,NUM_JOGADORES,backButton);
          if(returnValue!=screen)
              return returnValue;

              returnValue=compareButton(pos_flagRussia,screen,PRE_PARTIDA,flagRussia);//0
              if(returnValue!=screen){
                if(players==1){
                  player1=RUSSIA;
                  player2=BRASIL;
                }else if(!player1){
                    player1=RUSSIA;
                    returnValue=ESC_PERSONAGEM;
                  }
                  else if(player1!=RUSSIA){
                    player2=RUSSIA;
                  }else returnValue=ESC_PERSONAGEM;
                  return returnValue;
                }
              returnValue=compareButton(pos_flagBR,screen,PRE_PARTIDA,flagBR);//1
              if(returnValue!=screen){
                if(players==1){
                  player1=BRASIL;
                  player2=BRASIL;
                }else if(!player1){
                    player1=BRASIL;
                    returnValue=ESC_PERSONAGEM;
                  }else if(player1!=BRASIL){
                    player2=BRASIL;
                  }else returnValue=ESC_PERSONAGEM;
                  return returnValue;
                }
              returnValue=compareButton(pos_flagUSA,screen,PRE_PARTIDA,flagUSA);//2
              if(returnValue!=screen){
                if(players==1){
                  player1=USA;
                  player2=BRASIL;
                }else if(!player1){
                    player1=USA;
                    returnValue=ESC_PERSONAGEM;
                  }
                  else if(player1!=USA){
                    player2=USA;
                  }else returnValue=ESC_PERSONAGEM;
                  return returnValue;
                }
              returnValue=compareButton(pos_flagIslamic,screen,PRE_PARTIDA,flagIsla);//3
              if(returnValue!=screen){
                if(players==1){
                  player1=ISLAMIC;
                  player2=BRASIL;
                  return returnValue;
                }else if(!player1){
                    player1=ISLAMIC;
                    returnValue=ESC_PERSONAGEM;
                  }
                  else if(player1!=ISLAMIC){
                    player2=ISLAMIC;
                  }else returnValue=ESC_PERSONAGEM;
                  return returnValue;
                }
              returnValue=compareButton(pos_flagKorea,screen,PRE_PARTIDA,flagKorea);//4
              if(returnValue!=screen){
                if(players==1){
                  player1=KOREA;
                  player2=BRASIL;
                }else if(!player1){
                    player1=KOREA;
                    returnValue=ESC_PERSONAGEM;
                  }
                  else if(player1!=KOREA){
                    player2=KOREA;
                  }else returnValue=ESC_PERSONAGEM;
                  return returnValue;
                }
        return screen;

        case OPCOES:

            returnValue=compareButton(pos_btnBack,screen,MENU,backButton);
            if(returnValue!=screen)
                return returnValue;

        return screen;

        case INSTRUCOES:

            returnValue=compareButton(pos_btnBack,screen,MENU,backButton);
            if(returnValue!=screen)
                return returnValue;

        return screen;

        case NUM_JOGADORES:

            returnValue=compareButton(pos_btn1P,screen,ESC_PERSONAGEM,onePlayerButton);
            if(returnValue!=screen)
            {
                players=1;
                player1=0;player2=0;
                return returnValue;
            }

            returnValue=compareButton(pos_btn2P,screen,ESC_PERSONAGEM,twoPlayersButton);
            if(returnValue!=screen)
            {
                players=2;
                player1=0;player2=0;
                return returnValue;
            }

            returnValue=compareButton(pos_btnBack,screen,MENU,backButton);
            if(returnValue!=screen)
                return returnValue;
        return screen;
    }

}
