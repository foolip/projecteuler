SOURCES=$(wildcard problem*.hs)
TARGETS=$(patsubst %.hs, %.hs.bin, $(SOURCES))

all : $(TARGETS)

%.hs.bin : %.hs Prime.hs
	ghc $< -o $@

problem10.cc.bin : problem10.cc prime.h
	clang++ --std=c++11 -Weverything $< -o $@
