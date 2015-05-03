cmake_minimum_required(VERSION 3.1)
project(catrpg)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -D__NO_INLINE__")
set(EXEC_NAME "catrpg")

# Detect and add SFML
set(CMAKE_MODULE_PATH "C:/Program Files (x86)/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
set(SFML_ROOT "C:/Program Files (x86)/SFML/") # You will probably have to change this
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR} ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES
    src/main.cpp
    src/resources/resourceHolder.hpp
    src/resources/resourceHolder.inl
    src/resources/resourceIdentifiers.hpp
    src/objects/aircraft.cpp
    src/objects/aircraft.h
    src/scene/sceneNode.cpp
    src/scene/sceneNode.h
    src/entity/entity.cpp
    src/entity/entity.h
    src/scene/world.h
    src/scene/world.cpp
    src/game/spriteNode.cpp
    src/game/spriteNode.h
    src/command/command.h
    src/command/command.cpp
    src/objects/categories.h
    src/command/CommandQueue.h
    src/command/CommandQueue.cpp
    src/player.h
    src/player.cpp
    src/stateArchitecture/stateStack.h
    src/stateArchitecture/stateStack.cpp
    src/stateArchitecture/state.h
    src/stateArchitecture/state.cpp
    src/stateArchitecture/stateIdentifiers.h
    src/stateArchitecture/application.h
    src/stateArchitecture/application.cpp
    src/states/titleState.cpp
    src/states/titleState.h
    src/states/menuState.cpp
    src/states/menuState.h
    src/states/gameState.cpp
    src/states/gameState.h
    src/states/pauseState.cpp
    src/states/pauseState.h
    src/helpers/utility.cpp
    src/helpers/utility.h
    src/helpers/utility.inl
    src/states/loadingState.h
    src/states/loadingState.cpp
    src/asyncTasks/parallelTask.h
    src/asyncTasks/parallelTask.cpp
    src/gui/component.h
    src/gui/component.cpp
    src/gui/container.h
    src/gui/container.cpp
    src/gui/button.h
    src/gui/button.cpp
    src/states/settingState.h
    src/states/settingState.cpp
    src/gui/label.h
    src/gui/label.cpp
    src/entity/dataTables.h
    src/entity/dataTables.cpp
    src/objects/pickup.h
    src/objects/pickup.cpp
    src/objects/projectile.h
    src/objects/projectile.cpp
    )
add_executable(${EXEC_NAME} ${SOURCE_FILES} src/scene/textNode.h src/scene/textNode.cpp src/states/gameOverState.h src/states/gameOverState.cpp)
target_link_libraries(${EXEC_NAME} ${SFML_LIBRARIES})
target_link_libraries(${EXEC_NAME} -static-libgcc)
target_link_libraries(${EXEC_NAME} -static-libstdc++)

INSTALL(DIRECTORY ${CMAKE_SOURCE_DIR}/resources/ DESTINATION ${CMAKE_BINARY_DIR}/resources)
INSTALL(DIRECTORY ${CMAKE_SOURCE_DIR}/dll/ DESTINATION ${CMAKE_BINARY_DIR}/)
