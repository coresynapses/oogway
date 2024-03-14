#include <bits/stdc++.h>

#include <QObject>
#include <QtUiTools>
#include <QApplication>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QFile>

#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <QQmlFileSelector>
#include <QQuickView>
#include <QQuickStyle>

#include <sodium.h>
#include <sqlite3.h>
#include <cryptopp/rsa.h>

#include <boost/asio.hpp>
#include <boost/beast.hpp>

int main(int argc, char** argv) {
    
    std::cout << "Oogway\n";
    
    QApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QCoreApplication::setOrganizationName("Core Synapses");
    QCoreApplication::setApplicationName("Oogway");
    
    QGuiApplication app(argc, argv);
    
    QQuickStyle::setStyle("Basic");
    
    QQmlApplicationEngine eng;
    eng.load(QUrl("../main.qml"));
    
    if(eng.rootObjects().isEmpty())
	return -1;
    
    
    return app.exec();
}
