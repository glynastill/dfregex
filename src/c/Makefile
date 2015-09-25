##-------------------------------------------------------------------------
## posix regex extensions
##
## Copyright (c) 2015, glyn@8kb.co.uk
## Author: Glyn Astill <glyn@8kb.co.uk>
##
##-------------------------------------------------------------------------
##

CPP  = g++.exe
CC   = gcc.exe
WINDRES = windres.exe
RES  = dfregex_private.res
OBJ  = dfregex.o memman.o gnuregex.o $(RES)
LINKOBJ  = dfregex.o memman.o gnuregex.o $(RES)
LIBS =  --no-export-all-symbols --add-stdcall-alias -lgnurx  
INCS = 
CXXINCS = 
BIN  = dfregex.dll
CXXFLAGS = $(CXXINCS) -DBUILDING_DLL=1  
CFLAGS = $(INCS) -DBUILDING_DLL=1  
RM = del -f

.PHONY: all all-before all-after clean clean-custom

all: all-before dfregex.dll all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

DLLWRAP=dllwrap.exe
DEFFILE=libdfregex.def
STATICLIB=libdfregex.a

$(BIN): $(LINKOBJ)
	$(DLLWRAP) --output-def $(DEFFILE) --implib $(STATICLIB) $(LINKOBJ) $(LIBS) -o $(BIN)

dfregex.o: dfregex.c
	$(CC) -c dfregex.c -o dfregex.o $(CFLAGS)

memman.o: memman.c
	$(CC) -c memman.c -o memman.o $(CFLAGS)

gnuregex.o: gnuregex.c
	$(CC) -c gnuregex.c -o gnuregex.o $(CFLAGS)

dfregex_private.res: dfregex_private.rc 
	$(WINDRES) -i dfregex_private.rc --input-format=rc -o dfregex_private.res -O coff 
