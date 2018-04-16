CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Card.cpp Node.h LinkedList.h DeckofCards.cpp HandOfCards.cpp Blackjack.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Blackjack

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
