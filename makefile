.SUFFIXES:
.PRECIOUS:%.o 
.PHONY: clean compile test exe
CXX = g++ -g 
libs = -lgtest -lpthread
HEADERS = $(wildcard *.hpp)
o_files = $(wildcard *.o) #currently in folder
o_files_virtually = $(addsuffix .o, $(basename $(HEADERS)))
src = $(wildcard *.cpp)

Main = $(filter %Main, $(basename $(src)))
Test = $(filter %Test, $(basename $(src))) 
Testexecute = $(addsuffix .virtuell, $(Test))
all: clean format compile

exe:
	 
eigene: 
	
compile: $(Main) $(Test)

%Main: %Main.o $(o_files_virtually) 
	$(CXX) -o $@ $^ 
%Test: %Test.o %.o $(o_files_virtually) 
	$(CXX) -o $@ $^ $(libs)

%.o: %.cpp $(HEADERS) 
	$(CXX) -c $<

test: $(Testexecute) #to do test: first compile 

%Test.virtuell:
	./$(basename $@)
format:
	clang-format -i *.cpp
	clang-format -i *.hpp
clean:
	rm  -f $(basename $(src))
	rm -f $(o_files)
	rm -f a_copy.options a_copy.constraints 
	rm -f a.out 'WSL2_GUI_APPS_ENABLED=1'
