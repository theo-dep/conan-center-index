#include <QGuiApplication>
#include <QtPlugin>

#include <iostream>

#ifdef TEST_QT_STATIC
#if defined(_WIN32)
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)
#elif defined(__APPLE__)
Q_IMPORT_PLUGIN(QCocoaIntegrationPlugin)
#endif
#endif

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    const QString platform = QGuiApplication::platformName();
    std::cout << "Qt platform plugin: " << platform.toStdString() << std::endl;
    return platform.isEmpty() ? 1 : 0;
}
