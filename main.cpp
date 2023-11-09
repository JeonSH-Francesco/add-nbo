#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
#include <stdlib.h>

void read_file(char* filename, uint32_t *result) {
    FILE* file = fopen(filename,"rb");
    if (file == NULL) {
        printf("Failed to open the file: %s\n", filename);
        exit(1);
    }
    fread(result, sizeof(uint32_t), 1, file);
    fclose(file);
    *result = ntohl(*result);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    uint32_t ret1, ret2, result;
    read_file(argv[1], &ret1);
    read_file(argv[2], &ret2);
    
    result = ret1 + ret2;
    
    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", ret1, ret1, ret2, ret2, result, result);
    return 0;
}
