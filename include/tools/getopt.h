#ifndef TOOLS_GETOPT_HEADER_FILE
#define TOOLS_GETOPT_HEADER_FILE

enum Flags
{
  FULLSCREEN  = 0
};

int getopt(char *opt, char *shortFlag, char *longFlag);

#endif
