GPP=g++
FLAGS=-I ./src/header -std=c++20
OBJDIR=obj
BIN=bin/main
SRCDIR=src

SRCS=$(SRCDIR)/main.cpp $(SRCDIR)/query.cpp $(SRCDIR)/data.cpp
OBJS=$(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(BIN)

# Création du binaire
$(BIN): $(OBJS)
	@mkdir -p $(dir $@)
	$(GPP) $(OBJS) -o $@

# Compilation des fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(GPP) $(FLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(OBJDIR)/* $(BIN)
