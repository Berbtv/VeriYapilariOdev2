all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/Agac.cpp -o ./lib/Agac.o
	g++ -c -I "./include" ./src/AgacDugumu.cpp -o ./lib/AgacDugumu.o
	g++ -c -I "./include" ./src/ListeDugum.cpp -o ./lib/ListeDugum.o
	g++ -c -I "./include" ./src/AgaclarListe.cpp -o ./lib/AgaclarListe.o
	g++ -c -I "./include" ./src/Kuyruk.cpp -o ./lib/Kuyruk.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o		
bagla:
	g++ ./lib/AgacDugumu.o ./lib/Agac.o ./lib/ListeDugum.o ./lib/AgaclarListe.o ./lib/Kuyruk.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program