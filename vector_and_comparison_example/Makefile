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

include $(TDIR)/$(SRCS:.c=.d)

$(TDIR)/%.t.o: $(TDIR)/%.t.c $(TDIR)/%.t.h
	$(COMP) -o $@ $< $(CARG)

$(TDIR)/%t.c:
	echo $@ | sed -r "s,^$(TDIR)/([^\.]*)\.(.*)(t\.c)$$,cp \1\.\3 $@\n,g" > $@.cmds
	echo $@ | sed -r "s,^$(TDIR)/([^\.]*)\.(.*)(t\.c)$$,\2,g" |\
	sed -r "s,([^%\.]*)%([^%\.]*)\.,sed -i.junk -r s/\1/\2/g $@ \n,g" >> $@.cmds
	cat $@.cmds | while read line; do $$line; done
$(TDIR)/%t.h:
	echo $@ | sed -r "s,^$(TDIR)/([^\.]*)\.(.*)(t\.h)$$,cp \1\.\3 $@\n,g" > $@.cmds
	echo $@ | sed -r "s,^$(TDIR)/([^\.]*)\.(.*)(t\.h)$$,\2,g" |\
	sed -r "s,([^%\.]*)%([^%\.]*)\.,sed -i.junk -r s/\1/\2/g $@ \n,g" >> $@.cmds
	cat $@.cmds | while read line; do $$line; done

$(TDIR)/%.d: %.c
	$(COMP) -MM -MG $(CARG) $< > $@
	sed -i.junk -e 's/\.t\.[hc]/\.t\.o/g' $@
