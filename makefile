CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -pedantic-errors
CXXFLAGS += -Wall

OBJS = Caterpie.o Charmander.o Geodude.o menu.o Monster.o Onix.o PalletTown.o PewterCity.o Pidgey.o pokemonMain.o Route.o Space.o Trainer.o ViridianForest.o

SRCS = Caterpie.cpp Charmander.cpp Geodude.cpp menu.cpp Monster.cpp Onix.cpp PalletTown.cpp PewterCity.cpp Pidgey.cpp pokemonMain.cpp Route.cpp Space.cpp Trainer.cpp ViridianForest.cpp

HEADERS = Caterpie.hpp Charmander.hpp Geodude.hpp menu.hpp Monster.hpp Onix.hpp PalletTown.hpp PewterCity.hpp Pidgey.hpp Route.hpp Space.hpp Trainer.hpp ViridianForest.hpp

pokemon: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o pokemon

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm ${OBJS} pokemon 
