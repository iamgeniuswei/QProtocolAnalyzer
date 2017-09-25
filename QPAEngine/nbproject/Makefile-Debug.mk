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
	${OBJECTDIR}/src/charsets.o \
	${OBJECTDIR}/src/except.o \
	${OBJECTDIR}/src/strutil.o \
	${OBJECTDIR}/src/tvbuff.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=`pkg-config --cflags --libs glib-2.0` 
CXXFLAGS=`pkg-config --cflags --libs glib-2.0` 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Wl,-rpath,'../QPAMemoryManager/dist/Debug/GNU-Linux' -L../QPAMemoryManager/dist/Debug/GNU-Linux -lQPAMemoryManager -Wl,-rpath,'../QPAUtility/dist/Debug/GNU-Linux' -L../QPAUtility/dist/Debug/GNU-Linux -lQPAUtility

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAEngine.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAEngine.${CND_DLIB_EXT}: ../QPAMemoryManager/dist/Debug/GNU-Linux/libQPAMemoryManager.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAEngine.${CND_DLIB_EXT}: ../QPAUtility/dist/Debug/GNU-Linux/libQPAUtility.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAEngine.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAEngine.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/charsets.o: src/charsets.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../QPAMemoryManager/src -I../QPAUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/charsets.o src/charsets.cpp

${OBJECTDIR}/src/except.o: src/except.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../QPAMemoryManager/src -I../QPAUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/except.o src/except.cpp

${OBJECTDIR}/src/strutil.o: src/strutil.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../QPAMemoryManager/src -I../QPAUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/strutil.o src/strutil.cpp

${OBJECTDIR}/src/tvbuff.o: src/tvbuff.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../QPAMemoryManager/src -I../QPAUtility/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tvbuff.o src/tvbuff.cpp

# Subprojects
.build-subprojects:
	cd ../QPAMemoryManager && ${MAKE}  -f Makefile CONF=Debug
	cd ../QPAUtility && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAMemoryManager.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAUtility.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAEngine.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../QPAMemoryManager && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../QPAUtility && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
