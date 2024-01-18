# Makefile

# Compiler
CC=gcc

# Compiler flags
CFLAGS=-I./include

# Linker flags
LDFLAGS=-L./lib -lglew32 -lglfw3 -lopengl32 -lgdi32 -mwindows

# Source files
SOURCES=main.c shader_reader.c

# Object files
OBJECTS=$(SOURCES:.c=.o)

# Executable name
EXECUTABLE=app

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
