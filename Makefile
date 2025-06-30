CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Isrc/mcal -Isrc/rte
SRCS = src/mcal/CanDriver.c src/rte/Rte_CanIf.c src/main.c
OBJS = $(SRCS:.c=.o)
TARGET = complex_driver_demo

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(TARGET)
