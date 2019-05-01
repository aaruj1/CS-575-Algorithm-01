# The c++ compiler
CPP = g++
CFLAGS = -std=gnu++11

# The filename
FILENAME = submission

# The build target executable:
BINARY = submission

all: $(BINARY)

$(BINARY): $(BINARY).cpp
	$(CPP)  $(CFLAGS) -o $(BINARY) $(FILENAME).cpp

clean: 
	rm -f $(BINARY)
