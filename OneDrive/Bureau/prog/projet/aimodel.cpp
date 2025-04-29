#include "aimodel.h"
#include "ui_aimodel.h"
#include <QFileDialog>
#include <QProcess>
#include <QDebug>

aimodel::aimodel(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::aimodel),
    process(nullptr)  // Initialize process to null
{
    ui->setupUi(this);
    connect(ui->uploadButton, &QPushButton::clicked, this, &aimodel::onUploadButtonClicked);
}

aimodel::~aimodel()
{
    if (process) {
        delete process;  // Cleanup process if it's created
    }
    delete ui;
}

void aimodel::onUploadButtonClicked()
{
    // Open a file dialog to choose a video file
    videoPath = QFileDialog::getOpenFileName(this, "Select Video", "", "Videos (*.mp4 *.avi *.mov)");

    // If the user selects a video, run the Python script
    if (!videoPath.isEmpty()) {
        runPythonScript(videoPath);
    }
}

void aimodel::runPythonScript(const QString& videoPath)
{
    // Path to Python executable
    QString pythonPath = "python";  // Ensure Python is in your system PATH

    // Path to Python script
    QString scriptPath = "C:/Users/rayen/OneDrive/Bureau/aitest.py";  // Adjust to your Python script's path

    // Prepare the arguments for the Python script
    QStringList arguments;
    arguments << scriptPath << videoPath;  // Pass the video path as argument

    // Create a new QProcess to run the Python script
    process = new QProcess(this);

    // Start the Python process with the script and arguments
    process->start(pythonPath, arguments);

    // Check if the process started successfully
    if (!process->waitForStarted()) {
        qDebug() << "Error: Failed to start the Python process.";
        return;  // Exit if the process couldn't be started
    }

    // Optional: Wait for the process to finish (this will block the UI thread)
    process->waitForFinished();
}
