CC=gcc
CFLAGS=-Wall -Wextra -Wfloat-equal -Wpedantic -Wvla -std=c99 -Werror
DEBUG=-g3
SANITIZE= -fsanitize=undefined -fsanitize=address $(DEBUG)
VALGRIND= $(DEBUG)
LDLIBS=$(DEBUG)

SRC_DIR=src

all: test_soll test_soll_s test_soll_v

test_soll: soll.h $(SRC_DIR)/soll_util.h $(SRC_DIR)/soll.c $(SRC_DIR)/test_soll.c
	$(CC) $(CFLAGS) $(DEBUG) $(SRC_DIR)/soll.c $(SRC_DIR)/test_soll.c -o test_soll $(LDLIBS)

test_soll_s: soll.h $(SRC_DIR)/soll_util.h $(SRC_DIR)/soll.c $(SRC_DIR)/test_soll.c
	$(CC) $(CFLAGS) $(SANITIZE) $(SRC_DIR)/soll.c $(SRC_DIR)/test_soll.c -o test_soll_s $(LDLIBS)

test_soll_v: soll.h $(SRC_DIR)/soll_util.h $(SRC_DIR)/soll.c $(SRC_DIR)/test_soll.c
	$(CC) $(CFLAGS) $(VALGRIND) $(SRC_DIR)/soll.c $(SRC_DIR)/test_soll.c -o test_soll_v $(LDLIBS)

clean:
	rm -f test_soll test_soll_s test_soll_v
