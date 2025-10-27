CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES= main.c vectorMath.c user.c controller.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=Lab7

all: $(SOURCES) $(EXECUTABLE)

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $< > $*.d

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *.d