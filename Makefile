CXX=g++
CXXFLAGS=-c -g -std=c++17
OBJDIR=build
SRCDIR=src

OBJS=$(OBJDIR)/main.o $(OBJDIR)/sorting.o $(OBJDIR)/heap.o $(OBJDIR)/priorityQueue.o $(OBJDIR)/algorithms.o $(OBJDIR)/stack.o $(OBJDIR)/queue.o $(OBJDIR)/linkedList.o
OUTPUT=output

$(OUTPUT): $(OBJS)
	$(CXX) $(OBJS) -o $(OUTPUT)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/sorting.o: $(SRCDIR)/sorting.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/sorting.cpp -o $(OBJDIR)/sorting.o

$(OBJDIR)/heap.o: $(SRCDIR)/heap.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/heap.cpp -o $(OBJDIR)/heap.o

$(OBJDIR)/priorityQueue.o: $(SRCDIR)/priorityQueue.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/priorityQueue.cpp -o $(OBJDIR)/priorityQueue.o

$(OBJDIR)/algorithms.o: $(SRCDIR)/algorithms.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/algorithms.cpp -o $(OBJDIR)/algorithms.o

$(OBJDIR)/stack.o: $(SRCDIR)/stack.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/stack.cpp -o $(OBJDIR)/stack.o

$(OBJDIR)/queue.o: $(SRCDIR)/queue.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/queue.cpp -o $(OBJDIR)/queue.o

$(OBJDIR)/linkedList.o: $(SRCDIR)/linkedList.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/linkedList.cpp -o $(OBJDIR)/linkedList.o

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJDIR)/*.o $(OUTPUT)