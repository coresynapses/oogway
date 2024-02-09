#include <iostream>
#include <memory>

#include <QtUiTools>

#include <QApplication>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>

#include <QFile>

// static QWidget* loadCalculatorForm(QWidget* parent = nullptr) {
//   QtUiLoader loader;

//   QFile file(u":/forms/calculatorform.ui"_s);

//   if(!file.open(QFile::ReadOnly))
//     return nullptr;

//   QWidget *formWidget = loader.load(&file, parent);

//   file.close();

//   if(!formWidget)
//     return nullptr;

//   auto *inputSpinBox1 = formWidget->findChild<QSpinBox*>(u"inputSpinBox1"_s);
//   auto *inputSpinBox2 = formWidget->findChild<QSpinBox*>(u"inputSpinBox2"_s);
//   auto *outputWidget = formWidget->findChild<QLabel*>(u"oututWidget"_s);


//   auto updateResult = [inputSpinBox1, inputSpinBox2, outputWidget]() {
//     const int sum = inputSpinBox1->value() + inputSpinBox2->value();
//     outputWidget->SetText(QString::number(sum));
//   };

//   QObject::connect(inputSpinBox1, &QSpinBox::valueChanged, formWidget, updateResult);
//   QObject::connect(inputSpinBox2, &QSpinBox::valueChanged, formWidget, updateResult);

//   return formWidget;
// }
  

using namespace std;

int main(int argc, char** argv) {
  cout << "Oogway\n";
  
  QApplication app(argc, argv);

  return 0;
}
