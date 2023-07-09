#ifndef CONFIG_HEADER
#define CONFIG_HEADER

#define RETRO_END
/*
#define LOW_END
#define MEDIUM_END
#define HIGH_END
*/

#ifdef RETRO_END
  #define MAX_OBJECTS 32
  #define MAX_NODE3_SIZE 64
#elif LOW_END
  #define MAX_OBJECTS 128
  #define MAX_NODE3_SIZE 256
#elif MEDIUM_END
  #define MAX_OBJECTS 256
  #define MAX_NODE3_SIZE 512
#elif HIGH_END
  #define MAX_OBJECTS 512
  #define MAX_NODE3_SIZE 4096
#else
  #define MAX_OBJECTS 1024
  #define MAX_NODE3_SIZE 8192
#endif
#define MAX_NODE2_SIZE 6

#endif

