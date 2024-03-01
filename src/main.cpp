#include <bits/stdc++.h>
#include <iostream>
#include <memory>

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

using namespace std;

// class OogwayControl : public QObject {
//   Q_OBJECT
//   QML_ELEMENT
//   QML_SINGLETON

//   public:
//   Q_INVOKABLE void writeToFile() {
//     cout << "clicked" << endl;
//   }
// };

static QWidget* loadCalculatorForm(QWidget* parent = nullptr) {

  QUiLoader loader;

  QFile file("../forms/calculatorform.ui");

  if(!file.open(QFile::ReadOnly)) {
    std::cout << "File for UI not found.\n";
    return nullptr;
  }

  QWidget *formWidget = loader.load(&file, parent);

  file.close();

  if(!formWidget)
    return nullptr;

  auto *inputSpinBox1 = formWidget->findChild<QSpinBox*>("inputSpinBox1");
  auto *inputSpinBox2 = formWidget->findChild<QSpinBox*>("inputSpinBox2");
  auto *outputWidget = formWidget->findChild<QLabel*>("outputWidget");


  auto updateResult = [inputSpinBox1, inputSpinBox2, outputWidget]() {
    const int sum = inputSpinBox1->value() + inputSpinBox2->value();
    outputWidget->setText(QString::number(sum));
  };

  QObject::connect(inputSpinBox1, &QSpinBox::valueChanged, formWidget, updateResult);
  QObject::connect(inputSpinBox2, &QSpinBox::valueChanged, formWidget, updateResult);

  return formWidget;
}

int main(int argc, char** argv) {
  cout << "Oogway\n";

  sqlite3* db;
  int rc = sqlite3_open("oogway.db", &db);
  if (rc)
    cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
  else
    cout << "Databased opened\n";
  sqlite3_close(db);

  if(sodium_init() == -1) {
    cout << "Sodium initialization failed\n";
  } else {
    cout << "Sodium initialization succeeded\n";
  }
  
  QApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
  QCoreApplication::setOrganizationName("Core Synapses");
  QCoreApplication::setApplicationName("Oogway");

  // NOTE: This code loads a .ui file and renders it
  // QApplication app(argc, argv);

  // QWidget w;
  // auto* formWidget = loadCalculatorForm(&w);

  // if(!formWidget)
  //   return -1;

  // auto* layout = new QVBoxLayout(&w);
  // layout->addWidget(formWidget);

  // w.setWindowTitle(QCoreApplication::translate("Oogway", "Oogway"));
  // w.show();


  // This code loads .qml file and renders it
  QGuiApplication app(argc, argv);

  QQuickStyle::setStyle("Basic");

  // NOTE: QQuickView does not support using a window as a root item.
  //       Need to use QQmlApplicationEngine.
  // QQuickView view;
  // view.connect(view.engine(), &QQmlEngine::quit, &app, &QCoreApplication::quit);
  // view.setSource(QUrl("../main.qml"));
  // if(view.status() == QQuickView::Error) {
  //   cout << view.status() << ": Error\n";
  //   return -1;
  // }
  // view.setResizeMode(QQuickView::SizeRootObjectToView);
  // view.show();

  QQmlApplicationEngine eng;
  eng.load(QUrl("../main.qml"));

  if(eng.rootObjects().isEmpty())
    return -1;


  return app.exec();
}
