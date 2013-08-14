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

#ifndef CORAL_POLYVALUE_H
#define CORAL_POLYVALUE_H

#include <vector>
#include <string>
#include "Value.h"
#include "stringUtils.h"
#include "StringAttribute.h"
#include "Numeric.h"
#include "BoolAttribute.h"

#include <ImathVec.h>
#include <ImathMatrix.h>
#include <ImathColor.h>
#include <ImathQuat.h>

namespace coral{


//! This class is a container for any kind of data that needs to be carried by an Attribute.
class CORAL_EXPORT PolyValue : public Value{

public:
	// All value types
	enum ValueType{
		typeAny = 0,
		numericTypeAny,
		numericTypeInt,
		numericTypeIntArray,
		numericTypeFloat,
		numericTypeFloatArray,
		numericTypeVec3,
		numericTypeVec3Array,
		numericTypeCol4,
		numericTypeCol4Array,
		numericTypeQuat,
		numericTypeQuatArray,
		numericTypeMatrix44,
		numericTypeMatrix44Array,
		stringTypeAny,
		stringType,
		stringTypeArray,
		pathType,
		pathTypeArray,
		boolTypeAny,
		boolType,
		boolTypeArray,
		//geoTypeAny,
		geoType,
		//geoTypeArray,
		//imageTypeAny,
		imageType,
		//imageTypeArray
	};

	PolyValue();
	PolyValue::ValueType type();
	operator Numeric();
	operator Numeric*();


	Numeric *copyToNumeric();
	String *copyToString();
	Bool *copyToBool();
	void copy(const Value *other);
	//! Copy the proper values from a String value
	void copyFromString(String *other);
	//! Copy the proper values from a Bool value
	void copyFromBool(Bool *other);
	//! Copy the proper values from a Numeric value
	void copyFromNumeric(Numeric *other);
	void setType(ValueType type);
	virtual std::string asString();
	std::string sliceAsString(unsigned int slice);
	void setFromString(const std::string &value);
	bool isArray();
	unsigned int size();
	void resize(unsigned int newSize);
	unsigned int sizeSlice(unsigned int slice);
	void resizeSlice(unsigned int slice, unsigned int newSize);
	void resizeSlices(unsigned int slices);
	unsigned int slices(){return _slices;}
//	template<typename valType> void setValueAtSlice(unsigned int slice, unsigned int id, valType value);
//	template<typename valType> void setValueAt(unsigned int id, valType value);
//	template<typename valType> void setValues(const std::vector<valType> &values);
//	template<typename valType> valType valueAtSlice(unsigned int slice, unsigned int id);
//	template<typename valType> valType valueAt(unsigned int id);

	const std::vector<std::string> &stringValues();
	const std::vector<std::string> &pathValues();
	const std::vector<bool> &boolValues();
	const std::vector<int> &intValues();
	const std::vector<float> &floatValues();
	const std::vector<Imath::V3f> &vec3Values();
	const std::vector<Imath::Color4f> &col4Values();
	const std::vector<Imath::Quatf> &quatValues();
	const std::vector<Imath::M44f> &matrix44Values();

	const std::string stringValueAt(unsigned int id);
	const std::string pathValueAt(unsigned int id);
	const bool boolValueAt(unsigned int id);
	const int intValueAt(unsigned int id);
	const float floatValueAt(unsigned int id);
	const Imath::V3f vec3ValueAt(unsigned int id);
	const Imath::Color4f col4ValueAt(unsigned int id);
	const Imath::M44f matrix44ValueAt(unsigned int id);
	const Imath::Quatf quatValueAt(unsigned int id);

	const std::vector<int> &intValuesSlice(unsigned int slice);
	const std::vector<float> &floatValuesSlice(unsigned int slice);
	const std::vector<Imath::V3f> &vec3ValuesSlice(unsigned int slice);
	const std::vector<Imath::M44f> &matrix44ValuesSlice(unsigned int slice);
	const std::vector<Imath::Quatf> &quatValuesSlice(unsigned int slice);
	const std::vector<Imath::Color4f> &col4ValuesSlice(unsigned int slice);
	const std::vector<std::string> &stringValuesSlice(unsigned int slice);
	const std::vector<std::string> &pathValuesSlice(unsigned int slice);
	const std::vector<bool> &boolValuesSlice(unsigned int slice);

	void setStringValues(const std::vector<std::string> &values);
	void setPathValues(const std::vector<std::string> &values);
	void setBoolValues(const std::vector<bool> &values);
	void setIntValues(const std::vector<int> &values);
	void setFloatValues(const std::vector<float> &values);
	void setVec3Values(const std::vector<Imath::V3f> &values);
	void setMatrix44Values(const std::vector<Imath::M44f> &values);
	void setCol4Values(const std::vector<Imath::Color4f> &values);
	void setQuatValues(const std::vector<Imath::Quatf> &values);

	void setStringValueAt(unsigned int id, std::string value);
	void setPathValueAt(unsigned int id, std::string value);
	void setBoolValueAt(unsigned int id, bool value);
	void setIntValueAt(unsigned int id, int value);
	void setFloatValueAt(unsigned int id, float value);
	void setVec3ValueAt(unsigned int id, const Imath::V3f &value);
	void setCol4ValueAt(unsigned int id, const Imath::Color4f &value);
	void setMatrix44ValueAt(unsigned int id, const Imath::M44f &value);
	void setQuatValueAt(unsigned int id, const Imath::Quatf &value);

	void setStringValueAtSlice(unsigned int slice, unsigned int id, std::string &value);
	void setPathValueAtSlice(unsigned int slice, unsigned int id, std::string &value);
	void setBoolValueAtSlice(unsigned int slice, unsigned int id, bool value);
	void setIntValueAtSlice(unsigned int slice, unsigned int id, int value);
	void setFloatValueAtSlice(unsigned int slice, unsigned int id, float value);
	void setVec3ValueAtSlice(unsigned int slice, unsigned int id, const Imath::V3f &value);
	void setMatrix44ValueAtSlice(unsigned int slice, unsigned int id, const Imath::M44f &value);
	void setCol4ValueAtSlice(unsigned int slice, unsigned int id, const Imath::Color4f &value);
	void setQuatValueAtSlice(unsigned int slice, unsigned int id, const Imath::Quatf &value);

	void setStringValuesSlice(unsigned int slice, const std::vector<std::string> &values);
	void setPathValuesSlice(unsigned int slice, const std::vector<std::string> &values);
	void setBoolValuesSlice(unsigned int slice, const std::vector<bool> &values);
	void setIntValuesSlice(unsigned int slice, const std::vector<int> &values);
	void setFloatValuesSlice(unsigned int slice, const std::vector<float> &values);
	void setVec3ValuesSlice(unsigned int slice, const std::vector<Imath::V3f> &values);
	void setCol4ValuesSlice(unsigned int slice, const std::vector<Imath::Color4f> &values);
	void setMatrix44ValuesSlice(unsigned int slice, const std::vector<Imath::M44f> &values);
	void setQuatValuesSlice(unsigned int slice, const std::vector<Imath::Quatf> &values);

	std::string stringValueAtSlice(unsigned int slice, unsigned int id);
	std::string pathValueAtSlice(unsigned int slice, unsigned int id);
	bool boolValueAtSlice(unsigned int slice, unsigned int id);
	int intValueAtSlice(unsigned int slice, unsigned int id);
	float floatValueAtSlice(unsigned int slice, unsigned int id);
	Imath::V3f vec3ValueAtSlice(unsigned int slice, unsigned int id);
	Imath::Color4f col4ValueAtSlice(unsigned int slice, unsigned int id);
	Imath::M44f matrix44ValueAtSlice(unsigned int slice, unsigned int id);
	Imath::Quatf quatValueAtSlice(unsigned int slice, unsigned int id);

private:
	bool _isArray;
	ValueType _type;
	unsigned int _slices;
	PolyValue::ValueType typeConvert(String::Type type);
	PolyValue::ValueType typeConvert(Numeric::Type type);
	PolyValue::ValueType typeConvert(Bool::Type type);

	std::vector<std::vector<int> > _intValuesSliced;
	std::vector<std::vector<float> > _floatValuesSliced;
	std::vector<std::vector<Imath::V3f> > _vec3ValuesSliced;
	std::vector<std::vector<Imath::Color4f> > _col4ValuesSliced;
	std::vector<std::vector<Imath::M44f> > _matrix44ValuesSliced;
	std::vector<std::vector<Imath::Quatf> > _quatValuesSliced;
	std::vector<std::vector<std::string> > _stringValuesSliced;
	std::vector<std::vector<bool> > _boolValuesSliced;

	std::string boolSliceAsString(unsigned int slice);
	std::string stringSliceAsString(unsigned int slice);
	std::string intSliceAsString(unsigned int slice);
	std::string floatSliceAsString(unsigned int slice);
	std::string vec3SliceAsString(unsigned int slice);
	std::string col4SliceAsString(unsigned int slice);
	std::string matrix44SliceAsString(unsigned int slice);
	std::string quatSliceAsString(unsigned int slice);

	void stringSetFromString(const std::string &value);
	void boolSetFromString(const std::string &value);
	void intSetFromString(const std::string &value);
	void floatSetFromString(const std::string &value);
	void vec3SetFromString(const std::string &value);
	void col4SetFromString(const std::string &value);
	void matrix44SetFromString(const std::string &value);
	void quatSetFromString(const std::string &value);
};

}

#endif
