COMP = gcc
CARG = -c -Wall -Werror -Wextra -ansi -pedantic -std=c11 -g -Og
LARG =
PROD = example
OBJS = obj/main.o
ODIR = obj

.PHONY: all clean

all: $(PROD)

$(PROD) : $(OBJS)
	$(COMP) -o $@ $(ODIR)/*.o $(LARG)

$(ODIR)/%.o: $(ODIR)/%.c $(ODIR)/%.h
	$(COMP) -o $@ $< $(CARG)
$(ODIR)/%.o: $(ODIR)/%.c
	$(COMP) -o $@ $< $(CARG)

$(ODIR)/%.c: %.i.c
	./scanner.py $<
	cp $< $@
$(ODIR)/%.c: %.i.h
	./scanner.py $<
	cp $< $@

$(ODIR)/vector.%.c: | vector.TYPE.t.c
	./instantiator.py $| $* $@
$(ODIR)/vector.%.h: | vector.TYPE.t.h
	./instantiator.py $| $* $@
clean:
	-rm $(PROD) $(ODIR)/*
