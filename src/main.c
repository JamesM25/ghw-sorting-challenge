#include <stdio.h>

#define CSV_PATH "../hackathons.csv"

int main(int argc, char **argv) {
    
    FILE *fp = fopen(CSV_PATH, "r");
    if (fp == NULL) {
        printf("Unable to open file %s\n", CSV_PATH);
        return 1;
    }


    char line[1000];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    fclose(fp);
    

    return 0;
}