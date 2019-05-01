#include <iostream>
#include <unordered_set>

using namespace std;

FILE *srcFP, *destFP;

long long numLines, *data;

//returns file size as number of lines in the file
long long findNumLines(FILE *fp) {

    long long numLines = 0;
    char str[100];

    while (!feof(fp)) {
        fgets(str, 100, fp);
        numLines++;
    }
    numLines--;
    if (fseek(fp, 0L, SEEK_SET) == EOF) {
        perror("Error while seeking to beginning of file");
        exit(0);
    }
    return numLines;
}

int main(int argc, char *argv[]) {
    char str[100];
    int i, j;
    long long *list;

    unordered_set<int> hashTable;

    if (argc != 3) {
        printf("Please provide the input and output file name.");
        exit(0);
    }

    if ((srcFP = fopen(argv[1], "r")) == NULL) {
        perror("Error while opening input file");
        exit(1);
    }

    numLines = findNumLines(srcFP);

    printf("Number of lines in the input file : %lld \n", numLines);

    data = (long long *) malloc(numLines * sizeof(long long));

    for (int i = 0; i < numLines; i++) {
        fgets(str, 100, srcFP);
        sscanf(str, "%lld", &(data[i]));
    }

    list = data;

    if ((destFP = fopen(argv[2], "w")) == NULL) {
        perror("Error while opening output file");
        exit(1);
    }

    for (i = 0; i < numLines; i++) {
        hashTable.insert(list[i]);
    }

    for (i = 0; i < numLines; i++) {
        for (j = i + 1; j < numLines; j++) {
            if ((hashTable.find(abs(list[i] - list[j])) != hashTable.end()) && (abs(list[i] - list[j]) != list[i]) &&
                (abs(list[i] - list[j]) != list[j]) && (i != j)) {
                printf("%lld %lld %lld \n", abs(list[i] - list[j]), list[i], list[j]);
                fprintf(destFP, "%lld, %lld, %lld \n", abs(list[i] - list[j]), list[i], list[j]);
            }
        }
    }
    fclose(srcFP);
    fclose(destFP);
    return 0;
}
