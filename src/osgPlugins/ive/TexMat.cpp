/**********************************************************************
 *
 *	FILE:			TexMat.cpp
 *
 *	DESCRIPTION:	Read/Write osg::TexMat in binary format to disk.
 *
 *	CREATED BY:		Auto generated by iveGenerated
 *					and later modified by Rune Schmidt Jensen.
 *
 *	HISTORY:		Created 21.3.2003
 *
 *	Copyright 2003 VR-C
 **********************************************************************/

#include "Exception.h"
#include "TexMat.h"
#include "Object.h"

using namespace ive;

void TexMat::write(DataOutputStream* out){
	// Write TexMat's identification.
	out->writeInt(IVETEXMAT);
	// If the osg class is inherited by any other class we should also write this to file.
	osg::Object*  obj = dynamic_cast<osg::Object*>(this);
	if(obj){
		((ive::Object*)(obj))->write(out);
	}
	else
		throw Exception("TexMat::write(): Could not cast this osg::TexMat to an osg::Object.");
	// Write TexMat's properties.

	// Write mode
	out->writeMatrix(getMatrix());
}

void TexMat::read(DataInputStream* in){
	// Peek on TexMat's identification.
	int id = in->peekInt();
	if(id == IVETEXMAT){
		// Read TexMat's identification.
		id = in->readInt();
		// If the osg class is inherited by any other class we should also read this from file.
		osg::Object*  obj = dynamic_cast<osg::Object*>(this);
		if(obj){
			((ive::Object*)(obj))->read(in);
		}
		else
			throw Exception("TexMat::read(): Could not cast this osg::TexMat to an osg::Object.");
		// Read TexMat's properties

		// Read matrix
		setMatrix(in->readMatrix());

	}
	else{
		throw Exception("TexMat::read(): Expected TexMat identification.");
	}
}
