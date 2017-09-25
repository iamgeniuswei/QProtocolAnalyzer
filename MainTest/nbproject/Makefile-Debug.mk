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
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=-Wl,-rpath,'../QPAMemoryManager/dist/Debug/GNU-Linux' -L../QPAMemoryManager/dist/Debug/GNU-Linux -lQPAMemoryManager -Wl,-rpath,'../QPAEngine/dist/Debug/GNU-Linux' -L../QPAEngine/dist/Debug/GNU-Linux -lQPAEngine

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/maintest
	${CP} ../QPAMemoryManager/dist/Debug/GNU-Linux/libQPAMemoryManager.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../QPAEngine/dist/Debug/GNU-Linux/libQPAEngine.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/maintest: ../QPAMemoryManager/dist/Debug/GNU-Linux/libQPAMemoryManager.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/maintest: ../QPAEngine/dist/Debug/GNU-Linux/libQPAEngine.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/maintest: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/maintest ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../QPAMemoryManager/src -I../QPAEngine/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:
	cd ../QPAMemoryManager && ${MAKE}  -f Makefile CONF=Debug
	cd ../QPAEngine && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAMemoryManager.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAEngine.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/maintest

# Subprojects
.clean-subprojects:
	cd ../QPAMemoryManager && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../QPAEngine && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
