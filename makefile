
appname := windowstemp
path := ../$(appname)
bin := $(path)/bin
bin_object := $(bin)/object
bin_debug := $(bin)/debug
bin_release := $(bin)/release
include := $(path)/include
source := $(path)/source
header := $(source)/header

c_flags := -O3 -Wall -std=c++1z -static-libstdc++ -static-libgcc
windows_flag := -mwindows
link := -lgdi32 -luser32 -lkernel32

object := winmain.o test.o

build: $(object)
	g++ -s $(c_flags) \
	       $(windows_flag) \
	       $(bin_object)/test.o \
	       $(bin_object)/winmain.o \
	    -o $(bin_debug)/windowstemp

winmain.o:
	g++ -c -I $(header) $(source)/winmain.cpp -o $(bin_object)/winmain.o

test.o:
	g++ -c -I $(header) $(source)/test.cpp -o $(bin_object)/test.o

run:
	$(bin_debug)/windowstemp

clean:
	rm $(bin_object)/*.o $(bin_debug)/*.exe
