cmake_minimum_required(VERSION 3.17)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}) #for the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}) #for static library
set(SOURCES_FILES
        Adresse.cpp Candidat.cpp Date.cpp Personne.cpp validationFormat.cpp ContratException.cpp
        Electeur.cpp Electeur.h)
add_library(Untitled4 STATIC ${SOURCES_FILES})
#add_executable(main main.cpp test.cpp)
#target_link_libraries(main Untitled4)
