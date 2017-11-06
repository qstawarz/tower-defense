TARGET  = app

CC       = gpp
CFLAGS   = -I./includes

LINKER   = gpp
LFLAGS   = -I./includes

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(shell find $(SRCDIR) -name '*.cpp')
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
RM       = rm -rf

all: $(BINDIR)/$(TARGET) | $(BINDIR)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -cpp $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(RM) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: fclean
fclean: clean
	@$(RM) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"

re  : fclean all