CXX=g++
CXXFLAGS=-c -g -std=c++17
OBJDIR=build
SRCDIR=src

OBJS=$(OBJDIR)/main.o 
OUTPUT=output

$(OUTPUT): $(OBJS)
	$(CXX) $(OBJS) -o $(OUTPUT)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJDIR)/*.o $(OUTPUT)