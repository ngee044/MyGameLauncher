#pragma once

#include <QWidget>
#include "uicomponent_global.h"

class QSize;
class QPoint;
class QToolButton;

class UICOMPONENT_EXPORT TitleBar : public QWidget
{
	Q_OBJECT

public:
	explicit TitleBar(QWidget* parent = nullptr);
	virtual ~TitleBar();
	TitleBar(const TitleBar&) = delete;
	const TitleBar& operator = (const TitleBar&) = delete;

	void OnWindowsSizeButtonClicked(QToolButton* button);
	void OnWindowsExitButtonClicked();
	void OnWindowsHideButtonClicked();
	void SetButtonStyle(QToolButton* hide_button, QToolButton* resize_button, QToolButton* exit_button);

	inline void set_check_maximum_size(bool idx) { check_maximum_size_ = idx; }
	inline bool check_maximum_size() const { return  check_maximum_size_; }

protected:
	virtual void mousePressEvent(QMouseEvent* event) override;
	virtual void mouseMoveEvent(QMouseEvent* event) override;
	virtual void mouseReleaseEvent(QMouseEvent* event) override;
	virtual void mouseDoubleClickEvent(QMouseEvent* event) override;

private:
	QPoint mouse_pos_ = QPoint(0, 0);
	bool check_maximum_size_ = false;
};
