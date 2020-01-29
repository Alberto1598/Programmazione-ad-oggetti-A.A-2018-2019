#ifndef FORM_H
#define FORM_H
#include <QFormLayout>
#include <QGroupBox>
#include "QWidget"

class form : public QFormLayout{
    Q_OBJECT
public:
      form(QWidget* =nullptr);
private:
      QWidget* parent;
 };

#endif // FORM_H
