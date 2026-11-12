#include <stdio.h>
#include <string.h>

void parse(const char *data, size_t len) {
    char buf[64];
    memcpy(buf, data, len);
    printf("parsed %zu bytes, first byte=%d\n", len, buf[0]);
}

int main(int argc, char **argv) {
    if (argc < 2) { fprintf(stderr, "usage: %s <file>\n", argv[0]); return 1; }
    FILE *f = fopen(argv[1], "rb");
    if (!f) return 1;
    char data[4096];
    size_t n = fread(data, 1, sizeof(data), f);
    fclose(f);
    parse(data, n);
    return 0;
}
