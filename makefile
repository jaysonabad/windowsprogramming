
appname := windowstemp
path := ../windowsprogramming
bin := $(path)/bin
bin_object := $(bin)/object
bin_debug := $(bin)/debug
bin_release := $(bin)/release
include := $(path)/include
source := $(path)/source
header := $(source)/header
resource := $(path)/resource

c_flags := -O3 -Wall -std=c++1z -static-libstdc++ -static-libgcc
windows_flag := -mwindows
link := -lgdi32 -luser32 -lkernel32

object := resource.rc \
          main.o \
          bintana.o \
          button.o  \
          frame.o \
          components.o \
          combobox.o \
					progressbar.o

build: $(object)
	g++ -s $(c_flags) \
         $(windows_flag) \
         $(bin_object)/progressbar.o \
				 $(bin_object)/combobox.o \
				 $(bin_object)/components.o \
         $(bin_object)/frame.o \
         $(bin_object)/button.o \
         $(bin_object)/bintana.o \
         $(bin_object)/main.o \
				 $(build_objects)/resource.rc \
      -o $(bin_debug)/windowstemp \
         $(link)

main.o:
	g++ -c -I $(header) $(source)/main.cpp -o $(bin_object)/main.o

bintana.o:
	g++ -c -I $(header) $(source)/bintana.cpp -o $(bin_object)/bintana.o

button.o:
	g++ -c -I $(header) $(source)/button.cpp -o $(bin_object)/button.o

frame.o:
	g++ -c -I $(header) $(source)/frame.cpp -o $(bin_object)/frame.o

components.o:
	g++ -c -I $(header) $(source)/components.cpp -o $(bin_object)/components.o

combobox.o:
	g++ -c -I $(header) $(source)/combobox.cpp -o $(bin_object)/combobox.o

progressbar.o:
	g++ -c -I $(header) $(source)/progressbar.cpp -o $(bin_object)/progressbar.o

resource.rc:
	windres $(resource)/resource.rc -O coff -o $(build_objects)/resource.rc

run:
	$(bin_debug)/windowstemp

clean:
	rm $(bin_object)/*.o $(bin_debug)/*.exe
