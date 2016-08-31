//Inicializacao
#define worldWidth 800
#define worldHeight 600
#define PlayerSIZEX 60
#define PlayerSIZEY 100
#define PlayerHEIGHTSHOT 100
#define PlayerHEIGHTSPAWN 100
#define offSetPlayerCollision 20
#define BulletSIZEX 45.1
#define BulletSIZEY 20
#define CHANGES 10
#define STEPCOLORSIZE 1
#define NUM_BUFFERS 23 //quantidade de sons
#define NUM_SOURCES 23 //quantidade de sons
#define windForce 20
#define moveVelocity 160
#define jumpVelocity 120
#define jumDuration 80
#define animationSpeed 6
#define MINstrengh 150
#define MAXstrengh 300
#define timeToDestroyBullet 0
#define MAXdestructionHeight 199
#define bananaSpinSpeed 0.15
#define ainRadius 10000
#define loadFromFiles 1
#define canAimDown 1
#define permitEqualCountrys 1//permite dois jogares iguais no modo 2 jogadores
#define numMaps 5 //numero de mapas customizaveis
char elementalPath[]="";//"resources/"
bool bugMODE=false;
bool useStencil=true;
bool cheatMode=false;
bool DEBUG=true;
//arquivo de configs
char language[25]="english";
float gravity=-100.8;
int mapPreConfig=0;
bool soundState=1,musicState=1;
int initPlayerLifes=3;
int initPlayerBombs=1;
int wind=1;
bool windState=1;
int difficulty=1,idxMap=1;;
float damageRocket=2;
float damageAtomic=9;
//geracao de mapa
int nMapGen=250;
int variationMapGen=60;
int smallVariationMapGen=10;
int mountainVariationMapGen=20;
int mountainVerticalSize=100;
int mountainHorizontalSize=55;
int mountainChance=120;
float averageGroundSpawn=worldHeight/3-worldHeight/2;

//NEVER CHANGES
#define PI 3.14159265
#define SPLASH -111
#define MENU -112
#define JOGO -113
#define OPCOES -114
#define INSTRUCOES -115
#define CREDITOS -116
#define PREMENU -117
#define NUM_JOGADORES -118
#define ESC_PERSONAGEM -119
#define PRE_PARTIDA -120
#define SAIR -121
#define EDICAO_MAPA -7
#define BRASIL 7  //7 a 1
#define ISLAMIC 11 //11 de setembro
#define KOREA 24  //kim gayzao
#define RUSSIA 51 //garotinha vodka mode
#define USA 666 //lulu <3
#define arcoIrisChance 10
int currentScreen=SPLASH;
float FPS=40;
int gameFPS=60;
bool mouseClicked=0;
void AIturn();
float getAngle(int isRAD);
void saveMapConfig();
void saveSettings();
void createList();
int languageIdx=0;
float angle,strengh;
ALuint ALsource[NUM_SOURCES];
bool MOUSE2=0;
bool fullscreen=false;
bool canGG=0;
int pause=1;
bool alreadyAI=false;
int playerTurn=1;
float disFromP1=rand()%200;
//tipos
typedef struct mapSettings {
                            int nMapGen=250;
                            int variationMapGen=60;
                            int smallVariationMapGen=10;
                            int mountainVariationMapGen=20;
                            int mountainVerticalSize=100;
                            int mountainHorizontalSize=55;
                            int mountainChance=120;
} MAP_SETTINGS;

MAP_SETTINGS mapType[numMaps];
typedef struct settings {
    bool music=1,sound=1, windState=1;
    int difficulty=1,lives=3,specialAmmo=2,language=0,maps=0,resolutionIdx=0,gameFPS=60;
} SETTINGS;
