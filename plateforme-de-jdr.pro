QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += \
widgets \
multimedia \
multimediawidgets

CONFIG += c++17
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/entity.cpp \
    src/skill.cpp \
    src/item.cpp \
    src/world.cpp \
    src/display.cpp \
    src/event.cpp \
    src/stat.cpp \
    src/game.cpp \
    src/sheet.cpp \
    ui/addentity.cpp \
    ui/addstatwindow.cpp \
    ui/entitywindow.cpp \
    ui/mainwindow.cpp \
    ui/musicwindow.cpp \
    ui/seesheets.cpp

HEADERS += \
    include/entity.h \
    include/skill.h \
    include/item.h \
    include/world.h \
    include/display.h \
    include/event.h \
    include/stat.h \
    include/game.h \
    include/sheet.h \
    ui/addentity.h \
    ui/addstatwindow.h \
    ui/entitywindow.h \
    ui/mainwindow.h \
    ui/musicwindow.h \
    ui/seesheets.h

FORMS += \
    ui/addentity.ui \
    ui/addstatwindow.ui \
    ui/entitywindow.ui \
    ui/mainwindow.ui \
    ui/musicwindow.ui \
    ui/seesheets.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
