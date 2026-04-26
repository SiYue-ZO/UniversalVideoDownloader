#include "cli_runner.h"
#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>

int main(int argc, char *argv[]) {
    // 预扫描参数：如果有 --cli / -c / --help / -h 则启动终端模式
    bool cliMode = false;
    for (int i = 1; i < argc; ++i) {
        QString arg = QString::fromLocal8Bit(argv[i]);
        if (arg == "--cli" || arg == "-c"
            || arg == "--help" || arg == "-h") {
            cliMode = true;
            break;
        }
    }

    if (cliMode) {
        // 终端模式：轻量级 QCoreApplication，无 GUI 开销
        QCoreApplication app(argc, argv);
        app.setApplicationName("UniversalVideoDownloader");
        app.setApplicationVersion("2.0");

        CliRunner runner;
        int exitCode = runner.run(argc, argv);
        return exitCode;
    }

    // GUI 模式：标准 Qt 窗口
    QApplication app(argc, argv);
    app.setApplicationName("Video Downloader");
    app.setOrganizationName("UniversalVideoDownloader");
    app.setApplicationDisplayName("Video Downloader");
    MainWindow w;
    w.show();
    return app.exec();
}
