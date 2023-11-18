#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("./this-file <path>");
        return 1;
    }

    const char *pathname = argv[1];
    struct stat stats;

    if (stat(pathname, &stats) == 0) {
        struct tm date;

        printf("Koko: %ld\n", stats.st_size);
        printf("Kaytettyjen lohkojen maara: %ld\n", stats.st_blocks);
        printf("Suositeltu lohkojen koko: %ld\n", stats.st_blksize);
        date = *(gmtime(&stats.st_ctime));
        printf("Luotu: %d-%d-%d %d:%d:%d\n", date.tm_mday, date.tm_mon, date.tm_year + 1900,
					   date.tm_hour, date.tm_min, date.tm_sec);
    }
    else {
        perror("stat");
    }
    return 0;
}
