OBJS = uimain.o tokenizer.o history.o


CFLAGS=-g -O3


all: tokenizer


tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:

	rm -f *.o tokenizer
	rm -f *~ tokenizer

run: tokenizer

	./tokenizer
