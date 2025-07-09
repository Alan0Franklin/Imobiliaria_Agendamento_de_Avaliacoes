EXEC = imobiliaria.exe
CXX = g++
CXXFLAGS = -Wall -O0 -pedantic
OBJS = main.o Entidades.o

$(EXEC): $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS)

main.o: main.cpp Entidades.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Entidades.o: Entidades.cpp Entidades.hpp
	$(CXX) $(CXXFLAGS) -c Entidades.cpp

clean:
	@if exist *.o del /Q *.o
	@if exist $(EXEC) del /Q $(EXEC)
