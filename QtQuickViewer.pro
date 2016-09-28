QT += qml quick

CONFIG += c++11 qtquickcompiler

HEADERS += \
    Controller.h \
    RenderView.h

SOURCES += main.cpp \
    Controller.cpp \
    RenderView.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

win32 {
    # OpenSceneGraph
    INCLUDEPATH += D:\Developer\vs2013\OpenSceneGraph-3.5.4\include
    DEPENDPATH += D:\Developer\vs2013\OpenSceneGraph-3.5.4\include
    LIBS += -LD:\Developer\vs2013\OpenSceneGraph-3.5.4\lib

    CONFIG(debug, debug|release) {
        LIBS += -losgd -lOpenThreadsd -losgGAd -losgViewerd -losgDBd -losgUtild -losgTextd
    } else {
        LIBS += -losg -lOpenThreads -losgGA -losgViewer -losgDB -losgUtil -losgText
    }
}

macx {
    INCLUDEPATH += /Users/andre/Developer/OSG-3.5.4/include
    DEPENDPATH += /Users/andre/Developer/OSG-3.5.4/include
    LIBS += -L/Users/andre/Developer/OSG-3.5.4/lib
    LIBS += -losg -lOpenThreads -losgGA -losgViewer -losgDB -losgUtil -losgText
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
