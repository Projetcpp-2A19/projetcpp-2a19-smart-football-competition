#include "dialog.h"
#include "ui_dialog.h"

#include <QPixmap>
#include <QHeaderView>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <QDate>
#include <QMenu>
#include <QCursor>
#include <QSqlQuery>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QPageSize>
#endif

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    proxyModel(new QSortFilterProxyModel(this))
{
    ui->setupUi(this);

    // Load all original images exactly as before
    QPixmap logo("C:/Users/rayen/Downloads/Screenshot_2025-01-26_014639-removebg-preview.png");
    ui->logoo->setPixmap(logo);
    ui->logoo->setScaledContents(true);

    QPixmap chart("C:/Users/rayen/Downloads/Screenshot_2025-02-12_215513-removebg-preview.png");
    ui->chart->setPixmap(chart);
    ui->chart->setScaledContents(true);

    QPixmap home("C:/Users/rayen/Downloads/Screenshot_2025-02-13_021115-removebg-preview.png");
    ui->home->setPixmap(home);
    ui->home->setScaledContents(true);

    QPixmap set("C:/Users/rayen/Downloads/Screenshot_2025-02-13_021120-removebg-preview.png");
    ui->set->setPixmap(set);
    ui->set->setScaledContents(true);



    QPixmap pattern("C:/Users/rayen/Downloads/Screenshot_2025-02-12_212952-removebg-preview.png");
    ui->pattern->setPixmap(pattern);
    ui->pattern->setScaledContents(true);
    ui->pattern->setText("<a href='#'></a>");
    ui->pattern->setOpenExternalLinks(false);



    QPixmap ysar("C:/Users/rayen/Downloads/Screenshot_2025-02-12_223231-removebg-preview.png");
    ui->ysar->setPixmap(ysar);
    ui->ysar->setScaledContents(true);

    QPixmap ymin("C:/Users/rayen/Downloads/Screenshot_2025-02-12_223234-removebg-preview.png");
    ui->ymin->setPixmap(ymin);
    ui->ymin->setScaledContents(true);

    // Original connections
    connect(ui->searchbar, &QLineEdit::textEdited, this, &Dialog::on_searchbar_textEdited);
    connect(ui->pattern, &QLabel::linkActivated, this, &Dialog::on_pattern_clicked);

    // Initialize table exactly as before
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setVisible(false);

    // Set up proxy model for sorting
    proxyModel->setSourceModel(ui->tableWidget->model());
    ui->tableWidget->setModel(proxyModel);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_searchbar_textEdited(const QString &text)
{
    filterTable(text);
}

void Dialog::filterTable(const QString &text)
{
    QSqlQuery query;
    QString queryStr = "SELECT ID_EQUIPE, NOM_EQUIPE, SCORE, ORIGINE FROM EQUIPE ";

    if (!text.isEmpty()) {
        queryStr += "WHERE NOM_EQUIPE LIKE '%" + text + "%' OR ORIGINE LIKE '%" + text + "%' ";
    }

    queryStr += "ORDER BY RANG ASC";

    if (!query.exec(queryStr)) {
        qDebug() << "Query failed:" << query.lastError().text();
        return;
    }

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);

    QStringList headers;
    headers << "ID" << "Team Name" << "Score" << "Origin";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    while (query.next()) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        for (int col = 0; col < 4; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            ui->tableWidget->setItem(row, col, item);

            if (col == 0) {
                item->setData(Qt::UserRole, query.value(col).toInt());
            }
        }
    }
}

void Dialog::on_pattern_clicked()
{
    QMenu sortMenu;
    sortMenu.setStyleSheet(
        "QMenu {"
        "   background-color: #FDF6D0;"
        "   border: 1px solid #2E344C;"
        "   font: 12pt 'Arial';"
        "}"
        "QMenu::item {"
        "   padding: 8px 25px;"
        "}"
        "QMenu::item:selected {"
        "   background-color: #2E344C;"
        "   color: white;"
        "}"
        );

    QAction* nameAction = sortMenu.addAction("Trier par Nom");
    QAction* scoreAction = sortMenu.addAction("Trier par Score");
    QAction* rankAction = sortMenu.addAction("Trier par Rang");

    connect(nameAction, &QAction::triggered, this, &Dialog::sortByName);
    connect(scoreAction, &QAction::triggered, this, &Dialog::sortByScore);
    connect(rankAction, &QAction::triggered, this, &Dialog::sortByRank);

    sortMenu.exec(QCursor::pos());
}

void Dialog::sortByName()
{
    proxyModel->sort(1, Qt::AscendingOrder);
    ui->tableWidget->viewport()->update();
}

void Dialog::sortByScore()
{
    proxyModel->sort(2, Qt::DescendingOrder);
    ui->tableWidget->viewport()->update();
}

void Dialog::sortByRank()
{
    proxyModel->sort(3, Qt::AscendingOrder);
    ui->tableWidget->viewport()->update();
}

QString Dialog::getCurrentSortMethod() const
{
    switch(proxyModel->sortColumn()) {
    case 1: return "Tri par Nom";
    case 2: return "Tri par Score";
    case 3: return "Tri par Rang";
    default: return "Aucun tri spécifique";
    }
}

void Dialog::on_pushButton_6_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Exporter en PDF",
        QString("Classement_%1.pdf").arg(QDate::currentDate().toString("yyyyMMdd")),
        "PDF (*.pdf)"
        );

    if (fileName.isEmpty()) return;

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    printer.setPaperSize(QPrinter::A4);
#else
    printer.setPageSize(QPageSize(QPageSize::A4));
#endif

    printer.setOutputFileName(fileName);

    QPainter painter(&printer);
    painter.setRenderHint(QPainter::Antialiasing);

    // Official Header
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.drawText(QRect(0, 30, printer.width(), 60), Qt::AlignCenter, "The Mind Benders");

    painter.setFont(QFont("Arial", 12));
    painter.drawText(QRect(0, 80, printer.width(), 40), Qt::AlignCenter,
                     "Classement Officiel - ESPRIT El Ghazela");

    painter.setFont(QFont("Arial", 10));
    painter.drawText(QRect(0, 120, printer.width(), 30), Qt::AlignCenter,
                     QString("Date: %1 | %2")
                         .arg(QDate::currentDate().toString("dd/MM/yyyy"))
                         .arg(getCurrentSortMethod()));

    // Table drawing
    int rowHeight = 40;
    int headerHeight = 50;
    int tableTop = 180;
    int columnWidth = (printer.width() - 100) / ui->tableWidget->columnCount();

    // Draw headers
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.setBrush(QColor(46, 52, 76));
    painter.setPen(Qt::white);

    for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
        QString header = ui->tableWidget->horizontalHeaderItem(col)->text();
        painter.drawRect(50 + col*columnWidth, tableTop, columnWidth, headerHeight);
        painter.drawText(50 + col*columnWidth, tableTop, columnWidth, headerHeight,
                         Qt::AlignCenter, header);
    }

    // Draw data
    painter.setFont(QFont("Arial", 9));
    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::black);

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        if (row % 2 == 0) {
            painter.setBrush(QColor(253, 246, 208));
        } else {
            painter.setBrush(Qt::white);
        }

        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            QString text = item ? item->text() : "";

            painter.drawRect(50 + col*columnWidth,
                             tableTop + headerHeight + row*rowHeight,
                             columnWidth,
                             rowHeight);

            painter.drawText(50 + col*columnWidth,
                             tableTop + headerHeight + row*rowHeight,
                             columnWidth,
                             rowHeight,
                             Qt::AlignCenter,
                             text);
        }

        if ((tableTop + headerHeight + (row+1)*rowHeight) > (printer.height() - 100)) {
            printer.newPage();
            painter.drawText(QRect(0, 50, printer.width(), 30),
                             Qt::AlignCenter, "Suite du classement...");
            row = -1;
        }
    }

    // Footer
    painter.setFont(QFont("Arial", 8));
    painter.drawText(QRect(0, printer.height()-40, printer.width(), 30),
                     Qt::AlignCenter,
                     "© 2025 The Mind Benders - Tous droits réservés");

    painter.end();

    QMessageBox::information(this,
                             "Export Réussi",
                             QString("Le classement a été exporté au format PDF.\nTri appliqué: %1")
                                 .arg(getCurrentSortMethod()));
}
