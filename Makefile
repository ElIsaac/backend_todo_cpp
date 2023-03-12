CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=-pthread -lcpprest -lboost_system -lssl -lcrypto
SOURCES=main.cpp RouteHandler.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=server

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)