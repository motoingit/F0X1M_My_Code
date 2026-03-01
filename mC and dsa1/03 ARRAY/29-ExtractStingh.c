#include <stdio.h>
int main(){
    char os[100], s[20];
    int i, j, l1, l2;

    printf("Enter the main String : "); 
    scanf(" %[^\n]s", os); // Space before % to handle newline issue

    printf("Enter the start and end positions : ");
    scanf("%d %d", &l1, &l2); // Pass addresses of l1 and l2

    if (l1 < 1 || l2 < l1) {
        printf("Invalid range!");
        return 1;
    }

    l1 -= 1; // Convert to 0-based index
    l2 -= 1; 

    for (i = l1, j = 0; i <= l2 && os[i] != '\0'; i++, j++)
        s[j] = os[i];

    s[j] = '\0'; // Null-terminate the extracted string

    printf("Your extracted snippet is : [%s]\n", s);

    return 0;
}
