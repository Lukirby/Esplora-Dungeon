OBJ = main.o Menubar.o MapHandler.o Gamestate.o Map.o TreeRoom.o EnemiesHandler.o ArtefactHandler.o SpawnPoints.o LoC.o Room.o Walls.o Doors.o Exits.o Player.o Elements2.o Artefact.o Enemies2.o Movement2.o Entity.o Shooter.o Position.o CheckPlayer.o Interaction.o Coordinates.o -lncurses

Progetto: $(OBJ)
	g++ -o Progetto $(OBJ)

-include dependencies

.PHONY: clean cleanall
depend: 
	g++ -MM *.cc > dependencies
clean:
	rm -f *.o 
cleanall:
	rm -f Progetto *.o 