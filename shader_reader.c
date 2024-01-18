#include "shader_reader.h"
#include <stdio.h>
#include <stdlib.h>

char* read_shader_source(const char* shader_file) {
    FILE* file = fopen(shader_file, "r");
    if(file == NULL) {
        fprintf(stderr, "Could not open shader file %s\n", shader_file);
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* buffer = (char*)malloc(length + 1);
    if(buffer == NULL) {
        fprintf(stderr, "Could not allocate memory for shader source\n");
        fclose(file);
        return NULL;
    }
    fread(buffer, 1, length, file);
    buffer[length] = '\0';
    fclose(file);
    return buffer;
}
