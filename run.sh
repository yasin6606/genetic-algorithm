sudo rm ./runner && ./*.o && rm ./*.png
gcc -c ./plot/pbPlots.c -std=c99 -O3 -march=native
gcc -c ./plot/supportLib.c -std=c99 -O3 -march=native
#gcc -c main.c -lm -std=c99 -O3 -march=native
gcc main.c pbPlots.o supportLib.o -lm -o runner
#strip runner
#gcc main.c -lm -o runner
./runner