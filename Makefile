all: clang_debug clang_release ghc_release

# C++

CC_SOURCES=$(wildcard p???.cc)

CLANG_FLAGS=-std=c++1y -pthread -fno-exceptions -fno-rtti
CLANG_WARN_FLAGS=-Weverything -Wno-c++98-compat -Wno-padded
CLANG_DEBUG_FLAGS=$(CLANG_FLAGS) $(CLANG_WARN_FLAGS) -g -O0
CLANG_RELEASE_FLAGS=$(CLANG_FLAGS) $(CLANG_WARN_FLAGS) -DNDEBUG -O3

clang_debug: $(patsubst %.cc, out/clang_debug/%, $(CC_SOURCES))

out/clang_debug/%: %.cc prime.h
	@mkdir -p out/clang_debug/
	clang++ $(CLANG_DEBUG_FLAGS) $< -o $@

clang_release: $(patsubst %.cc, out/clang_release/%, $(CC_SOURCES))

out/clang_release/%: %.cc prime.h
	@mkdir -p out/clang_release/
	clang++ $(CLANG_RELEASE_FLAGS) $< -o $@

# Haskell

HS_SOURCES=$(wildcard p???.hs)

ghc_release: $(patsubst %.hs, out/ghc_release/%, $(HS_SOURCES))

out/ghc_release/%: %.hs
	@mkdir -p out/ghc_release/
	ghc --make -O2 $< -o $@ -outputdir $@.tmp
