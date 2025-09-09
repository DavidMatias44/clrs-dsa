CXX=g++
CXXFLAGS=-c -g -std=c++17
OBJDIR=build
SRCDIR=src

OBJS=$(OBJDIR)/main.o $(OBJDIR)/sorting.o $(OBJDIR)/heap.o
OUTPUT=output

$(OUTPUT): $(OBJS)
	$(CXX) $(OBJS) -o $(OUTPUT)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/sorting.o: $(SRCDIR)/sorting.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/sorting.cpp -o $(OBJDIR)/sorting.o

$(OBJDIR)/heap.o: $(SRCDIR)/heap.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/heap.cpp -o $(OBJDIR)/heap.o

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJDIR)/*.o $(OUTPUT)