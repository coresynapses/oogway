cmake_minimum_required(VERSION 3.18)
project(Oogway LANGUAGES CXX)

set(BUILD_DIR "build/")
set(CMAKE_AUTOMOC_ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

qt_standard_project_setup(REQUIRES 6.6)

add_subdirectory(Login)

qt_add_executable(oogway
  src/main.cpp
)

qt_add_qml_module(Oogway
  URI oogway
  VERSION 1.0
  QML_FILES "main.qml"
  DEPENDENCIES QtQuick
)

# qt_add_qml_module(database
#   URI Db
#   VERSION 0.1
#   SOURCES
#       src/db.cpp
#       src/db.hpp
#   QML_FILES
#       "db.qml"
#   DEPENDENCIES QtQuick
# )

target_link_libraries(oogway PRIVATE
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
  Login
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
