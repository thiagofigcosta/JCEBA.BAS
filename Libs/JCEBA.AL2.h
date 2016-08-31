ALfloat ListenerPos[] = { 0.0, 0.0, 0.0 };                                  //Position of the listener
ALfloat ListenerVel[] = { 0.0, 0.0, 0.0 };                                  //Velocity of the listener
ALfloat ListenerOri[] = { 0.0, 0.0, -1.0,  0.0, 1.0, 0.0 };
ALfloat SourcePos[] = { 0.0, 0.0, 0.0 };                                    //Position of the source sound
ALfloat SourceVel[] = { 0.0, 0.0, 0.0 };

ALuint ALbuffer[NUM_BUFFERS];

int currentFileLoading=0;

//alSourcePlay(source[0]); TOCA MSUICA
//alSourcePause(source[0]); pausa MSUICA
//alSourceStop(source[0]); para MSUICA

void ALinit(){
    ALCdevice *device;                                                          //Create an OpenAL Device
    ALCcontext *context;                                                        //And an OpenAL Context
    device = alcOpenDevice(NULL);                                               //Open the device
    context = alcCreateContext(device, NULL);                                   //Give the device a context
    alcMakeContextCurrent(context);                                             //Make the context the current                     //Error during context handeling

    alListenerfv(AL_POSITION,    ListenerPos);                                  //Set position of the listener
    alListenerfv(AL_VELOCITY,    ListenerVel);                                  //Set velocity of the listener
    alListenerfv(AL_ORIENTATION, ListenerOri);
}

bool loadSound(char* path,float vol,ALboolean loop){//AL_TRUE AL_FALSE
	FILE *fp = NULL;
    fp=fopen(newPath(path),"rb");
    if (!fp) return 0;

    char type[4];
    unsigned int size,chunkSize;
    short formatType,channels;
    unsigned int sampleRate,avgBytesPerSec;
    short bytesPerSample,bitsPerSample;
    unsigned int dataSize;

    fread(type,sizeof(char),4,fp);
    if(type[0]!='R' || type[1]!='I' || type[2]!='F' || type[3]!='F'){
        if(DEBUG)printf("Error loading sound %d, err:1\n",currentFileLoading);
    }
    //return 0;

    fread(&size, sizeof(unsigned int),1,fp);
    fread(type, sizeof(char),4,fp);
    if (type[0]!='W' || type[1]!='A' || type[2]!='V' || type[3]!='E'){
        if(DEBUG)printf("Error loading sound %d, err:2\n",currentFileLoading);
    }
    //return 0;

    fread(type,sizeof(char),4,fp);
    if (type[0]!='f' || type[1]!='m' || type[2]!='t' || type[3]!=' '){
        if(DEBUG)printf("Error loading sound %d, err:3\n",currentFileLoading);
    }
    //return 0;

    fread(&chunkSize,sizeof(unsigned int),1,fp);
    fread(&formatType,sizeof(short),1,fp);
    fread(&channels,sizeof(short),1,fp);
    fread(&sampleRate,sizeof(unsigned int),1,fp);
    fread(&avgBytesPerSec,sizeof(unsigned int),1,fp);
    fread(&bytesPerSample,sizeof(short),1,fp);
    fread(&bitsPerSample,sizeof(short),1,fp);

    fread(type,sizeof(char),4,fp);
    if (type[0]!='d' || type[1]!='a' || type[2]!='t' || type[3]!='a'){
        if(DEBUG)printf("Error loading sound %d, err:4\n",currentFileLoading);
    }
    //return 0;

    fread(&dataSize,sizeof(unsigned int),1,fp);

    unsigned char* buf= new unsigned char[dataSize];
    fread(buf,sizeof(unsigned char),dataSize,fp);

    ALuint frequency=sampleRate;
    ALenum format=0;
    alGenBuffers(1, &ALbuffer[currentFileLoading]);
    alGenSources(1, &ALsource[currentFileLoading]);
    if(bitsPerSample == 8){
        if(channels == 1)
            format = AL_FORMAT_MONO8;
        else if(channels == 2)
            format = AL_FORMAT_STEREO8;
    }
    else if(bitsPerSample == 16){
        if(channels == 1)
            format = AL_FORMAT_MONO16;
        else if(channels == 2)
            format = AL_FORMAT_STEREO16;
    }

    alBufferData(ALbuffer[currentFileLoading], format, buf, dataSize, frequency);

    alSourcei (ALsource[currentFileLoading], AL_BUFFER,   ALbuffer[currentFileLoading]);
    alSourcef (ALsource[currentFileLoading], AL_PITCH,    1.0f     );
    alSourcef (ALsource[currentFileLoading], AL_GAIN,     vol     );
    alSourcefv(ALsource[currentFileLoading], AL_POSITION, SourcePos);
    alSourcefv(ALsource[currentFileLoading], AL_VELOCITY, SourceVel);
    alSourcei (ALsource[currentFileLoading], AL_LOOPING,  loop );
    fclose(fp);
    delete[] buf;

	if(currentFileLoading<NUM_SOURCES-1)
		currentFileLoading++;
    return 1;
}

void stopAllSounds(int n){
	for(int i=0;i<NUM_SOURCES;i++)
		if(i!=4&&i!=n)//click,
			alSourceStop(ALsource[i]);
}
