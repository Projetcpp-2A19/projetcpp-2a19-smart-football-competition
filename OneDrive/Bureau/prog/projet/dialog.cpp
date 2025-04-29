#include "dialog.h"
#include "ui_dialog.h"
#include <QPaintEvent>
#include <QPainter>
#include <QPrinter>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QPixmap>
#include <QHeaderView>
#include <QFileDialog>
#include <QMessageBox>
#include <QDate>
#include <QMenu>
#include <QCursor>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QPageSize>
#include <QPageLayout>
#include "aimodel.h"
#endif

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
//aiModelWindow(nullptr)
{
    ui->setupUi(this);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &Dialog::on_page_3_clicked);

    // Initialize search filter to search all columns by default
    currentSearchFilter = "ALL";

    // Initialize histogram area
    ui->label_10->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_10->setStyleSheet("background: transparent;");

    // Load images
    QPixmap logo(":/images/logo.png");
    if(!logo.isNull()) {
        ui->logoo->setPixmap(logo.scaled(ui->logoo->size(), Qt::KeepAspectRatio));
    }

    // Initialize table
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Team Name", "Score", "Origin", "Possession"});
    ui->tableWidget->setSortingEnabled(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setVisible(false);

    // Set column widths
    ui->tableWidget->setColumnWidth(0, 50);
    ui->tableWidget->setColumnWidth(1, 150);
    ui->tableWidget->setColumnWidth(2, 80);
    ui->tableWidget->setColumnWidth(3, 120);
    ui->tableWidget->setColumnWidth(4, 100);

    // Load initial data
    filterTable("");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_page_3_clicked()
{
    aiModelWindow = new aimodel(this);
    aiModelWindow->setWindowTitle("Football AI Analysis");
    aiModelWindow->setAttribute(Qt::WA_DeleteOnClose);
    aiModelWindow->show();
}

void Dialog::on_trii_clicked()
{
    QMenu filterMenu;
    filterMenu.setStyleSheet(
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

    QAction* allAction = filterMenu.addAction("Search All Columns");
    QAction* nameAction = filterMenu.addAction("Search by Name");
    QAction* scoreAction = filterMenu.addAction("Search by Score");
    QAction* originAction = filterMenu.addAction("Search by Origin");
    QAction* possessionAction = filterMenu.addAction("Search by Possession");

    connect(allAction, &QAction::triggered, this, [this]() { setSearchFilter("ALL"); });
    connect(nameAction, &QAction::triggered, this, [this]() { setSearchFilter("NOM_EQUIPE"); });
    connect(scoreAction, &QAction::triggered, this, [this]() { setSearchFilter("SCORE"); });
    connect(originAction, &QAction::triggered, this, [this]() { setSearchFilter("ORIGINE"); });
    connect(possessionAction, &QAction::triggered, this, [this]() { setSearchFilter("POSSESSION"); });

    filterMenu.exec(QCursor::pos());
}

void Dialog::setSearchFilter(const QString &filter)
{
    currentSearchFilter = filter;
    filterTable(ui->searchbar->text());
}

QMap<QString, int> Dialog::getTeamGoalsData()
{
    QMap<QString, int> goalsData;

    if(!QSqlDatabase::database().isOpen()) {
        qDebug() << "Database not connected!";
        return goalsData;
    }

    QSqlQuery query;
    if(!query.exec("SELECT NOM_EQUIPE, SCORE FROM EQUIPE ORDER BY SCORE DESC")) {
        qDebug() << "Query error:" << query.lastError().text();
        return goalsData;
    }

    while(query.next()) {
        goalsData[query.value(0).toString()] = query.value(1).toInt();
    }

    return goalsData;
}

void Dialog::drawHistogram(QPainter &painter, const QMap<QString, int> &data)
{
    if(data.isEmpty()) {
        painter.drawText(ui->label_10->rect(), Qt::AlignCenter, "No data available");
        return;
    }

    QRect area = ui->label_10->rect();
    area.adjust(10, 10, -10, -10);

    const int barWidth = 40;
    const int spacing = 20;
    const int textMargin = 5;
    int x = area.left();
    int maxValue = *std::max_element(data.begin(), data.end());

    painter.setPen(Qt::black);
    painter.drawLine(area.left(), area.bottom(), area.right(), area.bottom());

    painter.setBrush(QColor(46, 52, 76));
    for(auto it = data.begin(); it != data.end(); ++it) {
        int barHeight = (it.value() * area.height()) / (maxValue * 1.2);
        QRect bar(x, area.bottom() - barHeight, barWidth, barHeight);

        painter.drawRect(bar);
        painter.drawText(bar.topLeft() + QPoint(0, -textMargin),
                         QString::number(it.value()));

        painter.save();
        painter.translate(x + barWidth/2, area.bottom() + 15);
        painter.rotate(-90);
        painter.drawText(0, 0, it.key());
        painter.restore();

        x += barWidth + spacing;
        if(x > area.right()) break;
    }
}

void Dialog::paintEvent(QPaintEvent *event)
{
    QDialog::paintEvent(event);

    if(ui->label_10->rect().intersects(event->rect())) {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.translate(ui->label_10->pos());

        QMap<QString, int> data = getTeamGoalsData();
        drawHistogram(painter, data);
    }
}

void Dialog::filterTable(const QString &text)
{
    QSqlQuery query;
    QString queryStr = "SELECT ID_EQUIPE, NOM_EQUIPE, SCORE, ORIGINE, POSSESSION FROM EQUIPE ";

    if(!text.isEmpty()) {
        if(currentSearchFilter == "ALL") {
            queryStr += "WHERE NOM_EQUIPE LIKE '%" + text + "%' OR ORIGINE LIKE '%" + text + "%' OR POSSESSION LIKE '%" + text + "%' ";
        } else {
            queryStr += "WHERE " + currentSearchFilter + " LIKE '%" + text + "%' ";
        }
    }
    queryStr += "ORDER BY SCORE DESC";

    if(!query.exec(queryStr)) {
        qDebug() << "Filter error:" << query.lastError().text();
        return;
    }

    ui->tableWidget->setSortingEnabled(false);
    ui->tableWidget->setRowCount(0);

    while(query.next()) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        for(int col = 0; col < 5; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            if(col == 4) {
                item->setTextAlignment(Qt::AlignCenter);
            }
            ui->tableWidget->setItem(row, col, item);
        }
    }
    ui->tableWidget->setSortingEnabled(true);
    update();
}

void Dialog::on_searchbar_textEdited(const QString &text)
{
    filterTable(text);
}

void Dialog::on_pushButton_6_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Export as PDF",
        QString("Teams_%1.pdf").arg(QDate::currentDate().toString("yyyyMMdd")),
        "PDF Files (*.pdf)"
        );

    if(fileName.isEmpty()) return;

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    printer.setPageSize(QPrinter::A4);
#else
    printer.setPageSize(QPageSize(QPageSize::A4));
#endif

    QPainter painter(&printer);
    painter.setFont(QFont("Arial", 16, QFont::Bold));
    painter.drawText(100, 100, "Teams Ranking Report");

    int y = 150;
    const int rowHeight = 30;
    const int colWidth = 150;

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    int pageHeight = printer.pageRect().height();
#else
    int pageHeight = printer.pageLayout().paintRectPixels(printer.resolution()).height();
#endif

    painter.setFont(QFont("Arial", 10, QFont::Bold));
    for(int col = 0; col < ui->tableWidget->columnCount(); col++) {
        QString header = ui->tableWidget->horizontalHeaderItem(col)->text();
        painter.drawText(100 + col * colWidth, y, header);
    }
    y += rowHeight;

    painter.setFont(QFont("Arial", 10));
    for(int row = 0; row < ui->tableWidget->rowCount(); row++) {
        if(y > pageHeight - 50) {
            printer.newPage();
            y = 100;
            painter.setFont(QFont("Arial", 10, QFont::Bold));
            for(int col = 0; col < ui->tableWidget->columnCount(); col++) {
                QString header = ui->tableWidget->horizontalHeaderItem(col)->text();
                painter.drawText(100 + col * colWidth, y, header);
            }
            y += rowHeight;
            painter.setFont(QFont("Arial", 10));
        }

        for(int col = 0; col < ui->tableWidget->columnCount(); col++) {
            QString text = ui->tableWidget->item(row, col)->text();
            painter.drawText(100 + col * colWidth, y, text);
        }
        y += rowHeight;
    }

    painter.end();
    QMessageBox::information(this, "Export Successful", "PDF file has been created successfully.");
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

    QAction* nameAction = sortMenu.addAction("Sort by Name");
    QAction* scoreAction = sortMenu.addAction("Sort by Score");
    QAction* rankAction = sortMenu.addAction("Sort by Rank");
    QAction* possessionAction = sortMenu.addAction("Sort by Possession");

    connect(nameAction, &QAction::triggered, this, &Dialog::sortByName);
    connect(scoreAction, &QAction::triggered, this, &Dialog::sortByScore);
    connect(rankAction, &QAction::triggered, this, &Dialog::sortByRank);
    connect(possessionAction, &QAction::triggered, this, &Dialog::sortByPossession);

    sortMenu.exec(QCursor::pos());
}

void Dialog::sortByName()
{
    ui->tableWidget->sortByColumn(1, Qt::AscendingOrder);
    update();
}

void Dialog::sortByScore()
{
    ui->tableWidget->sortByColumn(2, Qt::DescendingOrder);
    update();
}

void Dialog::sortByRank()
{
    ui->tableWidget->sortByColumn(3, Qt::AscendingOrder);
    update();
}

void Dialog::sortByPossession()
{
    ui->tableWidget->sortByColumn(4, Qt::DescendingOrder);
    update();
}

QString Dialog::getCurrentSortMethod() const
{
    return "Custom Sorting";
}
