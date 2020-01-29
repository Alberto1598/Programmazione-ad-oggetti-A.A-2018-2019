#include "form.h"
#include "QWidget"

form::form(QWidget* f): parent(f){
        setRowWrapPolicy(QFormLayout::DontWrapRows);
        setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        setFormAlignment(Qt::AlignLeft | Qt::AlignTop);
        setLabelAlignment(Qt::AlignLeft);
}


