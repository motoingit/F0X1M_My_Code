#include <stdio.h>
#include <string.h>

int main() {
    char *s = "string"; //it stores the adresss of the (s) and its just a temp location
                        // and here we cannot reassigned like s[0] = 'X' but we can do like s = "WOwbro".
    printf("%s",*s);
    return 0;
}
