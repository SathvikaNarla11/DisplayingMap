#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    webView(new QWebEngineView(this)) {
    ui->setupUi(this);

    // Set up QWebEngineView
    setCentralWidget(webView);
    // webView->setUrl(QUrl("https://www.google.com/maps"));
    webView->setUrl(QUrl("C:/Users/DT_Server/Documents/QT-Tasks/QtNavigationMap/autoplayvideo/jsonHtml/index.html"));


    // Button click logic to get directions
    connect(ui->getDirectionsButton, &QPushButton::clicked, this, &MainWindow::getDirections);
}

MainWindow::~MainWindow() {
    delete ui;
    delete webView;
}

void MainWindow::getDirections() {
    QString from = ui->fromLineEdit->text();
    QString to = ui->toLineEdit->text();

    // Construct the Google Maps Directions API URL
    QString url = QString("https://www.google.com/maps/dir/?api=1&origin=%1&destination=%2")
                      .arg(from)
                      .arg(to);

    // QString url = QString("C:/Users/DT_Server/Documents/QT-Tasks/QtNavigationMap/autoplayvideo/coordinates.json")
    //                   .arg(from)
    //                   .arg(to);

    // QString url = QString("C:/Users/DT_Server/Documents/QT-Tasks/QtNavigationMap/autoplayvideo/jsonHtml/index.html")
    //                   .arg(from)
    //                   .arg(to);

    // Load the directions in the QWebEngineView
    webView->setUrl(QUrl(url));
}
















// #include "mainwindow.h"
// #include "ui_mainwindow.h"

// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::MainWindow)
// {
//     ui->setupUi(this);
// }

// MainWindow::~MainWindow()
// {
//     delete ui;
// }
