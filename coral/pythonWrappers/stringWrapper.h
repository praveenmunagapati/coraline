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

int string_stringTypeAny(){
	return int(String::stringTypeAny);
}

int string_stringType(){
	return int(String::stringType);
}

int string_pathType(){
	return int(String::pathType);
}

std::string string_stringValue(String &self){
	return self.stringValue();
}

int string_type(String &self){
	return int(self.type());
}

void string_setType(String &self, String::Type type){
	self.setType(type);
}

void stringWrapper(){
	boost::python::enum_<String::Type>("Type")
		.value("stringTypeAny", String::stringTypeAny)
		.value("stringType", String::stringType)
		.value("pathType",String::pathType)
	;
	boost::python::class_<String, boost::shared_ptr<String>, boost::python::bases<Value>, boost::noncopyable>("String", boost::python::no_init)
		.def("__init__", pythonWrapperUtils::__init__<String>)
		.def("type", string_type)
		.def("setType", string_setType)
		.def("setStringValue", &String::setStringValue)
		.def("stringValue", string_stringValue)
		.def("createUnwrapped", pythonWrapperUtils::createUnwrapped<String>)
		.staticmethod("createUnwrapped")
	;
	
	pythonWrapperUtils::pythonWrapper<StringNode, Node>("StringNode");
	pythonWrapperUtils::pythonWrapper<StringAttribute, Attribute>("StringAttribute")
		.def("setLongString", &StringAttribute::setLongString)
		.def("longString", &StringAttribute::longString);
	pythonWrapperUtils::pythonWrapper<FilePathNode, Node>("FilePathNode");
}

#endif
