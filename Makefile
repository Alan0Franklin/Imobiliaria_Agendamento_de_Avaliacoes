EXEC = imobiliaria.exe
CXX = g++
CXXFLAGS = -std=c++11 -Wall -O0 -pedantic
SRCS = main.cpp pessoa.cpp cliente.cpp corretor.cpp imovel.cpp util.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(EXEC)

clean-windows:
	@if exist *.o del /Q *.o
	@if exist $(EXEC) del /Q $(EXEC)
