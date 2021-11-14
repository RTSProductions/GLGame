game repic:
	clang++ main.cpp -o Builds/Game -I/usr/local/Cellar/sdl2/2.0.16/include/  -L/usr/local/Cellar/sdl2/2.0.16/lib/ -lSDL2-2.0.0
	./Builds/Game
game andor:
	clang++ main.cpp -o Builds/Game -lSDL2
	./Builds/Game
clean:
	rm -rf *.app
	rm -rf *.exe
	rm -rf *.exec
	rm -rf *.out
	rm -rf Game
	rm -rf Program
