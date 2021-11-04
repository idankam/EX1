CC=gcc
OBJECTS_MAIN=main.o
OBJECTS_ALL=libclassloops.a libclassrec.a libclassloops.so libclassrec.so mains maindloop maindrec
OBJECTS_REC=advancedClassificationRecursion.o
OBJECTS_LOOP=advancedClassificationLoop.o
OBJECTS_BASE=basicClassification.o
OBJECTS_BASIC=basicFuncs.o
REC_C=advancedClassificationRecursion.c
LOOP_C=advancedClassificationLoop.c
BASE_C=basicClassification.c
BASIC_C = basicFuncs.c
BASIC_H = basicFuncs.h
NUM_H = NumClass.h
FLAGS= -Wall

all: $(OBJECTS_ALL)

loops: libclassloops.a
recursives:libclassrec.a
loopd:libclassloops.so
recursived:libclassrec.so

mains: $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(FLAGS) $(OBJECTS_MAIN) ./libclassrec.a -o mains

maindloop: $(OBJECTS_MAIN) libclassloops.so
	$(CC) $(FLAGS) $(OBJECTS_MAIN) ./libclassloops.so -o maindloop

maindrec: $(OBJECTS_MAIN) libclassrec.so
	$(CC) $(FLAGS) $(OBJECTS_MAIN) ./libclassloops.so -o maindrec

libclassloops.a: $(OBJECTS_LOOP) $(OBJECTS_BASE) $(OBJECTS_BASIC)
	$(AR) -rcs libclassloops.a $(OBJECTS_LOOP) $(OBJECTS_BASE) $(OBJECTS_BASIC)
	ranlib libclassloops.a
libclassrec.a: $(OBJECTS_REC) $(OBJECTS_BASE) $(OBJECTS_BASIC)
	$(AR) -rcs libclassrec.a $(OBJECTS_REC) $(OBJECTS_BASE) $(OBJECTS_BASIC)
	ranlib libclassrec.a
libclassloops.so: $(OBJECTS_LOOP) $(OBJECTS_BASE) $(OBJECTS_BASIC)
	$(CC) -shared -o libclassloops.so $(OBJECTS_LOOP) $(OBJECTS_BASE) $(OBJECTS_BASIC)
libclassrec.so: $(OBJECTS_REC) $(OBJECTS_BASE) $(OBJECTS_BASIC)
	$(CC) -shared -o libclassrec.so $(OBJECTS_REC) $(OBJECTS_BASE) $(OBJECTS_BASIC)

$(OBJECTS_LOOP): $(LOOP_C) $(BASIC_H) $(NUM_H)
	$(CC) $(FLAGS) -c $(LOOP_C)
$(OBJECTS_REC): $(REC_C) $(BASIC_H) $(NUM_H)
	$(CC) $(FLAGS) -c $(REC_C)
$(OBJECTS_BASE): $(BASE_C) $(BASIC_H) $(NUM_H)
	$(CC) $(FLAGS) -c $(BASE_C)
$(OBJECTS_BASIC): $(BASIC_C) $(BASIC_H)
	$(CC) $(FLAGS) -c $(BASIC_C)
$(OBJECTS_MAIN): main.c $(NUM_H)
	$(CC) $(FLAGS) -c main.c



.PHONY: clean loops recursives recursived loopd mains maindloop maindrec all

clean:
	rm -f *.o *.a *.so mains maindrec maindloop	