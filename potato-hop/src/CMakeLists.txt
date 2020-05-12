# src/CMakeLists.txt


include_directories(include)

#add_definitions( -DINSTALL_DIRECTORY=\"${CMAKE_SOURCE_DIR}\" )


add_executable(potato-hop
    include/potatoboard.hpp
    include/potatosolver.hpp
    potatoboard.cpp
    potatosolver.cpp
    main.cpp

    )

