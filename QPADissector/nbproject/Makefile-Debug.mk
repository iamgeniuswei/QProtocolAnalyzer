#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/QPAAddress.o \
	${OBJECTDIR}/src/QPADissection.o \
	${OBJECTDIR}/src/QPADissectionSession.o \
	${OBJECTDIR}/src/QPADissector.o \
	${OBJECTDIR}/src/QPADissectorHelper.o \
	${OBJECTDIR}/src/QPAExpertField.o \
	${OBJECTDIR}/src/QPAFieldInfo.o \
	${OBJECTDIR}/src/QPAFrameData.o \
	${OBJECTDIR}/src/QPAFrameTvbuff.o \
	${OBJECTDIR}/src/QPAGlobalHFMetaInfo.o \
	${OBJECTDIR}/src/QPAHeaderFieldInfo.o \
	${OBJECTDIR}/src/QPAHeaderFieldRegisterInfo.o \
	${OBJECTDIR}/src/QPAPacketInfo.o \
	${OBJECTDIR}/src/QPAProtoNode.o \
	${OBJECTDIR}/src/QPAProtocol.o \
	${OBJECTDIR}/src/QPAProtocolHelper.o \
	${OBJECTDIR}/src/QPATreeData.o \
	${OBJECTDIR}/src/QPATvbuff.o \
	${OBJECTDIR}/src/QPAValueString.o \
	${OBJECTDIR}/src/dissectors/packet-frame.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Wl,-rpath,'../../QProtocolAnalyzer/QPAUtility/dist/Debug/GNU-Linux' -L../../QProtocolAnalyzer/QPAUtility/dist/Debug/GNU-Linux -lQPAUtility -Wl,-rpath,'../QPAFileHelper/dist/Debug/GNU-Linux' -L../QPAFileHelper/dist/Debug/GNU-Linux -lQPAFileHelper -Wl,-rpath,'../QPAFieldType/dist/Debug/GNU-Linux' -L../QPAFieldType/dist/Debug/GNU-Linux -lQPAFieldType

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPADissector.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPADissector.${CND_DLIB_EXT}: ../../QProtocolAnalyzer/QPAUtility/dist/Debug/GNU-Linux/libQPAUtility.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPADissector.${CND_DLIB_EXT}: ../QPAFileHelper/dist/Debug/GNU-Linux/libQPAFileHelper.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPADissector.${CND_DLIB_EXT}: ../QPAFieldType/dist/Debug/GNU-Linux/libQPAFieldType.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPADissector.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPADissector.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/QPAAddress.o: src/QPAAddress.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAAddress.o src/QPAAddress.cpp

${OBJECTDIR}/src/QPADissection.o: src/QPADissection.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPADissection.o src/QPADissection.cpp

${OBJECTDIR}/src/QPADissectionSession.o: src/QPADissectionSession.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPADissectionSession.o src/QPADissectionSession.cpp

${OBJECTDIR}/src/QPADissector.o: src/QPADissector.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPADissector.o src/QPADissector.cpp

${OBJECTDIR}/src/QPADissectorHelper.o: src/QPADissectorHelper.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPADissectorHelper.o src/QPADissectorHelper.cpp

${OBJECTDIR}/src/QPAExpertField.o: src/QPAExpertField.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAExpertField.o src/QPAExpertField.cpp

${OBJECTDIR}/src/QPAFieldInfo.o: src/QPAFieldInfo.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAFieldInfo.o src/QPAFieldInfo.cpp

${OBJECTDIR}/src/QPAFrameData.o: src/QPAFrameData.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAFrameData.o src/QPAFrameData.cpp

${OBJECTDIR}/src/QPAFrameTvbuff.o: src/QPAFrameTvbuff.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAFrameTvbuff.o src/QPAFrameTvbuff.cpp

${OBJECTDIR}/src/QPAGlobalHFMetaInfo.o: src/QPAGlobalHFMetaInfo.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAGlobalHFMetaInfo.o src/QPAGlobalHFMetaInfo.cpp

${OBJECTDIR}/src/QPAHeaderFieldInfo.o: src/QPAHeaderFieldInfo.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAHeaderFieldInfo.o src/QPAHeaderFieldInfo.cpp

${OBJECTDIR}/src/QPAHeaderFieldRegisterInfo.o: src/QPAHeaderFieldRegisterInfo.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAHeaderFieldRegisterInfo.o src/QPAHeaderFieldRegisterInfo.cpp

${OBJECTDIR}/src/QPAPacketInfo.o: src/QPAPacketInfo.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAPacketInfo.o src/QPAPacketInfo.cpp

${OBJECTDIR}/src/QPAProtoNode.o: src/QPAProtoNode.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAProtoNode.o src/QPAProtoNode.cpp

${OBJECTDIR}/src/QPAProtocol.o: src/QPAProtocol.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAProtocol.o src/QPAProtocol.cpp

${OBJECTDIR}/src/QPAProtocolHelper.o: src/QPAProtocolHelper.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAProtocolHelper.o src/QPAProtocolHelper.cpp

${OBJECTDIR}/src/QPATreeData.o: src/QPATreeData.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPATreeData.o src/QPATreeData.cpp

${OBJECTDIR}/src/QPATvbuff.o: src/QPATvbuff.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPATvbuff.o src/QPATvbuff.cpp

${OBJECTDIR}/src/QPAValueString.o: src/QPAValueString.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAValueString.o src/QPAValueString.cpp

${OBJECTDIR}/src/dissectors/packet-frame.o: src/dissectors/packet-frame.cpp
	${MKDIR} -p ${OBJECTDIR}/src/dissectors
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -I../QPAFileHelper/src -I../QPAFieldType/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dissectors/packet-frame.o src/dissectors/packet-frame.cpp

# Subprojects
.build-subprojects:
	cd ../../QProtocolAnalyzer/QPAUtility && ${MAKE}  -f Makefile CONF=Debug
	cd ../QPAFileHelper && ${MAKE}  -f Makefile CONF=Debug
	cd ../QPAFieldType && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAUtility.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAFileHelper.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAFieldType.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPADissector.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../../QProtocolAnalyzer/QPAUtility && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../QPAFileHelper && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../QPAFieldType && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
