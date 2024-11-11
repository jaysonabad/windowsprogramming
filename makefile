
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

object := main.o bintana.o button.o

build: $(object)
	g++ -s $(c_flags) \
	       $(windows_flag) \
         $(bin_object)/button.o \
	       $(bin_object)/bintana.o \
	       $(bin_object)/main.o \
	    -o $(bin_debug)/windowstemp

main.o:
	g++ -c -I $(header) $(source)/main.cpp -o $(bin_object)/main.o

bintana.o:
	g++ -c -I $(header) $(source)/bintana.cpp -o $(bin_object)/bintana.o

button.o:
	g++ -c -I $(header) $(source)/button.cpp -o $(bin_object)/button.o

run:
	$(bin_debug)/windowstemp

clean:
	rm $(bin_object)/*.o $(bin_debug)/*.exe
