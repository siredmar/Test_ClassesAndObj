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

CXXFLAGS=-std=c++11 -g

OUTPUT=/home/alex/Workspace/RunCode

all:
	g++ $(CXXFLAGS) $(OBJ) -o $(OUTPUT)
