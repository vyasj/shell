#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {

  char *buffer;
  size_t bufsize = 8;

  while (1) {
    printf("$ ");
    getline(&buffer, &bufsize, stdin);

    char *tok = strtok(buffer, " ");
    if (strcmp(tok, "exit\n") == 0) {
      break;
    }
    char *cmd[8];
    int cmd_idx = 0;
    while (tok != NULL) {
      cmd[cmd_idx] = tok;
      tok = strtok(NULL, " ");
      cmd_idx++;
    }

    pid_t pid = fork();
    if (pid == 0) {
      execve(cmd[0], cmd, NULL);
    }
  }

  return 0;
}
