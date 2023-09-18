cmake_minimum_required(VERSION 3.16)

project(AlphaDash VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)


find_package(Qt6 6.4 REQUIRED COMPONENTS Core Quick QuickControls2 SerialPort Qml)

qt_standard_project_setup()

qt_add_executable(appAlphaDash
    src/main.cpp
)

qt_add_qml_module(appAlphaDash
    URI AlphaDash
    VERSION 1.0
    QML_FILES qml_main/Main.qml
    QML_FILES qml_main/MiddleBarInfo.qml
    QML_FILES qml_main/TopBarInfo.qml
    QML_FILES qml_main/BottomBarInfo.qml
    QML_FILES qml_main/RadialShape.qml
    QML_FILES qml_main/SpeedInfo.qml
    QML_FILES qml_main/RPMInfo.qml
    RESOURCES
            img/left-arrow3.png
            img/car-battery.png
            img/engine.png
            img/beam.png
            img/high_beam.png
            img/brake.png
            img/car-battery.png
            img/coolant_cold.png
            img/coolant_overheat.png
            img/low_fuel.png
            img/low_oil_pressure.png
    SOURCES include/middlebar.h src/middlebar.cpp
    SOURCES include/serialInfo.h src/serialInfo.cpp
    SOURCES include/serialdatatransmit.h src/serialdatatransmit.cpp


)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appAlphaDash PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appAlphaDash
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appAlphaDash
    PRIVATE Qt6::Core
    PRIVATE Qt6::Quick
    PRIVATE Qt6::QuickControls2
    PRIVATE Qt6::SerialPort
    PRIVATE Qt6::Qml

)

include(GNUInstallDirs)
install(TARGETS appAlphaDash
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
