#include "HashTableCellWidget.hpp"
#include "ui_HashTableCellWidget.hpp"

HashTableCellWidget::HashTableCellWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HashTableCellWidget)
{
    ui->setupUi(this);
    connect(ui->lineEdit_value, &QLineEdit::editingFinished, this, [this]() {
        emit valueChanged(this);
    });

}

HashTableCellWidget::~HashTableCellWidget()
{
    delete ui;
}

int HashTableCellWidget::key() const
{
    return ui->label_keyValue->text().toInt();
}

QString HashTableCellWidget::value() const
{
    return ui->lineEdit_value->text();
}

void HashTableCellWidget::setKey(int key) {
    if(key < 0) {
        ui->label_keyValue->clear();
        return;
    }

    ui->label_keyValue->setText(QString::number(key));
}

void HashTableCellWidget::setValue(const QString &value)
{
    ui->lineEdit_value->setText(value);
}
