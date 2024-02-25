#include <iostream>
#include <memory>

#include <QtUiTools>
#include <QApplication>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QFile>

using namespace std;

static QWidget* loadCalculatorForm(QWidget* parent = nullptr) {

  QUiLoader loader;

  QFile file("forms/calculatorform.ui");

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
  
  // QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
  // QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
  QApplication app(argc, argv);
  QWidget w;

  auto* formWidget = loadCalculatorForm(&w);

  if(!formWidget)
    return -1;

  auto* layout = new QVBoxLayout(&w);
  layout->addWidget(formWidget);

  w.setWindowTitle(QCoreApplication::translate("Oogway", "Oogway"));
  w.show();

  return app.exec();
}

