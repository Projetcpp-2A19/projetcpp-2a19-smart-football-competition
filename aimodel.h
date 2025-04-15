#ifndef AIMODEL_H
#define AIMODEL_H

#include <QDialog>
#include <QFileDialog>
#include <QProcess>

namespace Ui {
class aimodel;
}

class aimodel : public QDialog
{
    Q_OBJECT

public:
    explicit aimodel(QWidget *parent = nullptr);
    ~aimodel();

private slots:
    void onUploadButtonClicked();
    void runPythonScript(const QString &videoPath);

private:
    Ui::aimodel *ui;
    QProcess *process;
    QString videoPath;
};

#endif // AIMODEL_H
