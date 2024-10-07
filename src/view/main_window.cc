/**
 * @file main_window.cc
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-10-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/main_window.h"

MainWindow::MainWindow() : QWidget{} {
  allocateMemory();
  initView();
}

MainWindow::~MainWindow() { delete data_; }

void MainWindow::allocateMemory() {
  left_menu = new QGridLayout;
  path_ = new PathReader;
  scene_ = new ObjectScene;
  rotate_ = new AfinneData{new QLabel{"Rotate"}, {"X", "Y", "Z"}, -360, 360};
  scale_ = new AfinneData{new QLabel{"Scale"}, {"%"}, 1, 600, 100};
  move_ = new AfinneData{new QLabel{"Translate"}, {"X", "Y", "Z"}, -100, 100};
  figure_ = new ObjectData;
  setting_ = new SceneData{new QLabel{"Scene"}};
  function_ = new Function;
  data_ = new Data;
}

void MainWindow::initView() {
  QGridLayout *grid{new QGridLayout};
  setLayout(grid);
  setStyleSheet(Style::kWindowStyle);

  left_menu->addWidget(rotate_);
  left_menu->addWidget(scale_);
  left_menu->addWidget(move_);
  left_menu->addWidget(setting_);
  left_menu->addWidget(figure_);
  grid->addLayout(left_menu, 0, 0, 2, 1, Qt::AlignTop);
  grid->addWidget(path_, 0, 1);
  grid->addWidget(scene_, 1, 1, 3, 1);
  grid->addWidget(function_, 2, 0, 2, 1, Qt::AlignBottom);

  rotate_->setFixedSize(310, 160);
  move_->setFixedSize(310, 160);
  scale_->setFixedSize(310, 90);
  path_->setFixedHeight(60);
  setting_->setFixedSize(310, 190);
  figure_->setFixedSize(310, 190);

  QPushButton *temp{new QPushButton{"temp"}};
  left_menu->addWidget(temp);
  connect(temp, &QPushButton::clicked, this, &MainWindow::objectData);

  connect(path_, &PathReader::valid, scene_, &ObjectScene::drawScene);
  connect(function_, &Function::imageSave, scene_, &ObjectScene::imageSave);
  connect(function_, &Function::gifSave, scene_, &ObjectScene::gifSave);
  connect(function_, &Function::clear, scene_, &ObjectScene::clearScene);
  connect(function_, &Function::reset, scene_, &ObjectScene::resetObject);
}

Data *MainWindow::objectData() {
  rotate_->recordData(data_);
  scale_->recordData(data_);
  move_->recordData(data_);
  setting_->recordData(data_);
  figure_->recordData(data_);
  path_->recordData(data_);

  return data_;
}
