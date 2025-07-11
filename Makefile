# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -g -Iinclude
LDFLAGS =

# Project structure
EXECUTABLE = rps_game
SRCDIR = src
OBJDIR = obj
BINDIR = bin
INCDIR = include

# Define the final target path
TARGET = $(BINDIR)/$(EXECUTABLE)

# Find source and object files
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))


# --- Build Rules ---

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	@echo "Linking..."
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo "Build finished: $(TARGET)"

# Compile .c files into .o files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@


# --- Utility Rules ---

# Clean the project
clean:
	@echo "Cleaning project..."
	rm -rf $(OBJDIR) $(BINDIR)

# Rebuild the project
re: clean all

# Phony targets
.PHONY: all clean re