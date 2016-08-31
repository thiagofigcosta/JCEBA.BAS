SETTINGS configs;
void saveSettings(){
  configs.gameFPS=gameFPS;
  configs.resolutionIdx=resolutionIdx;
  configs.music=musicState;
  configs.sound=soundState;
  configs.windState=windState;
  configs.difficulty=difficulty;
  configs.lives=initPlayerLifes;
  configs.specialAmmo=initPlayerBombs;
  configs.maps=mapPreConfig;
  configs.language=getLanguageInt(language);
  languageIdx=getLanguageInt(language);
  FILE *settingsFP=fopen("settings.bin","wb");
	if(settingsFP==NULL){
        if(DEBUG)printf("Erro ao salvar arquivo settings.bin\n");
        return;
	}
	fwrite(&configs,sizeof(SETTINGS),1,settingsFP);
	fclose(settingsFP);
}

void saveMapConfig(){
    FILE *mapSettingsFP=fopen("mapSettings.bin","wb");
	if(mapSettingsFP==NULL){
      if(DEBUG)printf("\nErro ao gravar o arquivo mapSettings.bin\n");
      return;
    }
    for(int i=0;i<numMaps;i++){
        fwrite(&mapType[i],sizeof(MAP_SETTINGS),1,mapSettingsFP);
    }
    fclose(mapSettingsFP);
}
void loadSettings(){
	FILE *settingsFP=fopen("settings.bin","rb");
	if(settingsFP==NULL){
        if(DEBUG)printf("Erro ao carregar settings.bin\n");
        if(DEBUG)printf("Criando novo arquivo settings.bin...");
        saveSettings();
        if(DEBUG)printf("OK\n");
        return;
    }
  fread(&configs,sizeof(SETTINGS),1,settingsFP);
	fclose(settingsFP);
    gameFPS=configs.gameFPS;
    resolutionIdx=configs.resolutionIdx;
    musicState=configs.music;
    soundState=configs.sound;
    windState=configs.windState;
    difficulty=configs.difficulty;
    initPlayerLifes=configs.lives;
    initPlayerBombs=configs.specialAmmo;
    mapPreConfig=configs.maps;
    strcpy(language,getLanguageStr(configs.language));
    languageIdx=configs.language;
}

void loadMapSettings(){
    FILE *mapSettingsFP=fopen("mapSettings.bin","rb");
	if(mapSettingsFP==NULL){
        if(DEBUG)printf("Erro ao abrir o arquivo mapSettings.bin\n");
        if(DEBUG)printf("Criando novo arquivo mapSettings.bin...");
        mapType[0].nMapGen=250;
        mapType[0].variationMapGen=60;
        mapType[0].smallVariationMapGen=10;
        mapType[0].mountainVariationMapGen=20;
        mapType[0].mountainVerticalSize=100;
        mapType[0].mountainHorizontalSize=55;
        mapType[0].mountainChance=120;
        saveMapConfig();
        if(DEBUG)printf("OK\n");
        return;
    }
    for(int i=0;i<numMaps;i++){
        fread(&mapType[i],sizeof(MAP_SETTINGS),1,mapSettingsFP);
    }
    nMapGen=mapType[mapPreConfig].nMapGen;
    variationMapGen=mapType[mapPreConfig].variationMapGen;
    smallVariationMapGen=mapType[mapPreConfig].smallVariationMapGen;
    mountainVariationMapGen=mapType[mapPreConfig].mountainVariationMapGen;
    mountainVerticalSize=mapType[mapPreConfig].mountainVerticalSize;
    mountainHorizontalSize=mapType[mapPreConfig].mountainHorizontalSize;
    mountainChance=mapType[mapPreConfig].mountainChance;
	fclose(mapSettingsFP);
}

void editMapSettings(int posMap)
{
    mapType[posMap].nMapGen=nMapGen;
    mapType[posMap].variationMapGen=variationMapGen;
    mapType[posMap].smallVariationMapGen=smallVariationMapGen;
    mapType[posMap].mountainVariationMapGen=mountainVariationMapGen;
    mapType[posMap].mountainVerticalSize=mountainVerticalSize;
    mapType[posMap].mountainHorizontalSize=mountainHorizontalSize;
    mapType[posMap].mountainChance=mountainChance;
    saveMapConfig();
}
