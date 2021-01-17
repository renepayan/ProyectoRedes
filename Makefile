PROYECTO=proyecto_redes
DESTDIR=/usr/local/bin
CFLAGS=-Wall -lpthread -lpcap -std=c++14
LDFLAGS=-lm -lpcap
CC=g++
SRCS=$(wildcard *.cpp)
all: $(PROYECTO)
%.o:%.c
	$(CC) -c $< $(CFLAGS)
$(PROYECTO): $(SRCS:.cpp=.o)
	$(CC) $^ -o $@ $(LDFLAGS)
clean:
	rm -rf *.a
	rm -rf $(PROYECTO)
	rm -rf *.o
.PHONY: clean

install: all
	if [ ! -d $(DESTDIR) ]; then \
		sudo mkdir -p $(DESTDIR); \
	fi; \
	sudo cp $(PROYECTO) $(DESTDIR)
uninstall:
	sudo rm -rf $(DESTDIR)/$(PROYECTO)
zip:
	zip $(PROYECTO).zip *.hpp *.cpp Makefile