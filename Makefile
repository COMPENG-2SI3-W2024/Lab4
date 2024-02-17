CC=g++
CFLAGS=-I. -lm -g -std=c++11
DEPS = *.h
OBJ = objPosTree.o Test.o  
OBJTBC = objPos.o objPosTree.o objPosTreeModel.o Test.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Lab4: $(OBJ)
	$(CC) -o $@ ${OBJTBC} $(CFLAGS)

test:	testLab4
testLab4:
	./run.sh

.PHONY: clean

clean:
	$(RM) ${OBJ} *.exe *.xml Lab4
