CXX=g++
CXXFLAGS=-std=c++17 -Werror -Wall -Wextra

BINDIR=bin
SRCDIR=src
DEMODIR=demos
TESTDIR=tests
TESTFLAGS=-lCatch2Main -lCatch2

run-demo: | $(BINDIR)
ifeq ($(strip $(DEMO)),)
	$(error DEMO not specified. Usage: make run-demo DEMO=demoFile)
endif
	$(CXX) $(CXXFLAGS) $(SRCDIR)/$(DEMODIR)/$(DEMO).cpp -o $(BINDIR)/$(DEMO)
	./$(BINDIR)/$(DEMO)

run-tests:
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/tests $(SRCDIR)/$(TESTDIR)/*.cpp $(TESTFLAGS)
	./$(BINDIR)/tests --success

$(BINDIR):
	@mkdir -p $(BINDIR)

clean:
	rm -rf $(BINDIR)
