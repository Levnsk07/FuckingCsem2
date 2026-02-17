#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getCommandID(char *com) {
    // printf("GETID FROM: %s\n",com);
    char *commands[] = {"add", "sub", "mul"};
    for (int i = 0; i < 3; i++) {
        if (strcmp(com, commands[i]) == 0) {
            // printf("Got command ID: %s as %d\n",com,i);
            return i;
        }
    }
    return -1;
}

int main(int arg, char *argv[]) {
    if (arg == 1) {
        fprintf(stderr,"No parameters specified.");
        return 13;
    }

    int mod = 0;

    char **oneCom = argv;
    oneCom++;

    if (arg == 6) {
        // printf("%s \n", argv[1]);
        if (strcmp(*oneCom, "-m") == 0) {
            mod = atoi(argv[2]);
            // printf("MOD: %d\t %s %d\n",mod,*oneCom,strcmp(*oneCom, "-m"));
            oneCom += 2;
        } else {
            mod = atoi(argv[5]);
        }
    }

    // getCommandID(*oneCom++);
    // int ID = getCommandID(*oneCom++);

    long long int res =0;
   long long int a, b;
    switch (getCommandID(*oneCom++)) {
        // switch (ID) {
        case 0:
            a = atoi(*oneCom++);
            b = atoi(*oneCom);
            res = a + b;
            break;
        case 1:
            a = atoi(*oneCom++);
            b = atoi(*oneCom);
            res = a - b;
            break;
        case 2:
            a = atoi(*oneCom++);
            b = atoi(*oneCom);
            res = a * b;

            break;
    }
    if (mod != 0) {
        res = res % mod;
        if (res<0) {
            res += mod;
        }
        printf("%lld\n",res);

    }else {
        printf("%lld\n",res);
    }
    // printf("%lld %lld\n",a,b);


    return 0;
}
