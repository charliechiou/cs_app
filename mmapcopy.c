#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Using %s <File path>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error when opening the file!");
        return 1;
    }

    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1)
    {
        perror("Error when reading file.");
        return 1;
    }

    char *ptr = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    write(1, ptr, file_stat.st_size); // 1 means std output
    if (munmap(ptr, file_stat.st_size) == -1)
    {
        perror("Error delete the memory.");
        return 1;
    }
    return 1;
}