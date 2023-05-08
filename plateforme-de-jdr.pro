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
    src/stat.cpp \
    src/game.cpp \
    src/sheet.cpp \
    ui/additemtoentity.cpp \
    ui/additemwindow.cpp \
    ui/addstatwindow.cpp \
    ui/entitywindow.cpp \
    ui/itemwindow.cpp \
    ui/mainwindow.cpp \
    ui/skillwindow.cpp \
    ui/addskillwindow.cpp \
    ui/addentitywindow.cpp \
    ui/addskilltoentity.cpp

HEADERS += \
    include/entity.h \
    include/skill.h \
    include/item.h \
    include/stat.h \
    include/game.h \
    include/sheet.h \
    ui/additemtoentity.h \
    ui/additemwindow.h \
    ui/addstatwindow.h \
    ui/entitywindow.h \
    ui/itemwindow.h \
    ui/mainwindow.h \
    ui/skillwindow.h \
    ui/addskillwindow.h \
    ui/addentitywindow.h \
    ui/addskilltoentity.h

FORMS += \
    ui/additemtoentity.ui \
    ui/additemwindow.ui \
    ui/addstatwindow.ui \
    ui/entitywindow.ui \
    ui/itemwindow.ui \
    ui/mainwindow.ui \
    ui/skillwindow.ui \
    ui/addskillwindow.ui \
    ui/addentitywindow.ui \
    ui/addskilltoentity.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
