CXX=g++
CXXFLAGS=-Wall -Wextra -Wshadow -std=c++17

VERBOSE=FALSE

ifeq ($(VERBOSE), TRUE)
	HIDE=
else
	HIDE=@
endif

PROJDIR:=$(realpath $(CURDIR))
SRCDIR:=$(PROJDIR)
OBJDIR:=$(PROJDIR)/obj
DEPSDIR:=$(PROJDIR)/deps
BINDIR:=$(PROJDIR)/bin
DATADIR:=$(PROJDIR)/data
DIRS:=$(OBJDIR) $(BINDIR) $(DATADIR) $(DEPSDIR)

SRCS:=$(wildcard $(SRCDIR)/*.cpp)
OBJS:=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))
DEPS:=$(patsubst $(SRCDIR)/%.cpp, $(DEPSDIR)/%.d, $(SRCS))
BIN:=$(BINDIR)/main.out

.PHONY: all clean

all: $(BIN)
	$(HIDE)mkdir -p $(DATADIR)

$(BIN): $(OBJS) $(DEPS) | $(BINDIR)
	$(HIDE)$(CXX) $(CXXFLAGS) $(OBJS) -o $@ 

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPSDIR)/%.d | $(OBJDIR)
	$(HIDE)$(CXX) $(CXXFLAGS) -c -o $@ $<

$(DEPSDIR)/%.d: $(SRCDIR)/%.cpp | $(DEPSDIR)
	$(HIDE)$(CXX) -MM -MG -MF $@ $<

$(DEPSDIR):
	$(HIDE)mkdir -p $@

$(OBJDIR):
	$(HIDE)mkdir -p $@

$(BINDIR):
	$(HIDE)mkdir -p $@

clean:
	$(HIDE)rm -rf $(DIRS)

-include $(DEPS)
