#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    struct stat file;
    int n;

    if (argc != 2)
    {
        printf("Usage: ./stat <filename>\n");
        exit(-1);
    }
    if (stat(argv[1], &file) == -1)
    {
        perror(argv[1]);
        exit(-1);
    }

    printf("User ID : %d\n", file.st_uid);
    printf("GUID : %d\n", file.st_gid);
    printf("Block size : %d\n", file.st_blksize);
    printf("Blocks Allocated : %d\n", file.st_blocks);
    printf("Inode no. : %d\n", file.st_ino);
    printf("Last Accessed : %s", ctime(&file.st_atime));
    printf("Last Modified : %s", ctime(&file.st_mtime));
    printf("File Size : %d Bytes\n", file.st_size);
    printf("No. of Links : %d\n", file.st_nlink);

    return 0;
}