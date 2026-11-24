

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *source, *target;
    char sourceName[100], targetName[100];
    int ch;
    long count = 0;

    printf("Enter the name of the source file: ");
    scanf("%99s", sourceName);

    /* Open source file in read mode */
    source = fopen(sourceName, "r");
    if (source == NULL) {
        printf("Error: cannot open source file '%s'.\n", sourceName);
        exit(EXIT_FAILURE);
    }

    printf("Enter the name of the destination file: ");
    scanf("%99s", targetName);

    /* Open destination file in write mode (created if it does not exist) */
    target = fopen(targetName, "w");
    if (target == NULL) {
        printf("Error: cannot open destination file '%s'.\n", targetName);
        fclose(source);
        exit(EXIT_FAILURE);
    }

    /* Read one character at a time from source and write it to target */
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, target);
        count++;
    }

    printf("File copied successfully (%ld characters copied).\n", count);

    /* Close both files */
    fclose(source);
    fclose(target);

    return 0;
}
