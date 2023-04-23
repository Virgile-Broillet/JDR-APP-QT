#ifndef MUSICWINDOW_H
#define MUSICWINDOW_H

#include <QDialog>

namespace Ui {
class MusicWindow;
}

class MusicWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construcor of the MusicWindows
     * @param[in] parent, main QDialog
     */
    explicit MusicWindow(QWidget *parent = nullptr);
    /**
     * @brief Destructor of the MusicWindow
     */
    ~MusicWindow();

private:
    /**
     * @brief pointer to the ui of MusicWindow
     */
    Ui::MusicWindow *ui;
};

#endif // MUSICWINDOW_H
