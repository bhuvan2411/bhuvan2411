CC = gcc
CFLAGS = -Iinclude -I./src/utils -Wall -Wextra -g
SRC = src/main.c src/xml_parser.c src/table_manager.c src/referential_integrity.c src/utils/memory.c src/utils/string_utils.c
OBJ = $(SRC:.c=.o)
TARGET = xml_relational_c

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean