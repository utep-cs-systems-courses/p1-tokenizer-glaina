OBJS= tokenizer.o history.o uimain.o

CFLAGS=-g -03

all: tokenizer

$(OBJS): tokenizer.h history.h

tokenizer: $(OBJS)
	cc -o $@ $^ $(CFLAGS) $(OBJS)

clean:
	rm -f *.0 tokenizer

run: tokenizer
	./tokenizer
