LINK_TARGET = find_url.exe

OBJS =	\
	Utils.o \
	find_url.o

REBUILDABLES = $(OBJS) $(LINK_TARGET)

all: $(LINK_TARGET)
	echo All done

clean:
	rm -f $(REBUILDABLES)
	echo Clean done

$(LINK_TARGET): $(OBJS)
  g++ -g -o $@ $^
find_url.o Utils.o: Utils.h
