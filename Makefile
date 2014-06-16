
TMPDIR=.tmp
SOURCES:=$(shell ls -1 *.c )
HEADERS:=$(shell ls -1 include/*.h )
OBJS:=$(SOURCES:%.c=$(TMPDIR)/%.o)
PROG=ooc
CFLAGS?=-I include 

all: $(PROG)

debug: 
	@make -S CFLAGS="$(CFLAGS) -ggdb3 -O0"

release: all

docs: Doxyfile $(SOURCES) $(HEADERS)
	@echo -ne "\t[DOXYGEN]\n"
	@doxygen

$(PROG).log: $(PROG)
	@echo -ne "\t[OUT]\t$<\n"
	@script -c ./$(PROG) $@ >/dev/null

$(PROG): $(OBJS) 
	@echo -ne "\t[CC]\t$(PROG)\n"
	@cc $(CFLAGS) -o $@ $(OBJS) || exit 1

clean:
	@-rm -rf $(TMPDIR) $(PROG) $(PROG).log docs 2>/dev/null

$(TMPDIR)/%.o: %.c
	@-mkdir -p $(TMPDIR)
	@echo -ne "\t[CC]\t$$( basename $(@:.o=) )\n"
	@cc $(CFLAGS) -MT $@ -MM -MF $(@:.o=.dep) $< || exit 1
	@cc $(CFLAGS) -c -o $@ $< || exit 1

-include $(OBJS:.o=.dep)
