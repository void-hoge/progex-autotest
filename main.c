#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str);
    size_t len = strlen(str);
    if (str[len - 3] == 's' && str[len - 2] == 'a' && str[len - 1] == 'n') {
        printf("Yes\n");
    }else {
        printf("NO\n");
    }
}
