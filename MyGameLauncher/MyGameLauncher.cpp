#include <QApplication>
#include <QDebug>
#include <TitleBar.h>
#include <QFileDialog>
#include "../global_common.h"
#include "../UIComponent/CommonUi.hpp"
#include "../UIComponent/UIFactory.h"
#include "MyGameLauncher.h"

MyGameLauncher::MyGameLauncher(QWidget* parent)
	: QMainWindow(parent)
{
	setWindowFlags(Qt::FramelessWindowHint);

	ui.setupUi(this);

	initLayout();
	connection();
}

MyGameLauncher::~MyGameLauncher()
{
	clearFriendList();
}

void MyGameLauncher::connection()
{
	connect(ui.toolButton_hide, &QToolButton::clicked, this, [=]() { titlebar_->OnWindowsHideButtonClicked(); });
	connect(ui.toolButton_resize, &QToolButton::clicked, this, [=]() { titlebar_->OnWindowsSizeButtonClicked(ui.toolButton_resize); });
	connect(ui.toolButton_exit, &QToolButton::clicked, this, [=]() {QApplication::exit(); });

	connect(ui.pushButton_down_, &QPushButton::clicked, this, &MyGameLauncher::slotDownButton);
	connect(ui.pushButton_delete_, &QPushButton::clicked, this, &MyGameLauncher::slotDeleteButton);
	connect(ui.pushButton_dir_, &QPushButton::clicked, this, &MyGameLauncher::slotSetDirButton);
}

void MyGameLauncher::initLayout()
{
	titlebar_ = new TitleBar();
	titlebar_->SetButtonStyle(ui.toolButton_hide, ui.toolButton_resize, ui.toolButton_exit);
	QHBoxLayout* layout = static_cast<QHBoxLayout*>(ui.titlebar_widget_->layout());
	layout->insertWidget(0, titlebar_);

	ui.login_status_widget_->setStyleSheet("border:1px solid red;");
	ui.game_list_widget_->setStyleSheet("border:1px solid green;");
	ui.main_widget_->setStyleSheet("border:1px solid blue;");

	//UI
	GameSelectorButton* mobile_game_bt_ = new GameSelectorButton();
	mobile_game_bt_->setText(_kor("����� ����"));
	connect(mobile_game_bt_, &GameSelectorButton::clicked, [=]() { slotGameSelectButton(mobile_game_bt_); });

	GameSelectorButton* pc_game_bt_ = new GameSelectorButton();
	pc_game_bt_->setText(_kor("PC ����"));
	connect(pc_game_bt_, &GameSelectorButton::clicked, [=]() { slotGameSelectButton(pc_game_bt_); });

	QVBoxLayout* left_menu_lay = new QVBoxLayout;
	left_menu_lay->setContentsMargins(0, 0, 0, 0);
	left_menu_lay->setSpacing(0);
	left_menu_lay->setAlignment(Qt::AlignTop);

	left_menu_lay->addWidget(mobile_game_bt_);
	left_menu_lay->addWidget(pc_game_bt_);

	ui.game_list_widget_->setLayout(left_menu_lay);
}

void MyGameLauncher::resizeEvent(QResizeEvent* event)
{
	QMainWindow::resizeEvent(event);
	int a = 0, b = 0, c = 0;
	if (this->isMaximized() == false)
	{
		a = 2;
		b = 8;
		c = 2;
	}
	else
	{
		a = 2;
		b = 7;
		c = 2;
	}

	QHBoxLayout* main_lay = static_cast<QHBoxLayout*>(ui.main_application_widget->layout());
	main_lay->setStretch(0, a);
	main_lay->setStretch(1, b);
	main_lay->setStretch(2, c);
}

void MyGameLauncher::setAccountInfo(const QString& id, const QString& vip)
{
	ui.label_id_->setText(id);
	ui.label_vip_->setText(vip);

	//TODO List
	//setFriendList(friend list);
}

void MyGameLauncher::setFriendList(QVector<QPair<QString, int>>  id_list)
{
	auto list_layout = ui.friend_list_widget_->layout();
	if (list_layout == nullptr)
	{
		list_layout = new QVBoxLayout;
		ui.friend_list_widget_->setLayout(list_layout);
	}

	for (int i = 0; i < id_list.size(); ++i)
	{
		auto item = UIFactory::createFriendListItem(id_list[i].first, static_cast<FriendListWidgetItem::FriendStatus>(id_list[i].second));
		list_layout->addWidget(item);
		
		//connect(item, &FriendListWidgetItem::sigClicked, [=]() {});
		v_friend_list_item_.push_back(item);
	}
}

void MyGameLauncher::updateFriendList()
{
	clearFriendList();

	auto list = v_friend_list_item_;
	if (list.empty())
		return;

	for (int i = 0; i < list.size(); ++i)
	{
		//TODO LIST UPDATE
	}
}

void MyGameLauncher::clearFriendList()
{
	auto list = v_friend_list_item_;
	for (int i = 0; i < list.size(); ++i)
	{
		delete list[i];
		list[i] = nullptr;
	}
	v_friend_list_item_.clear();
	QVector<FriendListWidgetItem*>().swap(v_friend_list_item_);
	qDebug() << "v_friend_list_item_ cap = " << v_friend_list_item_.capacity();
}

void MyGameLauncher::slotDownButton()
{
	qDebug() << __func__ << __LINE__;
}

void MyGameLauncher::slotDeleteButton()
{
	auto dlg = UIFactory::showMsgBox(_kor("Ŭ���̾�Ʈ ����"), _kor("���� Ŭ���̾�Ʈ�� �����Ͻðڽ��ϱ�?"), MyMessageBox::TWO);
	if (dlg->exec())
	{

	}
	else
	{

	}
	delete dlg;
	qDebug() << __func__ << __LINE__;
}

void MyGameLauncher::slotSetDirButton()
{
	QString path = QFileDialog::getExistingDirectory(this, _kor("��ġ ���� ��θ� �������ּ���", "/home/"));

	ui.label_path_->setText("PATH : " + path);
}


void MyGameLauncher::slotGameSelectButton(GameSelectorButton* sender)
{
	QString txt = sender->text();
	if (txt == _kor("����� ����"))
	{
		download_path_ = ""; //default mobile path
		download_ftp_url_ = ""; //set mobile game ftp url
		ui.label_game_title_->setText(txt);
		ui.label_image_->setPixmap(QPixmap(":/MyGameLauncher/resource/gransaga_m.PNG"));
	}
	else if (txt == _kor("PC ����"))
	{
		download_path_ = ""; //default pc path
		download_ftp_url_ = ""; //set pc game ftp url
		ui.label_game_title_->setText(txt);
		ui.label_image_->setPixmap(QPixmap(":/MyGameLauncher/resource/gransaga_pc.PNG"));
	}
	else
	{
		qDebug() << __func__ << __LINE__;
		qDebug() << "range of out index";
	}
}