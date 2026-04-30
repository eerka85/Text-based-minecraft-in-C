#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fptr;
    char filejmeno[] = "fajl";
    strcat(filejmeno, ".txt");
    fptr = fopen(filejmeno,"w");
    return 0;
} 