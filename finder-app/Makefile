C := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Wextra -Werror
TARGET := writer
SRC := writer.c

all: $(TARGET)

$(TARGET): $(SRC)
	    $(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	    rm -f $(TARGET)

.PHONY: all clean
