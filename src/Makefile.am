AM_CXXFLAGS = \
	$(GCHESS_CFLAGS) \
	-include config.h \
	-DLOCALEDIR=\""$(localedir)"\"

bin_PROGRAMS = gchess

gchess_SOURCES = \
	main.cc

gchess_LDADD = $(GCHESS_LIBS)
