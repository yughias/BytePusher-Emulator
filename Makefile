all:
	gcc -Iinclude -Llib src/*.c -lSDL2main -lSDL2 -lSDL2_mixer -lole32 -lComdlg32