PROG = main.exe
SRC = main.cpp user.cpp
CFLAGS = -g -std=c++17
# CFLAGS = -g0 -O3 -std=c++17
LIBS =  -L/opt/homebrew/Cellar/openssl@3/3.4.0/lib -lssl -lcrypto
CC=g++
all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) -I/opt/homebrew/Cellar/openssl@3/3.4.0/include


clean:
	rm -f $(PROG)

.PHONY: all clean