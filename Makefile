SOURCES=$(wildcard *.hs)
TARGETS=$(patsubst %.hs, %.hs.bin, $(SOURCES))

all : $(TARGETS)

%.hs.bin : %.hs
	ghc $< -o $@
