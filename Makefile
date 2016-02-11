#

ROOTCFLAGS = $(shell root-config --cflags)
ROOTLIBS   = $(shell root-config --libs)
CXXFLAGS   = $(ROOTCFLAGS) -Wall
CXXLIBS    = $(ROOTLIBS)

#SRCS	      =	gkps.cxx
#SRCS		  = $(wildcard *.cxx)
SRCS		  = HEPAnalysis_jet.cxx

OBJS 	 	  = ${SRCS:.cxx=.o}

CC	      =	g++

INCLUDES      =	-I.

#FFLAGS        =	-g -O2 $(INCLUDES) \
#		-fno-automatic -finit-local-zero -fugly-complex \
#		-fno-globals -Wno-globals \
#		-fno-second-underscore
FFLAGS        = -Wall -O3 $(INCLUDES) -ffixed-line-length-132 

#FASTJETFLAGS  = `~/packages/fastjet_v3.0.3/bin/fastjet-config --cxxflags --libs --plugins`	
FASTJETFLAGS  = `~/packages/fastjet_v3.0.3/bin/fastjet-config --cxxflags --libs --plugins`	

DEST          =	./

INSTALL       =	install

LD            =	g++

LDOPTS        =

PROGRAM	      = HEPAnalysis

SHELL	      =	/bin/sh

ALLDEFINES    =	$(INCLUDES) 

DEPENDFLAGS   = 

DEPEND        =	makedepend

.cxx.o:
		$(CC) -c $(CXXFLAGS) $< $(FASTJETFLAGS)

all:	$(PROGRAM)

$(PROGRAM):	$(OBJS) $(LIBS)
	$(LD) $(LDOPTS) $(LIBS) $(CXXLIBS)  $(OBJS) -o $(PROGRAM) $(FASTJETFLAGS)

clean:;	@rm -f $(OBJS) $(PROGRAM) last.kumac* core *~ 

.SUFFIXES: .a .o .cxx

