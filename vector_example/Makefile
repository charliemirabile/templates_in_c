COMP = gcc
CARG = -c -Wall -Werror -Wextra -ansi -pedantic -std=c11 -g -Og
LARG =
PROD = example
SRCS = main.c
ODIR = objs

.PHONY: all clean

all: $(PROD)

$(PROD): $(ODIR)/$(SRCS:.c=.o)
	$(COMP) -o $@ $(ODIR)/*.o $(LARG)

$(ODIR)/%.o: %.c
	$(COMP) -o $@ $< $(CARG)

%(ODIR)/%.o: %.c %.h
	$(COMP) -o $@ $< $(CARG)

clean:
	-rm $(PROD) $(ODIR)/*

include $(ODIR)/$(SRCS:.c=.d)

$(ODIR)/%.d: %.c
	@set -e; rm -f $@; \
         $(COMP) -MM -MG $(CARG) $< > $@.$$$$; \
         sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
         rm -f $@.$$$$

$(ODIR)/vector.%.c $(ODIR)/vector.%.h $(ODIR)/vector.%.o:
	sed -e 's/TYPE/$*/g' vector.TYPE.c > $(ODIR)/vector.$*.c
	sed -e 's/TYPE/$*/g' vector.TYPE.h > $(ODIR)/vector.$*.h
	$(COMP) -o $(ODIR)/vector.$*.o $(ODIR)/vector.$*.c $(CARG)

