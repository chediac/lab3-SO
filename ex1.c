#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t proc;

    proc = fork();

    if (proc < 0) {
        printf("Erro ao criar processo filho!\n");
        return 1;
    } else if (proc == 0) {
        printf("Este é o processo filho. PID do filho: %d\n", getpid());

        for (int contador = 0; contador < 5; contador++) {
            printf("Filho: Mensagem %d\n", contador+1);
            sleep(1);
        }
    } else {
        printf("Este é o processo pai. PID do pai: %d, PID do filho: %d\n", getpid(), proc);
    }

    return 0;
}
