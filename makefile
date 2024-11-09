
path := ..\windowstemp
appname := windowstemp
bin := $(path)\bin
bin_object := $(path)\bin\object
source := $(path)\source

c_flags := -O3 -Wall -std=c++1z -static-libstdc++ -static-libgcc
windows_flag := -mwindows
link := -lgdi32 -luser32 -lkernel32

object := winmain.o

build: $(object)
	g++ -s $(c_flags) $(windows_flag) \
	       $(bin_object)/winmain.o \
	    -o $(bin)/windowstemp

winmain.o:
	g++ -c $(source)/winmain.cpp -o $(bin_object)/winmain.o

run:
	$(bin)/windowstemp

clean:
	del $(bin)\*.exe $(bin_object)\*.o
