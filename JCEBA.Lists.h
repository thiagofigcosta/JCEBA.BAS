//listas
int fullscreenBackground,title,subtitle,playIcon,optionsIcon,howtoIcon,
    quitIcon,fullscreenFront;

void createList()
{
    fullscreenBackground=glGenLists(1);
    fullscreenFront=glGenLists(1);
    //� possivel criar o menu todo em apenas uma lista,mas pra mudar a textura de cada um
    //individualmente acho q deve ser melhor assim
    title=glGenLists(1);
    subtitle=glGenLists(1);
    playIcon=glGenLists(1);
    optionsIcon=glGenLists(1);
    howtoIcon=glGenLists(1);
    quitIcon=glGenLists(1);

    glNewList(fullscreenBackground,GL_COMPILE);
        drawRectangle(-worldWidth,-worldHeight,worldWidth,worldHeight,-0.9);glEndList();
    glNewList(fullscreenFront,GL_COMPILE);
        drawRectangle(-worldWidth,-worldHeight,worldWidth,worldHeight,0.9);glEndList();
    glNewList(title,GL_COMPILE);
        drawRectangle(-400,0,400,250,0);glEndList();
    glNewList(subtitle,GL_COMPILE);    //subtitulo
        drawRectangle(-350,-80,350,-10,0);glEndList();

    glNewList(playIcon,GL_COMPILE);    //jogar
        drawRectangle(-50,-160,50,-130,0.5);glEndList();
    glNewList(optionsIcon,GL_COMPILE);    //opcoes
        drawRectangle(-60,-200,60,-170,0.5);glEndList();
    glNewList(howtoIcon,GL_COMPILE);    //instrucoes
        drawRectangle(-70,-240,70,-210,0.5);glEndList();
    glNewList(quitIcon,GL_COMPILE);    //sair
        drawRectangle(-40,-280,40,-250,0.5);glEndList();
}

void menuList()
{

        if(mouseX>=-50&&mouseY>=-180&&mouseX<=50&&mouseY<=-150)
            selectColor("yellow");//parte onde muda a textura
        else selectColor("grey");
        glCallList(playIcon);

        if(mouseX>=-60&&mouseY>=-220&&mouseX<=60&&mouseY<=-190)
            selectColor("yellow");//parte onde muda a textura
        else selectColor("grey");
        glCallList(optionsIcon);

        if(mouseX>=-70&&mouseY>=-260&&mouseX<=70&&mouseY<=-230)
            selectColor("yellow");//parte onde muda a textura
        else selectColor("grey");
        glCallList(howtoIcon);

        if(mouseX>=-40&&mouseY>=-300&&mouseX<=40&&mouseY<=-270)
            selectColor("yellow");//parte onde muda a textura
        else selectColor("grey");
        glCallList(quitIcon);
}
