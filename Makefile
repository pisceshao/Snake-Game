index: controller.o model.o view.o index.o
	gcc $^ -lcurses -o index
index.o: index.c controller.o model.o view.o
	gcc -c index.c
controller.o: controller.c
	gcc -c $^
model.o: model.c
	gcc -c $^
view.o: view.c
	gcc -c $^
clear:
	rm *.o
