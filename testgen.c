#include <stdio.h>

#define RELEASE "-O3"

void gen_build_target(const char *target) {
    printf("main: %s\n", target);
    printf("\tgcc %s %s -o main\n", target, RELEASE);
    printf("\n");
}

void gen_test_target(const int testnum, const char **inputs, const char **expects) {
    printf("test: main");
    for (int i = 0; i < testnum; i++) {
        printf(" %s", inputs[i]);
        printf(" %s", expects[i]);
    }
    printf("\n");
    for (int i = 0; i < testnum; i++) {
        printf("\t./main < %s > %s_out; \\\n", inputs[i], inputs[i]);
        printf("\tdiff %s_out %s; \\\n", inputs[i], expects[i]);
    }
    printf("\n");
}

void gen_clean_target(const int testnum, const char **inputs) {
    printf("clean:\n");
    printf("\trm main");
    for (int i = 0; i < testnum; i++) {
        printf(" %s_out", inputs[i]);
    }
    printf(" *~\n\n");
}

int main(const int argc, const char *argv[]) {
    printf("# target filename: %s\n", argv[1]);
    int testnum;
    sscanf(argv[2], "%d", &testnum);
    printf("# number of test cases: %d\n", testnum);
    printf("# input files:");
    for (int i = 0; i < testnum; i++) {
        printf(" %s", argv[i + 3]);
    }
    printf("\n");
    printf("# expected files:");
    for (int i = 0; i < testnum; i++) {
        printf(" %s", argv[i + 3 + testnum]);
    }
    printf("\n");

    const char *target = argv[1];
    const char **inputs = argv + 3;
    const char **expects = argv + 3 + testnum;
    gen_test_target(testnum, inputs, expects);
    gen_build_target(target);
    gen_clean_target(testnum, inputs);
}
