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
	${OBJECTDIR}/src/QPAFileInfo.o \
	${OBJECTDIR}/src/QPAFileMediator.o \
	${OBJECTDIR}/src/QPAFileReader.o \
	${OBJECTDIR}/src/QPAOpenRoutine.o \
	${OBJECTDIR}/src/QPAPcapOpenRoutine.o


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
LDLIBSOPTIONS=-Wl,-rpath,'../QPAUtility/dist/Debug/GNU-Linux' -L../QPAUtility/dist/Debug/GNU-Linux -lQPAUtility

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAFileHelper.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAFileHelper.${CND_DLIB_EXT}: ../QPAUtility/dist/Debug/GNU-Linux/libQPAUtility.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAFileHelper.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAFileHelper.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/QPAFileInfo.o: src/QPAFileInfo.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../QPAUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAFileInfo.o src/QPAFileInfo.cpp

${OBJECTDIR}/src/QPAFileMediator.o: src/QPAFileMediator.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../QPAUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAFileMediator.o src/QPAFileMediator.cpp

${OBJECTDIR}/src/QPAFileReader.o: src/QPAFileReader.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../QPAUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAFileReader.o src/QPAFileReader.cpp

${OBJECTDIR}/src/QPAOpenRoutine.o: src/QPAOpenRoutine.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../QPAUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAOpenRoutine.o src/QPAOpenRoutine.cpp

${OBJECTDIR}/src/QPAPcapOpenRoutine.o: src/QPAPcapOpenRoutine.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../QPAUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAPcapOpenRoutine.o src/QPAPcapOpenRoutine.cpp

# Subprojects
.build-subprojects:
	cd ../QPAUtility && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAUtility.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAFileHelper.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../QPAUtility && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
