######################

CXX           = g++
LD            = g++

#############################

os = $(shell uname -s)

INSTALL_DIR=/opt/local
GSL=$(INSTALL_DIR)

ifeq ($(os),Linux)
CXXFLAGS      = -O -Wall
else
CXXFLAGS      = -O -fPIC -pipe -Wall
endif

CXXFLAGSGSL = $(CXXFLAGS)
CXXFLAGSGSL += -I$(GSL)/include
CXXFLAGSROOT = -I$(ROOTSYS)/include

ifeq ($(os),Linux)
LDFLAGS       = -O -g
LDFLAGSS      = -g --shared
else
LDFLAGS       = -O -Xlinker -bind_at_load -flat_namespace
LDFLAGSS      = -dynamiclib -flat_namespace -undefined suppress
LDFLAGSSS     = -bundle
endif

ROOTLIBS      = $(shell root-config --libs)

LIBSROOT       = $(ROOTLIBS)
LIBSGSL	       = $(LIBS)
LIBSGSL       += -L$(GSL)/lib -lgsl -lgslcblas


vec2dTest :
	g++ $(CXXFLAGSGSL) $(CXXFLAGSROOT) -c src/vec2dTest.C
	g++ $(LDFLAGS) vec2dTest.o $(LIBSGSL) $(LIBSROOT) -L../Lib/ -lVec2d -o bin/vec2dTest
	rm vec2dTest.o

clean :
	rm -f *.o 
	@echo "All cleaned-up :-)"

# DO NOT DELETE
