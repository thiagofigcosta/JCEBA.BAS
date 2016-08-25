#include <AL/al.h>
#include <AL/alut.h>

#define NUM_BUFFERS 1 //quantidade de sons
#define NUM_SOURCES 1 //quantidade de sons
#define NUM_ENVIROMENTS 1

ALfloat listenerPos[]={0,0,4};//ou 0,0,0
ALfloat listenerVel[]={0,0,0};
ALfloat listenerOri[]={0,0,1,0,1,0};//ou 0,0,-1,0,1,0

ALuint ALbuffer[NUM_BUFFERS];
ALuint ALsource[NUM_SOURCES];
ALuint ALenviroment[NUM_ENVIROMENTS];
ALboolean al_bool;

ALsizei ALsize,ALfreq;
ALenum ALformat;
ALvoid *ALdata;

int currentFileLoading=0;

/*
LEGENDA:
0-background
*/

void ALinit(){
//definindo confiuracoes do openAL
	alListenerfv(AL_POSITION,listenerPos);
	alListenerfv(AL_VELOCITY,listenerVel);
	alListenerfv(AL_ORIENTATION,listenerOri);

	alGetError();
	if(alGetError()!=AL_NO_ERROR) exit(0);//error
}

void loadSound(char* path,ALboolean loop){//AL_TRUE AL_FALSE
	//abrir arquivos
	alGenBuffers(NUM_BUFFERS, ALbuffer);
	#ifdef WIN32 //talvez funcione para o linux tbm
		alutLoadWAVFile(path,&ALformat,&ALdata,&ALsize,&ALfreq,&al_bool);
	#elif  __linux
		alutLoadWAVFile((ALbyte*)path,&ALformat,&ALdata,&ALsize,&ALfreq,&al_bool);
	#endif
		alBufferData(ALbuffer[currentFileLoading],ALformat,ALdata,ALsize,ALfreq);//necessario?
		alutUnloadWAV(ALformat,ALdata,ALsize,ALfreq);//nnecessario?

	alGetError();
	alGenSources(NUM_SOURCES,ALsource);
	if(alGetError()!=AL_NO_ERROR) exit(0); //erro


//definindo configuracoes de cada arquivo de audio
	alSourcef(ALsource[currentFileLoading],AL_PITCH,1.0f);
	alSourcef(ALsource[currentFileLoading],AL_GAIN,1.0f); //volume
	alSourcef(ALsource[currentFileLoading],AL_POSITION,listenerPos[0]);//?? ou listenerPos
	alSourcef(ALsource[currentFileLoading],AL_VELOCITY,listenerVel[0]);//?? ou listenerVel
	alSourcef(ALsource[currentFileLoading],AL_BUFFER,ALbuffer[currentFileLoading]);//relacionado com o loop??
	alSourcef(ALsource[currentFileLoading],AL_LOOPING,loop);//se o som vai tocar sem parar ou nem
	if(currentFileLoading<NUM_SOURCES-1)
		currentFileLoading++;
}
