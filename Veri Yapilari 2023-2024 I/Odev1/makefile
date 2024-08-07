hepsi: derle bagla calistir

derle:
	g++ -c -I ./include/ ./src/FileManager.cpp -o ./lib/FileManager.o
	g++ -c -I ./include/ ./src/StringManager.cpp -o ./lib/StringManager.o
	g++ -c -I ./include/ ./src/NumberManager.cpp -o ./lib/NumberManager.o
	g++ -c -I ./include/ ./src/Basamak.cpp -o ./lib/Basamak.o
	g++ -c -I ./include/ ./src/Sayi.cpp -o ./lib/Sayi.o
	g++ -c -I ./include/ ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I ./include/ ./src/SayilarListesi.cpp -o ./lib/SayilarListesi.o
	g++ -c -I ./include/ ./src/Program.cpp -o ./lib/Program.o

bagla:
	g++ ./lib/FileManager.o ./lib/StringManager.o ./lib/NumberManager.o ./lib/Basamak.o ./lib/Sayi.o ./lib/Dugum.o ./lib/SayilarListesi.o ./lib/Program.o -o ./bin/Program.exe
	
calistir:
	./bin/Program.exe