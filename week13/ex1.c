#include <stdio.h>
#include <string.h>



int main(int argc, char *argv[]) {
    char str[100];
    FILE* input;
    FILE* output;
    int exRes[3];
    int allocationMatrix[5][3];
    int deadlock = 0;
    int finished[5];
    int curSymbol = 0;
    int requestMatrix[5][3];
    int deadlockProcesses[5];
    int canExecute[5];
    int ch = 1;
    int avRes[3];

    input = fopen(argv[1], "r");
    fgets(str, 100, input);
    
    for (size_t i = 0; i < 3; i++) {
        exRes[i] = (int)(str[curSymbol] - '0');
        curSymbol += 2;
    }

    curSymbol = 0;
    fgets(str, 100, input);
    fgets(str, 100, input);    

    fgets(str, 100, input);
    for (size_t i = 0; i < 3; i++) {
        avRes[i] = (int)(str[curSymbol] - '0');
        curSymbol += 2;
    }
    
    curSymbol = 0;
    fgets(str, 100, input);
    fgets(str, 100, input);
    fgets(str, 100, input);
    
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 3; j++) {
            allocationMatrix[i][j] = (int)(str[curSymbol] - '0');
            curSymbol += 2;
        }
        curSymbol = 0;
        fgets(str, 100, input);
    }

    curSymbol = 0;
    fgets(str, 100, input);
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 3; j++) {
            requestMatrix[i][j] = (int)(str[curSymbol] - '0');
            curSymbol += 2;
        }
        curSymbol = 0;
        fgets(str, 100, input);
    }
    fclose(input);

    for (size_t i = 0; i < 5; i++) {
        deadlockProcesses[i] = 0;
        canExecute[i] = 1;
        finished[i] = 0;
    }
    
    while (ch) {
        ch = 0;

        for (size_t i = 0; i < 5; i++) {
            canExecute[i] = 1;
            for (size_t j = 0; j < 3; j++) {
                if (requestMatrix[i][j] > avRes[j]) {
                    canExecute[i] = 0;
                    break;
                }
            }
        }

        for (size_t i = 0; i < 5; i++) {
            if (canExecute[i] && finished[i] == 0) {
                for (size_t j = 0; j < 3; j++) {
                    requestMatrix[i][j] = 0;
                    avRes[j] += allocationMatrix[i][j];
                    allocationMatrix[i][j] = 0;
                    ch = 1;
                    finished[i] = 1;
                }
            }
        }
    }

    for (size_t i = 0; i < 5; i++) {
        if (finished[i] == 0) {
            deadlockProcesses[i] = 1;
            deadlock = 1;
        }
    }
    
    if (deadlock) {
        output = fopen("output_dl.txt", "w+");
        int count=0;
        for (size_t i = 0; i < 5; i++) {
            if (deadlockProcesses[i]) {
                count++;
            }
        }
        fprintf(output, "There are %d deadlocks", count);
    }
    else
    {
        output = fopen("output_ok.txt", "w+");

        fprintf(output, "No deadlocks");
    }

    fclose(output);
    return 0;
}