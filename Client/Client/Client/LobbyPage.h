#pragma once

#include <QWidget>
#include "ui_LobbyPage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LobbyClass; };
QT_END_NAMESPACE

class LobbyPage : public QWidget
{
	Q_OBJECT

public:
	LobbyPage(QWidget *parent = nullptr);
	~LobbyPage();

private slots:
	void changeToLoginPage();
	void changeToGamePage();

signals:
	void goToLoginPage();
	void goToGamePage();

private:
	Ui::LobbyClass *ui;
};
