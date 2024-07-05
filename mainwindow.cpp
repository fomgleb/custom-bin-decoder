#include "mainwindow.h"

#include "ui_mainwindow.h"

namespace lua = custom_bin_decoder::lua_script;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_decodePushButton_clicked() {
  std::string binary_number = ui->binaryNumberLineEdit->text().toStdString();
  std::string lua_code = ui->scriptTextEdit->toPlainText().toStdString();
  std::string decoded_result = lua::Decode(binary_number, lua_code);
  ui->resultTextBrowser->setText(QString::fromStdString(decoded_result));
}
