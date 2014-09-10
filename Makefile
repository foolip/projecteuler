SOURCES=$(wildcard problem*.hs)
TARGETS=$(patsubst %.hs, %.hs.bin, $(SOURCES))

all : $(TARGETS)

%.hs.bin : %.hs Prime.hs
	ghc $< -o $@
