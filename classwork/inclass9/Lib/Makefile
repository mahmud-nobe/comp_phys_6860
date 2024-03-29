######################

CXX           = g++
LD            = g++

#############################

os = $(shell uname -s)


ifeq ($(os),Linux)
CXXFLAGS      = -I$(ROOTSYS)/include
else
CXXFLAGS      = -O -fPIC -pipe -Wall -dynamiclib -I$(ROOTSYS)/include
endif

ifeq ($(os),Linux)
LDFLAGS       = -g
LDFLAGSS      = -g --shared
else
LDFLAGS       = -O -Xlinker -bind_at_load -flat_namespace
LDFLAGSS      = -dynamiclib -flat_namespace -undefined suppress
LDFLAGSSS     = -bundle
endif

ROOTLIBS      = $(shell root-config --libs)
LIBS          =  $(ROOTLIBS)

HDRS          = vec2d.h
SRCS          = vec2d.C dictVec2d.C 

OBJS          = $(SRCS:.C=.o)

SLIB          = libVec2d.so

$(SLIB):     $(OBJS)
	@echo "Linking $(PROGRAM) for "$(os)
	@echo $(LD) $(LDFLAGSS) $(OBJS) $(LIBS) -o $(SLIB)	
	@$(LD) $(LDFLAGSS) $(OBJS) $(LIBS) -o $(SLIB)
#@$(LD) $(LDFLAGS) $(OBJS) $(LIBS) -o $(PROGRAM)
	@echo "done"

##########################################################

vec2d.o: vec2d.h

dictVec2d.C: $(HDRS)
	@echo "Generating dictionary ..."
	@$(ROOTSYS)/bin/rootcint -f dictVec2d.C -c $(HDRS)

.C.o:
	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f *.o dict*.* $(SLIB)
	@echo "All cleaned-up :-)"
