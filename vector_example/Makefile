COMP = gcc
CARG = -c -Wall -Werror -Wextra -ansi -pedantic -std=c11 -g -Og
LARG =
PROD = example
SRCS = main.c
TDIR = templates

.PHONY: all clean

#.SECONDARY: #uncomment this to prevent make from removing the source code of the instantiated templates

all: $(PROD)

$(PROD): $(SRCS:.c=.o)
	$(COMP) -o $@ $^ $(TDIR)/*.o $(LARG)

%.o: %.c
	$(COMP) -o $@ $< $(CARG)

%.o: %.c %.h
	$(COMP) -o $@ $< $(CARG)

clean:
	-rm $(PROD) $(SRCS:.c=.o) $(TDIR)/*

.PRECIOUS: $(TDIR)/*

include $(TDIR)/$(SRCS:.c=.d)

$(TDIR)/%.t.o: $(TDIR)/%.t.c $(TDIR)/%.t.h
	$(COMP) -o $@ $< $(CARG)

$(TDIR)/vector.%.t.h: vector.TYPE.h
	sed -e 's/TYPE/$*/g' $^ > $@

$(TDIR)/vector.%.t.c: vector.TYPE.c
	sed -e 's/TYPE/$*/g' $< > $@

$(TDIR)/%.d: %.c
	$(COMP) -MM -MG $(CARG) $< > $@
	sed -i.junk -e 's/\.t\.[hc]/\.t\.o/g' $@
