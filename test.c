#include <stdio.h>

void de(char* p){
//    unlink(p);
}

int main(int argc, char *argv[])
{
  char buf[128];
  if (argc != 2)
    {
      fprintf(stderr, "target1: argc != 2\n");
//      exit(EXIT_FAILURE);
    }
  de(argv[1]);
//  exit(1);
  return 0;
}
