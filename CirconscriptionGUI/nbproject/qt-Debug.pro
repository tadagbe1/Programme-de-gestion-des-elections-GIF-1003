# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = CirconscriptionGUI
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += AjoutCandidate.cpp AjoutElecteur.cpp CirconscriptionGUI.cpp Desinscription.cpp main.cpp
HEADERS += AjoutCandidate.h AjoutElecteur.h CirconscriptionGUI.h Desinscription.h
FORMS += AjoutCandidate.ui AjoutElecteur.ui CirconscriptionGUI.ui Desinscription.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += ../Sources 
LIBS += ../Sources/dist/Debug/GNU-Linux/libsources.a  
