CC          = g++
MAKE        = make
SHELL       = /bin/sh

FOLDERS =

LIBS = -lglfw -lGL -lopencv_core -lopencv_highgui
EXECS = test
SOURCES = test.cpp
HEADERS = VideoRecorder.hpp
OBJECTS = $(SOURCES:.cpp=.o)

$(EXECS): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LIBS)

.cpp.o: $(HEADERS)
	$(CC) -c $(SOURCES) $(LIBS) 

clean:
	/bin/rm -f *.o *.mod $(EXECS) *.gnu *.sh *.gif

run: $(EXECS)
	./$(EXECS)
	
