int compareButton(JRectangle r,int currentScreenValue,int nextScreenValue,int listValue)
{
    if(mouseX>=r.p0.x&&mouseY>=r.p0.y&&mouseX<=r.p1.x&&mouseY<=r.p1.y){
        glColor3f(0.15,0.15,0.15);//parte onde muda a textura
        if(MOUSE2){
                MOUSE2=0;
                if(soundState)alSourcePlay(ALsource[4]);
                    return nextScreenValue;
                  }
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

              returnValue=compareButton(pos_flagRand,screen,PRE_PARTIDA,flagRand);//0
              if(returnValue!=screen){
                int tmp=randCountry();
                if(players==1){
                  player1=tmp;
                  player2=BRASIL;
                }else if(!player1){
                    player1=tmp;
                    returnValue=ESC_PERSONAGEM;
                  }else if(player1!=tmp||permitEqualCountrys){
                    player2=tmp;
                  }else{
                    while (player1==tmp) {
                      tmp=randCountry();
                    }
                    player2=tmp;
                  }
                  return returnValue;
                }

                returnValue=compareButton(pos_flagRussia,screen,PRE_PARTIDA,flagRussia);//0
                if(returnValue!=screen){
                  if(players==1){
                    player1=RUSSIA;
                    player2=BRASIL;
                  }else if(!player1){
                      player1=RUSSIA;
                      returnValue=ESC_PERSONAGEM;
                    }else if(player1!=RUSSIA||permitEqualCountrys){
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
                  }else if(player1!=BRASIL||permitEqualCountrys){
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
                  else if(player1!=USA||permitEqualCountrys){
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
                  else if(player1!=ISLAMIC||permitEqualCountrys){
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
                  else if(player1!=KOREA||permitEqualCountrys){
                    player2=KOREA;
                  }else returnValue=ESC_PERSONAGEM;
                  return returnValue;
                }
        return screen;

        case PRE_PARTIDA:
          returnValue=compareButton(pos_btnPlay2,screen,JOGO,btnPlay2);
          if(returnValue!=screen)
              return returnValue;
        return screen;

        case OPCOES:

        returnValue=compareButton(pos_btnBack,screen,MENU,backButton);
        if(returnValue!=screen)
            return returnValue;
        //criar lista da textura do botão RESTORE
        returnValue=compareButton(pos_btnPlay2,screen,MENU,restore);//btnPlay2 to btnRESTORE q tem q ser criado
        if(returnValue!=screen){
            restoreDefaultSettings();
            return screen;//continua na msm tela
        }
        returnValue=compareButton(pos_btnQuit,screen,EDICAO_MAPA,mapConfigs);//btnPlay2 to btnMAPS q tem q ser criado
        if(returnValue!=screen)
            return returnValue;

        return screen;

        case INSTRUCOES:

            returnValue=compareButton(pos_btnBack,screen,MENU,backButton);
            if(returnValue!=screen)
                return returnValue;

        return screen;

        case EDICAO_MAPA:

            returnValue=compareButton(pos_btnBack,screen,OPCOES,backButton);
            if(returnValue!=screen)
                return returnValue;

            returnValue=compareButton(pos_btnPlay2,screen,MENU,Example);
            if(returnValue!=screen){
              mapGen(); refreshMapList(0); alreadyGenMap=true;
                return screen;
              }

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

        case 98:

        screen=JOGO;
        returnValue=compareButton(pos_btnPlay2,screen,PRE_PARTIDA,continueIcon);
        if(returnValue!=screen){
            player2=stage;
            return returnValue;
          }

          returnValue=compareButton(pos_btnQuit,screen,MENU,quitIcon);
            if(returnValue!=screen)
                return returnValue;

        return screen;

        case 99:

          screen=JOGO;
            returnValue=compareButton(pos_btnPlay2,screen,CREDITOS,continueIcon);
            if(returnValue!=screen)
                return returnValue;

        return screen;

        case 101:

          screen=JOGO;
            returnValue=compareButton(pos_btnPlay2,screen,MENU,continueIcon);
            if(returnValue!=screen)
                return returnValue;

        return screen;

        case 201:
          screen=JOGO;
          returnValue=compareButton(pos_btnQuit,screen,MENU,quitIcon);
          if(returnValue!=screen){
              currentScreen=returnValue;
              pause=1;
              return 0;
            }

          returnValue=compareButton(pos_btnPlay2,screen,MENU,continueIcon);
          if(returnValue!=screen){
            mouseClicked=0;
            MOUSE1=0;
            pause*=-1;
          return 0;
          }
        return screen;

        case 202:
          screen=JOGO;
          returnValue=compareButton(pos_btnPlay2,screen,PRE_PARTIDA,continueIcon);
          if(returnValue!=screen){
              pause=1;
              currentScreen=returnValue;
              return 0;
            }

          returnValue=compareButton(pos_btnBack,screen,MENU,backButton);
          if(returnValue!=screen){
            pause=1;
            mouseClicked=0;
            MOUSE1=0;
          return 0;
          }
        return screen;
    }
}
