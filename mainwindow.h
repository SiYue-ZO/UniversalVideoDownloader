#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QProgressBar>
#include <QComboBox>
#include <QProcess>
#include <QMap>
#include <QCheckBox>

class ToolManager;
class UrlExtractor;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAnalyzeClicked();
    void onDownloadClicked();

    // QProcess 的异步回调
    void handleAnalyzeFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void handleDownloadOutput();
    void handleDownloadFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void handleProcessError(QProcess::ProcessError error);

    // URL 自动解析回调
    void onUrlExtracted(const QString &extractedUrl);
    void onUrlExtractFailed(const QString &pageUrl);
    void onUrlExtractError(const QString &errorMsg);

private:
    QLineEdit *urlInput;
    QLineEdit *nameInput;
    QPushButton *analyzeBtn;
    QPushButton *downloadBtn;
    QComboBox *resolutionBox;
    QComboBox *cookieBox;
    QCheckBox *playlistCheckBox;
    QCheckBox *autoExtractCheckBox;
    QTextEdit *logConsole;
    QProgressBar *progressBar;

    QProcess *analyzeProcess;
    QProcess *downloadProcess;

    QMap<QString, QString> formatMap;
    QString currentUrl;
    QString ytdlpPath;
    QString ffmpegPath;

    ToolManager *toolManager;
    UrlExtractor *urlExtractor;

    void logMessage(const QString &msg);
    void setupToolManager();
    void startYtdlpAnalyze();
};

#endif // MAINWINDOW_H
