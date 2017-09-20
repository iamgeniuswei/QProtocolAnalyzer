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
	${OBJECTDIR}/src/QPADissectionSession.o \
	${OBJECTDIR}/src/QPADissector.o \
	${OBJECTDIR}/src/QPADissectorHelper.o \
	${OBJECTDIR}/src/QPAFrameData.o \
	${OBJECTDIR}/src/QPAProtocol.o


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
LDLIBSOPTIONS=-Wl,-rpath,'../../QProtocolAnalyzer/QPAUtility/dist/Debug/GNU-Linux' -L../../QProtocolAnalyzer/QPAUtility/dist/Debug/GNU-Linux -lQPAUtility

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPADissector.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPADissector.${CND_DLIB_EXT}: ../../QProtocolAnalyzer/QPAUtility/dist/Debug/GNU-Linux/libQPAUtility.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPADissector.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPADissector.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/QPADissectionSession.o: src/QPADissectionSession.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPADissectionSession.o src/QPADissectionSession.cpp

${OBJECTDIR}/src/QPADissector.o: src/QPADissector.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPADissector.o src/QPADissector.cpp

${OBJECTDIR}/src/QPADissectorHelper.o: src/QPADissectorHelper.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPADissectorHelper.o src/QPADissectorHelper.cpp

${OBJECTDIR}/src/QPAFrameData.o: src/QPAFrameData.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAFrameData.o src/QPAFrameData.cpp

${OBJECTDIR}/src/QPAProtocol.o: src/QPAProtocol.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../QProtocolAnalyzer/QPAUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAProtocol.o src/QPAProtocol.cpp

# Subprojects
.build-subprojects:
	cd ../../QProtocolAnalyzer/QPAUtility && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAUtility.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPADissector.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../../QProtocolAnalyzer/QPAUtility && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
