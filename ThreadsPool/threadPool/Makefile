CC = g++
LIBRARY += -lpthread
SRC = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRC))

TARGET=main_pool
all: clean $(TARGET)
	@echo Generation TARGET
$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(CFLAGS) $(LIBRARY)
.PHONY : clean
clean :
	@rm -f $(TARGET)
