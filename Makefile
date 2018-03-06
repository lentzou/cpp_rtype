# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dekamor/project/cpp_rtype

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dekamor/project/cpp_rtype

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dekamor/project/cpp_rtype/CMakeFiles /home/dekamor/project/cpp_rtype/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dekamor/project/cpp_rtype/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named server

# Build rule for target.
server: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 server
.PHONY : server

# fast build rule for target.
server/fast:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/build
.PHONY : server/fast

#=============================================================================
# Target rules for targets named input

# Build rule for target.
input: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 input
.PHONY : input

# fast build rule for target.
input/fast:
	$(MAKE) -f CMakeFiles/input.dir/build.make CMakeFiles/input.dir/build
.PHONY : input/fast

#=============================================================================
# Target rules for targets named graph

# Build rule for target.
graph: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 graph
.PHONY : graph

# fast build rule for target.
graph/fast:
	$(MAKE) -f CMakeFiles/graph.dir/build.make CMakeFiles/graph.dir/build
.PHONY : graph/fast

#=============================================================================
# Target rules for targets named client

# Build rule for target.
client: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 client
.PHONY : client

# fast build rule for target.
client/fast:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/build
.PHONY : client/fast

#=============================================================================
# Target rules for targets named game

# Build rule for target.
game: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 game
.PHONY : game

# fast build rule for target.
game/fast:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/build
.PHONY : game/fast

#=============================================================================
# Target rules for targets named sound

# Build rule for target.
sound: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 sound
.PHONY : sound

# fast build rule for target.
sound/fast:
	$(MAKE) -f CMakeFiles/sound.dir/build.make CMakeFiles/sound.dir/build
.PHONY : sound/fast

Client/Client.o: Client/Client.cpp.o

.PHONY : Client/Client.o

# target to build an object file
Client/Client.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/Client.cpp.o
.PHONY : Client/Client.cpp.o

Client/Client.i: Client/Client.cpp.i

.PHONY : Client/Client.i

# target to preprocess a source file
Client/Client.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/Client.cpp.i
.PHONY : Client/Client.cpp.i

Client/Client.s: Client/Client.cpp.s

.PHONY : Client/Client.s

# target to generate assembly for a file
Client/Client.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/Client.cpp.s
.PHONY : Client/Client.cpp.s

Client/Graphic.o: Client/Graphic.cpp.o

.PHONY : Client/Graphic.o

# target to build an object file
Client/Graphic.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/Graphic.cpp.o
.PHONY : Client/Graphic.cpp.o

Client/Graphic.i: Client/Graphic.cpp.i

.PHONY : Client/Graphic.i

# target to preprocess a source file
Client/Graphic.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/Graphic.cpp.i
.PHONY : Client/Graphic.cpp.i

Client/Graphic.s: Client/Graphic.cpp.s

.PHONY : Client/Graphic.s

# target to generate assembly for a file
Client/Graphic.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/Graphic.cpp.s
.PHONY : Client/Graphic.cpp.s

Client/Network.o: Client/Network.cpp.o

.PHONY : Client/Network.o

# target to build an object file
Client/Network.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/Network.cpp.o
.PHONY : Client/Network.cpp.o

Client/Network.i: Client/Network.cpp.i

.PHONY : Client/Network.i

# target to preprocess a source file
Client/Network.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/Network.cpp.i
.PHONY : Client/Network.cpp.i

Client/Network.s: Client/Network.cpp.s

.PHONY : Client/Network.s

# target to generate assembly for a file
Client/Network.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/Network.cpp.s
.PHONY : Client/Network.cpp.s

Client/System.o: Client/System.cpp.o

.PHONY : Client/System.o

# target to build an object file
Client/System.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/System.cpp.o
.PHONY : Client/System.cpp.o

Client/System.i: Client/System.cpp.i

.PHONY : Client/System.i

# target to preprocess a source file
Client/System.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/System.cpp.i
.PHONY : Client/System.cpp.i

Client/System.s: Client/System.cpp.s

.PHONY : Client/System.s

# target to generate assembly for a file
Client/System.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/System.cpp.s
.PHONY : Client/System.cpp.s

Client/main.o: Client/main.cpp.o

.PHONY : Client/main.o

# target to build an object file
Client/main.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/main.cpp.o
.PHONY : Client/main.cpp.o

Client/main.i: Client/main.cpp.i

.PHONY : Client/main.i

# target to preprocess a source file
Client/main.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/main.cpp.i
.PHONY : Client/main.cpp.i

Client/main.s: Client/main.cpp.s

.PHONY : Client/main.s

# target to generate assembly for a file
Client/main.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/main.cpp.s
.PHONY : Client/main.cpp.s

Client/tmp.o: Client/tmp.cpp.o

.PHONY : Client/tmp.o

# target to build an object file
Client/tmp.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/tmp.cpp.o
.PHONY : Client/tmp.cpp.o

Client/tmp.i: Client/tmp.cpp.i

.PHONY : Client/tmp.i

# target to preprocess a source file
Client/tmp.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/tmp.cpp.i
.PHONY : Client/tmp.cpp.i

Client/tmp.s: Client/tmp.cpp.s

.PHONY : Client/tmp.s

# target to generate assembly for a file
Client/tmp.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client/tmp.cpp.s
.PHONY : Client/tmp.cpp.s

Common/Player.o: Common/Player.cpp.o

.PHONY : Common/Player.o

# target to build an object file
Common/Player.cpp.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Common/Player.cpp.o
	$(MAKE) -f CMakeFiles/input.dir/build.make CMakeFiles/input.dir/Common/Player.cpp.o
	$(MAKE) -f CMakeFiles/graph.dir/build.make CMakeFiles/graph.dir/Common/Player.cpp.o
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Common/Player.cpp.o
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Common/Player.cpp.o
	$(MAKE) -f CMakeFiles/sound.dir/build.make CMakeFiles/sound.dir/Common/Player.cpp.o
.PHONY : Common/Player.cpp.o

Common/Player.i: Common/Player.cpp.i

.PHONY : Common/Player.i

# target to preprocess a source file
Common/Player.cpp.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Common/Player.cpp.i
	$(MAKE) -f CMakeFiles/input.dir/build.make CMakeFiles/input.dir/Common/Player.cpp.i
	$(MAKE) -f CMakeFiles/graph.dir/build.make CMakeFiles/graph.dir/Common/Player.cpp.i
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Common/Player.cpp.i
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Common/Player.cpp.i
	$(MAKE) -f CMakeFiles/sound.dir/build.make CMakeFiles/sound.dir/Common/Player.cpp.i
.PHONY : Common/Player.cpp.i

Common/Player.s: Common/Player.cpp.s

.PHONY : Common/Player.s

# target to generate assembly for a file
Common/Player.cpp.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Common/Player.cpp.s
	$(MAKE) -f CMakeFiles/input.dir/build.make CMakeFiles/input.dir/Common/Player.cpp.s
	$(MAKE) -f CMakeFiles/graph.dir/build.make CMakeFiles/graph.dir/Common/Player.cpp.s
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Common/Player.cpp.s
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Common/Player.cpp.s
	$(MAKE) -f CMakeFiles/sound.dir/build.make CMakeFiles/sound.dir/Common/Player.cpp.s
.PHONY : Common/Player.cpp.s

Game/Graphic/CreditState.o: Game/Graphic/CreditState.cpp.o

.PHONY : Game/Graphic/CreditState.o

# target to build an object file
Game/Graphic/CreditState.cpp.o:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/CreditState.cpp.o
.PHONY : Game/Graphic/CreditState.cpp.o

Game/Graphic/CreditState.i: Game/Graphic/CreditState.cpp.i

.PHONY : Game/Graphic/CreditState.i

# target to preprocess a source file
Game/Graphic/CreditState.cpp.i:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/CreditState.cpp.i
.PHONY : Game/Graphic/CreditState.cpp.i

Game/Graphic/CreditState.s: Game/Graphic/CreditState.cpp.s

.PHONY : Game/Graphic/CreditState.s

# target to generate assembly for a file
Game/Graphic/CreditState.cpp.s:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/CreditState.cpp.s
.PHONY : Game/Graphic/CreditState.cpp.s

Game/Graphic/GameState.o: Game/Graphic/GameState.cpp.o

.PHONY : Game/Graphic/GameState.o

# target to build an object file
Game/Graphic/GameState.cpp.o:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/GameState.cpp.o
.PHONY : Game/Graphic/GameState.cpp.o

Game/Graphic/GameState.i: Game/Graphic/GameState.cpp.i

.PHONY : Game/Graphic/GameState.i

# target to preprocess a source file
Game/Graphic/GameState.cpp.i:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/GameState.cpp.i
.PHONY : Game/Graphic/GameState.cpp.i

Game/Graphic/GameState.s: Game/Graphic/GameState.cpp.s

.PHONY : Game/Graphic/GameState.s

# target to generate assembly for a file
Game/Graphic/GameState.cpp.s:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/GameState.cpp.s
.PHONY : Game/Graphic/GameState.cpp.s

Game/Graphic/Graph.o: Game/Graphic/Graph.cpp.o

.PHONY : Game/Graphic/Graph.o

# target to build an object file
Game/Graphic/Graph.cpp.o:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/Graph.cpp.o
.PHONY : Game/Graphic/Graph.cpp.o

Game/Graphic/Graph.i: Game/Graphic/Graph.cpp.i

.PHONY : Game/Graphic/Graph.i

# target to preprocess a source file
Game/Graphic/Graph.cpp.i:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/Graph.cpp.i
.PHONY : Game/Graphic/Graph.cpp.i

Game/Graphic/Graph.s: Game/Graphic/Graph.cpp.s

.PHONY : Game/Graphic/Graph.s

# target to generate assembly for a file
Game/Graphic/Graph.cpp.s:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/Graph.cpp.s
.PHONY : Game/Graphic/Graph.cpp.s

Game/Graphic/LobbyState.o: Game/Graphic/LobbyState.cpp.o

.PHONY : Game/Graphic/LobbyState.o

# target to build an object file
Game/Graphic/LobbyState.cpp.o:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/LobbyState.cpp.o
.PHONY : Game/Graphic/LobbyState.cpp.o

Game/Graphic/LobbyState.i: Game/Graphic/LobbyState.cpp.i

.PHONY : Game/Graphic/LobbyState.i

# target to preprocess a source file
Game/Graphic/LobbyState.cpp.i:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/LobbyState.cpp.i
.PHONY : Game/Graphic/LobbyState.cpp.i

Game/Graphic/LobbyState.s: Game/Graphic/LobbyState.cpp.s

.PHONY : Game/Graphic/LobbyState.s

# target to generate assembly for a file
Game/Graphic/LobbyState.cpp.s:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/LobbyState.cpp.s
.PHONY : Game/Graphic/LobbyState.cpp.s

Game/Graphic/MenuState.o: Game/Graphic/MenuState.cpp.o

.PHONY : Game/Graphic/MenuState.o

# target to build an object file
Game/Graphic/MenuState.cpp.o:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/MenuState.cpp.o
.PHONY : Game/Graphic/MenuState.cpp.o

Game/Graphic/MenuState.i: Game/Graphic/MenuState.cpp.i

.PHONY : Game/Graphic/MenuState.i

# target to preprocess a source file
Game/Graphic/MenuState.cpp.i:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/MenuState.cpp.i
.PHONY : Game/Graphic/MenuState.cpp.i

Game/Graphic/MenuState.s: Game/Graphic/MenuState.cpp.s

.PHONY : Game/Graphic/MenuState.s

# target to generate assembly for a file
Game/Graphic/MenuState.cpp.s:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/MenuState.cpp.s
.PHONY : Game/Graphic/MenuState.cpp.s

Game/Graphic/StartState.o: Game/Graphic/StartState.cpp.o

.PHONY : Game/Graphic/StartState.o

# target to build an object file
Game/Graphic/StartState.cpp.o:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/StartState.cpp.o
.PHONY : Game/Graphic/StartState.cpp.o

Game/Graphic/StartState.i: Game/Graphic/StartState.cpp.i

.PHONY : Game/Graphic/StartState.i

# target to preprocess a source file
Game/Graphic/StartState.cpp.i:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/StartState.cpp.i
.PHONY : Game/Graphic/StartState.cpp.i

Game/Graphic/StartState.s: Game/Graphic/StartState.cpp.s

.PHONY : Game/Graphic/StartState.s

# target to generate assembly for a file
Game/Graphic/StartState.cpp.s:
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Game/Graphic/StartState.cpp.s
.PHONY : Game/Graphic/StartState.cpp.s

Game/Input/Input.o: Game/Input/Input.cpp.o

.PHONY : Game/Input/Input.o

# target to build an object file
Game/Input/Input.cpp.o:
	$(MAKE) -f CMakeFiles/input.dir/build.make CMakeFiles/input.dir/Game/Input/Input.cpp.o
.PHONY : Game/Input/Input.cpp.o

Game/Input/Input.i: Game/Input/Input.cpp.i

.PHONY : Game/Input/Input.i

# target to preprocess a source file
Game/Input/Input.cpp.i:
	$(MAKE) -f CMakeFiles/input.dir/build.make CMakeFiles/input.dir/Game/Input/Input.cpp.i
.PHONY : Game/Input/Input.cpp.i

Game/Input/Input.s: Game/Input/Input.cpp.s

.PHONY : Game/Input/Input.s

# target to generate assembly for a file
Game/Input/Input.cpp.s:
	$(MAKE) -f CMakeFiles/input.dir/build.make CMakeFiles/input.dir/Game/Input/Input.cpp.s
.PHONY : Game/Input/Input.cpp.s

Game/Sound/Sound.o: Game/Sound/Sound.cpp.o

.PHONY : Game/Sound/Sound.o

# target to build an object file
Game/Sound/Sound.cpp.o:
	$(MAKE) -f CMakeFiles/sound.dir/build.make CMakeFiles/sound.dir/Game/Sound/Sound.cpp.o
.PHONY : Game/Sound/Sound.cpp.o

Game/Sound/Sound.i: Game/Sound/Sound.cpp.i

.PHONY : Game/Sound/Sound.i

# target to preprocess a source file
Game/Sound/Sound.cpp.i:
	$(MAKE) -f CMakeFiles/sound.dir/build.make CMakeFiles/sound.dir/Game/Sound/Sound.cpp.i
.PHONY : Game/Sound/Sound.cpp.i

Game/Sound/Sound.s: Game/Sound/Sound.cpp.s

.PHONY : Game/Sound/Sound.s

# target to generate assembly for a file
Game/Sound/Sound.cpp.s:
	$(MAKE) -f CMakeFiles/sound.dir/build.make CMakeFiles/sound.dir/Game/Sound/Sound.cpp.s
.PHONY : Game/Sound/Sound.cpp.s

Graph/Sfml.o: Graph/Sfml.cpp.o

.PHONY : Graph/Sfml.o

# target to build an object file
Graph/Sfml.cpp.o:
	$(MAKE) -f CMakeFiles/graph.dir/build.make CMakeFiles/graph.dir/Graph/Sfml.cpp.o
.PHONY : Graph/Sfml.cpp.o

Graph/Sfml.i: Graph/Sfml.cpp.i

.PHONY : Graph/Sfml.i

# target to preprocess a source file
Graph/Sfml.cpp.i:
	$(MAKE) -f CMakeFiles/graph.dir/build.make CMakeFiles/graph.dir/Graph/Sfml.cpp.i
.PHONY : Graph/Sfml.cpp.i

Graph/Sfml.s: Graph/Sfml.cpp.s

.PHONY : Graph/Sfml.s

# target to generate assembly for a file
Graph/Sfml.cpp.s:
	$(MAKE) -f CMakeFiles/graph.dir/build.make CMakeFiles/graph.dir/Graph/Sfml.cpp.s
.PHONY : Graph/Sfml.cpp.s

Graph/StarField.o: Graph/StarField.cpp.o

.PHONY : Graph/StarField.o

# target to build an object file
Graph/StarField.cpp.o:
	$(MAKE) -f CMakeFiles/graph.dir/build.make CMakeFiles/graph.dir/Graph/StarField.cpp.o
.PHONY : Graph/StarField.cpp.o

Graph/StarField.i: Graph/StarField.cpp.i

.PHONY : Graph/StarField.i

# target to preprocess a source file
Graph/StarField.cpp.i:
	$(MAKE) -f CMakeFiles/graph.dir/build.make CMakeFiles/graph.dir/Graph/StarField.cpp.i
.PHONY : Graph/StarField.cpp.i

Graph/StarField.s: Graph/StarField.cpp.s

.PHONY : Graph/StarField.s

# target to generate assembly for a file
Graph/StarField.cpp.s:
	$(MAKE) -f CMakeFiles/graph.dir/build.make CMakeFiles/graph.dir/Graph/StarField.cpp.s
.PHONY : Graph/StarField.cpp.s

Server/Game.o: Server/Game.cpp.o

.PHONY : Server/Game.o

# target to build an object file
Server/Game.cpp.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Server/Game.cpp.o
.PHONY : Server/Game.cpp.o

Server/Game.i: Server/Game.cpp.i

.PHONY : Server/Game.i

# target to preprocess a source file
Server/Game.cpp.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Server/Game.cpp.i
.PHONY : Server/Game.cpp.i

Server/Game.s: Server/Game.cpp.s

.PHONY : Server/Game.s

# target to generate assembly for a file
Server/Game.cpp.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Server/Game.cpp.s
.PHONY : Server/Game.cpp.s

Server/Room.o: Server/Room.cpp.o

.PHONY : Server/Room.o

# target to build an object file
Server/Room.cpp.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Server/Room.cpp.o
.PHONY : Server/Room.cpp.o

Server/Room.i: Server/Room.cpp.i

.PHONY : Server/Room.i

# target to preprocess a source file
Server/Room.cpp.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Server/Room.cpp.i
.PHONY : Server/Room.cpp.i

Server/Room.s: Server/Room.cpp.s

.PHONY : Server/Room.s

# target to generate assembly for a file
Server/Room.cpp.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Server/Room.cpp.s
.PHONY : Server/Room.cpp.s

Server/Server.o: Server/Server.cpp.o

.PHONY : Server/Server.o

# target to build an object file
Server/Server.cpp.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Server/Server.cpp.o
.PHONY : Server/Server.cpp.o

Server/Server.i: Server/Server.cpp.i

.PHONY : Server/Server.i

# target to preprocess a source file
Server/Server.cpp.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Server/Server.cpp.i
.PHONY : Server/Server.cpp.i

Server/Server.s: Server/Server.cpp.s

.PHONY : Server/Server.s

# target to generate assembly for a file
Server/Server.cpp.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Server/Server.cpp.s
.PHONY : Server/Server.cpp.s

Server/main.o: Server/main.cpp.o

.PHONY : Server/main.o

# target to build an object file
Server/main.cpp.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Server/main.cpp.o
.PHONY : Server/main.cpp.o

Server/main.i: Server/main.cpp.i

.PHONY : Server/main.i

# target to preprocess a source file
Server/main.cpp.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Server/main.cpp.i
.PHONY : Server/main.cpp.i

Server/main.s: Server/main.cpp.s

.PHONY : Server/main.s

# target to generate assembly for a file
Server/main.cpp.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/Server/main.cpp.s
.PHONY : Server/main.cpp.s

Tools/Tools.o: Tools/Tools.cpp.o

.PHONY : Tools/Tools.o

# target to build an object file
Tools/Tools.cpp.o:
	$(MAKE) -f CMakeFiles/input.dir/build.make CMakeFiles/input.dir/Tools/Tools.cpp.o
	$(MAKE) -f CMakeFiles/graph.dir/build.make CMakeFiles/graph.dir/Tools/Tools.cpp.o
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Tools/Tools.cpp.o
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Tools/Tools.cpp.o
	$(MAKE) -f CMakeFiles/sound.dir/build.make CMakeFiles/sound.dir/Tools/Tools.cpp.o
.PHONY : Tools/Tools.cpp.o

Tools/Tools.i: Tools/Tools.cpp.i

.PHONY : Tools/Tools.i

# target to preprocess a source file
Tools/Tools.cpp.i:
	$(MAKE) -f CMakeFiles/input.dir/build.make CMakeFiles/input.dir/Tools/Tools.cpp.i
	$(MAKE) -f CMakeFiles/graph.dir/build.make CMakeFiles/graph.dir/Tools/Tools.cpp.i
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Tools/Tools.cpp.i
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Tools/Tools.cpp.i
	$(MAKE) -f CMakeFiles/sound.dir/build.make CMakeFiles/sound.dir/Tools/Tools.cpp.i
.PHONY : Tools/Tools.cpp.i

Tools/Tools.s: Tools/Tools.cpp.s

.PHONY : Tools/Tools.s

# target to generate assembly for a file
Tools/Tools.cpp.s:
	$(MAKE) -f CMakeFiles/input.dir/build.make CMakeFiles/input.dir/Tools/Tools.cpp.s
	$(MAKE) -f CMakeFiles/graph.dir/build.make CMakeFiles/graph.dir/Tools/Tools.cpp.s
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Tools/Tools.cpp.s
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/Tools/Tools.cpp.s
	$(MAKE) -f CMakeFiles/sound.dir/build.make CMakeFiles/sound.dir/Tools/Tools.cpp.s
.PHONY : Tools/Tools.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... server"
	@echo "... input"
	@echo "... graph"
	@echo "... client"
	@echo "... game"
	@echo "... sound"
	@echo "... Client/Client.o"
	@echo "... Client/Client.i"
	@echo "... Client/Client.s"
	@echo "... Client/Graphic.o"
	@echo "... Client/Graphic.i"
	@echo "... Client/Graphic.s"
	@echo "... Client/Network.o"
	@echo "... Client/Network.i"
	@echo "... Client/Network.s"
	@echo "... Client/System.o"
	@echo "... Client/System.i"
	@echo "... Client/System.s"
	@echo "... Client/main.o"
	@echo "... Client/main.i"
	@echo "... Client/main.s"
	@echo "... Client/tmp.o"
	@echo "... Client/tmp.i"
	@echo "... Client/tmp.s"
	@echo "... Common/Player.o"
	@echo "... Common/Player.i"
	@echo "... Common/Player.s"
	@echo "... Game/Graphic/CreditState.o"
	@echo "... Game/Graphic/CreditState.i"
	@echo "... Game/Graphic/CreditState.s"
	@echo "... Game/Graphic/GameState.o"
	@echo "... Game/Graphic/GameState.i"
	@echo "... Game/Graphic/GameState.s"
	@echo "... Game/Graphic/Graph.o"
	@echo "... Game/Graphic/Graph.i"
	@echo "... Game/Graphic/Graph.s"
	@echo "... Game/Graphic/LobbyState.o"
	@echo "... Game/Graphic/LobbyState.i"
	@echo "... Game/Graphic/LobbyState.s"
	@echo "... Game/Graphic/MenuState.o"
	@echo "... Game/Graphic/MenuState.i"
	@echo "... Game/Graphic/MenuState.s"
	@echo "... Game/Graphic/StartState.o"
	@echo "... Game/Graphic/StartState.i"
	@echo "... Game/Graphic/StartState.s"
	@echo "... Game/Input/Input.o"
	@echo "... Game/Input/Input.i"
	@echo "... Game/Input/Input.s"
	@echo "... Game/Sound/Sound.o"
	@echo "... Game/Sound/Sound.i"
	@echo "... Game/Sound/Sound.s"
	@echo "... Graph/Sfml.o"
	@echo "... Graph/Sfml.i"
	@echo "... Graph/Sfml.s"
	@echo "... Graph/StarField.o"
	@echo "... Graph/StarField.i"
	@echo "... Graph/StarField.s"
	@echo "... Server/Game.o"
	@echo "... Server/Game.i"
	@echo "... Server/Game.s"
	@echo "... Server/Room.o"
	@echo "... Server/Room.i"
	@echo "... Server/Room.s"
	@echo "... Server/Server.o"
	@echo "... Server/Server.i"
	@echo "... Server/Server.s"
	@echo "... Server/main.o"
	@echo "... Server/main.i"
	@echo "... Server/main.s"
	@echo "... Tools/Tools.o"
	@echo "... Tools/Tools.i"
	@echo "... Tools/Tools.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

