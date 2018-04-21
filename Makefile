CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		sand_box.o

LIBS =

TARGET =	sand_box.elf

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
