#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QProgressBar>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QSizePolicy>
#include <QFont>
#include <QCheckBox>
#include <QTextEdit>

void MainWindow::MainWindow_ui_Init()
{
	// 窗口基本属性
	this->setWindowTitle("McuDownloader (open source address:github.com/ByZwc/McuDownLoaderForCortex-M) ");
	this->resize(600, 400);

	// 中心背景（浅灰 RGB(240,240,240)）
	if (ui && ui->centralwidget) {
		ui->centralwidget->setStyleSheet("background-color: rgba(240, 240, 240, 0.5);");
	}

	// 主布局
	auto *mainLayout = new QVBoxLayout(ui->centralwidget);
	mainLayout->setContentsMargins(8, 8, 8, 8);
	mainLayout->setSpacing(8);

	// 顶部行：选择芯片、端口、波特率
	{
		auto *topRow = new QHBoxLayout();
		topRow->setSpacing(8);

		auto *lblChip = new QLabel("选择芯片:", ui->centralwidget);
		lblChip->setFixedWidth(60);
        //设置标签字体颜色为黑色
        lblChip->setStyleSheet("color: black;");
        //设置标签背景为透明
        lblChip->setAttribute(Qt::WA_TranslucentBackground);
		lblChip->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

		auto *comboChip = new QComboBox(ui->centralwidget);
		comboChip->addItem("Py32F403");
		comboChip->setMinimumWidth(140);
        comboChip->setStyleSheet("QComboBox{color: black; background:rgba(240, 240, 240, 0.5); border:1px solid #a0a0a0;}QComboBox:hover{background:rgba(255, 0, 0, 0.3);}QComboBox QAbstractItemView{color: black; background: rgba(255, 0, 0, 0.3);}");

		auto *lblPort = new QLabel("端口号:", ui->centralwidget);
		lblPort->setFixedWidth(60);
        //设置标签字体颜色为黑色
        lblPort->setStyleSheet("color: black;");
        //设置标签背景为透明
        lblPort->setAttribute(Qt::WA_TranslucentBackground);
		lblPort->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

		auto *comboPort = new QComboBox(ui->centralwidget);
		comboPort->addItem("COM9 Prolific USB-to-Serial Comm Port");
		comboPort->setMinimumWidth(260);
        comboPort->setStyleSheet("QComboBox{color: black; background:rgba(240, 240, 240, 0.5); border:1px solid #a0a0a0;}QComboBox:hover{background:rgba(255, 0, 0, 0.3);}QComboBox QAbstractItemView{color: black; background: rgba(255, 0, 0, 0.3);}");
		auto *lblBaud = new QLabel("波特率:", ui->centralwidget);
		lblBaud->setFixedWidth(60);
        //设置标签字体颜色为黑色
        lblBaud->setStyleSheet("color: black;");
        //设置标签背景为透明
        lblBaud->setAttribute(Qt::WA_TranslucentBackground);
		lblBaud->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

		auto *comboBaud = new QComboBox(ui->centralwidget);
		comboBaud->addItems(QStringList() << "115200" << "57600" << "9600");
		comboBaud->setFixedWidth(90);
        comboBaud->setStyleSheet("QComboBox{color: black; background:rgba(240, 240, 240, 0.5); border:1px solid #a0a0a0;}QComboBox:hover{background:rgba(255, 0, 0, 0.3);}QComboBox QAbstractItemView{color: black; background: rgba(255, 0, 0, 0.3);}");
		topRow->addWidget(lblChip);
		topRow->addWidget(comboChip);
		topRow->addSpacing(6);
		topRow->addWidget(lblPort);
		topRow->addWidget(comboPort);
		topRow->addSpacing(6);
		topRow->addWidget(lblBaud);
		topRow->addWidget(comboBaud);
		topRow->addStretch(1);

		mainLayout->addLayout(topRow);
	}

	// 固件路径行：LineEdit + 选择固件 + 下载固件
	{
		auto *fileRow = new QHBoxLayout();
		fileRow->setSpacing(8);

		auto *lineFile = new QLineEdit(ui->centralwidget);
		lineFile->setPlaceholderText("C:/Users/hello/Desktop/LED.bin");
		lineFile->setStyleSheet("QLineEdit{color: black;background:rgba(240, 240, 240, 0.5); border:1px solid #a0a0a0;}");
		lineFile->setMinimumWidth(380);
		lineFile->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

		auto *btnSelect = new QPushButton("选择固件", ui->centralwidget);
		btnSelect->setFixedSize(90, 26);
        //设置按钮字体颜色为黑色
        btnSelect->setStyleSheet("QPushButton{color: black; background: rgba(240, 240, 240, 0.5); border:1px solid #888888; border-radius: 5px;} QPushButton:hover{background: rgba(255, 0, 0, 0.5);}");

		auto *btnDownload = new QPushButton("下载固件", ui->centralwidget);
		btnDownload->setFixedSize(90, 26);
        //添加鼠标悬停效果
        //设置按钮字体颜色为黑色
        btnDownload->setStyleSheet("QPushButton{color: black; background: rgba(240, 240, 240, 0.5); border:1px solid #888888; border-radius: 5px;} QPushButton:hover{background: rgba(255, 0, 0, 0.5);}");

		fileRow->addWidget(lineFile);
		fileRow->addWidget(btnSelect);
		fileRow->addWidget(btnDownload);
		mainLayout->addLayout(fileRow);
	}

	// 进度条（绿色）位于文件行下方
	{
		auto *progress = new QProgressBar(ui->centralwidget);
		progress->setRange(0, 100);
		progress->setValue(0);
		progress->setTextVisible(true);
		progress->setFixedHeight(16);
		progress->setStyleSheet(
			"QProgressBar{border:1px solid #a0a0a0; background: rgba(240, 240, 240, 0.5); color: black;}"
			"QProgressBar::chunk{background: #3cae3c;}"
		);
        //设置数字显示在右边
		progress->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
		mainLayout->addWidget(progress);
	}

	// 日志区：大文本框，占满剩余空间
	{
		auto *logText = new QTextEdit(ui->centralwidget);
		logText->setReadOnly(true);
		logText->setStyleSheet("background:white; border:1px solid #a0a0a0; font-family:monospace;");
		QFont mono;
		mono.setFamily("Courier");
		mono.setPointSize(10);
		logText->setFont(mono);
		logText->setPlainText(
			">>> 检查固件... C:/Users/hello/Desktop/LED.bin\n"
			">>> 打开固件... C:/Users/hello/Desktop/LED.bin\n"
			">>> 固件大小: 4884字节\n"
			">>> ...\n"
		);
        //设置日志字体颜色为黑色
        logText->setStyleSheet("color: black;");
		logText->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		mainLayout->addWidget(logText);
	}
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow_ui_Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

