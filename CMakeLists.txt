cmake_minimum_required(VERSION 3.18)
project(Oogway LANGUAGES CXX)

set(BUILD_DIR "build/")
set(CMAKE_AUTOMOC_ON)

find_package(Qt6 6.6 REQUIRED COMPONENTS
  Core
  Gui
  Widgets
  UiTools
  Pdf
  Qml
  Quick
  QuickControls2
  QuickControls2
)

qt_standard_project_setup(REQUIRES 6.6)

qt_add_executable(oogway
  src/main.cpp
  forms/calculatorform.ui
)

qt_add_qml_module(Oogway
  URI oogway
  VERSION 0.1
  QML_FILES "main.qml"
)

# qt_add_resources(Oogway  "configuration"
#   PREFIX "/"
#   FILES qtquickcontrols2.conf
# )

#include(qmlmodules.cmake)

target_link_libraries(oogway PRIVATE
  Qt6::Core
  Qt6::Gui
  Qt6::Widgets
  Qt6::UiTools
  Qt6::Pdf
  Qt6::Qml
  Qt6::Quick
  Qt6::QuickControls2
)

install(TARGETS oogway
  RUNTIME DESTINATION "${BUILD_DIR}"
  BUNDLE DESTINATION "${BUILD_DIR}"
  LIBRARY DESTINATION "${BUILD_DIR}"
)

set_target_properties(oogway PROPERTIES
  WIN32_EXECUTABLE ON
  MACOSX_BUNDLE ON
)
