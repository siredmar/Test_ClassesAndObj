OBJ=main.cpp
OBJ+=Address.cpp
#OBJ+=ExportData.h
OBJ+=Contact.cpp
OBJ+=ExportToXml.cpp
OBJ+=ExportToXmlExp.cpp
OBJ+=ExportToCsv.cpp
OBJ+=ImportExport.cpp
OBJ+=Person.cpp
OBJ+=PhoneBook.cpp
OBJ+=pugixml.cpp

CXXFLAGS=-std=c++11

OUTPUT=/home/alex/Workspace/RunCode

all:
	g++ $(CXXFLAGS) $(OBJ) -o $(OUTPUT)
