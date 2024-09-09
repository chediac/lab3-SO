#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid_filho;

    pid_filho = fork();

    if (pid_filho < 0) {
        printf("Erro ao criar processo filho!\n");
        return 1;
    } else if (pid_filho == 0) {
        printf("Este é o processo filho. PID do filho: %d\n", getpid());
        fflush(stdout);

        execlp("ls", "ls", "-l", NULL); // Executa o comando 'ls -l'
        printf("Erro ao executar o comando.\n");
        return 1;
    } else {
        printf("Este é o processo pai. PID do pai: %d, PID do filho: %d\n", getpid(), pid_filho);
        fflush(stdout);

        wait(NULL);
        printf("O processo filho terminou.\n");
    }

    return 0;
}
