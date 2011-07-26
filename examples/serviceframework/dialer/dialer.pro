QT = core serviceframework declarative qtquick1
win32: CONFIG += console
mac:CONFIG -= app_bundle

SOURCES += main.cpp

RESOURCES += dialer.qrc

OTHER_FILES += \
content/DialButton.qml \
content/DialScreen.qml \
content/DialerList.qml \
dialer.qml


# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtsystems/serviceframework/dialer
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS dialer.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/qtsystems/serviceframework/dialer
contains(jsondb_enabled, yes) {
    info.path = $$[QT_INSTALL_EXAMPLES]/qtsystems/serviceframework/dialer
    info.files = info.json
}
INSTALLS += target sources info

symbian: CONFIG += qt_example
maemo5: CONFIG += qt_example

symbian*: {
    addFiles.sources = remotedialerservice.xml
    addFiles.path = /private/2002AC7F/import/
    DEPLOYMENT += addFiles
}
else {
    DEFINES += TESTDATA_DIR=\\\"$$PWD/\\\"
}


symbian {
    TARGET.EPOCHEAPSIZE = 0x20000 0x2000000
}

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
# installs into /usr/loca/bin, bad idea, deployment rules are above
#qtcAddDeployment()