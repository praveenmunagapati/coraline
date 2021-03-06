// <license>
// Copyright (C) 2011 Andrea Interguglielmi, All rights reserved.
// This file is part of the coral repository downloaded from http://code.google.com/p/coral-repo.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// 
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
// 
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// </license>


#ifndef STRINGWRAPPER_H
#define STRINGWRAPPER_H

#include <boost/python.hpp>
#include "../builtinNodes/StringNode.h"
#include "../src/pythonWrapperUtils.h"

using namespace coral;

std::vector<std::string> string_stringValues(String &self){
	return self.stringValues();
}

std::vector<std::string> string_pathValues(String &self){
	return self.pathValues();
}

std::string string_stringValueAtSlice(String &self, unsigned int slice, unsigned int id){
	return self.stringValueAtSlice(slice, id);
}

std::vector<std::string> string_stringValuesSlice(String &self, unsigned int slice){
	return self.stringValuesSlice(slice);
}

std::vector<std::string> string_pathValuesSlice(String &self, unsigned int slice){
	return self.pathValuesSlice(slice);
}

int string_stringTypeAny(){
	return int(String::stringTypeAny);
}

int string_stringType(){
	return int(String::stringType);
}

int string_stringTypeArray(){
	return int(String::stringTypeArray);
}

int string_pathType(){
	return int(String::pathType);
}

int string_pathTypeArray(){
	return int(String::pathTypeArray);
}

void string_setStringValues(String &self, boost::python::list pyList){
	std::vector<std::string> convertedList;
	for(int i=0; i < boost::python::len(pyList); ++i){
		std::string val = boost::python::extract<std::string>(pyList[i]);
		convertedList.push_back(val);
	}
	self.setStringValues(convertedList);
}

void string_setPathValues(String &self, boost::python::list pyList){
	std::vector<std::string> convertedList;
	for (int i=0; i < boost::python::len(pyList); i++){
		std::string val = boost::python::extract<std::string>(pyList[i]);
		convertedList.push_back(val);
	}
	self.setPathValues(convertedList);
}

void string_setStringValuesSlice(String &self, unsigned int slice, boost::python::list pyList){
	std::vector<std::string> convertedList;
	for (int i=0; i <boost::python::len(pyList); i++){
		std::string val = boost::python::extract<std::string>(pyList[i]);
		convertedList.push_back(val);
	}
	self.setStringValuesSlice(slice, convertedList);
}

void string_setPathValuesSlice(String &self, unsigned int slice, boost::python::list pyList){
	std::vector<std::string> convertedList;
	for (int i=0; i < boost::python::len(pyList); i++){
		std::string val = boost::python::extract<std::string>(pyList[i]);
		convertedList.push_back(val);
	}
	self.setPathValuesSlice(slice, convertedList);
}

void string_setStringValueAt(String &self, unsigned int id, std::string value){
	self.setStringValueAt(id, value);
}

int string_type(String &self){
	return int(self.type());
}

void string_setType(String &self, String::Type type){
	self.setType(type);
}

void stringWrapper(){
//	boost::python::enum_<String::Type>("Type")
//		.value("stringTypeAny", String::stringTypeAny)
//		.value("stringType", String::stringType)
//		.value("stringTypeArray", String::stringTypeArray)
//		.value("pathType",String::pathType)
//		.value("pathTypeArray", String::pathTypeArray)
//	;
	boost::python::class_<String, boost::shared_ptr<String>, boost::python::bases<Value>, boost::noncopyable>("String", boost::python::no_init)
		.def("__init__", pythonWrapperUtils::__init__<String>)
		.def("type", string_type)
		.def("setType", string_setType)
		.def("isArray", &String::isArray)
		.def("size", &String::size)
		.def("resize", &String::resize)
		.def("setStringValueAt", string_setStringValueAt)
		.def("setStringValues", string_setStringValues)
		.def("setPathValues", string_setPathValues)
		.def("setStringValuesSlice", string_setStringValuesSlice)
		.def("setPathValuesSlice", string_setPathValuesSlice)
		.def("stringValueAt", &String::stringValueAt)
		.def("pathValueAt", &String::pathValueAt)
		.def("stringValues", string_stringValues)
		.def("pathValues", string_pathValues)
		.def("stringValueAtSlice", string_stringValueAtSlice)
		.def("stringValuesSlice", string_stringValuesSlice)
		.def("pathValuesSlice", string_stringValuesSlice)
		.def("createUnwrapped", pythonWrapperUtils::createUnwrapped<String>)
		.staticmethod("createUnwrapped")
		.add_static_property("stringTypeAny", string_stringTypeAny)
		.add_static_property("stringType", string_stringType)
		.add_static_property("stringTypeArray", string_stringTypeArray)
		.add_static_property("pathType", string_pathType)
		.add_static_property("pathTypeArray", string_pathTypeArray)
	;
	
	pythonWrapperUtils::pythonWrapper<StringAttribute, Attribute>("StringAttribute")
		.def("setLongString", &StringAttribute::setLongString)
		.def("longString", &StringAttribute::longString);
	pythonWrapperUtils::pythonWrapper<StringNode, Node>("StringNode");
	pythonWrapperUtils::pythonWrapper<FilePathNode, Node>("FilePathNode");
	pythonWrapperUtils::pythonWrapper<AddStringNode, Node>("AddStringNode");
	pythonWrapperUtils::pythonWrapper<BuildArrayStringNode, Node>("BuildArrayStringNode")
		.def("addStringAttribute", &BuildArrayStringNode::addStringAttribute);
	pythonWrapperUtils::pythonWrapper<StringArrayIndices, Node>("StringArrayIndices");
	pythonWrapperUtils::pythonWrapper<GetStringArrayElement, Node>("GetStringArrayElement");
	pythonWrapperUtils::pythonWrapper<StringArraySize, Node>("StringArraySize");
}

#endif
