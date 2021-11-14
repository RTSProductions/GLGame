game repic:
	clang++ main.cpp -o Game -I/usr/local/Cellar/sdl2/2.0.16/include/  -L/usr/local/Cellar/sdl2/2.0.16/lib/ -lSDL2-2.0.0

game andor:
	clang++ main.cpp -o Game -lSDL2
play:
	./Game
	rm -rf Game

clean:
	rm -rf *.app
	rm -rf *.exe
	rm -rf *.exec
	rm -rf *.out
	rm -rf Game
	rm -rf Program
