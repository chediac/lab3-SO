#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t processo;

    processo = fork();

    if (processo < 0) {
        printf("Erro ao criar processo filho!\n");
        return 1;
    } else if (processo == 0) {
        printf("Este é o processo filho. PID do filho: %d\n", getpid());
        fflush(stdout);

        for (int i = 0; i < 5; i++) {
            printf("Filho: Mensagem %d\n", i + 1);
            fflush(stdout);
            sleep(1);
        }
    } else {
        printf("Este é o processo pai. PID do pai: %d, PID do filho: %d\n", getpid(), processo);
        fflush(stdout);

        wait(NULL);
        printf("O processo filho terminou.\n");
    }

    return 0;
}
