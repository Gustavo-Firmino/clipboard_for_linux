cmake_minimum_required(VERSION 3.10)
project(CopyCAT)
set(CMAKE_CXX_STANDARD 17)

# Qt5
set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/Qt5")
find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(X11 REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(CopyCAT
        main.cpp
        CopyCATWindow.cpp
        CopyCATWindow.h
        CopyCAT.ui
        Modules/ApplicationConfigs/Configs.cpp
        Modules/ApplicationConfigs/Configs.h
        Modules/History/History.cpp
        Modules/History/History.h
        Modules/Data/Data.cpp
        Modules/Data/Data.h
        worker.cpp
        worker.h
)

target_link_libraries(CopyCAT
        Qt5::Widgets
        ${X11_LIBRARIES}
)
target_include_directories(CopyCAT PRIVATE ${X11_INCLUDE_DIR})