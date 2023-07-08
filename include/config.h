#ifndef CONFIG_HEADER
#define CONFIG_HEADER

#define MEDIUM_END
/*
#define RETRO_END
#define LOW_END
#define HIGH_END
*/

#ifdef RETRO_END
  #define MAX_OBJECTS 128
  #define MAX_VERTEX3_SIZE 64
#elif defined LOW_END
  #define MAX_OBJECTS 512
  #define MAX_VERTEX3_SIZE 256
#elif defined MEDIUM_END
  #define MAX_OBJECTS 1024
  #define MAX_VERTEX3_SIZE 512
#elif defined HIGH_END
  #define MAX_OBJECTS 2048
  #define MAX_VERTEX3_SIZE 4096
#else
  #define MAX_OBJECTS 4096
  #define MAX_VERTEX3_SIZE 8192
#endif
#define MAX_VERTEX2_SIZE 6

#endif

