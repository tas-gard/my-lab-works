CC = gcc
CFLAGS  = -std=c99 -Wall -Wextra -Iinclude

BUILD_DIR = build
TARGET = $(BUILD_DIR)/prog

SRCS = src/main.c src/set.c
OBJS = $(SRCS:src/%.c=$(BUILD_DIR)/%.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
