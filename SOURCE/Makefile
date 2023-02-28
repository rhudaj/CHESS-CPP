CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -Werror=vla
EXEC = chess -lX11
OBJECTS = main.o board.o char2piece.o gamesetup.o position.o square.o windowobserver.o textobserver.o subject.o window.o move.o boardtracker.o game.o squaredecorator.o empty.o piece.o bishop.o king.o queen.o rook.o knight.o pawn.o

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} chess ${DEPENDS}
