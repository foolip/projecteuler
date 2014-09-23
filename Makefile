SOURCES=$(wildcard p???.hs)
TARGETS=$(patsubst %.hs, %.hs.bin, $(SOURCES))

all : $(TARGETS)

%.hs.bin : %.hs Prime.hs
	ghc $< -o $@

CLANG_WARN_FLAGS=-Weverything -Wno-c++98-compat -Wno-padded
CLANG_DEBUG_FLAGS=-g -O0
CLANG_RELEASE_FLAGS=-DNDEBUG -O3
CLANG_FLAGS=--std=c++11 -pthread -fno-exceptions -fno-rtti $(CLANG_WARN_FLAGS) $(CLANG_RELEASE_FLAGS)

%.cc.bin : %.cc prime.h
	clang++ $(CLANG_FLAGS) $< -o $@
