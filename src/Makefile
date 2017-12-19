#DEFINIZIONI DELLE VARIABILI

CC = g++
LIBS = -I. -I../lib
CXXFLAGS=$(LIBS) 

SOURCES ="main.cc creazione.cc playTime.cc videoRender.cc"
OBJ="main.o creazione.o playTime.o videoRender.o"
ALLEGRO="allegro-5.0 allegro_primitives-5.0 allegro_image-5.0 allegro_font-5.0 allegro_ttf-5.0 allegro_audio-5.0 allegro_acodec-5.0"

EXE_NAME = SpaceEffect
DEB_NAME = SE_Debug
#VPATH = src:../include

#-----Dichiarazione esplicita dei Phony Target
.PHONY: depend debug clean cleanall


SpaceEffect: main.o creazione.o playTime.o videoRender.o
	$(CC) -o $(EXE_NAME) main.o creazione.o playTime.o videoRender.o `pkg-config --cflags --libs $(ALLEGRO)`


depend:
	mkdir dep
	g++ -MM -I../lib main.cc > dep/main
	g++ -MM -I../lib creazione.cc > dep/creazione
	g++ -MM -I../lib playTime.cc > dep/playTime
	g++ -MM -I../lib videoRender.cc > dep/videoRender






#-----REGOLE IMPLICITE

main.o: #include dep/dep_main

creazione.o: #include dep/dep_creazione

playTime.o: #include dep/dep_playTime

videoRender.o: #include dep/dep_videoRender

#-----FINE REGOLE IMPLICITE



debug: 
	$(CC) -o $(DEB_NAME) -D DEBUG_MODE -g main.cc creazione.cc playTime.cc videoRender.cc `pkg-config --cflags --libs $(ALLEGRO)` -I../lib

clean:
	rm *.o

cleanall:
	rm $(EXE_NAME) $(DEB_NAME) -R dep *.o


