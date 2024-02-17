CC = g++
CFLAGS = -I. -I../inc -g -std=c++11
OBJTBC = objPos.o objPosTree.o GameMechs.o MacUILib.o Player.o ItemBin.o ScreenDrawer.o MainGame.o 
OBJ = objPos.o ../obj/DLinkedList.o ../obj/objPosDLinkedList.o ../obj/objPosStack.o ../obj/cmdQueue.o objPosTree.o GameMechs.o MacUILib.o Player.o ItemBin.o ScreenDrawer.o MainGame.o   
DEPS = *.h

ifeq (${OS}, Windows_NT)
	OSSETTING = -DWINDOWS
else
	OSSETTING = -DPOSIX
	POSTLINKER = -lncurses   ## uncomment this if on Linux
endif

EXEC = Project

%.o: %.cpp $(DEPENDS)
	$(CC) ${OSSETTING} -c -o $@ $< $(CFLAGS)

${EXEC} : $(OBJTBC)
	$(CC) ${OSSETTING} -o $@ ${OBJ} $(CFLAGS) ${POSTLINKER}

clean :
	rm -rf ${OBJTBC} ${EXEC} ${EXEC}.exe

