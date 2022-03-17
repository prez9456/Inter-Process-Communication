FILES = Starter.c Fibb.c Prime.c Total.c CharacterReader.c
OUT_EXE = Starter
OUT_FIB = Fibb
OUT_PRI = Prime
OUT_TOT = Total
OUT_CHAR = CharacterReader
PAK = README.txt Makefile
TAR_NAME = Andy-Donis_Paz-HW3.tar

build:
	gcc -lrt -o $(OUT_EXE) Starter.c
	gcc -lrt -o $(OUT_FIB) Fibb.c
	gcc -lrt -o $(OUT_PRI) Prime.c
	gcc -lrt -o $(OUT_TOT) Total.c
	gcc -lrt -o $(OUT_CHAR) CharacterReader.c
package:
	tar cvzf $(TAR_NAME) $(FILES) $(PAK)
clean:
	rm -f $(OUT_EXE) $(OUT_FIB) $(OUT_PRI) $(OUT_TOT) $(OUT_CHAR)