cmake_minimum_required(VERSION 3.16)
project(Login LANGUAGES CXX)

set(CMAKE_AUTOMOC_ON)

find_package(Qt6 REQUIRED COMPONENTS
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

find_package(Boost REQUIRED COMPONENTS
  system
)

find_package(PkgConfig REQUIRED)

pkg_check_modules(sodium_PKG REQUIRED libsodium)
pkg_check_modules(sqlite3_PKG REQUIRED sqlite3)
pkg_check_modules(libcryptopp_PKG REQUIRED libcryptopp)

include_directories(${SODIUM_INCLUDE_DIR})
include_directories(${sqlite3_INCLUDE_DIR})
include_directories(${libcryptopp_PKG_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIRS})
  
# set_source_properties(
#   Db.qml
#   Properties
#   QT_QML_SINGLETON TRUE
# )

qt_add_qml_module(${PROJECT_NAME}
  URI LightningViewer
  VERSION 1.0
  SOURCES 
    db.cpp db.hpp
  QML_FILES
    db.qml
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  Qt6::Core
  Qt6::Gui
  Qt6::Widgets
  Qt6::UiTools
  Qt6::Pdf
  Qt6::Qml
  Qt6::Quick
  Qt6::QuickControls2
  ${sodium_PKG_LIBRARIES}
  ${sqlite3_PKG_LIBRARIES}
  ${libcryptopp_PKG_LIBRARIES}
  ${Boost_LIBRARIES}
)
