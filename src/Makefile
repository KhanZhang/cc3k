CC = g++
CCFLAGS = -g -ggdb -std=c++14 -Wall -MMD -Werror=vla
EXEC = cc3k+

# Removed these temporarily from OBJECTS:
# Pickup.o Potion.o
OBJECTS = main.o \
	Animal.o Barrier.o BasicCell.o Cell.o CellDecorator.o Compass.o Display.o \
	Dragonborn.o Dragon.o Dwarf.o Elf.o Enemy.o Floor.o Goblin.o Human.o Merchant.o \
	Observer.o Orc.o Phoenix.o Player.o Subject.o Treasure.o \
	Troll.o Vampire.o Werewolf.o Pickup.o Potions.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CC} ${CCFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHNOY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
