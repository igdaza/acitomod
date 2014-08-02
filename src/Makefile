# $Id$
# Makefile:
#  Make file for Auscult
#

.KEEP.STATE:

OPENCV_LDFLAG	=  -export-dynamic -I -Wl -L/usr/local/lib `pkg-config gtk+-2.0 libglademm-2.4 --libs` -L/usr/lib

LDFLAGS 	= $(OPENCV_LDFLAG) -L./objs

OPENCV_INFLAG	=  -I. -DXTHREADS -D_FILE_OFFSET_BITS=64 -I/usr/include/gtk-2.0 -I/usr/lib/gtk-2.0/include -I/usr/X11R6/include -I/usr/include/atk-1.0 -I/usr/include/pango-1.0 -I/usr/include/freetype2 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include `pkg-config gtk+-2.0 libglademm-2.4 --cflags`

CC		= g++ -pg -ggdb -Wno-deprecated

CFLAGS		= -g -O0 -Wall $(OPENCV_INFLAG) -Wno-unused-variable

OBJS = Interface.o callbacks.o rs232_comm.o rs232.o tinyxml.o tinyxmlparser.o tinyxmlerror.o tinystr.o riego.o init_process.o edit_open_profile.o callbacks_riego.o

TARGET	= DOMOTICA-MANUAL

OBJDIR := objs

SRCDIR := .
INCDIR := .


#
# compile
#

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $<  -o $@

$(OBJDIR)/%.o : Interface.cpp
	$(CC) $(CFLAGS) -c $<  -o $@
#
# link 
#
$(TARGET) : $(addprefix $(OBJDIR)/,$(OBJS)) 
	$(CC) $(LDFLAGS) -o $@ $(addprefix $(OBJDIR)/,$(OBJS))

clean:
	rm -f  $(addprefix $(OBJDIR)/,$(OBJS)) $(TARGET) *~

