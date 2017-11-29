OBJ=main.cpp
OBJ+=Address.cpp
#OBJ+=ExportData.h
OBJ+=Contact.cpp
OBJ+=ImportExportXml.cpp
OBJ+=ImportExportXmlExp.cpp
OBJ+=ImportExportCsv.cpp
OBJ+=ImportExport.cpp
OBJ+=Person.cpp
OBJ+=PhoneBook.cpp
OBJ+=pugixml.cpp
OBJ+=ExportFactory.cpp

CXXFLAGS=-std=c++14 -g
LIBS = -lboost_program_options
OUTPUT=RunCode

all:
	g++ $(CXXFLAGS) $(OBJ) $(LIBS) -o $(OUTPUT)
