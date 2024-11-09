
path := ..\windowstemp
appname := windowstemp
bin := $(path)\bin
bin_object := $(bin)\object
bin_debug := $(bin)\debug
bin_release := $(bin)\release
source := $(path)\source

c_flags := -O3 -Wall -std=c++1z -static-libstdc++ -static-libgcc
windows_flag := -mwindows
link := -lgdi32 -luser32 -lkernel32

object := winmain.o

build: $(object)
	g++ -s $(c_flags) $(windows_flag) \
	       $(bin_object)/winmain.o \
	    -o $(bin_debug)/windowstemp

winmain.o:
	g++ -c $(source)/winmain.cpp -o $(bin_object)/winmain.o

run:
	$(bin_debug)/windowstemp

clean:
	del $(bin_object)\*.o
	del $(bin_debug)\*.exe
