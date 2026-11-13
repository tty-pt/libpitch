FOLDER := pitch
all := libpitch test_pitch

libpitch-obj-y := src/token.o src/parse.o src/render.o src/music.o
LDLIBS-test_pitch := -L./lib -lpitch

WASM_SRCS := src/token.c src/parse.c src/render.c src/music.c src/libpitch.c npm/wasm/pitch_wasm.c
WASM_EXTRA_CFLAGS := -Iinclude/pitch -Iinclude -Isrc

include ../mk/include.mk

CFLAGS += -I./include/pitch -I./include -I./src $(EXTRA_CFLAGS)

lib/libpitch.a: src/libpitch.o src/token.o src/parse.o src/render.o src/music.o lib
	ar rcs $@ src/libpitch.o src/token.o src/parse.o src/render.o src/music.o

lib/libtransp.so: lib/libpitch.so
	ln -sf libpitch.so $@

lib/libtransp.a: lib/libpitch.a
	ln -sf libpitch.a $@

all: lib/libpitch.a lib/libtransp.so lib/libtransp.a

test: all
	LD_LIBRARY_PATH=./lib ./bin/test_pitch

${DESTDIR}${PREFIX}/lib/pkgconfig/pitch.pc: pitch.pc
	install -d ${DESTDIR}${PREFIX}/lib/pkgconfig
	install -m 644 pitch.pc $@

install: ${DESTDIR}${PREFIX}/lib/pkgconfig/pitch.pc

# Optional Node.js & WebAssembly bindings
NPM ?= npm

npm-build:
	@if command -v $(NPM) >/dev/null 2>&1; then \
		(cd npm && $(NPM) run build); \
	else \
		echo "Skipping npm build — $(NPM) not found"; \
	fi

npm-test: npm-build
	@if command -v $(NPM) >/dev/null 2>&1; then \
		(cd npm && $(NPM) test); \
	fi

objects-set.mk: Makefile

.PHONY: all test npm-build npm-test
