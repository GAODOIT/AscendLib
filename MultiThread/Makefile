CC = gcc
LIBRARY += -lpthread
SRC = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRC))

TARGET=main_out
all: clean $(TARGET)
	@echo Generation TARGET
$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(CFLAGS) $(LIBRARY)
.PHONY : clean
clean :
	@rm -f $(TARGET)
