#include <stdio.h>
#include <string.h>
#include "mm.h"
#include "memlib.h"

void test_coalesce()
{
    printf("--- Test coalesce ---\n");
    printf("--- Before free ---\n");
    void *p1 = mm_malloc(100);
    void *p2 = mm_malloc(100);
    void *p3 = mm_malloc(100);
    mm_checkheap(1);

    mm_free(p2);
    mm_free(p1);

    printf("--- After free ---\n");
    mm_checkheap(1);
    mm_free(p3);
}

void test_malloc_and_free()
{
    char *p1 = (char *)mm_malloc(100);
    if (p1)
    {
        strcpy(p1, "Hello Malloc!");
        printf("P1 Address: %p, Content: %s\n", p1, p1);
    }

    void *p2 = mm_malloc(500);
    printf("P2 Address: %p\n", p2);

    mm_checkheap(1);

    mm_free(p1);
    printf("P1 released\n");

    mm_checkheap(1);
}

int main()
{
    mem_init();

    if (mm_init() < 0)
    {
        printf("Error when init！\n");
        return 1;
    }

    printf("=== Start testing ===\n");

    test_coalesce();

    printf("\n\n");

    test_malloc_and_free();

    mem_deinit();
    printf("=== End of test ===\n");
    return 0;
}