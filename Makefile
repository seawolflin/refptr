
SRC :=  refptr_test.c \
		  refptr.c

OBJS := $(SRC:.c=.o)

CC = gcc

INCLUDE = -I.

CFLAGS := -g -Os

all: refptr_test
	@echo "Enter regular: all..."


refptr_test: $(OBJS)
	gcc -o $@ $^


%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

.PHONY:all clean print

rwildcard=$(strip $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2)$(filter $(subst *,%,$2),$d)))

clean:
	-rm -rf $(call rwildcard,,*.o) refptr_test

print:
	@echo $(OBJS)

