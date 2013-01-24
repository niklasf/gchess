AM_CXXFLAGS = \
	$(GCHESS_CFLAGS) \
	-include config.h \
	-DLOCALEDIR=\""$(localedir)"\"

bin_PROGRAMS = gchess

gchess_SOURCES = \
	main.cc \
	MainWindow.cc MainWindow.h \
	ChessboardWidget.cc ChessboardWidget.h

gchess_LDADD = $(GCHESS_LIBS)
