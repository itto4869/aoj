CXX ?= g++
STD ?= gnu++17

SRC ?= main.cpp
PROBLEM ?=

ifneq ($(PROBLEM),)
SRC := problems/$(PROBLEM).cpp
endif

NAME := $(basename $(notdir $(SRC)))
BIN := build/$(NAME)
INPUT ?= samples/$(NAME).in
EXPECTED ?= samples/$(NAME).out
SUBMIT ?= submit/$(NAME).cpp

CXXFLAGS ?= -std=$(STD) -O2 -pipe -Wall -Wextra -Wshadow
DEBUGFLAGS ?= -std=$(STD) -O0 -g3 -D_GLIBCXX_DEBUG -fsanitize=address,undefined -Wall -Wextra -Wshadow
LIB_INCLUDE_DIRS := $(wildcard lib/*/ lib/*/include/)
CPPFLAGS ?= -Iinclude -Ilib $(addprefix -I,$(LIB_INCLUDE_DIRS))

.PHONY: build run debug test submit new clean b r d t s n c

build: $(BIN)
b: build

$(BIN): $(SRC)
	@mkdir -p build
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

run: build
	@if [ -f "$(INPUT)" ]; then \
		./$(BIN) < "$(INPUT)"; \
	else \
		./$(BIN); \
	fi
r: run

debug: $(SRC)
	@mkdir -p build
	$(CXX) $(CPPFLAGS) $(DEBUGFLAGS) $< -o $(BIN)-debug
	@if [ -f "$(INPUT)" ]; then \
		ASAN_OPTIONS=detect_leaks=0 ./$(BIN)-debug < "$(INPUT)"; \
	else \
		ASAN_OPTIONS=detect_leaks=0 ./$(BIN)-debug; \
	fi
d: debug

test: build
	@./scripts/run_tests.sh ./$(BIN) "$(NAME)" "$(INPUT)" "$(EXPECTED)"
t: test

submit:
	@./scripts/expand_submit.py "$(SRC)" "$(SUBMIT)"
s: submit

new:
	@if [ -z "$(PROBLEM)" ]; then \
		echo "usage: make new PROBLEM=ITP1_1_A"; \
		exit 1; \
	fi
	@mkdir -p problems samples
	@if [ -e "problems/$(PROBLEM).cpp" ]; then \
		echo "already exists: problems/$(PROBLEM).cpp"; \
		exit 1; \
	fi
	cp template.cpp problems/$(PROBLEM).cpp
	@mkdir -p samples/$(PROBLEM)
	@touch samples/$(PROBLEM)/1.in samples/$(PROBLEM)/1.out
n: new

clean:
	rm -rf build
c: clean
