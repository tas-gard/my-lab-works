CC = gcc
CFLAGS  = -std=c99 -Wall -Wextra -Iinclude

BUILD_DIR = build
TARGET = $(BUILD_DIR)/prog

SRCS = src/main.c src/operations.c
OBJS = $(SRCS:src/%.c=$(BUILD_DIR)/%.o)

.PHONY: all clean

# по умолчанию
all: $(TARGET)

# линковка: из объектников делаем итоговый бинарник
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# общее правило: src/foo.c -> build/foo.o
$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# создать build, если его ещё нет
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# уборка
clean:
	rm -rf $(BUILD_DIR)
