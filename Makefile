oogway:
	g++ src/main.cpp \
		-I/usr/include/qt6/QtUiTools \
		-I/usr/include/qt6 \
		-DQT_UITOOLS_LIB \
		-I/usr/include/qt6/QtOpenGLWidgets \
		-DQT_OPENGLWIDGETS_LIB \
		-I/usr/include/qt6/QtOpenGL \
		-DQT_OPENGL_LIB \
		-I/usr/include/qt6/QtWidgets \
		-DQT_WIDGETS_LIB \
		-I/usr/include/qt6/QtGui \
		-DQT_GUI_LIB \
		-I/usr/include/qt6/QtCore \
		-DQT_CORE_LIB \
		-I/usr/lib/qt6/mkspecs/linux-g++ \
		-lQt6Gui -lQt6Core -lQt6UiTools \
		-o build/oogway
