generator:combination.o combinationGenerator.o combinationAssignment.o
	cc -o generator combination.o combinationGenerator.o combinationAssignment.o
combinationGenerator.o:combinationGenerator.c combinationGenerator.h
	cc -c combinationGenerator.c
combinationAssignment.o:combinationAssignment.c combinationAssignment.h
	cc -c combinationAssignment.c
combination.o:combination.c combinationGenerator.h combinationAssignment.h
	cc -c combination.c
