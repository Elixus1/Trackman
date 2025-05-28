compile:
	g++ -g -o main main.cpp vector3d.cpp ball.cpp physics.cpp simulator.cpp writer.cpp

format: 
	clang-format -i *.cpp
	clang-format -i *.hpp
clean:
	rm -f main
	rm -f *.o

	
