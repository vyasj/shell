#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {

  char *buffer;
  size_t bufsize = 8;

  while (1) {
    printf("$ ");
    getline(&buffer, &bufsize, stdin);

    if (strcmp(buffer, "exit\n") == 0) {
      break;
    }
  }

  return 0;
}
