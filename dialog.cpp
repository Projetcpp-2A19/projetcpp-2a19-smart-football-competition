#include "dialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include <QRandomGenerator>
#include <QEventLoop>
#include <QTimer>
#include <QLabel>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>

Billet::Billet() : prix(0), num_place(0) {}

Billet::Billet(QString nom_etab, QString zone, double prix, QDateTime date, int num_place) :
    nom_etab(nom_etab), zone(zone), prix(prix), date(date), num_place(num_place) {}

bool Billet::ajouter_billet() {
    QSqlQuery query;
    query.prepare("INSERT INTO billets (nom_etab, zone, prix, date_heure, num_place) "
                  "VALUES (:nom_etab, :zone, :prix, :date_heure, :num_place)");

    query.bindValue(":nom_etab", nom_etab);
    query.bindValue(":zone", zone);
    query.bindValue(":prix", prix);
    query.bindValue(":date_heure", date);
    query.bindValue(":num_place", num_place);

    if (!query.exec()) {
        qDebug() << "Error adding billet:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel* Billet::afficher_billets() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, nom_etab, zone, prix, TO_CHAR(date_heure, 'YYYY-MM-DD HH24:MI:SS') as date_heure, num_place FROM billets");

    if (model->lastError().isValid()) {
        qDebug() << "Error displaying billets:" << model->lastError().text();
        return nullptr;
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Établissement"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Zone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date/Heure"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num Place"));

    return model;
}

bool Billet::billetExists(int id) {
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT 1 FROM billets WHERE id = :id");
    checkQuery.bindValue(":id", id);
    return checkQuery.exec() && checkQuery.next();
}

bool Billet::supprimer_billet(int id, QWidget *parent) {
    // Check if billet exists
    if (!billetExists(id)) {
        if (parent) {
            QMessageBox::warning(parent, "Non trouvé",
                                 "Aucun billet trouvé avec l'ID " + QString::number(id));
        }
        return false;
    }

    // Get user confirmation (if parent widget provided)
    if (parent) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(parent, "Confirmation",
                                      "Voulez-vous vraiment supprimer le billet #" +
                                          QString::number(id) + "?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply != QMessageBox::Yes) {
            return false;
        }
    }

    // Perform deletion
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM billets WHERE id = :id");
    deleteQuery.bindValue(":id", id);

    if (!deleteQuery.exec()) {
        if (parent) {
            QString errorDetails = deleteQuery.lastError().text();
            if (errorDetails.contains("foreign key constraint", Qt::CaseInsensitive)) {
                QMessageBox::critical(parent, "Erreur",
                                      "Impossible de supprimer: ce billet est référencé ailleurs!");
            } else {
                QMessageBox::critical(parent, "Erreur de base de données",
                                      "Erreur technique:\n" + errorDetails);
            }
        }
        return false;
    }

    return deleteQuery.numRowsAffected() > 0;
}

bool Billet::modifier_billet(int id, const QString& newNomEtab, const QString& newZone,
                             double newPrix, const QDateTime& newDate, int newNumPlace,
                             QWidget* parent)
{
    // Check if billet exists
    if (!billetExists(id)) {
        if (parent) {
            QMessageBox::warning(parent, "Non trouvé",
                                 "Aucun billet trouvé avec l'ID " + QString::number(id));
        }
        return false;
    }

    // Get user confirmation (if parent widget provided)
    if (parent) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(parent, "Confirmation",
                                      "Voulez-vous vraiment modifier le billet #" +
                                          QString::number(id) + "?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply != QMessageBox::Yes) {
            return false;
        }
    }

    // Perform update
    QSqlQuery query;
    query.prepare("UPDATE billets SET "
                  "nom_etab = :nom_etab, "
                  "zone = :zone, "
                  "prix = :prix, "
                  "date_heure = :date_heure, "
                  "num_place = :num_place "
                  "WHERE id = :id");

    query.bindValue(":nom_etab", newNomEtab);
    query.bindValue(":zone", newZone);
    query.bindValue(":prix", newPrix);
    query.bindValue(":date_heure", newDate);
    query.bindValue(":num_place", newNumPlace);
    query.bindValue(":id", id);

    if (!query.exec()) {
        if (parent) {
            QString errorDetails = query.lastError().text();
            QMessageBox::critical(parent, "Erreur de base de données",
                                  "Échec de la modification:\n" + errorDetails);
        }
        return false;
    }

    return query.numRowsAffected() > 0;
}


QSqlQueryModel* Billet::searchByNumPlace(int num_place) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT id, nom_etab, zone, prix, TO_CHAR(date_heure, 'YYYY-MM-DD HH24:MI:SS') as date_heure, num_place "
                  "FROM billets WHERE num_place = :num_place ORDER BY date_heure DESC");
    query.bindValue(":num_place", num_place);

    if (!query.exec()) {
        qDebug() << "Search error:" << query.lastError().text();
        delete model;
        return nullptr;
    }

    model->setQuery(query);

    // Set headers
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Établissement"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Zone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date/Heure"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num Place"));

    return model;
}


QSqlQueryModel* Billet::sortByNumPlaceAsc() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, nom_etab, zone, prix, TO_CHAR(date_heure, 'YYYY-MM-DD HH24:MI:SS') as date_heure, num_place "
                    "FROM billets ORDER BY num_place ASC");

    if (model->lastError().isValid()) {
        qDebug() << "Sorting error (ASC):" << model->lastError().text();
        delete model;
        return nullptr;
    }

    // Set headers (same as your display function)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Établissement"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Zone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date/Heure"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num Place"));

    return model;
}

QSqlQueryModel* Billet::sortByNumPlaceDesc() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, nom_etab, zone, prix, TO_CHAR(date_heure, 'YYYY-MM-DD HH24:MI:SS') as date_heure, num_place "
                    "FROM billets ORDER BY num_place DESC");

    if (model->lastError().isValid()) {
        qDebug() << "Sorting error (DESC):" << model->lastError().text();
        delete model;
        return nullptr;
    }

    // Set headers (same as your display function)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Établissement"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Zone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date/Heure"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Num Place"));

    return model;
}

QMap<QString, int> Billet::getTicketCountsByZone()
{
    QMap<QString, int> zoneCounts;

    connection c;
    QSqlDatabase db = c.get_connection();

    if (db.open()) {
        QSqlQuery query(db);
        query.prepare("SELECT zone, COUNT(*) FROM billets GROUP BY zone");

        if (query.exec()) {
            while (query.next()) {
                QString zone = query.value(0).toString();
                int count = query.value(1).toInt();
                zoneCounts[zone] = count;
            }
        } else {
            qDebug() << "Query error:" << query.lastError().text();
        }

        db.close();
    } else {
        qDebug() << "Database connection error:" << db.lastError().text();
    }

    return zoneCounts;
}

bool Billet::tirageAuSort(QWidget* parent) {
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(parent, "Erreur", "Pas de connexion à la base de données!");
        return false;
    }

    // Get stadium names
    QSqlQuery query;
    if (!query.exec("SELECT DISTINCT nom_etab FROM billets")) {
        QMessageBox::critical(parent, "Erreur", query.lastError().text());
        return false;
    }

    QStringList stadiumNames;
    while (query.next()) {
        stadiumNames << query.value(0).toString();
    }

    if (stadiumNames.isEmpty()) {
        QMessageBox::information(parent, "Information", "Aucun stade trouvé!");
        return false;
    }

    // Create lottery dialog
    QDialog lotteryDialog(parent);
    lotteryDialog.setWindowTitle("Tirage au Sort");
    lotteryDialog.setFixedSize(400, 200);

    QVBoxLayout* layout = new QVBoxLayout(&lotteryDialog);

    QLabel* animationLabel = new QLabel("Démarrage du tirage...", &lotteryDialog);
    animationLabel->setAlignment(Qt::AlignCenter);
    animationLabel->setStyleSheet("font-size: 18px; color: #333;");
    layout->addWidget(animationLabel);

    QLabel* resultLabel = new QLabel(&lotteryDialog);
    resultLabel->setAlignment(Qt::AlignCenter);
    resultLabel->setStyleSheet("font-size: 22px; color: #FF5722; font-weight: bold;");
    layout->addWidget(resultLabel);

    // Start the draw
    QString selectedStadium;
    QTimer::singleShot(500, [&]() {
        // Create cycling animation
        QPropertyAnimation* anim = new QPropertyAnimation(&lotteryDialog);
        anim->setTargetObject(animationLabel);
        anim->setPropertyName("text");
        anim->setDuration(3000);

        // Add all stadiums to animation
        for(int i = 0; i < stadiumNames.size(); i++) {
            anim->setKeyValueAt(i/static_cast<double>(stadiumNames.size()), stadiumNames[i]);
        }

        // Select random winner
        selectedStadium = stadiumNames[QRandomGenerator::global()->bounded(stadiumNames.size())];
        anim->setKeyValueAt(1.0, selectedStadium);

        // When animation completes
        QAbstractAnimation::connect(anim, &QPropertyAnimation::finished, [&]() {
            animationLabel->hide();
            resultLabel->setText(QString("Gagnant:\n%1").arg(selectedStadium));

            // Add celebration effect
            QGraphicsOpacityEffect* effect = new QGraphicsOpacityEffect(resultLabel);
            resultLabel->setGraphicsEffect(effect);

            QPropertyAnimation* fadeAnim = new QPropertyAnimation(effect, "opacity");
            fadeAnim->setDuration(1000);
            fadeAnim->setStartValue(0);
            fadeAnim->setEndValue(1);
            fadeAnim->start(QPropertyAnimation::DeleteWhenStopped);

            // Close after delay
            QTimer::singleShot(2500, [&lotteryDialog]() {
                lotteryDialog.accept();
            });
        });

        anim->start(QPropertyAnimation::DeleteWhenStopped);
    });

    // Show dialog and wait for completion
    if (lotteryDialog.exec() != QDialog::Accepted) {
        return false;
    }

    // Apply discount
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE billets SET prix = prix * 0.5 WHERE nom_etab = :nom_etab");
    updateQuery.bindValue(":nom_etab", selectedStadium);

    if (!updateQuery.exec()) {
        QMessageBox::critical(parent, "Erreur", updateQuery.lastError().text());
        return false;
    }

    // Show results
    int affected = updateQuery.numRowsAffected();
    QMessageBox::information(parent, "Résultats",
                             QString("Le stade %1 a gagné!\n%2 billets réduits de 50%.")
                                 .arg(selectedStadium).arg(affected));

    return true;
}





