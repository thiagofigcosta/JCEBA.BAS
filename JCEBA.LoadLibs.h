#define useSoil 0
#define useAlut 0

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <cstdio>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <AL/al.h>
#include <AL/alc.h>
#if useSoil
  #include <SOIL.h>
#else
  #include "Libs/soil/SOIL.h"
#endif
//--------------------------------------
#include "Libs/JCEBA.Globals.h"
#include "Libs/JCEBA.Util.h"
#include "Libs/JCEBA.GL.h"
#if useAlut
  #include <AL/alut.h>
  #include "Libs/JCEBA.AL.h"
#else
  #include "Libs/JCEBA.AL2.h"
#endif
#include "Libs/JCEBA.Strings.h"
#include "Libs/JCEBA.LoadFiles.h"
#include "Libs/JCEBA.Lists.h"
#include "Libs/JCEBA.Options.h"
#include "Libs/JCEBA.Buttons.h"
#include "Libs/JCEBA.PlayerBehaviour.h"
#include "Libs/JCEBA.BulletBehaviour.h"
#include "Libs/JCEBA.Mechanics.h"
#include "Libs/JCEBA.Scenes.h"
#include "Libs/JCEBA.IO.h"
#include "Libs/JCEBA.AI.h"
#include "Libs/JCEBA.Settings.h"
